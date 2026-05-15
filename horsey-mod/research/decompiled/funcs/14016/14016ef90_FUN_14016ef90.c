// Address: 0x14016ef90
// Ghidra name: FUN_14016ef90
// ============ 0x14016ef90 FUN_14016ef90 (size=117) ============


undefined1 * FUN_14016ef90(longlong param_1)



{

  char cVar1;

  undefined1 *puVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return &DAT_14039bcb9;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016efec;

    }

    puVar2 = &DAT_14039bcb9;

    if (*(undefined1 **)(param_1 + 8) != (undefined1 *)0x0) {

      puVar2 = *(undefined1 **)(param_1 + 8);

    }

    return puVar2;

  }

LAB_14016efec:

  FUN_14012e850("Invalid window");

  return &DAT_14039bcb9;

}




