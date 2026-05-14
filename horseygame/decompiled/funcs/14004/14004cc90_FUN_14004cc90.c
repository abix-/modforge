// Address: 0x14004cc90
// Ghidra name: FUN_14004cc90
// ============ 0x14004cc90 FUN_14004cc90 (size=451) ============


undefined8 FUN_14004cc90(longlong param_1,uint *param_2)



{

  int iVar1;

  undefined8 *puVar2;

  int iVar3;

  uint uVar4;

  size_t sVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  uint uVar9;

  uint uVar11;

  uint uVar13;

  uint uVar14;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined2 local_110;

  byte local_10e;

  byte local_108 [256];

  ulonglong uVar10;

  uint uVar12;

  ulonglong uVar15;

  

  uVar7 = 0;

  uVar12 = 0;

  uVar11 = 0;

  uVar13 = 0;

  uVar6 = uVar13;

  if (*(char *)(param_1 + 0x5c) == '\0') {

    if (*(longlong *)(param_1 + 0x40) == 0) {

      iVar1 = *(int *)(param_1 + 0x38);

      iVar3 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

      uVar6 = iVar3 - iVar1;

    }

    else {

      uVar6 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

    }

  }

  *param_2 = uVar6;

  puVar2 = *(undefined8 **)(param_1 + 0x40);

  if (puVar2 == (undefined8 *)0x0) {

    sVar5 = fread(&local_128,0x1b,1,*(FILE **)(param_1 + 0x30));

    if (sVar5 != 1) goto LAB_14004cd42;

  }

  else if (*(ulonglong *)(param_1 + 0x50) < (longlong)puVar2 + 0x1bU) {

LAB_14004cd42:

    *(undefined4 *)(param_1 + 0x98) = 1;

  }

  else {

    local_128 = *puVar2;

    uStack_120 = puVar2[1];

    local_118 = puVar2[2];

    local_110 = *(undefined2 *)(puVar2 + 3);

    local_10e = *(byte *)((longlong)puVar2 + 0x1a);

    *(ulonglong *)(param_1 + 0x40) = (longlong)puVar2 + 0x1bU;

  }

  if (((((char)local_128 != 'O') || (local_128._1_1_ != 'g')) || (local_128._2_1_ != 'g')) ||

     (local_128._3_1_ != 'S')) {

    return 0;

  }

  FUN_14004ce60(param_1,local_108,local_10e);

  if (local_10e < 2) {

    uVar6 = 0;

    uVar9 = uVar13;

    uVar14 = uVar13;

    if (local_10e == 0) goto LAB_14004cde6;

  }

  else {

    uVar4 = (local_10e - 2 >> 1) + 1;

    uVar8 = (ulonglong)uVar4;

    uVar10 = uVar7;

    uVar15 = uVar7;

    do {

      uVar14 = (int)uVar15 + (uint)local_108[uVar7];

      uVar15 = (ulonglong)uVar14;

      uVar9 = (int)uVar10 + (uint)local_108[uVar7 + 1];

      uVar10 = (ulonglong)uVar9;

      uVar7 = uVar7 + 2;

      uVar8 = uVar8 - 1;

    } while (uVar8 != 0);

    uVar6 = uVar13;

    uVar11 = uVar9;

    uVar12 = uVar14;

    if ((int)(uint)local_10e <= (int)(uVar4 * 2)) goto LAB_14004cde6;

  }

  uVar6 = (uint)local_108[uVar7];

  uVar9 = uVar11;

  uVar14 = uVar12;

LAB_14004cde6:

  param_2[1] = *param_2 + (uint)local_10e + uVar9 + uVar14 + uVar6 + 0x1b;

  param_2[2] = (uint)local_128._7_1_ * 0x100 + (uint)(byte)uStack_120 * 0x10000 +

               (uint)uStack_120._1_1_ * 0x1000000 + (uint)local_128._6_1_;

  FUN_140050920(param_1);

  return 1;

}




