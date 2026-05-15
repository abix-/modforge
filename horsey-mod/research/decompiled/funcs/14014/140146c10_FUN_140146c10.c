// Address: 0x140146c10
// Ghidra name: FUN_140146c10
// ============ 0x140146c10 FUN_140146c10 (size=131) ============


ulonglong FUN_140146c10(longlong param_1,uint param_2)



{

  char cVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  uint uVar4;

  

  uVar4 = DAT_14039ca44;

  param_2 = param_2 & 0x3e0;

  if ((param_2 != 0x100) && (param_2 != 0x200)) {

    return (ulonglong)DAT_14039ca44;

  }

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = 0;

  }

  else {

    uVar2 = *(undefined4 *)(param_1 + 0x34);

  }

  if (param_2 == 0x200) {

    uVar4 = DAT_14030a234;

  }

  uVar3 = FUN_140174af0(uVar2,"SDL.surface.SDR_white_point",uVar4);

  return uVar3;

}




