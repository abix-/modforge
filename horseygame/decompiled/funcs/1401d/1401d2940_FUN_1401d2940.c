// Address: 0x1401d2940
// Ghidra name: FUN_1401d2940
// ============ 0x1401d2940 FUN_1401d2940 (size=702) ============


undefined8 FUN_1401d2940(byte *param_1)



{

  uint uVar1;

  char cVar2;

  code *pcVar3;

  uint uVar4;

  

  if ((param_1[0x30] & 4) != 0) {

    FUN_1401d2c00();

  }

  uVar4 = *(uint *)(param_1 + 4);

  if (uVar4 == 0) {

    return 0;

  }

  if ((uVar4 & 0xf0000000) != 0x10000000) {

    return 0;

  }

  if ((uVar4 & 0xff00) < 0x800) {

    return 0;

  }

  if (*(longlong *)(param_1 + 0x18) == 0) {

    return 0;

  }

  uVar1 = *(uint *)(param_1 + 0x108);

  if ((uVar1 >> 10 & 1) == 0) {

    if ((uVar1 & 0x10) == 0) {

      return 0;

    }

    if ((((uVar4 & 0xf000000) != 0x4000000) &&

        (((uVar4 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) ||

       ((uVar4 = uVar4 & 0xf00000, uVar4 != 0x300000 &&

        (((uVar4 != 0x400000 && (uVar4 != 0x700000)) && (uVar4 != 0x800000)))))) {

      uVar4 = *(uint *)(param_1 + 4) & 0xf000000;

      if ((uVar4 != 0x7000000) && ((uVar4 + 0xf8000000 & 0xfcffffff) != 0)) {

        return 0;

      }

      uVar4 = *(uint *)(param_1 + 4) & 0xf00000;

      if (((uVar4 != 0x300000) && (uVar4 != 0x200000)) &&

         ((uVar4 != 0x600000 && (uVar4 != 0x500000)))) {

        return 0;

      }

    }

  }

  if ((uVar1 & 1) != 0) {

    return 0;

  }

  if ((uVar1 & 2) != 0) {

    uVar4 = *(uint *)(param_1 + 4) & 0xf000000;

    if ((uVar4 == 0x4000000) || ((uVar4 + 0xfb000000 & 0xfeffffff) == 0)) {

      uVar4 = *(uint *)(param_1 + 4) & 0xf00000;

      if (uVar4 == 0x300000) {

        return 0;

      }

      if (uVar4 == 0x400000) {

        return 0;

      }

      if (uVar4 == 0x700000) {

        return 0;

      }

      if (uVar4 == 0x800000) {

        return 0;

      }

    }

    uVar4 = *(uint *)(param_1 + 4) & 0xf000000;

    if ((uVar4 == 0x7000000) || ((uVar4 + 0xf8000000 & 0xfcffffff) == 0)) {

      uVar4 = *(uint *)(param_1 + 4) & 0xf00000;

      if (uVar4 == 0x300000) {

        return 0;

      }

      if (uVar4 == 0x200000) {

        return 0;

      }

      if (uVar4 == 0x600000) {

        return 0;

      }

      if (uVar4 == 0x500000) {

        return 0;

      }

    }

  }

  if ((uVar1 & 0xbe0) != 0) {

    return 0;

  }

  uVar4 = *(uint *)(param_1 + 4) & 0xf000000;

  if (((uVar4 == 0x4000000) || ((uVar4 + 0xfb000000 & 0xfeffffff) == 0)) &&

     ((uVar4 = *(uint *)(param_1 + 4) & 0xf00000, uVar4 == 0x300000 ||

      (((uVar4 == 0x400000 || (uVar4 == 0x700000)) || (uVar4 == 0x800000)))))) {

LAB_1401d2b7c:

    if ((uVar1 & 0x10) != 0) {

      cVar2 = FUN_1401ceb30(param_1);

      if (cVar2 == '\0') {

        return 0;

      }

      *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x4000;

      pcVar3 = FUN_1401d0e20;

      goto LAB_1401d2bc3;

    }

  }

  else {

    uVar4 = *(uint *)(param_1 + 4) & 0xf000000;

    if (((uVar4 == 0x7000000) || ((uVar4 + 0xf8000000 & 0xfcffffff) == 0)) &&

       ((uVar4 = *(uint *)(param_1 + 4) & 0xf00000, uVar4 == 0x300000 ||

        (((uVar4 == 0x200000 || (uVar4 == 0x600000)) || (uVar4 == 0x500000)))))) goto LAB_1401d2b7c;

  }

  if ((*(int *)(param_1 + 0x78) == 0) || (cVar2 = FUN_1401d09c0(param_1), cVar2 == '\0')) {

    return 0;

  }

  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x2000;

  pcVar3 = FUN_1401d1440;

LAB_1401d2bc3:

  *(code **)(param_1 + 0x80) = pcVar3;

  if ((*param_1 & 1) == 0) {

    *(undefined8 *)(param_1 + 0x120) = *(undefined8 *)(param_1 + 0x18);

    param_1[0x18] = 0;

    param_1[0x19] = 0;

    param_1[0x1a] = 0;

    param_1[0x1b] = 0;

    param_1[0x1c] = 0;

    param_1[0x1d] = 0;

    param_1[0x1e] = 0;

    param_1[0x1f] = 0;

  }

  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;

  FUN_140148a20(param_1);

  return 1;

}




