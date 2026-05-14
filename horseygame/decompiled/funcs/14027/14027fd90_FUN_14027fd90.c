// Address: 0x14027fd90
// Ghidra name: FUN_14027fd90
// ============ 0x14027fd90 FUN_14027fd90 (size=257) ============


undefined8 FUN_14027fd90(longlong param_1,longlong param_2)



{

  char *pcVar1;

  undefined1 auVar2 [16];

  ushort uVar3;

  undefined4 uVar4;

  ulonglong uVar5;

  

  pcVar1 = *(char **)(param_1 + 0x70);

  _guard_check_icall();

  pcVar1[0x1c] = '\0';

  pcVar1[0x1d] = '\0';

  pcVar1[0x1e] = '\0';

  pcVar1[0x1f] = '\0';

  pcVar1[0x20] = '\0';

  pcVar1[0x21] = '\0';

  pcVar1[0x22] = '\0';

  pcVar1[0x23] = '\0';

  pcVar1[0x24] = '\0';

  pcVar1[0x25] = '\0';

  pcVar1[0x26] = '\0';

  pcVar1[0x27] = '\0';

  pcVar1[0x28] = '\0';

  pcVar1[0x29] = '\0';

  pcVar1[0x2a] = '\0';

  pcVar1[0x2b] = '\0';

  pcVar1[0x2c] = '\0';

  pcVar1[0x2d] = '\0';

  pcVar1[0x2e] = '\0';

  pcVar1[0x2f] = '\0';

  pcVar1[0x30] = '\0';

  pcVar1[0x31] = '\0';

  pcVar1[0x32] = '\0';

  pcVar1[0x33] = '\0';

  pcVar1[0x34] = '\0';

  pcVar1[0x35] = '\0';

  pcVar1[0x36] = '\0';

  pcVar1[0x37] = '\0';

  pcVar1[0x38] = '\0';

  pcVar1[0x39] = '\0';

  pcVar1[0x3a] = '\0';

  pcVar1[0x3b] = '\0';

  pcVar1[0x3c] = '\0';

  pcVar1[0x3d] = '\0';

  pcVar1[0x3e] = '\0';

  pcVar1[0x3f] = '\0';

  pcVar1[0x40] = '\0';

  pcVar1[0x41] = '\0';

  pcVar1[0x42] = '\0';

  pcVar1[0x43] = '\0';

  pcVar1[0x44] = '\0';

  pcVar1[0x45] = '\0';

  pcVar1[0x46] = '\0';

  pcVar1[0x47] = '\0';

  pcVar1[0x48] = '\0';

  pcVar1[0x49] = '\0';

  pcVar1[0x4a] = '\0';

  pcVar1[0x4b] = '\0';

  pcVar1[0x4c] = '\0';

  pcVar1[0x4d] = '\0';

  pcVar1[0x4e] = '\0';

  pcVar1[0x4f] = '\0';

  pcVar1[0x50] = '\0';

  pcVar1[0x51] = '\0';

  pcVar1[0x52] = '\0';

  pcVar1[0x53] = '\0';

  pcVar1[0x54] = '\0';

  pcVar1[0x55] = '\0';

  pcVar1[0x56] = '\0';

  pcVar1[0x57] = '\0';

  pcVar1[0x58] = '\0';

  pcVar1[0x59] = '\0';

  pcVar1[0x5a] = '\0';

  pcVar1[0x5b] = '\0';

  if ((*(short *)(param_1 + 0x22) == 0x6003) ||

     ((uVar3 = *(short *)(param_1 + 0x22) + 0x9ffa, uVar3 < 0xd &&

      ((0x1009U >> (uVar3 & 0x1f) & 1) != 0)))) {

    uVar4 = 0xf;

  }

  else {

    uVar4 = 0xb;

  }

  *(undefined4 *)(param_2 + 0x70) = uVar4;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  if (*pcVar1 != '\0') {

    uVar5 = FUN_140280040(param_1);

    auVar2._8_8_ = 0;

    auVar2._0_8_ = uVar5;

    *(longlong *)(pcVar1 + 0x68) = SUB168((ZEXT816(0) << 0x40 | ZEXT816(1000000000)) / auVar2,0);

    FUN_14015a190(param_2,2,(float)uVar5);

    FUN_14015a190(param_2,1,(float)uVar5);

    pcVar1[0x14] = '\n';

    pcVar1[0x15] = -0x18;

    pcVar1[0x16] = '\x1c';

    pcVar1[0x17] = ';';

    pcVar1[0x18] = 'o';

    pcVar1[0x19] = -0x5f;

    pcVar1[0x1a] = -0x75;

    pcVar1[0x1b] = ':';

  }

  return 1;

}




