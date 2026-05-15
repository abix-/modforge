// Address: 0x140271bf0
// Ghidra name: FUN_140271bf0
// ============ 0x140271bf0 FUN_140271bf0 (size=202) ============


void FUN_140271bf0(undefined8 *param_1)



{

  if (*(char *)((longlong)param_1 + 0x22) == '\0') {

    *(undefined1 *)((longlong)param_1 + 0x22) = 1;

    if (*(char *)((longlong)param_1 + 0x16) != '\0') {

      FUN_14015a220(param_1[1],2);

      *(undefined1 *)((longlong)param_1 + 0x25) = 1;

    }

    if (*(char *)((longlong)param_1 + 0x13) != '\0') {

      FUN_14015a190(param_1[1],2);

      FUN_14015a190(param_1[1],1);

    }

    if (*(char *)((longlong)param_1 + 0x19) != '\0') {

      FUN_14015a190(param_1[1],1);

    }

    if (*(char *)((longlong)param_1 + 0x12) != '\0') {

      *(undefined1 *)((longlong)param_1 + 0x26) = 1;

    }

    FUN_1402089a0(*param_1);

    return;

  }

  return;

}




