let FWInit = function(){
  d.begin(0x2, 0x3C);
  d.clearDisplay();
  d.setTextColor(Adafruit_SH1106.WHITE);
  d.setTextSize(1);
  d.setTextWrap(true);

  d.setCursor(4,0);
  d.write(Cfg.get('bt.dev_name'));
  d.setCursor(4,8);
  d.write('Mongoose V: ' + Cfg.get('lion.firmware_version'));
  d.setCursor(4,16);
  d.write('FW V: ' + Cfg.get('lion.fileware_version'));
  d.display();
};

let LionStart = function(){
    return {status: '200'}
};

let LionStop = function(){
    return {status: '200'}
};

let LionDo = function(d) {
};
