// Address: 0x1401d2c00
// Ghidra name: FUN_1401d2c00
// ============ 0x1401d2c00 FUN_1401d2c00 (size=110) ============


void FUN_1401d2c00(byte *param_1)



{

  if ((*(uint *)(param_1 + 0x30) & 4) != 0) {

    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffff9fff;

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb;

    if ((*param_1 & 1) == 0) {

      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_1 + 0x120);

      param_1[0x120] = 0;

      param_1[0x121] = 0;

      param_1[0x122] = 0;

      param_1[0x123] = 0;

      param_1[0x124] = 0;

      param_1[0x125] = 0;

      param_1[0x126] = 0;

      param_1[0x127] = 0;

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x88));

    param_1[0x88] = 0;

    param_1[0x89] = 0;

    param_1[0x8a] = 0;

    param_1[0x8b] = 0;

    param_1[0x8c] = 0;

    param_1[0x8d] = 0;

    param_1[0x8e] = 0;

    param_1[0x8f] = 0;

    FUN_14017ba60(param_1 + 0x78);

    FUN_140148a20(param_1);

    return;

  }

  return;

}




