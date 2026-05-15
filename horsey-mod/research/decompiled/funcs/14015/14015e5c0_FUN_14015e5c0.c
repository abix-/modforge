// Address: 0x14015e5c0
// Ghidra name: FUN_14015e5c0
// ============ 0x14015e5c0 FUN_14015e5c0 (size=68) ============


undefined8 FUN_14015e5c0(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  undefined8 uVar1;

  

  uVar1 = 0x50;

  if (*(char *)(param_1 + 0x94) != '\0') {

    uVar1 = 0x43;

  }

  FUN_14012ef10(param_2,param_3,"SDLAudio%c%d",uVar1,*(undefined4 *)(param_1 + 0x50));

  return param_2;

}




