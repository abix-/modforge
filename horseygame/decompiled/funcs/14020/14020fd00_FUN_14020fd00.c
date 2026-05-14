// Address: 0x14020fd00
// Ghidra name: FUN_14020fd00
// ============ 0x14020fd00 FUN_14020fd00 (size=305) ============


undefined1 FUN_14020fd00(undefined8 param_1,undefined4 *param_2)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_140210760();

  cVar1 = FUN_140210780(*(undefined8 *)(lVar2 + 0x70));

  if ((cVar1 == '\0') && (*(int *)(lVar2 + 0x78) == 0)) {

    return 0;

  }

  *param_2 = 1;

  *(undefined1 *)(param_2 + 1) = 0;

  param_2[2] = 1;

  *(undefined1 *)(param_2 + 3) = 1;

  param_2[4] = 1;

  *(undefined1 *)(param_2 + 5) = 2;

  param_2[6] = 1;

  *(undefined1 *)(param_2 + 7) = 3;

  param_2[8] = 1;

  *(undefined1 *)(param_2 + 9) = 4;

  param_2[0xc] = 1;

  *(undefined1 *)(param_2 + 0xd) = 6;

  param_2[0xe] = 1;

  *(undefined1 *)(param_2 + 0xf) = 7;

  param_2[0x10] = 1;

  *(undefined1 *)(param_2 + 0x11) = 8;

  param_2[0x12] = 1;

  *(undefined1 *)(param_2 + 0x13) = 9;

  param_2[0x14] = 1;

  *(undefined1 *)(param_2 + 0x15) = 10;

  param_2[0x16] = 3;

  *(undefined1 *)(param_2 + 0x17) = 1;

  param_2[0x18] = 3;

  *(undefined1 *)(param_2 + 0x19) = 4;

  param_2[0x1a] = 3;

  *(undefined1 *)(param_2 + 0x1b) = 8;

  param_2[0x1c] = 3;

  *(undefined1 *)(param_2 + 0x1d) = 2;

  param_2[0x32] = 2;

  *(undefined1 *)(param_2 + 0x33) = 0;

  param_2[0x34] = 2;

  *(undefined1 *)(param_2 + 0x35) = 1;

  param_2[0x36] = 2;

  *(undefined1 *)(param_2 + 0x37) = 2;

  param_2[0x38] = 2;

  *(undefined1 *)(param_2 + 0x39) = 3;

  param_2[0x3a] = 2;

  *(undefined1 *)(param_2 + 0x3b) = 4;

  param_2[0x3c] = 2;

  *(undefined1 *)(param_2 + 0x3d) = 5;

  return 1;

}




