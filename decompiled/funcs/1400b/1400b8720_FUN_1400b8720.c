// Address: 0x1400b8720
// Ghidra name: FUN_1400b8720
// ============ 0x1400b8720 FUN_1400b8720 (size=174) ============


void FUN_1400b8720(longlong param_1)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  uint uVar4;

  ulonglong uVar5;

  

  lVar3 = *(longlong *)(param_1 + 0x40);

  lVar1 = *(longlong *)(param_1 + 0x48) - lVar3;

  uVar2 = 0;

  lVar1 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar1),8) + lVar1;

  uVar5 = uVar2;

  if (lVar1 >> 7 != lVar1 >> 0x3f) {

    do {

      if (*(int *)(uVar2 + 8 + lVar3) == 10) {

        *(undefined4 *)(uVar2 + 0xa4 + lVar3) = 1;

        *(undefined4 *)(uVar2 + 0xa8 + *(longlong *)(param_1 + 0x40)) = 0x2d;

        *(undefined4 *)(uVar2 + 0xac + *(longlong *)(param_1 + 0x40)) = 0x3f800000;

      }

      lVar3 = *(longlong *)(param_1 + 0x40);

      uVar4 = (int)uVar5 + 1;

      lVar1 = *(longlong *)(param_1 + 0x48) - lVar3;

      uVar2 = uVar2 + 0xb8;

      lVar1 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar1),8) + lVar1;

      uVar5 = (ulonglong)uVar4;

    } while ((ulonglong)(longlong)(int)uVar4 < (ulonglong)((lVar1 >> 7) - (lVar1 >> 0x3f)));

  }

  return;

}




