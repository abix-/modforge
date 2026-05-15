// Address: 0x140182d30
// Ghidra name: FUN_140182d30
// ============ 0x140182d30 FUN_140182d30 (size=44) ============


undefined8 FUN_140182d30(uint param_1,undefined8 param_2)



{

  undefined8 uVar1;

  

  if (param_1 < 0x200) {

    (&DAT_1403e2940)[(int)param_1] = param_2;

    return CONCAT71((int7)(int3)(param_1 >> 8),1);

  }

  uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","scancode");

  return uVar1;

}




