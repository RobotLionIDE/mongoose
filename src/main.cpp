/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mgos.h"
#include "mgos_sys_config.h"
#include "mgos_rpc.h"

#define SH1106_128_64
#define OLED_SDA 21
#define OLED_SCL 22

#include <Wire.h>
#include "Adafruit_SH1106.h"
#include "mgos_arduino_sh1106.h"
#include "md5_1.h"
#include "mgos_sys_config.h"
#include "mgos_config_util.h"

Adafruit_SH1106 display(SH1106_LCDWIDTH, SH1106_LCDHEIGHT);

static void sum_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {
  double a = 0, b = 0;
  if (json_scanf(args.p, args.len, ri->args_fmt, &a, &b) == 2) {
    mg_rpc_send_responsef(ri, "%.2lf", a + b);
  } else {
    mg_rpc_send_errorf(ri, -1, "Bad request. Expected: {\"a\":N1,\"b\":N2}");
  }
  (void) cb_arg;
  (void) fi;
}

static void calc_config_hash(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args)
{
  struct mgos_config *cfg = &mgos_sys_config;
  const struct mgos_conf_entry *schema = mgos_config_schema();
  
  struct mbuf conf_mbuf;
  mbuf_init(&conf_mbuf, 0);
  mgos_conf_emit_cb(((char *) cfg) + schema->offset, NULL, schema, false,
                    &conf_mbuf, NULL, NULL);
  
  MD5 md5;
  md5.update(conf_mbuf.buf, conf_mbuf.size);
  md5.finalize();

  char hash[32 + 1]={0};
  md5.hexdigest(hash, sizeof(hash));
  
  mg_rpc_send_responsef(ri, "{ ConfigHash: \"%s\" }", hash);

  mbuf_free(&conf_mbuf);
}

enum mgos_app_init_result mgos_app_init(void) 
{
  mg_rpc_add_handler(mgos_rpc_get_global(), "Sum", "{a: %lf, b: %lf}", sum_cb, NULL);
  mg_rpc_add_handler(mgos_rpc_get_global(), "Config.GetHash", 0, calc_config_hash, NULL);
  Wire.begin(SH1106_128_64);
  return MGOS_APP_INIT_SUCCESS;
}
