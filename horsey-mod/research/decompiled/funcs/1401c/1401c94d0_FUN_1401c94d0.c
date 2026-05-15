// Address: 0x1401c94d0
// Ghidra name: FUN_1401c94d0
// ============ 0x1401c94d0 FUN_1401c94d0 (size=116) ============


undefined8 FUN_1401c94d0(undefined8 *param_1)



{

  uint uVar1;

  

  uVar1 = *(uint *)*param_1;

  if ((uVar1 & 1) != 0) {

    return 1;

  }

  if ((uVar1 & 2) != 0) {

    return 2;

  }

  if ((uVar1 & 4) != 0) {

    return 0x200;

  }

  if ((uVar1 & 8) != 0) {

    return 0xc0;

  }

  if ((uVar1 & 0x10) != 0) {

    return 0x40;

  }

  if ((uVar1 & 0x20) != 0) {

    return 8;

  }

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(9,"Buffer has no default usage mode!");

}




