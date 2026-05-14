// Address: 0x1400b5f80
// Ghidra name: FUN_1400b5f80
// ============ 0x1400b5f80 FUN_1400b5f80 (size=78) ============


ulonglong FUN_1400b5f80(longlong param_1)



{

  int *piVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  int iVar5;

  

  iVar5 = 0;

  lVar4 = *(longlong *)(param_1 + 0x48) - *(longlong *)(param_1 + 0x40);

  lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

  lVar2 = lVar4 >> 7;

  lVar4 = lVar4 >> 0x3f;

  piVar1 = (int *)-lVar4;

  uVar3 = lVar2 + (longlong)piVar1;

  if (lVar2 != lVar4) {

    piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 8);

    do {

      if (*piVar1 == 0xd) {

        return CONCAT71((int7)((ulonglong)piVar1 >> 8),1);

      }

      iVar5 = iVar5 + 1;

      piVar1 = piVar1 + 0x2e;

    } while ((ulonglong)(longlong)iVar5 < uVar3);

  }

  return (ulonglong)piVar1 & 0xffffffffffffff00;

}




