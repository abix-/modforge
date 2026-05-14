// Address: 0x14015d380
// Ghidra name: FUN_14015d380
// ============ 0x14015d380 FUN_14015d380 (size=65) ============


undefined8 FUN_14015d380(longlong param_1)



{

  char cVar1;

  

  FUN_14015f420();

  do {

    cVar1 = (**(code **)(param_1 + 0x30))(param_1);

    if (cVar1 == '\0') {

      FUN_14015d5d0(param_1);

    }

    cVar1 = FUN_14015f620(param_1);

  } while (cVar1 != '\0');

  FUN_14015f8f0(param_1);

  return 0;

}




