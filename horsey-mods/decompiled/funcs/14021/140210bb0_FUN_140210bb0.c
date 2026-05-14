// Address: 0x140210bb0
// Ghidra name: FUN_140210bb0
// ============ 0x140210bb0 FUN_140210bb0 (size=70) ============


void FUN_140210bb0(void)



{

  int iVar1;

  char *pcVar2;

  

  _guard_check_icall();

  iVar1 = FUN_14017e2e0();

  if (iVar1 != 4) {

    pcVar2 = (char *)FUN_1401796b0("SteamVirtualGamepadInfo");

    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {

      DAT_1403fd3c8 = FUN_14012f0d0(pcVar2);

    }

    FUN_140210c60();

    return;

  }

  return;

}




