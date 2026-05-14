// Address: 0x140172d10
// Ghidra name: FUN_140172d10
// ============ 0x140172d10 FUN_140172d10 (size=304) ============


undefined8 FUN_140172d10(longlong param_1,int param_2)



{

  char cVar1;

  int iVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    FUN_14012e850("Invalid window");

    return 0;

  }

  if (*(int *)(param_1 + 0x134) != 0) {

    FUN_1401747e0();

    *(undefined4 *)(param_1 + 0x134) = 0;

  }

  if (param_2 != 0) {

    iVar2 = FUN_1401746e0();

    *(int *)(param_1 + 0x134) = iVar2;

    if (iVar2 == 0) {

      return 0;

    }

    cVar1 = FUN_1401745f0(param_2,iVar2);

    if (cVar1 == '\0') {

      return 0;

    }

  }

  if (*(code **)(DAT_1403fc410 + 0x298) != (code *)0x0) {

    (**(code **)(DAT_1403fc410 + 0x298))(DAT_1403fc410,param_1,param_2);

  }

  cVar1 = FUN_140169bb0();

  if (((cVar1 != '\0') && (cVar1 = FUN_140170250(param_1), cVar1 == '\0')) &&

     (*(code **)(DAT_1403fc410 + 0x288) != (code *)0x0)) {

    (**(code **)(DAT_1403fc410 + 0x288))(DAT_1403fc410,param_1,param_2);

  }

  if (*(char *)(param_1 + 0x138) == '\0') {

    if ((*(code **)(DAT_1403fc410 + 0x260) != (code *)0x0) &&

       (cVar1 = (**(code **)(DAT_1403fc410 + 0x260))(DAT_1403fc410,param_1,param_2), cVar1 == '\0'))

    {

      return 0;

    }

    *(undefined1 *)(param_1 + 0x138) = 1;

  }

  return 1;

}




