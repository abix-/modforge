// Address: 0x14012ed70
// Ghidra name: FUN_14012ed70
// ============ 0x14012ed70 FUN_14012ed70 (size=199) ============


byte * FUN_14012ed70(uint param_1,byte *param_2)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  

  if (param_2 == (byte *)0x0) {

    return (byte *)0x0;

  }

  if ((param_1 < 0x110000) && (0x7ff < param_1 - 0xd800)) {

    if (param_1 < 0x80) {

      *param_2 = (byte)param_1;

      return param_2 + 1;

    }

    bVar1 = (byte)(param_1 >> 6);

    bVar2 = (byte)param_1 & 0x3f | 0x80;

    if (param_1 < 0x800) {

      param_2[1] = bVar2;

      *param_2 = bVar1 & 0x1f | 0xc0;

      return param_2 + 2;

    }

    bVar3 = (byte)(param_1 >> 0xc);

    bVar1 = bVar1 & 0x3f | 0x80;

    if (0xffff < param_1) {

      param_2[3] = bVar2;

      param_2[2] = bVar1;

      param_2[1] = bVar3 & 0x3f | 0x80;

      *param_2 = (byte)(param_1 >> 0x12) & 7 | 0xf0;

      return param_2 + 4;

    }

  }

  else {

    bVar2 = 0xbd;

    bVar3 = 0xf;

    bVar1 = 0xbf;

  }

  param_2[1] = bVar1;

  param_2[2] = bVar2;

  *param_2 = bVar3 & 0xf | 0xe0;

  return param_2 + 3;

}




