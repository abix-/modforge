// Address: 0x140144d60
// Ghidra name: FUN_140144d60
// ============ 0x140144d60 FUN_140144d60 (size=1118) ============


undefined1

FUN_140144d60(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5,longlong param_6,

             int param_7,uint param_8,int param_9,undefined4 param_10,longlong param_11,int param_12

             )



{

  undefined1 uVar1;

  char cVar2;

  int local_res20;

  undefined8 in_stack_fffffffffffffd30;

  undefined4 uVar4;

  undefined8 uVar3;

  undefined8 local_298;

  int local_290;

  int local_28c;

  undefined1 local_288 [304];

  undefined1 local_158 [304];

  

  uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffd30 >> 0x20);

  if (param_6 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar1;

  }

  if (param_7 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","src_pitch");

  }

  else if (param_11 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  }

  else if (param_12 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","dst_pitch");

  }

  else {

    local_res20 = param_4;

    if (param_4 == 0) {

      local_res20 = FUN_14017a4b0(param_3);

    }

    if (param_9 == 0) {

      param_9 = FUN_14017a4b0(param_8);

    }

    if (param_3 == 0x47504a4d) {

      uVar1 = FUN_14019aee0(param_1,param_2,0x47504a4d,local_res20,param_5,param_6,param_7,param_8,

                            param_9,param_10,param_11,param_12);

    }

    else if ((param_3 == 0) || ((param_3 & 0xf0000000) == 0x10000000)) {

      if ((param_8 == 0) || ((param_8 & 0xf0000000) == 0x10000000)) {

        if ((param_3 == param_8) && (local_res20 == param_9)) {

          if (param_7 == param_12) {

            FUN_1402f8e20(param_11,param_6,(longlong)(param_2 * param_7));

            uVar1 = 1;

          }

          else {

            if ((param_3 == 0) || ((param_3 & 0xf0000000) == 0x10000000)) {

              param_3 = param_3 & 0xff;

            }

            else if ((((param_3 == 0x32595559) || (param_3 == 0x59565955)) ||

                     (param_3 == 0x55595659)) || (param_3 == 0x30313050)) {

              param_3 = 2;

            }

            else {

              param_3 = 1;

            }

            if (param_2 != 0) {

              do {

                FUN_1402f8e20(param_11,param_6,(longlong)(int)(param_1 * param_3));

                param_6 = param_6 + param_7;

                param_11 = param_11 + param_12;

                param_2 = param_2 + -1;

              } while (param_2 != 0);

            }

            uVar1 = 1;

          }

        }

        else {

          uVar3 = CONCAT44(uVar4,param_5);

          cVar2 = FUN_140146ca0(local_288,param_1,param_2,param_3,local_res20,uVar3,param_6,param_7,

                                1);

          uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

          if (cVar2 != '\0') {

            FUN_140148450(local_288,0);

            cVar2 = FUN_140146ca0(local_158,param_1,param_2,param_8,param_9,CONCAT44(uVar4,param_10)

                                  ,param_11,param_12,1);

            if (cVar2 != '\0') {

              local_298 = 0;

              local_290 = param_1;

              local_28c = param_2;

              uVar1 = FUN_140144330(local_288,&local_298,local_158,&local_298);

              FUN_140146010(local_288);

              FUN_140146010(local_158);

              return uVar1;

            }

          }

          uVar1 = 0;

        }

      }

      else {

        uVar1 = FUN_1401d5930(param_1,param_2,param_3,local_res20,param_5,param_6,param_7,param_8,

                              param_9,param_10,param_11,param_12);

      }

    }

    else if ((param_8 == 0) || ((param_8 & 0xf0000000) == 0x10000000)) {

      uVar1 = FUN_1401dad80(param_1,param_2,param_3,local_res20,param_5,param_6,param_7,param_8,

                            param_9,param_10,param_11,param_12);

    }

    else {

      uVar1 = FUN_1401db150(param_1,param_2,param_3,local_res20,param_5,param_6,param_7,param_8,

                            param_9,param_10,param_11,param_12);

    }

  }

  return uVar1;

}




