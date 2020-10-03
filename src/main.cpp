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

#define SH1106_128_64
#define OLED_SDA 21
#define OLED_SCL 22

#include <Wire.h>
#include "Adafruit_SH1106.h"
#include "mgos_arduino_sh1106.h"

Adafruit_SH1106 display(SH1106_LCDWIDTH, SH1106_LCDHEIGHT);


enum mgos_app_init_result mgos_app_init(void) 
{
  Wire.begin(SH1106_128_64);
  return MGOS_APP_INIT_SUCCESS;
}
