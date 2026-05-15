// Address: 0x14016e330
// Ghidra name: FUN_14016e330
// ============ 0x14016e330 FUN_14016e330 (size=119) ============


ulonglong FUN_14016e330(ulonglong param_1)



{

  uint uVar1;

  char cVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 == '\0')))) {

    uVar3 = FUN_14012e850("Invalid window");

  }

  else {

    uVar3 = *(ulonglong *)(DAT_1403fc410 + 0x350);

    if (param_1 == uVar3) {

      uVar1 = *(uint *)(uVar3 + 0x48);

      uVar3 = (ulonglong)uVar1;

      if ((uVar1 >> 0x14 & 1) != 0) {

        return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);

      }

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




