// Address: 0x140146f80
// Ghidra name: FUN_140146f80
// ============ 0x140146f80 FUN_140146f80 (size=125) ============


undefined8

FUN_140146f80(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,

             undefined1 param_5)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    uVar2 = 1;

  }

  else {

    uVar2 = FUN_14017bba0(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x48),param_2,

                          param_3,param_4,param_5);

  }

  return uVar2;

}




