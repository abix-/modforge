// Address: 0x14013bf90
// Ghidra name: FUN_14013bf90
// ============ 0x14013bf90 FUN_14013bf90 (size=40) ============


longlong FUN_14013bf90(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x348);

  while( true ) {

    if (lVar1 == 0) {

      return 0;

    }

    if (*(char *)(lVar1 + 0x10f) == '\0') break;

    lVar1 = *(longlong *)(lVar1 + 0x1a0);

  }

  return lVar1;

}




