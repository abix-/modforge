// Address: 0x1401468a0
// Ghidra name: FUN_1401468a0
// ============ 0x1401468a0 FUN_1401468a0 (size=81) ============


ulonglong FUN_1401468a0(longlong param_1,uint param_2)



{

  char cVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  

  if (((param_2 & 0x3e0) != 0x100) && ((param_2 & 0x3e0) != 0x200)) {

    return (ulonglong)DAT_14039ca44;

  }

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = 0;

  }

  else {

    uVar2 = *(undefined4 *)(param_1 + 0x34);

  }

  uVar3 = FUN_140174af0(uVar2,"SDL.surface.HDR_headroom",0);

  return uVar3;

}




