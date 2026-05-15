// Address: 0x14017c1c0
// Ghidra name: FUN_14017c1c0
// ============ 0x14017c1c0 FUN_14017c1c0 (size=134) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float FUN_14017c1c0(undefined4 param_1)



{

  float fVar1;

  float fVar2;

  

  fVar1 = (float)thunk_FUN_1402d8d60(param_1,DAT_140336b6c);

  fVar1 = fVar1 - _DAT_140336b80;

  if (fVar1 <= 0.0) {

    fVar1 = 0.0;

  }

  fVar2 = (float)thunk_FUN_1402d8d60(param_1,DAT_140336b6c);

  fVar1 = (float)thunk_FUN_1402d8d60(fVar1 / (DAT_140336b98 - fVar2 * _DAT_140336b94),DAT_140336b8c)

  ;

  return fVar1 * DAT_14030dc08;

}




