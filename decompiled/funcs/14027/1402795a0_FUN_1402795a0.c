// Address: 0x1402795a0
// Ghidra name: FUN_1402795a0
// ============ 0x1402795a0 FUN_1402795a0 (size=172) ============


void FUN_1402795a0(longlong param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x1c);

  if (iVar1 == 0x81) {

    *(undefined4 *)(param_1 + 0x62) = 0xd70028;

    *(undefined4 *)(param_1 + 0x66) = 0xa0000;

    *(undefined4 *)(param_1 + 0x6a) = 0xd70028;

    *(undefined4 *)(param_1 + 0x6e) = 0xa0000;

  }

  else {

    if (iVar1 == 0x82) {

      *(undefined4 *)(param_1 + 0x62) = 0x360009;

      *(undefined4 *)(param_1 + 0x66) = 0x40000;

      *(undefined4 *)(param_1 + 0x6a) = 0x360009;

      *(undefined4 *)(param_1 + 0x6e) = 0x40000;

      *(undefined4 *)(param_1 + 0x72) = 0x1a0005;

      *(undefined4 *)(param_1 + 0x76) = 0x20000;

      *(undefined4 *)(param_1 + 0x7a) = 0x1a0005;

      *(undefined4 *)(param_1 + 0x7e) = 0x20000;

      return;

    }

    if (iVar1 == 0x83) {

      *(undefined4 *)(param_1 + 0x62) = 0xbb803e8;

      *(undefined4 *)(param_1 + 0x66) = 0x640000;

      *(undefined4 *)(param_1 + 0x6a) = 0xbb803e8;

      *(undefined4 *)(param_1 + 0x6e) = 0x640000;

      *(undefined4 *)(param_1 + 0x72) = 0xbb803e8;

      *(undefined4 *)(param_1 + 0x76) = 0x640000;

      *(undefined4 *)(param_1 + 0x7a) = 0xbb803e8;

      *(undefined4 *)(param_1 + 0x7e) = 0x640000;

      return;

    }

  }

  return;

}




