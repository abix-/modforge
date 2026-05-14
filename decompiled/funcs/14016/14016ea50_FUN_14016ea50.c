// Address: 0x14016ea50
// Ghidra name: FUN_14016ea50
// ============ 0x14016ea50 FUN_14016ea50 (size=107) ============


ulonglong FUN_14016ea50(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 == 0) {

LAB_14016eaa7:

    FUN_14012e850("Invalid window");

    uVar2 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016eaa7;

    }

    uVar2 = (ulonglong)*(uint *)(param_1 + 0x178);

    if (*(uint *)(param_1 + 0x178) == 0) {

      uVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x178) = (int)uVar2;

      return uVar2;

    }

  }

  return uVar2;

}




