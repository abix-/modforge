// Address: 0x14004cee0
// Ghidra name: FUN_14004cee0
// ============ 0x14004cee0 FUN_14004cee0 (size=160) ============


int FUN_14004cee0(int param_1)



{

  ulonglong uVar1;

  

  if (param_1 < 0) {

    return 0;

  }

  uVar1 = (ulonglong)param_1;

  if (0x3fff < param_1) {

    if (0xffffff < param_1) {

      if (param_1 < 0x20000000) {

        return (char)(&DAT_1403d4a10)[uVar1 >> 0x19] + 0x19;

      }

      return (char)(&DAT_1403d4a10)[uVar1 >> 0x1e] + 0x1e;

    }

    if (param_1 < 0x80000) {

      return (char)(&DAT_1403d4a10)[uVar1 >> 0xf] + 0xf;

    }

    return (char)(&DAT_1403d4a10)[uVar1 >> 0x14] + 0x14;

  }

  if (param_1 < 0x10) {

    return (int)(char)(&DAT_1403d4a10)[uVar1];

  }

  if (param_1 < 0x200) {

    return (char)(&DAT_1403d4a10)[uVar1 >> 5] + 5;

  }

  return (char)(&DAT_1403d4a10)[uVar1 >> 10] + 10;

}




