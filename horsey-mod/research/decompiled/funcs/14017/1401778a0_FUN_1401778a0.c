// Address: 0x1401778a0
// Ghidra name: FUN_1401778a0
// ============ 0x1401778a0 FUN_1401778a0 (size=84) ============


ulonglong FUN_1401778a0(longlong param_1)



{

  byte bVar1;

  ulonglong uVar2;

  

  bVar1 = 1;

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Invalid storage container");

    return uVar2;

  }

  if (*(code **)(param_1 + 8) != (code *)0x0) {

    bVar1 = (**(code **)(param_1 + 8))(*(undefined8 *)(param_1 + 0x60));

  }

  FUN_1401841e0(param_1);

  return (ulonglong)bVar1;

}




