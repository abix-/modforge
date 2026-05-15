// Address: 0x1402a29d0
// Ghidra name: FUN_1402a29d0
// ============ 0x1402a29d0 FUN_1402a29d0 (size=77) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint FUN_1402a29d0(ushort param_1)



{

  float fVar1;

  

  fVar1 = (float)((param_1 & 0x7fff) << 0xd) * _DAT_140383a24;

  if (_DAT_140383a20 <= fVar1) {

    fVar1 = (float)((uint)fVar1 | 0x7f800000);

  }

  return (uint)fVar1 | (param_1 & 0x8000) << 0x10;

}




