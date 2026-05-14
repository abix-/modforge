// Address: 0x140161850
// Ghidra name: FUN_140161850
// ============ 0x140161850 FUN_140161850 (size=103) ============


void FUN_140161850(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  *(char *)(param_1 + 0xef) = cVar1;

  if (cVar1 == '\0') {

    if (*(char *)(param_1 + 0xf2) != '\0') {

      FUN_140186110(0xfffffffffffffffe);

      *(undefined1 *)(param_1 + 0xf2) = 0;

    }

  }

  else if (*(char *)(param_1 + 0xf2) == '\0') {

    FUN_140185f90(0xfffffffffffffffe,0,"pen_input");

    *(undefined1 *)(param_1 + 0xf2) = 1;

    return;

  }

  return;

}




