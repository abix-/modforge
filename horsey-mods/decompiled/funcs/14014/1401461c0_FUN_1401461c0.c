// Address: 0x1401461c0
// Ghidra name: FUN_1401461c0
// ============ 0x1401461c0 FUN_1401461c0 (size=77) ============


undefined8 FUN_1401461c0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  uVar2 = FUN_140145220(param_1,*(undefined4 *)(param_1 + 4),*(undefined8 *)(param_1 + 0x48),

                        *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34));

  return uVar2;

}




