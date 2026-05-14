// Address: 0x14016fa80
// Ghidra name: FUN_14016fa80
// ============ 0x14016fa80 FUN_14016fa80 (size=123) ============


undefined8 FUN_14016fa80(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (((*(byte *)(param_1 + 0x48) & 8) == 0) && (*(code **)(DAT_1403fc410 + 200) != (code *)0x0))

    {

      (**(code **)(DAT_1403fc410 + 200))(DAT_1403fc410,param_1);

    }

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




