// Address: 0x14012ea30
// Ghidra name: FUN_14012ea30
// ============ 0x14012ea30 FUN_14012ea30 (size=105) ============


undefined8 FUN_14012ea30(void)



{

  undefined8 uVar1;

  int *in_R9;

  undefined1 local_res20;

  undefined8 local_18;

  

  uVar1 = FUN_14012eaa0();

  if (local_res20 == '\0') {

    if (0x7fffffff < local_18) {

      local_18 = 0x7fffffff;

    }

    *in_R9 = (int)local_18;

    return uVar1;

  }

  if (local_18 - 1 < 0x80000000) {

    *in_R9 = -(int)local_18;

    return uVar1;

  }

  *in_R9 = -0x80000000;

  return uVar1;

}




