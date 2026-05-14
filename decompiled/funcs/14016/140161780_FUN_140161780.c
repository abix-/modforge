// Address: 0x140161780
// Ghidra name: FUN_140161780
// ============ 0x140161780 FUN_140161780 (size=103) ============


void FUN_140161780(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,0);

  *(char *)(param_1 + 0xed) = cVar1;

  if (cVar1 == '\0') {

    if (*(char *)(param_1 + 0xf1) != '\0') {

      FUN_140186110(0xffffffffffffffff);

      *(undefined1 *)(param_1 + 0xf1) = 0;

    }

  }

  else if (*(char *)(param_1 + 0xf1) == '\0') {

    FUN_140185f90(0xffffffffffffffff,0,"mouse_input");

    *(undefined1 *)(param_1 + 0xf1) = 1;

    return;

  }

  return;

}




