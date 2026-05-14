// Address: 0x140170ff0
// Ghidra name: FUN_140170ff0
// ============ 0x140170ff0 FUN_140170ff0 (size=223) ============


ulonglong FUN_140170ff0(longlong param_1,longlong param_2)



{

  char cVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_1 == 0) {

LAB_1401710b6:

    uVar2 = FUN_14012e850("Invalid window");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_1401710b6;

    }

    if (param_2 == 0) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140334ddc);

      return uVar2;

    }

    FUN_140146010(*(undefined8 *)(param_1 + 0x10));

    lVar3 = FUN_140145bb0(param_2,0x16362004);

    *(longlong *)(param_1 + 0x10) = lVar3;

    uVar2 = 0;

    if (lVar3 != 0) {

      if (*(code **)(DAT_1403fc410 + 0x58) == (code *)0x0) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

                    /* WARNING: Could not recover jumptable at 0x0001401710b3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(DAT_1403fc410 + 0x58))(DAT_1403fc410,param_1,lVar3);

      return uVar2;

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




