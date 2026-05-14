// Address: 0x140174060
// Ghidra name: FUN_140174060
// ============ 0x140174060 FUN_140174060 (size=128) ============


ulonglong FUN_140174060(longlong param_1,longlong param_2,undefined4 param_3)



{

  ulonglong uVar1;

  

  if (DAT_1403fc410 == 0) {

    uVar1 = FUN_1401730c0();

    return uVar1 & 0xffffffffffffff00;

  }

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","instance");

    return uVar1 & 0xffffffffffffff00;

  }

  if (param_2 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","physicalDevice");

    return uVar1 & 0xffffffffffffff00;

  }

  if (*(code **)(DAT_1403fc410 + 0x220) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0001401740d6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(DAT_1403fc410 + 0x220))(DAT_1403fc410,param_1,param_2,param_3);

    return uVar1;

  }

  return 1;

}




