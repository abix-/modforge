// Address: 0x1401d4a90
// Ghidra name: FUN_1401d4a90
// ============ 0x1401d4a90 FUN_1401d4a90 (size=424) ============


undefined8

FUN_1401d4a90(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6,

             char param_7)



{

  undefined1 uVar1;

  longlong lVar2;

  undefined1 uVar3;

  undefined1 uVar4;

  undefined1 uVar5;

  undefined1 uVar6;

  undefined1 uVar7;

  undefined1 uVar8;

  undefined1 uVar9;

  undefined1 uVar10;

  undefined1 uVar11;

  undefined1 uVar12;

  undefined1 uVar13;

  undefined1 uVar14;

  undefined1 uVar15;

  undefined1 uVar16;

  undefined1 uVar17;

  undefined1 uVar18;

  undefined1 uVar19;

  undefined1 uVar20;

  undefined1 uVar21;

  undefined1 uVar22;

  undefined1 uVar23;

  undefined1 uVar24;

  undefined1 uVar25;

  undefined1 uVar26;

  undefined1 uVar27;

  undefined1 uVar28;

  undefined1 uVar29;

  undefined1 uVar30;

  undefined1 uVar31;

  undefined1 uVar32;

  undefined1 uVar33;

  uint uVar34;

  int iVar35;

  int iVar36;

  undefined1 *puVar37;

  undefined1 *puVar38;

  undefined1 *puVar39;

  uint uVar40;

  ulonglong uVar41;

  uint uVar42;

  ulonglong uVar43;

  undefined1 *puVar44;

  

  uVar34 = (param_1 + 1) / 2;

  puVar37 = (undefined1 *)0x0;

  iVar35 = (param_2 + 1) / 2;

  uVar41 = (ulonglong)iVar35;

  iVar36 = (param_4 + 1) / 2;

  puVar44 = (undefined1 *)(param_3 + param_2 * param_4);

  puVar39 = (undefined1 *)(param_5 + param_2 * param_6);

  if (puVar44 == puVar39) {

    lVar2 = (longlong)iVar36 * uVar41 * 2;

    puVar37 = (undefined1 *)FUN_1401841f0(lVar2);

    if (puVar37 == (undefined1 *)0x0) {

      return 0;

    }

    FUN_1402f8e20(puVar37,puVar44,lVar2);

    puVar44 = puVar37;

  }

  if (iVar35 != 0) {

    puVar38 = puVar44 + iVar36 * iVar35;

    if (param_7 == '\0') {

      puVar38 = puVar44;

      puVar44 = puVar44 + iVar36 * iVar35;

    }

    do {

      uVar40 = (int)uVar41 - 1;

      uVar41 = (ulonglong)uVar40;

      uVar42 = uVar34;

      if (0xf < (int)uVar34) {

        uVar43 = (ulonglong)(uVar34 >> 4);

        uVar42 = uVar34 + (uVar34 >> 4) * -0x10;

        do {

          uVar1 = *puVar38;

          uVar3 = puVar38[1];

          uVar4 = puVar38[2];

          uVar5 = puVar38[3];

          uVar6 = puVar38[4];

          uVar7 = puVar38[5];

          uVar8 = puVar38[6];

          uVar9 = puVar38[7];

          uVar10 = puVar38[8];

          uVar11 = puVar38[9];

          uVar12 = puVar38[10];

          uVar13 = puVar38[0xb];

          uVar14 = puVar38[0xc];

          uVar15 = puVar38[0xd];

          uVar16 = puVar38[0xe];

          uVar17 = puVar38[0xf];

          puVar38 = puVar38 + 0x10;

          uVar18 = *puVar44;

          uVar19 = puVar44[1];

          uVar20 = puVar44[2];

          uVar21 = puVar44[3];

          uVar22 = puVar44[4];

          uVar23 = puVar44[5];

          uVar24 = puVar44[6];

          uVar25 = puVar44[7];

          uVar26 = puVar44[8];

          uVar27 = puVar44[9];

          uVar28 = puVar44[10];

          uVar29 = puVar44[0xb];

          uVar30 = puVar44[0xc];

          uVar31 = puVar44[0xd];

          uVar32 = puVar44[0xe];

          uVar33 = puVar44[0xf];

          puVar44 = puVar44 + 0x10;

          *puVar39 = uVar1;

          puVar39[1] = uVar18;

          puVar39[2] = uVar3;

          puVar39[3] = uVar19;

          puVar39[4] = uVar4;

          puVar39[5] = uVar20;

          puVar39[6] = uVar5;

          puVar39[7] = uVar21;

          puVar39[8] = uVar6;

          puVar39[9] = uVar22;

          puVar39[10] = uVar7;

          puVar39[0xb] = uVar23;

          puVar39[0xc] = uVar8;

          puVar39[0xd] = uVar24;

          puVar39[0xe] = uVar9;

          puVar39[0xf] = uVar25;

          puVar39[0x10] = uVar10;

          puVar39[0x11] = uVar26;

          puVar39[0x12] = uVar11;

          puVar39[0x13] = uVar27;

          puVar39[0x14] = uVar12;

          puVar39[0x15] = uVar28;

          puVar39[0x16] = uVar13;

          puVar39[0x17] = uVar29;

          puVar39[0x18] = uVar14;

          puVar39[0x19] = uVar30;

          puVar39[0x1a] = uVar15;

          puVar39[0x1b] = uVar31;

          puVar39[0x1c] = uVar16;

          puVar39[0x1d] = uVar32;

          puVar39[0x1e] = uVar17;

          puVar39[0x1f] = uVar33;

          puVar39 = puVar39 + 0x20;

          uVar43 = uVar43 - 1;

        } while (uVar43 != 0);

      }

      for (; uVar42 != 0; uVar42 = uVar42 - 1) {

        uVar1 = *puVar38;

        puVar38 = puVar38 + 1;

        *puVar39 = uVar1;

        uVar1 = *puVar44;

        puVar44 = puVar44 + 1;

        puVar39[1] = uVar1;

        puVar39 = puVar39 + 2;

      }

      puVar39 = puVar39 + (int)(((param_6 + 1) / 2 - uVar34) * 2);

      puVar38 = puVar38 + (int)(iVar36 - uVar34);

      puVar44 = puVar44 + (int)(iVar36 - uVar34);

    } while (uVar40 != 0);

  }

  if (puVar37 != (undefined1 *)0x0) {

    FUN_1401841e0(puVar37);

  }

  return 1;

}




