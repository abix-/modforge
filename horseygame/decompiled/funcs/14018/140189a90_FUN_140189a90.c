// Address: 0x140189a90
// Ghidra name: FUN_140189a90
// ============ 0x140189a90 FUN_140189a90 (size=215) ============


uint FUN_140189a90(ushort *param_1,int param_2,int param_3,byte param_4)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  ushort local_28 [16];

  

  local_28[0] = 0xe6;

  local_28[1] = 0xe6;

  local_28[2] = 0xe6;

  local_28[3] = 0xe6;

  local_28[4] = 0x133;

  local_28[5] = 0x199;

  local_28[6] = 0x200;

  local_28[7] = 0x266;

  local_28[8] = 0x300;

  local_28[9] = 0x266;

  local_28[10] = 0x200;

  local_28[0xb] = 0x199;

  local_28[0xc] = 0x133;

  local_28[0xd] = 0xe6;

  local_28[0xe] = 0xe6;

  local_28[0xf] = 0xe6;

  iVar1 = (short)param_1[1] * param_2 + (short)param_1[2] * param_3;

  iVar2 = 0;

  if (7 < param_4) {

    iVar2 = 0x10;

  }

  uVar4 = ((int)(iVar1 + (iVar1 >> 0x1f & 0xffU)) >> 8) + ((uint)param_4 - iVar2) * (uint)*param_1;

  uVar5 = 0xffff8000;

  if ((-0x8001 < (int)uVar4) && (uVar5 = uVar4, 0x7fff < (int)uVar4)) {

    uVar5 = 0x7fff;

  }

  uVar3 = (uint)local_28[param_4] * (uint)*param_1 >> 8;

  uVar4 = 0x10;

  if ((0xf < uVar3) && (uVar4 = uVar3, 0xffff < uVar3)) {

    uVar4 = 0xffff;

  }

  *param_1 = (ushort)uVar4;

  return uVar5 & 0xffff;

}




