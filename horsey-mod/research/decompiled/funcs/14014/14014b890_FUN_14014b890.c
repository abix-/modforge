// Address: 0x14014b890
// Ghidra name: FUN_14014b890
// ============ 0x14014b890 FUN_14014b890 (size=165) ============


ulonglong FUN_14014b890(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  ulonglong uVar2;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      if (*(code **)(param_1 + 0xf8) == (code *)0x0) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

      uVar2 = (**(code **)(param_1 + 0xf8))(param_1,param_2,param_3,param_4);

      return uVar2;

    }

    uVar2 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return uVar2 & 0xffffffffffffff00;

}




