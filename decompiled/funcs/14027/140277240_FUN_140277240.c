// Address: 0x140277240
// Ghidra name: FUN_140277240
// ============ 0x140277240 FUN_140277240 (size=610) ============


undefined8 FUN_140277240(byte *param_1,undefined8 param_2,longlong param_3)



{

  byte *pbVar1;

  byte bVar2;

  byte bVar3;

  undefined8 uVar4;

  undefined2 uVar5;

  uint *puVar6;

  uint *puVar7;

  byte *pbVar8;

  int iVar9;

  longlong lVar10;

  uint uVar11;

  float fVar12;

  undefined4 uVar13;

  undefined4 uVar14;

  int local_res8 [2];

  int local_res18 [4];

  

  *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;

  pbVar8 = param_1 + 2;

  bVar2 = *param_1;

  puVar7 = (uint *)(param_3 + 8);

  bVar3 = param_1[1];

  if ((bVar2 & 0x10) != 0) {

    *(undefined2 *)puVar7 = *(undefined2 *)pbVar8;

    pbVar8 = param_1 + 5;

    *(byte *)(param_3 + 10) = param_1[4];

  }

  lVar10 = param_3;

  if ((bVar2 & 0x20) != 0) {

    uVar13 = DAT_14037f688;

    uVar14 = DAT_1403053f0;

    fVar12 = (float)FUN_140276c60((uint)*pbVar8 << 7 | (uint)*pbVar8,0,DAT_14037f688,0,DAT_1403053f0

                                 );

    *(short *)(lVar10 + 0x24) = (short)(int)fVar12;

    fVar12 = (float)FUN_140276c60((uint)pbVar8[1] << 7 | (uint)pbVar8[1],0,uVar13,0,uVar14);

    pbVar8 = pbVar8 + 2;

    *(short *)(lVar10 + 0x26) = (short)(int)fVar12;

  }

  puVar6 = puVar7;

  if ((bVar2 & 0x40) != 0) {

    puVar6 = (uint *)(lVar10 + 8);

    *(byte *)(lVar10 + 0xd) = *pbVar8;

    *(byte *)(lVar10 + 0xe) = pbVar8[1];

    pbVar1 = pbVar8 + 2;

    pbVar8 = pbVar8 + 3;

    *(byte *)(lVar10 + 0xf) = *pbVar1;

  }

  if ((char)bVar2 < '\0') {

    *(undefined4 *)(lVar10 + 0x1c) = *(undefined4 *)pbVar8;

    pbVar8 = pbVar8 + 4;

    puVar7 = puVar6;

  }

  uVar13 = DAT_14037f690;

  if ((bVar3 & 1) != 0) {

    uVar14 = *(undefined4 *)pbVar8;

    *(undefined4 *)(lVar10 + 0x10) = uVar14;

    local_res8[0] = (int)(short)uVar14;

    uVar11 = -(uint)((*puVar7 & 0x80000) != 0) & 1000;

    local_res18[0] = (int)(short)((uint)uVar14 >> 0x10);

    FUN_140276f00(local_res8,local_res18,uVar13);

    local_res8[0] = local_res8[0] + uVar11;

    iVar9 = 0x7fff;

    if ((local_res8[0] < 0x8000) && (iVar9 = local_res8[0], local_res8[0] < -0x8000)) {

      iVar9 = -0x8000;

    }

    *(short *)(param_3 + 0x10) = (short)iVar9;

    local_res18[0] = local_res18[0] + uVar11;

    if (local_res18[0] < 0x8000) {

      uVar5 = (undefined2)local_res18[0];

      if (local_res18[0] < -0x8000) {

        uVar5 = 0x8000;

      }

    }

    else {

      uVar5 = 0x7fff;

    }

    *(undefined2 *)(param_3 + 0x12) = uVar5;

    puVar7 = (uint *)(param_3 + 8);

    pbVar8 = pbVar8 + 4;

  }

  uVar13 = DAT_14037f680;

  if ((bVar3 >> 1 & 1) != 0) {

    uVar14 = *(undefined4 *)pbVar8;

    *(undefined4 *)(param_3 + 0x14) = uVar14;

    local_res8[0] = (int)(short)uVar14;

    uVar11 = -(uint)((*puVar7 & 0x100000) != 0) & 1000;

    local_res18[0] = (int)(short)((uint)uVar14 >> 0x10);

    FUN_140276f00(local_res8,local_res18,uVar13);

    local_res8[0] = local_res8[0] + uVar11;

    if (local_res8[0] < 0x8000) {

      uVar5 = (undefined2)local_res8[0];

      if (local_res8[0] < -0x8000) {

        uVar5 = 0x8000;

      }

    }

    else {

      uVar5 = 0x7fff;

    }

    *(undefined2 *)(param_3 + 0x14) = uVar5;

    local_res18[0] = local_res18[0] + uVar11;

    iVar9 = 0x7fff;

    if ((local_res18[0] < 0x8000) && (iVar9 = local_res18[0], local_res18[0] < -0x8000)) {

      iVar9 = -0x8000;

    }

    *(short *)(param_3 + 0x16) = (short)iVar9;

    pbVar8 = pbVar8 + 4;

  }

  if ((bVar3 >> 2 & 1) != 0) {

    *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)pbVar8;

    pbVar1 = pbVar8 + 4;

    pbVar8 = pbVar8 + 6;

    *(undefined2 *)(param_3 + 0x2c) = *(undefined2 *)pbVar1;

  }

  if ((bVar3 >> 3 & 1) != 0) {

    *(undefined4 *)(param_3 + 0x2e) = *(undefined4 *)pbVar8;

    pbVar1 = pbVar8 + 4;

    pbVar8 = pbVar8 + 6;

    *(undefined2 *)(param_3 + 0x32) = *(undefined2 *)pbVar1;

  }

  if ((bVar3 >> 4 & 1) != 0) {

    uVar4 = *(undefined8 *)(pbVar8 + 8);

    *(undefined8 *)(param_3 + 0x34) = *(undefined8 *)pbVar8;

    *(undefined8 *)(param_3 + 0x3c) = uVar4;

  }

  return 1;

}




