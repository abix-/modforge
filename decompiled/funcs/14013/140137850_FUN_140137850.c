// Address: 0x140137850
// Ghidra name: FUN_140137850
// ============ 0x140137850 FUN_140137850 (size=39) ============


undefined4 FUN_140137850(longlong param_1)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  return *(undefined4 *)(param_1 + 0x2a8);

}




