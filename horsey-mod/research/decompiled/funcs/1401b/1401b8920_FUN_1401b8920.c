// Address: 0x1401b8920
// Ghidra name: FUN_1401b8920
// ============ 0x1401b8920 FUN_1401b8920 (size=108) ============


undefined8 FUN_1401b8920(longlong param_1)



{

  uint uVar1;

  

  uVar1 = *(uint *)(param_1 + 0x24);

  if ((uVar1 & 1) != 0) {

    return 2;

  }

  if ((uVar1 & 2) != 0) {

    return 3;

  }

  if ((uVar1 & 4) != 0) {

    return 4;

  }

  if ((uVar1 & 8) != 0) {

    return 5;

  }

  if ((uVar1 & 0x10) != 0) {

    return 6;

  }

  if ((uVar1 & 0x20) != 0) {

    return 7;

  }

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(9,"Buffer has no default usage mode!");

}




