// Address: 0x140188d80
// Ghidra name: FUN_140188d80
// ============ 0x140188d80 FUN_140188d80 (size=487) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint FUN_140188d80(char *param_1,short param_2,byte param_3)



{

  ushort uVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  ushort local_d8 [96];

  undefined8 local_18;

  undefined8 uStack_10;

  

  cVar2 = *param_1;

  local_d8[0] = 7;

  local_d8[1] = 8;

  local_d8[2] = 9;

  local_d8[3] = 10;

  local_d8[4] = 0xb;

  local_d8[5] = 0xc;

  local_d8[6] = 0xd;

  local_d8[7] = 0xe;

  local_d8[8] = 0x10;

  local_d8[9] = 0x11;

  local_d8[10] = 0x13;

  local_d8[0xb] = 0x15;

  local_d8[0xc] = 0x17;

  local_d8[0xd] = 0x19;

  local_d8[0xe] = 0x1c;

  local_d8[0xf] = 0x1f;

  local_d8[0x10] = 0x22;

  local_d8[0x11] = 0x25;

  local_d8[0x12] = 0x29;

  local_d8[0x13] = 0x2d;

  local_d8[0x14] = 0x32;

  local_d8[0x15] = 0x37;

  local_d8[0x16] = 0x3c;

  local_d8[0x17] = 0x42;

  local_d8[0x18] = 0x49;

  local_d8[0x19] = 0x50;

  local_d8[0x1a] = 0x58;

  local_d8[0x1b] = 0x61;

  local_d8[0x1c] = 0x6b;

  local_d8[0x1d] = 0x76;

  local_d8[0x1e] = 0x82;

  local_d8[0x1f] = 0x8f;

  local_d8[0x20] = 0x9d;

  local_d8[0x21] = 0xad;

  local_d8[0x22] = 0xbe;

  local_d8[0x23] = 0xd1;

  local_d8[0x24] = 0xe6;

  local_d8[0x25] = 0xfd;

  local_d8[0x26] = 0x117;

  local_d8[0x27] = 0x133;

  local_d8[0x28] = 0x151;

  local_d8[0x29] = 0x173;

  local_d8[0x2a] = 0x198;

  local_d8[0x2b] = 0x1c1;

  local_d8[0x2c] = 0x1ee;

  local_d8[0x2d] = 0x220;

  local_d8[0x2e] = 0x256;

  local_d8[0x2f] = 0x292;

  local_d8[0x30] = 0x2d4;

  local_d8[0x31] = 0x31c;

  local_d8[0x32] = 0x36c;

  local_d8[0x33] = 0x3c3;

  local_d8[0x34] = 0x424;

  local_d8[0x35] = 0x48e;

  local_d8[0x36] = 0x502;

  local_d8[0x37] = 0x583;

  local_d8[0x38] = 0x610;

  local_d8[0x39] = 0x6ab;

  local_d8[0x3a] = 0x756;

  local_d8[0x3b] = 0x812;

  local_d8[0x3c] = 0x8e0;

  local_d8[0x3d] = 0x9c3;

  local_d8[0x3e] = 0xabd;

  local_d8[0x3f] = 0xbd0;

  local_d8[0x40] = 0xcff;

  local_d8[0x41] = 0xe4c;

  local_d8[0x42] = 0xfba;

  local_d8[0x43] = 0x114c;

  local_d8[0x44] = 0x1307;

  local_d8[0x45] = 0x14ee;

  local_d8[0x46] = 0x1706;

  local_d8[0x47] = 0x1954;

  local_d8[0x48] = 0x1bdc;

  local_d8[0x49] = 0x1ea5;

  local_d8[0x4a] = 0x21b6;

  local_d8[0x4b] = 0x2515;

  local_d8[0x4c] = 0x28ca;

  local_d8[0x4d] = 0x2cdf;

  local_d8[0x4e] = 0x315b;

  local_d8[0x4f] = 0x364b;

  local_d8[0x50] = 0x3bb9;

  local_d8[0x51] = 0x41b2;

  local_d8[0x52] = 0x4844;

  local_d8[0x53] = 0x4f7e;

  local_d8[0x54] = 0x5771;

  local_d8[0x55] = 0x602f;

  local_d8[0x56] = 0x69ce;

  local_d8[0x57] = 0x7462;

  local_d8[0x58] = 0x7fff;

  local_18 = _DAT_140339990;

  uStack_10 = _UNK_140339998;

  if (cVar2 < 'Y') {

    if (cVar2 < '\0') {

      cVar2 = '\0';

    }

  }

  else {

    cVar2 = 'X';

  }

  uVar1 = local_d8[cVar2];

  *param_1 = cVar2 + *(char *)((longlong)&local_18 + (ulonglong)param_3);

  uVar3 = (uint)(uVar1 >> 3);

  if ((param_3 & 4) != 0) {

    uVar3 = uVar3 + uVar1;

  }

  if ((param_3 & 2) != 0) {

    uVar3 = uVar3 + (uVar1 >> 1);

  }

  if ((param_3 & 1) != 0) {

    uVar3 = uVar3 + (uVar1 >> 2);

  }

  uVar4 = -uVar3;

  if ((param_3 & 8) == 0) {

    uVar4 = uVar3;

  }

  uVar4 = uVar4 + (int)param_2;

  if (0x7fff < (int)uVar4) {

    return 0x7fff;

  }

  if ((int)uVar4 < -0x8000) {

    uVar4 = 0xffff8000;

  }

  return uVar4 & 0xffff;

}




