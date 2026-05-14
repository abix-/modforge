// Address: 0x140280fd0
// Ghidra name: FUN_140280fd0
// ============ 0x140280fd0 FUN_140280fd0 (size=161) ============


void FUN_140280fd0(longlong param_1,undefined8 *param_2,char *param_3,int param_4)



{

  char cVar1;

  

  if ((0 < param_4) && (*param_3 != 'Z')) {

    param_3 = param_3 + 1;

    param_4 = param_4 + -1;

  }

  if (((0x1e < param_4) && (*param_3 == 'Z')) && (param_3[1] == -0x5b)) {

    cVar1 = param_3[2];

    if (cVar1 == '\x01') {

      if (param_1 != 0) {

        FUN_140280f50(param_1,param_2,param_3);

        return;

      }

    }

    else {

      if (cVar1 == '\x10') {

        FUN_140281ca0(*param_2,param_3,param_4);

        return;

      }

      if (cVar1 == '\x11') {

        thunk_FUN_140282420(*param_2,param_3,param_4);

        return;

      }

      if (cVar1 == '\x1c') {

        FUN_140280f30(*param_2,param_3,param_4);

        return;

      }

      if ((cVar1 == -0x11) && (param_1 != 0)) {

        FUN_1402816a0(param_1,param_2,param_3);

        return;

      }

    }

  }

  return;

}




