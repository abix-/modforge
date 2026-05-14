// Address: 0x14014f530
// Ghidra name: FUN_14014f530
// ============ 0x14014f530 FUN_14014f530 (size=91) ============


ulonglong FUN_14014f530(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

LAB_14014f570:

    FUN_14012e850("Parameter \'%s\' is invalid","texture");

    uVar2 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014f570;

    }

    uVar2 = (ulonglong)*(uint *)(param_1 + 0x134);

    if (*(uint *)(param_1 + 0x134) == 0) {

      uVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x134) = (int)uVar2;

      return uVar2;

    }

  }

  return uVar2;

}




