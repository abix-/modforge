// Address: 0x1401c6d10
// Ghidra name: FUN_1401c6d10
// ============ 0x1401c6d10 FUN_1401c6d10 (size=1191) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1401c6d10(longlong param_1,uint *param_2)



{

  uint uVar1;

  int *piVar2;

  int *piVar3;

  longlong lVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  undefined4 uVar10;

  ulonglong uVar11;

  ulonglong in_RAX;

  ulonglong *puVar12;

  undefined1 uVar13;

  uint uVar14;

  longlong lVar15;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 uStack_14;

  

  if (param_2 == (uint *)0x0) {

    return in_RAX & 0xffffffffffffff00;

  }

  FUN_1402f94c0(param_2,0,0x148);

  uVar9 = _UNK_14034a8b8;

  uVar8 = _DAT_14034a8b0;

  uVar7 = _UNK_140313a78;

  uVar6 = _DAT_140313a70;

  lVar15 = 0x48;

  *param_2 = (uint)*(byte *)(param_1 + 0x59);

  puVar12 = (ulonglong *)(param_2 + 0x16);

  uVar14 = 2;

  do {

    local_38 = uVar8;

    uVar11 = local_38;

    uStack_30 = uVar9;

    uStack_14 = CONCAT31(uStack_14._1_3_,0xf);

    local_28 = uVar6;

    uStack_20 = uVar7;

    local_38._4_4_ = (undefined4)(uVar8 >> 0x20);

    uVar10 = local_38._4_4_;

    if (uVar14 - 2 < *(uint *)(param_1 + 0x90)) {

      lVar4 = *(longlong *)(param_1 + 0x88);

      uVar5 = *(undefined8 *)(lVar4 + -0x2c + lVar15);

      piVar2 = (int *)(lVar4 + -0x44 + lVar15);

      piVar3 = (int *)(lVar4 + -0x34 + lVar15);

      uVar13 = 0xf;

      if ((char)((ulonglong)uVar5 >> 0x10) != '\0') {

        uVar13 = (char)uVar5;

      }

      local_38 = CONCAT44(local_38._4_4_,(int)((ulonglong)uVar5 >> 8)) & 0xffffffff000000ff;

      uStack_14 = CONCAT31(uStack_14._1_3_,uVar13);

      uStack_30 = CONCAT44(*(undefined4 *)(&DAT_1403e4368 + (longlong)piVar2[1] * 4),

                           *(undefined4 *)(&DAT_1403e4368 + (longlong)*piVar2 * 4));

      local_28 = CONCAT44(*(undefined4 *)(&DAT_1403e43a0 + (longlong)piVar2[3] * 4),

                          *(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar2[2] * 4));

      uStack_20 = CONCAT44(*(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar3[1] * 4),

                           *(undefined4 *)(&DAT_1403e43a0 + (longlong)*piVar3 * 4));

      uVar11 = local_38;

      if (uVar14 != 2) {

        param_2[1] = 1;

      }

    }

    local_38 = uVar11;

    puVar12[-10] = local_38;

    puVar12[-9] = uStack_30;

    puVar12[-8] = local_28;

    puVar12[-7] = uStack_20;

    puVar12[-6] = CONCAT44(uStack_14,4);

    local_38 = uVar8;

    uStack_30 = uVar9;

    uStack_14 = CONCAT31(uStack_14._1_3_,0xf);

    local_28 = uVar6;

    uStack_20 = uVar7;

    if (uVar14 - 1 < *(uint *)(param_1 + 0x90)) {

      lVar4 = *(longlong *)(param_1 + 0x88);

      uVar5 = *(undefined8 *)(lVar4 + -8 + lVar15);

      piVar2 = (int *)(lVar4 + -0x20 + lVar15);

      piVar3 = (int *)(lVar4 + -0x10 + lVar15);

      uVar13 = 0xf;

      if ((char)((ulonglong)uVar5 >> 0x10) != '\0') {

        uVar13 = (char)uVar5;

      }

      local_38 = CONCAT44(uVar10,(int)((ulonglong)uVar5 >> 8)) & 0xffffffff000000ff;

      uStack_14 = CONCAT31(uStack_14._1_3_,uVar13);

      uStack_30 = CONCAT44(*(undefined4 *)(&DAT_1403e4368 + (longlong)piVar2[1] * 4),

                           *(undefined4 *)(&DAT_1403e4368 + (longlong)*piVar2 * 4));

      local_28 = CONCAT44(*(undefined4 *)(&DAT_1403e43a0 + (longlong)piVar2[3] * 4),

                          *(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar2[2] * 4));

      uStack_20 = CONCAT44(*(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar3[1] * 4),

                           *(undefined4 *)(&DAT_1403e43a0 + (longlong)*piVar3 * 4));

      if (uVar14 != 1) {

        param_2[1] = 1;

      }

    }

    puVar12[-5] = local_38;

    puVar12[-4] = uStack_30;

    puVar12[-3] = local_28;

    puVar12[-2] = uStack_20;

    puVar12[-1] = CONCAT44(uStack_14,4);

    local_38 = uVar8;

    uStack_30 = uVar9;

    uStack_14 = CONCAT31(uStack_14._1_3_,0xf);

    local_28 = uVar6;

    uStack_20 = uVar7;

    if (uVar14 < *(uint *)(param_1 + 0x90)) {

      lVar4 = *(longlong *)(param_1 + 0x88);

      uVar5 = *(undefined8 *)(lVar4 + 0x1c + lVar15);

      piVar2 = (int *)(lVar4 + 4 + lVar15);

      piVar3 = (int *)(lVar4 + 0x14 + lVar15);

      uVar13 = 0xf;

      if ((char)((ulonglong)uVar5 >> 0x10) != '\0') {

        uVar13 = (char)uVar5;

      }

      local_38 = CONCAT44(uVar10,(int)((ulonglong)uVar5 >> 8)) & 0xffffffff000000ff;

      uStack_14 = CONCAT31(uStack_14._1_3_,uVar13);

      uStack_30 = CONCAT44(*(undefined4 *)(&DAT_1403e4368 + (longlong)piVar2[1] * 4),

                           *(undefined4 *)(&DAT_1403e4368 + (longlong)*piVar2 * 4));

      local_28 = CONCAT44(*(undefined4 *)(&DAT_1403e43a0 + (longlong)piVar2[3] * 4),

                          *(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar2[2] * 4));

      uStack_20 = CONCAT44(*(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar3[1] * 4),

                           *(undefined4 *)(&DAT_1403e43a0 + (longlong)*piVar3 * 4));

      if (uVar14 != 0) {

        param_2[1] = 1;

      }

    }

    *puVar12 = local_38;

    puVar12[1] = uStack_30;

    puVar12[2] = local_28;

    puVar12[3] = uStack_20;

    puVar12[4] = CONCAT44(uStack_14,4);

    local_38 = uVar8;

    uStack_30 = uVar9;

    uStack_14 = CONCAT31(uStack_14._1_3_,0xf);

    local_28 = uVar6;

    uStack_20 = uVar7;

    if (uVar14 + 1 < *(uint *)(param_1 + 0x90)) {

      lVar4 = *(longlong *)(param_1 + 0x88);

      uVar5 = *(undefined8 *)(lVar4 + 0x40 + lVar15);

      piVar2 = (int *)(lVar4 + 0x28 + lVar15);

      piVar3 = (int *)(lVar4 + 0x38 + lVar15);

      uVar13 = 0xf;

      if ((char)((ulonglong)uVar5 >> 0x10) != '\0') {

        uVar13 = (char)uVar5;

      }

      local_38 = CONCAT44(uVar10,(int)((ulonglong)uVar5 >> 8)) & 0xffffffff000000ff;

      uStack_14 = CONCAT31(uStack_14._1_3_,uVar13);

      uStack_30 = CONCAT44(*(undefined4 *)(&DAT_1403e4368 + (longlong)piVar2[1] * 4),

                           *(undefined4 *)(&DAT_1403e4368 + (longlong)*piVar2 * 4));

      local_28 = CONCAT44(*(undefined4 *)(&DAT_1403e43a0 + (longlong)piVar2[3] * 4),

                          *(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar2[2] * 4));

      uStack_20 = CONCAT44(*(undefined4 *)(&DAT_1403e43d8 + (longlong)piVar3[1] * 4),

                           *(undefined4 *)(&DAT_1403e43a0 + (longlong)*piVar3 * 4));

      if (uVar14 != 0xffffffff) {

        param_2[1] = 1;

      }

    }

    lVar15 = lVar15 + 0x90;

    puVar12[5] = local_38;

    puVar12[6] = uStack_30;

    uVar1 = uVar14 + 2;

    puVar12[7] = local_28;

    puVar12[8] = uStack_20;

    puVar12[9] = CONCAT44(uStack_14,4);

    puVar12 = puVar12 + 0x14;

    uVar14 = uVar14 + 4;

  } while (uVar1 < 8);

  return CONCAT71((int7)((ulonglong)puVar12 >> 8),1);

}




