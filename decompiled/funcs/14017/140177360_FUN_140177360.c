// Address: 0x140177360
// Ghidra name: FUN_140177360
// ============ 0x140177360 FUN_140177360 (size=161) ============


ulonglong FUN_140177360(void)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc468 == 0) {

    DAT_1403fc468 = FUN_140179a30();

  }

  uVar2 = FUN_14017e460(0x4000);

  if ((char)uVar2 != '\0') {

    FUN_140177410();

    DAT_1403fc478 = 1;

    cVar1 = (**(code **)PTR_PTR_1403e2870)();

    FUN_140177750();

    if (cVar1 == '\0') {

      FUN_1401775b0();

    }

    return (ulonglong)(cVar1 != '\0');

  }

  return uVar2;

}




