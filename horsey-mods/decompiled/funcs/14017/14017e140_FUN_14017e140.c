// Address: 0x14017e140
// Ghidra name: FUN_14017e140
// ============ 0x14017e140 FUN_14017e140 (size=36) ============


uint FUN_14017e140(int param_1)



{

  char cVar1;

  uint uVar2;

  

  uVar2 = param_1 - 0x30;

  if (9 < (byte)uVar2) {

    cVar1 = (char)param_1;

    if ((byte)(cVar1 + 0xbfU) < 6) {

      return param_1 - 0x37;

    }

    uVar2 = 0;

    if ((byte)(cVar1 + 0x9fU) < 6) {

      uVar2 = (uint)(byte)(cVar1 + 0xa9);

    }

  }

  return uVar2;

}




