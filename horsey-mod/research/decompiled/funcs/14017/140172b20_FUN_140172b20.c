// Address: 0x140172b20
// Ghidra name: FUN_140172b20
// ============ 0x140172b20 FUN_140172b20 (size=213) ============


undefined8 FUN_140172b20(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  char cVar1;

  undefined8 uVar2;

  char *pcVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    pcVar3 = "Invalid window";

  }

  else {

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) == 0) {

      if (*(code **)(DAT_1403fc410 + 0x308) == (code *)0x0) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

      (**(code **)(DAT_1403fc410 + 0x308))(param_1,param_2,param_3);

      return 1;

    }

    pcVar3 = "Operation invalid on popup windows";

  }

  FUN_14012e850(pcVar3);

  return 0;

}




