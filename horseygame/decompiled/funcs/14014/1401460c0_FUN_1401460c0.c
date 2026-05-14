// Address: 0x1401460c0
// Ghidra name: FUN_1401460c0
// ============ 0x1401460c0 FUN_1401460c0 (size=249) ============


longlong FUN_1401460c0(int param_1,int param_2,uint param_3,undefined4 param_4,longlong param_5,

                      int param_6)



{

  longlong lVar1;

  longlong lVar2;

  

  if (param_5 == 0) {

    lVar1 = FUN_140145bc0();

  }

  else {

    lVar1 = FUN_140145e60();

  }

  if (lVar1 != 0) {

    FUN_1401487a0(lVar1,param_4);

    lVar2 = *(longlong *)(lVar1 + 0x18);

    if (lVar2 != 0) {

      if ((param_3 == 0) || ((param_3 & 0xf0000000) == 0x10000000)) {

        param_3 = param_3 & 0xff;

      }

      else if ((((param_3 == 0x32595559) || (param_3 == 0x59565955)) || (param_3 == 0x55595659)) ||

              (param_3 == 0x30313050)) {

        param_3 = 2;

      }

      else {

        param_3 = 1;

      }

      if (param_2 != 0) {

        do {

          FUN_1402f8e20(lVar2,param_5,(longlong)(int)(param_3 * param_1));

          param_5 = param_5 + param_6;

          lVar2 = lVar2 + *(int *)(lVar1 + 0x10);

          param_2 = param_2 + -1;

        } while (param_2 != 0);

      }

    }

  }

  return lVar1;

}




