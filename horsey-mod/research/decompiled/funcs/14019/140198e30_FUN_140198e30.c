// Address: 0x140198e30
// Ghidra name: FUN_140198e30
// ============ 0x140198e30 FUN_140198e30 (size=44) ============


undefined8 FUN_140198e30(longlong param_1)



{

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b0b8);

    return 0;

  }

  return *(undefined8 *)(param_1 + 0x18);

}




