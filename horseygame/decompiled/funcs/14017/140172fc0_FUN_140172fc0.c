// Address: 0x140172fc0
// Ghidra name: FUN_140172fc0
// ============ 0x140172fc0 FUN_140172fc0 (size=93) ============


ulonglong FUN_140172fc0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_140173009;

    }

    return (ulonglong)*(byte *)(param_1 + 0x138);

  }

LAB_140173009:

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




