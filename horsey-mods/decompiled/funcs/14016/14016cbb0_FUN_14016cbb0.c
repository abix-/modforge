// Address: 0x14016cbb0
// Ghidra name: FUN_14016cbb0
// ============ 0x14016cbb0 FUN_14016cbb0 (size=441) ============


undefined8 FUN_14016cbb0(undefined4 param_1,uint param_2)



{

  undefined8 uVar1;

  

  if (DAT_1403fc410 == 0) {

    uVar1 = FUN_14012e850("Video subsystem has not been initialized");

    return uVar1;

  }

  switch(param_1) {

  case 0:

    *(uint *)(DAT_1403fc410 + 0x3a0) = param_2;

    return 1;

  case 1:

    *(uint *)(DAT_1403fc410 + 0x3a4) = param_2;

    return 1;

  case 2:

    *(uint *)(DAT_1403fc410 + 0x3a8) = param_2;

    return 1;

  case 3:

    *(uint *)(DAT_1403fc410 + 0x3ac) = param_2;

    return 1;

  case 4:

    *(uint *)(DAT_1403fc410 + 0x3b4) = param_2;

    return 1;

  case 5:

    *(uint *)(DAT_1403fc410 + 0x3bc) = param_2;

    return 1;

  case 6:

    *(uint *)(DAT_1403fc410 + 0x3b0) = param_2;

    return 1;

  case 7:

    *(uint *)(DAT_1403fc410 + 0x3b8) = param_2;

    return 1;

  case 8:

    *(uint *)(DAT_1403fc410 + 0x3c0) = param_2;

    return 1;

  case 9:

    *(uint *)(DAT_1403fc410 + 0x3c4) = param_2;

    return 1;

  case 10:

    *(uint *)(DAT_1403fc410 + 0x3c8) = param_2;

    return 1;

  case 0xb:

    *(uint *)(DAT_1403fc410 + 0x3cc) = param_2;

    return 1;

  case 0xc:

    *(uint *)(DAT_1403fc410 + 0x3d0) = param_2;

    return 1;

  case 0xd:

    *(uint *)(DAT_1403fc410 + 0x3d4) = param_2;

    return 1;

  case 0xe:

    *(uint *)(DAT_1403fc410 + 0x3d8) = param_2;

    return 1;

  case 0xf:

    *(uint *)(DAT_1403fc410 + 0x3e0) = param_2;

    return 1;

  case 0x10:

    *(uint *)(DAT_1403fc410 + 0x408) = param_2;

    return 1;

  case 0x11:

    *(uint *)(DAT_1403fc410 + 0x3e4) = param_2;

    return 1;

  case 0x12:

    *(uint *)(DAT_1403fc410 + 1000) = param_2;

    return 1;

  case 0x13:

    if ((param_2 & 0xfffffff0) == 0) {

      *(uint *)(DAT_1403fc410 + 0x3ec) = param_2;

      return 1;

    }

    uVar1 = FUN_14012e850("Unknown OpenGL context flag %d");

    return uVar1;

  case 0x14:

    break;

  case 0x15:

    *(uint *)(DAT_1403fc410 + 0x3f4) = param_2;

    return 1;

  case 0x16:

    *(uint *)(DAT_1403fc410 + 0x400) = param_2;

    return 1;

  case 0x17:

    *(uint *)(DAT_1403fc410 + 0x3f8) = param_2;

    return 1;

  case 0x18:

    *(uint *)(DAT_1403fc410 + 0x3fc) = param_2;

    return 1;

  case 0x19:

    *(uint *)(DAT_1403fc410 + 0x404) = param_2;

    return 1;

  case 0x1a:

    *(uint *)(DAT_1403fc410 + 0x3dc) = param_2;

    return 1;

  case 0x1b:

    *(uint *)(DAT_1403fc410 + 0x40c) = param_2;

    return 1;

  default:

    uVar1 = FUN_14012e850("Unknown OpenGL attribute");

    return uVar1;

  }

  if ((2 < param_2) && (param_2 != 4)) {

    uVar1 = FUN_14012e850("Unknown OpenGL context profile %d");

    return uVar1;

  }

  *(uint *)(DAT_1403fc410 + 0x3f0) = param_2;

  return 1;

}




