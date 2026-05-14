// Address: 0x140159610
// Ghidra name: FUN_140159610
// ============ 0x140159610 FUN_140159610 (size=55) ============


undefined8 FUN_140159610(short param_1,short param_2)



{

  ushort uVar1;

  

  if (param_1 != 0x2e8a) {

    return 0x2e00;

  }

  uVar1 = param_2 + 0xef3a;

  if ((uVar1 < 0x1b) && ((0x6800001U >> (uVar1 & 0x1f) & 1) != 0)) {

    return CONCAT71((uint7)(byte)(uVar1 >> 8),1);

  }

  return CONCAT71(0x10,param_2 == 0x10e5);

}




