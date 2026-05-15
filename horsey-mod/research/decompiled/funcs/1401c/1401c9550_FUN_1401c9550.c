// Address: 0x1401c9550
// Ghidra name: FUN_1401c9550
// ============ 0x1401c9550 FUN_1401c9550 (size=106) ============


undefined8 FUN_1401c9550(ulonglong param_1)



{

  if (((param_1 & 1) != 0) || ((param_1 & 8) != 0)) {

    return 0xc0;

  }

  if ((param_1 & 2) != 0) {

    return 4;

  }

  if ((param_1 & 4) != 0) {

    return 0x10;

  }

  if ((param_1 & 0x10) != 0) {

    return 0x40;

  }

  if (((param_1 & 0x20) == 0) && ((param_1 & 0x40) == 0)) {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"Texture has no default usage mode!");

  }

  return 8;

}




