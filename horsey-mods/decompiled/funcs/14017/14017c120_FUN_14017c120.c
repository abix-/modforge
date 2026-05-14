// Address: 0x14017c120
// Ghidra name: FUN_14017c120
// ============ 0x14017c120 FUN_14017c120 (size=151) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14017c120(float param_1)



{

  float fVar1;

  float fVar2;

  

  param_1 = param_1 / DAT_14030dc08;

  fVar2 = 0.0;

  if ((0.0 <= param_1) && (fVar2 = DAT_14039ca44, param_1 <= DAT_14039ca44)) {

    fVar2 = param_1;

  }

  fVar1 = (float)thunk_FUN_1402d8d60(fVar2,DAT_140336b78);

  fVar1 = fVar1 * DAT_140336b98 + _DAT_140336b80;

  fVar2 = (float)thunk_FUN_1402d8d60(fVar2,DAT_140336b78);

  thunk_FUN_1402d8d60(fVar1 / (fVar2 * _DAT_140336b94 + DAT_14039ca44),_DAT_140336b9c);

  return;

}




