// Address: 0x1400b7730
// Ghidra name: FUN_1400b7730
// ============ 0x1400b7730 FUN_1400b7730 (size=53) ============


undefined1 FUN_1400b7730(longlong param_1)



{

  char cVar1;

  

  if ((*(byte *)(param_1 + 600) & 1) != 0) {

    if ((*(int *)(param_1 + 0x1c) != 2) && (*(int *)(param_1 + 0x1c) != 1)) {

      cVar1 = FUN_140067e30(*(undefined4 *)(param_1 + 0x284));

      if (cVar1 == '\0') {

        return 0;

      }

    }

  }

  return 1;

}




