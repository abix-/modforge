// Address: 0x1400b8660
// Ghidra name: FUN_1400b8660
// ============ 0x1400b8660 FUN_1400b8660 (size=185) ============


void FUN_1400b8660(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar4 = *(longlong *)(param_1 + 0x40);

  lVar3 = *(longlong *)(param_1 + 0x48) - lVar4;

  iVar2 = 0;

  lVar3 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar3),8) + lVar3;

  if (lVar3 >> 7 != lVar3 >> 0x3f) {

    lVar3 = 0;

    do {

      if (*(int *)(lVar3 + 8 + lVar4) == 7) {

        *(undefined4 *)(lVar3 + 0xa4 + lVar4) = 1;

        *(undefined4 *)(lVar3 + 0xa8 + *(longlong *)(param_1 + 0x40)) = param_3;

        *(undefined4 *)(lVar3 + 0xac + *(longlong *)(param_1 + 0x40)) = param_2;

      }

      lVar4 = *(longlong *)(param_1 + 0x40);

      iVar2 = iVar2 + 1;

      lVar1 = *(longlong *)(param_1 + 0x48) - lVar4;

      lVar3 = lVar3 + 0xb8;

      lVar1 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar1),8) + lVar1;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)((lVar1 >> 7) - (lVar1 >> 0x3f)));

  }

  return;

}




