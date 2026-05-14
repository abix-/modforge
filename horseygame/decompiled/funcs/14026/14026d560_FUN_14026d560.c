// Address: 0x14026d560
// Ghidra name: FUN_14026d560
// ============ 0x14026d560 FUN_14026d560 (size=68) ============


void FUN_14026d560(longlong param_1)



{

  undefined8 uVar1;

  

  *(char *)(param_1 + 0x37) = *(char *)(param_1 + 0x2c);

  *(undefined1 *)(param_1 + 0x36) = 0x10;

  *(byte *)(param_1 + 0x2c) = *(char *)(param_1 + 0x2c) + 1U & 0xf;

  uVar1 = FUN_140149350();

  *(undefined8 *)(param_1 + 0x88) = uVar1;

  FUN_14026d3d0(param_1,param_1 + 0x36,10);

  return;

}




