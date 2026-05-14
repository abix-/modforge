// Address: 0x14019ca40
// Ghidra name: FUN_14019ca40
// ============ 0x14019ca40 FUN_14019ca40 (size=28) ============


uint FUN_14019ca40(byte param_1,byte param_2)



{

  uint uVar1;

  

  uVar1 = (uint)param_1 * (uint)param_2 + 0x80;

  return (uVar1 >> 8) + uVar1 >> 8;

}




