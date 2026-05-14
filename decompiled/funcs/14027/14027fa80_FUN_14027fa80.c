// Address: 0x14027fa80
// Ghidra name: FUN_14027fa80
// ============ 0x14027fa80 FUN_14027fa80 (size=91) ============


uint FUN_14027fa80(uint param_1,ushort param_2)



{

  int iVar1;

  uint uVar2;

  

  if ((param_2 == 900) || (param_2 == 200)) {

    return param_1 & 0xffff;

  }

  iVar1 = ((param_1 & 0xffff) - 0x2000) * 200;

  if (199 < param_2) {

    iVar1 = ((param_1 & 0xffff) - 0x2000) * 900;

  }

  uVar2 = iVar1 / (int)(uint)param_2 + 0x2000;

  if ((int)uVar2 < 0) {

    return 0;

  }

  if (0x3fff < (int)uVar2) {

    uVar2 = CONCAT22((short)(uVar2 >> 0x10),0x3fff);

  }

  return uVar2;

}




