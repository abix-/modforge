// Address: 0x1401f2350
// Ghidra name: FUN_1401f2350
// ============ 0x1401f2350 FUN_1401f2350 (size=516) ============


undefined8 FUN_1401f2350(longlong param_1,longlong param_2,float *param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  bool bVar5;

  float fVar6;

  float *pfVar7;

  undefined8 uVar8;

  longlong lVar9;

  float *pfVar10;

  longlong lVar11;

  undefined4 uVar12;

  float extraout_XMM0_Da;

  float fVar13;

  float fVar14;

  undefined8 local_88;

  undefined8 uStack_80;

  

  lVar9 = 1;

  if ((*(int **)(param_1 + 0x1f0) == (int *)0x0) ||

     ((iVar4 = **(int **)(param_1 + 0x1f0), iVar4 != 0x16362004 && (iVar4 != 0x16161804)))) {

    bVar5 = false;

  }

  else {

    bVar5 = true;

  }

  lVar11 = (longlong)param_4;

  pfVar7 = (float *)FUN_14014b940(param_1,lVar11 * 0x18,0,param_2 + 8);

  fVar6 = DAT_14039ca34;

  fVar1 = *(float *)(param_2 + 0x18);

  uVar8 = 0;

  if (pfVar7 != (float *)0x0) {

    local_88._0_4_ = (float)*(undefined8 *)(param_2 + 0x1c);

    local_88._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x1c) >> 0x20);

    uStack_80._0_4_ = (float)*(undefined8 *)(param_2 + 0x24);

    fVar13 = (float)local_88 * fVar1;

    fVar14 = (float)uStack_80 * fVar1;

    if (bVar5) {

      fVar13 = (float)uStack_80 * fVar1;

      fVar14 = (float)local_88 * fVar1;

    }

    uStack_80 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x24) >> 0x20),fVar14);

    local_88 = CONCAT44(local_88._4_4_ * fVar1,fVar13);

    *(longlong *)(param_2 + 0x10) = lVar11;

    fVar14 = *param_3 + fVar6;

    fVar13 = param_3[1] + fVar6;

    *pfVar7 = fVar14;

    pfVar7[1] = fVar13;

    *(undefined8 *)(pfVar7 + 2) = local_88;

    *(undefined8 *)(pfVar7 + 4) = uStack_80;

    fVar1 = DAT_14030335c;

    if (1 < lVar11) {

      pfVar10 = pfVar7 + 8;

      do {

        pfVar7 = pfVar7 + 6;

        fVar2 = param_3[lVar9 * 2];

        fVar3 = param_3[lVar9 * 2 + 1];

        uVar12 = thunk_FUN_1402cd4c0((fVar3 + fVar6) - fVar13,(fVar2 + fVar6) - fVar14);

        fVar13 = (float)thunk_FUN_1402cfda0();

        fVar14 = fVar13 * fVar1 + fVar2 + fVar6;

        thunk_FUN_1402cdc50(uVar12);

        *pfVar7 = fVar14;

        lVar9 = lVar9 + 1;

        *(undefined8 *)pfVar10 = local_88;

        *(undefined8 *)(pfVar10 + 2) = uStack_80;

        fVar13 = extraout_XMM0_Da * fVar1 + fVar3 + fVar6;

        pfVar10[-1] = fVar13;

        pfVar10 = pfVar10 + 6;

      } while (lVar9 < lVar11);

    }

    uVar8 = 1;

  }

  return uVar8;

}




