// Address: 0x14028b0a0
// Ghidra name: FUN_14028b0a0
// ============ 0x14028b0a0 FUN_14028b0a0 (size=424) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_14028b0a0(short *param_1,ulonglong param_2)



{

  short sVar1;

  uint uVar2;

  int iVar3;

  ulonglong uVar4;

  longlong lVar5;

  short *psVar6;

  uint uVar7;

  longlong lVar8;

  int iVar9;

  int iVar10;

  ulonglong uVar11;

  int iVar12;

  double dVar13;

  

  iVar10 = (int)param_1[0x10];

  uVar11 = (ulonglong)(ushort)param_1[0x13];

  iVar9 = (int)param_1[0x11];

  uVar4 = *(ulonglong *)(param_1 + 0x34);

  iVar12 = (iVar10 >> 0x1f & 0xfffffffeU) + 1;

  if (uVar4 < uVar11) {

    uVar4 = (longlong)(int)(iVar10 - (uint)(ushort)param_1[0x14] * iVar12) * uVar4;

    param_2 = uVar4 % uVar11;

    iVar10 = (uint)(ushort)param_1[0x14] * iVar12 + (int)(uVar4 / uVar11);

  }

  else if ((*(int *)(param_1 + 10) != 0) && (param_1[0x15] != 0)) {

    uVar2 = (uint)(ushort)param_1[0x15];

    psVar6 = param_1;

    iVar3 = FUN_14028af90();

    uVar7 = (uVar2 + (int)uVar4) - iVar3;

    param_2 = (ulonglong)uVar7;

    if (0 < (int)uVar7) {

      iVar12 = (iVar10 - (uint)(ushort)psVar6[0x16] * iVar12) * uVar7;

      param_2 = (longlong)iVar12 % (longlong)(int)uVar2 & 0xffffffff;

      iVar10 = iVar10 - iVar12 / (int)uVar2;

    }

  }

  sVar1 = *param_1;

  if (sVar1 == 2) {

    dVar13 = (double)thunk_FUN_1402d0f80(((double)*(uint *)(param_1 + 0x3c) * DAT_140333080) /

                                         _DAT_140333088,param_2);

    iVar12 = (int)(dVar13 * (double)iVar10);

  }

  else if (sVar1 == 4) {

    iVar12 = -iVar10;

    if (*(uint *)(param_1 + 0x3c) < 0xb4) {

      iVar12 = iVar10;

    }

  }

  else {

    if (sVar1 != 8) {

      if (sVar1 == 0x10) {

        iVar9 = iVar9 + ((uint)(iVar10 * *(int *)(param_1 + 0x3c) * 2) / 0x168 - iVar10);

      }

      else if (sVar1 == 0x20) {

        iVar9 = iVar9 + (iVar10 - (uint)(iVar10 * *(int *)(param_1 + 0x3c) * 2) / 0x168);

      }

      goto LAB_14028b224;

    }

    lVar8 = (longlong)((ulonglong)*(uint *)(param_1 + 0x3c) * (longlong)iVar10 * 2) / 0x168 -

            (longlong)iVar10;

    lVar5 = -lVar8;

    if (lVar5 < 0) {

      lVar5 = lVar8;

    }

    iVar12 = (int)lVar5 * 2 - iVar10;

  }

  iVar9 = iVar9 + iVar12;

LAB_14028b224:

  return (int)((double)iVar9 * *(double *)(param_1 + 0x44));

}




