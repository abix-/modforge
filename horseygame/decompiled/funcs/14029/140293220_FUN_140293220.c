// Address: 0x140293220
// Ghidra name: FUN_140293220
// ============ 0x140293220 FUN_140293220 (size=202) ============


code * FUN_140293220(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  code *pcVar3;

  

  pcVar3 = (code *)0x0;

  uVar1 = **(uint **)(param_1 + 0xe8);

  if (((uVar1 == 0) || ((uVar1 & 0xf0000000) != 0x10000000)) ||

     (uVar2 = uVar1 & 0xff, (uVar1 & 0xff00) < 0x800)) {

    uVar2 = 0;

  }

  uVar1 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

  if ((int)uVar1 < 0x401) {

    if (uVar1 != 0x400) {

      if (uVar1 == 0) {

        if (4 < uVar2) {

          return (code *)0x0;

        }

        return *(code **)(&DAT_1403813c0 + (ulonglong)uVar2 * 8);

      }

      if ((uVar1 - 0x10 & 0xfffffffd) != 0) {

        return (code *)0x0;

      }

      if (1 < uVar2) {

        pcVar3 = FUN_140291460;

      }

      return pcVar3;

    }

joined_r0x0001402932d6:

    if (4 < uVar2) {

      return (code *)0x0;

    }

    return *(code **)(&DAT_1403813e8 + (ulonglong)uVar2 * 8);

  }

  if (uVar1 == 0x410) {

    if (*(char *)(param_1 + 0x113) == -1) goto joined_r0x0001402932d6;

  }

  else if (uVar1 != 0x412) {

    return (code *)0x0;

  }

  if (1 < uVar2) {

    pcVar3 = FUN_140292310;

  }

  return pcVar3;

}




