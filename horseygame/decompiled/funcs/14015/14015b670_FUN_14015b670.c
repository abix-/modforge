// Address: 0x14015b670
// Ghidra name: FUN_14015b670
// ============ 0x14015b670 FUN_14015b670 (size=119) ============


ulonglong FUN_14015b670(undefined4 *param_1,undefined4 param_2)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_14015b6c2;

    }

    bVar2 = FUN_14015b440(param_2,*param_1);

    FUN_14015bb10();

    return (ulonglong)bVar2;

  }

LAB_14015b6c2:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




