// Address: 0x14006f150
// Ghidra name: FUN_14006f150
// ============ 0x14006f150 FUN_14006f150 (size=772) ============


void FUN_14006f150(longlong param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  int iVar8;

  ulonglong uVar9;

  byte local_res8 [8];

  undefined4 local_res10 [2];

  longlong local_38 [3];

  ulonglong local_20;

  

  FUN_14006d580(param_1 + 0x2b8);

  FUN_140075d50(param_1 + 0x2a8);

  FUN_140075b80(param_1 + 0x1f8);

  FUN_140075cb0(param_1 + 0x220);

  FUN_140075c60(param_1 + 0x1c);

  FUN_140075c60(param_1 + 0x1fc);

  FUN_140075c60(param_1 + 0x21c);

  FUN_140075c60(param_1 + 0x284);

  FUN_140075c60(param_1 + 0x214);

  FUN_140075c60(param_1 + 0x234);

  FUN_140075c60(param_1 + 0x210);

  FUN_140075c60(param_1 + 0x1cc);

  FUN_140075e30(local_res8);

  *(byte *)(param_1 + 0x1a) = local_res8[0] & 1;

  *(byte *)(param_1 + 0x204) = local_res8[0] >> 1 & 1;

  *(byte *)(param_1 + 0x205) = local_res8[0] >> 2 & 1;

  *(byte *)(param_1 + 0x206) = local_res8[0] >> 3 & 1;

  *(byte *)(param_1 + 0x160) = local_res8[0] >> 4 & 1;

  *(byte *)(param_1 + 0x23) = local_res8[0] >> 6 & 1;

  *(byte *)(param_1 + 0x22) = local_res8[0] >> 5 & 1;

  FUN_140075f20(local_res10,param_1 + 0x1d4);

  FUN_1400760f0(local_38,param_1 + 0x168);

  if (0xf < local_20) {

    if ((0xfff < local_20 + 1) && (0x1f < (local_38[0] - *(longlong *)(local_38[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_140075fd0(local_res10,param_1 + 0xc0);

  uVar2 = FUN_140075da0();

  if (0 < (int)uVar2) {

    uVar9 = (ulonglong)uVar2;

    do {

      iVar3 = FUN_140075da0();

      uVar4 = FUN_140075da0();

      *(undefined4 *)(param_1 + 0xcc + (longlong)iVar3 * 4) = uVar4;

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

  }

  FUN_1400b3070(param_1);

  if (DAT_1403fb0e0 < 8) {

    FUN_140075e80(local_res10);

    iVar3 = 0;

    if ((char)local_res10[0] != '\0') {

      lVar7 = *(longlong *)(param_1 + 0x40);

      lVar5 = *(longlong *)(param_1 + 0x48) - lVar7;

      iVar8 = 0;

      lVar5 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar5),8) + lVar5;

      iVar3 = 0;

      if (lVar5 >> 7 != lVar5 >> 0x3f) {

        uVar9 = 0;

        do {

          FUN_140075bd0(lVar7 + 0x10 + uVar9 * 0xb8);

          lVar7 = *(longlong *)(param_1 + 0x40);

          iVar8 = iVar8 + 1;

          lVar5 = *(longlong *)(param_1 + 0x48) - lVar7;

          uVar9 = (ulonglong)iVar8;

          lVar5 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar5),8) + lVar5;

        } while (uVar9 < (ulonglong)((lVar5 >> 7) - (lVar5 >> 0x3f)));

      }

    }

    do {

      cVar1 = FUN_140075c20();

      if (cVar1 == '\0') break;

      iVar3 = iVar3 + 1;

    } while (iVar3 < 100);

  }

  else {

    iVar8 = 0;

    iVar3 = FUN_140075da0();

    lVar7 = (longlong)iVar3;

    if (0 < iVar3) {

      lVar5 = 0;

      do {

        FUN_140075b80(local_res10);

        lVar6 = *(longlong *)(param_1 + 0x48) - *(longlong *)(param_1 + 0x40);

        lVar6 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar6),8) + lVar6;

        if ((ulonglong)(longlong)iVar8 < (ulonglong)((lVar6 >> 7) - (lVar6 >> 0x3f))) {

          *(undefined4 *)(lVar5 + 0x10 + *(longlong *)(param_1 + 0x40)) = local_res10[0];

        }

        iVar8 = iVar8 + 1;

        lVar5 = lVar5 + 0xb8;

        lVar7 = lVar7 + -1;

      } while (lVar7 != 0);

    }

  }

  FUN_140075f20(local_res10,*(longlong *)(param_1 + 0x40) + 0x40);

  return;

}




