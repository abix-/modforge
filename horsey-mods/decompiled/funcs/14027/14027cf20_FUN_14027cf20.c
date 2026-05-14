// Address: 0x14027cf20
// Ghidra name: FUN_14027cf20
// ============ 0x14027cf20 FUN_14027cf20 (size=280) ============


undefined8

FUN_14027cf20(longlong param_1,longlong param_2,char *param_3,undefined8 param_4,undefined4 param_5)



{

  char cVar1;

  

  if ((param_3[1] & 0xfU) == 0) {

    cVar1 = *param_3;

    if ((param_3[1] & 0x20U) == 0) {

      if (cVar1 == '\f') {

        if (param_1 != 0) {

          FUN_14027caf0(param_1,param_2,param_4,param_5);

        }

      }

      else if (cVar1 == ' ') {

        if (*(int *)(param_2 + 0xc) < 4) {

          FUN_14027d2d0(param_2,4);

          return 1;

        }

        if (param_1 != 0) {

          FUN_14027c590(param_1,param_2,param_4,param_5);

          return 1;

        }

      }

    }

    else {

      if (cVar1 == '\x02') {

        FUN_14027d2d0(param_2,0);

        return 1;

      }

      if (cVar1 == '\x03') {

        FUN_14027cad0(param_2,param_4,param_5);

        return 1;

      }

      if (cVar1 == '\x04') {

        FUN_14027d2d0(param_2,2);

        return 1;

      }

      if (cVar1 == '\a') {

        if (param_1 != 0) {

          FUN_14027c4d0(param_1,param_2,param_4,param_5);

          return 1;

        }

      }

      else if (cVar1 == '\x1e') {

        FUN_14027c510(param_2,param_4,param_5);

        return 1;

      }

    }

  }

  return 1;

}




