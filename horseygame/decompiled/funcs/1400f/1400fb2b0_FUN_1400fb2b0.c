// Address: 0x1400fb2b0
// Ghidra name: FUN_1400fb2b0
// ============ 0x1400fb2b0 FUN_1400fb2b0 (size=115) ============


void FUN_1400fb2b0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x130);

  iVar2 = 0;

  if (*(longlong *)(param_1 + 0x138) - lVar1 >> 3 != 0) {

    lVar3 = 0;

    do {

      FUN_1400b6610(*(longlong *)(lVar3 + lVar1),*(longlong *)(lVar3 + lVar1) + 0x1d4);

      lVar1 = *(longlong *)(param_1 + 0x130);

      lVar3 = lVar3 + 8;

      iVar2 = iVar2 + 1;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar1 >> 3));

  }

  return;

}




