// Address: 0x140170710
// Ghidra name: FUN_140170710
// ============ 0x140170710 FUN_140170710 (size=231) ============


undefined8 FUN_140170710(longlong param_1,char param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 != '\0')))) {

    lVar2 = DAT_1403fc410;

    uVar1 = *(ulonglong *)(param_1 + 0x48);

    if ((uVar1 & 0xc0000) == 0) {

      if (((param_2 != '\0') != (bool)((byte)(uVar1 >> 0x10) & 1)) &&

         (*(longlong *)(DAT_1403fc410 + 0xf8) != 0)) {

        uVar4 = uVar1 | 0x10000;

        if (param_2 == '\0') {

          uVar4 = uVar1 & 0xfffffffffffeffff;

        }

        *(ulonglong *)(param_1 + 0x48) = uVar4;

        (**(code **)(lVar2 + 0xf8))(lVar2,param_1);

      }

      return 1;

    }

    FUN_14012e850("Operation invalid on popup windows");

    return 0;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




