// Address: 0x140276ab0
// Ghidra name: FUN_140276ab0
// ============ 0x140276ab0 FUN_140276ab0 (size=20) ============


byte FUN_140276ab0(byte param_1,char param_2)



{

  byte bVar1;

  

  bVar1 = param_1 | 0xc0;

  if (param_2 == '\0') {

    bVar1 = param_1 | 0x80;

  }

  return bVar1;

}




