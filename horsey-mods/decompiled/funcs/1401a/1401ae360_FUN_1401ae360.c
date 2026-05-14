// Address: 0x1401ae360
// Ghidra name: FUN_1401ae360
// ============ 0x1401ae360 FUN_1401ae360 (size=1332) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401ae360(longlong param_1,longlong *param_2,uint param_3,longlong *param_4)



{

  undefined4 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  code *pcVar4;

  uint uVar5;

  undefined8 *puVar6;

  longlong lVar7;

  byte bVar8;

  longlong lVar9;

  longlong lVar10;

  undefined4 *puVar11;

  undefined4 *puVar12;

  uint uVar13;

  uint uVar14;

  longlong *plVar15;

  ulonglong uVar16;

  undefined4 *puVar17;

  undefined4 uVar18;

  ulonglong uVar19;

  longlong lVar20;

  uint uVar21;

  uint uVar22;

  uint local_res8;

  undefined8 auStack_100 [5];

  longlong *local_d8;

  uint local_d0;

  uint local_c8;

  undefined8 local_b8;

  longlong local_a8;

  undefined8 uStack_a0;

  undefined4 local_98;

  undefined4 local_94;

  undefined4 local_88 [2];

  undefined8 local_80;

  longlong local_78;

  undefined8 local_70;

  undefined8 local_68;

  uint local_60;

  uint local_5c;

  uint local_58;

  undefined4 *local_50;

  

  lVar2 = *(longlong *)(param_1 + 0x110);

  uVar21 = 0;

  uVar19 = (ulonglong)param_3;

  uVar22 = 0xffffffff;

  local_res8 = 0;

  local_b8._0_4_ = 0xffffffff;

  uVar16 = (ulonglong)param_3;

  uVar14 = 0xffffffff;

  plVar15 = param_2;

  if (param_3 != 0) {

    do {

      bVar8 = (byte)(int)plVar15[1];

      uVar13 = *(uint *)(*plVar15 + 0xc) >> (bVar8 & 0x1f);

      local_b8._0_4_ = *(uint *)(*plVar15 + 0x10) >> (bVar8 & 0x1f);

      if (uVar22 <= uVar13) {

        uVar13 = uVar22;

      }

      uVar22 = uVar13;

      if (uVar14 <= (uint)local_b8) {

        local_b8._0_4_ = uVar14;

      }

      uVar19 = uVar19 - 1;

      plVar15 = plVar15 + 8;

      uVar14 = (uint)local_b8;

    } while (uVar19 != 0);

  }

  if (param_4 != (longlong *)0x0) {

    uVar14 = *(uint *)(*param_4 + 0xc) >> (*(byte *)((longlong)param_4 + 0x1e) & 0x1f);

    uVar13 = *(uint *)(*param_4 + 0x10) >> (*(byte *)((longlong)param_4 + 0x1e) & 0x1f);

    if (uVar22 <= uVar14) {

      uVar14 = uVar22;

    }

    uVar22 = uVar14;

    if (uVar13 < (uint)local_b8) {

      local_b8._0_4_ = uVar13;

    }

  }

  local_a8 = lVar2;

  if (param_3 != 0) {

    plVar15 = param_2 + 7;

    do {

      if (*(int *)plVar15[-7] == 2) {

        uVar18 = 0;

      }

      else {

        uVar18 = *(undefined4 *)((longlong)plVar15 + -0x2c);

      }

      local_c8 = 7;

      local_d0 = CONCAT31(local_d0._1_3_,(char)*plVar15);

      local_d8 = (longlong *)CONCAT44(local_d8._4_4_,(int)plVar15[-6]);

      auStack_100[0] = 0x1401ae474;

      puVar6 = (undefined8 *)FUN_1401bbea0(lVar2,param_1,(int *)plVar15[-7],uVar18);

      *(undefined8 **)(param_1 + 0x168 + (ulonglong)*(uint *)(param_1 + 0x1a8) * 8) = puVar6;

      *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;

      auStack_100[0] = 0x1401ae493;

      FUN_1401bdb50(param_1,*puVar6);

      uVar14 = uVar21 + 1;

      uVar13 = local_res8 + 1;

      if (*(int *)((longlong)plVar15 + -0x14) - 2U < 2) {

        local_c8 = 7;

        local_d0 = CONCAT31(local_d0._1_3_,*(undefined1 *)((longlong)plVar15 + 1));

        local_d8 = (longlong *)CONCAT44(local_d8._4_4_,(int)plVar15[-1]);

        auStack_100[0] = 0x1401ae4d1;

        puVar6 = (undefined8 *)

                 FUN_1401bbea0(lVar2,param_1,plVar15[-2],*(undefined4 *)((longlong)plVar15 + -4));

        *(undefined8 **)(param_1 + 0x1b0 + (ulonglong)*(uint *)(param_1 + 0x1f0) * 8) = puVar6;

        *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;

        auStack_100[0] = 0x1401ae4f0;

        FUN_1401bdb50(param_1,*puVar6);

        uVar14 = uVar21 + 2;

        uVar13 = local_res8 + 2;

      }

      local_res8 = uVar13;

      uVar21 = uVar14;

      plVar15 = plVar15 + 8;

      uVar16 = uVar16 - 1;

    } while (uVar16 != 0);

  }

  lVar2 = local_a8;

  if (param_4 != (longlong *)0x0) {

    local_c8 = 8;

    local_d0 = CONCAT31(local_d0._1_3_,*(undefined1 *)((longlong)param_4 + 0x1c));

    local_d8 = (longlong *)CONCAT44(local_d8._4_4_,(uint)*(byte *)((longlong)param_4 + 0x1e));

    auStack_100[0] = 0x1401ae54f;

    puVar6 = (undefined8 *)

             FUN_1401bbea0(local_a8,param_1,*param_4,*(undefined1 *)((longlong)param_4 + 0x1f));

    *(undefined8 **)(param_1 + 0x1f8) = puVar6;

    auStack_100[0] = 0x1401ae561;

    FUN_1401bdb50(param_1,*puVar6);

    uVar21 = uVar21 + 1;

  }

  auStack_100[0] = 0x1401ae579;

  lVar7 = FUN_1401baa10(lVar2,param_2,param_3,param_4);

  uVar14 = (uint)local_b8;

  if (lVar7 == 0) {

    return;

  }

  uVar16 = (ulonglong)(uint)local_b8;

  local_c8 = (uint)local_b8;

  auStack_100[0] = 0x1401ae5af;

  local_d8 = param_4;

  local_d0 = uVar22;

  local_b8 = (undefined8 *)FUN_1401ba340(lVar2,lVar7,param_2,param_3);

  if (local_b8 == (undefined8 *)0x0) {

    return;

  }

  auStack_100[0] = 0x1401ae5c7;

  FUN_1401bd940(param_1,local_b8);

  uVar19 = (ulonglong)uVar21 * 0x10 + 0xf;

  if (uVar19 <= (ulonglong)uVar21 * 0x10) {

    uVar19 = 0xffffffffffffff0;

  }

  auStack_100[0] = 0x1401ae5ea;

  lVar2 = -(uVar19 & 0xfffffffffffffff0);

  uVar13 = 0;

  puVar1 = (undefined4 *)((longlong)&local_b8 + lVar2);

  if (param_3 < 4) {

    if (param_3 == 0) goto LAB_1401ae792;

    lVar20 = 0;

    lVar10 = 0;

  }

  else {

    puVar17 = (undefined4 *)((longlong)param_2 + 0x14);

    lVar10 = 0;

    uVar5 = (param_3 - 4 >> 2) + 1;

    uVar19 = (ulonglong)uVar5;

    uVar13 = uVar5 * 4;

    lVar20 = (ulonglong)uVar5 * 4;

    puVar11 = puVar1;

    do {

      lVar9 = lVar10 + 1;

      *puVar11 = puVar17[-1];

      puVar11[1] = *puVar17;

      puVar11[2] = puVar17[1];

      puVar11[3] = puVar17[2];

      puVar12 = puVar11 + 4;

      if (puVar17[4] - 2 < 2) {

        lVar9 = lVar10 + 2;

        puVar12 = puVar11 + 8;

      }

      lVar10 = lVar9 + 1;

      *puVar12 = puVar17[0xf];

      puVar12[1] = puVar17[0x10];

      puVar12[2] = puVar17[0x11];

      puVar12[3] = puVar17[0x12];

      puVar11 = puVar12 + 4;

      if (puVar17[0x14] - 2 < 2) {

        lVar10 = lVar9 + 2;

        puVar11 = puVar12 + 8;

      }

      lVar9 = lVar10 + 1;

      *puVar11 = puVar17[0x1f];

      puVar11[1] = puVar17[0x20];

      puVar11[2] = puVar17[0x21];

      puVar11[3] = puVar17[0x22];

      puVar12 = puVar11 + 4;

      if (puVar17[0x24] - 2 < 2) {

        lVar9 = lVar10 + 2;

        puVar12 = puVar11 + 8;

      }

      lVar10 = lVar9 + 1;

      *puVar12 = puVar17[0x2f];

      puVar12[1] = puVar17[0x30];

      puVar12[2] = puVar17[0x31];

      puVar12[3] = puVar17[0x32];

      puVar11 = puVar12 + 4;

      if (puVar17[0x34] - 2 < 2) {

        lVar10 = lVar9 + 2;

        puVar11 = puVar12 + 8;

      }

      puVar17 = puVar17 + 0x40;

      uVar19 = uVar19 - 1;

    } while (uVar19 != 0);

    if (param_3 <= uVar13) goto LAB_1401ae792;

  }

  puVar17 = (undefined4 *)((longlong)param_2 + lVar20 * 0x40 + 0x14);

  uVar19 = (ulonglong)(param_3 - uVar13);

  puVar11 = puVar1 + lVar10 * 4;

  do {

    *puVar11 = puVar17[-1];

    puVar11[1] = *puVar17;

    puVar11[2] = puVar17[1];

    puVar11[3] = puVar17[2];

    puVar12 = puVar11 + 4;

    if (puVar17[4] - 2 < 2) {

      puVar12 = puVar11 + 8;

    }

    puVar17 = puVar17 + 0x10;

    uVar19 = uVar19 - 1;

    puVar11 = puVar12;

  } while (uVar19 != 0);

LAB_1401ae792:

  if (param_4 != (longlong *)0x0) {

    puVar1[(ulonglong)local_res8 * 4] = (int)param_4[1];

    *(uint *)((longlong)&local_b8 + (ulonglong)local_res8 * 0x10 + lVar2 + 4) =

         (uint)*(byte *)((longlong)param_4 + 0x1d);

  }

  uVar3 = *(undefined8 *)(param_1 + 0x118);

  local_88[0] = 0x2b;

  local_80 = 0;

  local_70 = *local_b8;

  local_5c = uVar14;

  local_68 = 0;

  pcVar4 = *(code **)(local_a8 + 0xa18);

  local_78 = lVar7;

  local_60 = uVar22;

  local_58 = uVar21;

  local_50 = puVar1;

  *(undefined8 *)((longlong)auStack_100 + lVar2) = 0x1401ae809;

  (*pcVar4)(uVar3,local_88,0);

  local_a8 = 0;

  local_98 = 0;

  local_94 = 0x3f800000;

  uStack_a0 = CONCAT44((float)uVar16,(float)uVar22);

  *(undefined8 *)((longlong)auStack_100 + lVar2) = 0x1401ae848;

  FUN_1401bd200(param_1,&local_a8);

  local_a8 = 0;

  uStack_a0 = CONCAT44(uVar14,uVar22);

  *(undefined8 *)((longlong)auStack_100 + lVar2) = 0x1401ae861;

  FUN_1401bd180(param_1,&local_a8);

  local_a8 = _DAT_14030a340;

  uStack_a0 = _UNK_14030a348;

  *(undefined8 *)((longlong)auStack_100 + lVar2) = 0x1401ae879;

  FUN_1401bd130(param_1,&local_a8);

  *(undefined8 *)((longlong)auStack_100 + lVar2) = 0x1401ae883;

  FUN_1401bd1d0(param_1,0);

  return;

}




