// Address: 0x1401d5c60
// Ghidra name: FUN_1401d5c60
// ============ 0x1401d5c60 FUN_1401d5c60 (size=440) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1401d5c60(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6,

             char param_7)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short sVar11;

  short sVar12;

  short sVar13;

  short sVar14;

  short sVar15;

  short sVar16;

  short sVar17;

  short sVar18;

  int iVar19;

  undefined1 *puVar20;

  uint uVar21;

  uint uVar22;

  uint uVar23;

  uint uVar24;

  uint uVar25;

  int iVar26;

  int iVar27;

  undefined1 (*pauVar28) [16];

  undefined1 (*pauVar29) [16];

  undefined1 (*pauVar30) [16];

  int iVar31;

  longlong lVar32;

  uint uVar33;

  ulonglong uVar34;

  uint uVar35;

  ulonglong uVar36;

  undefined1 (*pauVar37) [16];

  undefined1 (*pauVar38) [16];

  uint uVar39;

  uint uVar40;

  uint uVar41;

  uint uVar42;

  uint uVar43;

  uint uVar44;

  uint uVar45;

  uint uVar46;

  ushort uVar47;

  ushort uVar48;

  ushort uVar49;

  ushort uVar50;

  ushort uVar51;

  ushort uVar52;

  ushort uVar53;

  ushort uVar54;

  ushort uVar55;

  ushort uVar56;

  ushort uVar57;

  ushort uVar58;

  ushort uVar59;

  ushort uVar60;

  ushort uVar61;

  ushort uVar62;

  

  uVar25 = (param_1 + 1) / 2;

  iVar26 = (param_2 + 1) / 2;

  uVar34 = (ulonglong)iVar26;

  iVar19 = ((param_4 + 1) / 2) * 2;

  iVar27 = (param_6 + 1) / 2;

  iVar31 = iVar27 - uVar25;

  pauVar30 = (undefined1 (*) [16])(param_3 + param_2 * param_4);

  pauVar37 = (undefined1 (*) [16])(param_2 * param_6 + param_5);

  pauVar28 = pauVar30;

  pauVar38 = (undefined1 (*) [16])0x0;

  if (pauVar30 == pauVar37) {

    lVar32 = (longlong)iVar19 * uVar34;

    pauVar28 = (undefined1 (*) [16])FUN_1401841f0(lVar32);

    if (pauVar28 == (undefined1 (*) [16])0x0) {

      return 0;

    }

    FUN_1402f8e20(pauVar28,pauVar30,lVar32);

    pauVar38 = pauVar28;

  }

  uVar24 = _UNK_14033c2bc;

  uVar23 = _UNK_14033c2b8;

  uVar22 = _UNK_14033c2b4;

  uVar21 = _DAT_14033c2b0;

  if (iVar26 != 0) {

    pauVar30 = pauVar37;

    if (param_7 == '\0') {

      pauVar30 = (undefined1 (*) [16])(*pauVar37 + iVar27 * iVar26);

    }

    pauVar29 = (undefined1 (*) [16])(*pauVar37 + iVar27 * iVar26);

    if (param_7 == '\0') {

      pauVar29 = pauVar37;

    }

    do {

      uVar33 = (int)uVar34 - 1;

      uVar34 = (ulonglong)uVar33;

      uVar35 = uVar25;

      if (0xf < (int)uVar25) {

        uVar36 = (ulonglong)(uVar25 >> 4);

        uVar35 = uVar25 + (uVar25 >> 4) * -0x10;

        do {

          auVar1 = *pauVar28;

          auVar2 = pauVar28[1];

          pauVar28 = pauVar28 + 2;

          uVar55 = auVar1._0_2_ >> 8;

          uVar56 = auVar1._2_2_ >> 8;

          uVar57 = auVar1._4_2_ >> 8;

          uVar58 = auVar1._6_2_ >> 8;

          uVar59 = auVar1._8_2_ >> 8;

          uVar60 = auVar1._10_2_ >> 8;

          uVar61 = auVar1._12_2_ >> 8;

          uVar62 = auVar1._14_2_ >> 8;

          uVar43 = auVar1._0_4_ & uVar21;

          uVar44 = auVar1._4_4_ & uVar22;

          uVar45 = auVar1._8_4_ & uVar23;

          uVar46 = auVar1._12_4_ & uVar24;

          uVar39 = auVar2._0_4_ & uVar21;

          uVar40 = auVar2._4_4_ & uVar22;

          uVar41 = auVar2._8_4_ & uVar23;

          uVar42 = auVar2._12_4_ & uVar24;

          uVar47 = auVar2._0_2_ >> 8;

          uVar48 = auVar2._2_2_ >> 8;

          uVar49 = auVar2._4_2_ >> 8;

          uVar50 = auVar2._6_2_ >> 8;

          uVar51 = auVar2._8_2_ >> 8;

          uVar52 = auVar2._10_2_ >> 8;

          uVar53 = auVar2._12_2_ >> 8;

          uVar54 = auVar2._14_2_ >> 8;

          sVar3 = (short)uVar43;

          sVar4 = (short)(uVar43 >> 0x10);

          sVar5 = (short)uVar44;

          sVar6 = (short)(uVar44 >> 0x10);

          sVar7 = (short)uVar45;

          sVar8 = (short)(uVar45 >> 0x10);

          sVar9 = (short)uVar46;

          sVar10 = (short)(uVar46 >> 0x10);

          sVar11 = (short)uVar39;

          sVar12 = (short)(uVar39 >> 0x10);

          sVar13 = (short)uVar40;

          sVar14 = (short)(uVar40 >> 0x10);

          sVar15 = (short)uVar41;

          sVar16 = (short)(uVar41 >> 0x10);

          sVar17 = (short)uVar42;

          sVar18 = (short)(uVar42 >> 0x10);

          (*pauVar29)[0] = (0 < sVar3) * (sVar3 < 0x100) * (char)uVar43 - (0xff < sVar3);

          (*pauVar29)[1] = (0 < sVar4) * (sVar4 < 0x100) * (char)(uVar43 >> 0x10) - (0xff < sVar4);

          (*pauVar29)[2] = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar44 - (0xff < sVar5);

          (*pauVar29)[3] = (0 < sVar6) * (sVar6 < 0x100) * (char)(uVar44 >> 0x10) - (0xff < sVar6);

          (*pauVar29)[4] = (0 < sVar7) * (sVar7 < 0x100) * (char)uVar45 - (0xff < sVar7);

          (*pauVar29)[5] = (0 < sVar8) * (sVar8 < 0x100) * (char)(uVar45 >> 0x10) - (0xff < sVar8);

          (*pauVar29)[6] = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar46 - (0xff < sVar9);

          (*pauVar29)[7] =

               (0 < sVar10) * (sVar10 < 0x100) * (char)(uVar46 >> 0x10) - (0xff < sVar10);

          (*pauVar29)[8] = (0 < sVar11) * (sVar11 < 0x100) * (char)uVar39 - (0xff < sVar11);

          (*pauVar29)[9] =

               (0 < sVar12) * (sVar12 < 0x100) * (char)(uVar39 >> 0x10) - (0xff < sVar12);

          (*pauVar29)[10] = (0 < sVar13) * (sVar13 < 0x100) * (char)uVar40 - (0xff < sVar13);

          (*pauVar29)[0xb] =

               (0 < sVar14) * (sVar14 < 0x100) * (char)(uVar40 >> 0x10) - (0xff < sVar14);

          (*pauVar29)[0xc] = (0 < sVar15) * (sVar15 < 0x100) * (char)uVar41 - (0xff < sVar15);

          (*pauVar29)[0xd] =

               (0 < sVar16) * (sVar16 < 0x100) * (char)(uVar41 >> 0x10) - (0xff < sVar16);

          (*pauVar29)[0xe] = (0 < sVar17) * (sVar17 < 0x100) * (char)uVar42 - (0xff < sVar17);

          (*pauVar29)[0xf] =

               (0 < sVar18) * (sVar18 < 0x100) * (char)(uVar42 >> 0x10) - (0xff < sVar18);

          pauVar29 = pauVar29 + 1;

          (*pauVar30)[0] = (uVar55 != 0) * (uVar55 < 0x100) * auVar1[1] - (0xff < uVar55);

          (*pauVar30)[1] = (uVar56 != 0) * (uVar56 < 0x100) * auVar1[3] - (0xff < uVar56);

          (*pauVar30)[2] = (uVar57 != 0) * (uVar57 < 0x100) * auVar1[5] - (0xff < uVar57);

          (*pauVar30)[3] = (uVar58 != 0) * (uVar58 < 0x100) * auVar1[7] - (0xff < uVar58);

          (*pauVar30)[4] = (uVar59 != 0) * (uVar59 < 0x100) * auVar1[9] - (0xff < uVar59);

          (*pauVar30)[5] = (uVar60 != 0) * (uVar60 < 0x100) * auVar1[0xb] - (0xff < uVar60);

          (*pauVar30)[6] = (uVar61 != 0) * (uVar61 < 0x100) * auVar1[0xd] - (0xff < uVar61);

          (*pauVar30)[7] = (uVar62 != 0) * (uVar62 < 0x100) * auVar1[0xf] - (0xff < uVar62);

          (*pauVar30)[8] = (uVar47 != 0) * (uVar47 < 0x100) * auVar2[1] - (0xff < uVar47);

          (*pauVar30)[9] = (uVar48 != 0) * (uVar48 < 0x100) * auVar2[3] - (0xff < uVar48);

          (*pauVar30)[10] = (uVar49 != 0) * (uVar49 < 0x100) * auVar2[5] - (0xff < uVar49);

          (*pauVar30)[0xb] = (uVar50 != 0) * (uVar50 < 0x100) * auVar2[7] - (0xff < uVar50);

          (*pauVar30)[0xc] = (uVar51 != 0) * (uVar51 < 0x100) * auVar2[9] - (0xff < uVar51);

          (*pauVar30)[0xd] = (uVar52 != 0) * (uVar52 < 0x100) * auVar2[0xb] - (0xff < uVar52);

          (*pauVar30)[0xe] = (uVar53 != 0) * (uVar53 < 0x100) * auVar2[0xd] - (0xff < uVar53);

          (*pauVar30)[0xf] = (uVar54 != 0) * (uVar54 < 0x100) * auVar2[0xf] - (0xff < uVar54);

          pauVar30 = pauVar30 + 1;

          uVar36 = uVar36 - 1;

        } while (uVar36 != 0);

      }

      for (; uVar35 != 0; uVar35 = uVar35 - 1) {

        (*pauVar29)[0] = (*pauVar28)[0];

        pauVar29 = (undefined1 (*) [16])(*pauVar29 + 1);

        puVar20 = *pauVar28;

        pauVar28 = (undefined1 (*) [16])(*pauVar28 + 2);

        (*pauVar30)[0] = puVar20[1];

        pauVar30 = (undefined1 (*) [16])(*pauVar30 + 1);

      }

      pauVar28 = (undefined1 (*) [16])(*pauVar28 + (int)(iVar19 + uVar25 * -2));

      pauVar29 = (undefined1 (*) [16])(*pauVar29 + iVar31);

      pauVar30 = (undefined1 (*) [16])(*pauVar30 + iVar31);

    } while (uVar33 != 0);

  }

  if (pauVar38 != (undefined1 (*) [16])0x0) {

    FUN_1401841e0(pauVar38);

  }

  return 1;

}




