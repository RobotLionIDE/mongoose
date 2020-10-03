let LionSetup = function()(
    GPIO.set_mode(Cfg.get('lion.A0'), Cfg.get('lion.setup.A0'));
    GPIO.set_mode(Cfg.get('lion.A1'), Cfg.get('lion.setup.A1'));
    GPIO.set_mode(Cfg.get('lion.A2'), Cfg.get('lion.setup.A2'));
    GPIO.set_mode(Cfg.get('lion.A3'), Cfg.get('lion.setup.A3'));

    GPIO.set_mode(Cfg.get('lion.RX'), Cfg.get('lion.setup.RX'));
    GPIO.set_mode(Cfg.get('lion.TX'), Cfg.get('lion.setup.TX'));

    GPIO.set_mode(Cfg.get('lion.BlueL'), Cfg.get('lion.setup.BlueL'));
    GPIO.set_mode(Cfg.get('lion.BlueR'), Cfg.get('lion.setup.BlueR'));
    GPIO.set_mode(Cfg.get('lion.RedL'), Cfg.get('lion.setup.RedL'));
    GPIO.set_mode(Cfg.get('lion.RedR'), Cfg.get('lion.setup.RedR'));

    GPIO.set_mode(Cfg.get('lion.TRIG'), Cfg.get('lion.setup.TRIG'));
    GPIO.set_mode(Cfg.get('lion.ECHO'), Cfg.get('lion.setup.ECHO'));

    GPIO.set_mode(Cfg.get('lion.MR_DIR'), Cfg.get('lion.setup.MR_DIR'));
    GPIO.set_mode(Cfg.get('lion.MR_EN'), Cfg.get('lion.setup.MR_EN'));
    GPIO.set_mode(Cfg.get('lion.ML_DIR'), Cfg.get('lion.setup.ML_DIR'));
    GPIO.set_mode(Cfg.get('lion.ML_EN'), Cfg.get('lion.setup.ML_EN'));
    print('Setup Ok');
};
