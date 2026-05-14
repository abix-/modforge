// Address: 0x1401d4420
// Ghidra name: FUN_1401d4420
// ============ 0x1401d4420 FUN_1401d4420 (size=107) ============


undefined8 FUN_1401d4420(uint param_1,uint *param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  uVar1 = param_1 & 0x1f;

  if ((uVar1 == 6) || (uVar1 == 5)) {

    *param_2 = (uint)((param_1 & 0xf000000) != 0x2000000);

    return 1;

  }

  if (uVar1 == 1) {

    *param_2 = ((param_1 & 0xf000000) != 0x2000000) + 2;

    return 1;

  }

  if ((uVar1 == 9) && ((param_1 & 0xf000000) == 0x2000000)) {

    *param_2 = 4;

    return 1;

  }

  uVar2 = FUN_14012e850("Unsupported YUV colorspace");

  return uVar2;

}




