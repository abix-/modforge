// Address: 0x14014fbe0
// Ghidra name: FUN_14014fbe0
// ============ 0x14014fbe0 FUN_14014fbe0 (size=110) ============


ulonglong FUN_14014fbe0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014fc33;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      uVar2 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return uVar2 & 0xffffffffffffff00;

    }

    return (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x138) + 0x48);

  }

LAB_14014fc33:

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return uVar2 & 0xffffffffffffff00;

}




