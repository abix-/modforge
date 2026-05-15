// Address: 0x1401303f0
// Ghidra name: FUN_1401303f0
// ============ 0x1401303f0 FUN_1401303f0 (size=71) ============


undefined8 FUN_1401303f0(longlong param_1)



{

  char cVar1;

  

  FUN_140130b60();

  FUN_140131820(param_1);

  do {

    cVar1 = (**(code **)(param_1 + 0x18))(param_1);

    if (cVar1 == '\0') {

      FUN_140130fb0(param_1);

    }

    cVar1 = FUN_140131550(param_1);

  } while (cVar1 != '\0');

  FUN_1401324e0(param_1);

  return 0;

}




