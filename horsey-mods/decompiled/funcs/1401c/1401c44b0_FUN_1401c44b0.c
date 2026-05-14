// Address: 0x1401c44b0
// Ghidra name: FUN_1401c44b0
// ============ 0x1401c44b0 FUN_1401c44b0 (size=123) ============


void FUN_1401c44b0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x298);

  FUN_1401cab60(lVar1);

  FUN_1401cd410(lVar1);

  iVar2 = *(int *)(lVar1 + 0x148) + -1;

  lVar3 = (longlong)iVar2;

  if (-1 < iVar2) {

    do {

      FUN_1401cc0d0(lVar1,**(undefined8 **)(*(longlong *)(lVar1 + 0x140) + lVar3 * 8));

      lVar3 = lVar3 + -1;

    } while (-1 < lVar3);

  }

  FUN_1401c97e0(lVar1);

  FUN_1401841e0(param_1);

  return;

}




