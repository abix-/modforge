// Address: 0x14009ddb0
// Ghidra name: FUN_14009ddb0
// ============ 0x14009ddb0 FUN_14009ddb0 (size=922) ============


longlong FUN_14009ddb0(longlong param_1,char *param_2,undefined4 param_3)



{

  float fVar1;

  char cVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  short sVar9;

  undefined8 *puVar10;

  undefined8 *puVar11;

  undefined8 *puVar12;

  uint uVar13;

  undefined8 *puVar14;

  int iVar15;

  int iVar16;

  longlong lVar17;

  size_t sVar18;

  float *pfVar19;

  longlong *plVar20;

  longlong lVar21;

  int *piVar22;

  undefined4 *puVar23;

  longlong *plVar24;

  float fVar25;

  undefined4 local_res20 [2];

  undefined4 local_b8 [2];

  undefined4 *local_b0;

  ulonglong local_a8;

  longlong *local_a0;

  longlong local_98;

  undefined8 local_90;

  undefined8 uStack_88;

  undefined8 local_80;

  undefined8 local_78;

  

  plVar24 = (longlong *)(param_1 + 0x10);

  *plVar24 = 0;

  *(undefined8 *)(param_1 + 0x18) = 0;

  local_a0 = plVar24;

  lVar17 = FUN_1402c704c(0x30);

  *(longlong *)lVar17 = lVar17;

  *(longlong *)(lVar17 + 8) = lVar17;

  *(longlong *)(lVar17 + 0x10) = lVar17;

  *(undefined2 *)(lVar17 + 0x18) = 0x101;

  *plVar24 = lVar17;

  *(undefined4 *)(param_1 + 0x20) = 0;

  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;

  *(undefined8 *)(param_1 + 0x28) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x30) = 0;

  *(undefined4 *)(param_1 + 0x34) = 0x3fc00000;

  *(undefined4 *)(param_1 + 8) = param_3;

  *(undefined8 *)(param_1 + 0x40) = 0;

  *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x50) = 0x49742400;

  *(undefined4 *)(param_1 + 0x54) = 0x41200000;

  *(undefined4 *)(param_1 + 0x3c) = 0;

  *(undefined4 *)(param_1 + 0x38) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x48) = 0xff000000;

  local_res20[0] = 0;

  local_90 = 0;

  uStack_88 = 0;

  local_80 = 0;

  local_78 = 0;

  sVar18 = strlen(param_2);

  FUN_140027e30(&local_90,param_2,sVar18);

  lVar17 = FUN_1400c43d0(&local_90,local_res20);

  if (lVar17 != 0) {

    piVar22 = (int *)((longlong)*(int *)(lVar17 + 5) + 10 + lVar17);

    iVar15 = *piVar22;

    lVar21 = (longlong)*(int *)((longlong)piVar22 + (longlong)iVar15 + 5);

    puVar23 = (undefined4 *)((longlong)piVar22 + lVar21 + (longlong)iVar15 + 0xe);

    uVar13 = *(int *)((longlong)piVar22 + lVar21 + 10 + (longlong)iVar15) / 0x14;

    local_b0 = puVar23;

    local_98 = lVar17;

    iVar15 = FUN_140072ca0(*(undefined4 *)(param_1 + 8));

    iVar16 = FUN_140072cc0(*(undefined4 *)(param_1 + 8));

    fVar1 = DAT_14030c670;

    if (0 < (int)uVar13) {

      local_a8 = (ulonglong)uVar13;

      do {

        local_b8[0] = *puVar23;

        sVar3 = *(short *)(puVar23 + 1);

        sVar4 = *(short *)((longlong)puVar23 + 6);

        sVar5 = *(short *)(puVar23 + 2);

        sVar6 = *(short *)((longlong)puVar23 + 10);

        sVar7 = *(short *)(puVar23 + 3);

        sVar8 = *(short *)((longlong)puVar23 + 0xe);

        sVar9 = *(short *)(puVar23 + 4);

        pfVar19 = (float *)FUN_1402c704c(0x28);

        plVar24 = local_a0;

        fVar25 = (float)(int)sVar5;

        *pfVar19 = fVar25;

        pfVar19[1] = (float)(int)sVar6;

        pfVar19[4] = (float)(int)sVar3 / (float)iVar15 + fVar1;

        pfVar19[5] = (float)((int)sVar5 + (int)sVar3) / (float)iVar15 - fVar1;

        pfVar19[6] = (float)(int)sVar4 / (float)iVar16 + fVar1;

        pfVar19[7] = (float)((int)sVar6 + (int)sVar4) / (float)iVar16 - fVar1;

        pfVar19[2] = (float)(int)sVar7;

        pfVar19[3] = (float)(int)sVar8;

        pfVar19[8] = 0.0;

        pfVar19[9] = (float)(int)sVar9 - fVar25;

        plVar20 = (longlong *)FUN_14009f4a0(local_a0,local_b8);

        *plVar20 = (longlong)pfVar19;

        puVar23 = local_b0 + 5;

        local_a8 = local_a8 - 1;

        local_b0 = puVar23;

      } while (local_a8 != 0);

      local_a8 = 0;

      lVar17 = local_98;

    }

    local_b8[0] = 0x41;

    plVar20 = (longlong *)FUN_14009f4a0(plVar24,local_b8);

    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*plVar20 + 4);

    local_b8[0] = 0x41;

    plVar20 = (longlong *)FUN_14009f4a0(plVar24,local_b8);

    fVar1 = *(float *)(*plVar20 + 0xc);

    puVar10 = (undefined8 *)*plVar24;

    puVar11 = (undefined8 *)*puVar10;

    while (puVar11 != puVar10) {

      *(float *)(puVar11[5] + 0xc) = *(float *)(puVar11[5] + 0xc) - fVar1;

      puVar12 = (undefined8 *)puVar11[2];

      if (*(char *)((longlong)puVar12 + 0x19) == '\0') {

        cVar2 = *(char *)((longlong)*puVar12 + 0x19);

        puVar11 = puVar12;

        puVar12 = (undefined8 *)*puVar12;

        while (cVar2 == '\0') {

          cVar2 = *(char *)((longlong)*puVar12 + 0x19);

          puVar11 = puVar12;

          puVar12 = (undefined8 *)*puVar12;

        }

      }

      else {

        cVar2 = *(char *)((longlong)puVar11[1] + 0x19);

        puVar14 = (undefined8 *)puVar11[1];

        puVar12 = puVar11;

        while ((puVar11 = puVar14, cVar2 == '\0' && (puVar12 == (undefined8 *)puVar11[2]))) {

          cVar2 = *(char *)((longlong)puVar11[1] + 0x19);

          puVar14 = (undefined8 *)puVar11[1];

          puVar12 = puVar11;

        }

      }

    }

    FUN_1400c4de0(lVar17);

  }

  return param_1;

}




