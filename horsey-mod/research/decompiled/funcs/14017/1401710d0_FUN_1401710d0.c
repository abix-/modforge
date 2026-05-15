// Address: 0x1401710d0
// Ghidra name: FUN_1401710d0
// ============ 0x1401710d0 FUN_1401710d0 (size=268) ============


uint FUN_1401710d0(longlong param_1,char param_2)



{

  char cVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_1401711c3;

    }

    uVar2 = *(ulonglong *)(param_1 + 0x48);

    if ((uVar2 & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return 0;

    }

    if ((uVar2 & 8) == 0) {

      if ((uint)(param_2 != '\0') != ((uint)(uVar2 >> 0x14) & 1)) {

        uVar3 = uVar2 | 0x100000;

        if (param_2 == '\0') {

          uVar3 = uVar2 & 0xffffffffffefffff;

        }

        *(ulonglong *)(param_1 + 0x48) = uVar3;

        FUN_1401735a0(param_1);

        if (param_2 != '\0') {

          return *(uint *)(param_1 + 0x48) >> 0x14 & 1;

        }

      }

    }

    else {

      uVar2 = *(ulonglong *)(param_1 + 0x50) | 0x100000;

      if (param_2 == '\0') {

        uVar2 = *(ulonglong *)(param_1 + 0x50) & 0xffffffffffefffff;

      }

      *(ulonglong *)(param_1 + 0x50) = uVar2;

    }

    return 1;

  }

LAB_1401711c3:

  FUN_14012e850("Invalid window");

  return 0;

}




