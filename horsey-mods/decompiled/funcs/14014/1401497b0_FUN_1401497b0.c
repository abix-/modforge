// Address: 0x1401497b0
// Ghidra name: FUN_1401497b0
// ============ 0x1401497b0 FUN_1401497b0 (size=84) ============


void FUN_1401497b0(undefined8 param_1,undefined8 param_2,char *param_3,char *param_4)



{

  int iVar1;

  

  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {

    iVar1 = 1;

  }

  else {

    iVar1 = thunk_FUN_1402d89dc(param_4);

    if (iVar1 == 0) {

      if (param_3 == param_4) {

        return;

      }

      FUN_140149770(0);

      return;

    }

  }

  FUN_140149770(iVar1);

  return;

}




