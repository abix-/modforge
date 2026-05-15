// Address: 0x1401934d0
// Ghidra name: FUN_1401934d0
// ============ 0x1401934d0 FUN_1401934d0 (size=78) ============


ulonglong FUN_1401934d0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

LAB_14019350a:

    FUN_14012e850("Invalid device");

    uVar2 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_14019350a;

    }

    uVar2 = (ulonglong)*(uint *)(param_1 + 0x60);

    if (*(uint *)(param_1 + 0x60) == 0) {

      uVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x60) = (int)uVar2;

      return uVar2;

    }

  }

  return uVar2;

}




