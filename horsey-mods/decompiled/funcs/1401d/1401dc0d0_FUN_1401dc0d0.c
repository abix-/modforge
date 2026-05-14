// Address: 0x1401dc0d0
// Ghidra name: FUN_1401dc0d0
// ============ 0x1401dc0d0 FUN_1401dc0d0 (size=1832) ============


undefined8

FUN_1401dc0d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,

             undefined8 param_6,undefined8 param_7,undefined4 param_8,undefined4 param_9,

             undefined8 param_10,undefined4 param_11,undefined4 param_12)



{

  if ((param_1 == 0x32315659) || (param_1 == 0x56555949)) {

    if (param_2 < 0x16561805) {

      if (param_2 == 0x16561804) {

LAB_1401dc766:

        FUN_140230ce0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x15151002) {

        FUN_140232450(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16161804) {

LAB_1401dc17e:

        FUN_140231300(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16261804) {

LAB_1401dc135:

        FUN_140232a90(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16362004) goto LAB_1401dc17e;

      if (param_2 == 0x16462004) goto LAB_1401dc135;

    }

    else {

      if (param_2 == 0x16661804) {

LAB_1401dc7af:

        FUN_140231930(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16762004) goto LAB_1401dc766;

      if (param_2 == 0x16862004) goto LAB_1401dc7af;

      if (param_2 == 0x17101803) {

        FUN_140231f70(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

    }

  }

  if (((param_1 == 0x32595559) || (param_1 == 0x59565955)) || (param_1 == 0x55595659)) {

    if (param_2 < 0x16561805) {

      if (param_2 == 0x16561804) {

LAB_1401dc68b:

        FUN_1402330d0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x15151002) {

        FUN_140233b00(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16161804) {

LAB_1401dc2e7:

        FUN_140233380(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16261804) {

LAB_1401dc29e:

        FUN_140233da0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16362004) goto LAB_1401dc2e7;

      if (param_2 == 0x16462004) goto LAB_1401dc29e;

    }

    else {

      if (param_2 == 0x16661804) {

LAB_1401dc6d4:

        FUN_140233630(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16762004) goto LAB_1401dc68b;

      if (param_2 == 0x16862004) goto LAB_1401dc6d4;

      if (param_2 == 0x17101803) {

        FUN_1402338e0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

    }

  }

  if ((param_1 != 0x3231564e) && (param_1 != 0x3132564e)) {

LAB_1401dc506:

    if ((param_1 == 0x30313050) && (param_2 == 0x16572004)) {

      FUN_140236470(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                    param_12);

      return 1;

    }

    return 0;

  }

  if (0x16561804 < param_2) {

    if (param_2 != 0x16661804) {

      if (param_2 == 0x16762004) goto LAB_1401dc5b0;

      if (param_2 != 0x16862004) {

        if (param_2 == 0x17101803) {

          FUN_1402352e0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                        param_12);

          return 1;

        }

        goto LAB_1401dc506;

      }

    }

    FUN_140234ca0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 == 0x16561804) {

LAB_1401dc5b0:

    FUN_140234040(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 == 0x15151002) {

    FUN_1402357d0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 != 0x16161804) {

    if (param_2 != 0x16261804) {

      if (param_2 == 0x16362004) goto LAB_1401dc448;

      if (param_2 != 0x16462004) goto LAB_1401dc506;

    }

    FUN_140235e20(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

LAB_1401dc448:

  FUN_140234670(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);

  return 1;

}




