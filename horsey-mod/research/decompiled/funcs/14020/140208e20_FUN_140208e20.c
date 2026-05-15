// Address: 0x140208e20
// Ghidra name: FUN_140208e20
// ============ 0x140208e20 FUN_140208e20 (size=193) ============


void FUN_140208e20(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (DAT_1403fd1c0 == param_1) {

    DAT_1403fd1c0 = 0;

  }

  if (DAT_1403fd1c8 == param_1) {

    DAT_1403fd1c8 = 0;

  }

  if (lVar1 != 0) {

    DAT_1403e4ec8 = 1;

    if (*(char *)(lVar1 + 0x50) != '\0') {

      if (*(char *)(lVar1 + 0x51) != '\0') {

        FUN_14020a8b0(*(undefined1 *)(lVar1 + 0x55));

      }

      FUN_140284fc0();

    }

    FUN_14020aac0(lVar1);

    if (*(longlong *)(lVar1 + 0x90) != 0) {

      *(undefined8 *)(*(longlong *)(lVar1 + 0x90) + 0x48) = 0;

      FUN_14020ac40();

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x18));

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x20));

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x28));

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x30));

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_1 + 0x148) = 0;

  }

  return;

}




