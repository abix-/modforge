// Address: 0x140072640
// Ghidra name: FUN_140072640
// ============ 0x140072640 FUN_140072640 (size=113) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140072640(uint param_1)



{

  _DAT_1403d94d0 = param_1;

  _DAT_1403d94c0 = (float)(param_1 & 0xff) / DAT_14030a2d0;

  _DAT_1403d94c4 = (float)(param_1 >> 8 & 0xff) / DAT_14030a2d0;

  _DAT_1403d94c8 = (float)(param_1 >> 0x10 & 0xff) / DAT_14030a2d0;

  _DAT_1403d94cc = (float)(param_1 >> 0x18) / DAT_14030a2d0;

  return;

}




