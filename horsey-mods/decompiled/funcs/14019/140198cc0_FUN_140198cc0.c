// Address: 0x140198cc0
// Ghidra name: FUN_140198cc0
// ============ 0x140198cc0 FUN_140198cc0 (size=54) ============


undefined8 FUN_140198cc0(longlong param_1,undefined4 *param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b0b8);

    return 0;

  }

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = *(undefined4 *)(param_1 + 8);

  }

  return *(undefined8 *)(param_1 + 0x10);

}




