// Address: 0x14016bd20
// Ghidra name: FUN_14016bd20
// ============ 0x14016bd20 FUN_14016bd20 (size=197) ============


ulonglong FUN_14016bd20(longlong param_1,undefined4 param_2)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    uVar2 = FUN_14012e850("Invalid window");

    return uVar2 & 0xffffffffffffff00;

  }

  if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

    uVar2 = FUN_14012e850("Operation invalid on popup windows");

    return uVar2 & 0xffffffffffffff00;

  }

  if (*(code **)(DAT_1403fc410 + 0x170) == (code *)0x0) {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

                    /* WARNING: Could not recover jumptable at 0x00014016bdb3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = (**(code **)(DAT_1403fc410 + 0x170))(DAT_1403fc410,param_1,param_2);

  return uVar2;

}




