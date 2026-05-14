// Address: 0x140170f10
// Ghidra name: FUN_140170f10
// ============ 0x140170f10 FUN_140170f10 (size=209) ============


ulonglong FUN_140170f10(longlong param_1,longlong param_2,undefined8 param_3)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    lVar1 = DAT_1403fc410;

    if (*(longlong *)(DAT_1403fc410 + 0x2f8) != 0) {

      *(longlong *)(param_1 + 0x160) = param_2;

      *(undefined8 *)(param_1 + 0x168) = param_3;

                    /* WARNING: Could not recover jumptable at 0x000140170fc0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar3 = (**(code **)(lVar1 + 0x2f8))(param_1,param_2 != 0);

      return uVar3;

    }

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  uVar3 = FUN_14012e850("Invalid window");

  return uVar3 & 0xffffffffffffff00;

}




