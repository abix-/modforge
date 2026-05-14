// Address: 0x1401f2560
// Ghidra name: FUN_1401f2560
// ============ 0x1401f2560 FUN_1401f2560 (size=470) ============


undefined8 FUN_1401f2560(longlong param_1,longlong param_2,longlong param_3,int param_4)



{

  float fVar1;

  int iVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  float *pfVar8;

  undefined8 uVar9;

  float *pfVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar12 = 0;

  if ((*(int **)(param_1 + 0x1f0) == (int *)0x0) ||

     ((iVar2 = **(int **)(param_1 + 0x1f0), iVar2 != 0x16362004 && (iVar2 != 0x16161804)))) {

    bVar3 = false;

  }

  else {

    bVar3 = true;

  }

  lVar13 = (longlong)param_4;

  pfVar7 = (float *)FUN_14014b940(param_1,lVar13 * 0x18,0,param_2 + 8);

  fVar6 = DAT_14039ca34;

  fVar1 = *(float *)(param_2 + 0x18);

  uVar9 = 0;

  if (pfVar7 != (float *)0x0) {

    local_18._0_4_ = (float)*(undefined8 *)(param_2 + 0x1c);

    local_18._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x1c) >> 0x20);

    uStack_10._0_4_ = (float)*(undefined8 *)(param_2 + 0x24);

    fVar4 = (float)local_18 * fVar1;

    fVar5 = (float)uStack_10 * fVar1;

    if (bVar3) {

      fVar4 = (float)uStack_10 * fVar1;

      fVar5 = (float)local_18 * fVar1;

    }

    uStack_10 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x24) >> 0x20),fVar5);

    local_18 = CONCAT44(local_18._4_4_ * fVar1,fVar4);

    *(longlong *)(param_2 + 0x10) = lVar13;

    if (3 < lVar13) {

      pfVar8 = pfVar7 + 2;

      pfVar10 = (float *)(param_3 + 8);

      lVar11 = (lVar13 - 4U >> 2) + 1;

      lVar12 = lVar11 * 4;

      do {

        *pfVar7 = pfVar10[-2] + fVar6;

        pfVar7 = pfVar7 + 0x18;

        fVar1 = pfVar10[-1];

        *(undefined8 *)pfVar8 = local_18;

        *(undefined8 *)(pfVar8 + 2) = uStack_10;

        pfVar8[-1] = fVar1 + fVar6;

        pfVar8[4] = *pfVar10 + fVar6;

        fVar1 = pfVar10[1];

        *(undefined8 *)(pfVar8 + 6) = local_18;

        *(undefined8 *)(pfVar8 + 8) = uStack_10;

        pfVar8[5] = fVar1 + fVar6;

        pfVar8[10] = pfVar10[2] + fVar6;

        fVar1 = pfVar10[3];

        *(undefined8 *)(pfVar8 + 0xc) = local_18;

        *(undefined8 *)(pfVar8 + 0xe) = uStack_10;

        pfVar8[0xb] = fVar1 + fVar6;

        pfVar8[0x10] = pfVar10[4] + fVar6;

        fVar1 = pfVar10[5];

        pfVar10 = pfVar10 + 8;

        *(undefined8 *)(pfVar8 + 0x12) = local_18;

        *(undefined8 *)(pfVar8 + 0x14) = uStack_10;

        pfVar8[0x11] = fVar1 + fVar6;

        pfVar8 = pfVar8 + 0x18;

        lVar11 = lVar11 + -1;

      } while (lVar11 != 0);

    }

    if (lVar12 < lVar13) {

      pfVar7 = pfVar7 + 2;

      do {

        pfVar7[-2] = *(float *)(param_3 + lVar12 * 8) + fVar6;

        fVar1 = *(float *)(param_3 + 4 + lVar12 * 8);

        lVar12 = lVar12 + 1;

        *(undefined8 *)pfVar7 = local_18;

        *(undefined8 *)(pfVar7 + 2) = uStack_10;

        pfVar7[-1] = fVar1 + fVar6;

        pfVar7 = pfVar7 + 6;

      } while (lVar12 < lVar13);

    }

    uVar9 = 1;

  }

  return uVar9;

}




