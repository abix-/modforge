// Address: 0x14013bfc0
// Ghidra name: FUN_14013bfc0
// ============ 0x14013bfc0 FUN_14013bfc0 (size=100) ============


void FUN_14013bfc0(undefined8 param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  

  _guard_check_icall();

  lVar3 = DAT_1403fbf30;

  iVar2 = *(int *)(DAT_1403fbf30 + 0x18);

  lVar1 = (longlong)iVar2 * 8;

  lVar4 = FUN_140184230(*(undefined8 *)(DAT_1403fbf30 + 0x20),lVar1 + 8);

  if (lVar4 != 0) {

    *(longlong *)(lVar3 + 0x20) = lVar4;

    *(undefined8 *)(lVar1 + lVar4) = param_1;

    *(int *)(lVar3 + 0x18) = iVar2 + 1;

  }

  return;

}




