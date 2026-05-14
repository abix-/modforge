// Address: 0x1401377a0
// Ghidra name: FUN_1401377a0
// ============ 0x1401377a0 FUN_1401377a0 (size=40) ============


undefined8 FUN_1401377a0(longlong param_1)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  return *(undefined8 *)(param_1 + 0x2a0);

}




