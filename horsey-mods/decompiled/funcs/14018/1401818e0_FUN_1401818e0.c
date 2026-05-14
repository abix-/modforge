// Address: 0x1401818e0
// Ghidra name: FUN_1401818e0
// ============ 0x1401818e0 FUN_1401818e0 (size=44) ============


ushort FUN_1401818e0(ushort param_1)



{

  ushort uVar1;

  ushort uVar2;

  

  uVar2 = param_1 & 0x6307 | 3;

  if ((param_1 & 3) == 0) {

    uVar2 = param_1 & 0x6307;

  }

  uVar1 = uVar2 | 0x300;

  if ((uVar2 & 0x300) == 0) {

    uVar1 = uVar2;

  }

  return uVar1;

}




