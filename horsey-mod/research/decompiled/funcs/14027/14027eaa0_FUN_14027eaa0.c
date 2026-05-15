// Address: 0x14027eaa0
// Ghidra name: FUN_14027eaa0
// ============ 0x14027eaa0 FUN_14027eaa0 (size=43) ============


bool FUN_14027eaa0(longlong param_1,int param_2)



{

  uint uVar1;

  

  uVar1 = param_2 >> 0x1f & 7;

  param_2 = param_2 + uVar1;

  return (*(byte *)((param_2 >> 3) + param_1) & '\x01' << (((byte)param_2 & 7) - (char)uVar1 & 0x1f)

         ) != 0;

}




