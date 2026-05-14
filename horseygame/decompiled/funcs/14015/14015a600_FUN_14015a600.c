// Address: 0x14015a600
// Ghidra name: FUN_14015a600
// ============ 0x14015a600 FUN_14015a600 (size=54) ============


void FUN_14015a600(longlong param_1,int param_2,undefined4 param_3)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0x90)) {

    lVar1 = 0;

    do {

      if (*(int *)(lVar1 + *(longlong *)(param_1 + 0x98)) == param_2) {

        *(undefined4 *)(lVar1 + 8 + *(longlong *)(param_1 + 0x98)) = param_3;

      }

      iVar2 = iVar2 + 1;

      lVar1 = lVar1 + 0x18;

    } while (iVar2 < *(int *)(param_1 + 0x90));

  }

  return;

}




