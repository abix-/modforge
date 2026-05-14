// Address: 0x140182c30
// Ghidra name: FUN_140182c30
// ============ 0x140182c30 FUN_140182c30 (size=76) ============


undefined1 * FUN_140182c30(uint param_1)



{

  undefined1 *puVar1;

  

  if (param_1 < 0x200) {

    puVar1 = &DAT_14039bcb9;

    if ((undefined1 *)(&DAT_1403e2940)[(int)param_1] != (undefined1 *)0x0) {

      puVar1 = (undefined1 *)(&DAT_1403e2940)[(int)param_1];

    }

    return puVar1;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","scancode");

  return &DAT_14039bcb9;

}




