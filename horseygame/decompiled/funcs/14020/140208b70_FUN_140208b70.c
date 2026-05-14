// Address: 0x140208b70
// Ghidra name: FUN_140208b70
// ============ 0x140208b70 FUN_140208b70 (size=135) ============


void FUN_140208b70(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong lVar3;

  int iVar4;

  

  _guard_check_icall();

  iVar4 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar3 = 0;

    do {

      lVar1 = FUN_1401581c0(*(undefined4 *)(*(longlong *)(param_1 + 0x90) + lVar3));

      if ((lVar1 != 0) && (*(longlong *)(param_1 + 0x28) != 0)) {

        FUN_1401841e0(*(undefined8 *)(lVar1 + 0x18));

        uVar2 = FUN_14012f0d0(*(undefined8 *)(param_1 + 0x28));

        *(undefined8 *)(lVar1 + 0x18) = uVar2;

      }

      iVar4 = iVar4 + 1;

      lVar3 = lVar3 + 4;

    } while (iVar4 < *(int *)(param_1 + 0x8c));

  }

  return;

}




