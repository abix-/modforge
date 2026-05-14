// Address: 0x140136a90
// Ghidra name: FUN_140136a90
// ============ 0x140136a90 FUN_140136a90 (size=150) ============


undefined8 FUN_140136a90(undefined4 param_1)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  switch(param_1) {

  case 1:

  case 2:

  case 0x15:

  case 0x22:

  case 0x2b:

    return 1;

  case 3:

  case 5:

  case 9:

  case 10:

  case 0xb:

  case 0x16:

  case 0x18:

  case 0x1b:

  case 0x23:

  case 0x25:

  case 0x2c:

  case 0x2e:

  case 0x3a:

    return 2;

  case 4:

  case 6:

  case 8:

  case 0xc:

  case 0x17:

  case 0x19:

  case 0x1c:

  case 0x1e:

  case 0x21:

  case 0x24:

  case 0x26:

  case 0x28:

  case 0x2d:

  case 0x2f:

  case 0x31:

  case 0x34:

  case 0x35:

  case 0x3b:

  case 0x3c:

  case 0x3d:

    return 4;

  case 7:

  case 0xd:

  case 0x10:

  case 0x1a:

  case 0x1d:

  case 0x1f:

  case 0x27:

  case 0x29:

  case 0x30:

  case 0x32:

  case 0x36:

    return 8;

  case 0xe:

  case 0xf:

  case 0x11:

  case 0x12:

  case 0x13:

  case 0x14:

  case 0x20:

  case 0x2a:

  case 0x33:

  case 0x37:

  case 0x38:

  case 0x39:

  case 0x3f:

  case 0x40:

  case 0x41:

  case 0x42:

  case 0x43:

  case 0x44:

  case 0x45:

  case 0x46:

  case 0x47:

  case 0x48:

  case 0x49:

  case 0x4a:

  case 0x4b:

  case 0x4c:

  case 0x4d:

  case 0x4e:

  case 0x4f:

  case 0x50:

  case 0x51:

  case 0x52:

  case 0x53:

  case 0x54:

  case 0x55:

  case 0x56:

  case 0x57:

  case 0x58:

  case 0x59:

  case 0x5a:

  case 0x5b:

  case 0x5c:

  case 0x5d:

  case 0x5e:

  case 0x5f:

  case 0x60:

  case 0x61:

  case 0x62:

  case 99:

  case 100:

  case 0x65:

  case 0x66:

  case 0x67:

  case 0x68:

    return 0x10;

  case 0x3e:

    return 5;

  }

  do {

    iVar2 = FUN_14017f2a0(&DAT_1403def38,"SDL_GPUTextureFormatTexelBlockSize_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x391);

  } while (iVar2 == 0);

  if (iVar2 != 1) {

    return 0;

  }

  pcVar1 = (code *)swi(3);

  uVar3 = (*pcVar1)();

  return uVar3;

}




