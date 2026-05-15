// Address: 0x1401786c0
// Ghidra name: FUN_1401786c0
// ============ 0x1401786c0 FUN_1401786c0 (size=182) ============


undefined8 FUN_1401786c0(byte *param_1,uint param_2,ulonglong param_3)



{

  byte bVar1;

  

  bVar1 = (byte)param_2;

  if (param_2 < 0x80) {

    if (param_3 != 0) {

      *param_1 = bVar1;

      return 1;

    }

  }

  else if (param_2 < 0x800) {

    if (1 < param_3) {

      *param_1 = (byte)(param_2 >> 6) | 0xc0;

      param_1[1] = bVar1 & 0x3f | 0x80;

      return 2;

    }

  }

  else if (param_2 < 0x10000) {

    if (2 < param_3) {

      *param_1 = (byte)(param_2 >> 0xc) | 0xe0;

      param_1[1] = (byte)(param_2 >> 6) & 0x3f | 0x80;

      param_1[2] = bVar1 & 0x3f | 0x80;

      return 3;

    }

  }

  else if ((param_2 < 0x110000) && (3 < param_3)) {

    *param_1 = (byte)(param_2 >> 0x12) | 0xf0;

    param_1[1] = (byte)(param_2 >> 0xc) & 0x3f | 0x80;

    param_1[2] = (byte)(param_2 >> 6) & 0x3f | 0x80;

    param_1[3] = bVar1 & 0x3f | 0x80;

    return 4;

  }

  return 0;

}




