// Address: 0x14017f8f0
// Ghidra name: FUN_14017f8f0
// ============ 0x14017f8f0 FUN_14017f8f0 (size=643) ============


uint FUN_14017f8f0(void)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  

  if (DAT_1403e28f8 == 0xffffffff) {

    FUN_14017f460();

    uVar7 = 8;

    DAT_1403e28f8 = 0;

    DAT_1403e28fc = 8;

    iVar2 = FUN_14017f5a0();

    uVar6 = 0x10;

    uVar3 = DAT_1403e28fc;

    if (iVar2 != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 1;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if (((DAT_1403fc69c >> 0x17 & 1) != 0) &&

       (DAT_1403e28f8 = DAT_1403e28f8 | 2, uVar3 = uVar7, uVar7 < DAT_1403e28fc)) {

      uVar3 = DAT_1403e28fc;

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc69c >> 0x19 & 1) != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 4;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc69c >> 0x1a & 1) != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 8;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc698 & 1) != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 0x10;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc698 >> 0x13 & 1) != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 0x20;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc698 >> 0x14 & 1) != 0) {

      DAT_1403e28f8 = DAT_1403e28f8 | 0x40;

      uVar3 = 0x10;

      if (0x10 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar7 = 0x20;

    uVar3 = DAT_1403e28fc;

    if ((DAT_1403fc6a4 != '\0') && ((DAT_1403fc698 >> 0x1c & 1) != 0)) {

      DAT_1403e28f8 = DAT_1403e28f8 | 0x80;

      uVar3 = 0x20;

      if (0x20 < DAT_1403e28fc) {

        uVar3 = DAT_1403e28fc;

      }

    }

    DAT_1403e28fc = uVar3;

    uVar5 = DAT_1403e28f8;

    uVar4 = DAT_1403e28fc;

    iVar2 = FUN_14017f520();

    uVar3 = uVar4;

    if ((iVar2 != 0) &&

       (uVar5 = uVar5 | 0x100, uVar3 = uVar7, DAT_1403e28f8 = uVar5, DAT_1403e28fc = uVar7,

       uVar7 < uVar4)) {

      uVar3 = uVar4;

      DAT_1403e28fc = uVar4;

    }

    iVar2 = FUN_14017f560();

    uVar4 = uVar3;

    if (iVar2 != 0) {

      uVar5 = uVar5 | 0x400;

      uVar4 = 0x40;

      DAT_1403e28f8 = uVar5;

      DAT_1403e28fc = 0x40;

      if (0x40 < uVar3) {

        uVar4 = uVar3;

        DAT_1403e28fc = uVar3;

      }

    }

    iVar2 = FUN_1400248b0();

    uVar3 = uVar4;

    if ((iVar2 != 0) &&

       (uVar5 = uVar5 | 0x800, uVar3 = uVar6, DAT_1403e28f8 = uVar5, DAT_1403e28fc = uVar6,

       uVar6 < uVar4)) {

      uVar3 = uVar4;

      DAT_1403e28fc = uVar4;

    }

    iVar2 = FUN_1400248b0();

    uVar4 = uVar3;

    if ((iVar2 != 0) &&

       (uVar5 = uVar5 | 0x200, uVar4 = uVar6, DAT_1403e28f8 = uVar5, DAT_1403e28fc = uVar6,

       uVar6 < uVar3)) {

      uVar4 = uVar3;

      DAT_1403e28fc = uVar3;

    }

    bVar1 = FUN_1400248b0();

    uVar3 = uVar4;

    if (((bVar1 & 0x40) != 0) &&

       (uVar5 = uVar5 | 0x1000, uVar3 = uVar6, DAT_1403e28f8 = uVar5, DAT_1403e28fc = uVar6,

       uVar6 < uVar4)) {

      uVar3 = uVar4;

      DAT_1403e28fc = uVar4;

    }

    if (((char)bVar1 < '\0') &&

       (DAT_1403e28f8 = uVar5 | 0x2000, DAT_1403e28fc = uVar7, uVar7 < uVar3)) {

      DAT_1403e28fc = uVar3;

    }

    uVar3 = FUN_14017f5b0();

    DAT_1403e28f8 = DAT_1403e28f8 & uVar3;

  }

  return DAT_1403e28f8;

}




