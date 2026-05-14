// Address: 0x1400ce9b0
// Ghidra name: FUN_1400ce9b0
// ============ 0x1400ce9b0 FUN_1400ce9b0 (size=163) ============


void FUN_1400ce9b0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x130);

  iVar2 = 0;

  if (*(longlong *)(param_1 + 0x138) - lVar1 >> 3 != 0) {

    lVar3 = 0;

    do {

      FUN_1400b47e0(*(undefined8 *)(lVar3 + lVar1));

      lVar1 = *(longlong *)(param_1 + 0x130);

      lVar3 = lVar3 + 8;

      iVar2 = iVar2 + 1;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar1 >> 3));

  }

  lVar1 = *(longlong *)(param_1 + 0x98);

  if (lVar1 != 0) {

    FUN_140005cf0(lVar1);

    FUN_1402c7088(lVar1,0x19380);

    *(undefined8 *)(param_1 + 0x98) = 0;

    *(undefined8 *)(param_1 + 0xa0) = 0;

  }

  return;

}




