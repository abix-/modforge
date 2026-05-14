// Address: 0x140170250
// Ghidra name: FUN_140170250
// ============ 0x140170250 FUN_140170250 (size=94) ============


ulonglong FUN_140170250(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    return (ulonglong)*(byte *)(DAT_1403fc410 + 0x39c);

  }

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




