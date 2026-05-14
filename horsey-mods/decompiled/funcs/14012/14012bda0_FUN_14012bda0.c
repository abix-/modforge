// Address: 0x14012bda0
// Ghidra name: FUN_14012bda0
// ============ 0x14012bda0 FUN_14012bda0 (size=126) ============


ulonglong FUN_14012bda0(longlong param_1)



{

  byte bVar1;

  ulonglong uVar2;

  

  bVar1 = 1;

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","context");

    return uVar2;

  }

  *(undefined4 *)(param_1 + 0x40) = 0;

  FUN_14012e710();

  if (*(code **)(param_1 + 0x28) != (code *)0x0) {

    bVar1 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x38),param_1 + 0x40);

    if ((bVar1 == 0) && (*(int *)(param_1 + 0x40) == 0)) {

      *(undefined4 *)(param_1 + 0x40) = 1;

    }

  }

  return (ulonglong)bVar1;

}




