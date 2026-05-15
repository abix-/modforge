// Address: 0x140162e60
// Ghidra name: FUN_140162e60
// ============ 0x140162e60 FUN_140162e60 (size=66) ============


undefined1 FUN_140162e60(void)



{

  longlong lVar1;

  

  lVar1 = FUN_1401611a0();

  if (*(char *)(lVar1 + 0xc6) != '\0') {

    FUN_140162d10(0);

    *(undefined1 *)(lVar1 + 0xc6) = 0;

  }

  if (*(char *)(lVar1 + 0x128) == '\0') {

    *(undefined1 *)(lVar1 + 0x128) = 1;

    FUN_140162700();

  }

  return 1;

}




