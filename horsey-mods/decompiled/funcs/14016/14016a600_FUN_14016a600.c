// Address: 0x14016a600
// Ghidra name: FUN_14016a600
// ============ 0x14016a600 FUN_14016a600 (size=123) ============


ulonglong FUN_14016a600(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (*(code **)(DAT_1403fc410 + 0x278) == (code *)0x0) {

      return 1;

    }

                    /* WARNING: Could not recover jumptable at 0x00014016a65c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(DAT_1403fc410 + 0x278))(DAT_1403fc410,param_1);

    return uVar2;

  }

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




