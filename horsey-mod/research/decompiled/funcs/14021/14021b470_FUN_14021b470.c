// Address: 0x14021b470
// Ghidra name: FUN_14021b470
// ============ 0x14021b470 FUN_14021b470 (size=113) ============


undefined8 FUN_14021b470(longlong param_1)



{

  char cVar1;

  undefined **ppuVar2;

  

  _guard_check_icall();

  if (*(undefined ***)(param_1 + 0x140) == &PTR_FUN_1403e4c90) {

    ppuVar2 = &PTR_PTR_1403e5378;

    do {

      cVar1 = (**(code **)*ppuVar2)(param_1);

      if (cVar1 != '\0') {

        return 1;

      }

      ppuVar2 = ppuVar2 + 1;

    } while ((longlong)ppuVar2 < 0x1403e5380);

  }

  return 0;

}




