// Address: 0x14016ce50
// Ghidra name: FUN_14016ce50
// ============ 0x14016ce50 FUN_14016ce50 (size=155) ============


ulonglong FUN_14016ce50(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016ced7;

    }

    if ((*(byte *)(param_1 + 0x48) & 2) == 0) {

      uVar2 = FUN_14012e850("The specified window isn\'t an OpenGL window");

      return uVar2;

    }

    lVar3 = FUN_14016c700();

    if (lVar3 != param_1) {

      uVar2 = FUN_14012e850("The specified window has not been made current");

      return uVar2;

    }

                    /* WARNING: Could not recover jumptable at 0x00014016ced4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(DAT_1403fc410 + 0x1e0))(DAT_1403fc410,param_1);

    return uVar2;

  }

LAB_14016ced7:

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




