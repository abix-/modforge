// Address: 0x1401dba20
// Ghidra name: FUN_1401dba20
// ============ 0x1401dba20 FUN_1401dba20 (size=1712) ============


undefined8

FUN_1401dba20(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,

             undefined8 param_6,undefined8 param_7,undefined4 param_8,undefined4 param_9,

             undefined8 param_10,undefined4 param_11,undefined4 param_12)



{

  char cVar1;

  

  cVar1 = FUN_14017fe50();

  if (cVar1 == '\0') {

    return 0;

  }

  if ((param_1 == 0x32315659) || (param_1 == 0x56555949)) {

    if (param_2 < 0x16561805) {

      if (param_2 == 0x16561804) {

LAB_1401dc034:

        FUN_140236b10(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x15151002) {

        FUN_140239030(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16161804) {

LAB_1401dbaf3:

        FUN_140237390(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

      }

      else {

        if (param_2 != 0x16261804) {

          if (param_2 == 0x16362004) goto LAB_1401dbaf3;

          if (param_2 != 0x16462004) goto LAB_1401dbbab;

        }

        FUN_1402398f0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

      }

      return 1;

    }

    if (param_2 == 0x16661804) {

LAB_1401dc075:

      FUN_140237c00(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                    param_12);

      return 1;

    }

    if (param_2 == 0x16762004) goto LAB_1401dc034;

    if (param_2 == 0x16862004) goto LAB_1401dc075;

    if (param_2 == 0x17101803) {

      FUN_140238490(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                    param_12);

      return 1;

    }

  }

LAB_1401dbbab:

  if (((param_1 == 0x32595559) || (param_1 == 0x59565955)) || (param_1 == 0x55595659)) {

    if (param_2 < 0x16561805) {

      if (param_2 == 0x16561804) {

LAB_1401dbf68:

        FUN_14023a180(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x15151002) {

        FUN_14023bd00(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16161804) {

LAB_1401dbc50:

        FUN_14023a7f0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16261804) {

LAB_1401dbc0c:

        FUN_14023c3a0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16362004) goto LAB_1401dbc50;

      if (param_2 == 0x16462004) goto LAB_1401dbc0c;

    }

    else {

      if (param_2 == 0x16661804) {

LAB_1401dbfac:

        FUN_14023ae60(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

      if (param_2 == 0x16762004) goto LAB_1401dbf68;

      if (param_2 == 0x16862004) goto LAB_1401dbfac;

      if (param_2 == 0x17101803) {

        FUN_14023b4e0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

    }

  }

  if ((param_1 != 0x3231564e) && (param_1 != 0x3132564e)) {

    return 0;

  }

  if (0x16561804 < param_2) {

    if (param_2 != 0x16661804) {

      if (param_2 == 0x16762004) goto LAB_1401dbe9c;

      if (param_2 != 0x16862004) {

        if (param_2 != 0x17101803) {

          return 0;

        }

        FUN_14023e590(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,

                      param_12);

        return 1;

      }

    }

    FUN_14023dc60(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 == 0x16561804) {

LAB_1401dbe9c:

    FUN_14023ca20(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 == 0x15151002) {

    FUN_14023f1d0(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

  if (param_2 != 0x16161804) {

    if (param_2 != 0x16261804) {

      if (param_2 == 0x16362004) goto LAB_1401dbda4;

      if (param_2 != 0x16462004) {

        return 0;

      }

    }

    FUN_14023fb40(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12

                 );

    return 1;

  }

LAB_1401dbda4:

  FUN_14023d340(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);

  return 1;

}




