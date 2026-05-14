// Address: 0x14016e780
// Ghidra name: FUN_14016e780
// ============ 0x14016e780 FUN_14016e780 (size=109) ============


undefined4 FUN_14016e780(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 == 0) {

LAB_14016e7d9:

    FUN_14012e850("Invalid window");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e7d9;

    }

    uVar2 = FUN_14016d540(param_1);

    lVar3 = FUN_14016d1d0(uVar2);

    if (lVar3 != 0) {

      return *(undefined4 *)(lVar3 + 4);

    }

  }

  return 0;

}




