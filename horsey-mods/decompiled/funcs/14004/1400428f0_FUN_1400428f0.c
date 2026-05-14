// Address: 0x1400428f0
// Ghidra name: FUN_1400428f0
// ============ 0x1400428f0 FUN_1400428f0 (size=81) ============


undefined8 FUN_1400428f0(longlong param_1)



{

  undefined8 uVar1;

  

  if (*(char *)(param_1 + 0x5c) != '\0') {

    *(undefined4 *)(param_1 + 0x9c) = 2;

    return 0;

  }

  FUN_140050920(param_1,*(undefined4 *)(param_1 + 0x60));

  *(undefined4 *)(param_1 + 0x4f8) = 0;

  *(undefined1 *)(param_1 + 0x6e5) = 1;

  *(undefined4 *)(param_1 + 0x6e8) = 0xffffffff;

  uVar1 = FUN_140055360(param_1);

  return uVar1;

}




