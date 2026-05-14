// Address: 0x1401bfa20
// Ghidra name: FUN_1401bfa20
// ============ 0x1401bfa20 FUN_1401bfa20 (size=115) ============


undefined8 FUN_1401bfa20(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  int iVar2;

  uint uVar3;

  ulonglong uVar4;

  

  uVar4 = 0;

  *(undefined4 *)(param_1 + 0x584) = param_2;

  if (*(int *)(param_1 + 0x7b8) != 0) {

    do {

      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x7b0) + uVar4 * 8);

      iVar2 = FUN_1401bc750(param_1,lVar1);

      if (iVar2 == 0) {

        return 0;

      }

      if (iVar2 == 2) {

        *(undefined1 *)(lVar1 + 0x1c) = 1;

      }

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_1 + 0x7b8));

  }

  return 1;

}




