// Address: 0x14017e340
// Ghidra name: FUN_14017e340
// ============ 0x14017e340 FUN_14017e340 (size=229) ============


void FUN_14017e340(void)



{

  char *pcVar1;

  char *pcVar2;

  

  if (DAT_1403fc628 == 0) {

    DAT_1403fc628 = FUN_14017ffb0();

  }

  thunk_FUN_140217550();

  FUN_140179460();

  FUN_1401493a0();

  _guard_check_icall();

  if (DAT_1403fc641 == '\0') {

    pcVar1 = (char *)FUN_14017e1d0("SDL.app.metadata.name");

    pcVar2 = "<unspecified>";

    if (pcVar1 != (char *)0x0) {

      pcVar2 = pcVar1;

    }

    FUN_14012e0e0(3,"App name: %s",pcVar2);

    pcVar1 = (char *)FUN_14017e1d0("SDL.app.metadata.version");

    pcVar2 = "<unspecified>";

    if (pcVar1 != (char *)0x0) {

      pcVar2 = pcVar1;

    }

    FUN_14012e0e0(3,"App version: %s",pcVar2);

    pcVar1 = (char *)FUN_14017e1d0("SDL.app.metadata.identifier");

    pcVar2 = "<unspecified>";

    if (pcVar1 != (char *)0x0) {

      pcVar2 = pcVar1;

    }

    FUN_14012e0e0(3,"App ID: %s",pcVar2);

    FUN_14012e0e0(3,"SDL revision: %s","libsdl.org");

    DAT_1403fc641 = '\x01';

  }

  return;

}




