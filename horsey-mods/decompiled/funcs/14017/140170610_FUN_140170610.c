// Address: 0x140170610
// Ghidra name: FUN_140170610
// ============ 0x140170610 FUN_140170610 (size=32) ============


void FUN_140170610(int param_1)



{

  if ((DAT_1403fc410 != 0) && (param_1 != *(int *)(DAT_1403fc410 + 0x398))) {

    *(int *)(DAT_1403fc410 + 0x398) = param_1;

    FUN_14013b570();

    return;

  }

  return;

}




