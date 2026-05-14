// Address: 0x14015de30
// Ghidra name: FUN_14015de30
// ============ 0x14015de30 FUN_14015de30 (size=54) ============


undefined4 * FUN_14015de30(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = 0;

  piVar1 = &DAT_140333540;

  do {

    if (*piVar1 == param_1) {

      return &DAT_140333540 + (longlong)iVar2 * 9;

    }

    iVar2 = iVar2 + 1;

    piVar1 = piVar1 + 9;

  } while ((longlong)piVar1 < 0x140333660);

  return (undefined4 *)&DAT_140333560;

}




