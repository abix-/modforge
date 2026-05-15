// Address: 0x140290640
// Ghidra name: FUN_140290640
// ============ 0x140290640 FUN_140290640 (size=394) ============


code * FUN_140290640(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  code *pcVar3;

  int iVar4;

  

  pcVar3 = (code *)0x0;

  uVar1 = **(uint **)(param_1 + 0xe8);

  if (((uVar1 == 0) || ((uVar1 & 0xf0000000) != 0x10000000)) ||

     (uVar2 = uVar1 & 0xff, (uVar1 & 0xff00) < 0x800)) {

    uVar2 = 0;

  }

  uVar1 = *(uint *)(param_1 + 4) & 0xf000000;

  if (uVar1 == 0x1000000) {

    uVar1 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

    if (uVar1 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_1403812d0 + (ulonglong)uVar2 * 8);

    }

    if (uVar1 == 0x12) goto LAB_1402906e2;

    iVar4 = uVar1 - 0x400;

    if (iVar4 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_1403812f8 + (ulonglong)uVar2 * 8);

    }

  }

  else if (uVar1 == 0xc000000) {

    uVar1 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

    if (uVar1 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_140381320 + (ulonglong)uVar2 * 8);

    }

    if (uVar1 == 0x12) {

LAB_1402906e2:

      if (1 < uVar2) {

        pcVar3 = FUN_14028f280;

      }

      return pcVar3;

    }

    iVar4 = uVar1 - 0x400;

    if (iVar4 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_140381348 + (ulonglong)uVar2 * 8);

    }

  }

  else {

    if (uVar1 != 0x2000000) {

      return (code *)0x0;

    }

    uVar1 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

    if (uVar1 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_140381370 + (ulonglong)uVar2 * 8);

    }

    if (uVar1 == 0x12) goto LAB_1402906e2;

    iVar4 = uVar1 - 0x400;

    if (iVar4 == 0) {

      if (4 < uVar2) {

        return (code *)0x0;

      }

      return *(code **)(&DAT_140381398 + (ulonglong)uVar2 * 8);

    }

  }

  if (iVar4 != 0x12) {

    return (code *)0x0;

  }

  if (1 < uVar2) {

    pcVar3 = FUN_14028fc70;

  }

  return pcVar3;

}




