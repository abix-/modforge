// Address: 0x1401b8990
// Ghidra name: FUN_1401b8990
// ============ 0x1401b8990 FUN_1401b8990 (size=112) ============


undefined8 FUN_1401b8990(longlong param_1)



{

  uint uVar1;

  

  uVar1 = *(uint *)(param_1 + 0x40);

  if ((uVar1 & 1) != 0) {

    return 3;

  }

  if ((uVar1 & 8) != 0) {

    return 4;

  }

  if ((uVar1 & 2) != 0) {

    return 7;

  }

  if ((uVar1 & 4) != 0) {

    return 8;

  }

  if ((uVar1 & 0x10) != 0) {

    return 5;

  }

  if (((uVar1 & 0x20) == 0) && ((uVar1 & 0x40) == 0)) {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"Texture has no default usage mode!");

  }

  return 6;

}




