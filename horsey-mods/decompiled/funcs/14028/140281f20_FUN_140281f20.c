// Address: 0x140281f20
// Ghidra name: FUN_140281f20
// ============ 0x140281f20 FUN_140281f20 (size=89) ============


void FUN_140281f20(longlong param_1,char param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (param_2 != *(char *)(lVar1 + 9)) {

    if (param_2 == '\0') {

      if (0 < *(int *)(param_1 + 0x8c)) {

        FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

      }

    }

    else if (*(int *)(param_1 + 0x8c) == 0) {

      FUN_140208110(param_1,0);

      *(char *)(lVar1 + 9) = param_2;

      return;

    }

    *(char *)(lVar1 + 9) = param_2;

  }

  return;

}




