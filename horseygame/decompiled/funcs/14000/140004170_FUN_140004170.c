// Address: 0x140004170
// Ghidra name: FUN_140004170
// ============ 0x140004170 FUN_140004170 (size=195) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140004170(void)



{

  uint uVar1;

  longlong lVar2;

  longlong lVar3;

  byte local_18 [16];

  

  uVar1 = 0;

  local_18[0] = 0;

  local_18[1] = 0;

  local_18[2] = 0;

  local_18[3] = 0;

  _DAT_1403edf10 = (undefined8 *)FUN_1400285e0(0x10);

  _DAT_1403edf18 = _DAT_1403edf10 + 2;

  local_18[4] = 0;

  local_18[5] = 0;

  local_18[6] = 0;

  local_18[7] = 0;

  lVar2 = 0;

  do {

    lVar3 = lVar2 + 1;

    if (local_18[lVar2] != local_18[lVar2 + 4]) {

      uVar1 = -(uint)(local_18[lVar2] < local_18[lVar2 + 4]) | 1;

      break;

    }

    lVar2 = lVar3;

  } while (lVar3 != 4);

  DAT_1403edf08 = _DAT_1403edf10;

  if (uVar1 == 0) {

    *_DAT_1403edf10 = 0;

    _DAT_1403edf10[1] = 0;

  }

  else {

    *_DAT_1403edf10 = 0;

    _DAT_1403edf10[1] = 0;

  }

  _DAT_1403edf10 = _DAT_1403edf10 + 2;

  if ((4 < (ulonglong)((longlong)_DAT_1403edf10 - (longlong)DAT_1403edf08 >> 2)) &&

     (DAT_1403edf08 + 2 != _DAT_1403edf10)) {

    _DAT_1403edf10 = DAT_1403edf08 + 2;

  }

  DAT_1403edf20 = 100;

  *(uint *)((longlong)DAT_1403edf08 + 0xc) = *(uint *)((longlong)DAT_1403edf08 + 0xc) & 0xf;

  atexit((_func_5014 *)&LAB_140300820);

  return;

}




