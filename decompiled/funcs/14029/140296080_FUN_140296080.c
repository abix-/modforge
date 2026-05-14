// Address: 0x140296080
// Ghidra name: FUN_140296080
// ============ 0x140296080 FUN_140296080 (size=5512) ============


void FUN_140296080(longlong param_1)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint *puVar5;

  uint uVar6;

  uint *puVar7;

  byte bVar8;

  uint uVar9;

  uint *puVar10;

  byte bVar11;

  uint uVar12;

  longlong lVar13;

  ulonglong uVar14;

  byte bVar15;

  int iVar16;

  uint uVar17;

  longlong lVar18;

  longlong lVar19;

  longlong lVar20;

  byte bVar21;

  uint uVar22;

  uint uVar23;

  longlong lVar24;

  int local_res8;

  uint local_68;

  uint local_64;

  int local_60;

  int local_5c;

  int local_58;

  int local_54;

  uint *local_50;

  

  uVar2 = *(uint *)(param_1 + 0x38);

  puVar5 = *(uint **)(param_1 + 0x58);

  local_50 = *(uint **)(param_1 + 0x48);

  iVar3 = *(int *)(param_1 + 0x1c);

  local_res8 = *(int *)(param_1 + 0x3c);

  bVar21 = *(byte *)((longlong)puVar5 + 5);

  puVar7 = *(uint **)(param_1 + 8);

  puVar10 = *(uint **)(param_1 + 0x30);

  bVar1 = *(byte *)((longlong)local_50 + 5);

  iVar4 = *(int *)(param_1 + 0x44);

  uVar12 = (uint)bVar21;

  if (puVar5[5] == 0) {

    uVar22 = 0;

  }

  else {

    uVar22 = (uint)*(byte *)(param_1 + 0x83);

  }

  uVar6 = *local_50;

  uVar23 = ~local_50[5];

  uVar17 = *puVar5;

  uVar9 = *(uint *)(param_1 + 0x7c) & uVar23;

  if ((((bVar1 == 4) && (uVar12 == 4)) && (local_50[2] == puVar5[2])) &&

     ((local_50[3] == puVar5[3] && (local_50[4] == puVar5[4])))) {

    if (puVar5[5] != 0) {

      uVar12 = (uint)*(byte *)(param_1 + 0x83) << (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

      while (local_res8 != 0) {

        iVar16 = (int)(((int)(uVar2 + 7) >> 0x1f & 7U) + uVar2 + 7) >> 3;

        switch(uVar2 & 7) {

        case 1:

          goto switchD_1402961a1_caseD_1;

        case 2:

          goto switchD_1402961a1_caseD_2;

        case 3:

          goto switchD_1402961a1_caseD_3;

        case 4:

          goto switchD_1402961a1_caseD_4;

        case 5:

          goto switchD_1402961a1_caseD_5;

        case 6:

          goto switchD_1402961a1_caseD_6;

        case 7:

          goto switchD_1402961a1_caseD_7;

        }

        do {

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_7:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_6:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_5:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_4:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_3:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_2:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402961a1_caseD_1:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 | uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

          iVar16 = iVar16 + -1;

        } while (0 < iVar16);

        puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

        local_res8 = local_res8 + -1;

      }

      return;

    }

    uVar12 = local_50[2] | local_50[3] | local_50[4];

    while (local_res8 != 0) {

      iVar16 = (int)(((int)(uVar2 + 7) >> 0x1f & 7U) + uVar2 + 7) >> 3;

      switch(uVar2 & 7) {

      case 0:

        do {

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_7:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_6:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_5:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_4:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_3:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_2:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

switchD_1402962c1_caseD_1:

          if ((*puVar7 & uVar23) != uVar9) {

            *puVar10 = *puVar7 & uVar12;

          }

          puVar10 = puVar10 + 1;

          puVar7 = puVar7 + 1;

          iVar16 = iVar16 + -1;

        } while (0 < iVar16);

        break;

      case 1:

        goto switchD_1402962c1_caseD_1;

      case 2:

        goto switchD_1402962c1_caseD_2;

      case 3:

        goto switchD_1402962c1_caseD_3;

      case 4:

        goto switchD_1402962c1_caseD_4;

      case 5:

        goto switchD_1402962c1_caseD_5;

      case 6:

        goto switchD_1402962c1_caseD_6;

      case 7:

        goto switchD_1402962c1_caseD_7;

      }

      puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

      puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

      local_res8 = local_res8 + -1;

    }

    return;

  }

  local_68 = uVar22;

  local_64 = uVar12;

  if ((((bVar1 == 4) && (bVar21 == 4)) &&

      ((uVar6 == 0 ||

       ((((uVar6 & 0xf0000000) != 0x10000000 || ((uVar6 & 0xf000000) != 0x6000000)) ||

        ((uVar6 & 0xf0000) != 0x70000)))))) &&

     (((uVar17 == 0 || ((uVar17 & 0xf0000000) != 0x10000000)) ||

      (((uVar17 & 0xf000000) != 0x6000000 || ((uVar17 & 0xf0000) != 0x70000)))))) {

    FUN_140298ae0(local_50,puVar5,&local_58,&local_5c,&local_60,&local_68,&local_64);

    lVar13 = (longlong)(int)local_64;

    lVar18 = (longlong)(int)local_68;

    lVar19 = (longlong)local_60;

    lVar20 = (longlong)local_5c;

    lVar24 = (longlong)local_58;

    while (local_res8 != 0) {

      iVar16 = (int)(((int)(uVar2 + 3) >> 0x1f & 3U) + uVar2 + 3) >> 2;

      uVar12 = uVar2 & 3;

      bVar21 = (byte)uVar22;

      if (uVar12 == 0) goto LAB_1402964b2;

      if (uVar12 == 1) goto LAB_14029654e;

      if (uVar12 == 2) goto LAB_14029651a;

      if (uVar12 == 3) {

        while( true ) {

          if ((*puVar7 & uVar23) != uVar9) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = puVar7 + 1;

          puVar10 = puVar10 + 1;

LAB_14029651a:

          if ((*puVar7 & uVar23) != uVar9) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = puVar7 + 1;

          puVar10 = puVar10 + 1;

LAB_14029654e:

          if ((*puVar7 & uVar23) != uVar9) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = puVar7 + 1;

          puVar10 = puVar10 + 1;

          iVar16 = iVar16 + -1;

          if (iVar16 < 1) break;

LAB_1402964b2:

          if ((*puVar7 & uVar23) != uVar9) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = puVar7 + 1;

          puVar10 = puVar10 + 1;

        }

        puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

        local_res8 = local_res8 + -1;

      }

      else {

        puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

        local_res8 = local_res8 + -1;

      }

    }

    return;

  }

  bVar8 = (byte)uVar9;

  bVar11 = (byte)(uVar9 >> 8);

  bVar15 = (byte)(uVar9 >> 0x10);

  if (uVar6 == 0x17101803) {

    if (uVar17 == 0x17101803) {

LAB_1402966c0:

      while (local_res8 != 0) {

        iVar16 = (int)(((int)(uVar2 + 3) >> 0x1f & 3U) + uVar2 + 3) >> 2;

        uVar12 = uVar2 & 3;

        if (uVar12 == 0) goto LAB_14029670a;

        if (uVar12 == 1) goto LAB_140296788;

        if (uVar12 == 2) goto LAB_14029675e;

        if (uVar12 == 3) {

          while( true ) {

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            bVar1 = *(byte *)((longlong)puVar7 + 2);

            if (((bVar8 != (byte)*puVar7) || (bVar11 != bVar21)) || (bVar15 != bVar1)) {

              *(byte *)puVar10 = (byte)*puVar7;

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = bVar1;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_14029675e:

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            bVar1 = *(byte *)((longlong)puVar7 + 2);

            if (((bVar8 != (byte)*puVar7) || (bVar11 != bVar21)) || (bVar15 != bVar1)) {

              *(byte *)puVar10 = (byte)*puVar7;

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = bVar1;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_140296788:

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            bVar1 = *(byte *)((longlong)puVar7 + 2);

            if (((bVar8 != (byte)*puVar7) || (bVar11 != bVar21)) || (bVar15 != bVar1)) {

              *(byte *)puVar10 = (byte)*puVar7;

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = bVar1;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

            iVar16 = iVar16 + -1;

            if (iVar16 < 1) break;

LAB_14029670a:

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            bVar1 = *(byte *)((longlong)puVar7 + 2);

            if (((bVar8 != (byte)*puVar7) || (bVar11 != bVar21)) || (bVar15 != bVar1)) {

              *(byte *)puVar10 = (byte)*puVar7;

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = bVar1;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

          }

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

        else {

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

      }

      return;

    }

    if (uVar17 == 0x17401803) {

LAB_1402967f0:

      while (local_res8 != 0) {

        iVar16 = (int)(((int)(uVar2 + 3) >> 0x1f & 3U) + uVar2 + 3) >> 2;

        uVar12 = uVar2 & 3;

        if (uVar12 == 0) goto LAB_14029683a;

        if (uVar12 == 1) goto LAB_1402968b8;

        if (uVar12 == 2) goto LAB_14029688e;

        if (uVar12 == 3) {

          while( true ) {

            uVar12 = *puVar7;

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            if (((bVar8 != (byte)uVar12) || (bVar11 != bVar21)) ||

               (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

              *(byte *)puVar10 = *(byte *)((longlong)puVar7 + 2);

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = (byte)uVar12;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_14029688e:

            uVar12 = *puVar7;

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            if (((bVar8 != (byte)uVar12) || (bVar11 != bVar21)) ||

               (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

              *(byte *)puVar10 = *(byte *)((longlong)puVar7 + 2);

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = (byte)uVar12;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_1402968b8:

            uVar12 = *puVar7;

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            if (((bVar8 != (byte)uVar12) || (bVar11 != bVar21)) ||

               (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

              *(byte *)puVar10 = *(byte *)((longlong)puVar7 + 2);

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = (byte)uVar12;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

            iVar16 = iVar16 + -1;

            if (iVar16 < 1) break;

LAB_14029683a:

            uVar12 = *puVar7;

            bVar21 = *(byte *)((longlong)puVar7 + 1);

            if (((bVar8 != (byte)uVar12) || (bVar11 != bVar21)) ||

               (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

              *(byte *)puVar10 = *(byte *)((longlong)puVar7 + 2);

              *(byte *)((longlong)puVar10 + 1) = bVar21;

              *(byte *)((longlong)puVar10 + 2) = (byte)uVar12;

            }

            puVar7 = (uint *)((longlong)puVar7 + 3);

            puVar10 = (uint *)((longlong)puVar10 + 3);

          }

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

        else {

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

      }

      return;

    }

  }

  else if (uVar6 == 0x17401803) {

    if (uVar17 == 0x17401803) goto LAB_1402966c0;

    if (uVar17 == 0x17101803) goto LAB_1402967f0;

  }

  if (bVar1 == 4) {

    if ((bVar21 == 3) &&

       (((uVar6 = *local_50, uVar6 == 0 || ((uVar6 & 0xf0000000) != 0x10000000)) ||

        (((uVar6 & 0xf000000) != 0x6000000 || ((uVar6 & 0xf0000) != 0x70000)))))) {

      FUN_140298ae0(local_50,puVar5,&local_60,&local_5c,&local_58,&local_54,0);

      lVar13 = (longlong)local_58;

      lVar18 = (longlong)local_5c;

      lVar19 = (longlong)local_60;

      while (local_res8 != 0) {

        iVar16 = (int)(((int)(uVar2 + 3) >> 0x1f & 3U) + uVar2 + 3) >> 2;

        uVar12 = uVar2 & 3;

        if (uVar12 == 0) goto LAB_140296901;

        if (uVar12 == 1) goto LAB_140296979;

        if (uVar12 == 2) goto LAB_140296951;

        if (uVar12 == 3) {

          while( true ) {

            if ((*puVar7 & uVar23) != uVar9) {

              *(byte *)puVar10 = *(byte *)(lVar19 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar18 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar13 + (longlong)puVar7);

            }

            puVar7 = puVar7 + 1;

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_140296951:

            if ((*puVar7 & uVar23) != uVar9) {

              *(byte *)puVar10 = *(byte *)(lVar19 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar18 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar13 + (longlong)puVar7);

            }

            puVar7 = puVar7 + 1;

            puVar10 = (uint *)((longlong)puVar10 + 3);

LAB_140296979:

            if ((*puVar7 & uVar23) != uVar9) {

              *(byte *)puVar10 = *(byte *)(lVar19 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar18 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar13 + (longlong)puVar7);

            }

            puVar7 = puVar7 + 1;

            puVar10 = (uint *)((longlong)puVar10 + 3);

            iVar16 = iVar16 + -1;

            if (iVar16 < 1) break;

LAB_140296901:

            if ((*puVar7 & uVar23) != uVar9) {

              *(byte *)puVar10 = *(byte *)(lVar19 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar18 + (longlong)puVar7);

              *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar13 + (longlong)puVar7);

            }

            puVar7 = puVar7 + 1;

            puVar10 = (uint *)((longlong)puVar10 + 3);

          }

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

        else {

          puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

          puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

          local_res8 = local_res8 + -1;

        }

      }

      return;

    }

  }

  else if (((bVar1 == 3) && (bVar21 == 4)) &&

          (((uVar6 = *puVar5, uVar6 == 0 ||

            (((uVar6 & 0xf0000000) != 0x10000000 || ((uVar6 & 0xf000000) != 0x6000000)))) ||

           ((uVar6 & 0xf0000) != 0x70000)))) {

    FUN_140298ae0(local_50,puVar5,&local_54,&local_64,&local_60,&local_5c,&local_58);

    lVar13 = (longlong)local_58;

    lVar18 = (longlong)local_5c;

    lVar19 = (longlong)local_60;

    lVar20 = (longlong)(int)local_64;

    lVar24 = (longlong)local_54;

    while (local_res8 != 0) {

      iVar16 = (int)(((int)(uVar2 + 3) >> 0x1f & 3U) + uVar2 + 3) >> 2;

      uVar12 = uVar2 & 3;

      bVar21 = (byte)local_68;

      if (uVar12 == 0) goto LAB_140296ab2;

      if (uVar12 == 1) goto LAB_140296b6f;

      if (uVar12 == 2) goto LAB_140296b30;

      if (uVar12 == 3) {

        while( true ) {

          if (((bVar8 != (byte)*puVar7) || (bVar11 != *(byte *)((longlong)puVar7 + 1))) ||

             (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = (uint *)((longlong)puVar7 + 3);

          puVar10 = puVar10 + 1;

LAB_140296b30:

          if (((bVar8 != (byte)*puVar7) || (bVar11 != *(byte *)((longlong)puVar7 + 1))) ||

             (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = (uint *)((longlong)puVar7 + 3);

          puVar10 = puVar10 + 1;

LAB_140296b6f:

          if (((bVar8 != (byte)*puVar7) || (bVar11 != *(byte *)((longlong)puVar7 + 1))) ||

             (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = (uint *)((longlong)puVar7 + 3);

          puVar10 = puVar10 + 1;

          iVar16 = iVar16 + -1;

          if (iVar16 < 1) break;

LAB_140296ab2:

          if (((bVar8 != (byte)*puVar7) || (bVar11 != *(byte *)((longlong)puVar7 + 1))) ||

             (bVar15 != *(byte *)((longlong)puVar7 + 2))) {

            *(byte *)puVar10 = *(byte *)(lVar24 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 1) = *(byte *)(lVar20 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 2) = *(byte *)(lVar19 + (longlong)puVar7);

            *(byte *)((longlong)puVar10 + 3) = *(byte *)(lVar18 + (longlong)puVar7);

            *(byte *)(lVar13 + (longlong)puVar10) = bVar21;

          }

          puVar7 = (uint *)((longlong)puVar7 + 3);

          puVar10 = puVar10 + 1;

        }

        puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

        local_res8 = local_res8 + -1;

      }

      else {

        puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

        local_res8 = local_res8 + -1;

      }

    }

    return;

  }

  while (local_res8 != 0) {

    local_64 = (int)(uVar2 + 3 + ((int)(uVar2 + 3) >> 0x1f & 3U)) >> 2;

    uVar6 = uVar2 & 3;

    uVar17 = (uint)bVar1;

    if (uVar6 == 0) goto LAB_140296c1f;

    if (uVar6 == 1) goto LAB_14029735f;

    if (uVar6 == 2) goto LAB_1402970f3;

    if (uVar6 == 3) {

      while( true ) {

        if (uVar17 == 1) {

          uVar14 = (ulonglong)(byte)*puVar7;

        }

        else if (uVar17 == 2) {

          uVar14 = (ulonglong)(ushort)*puVar7;

        }

        else if (uVar17 == 3) {

          uVar14 = (ulonglong)(uint3)*puVar7;

        }

        else if (uVar17 == 4) {

          uVar14 = (ulonglong)*puVar7;

        }

        else {

          uVar14 = 0;

        }

        if (((uint)uVar14 & uVar23) != uVar9) {

          bVar21 = (&PTR_DAT_1403e28a0)[(byte)local_50[6]]

                   [(local_50[2] & uVar14) >> ((byte)local_50[7] & 0x3f)];

          bVar8 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x19)]

                  [(local_50[3] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1d) & 0x3f)];

          bVar11 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x1a)]

                   [(local_50[4] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1e) & 0x3f)];

          if (uVar12 == 1) {

            *(byte *)puVar10 =

                 (char)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 2) {

            *(ushort *)puVar10 =

                 (short)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (ushort)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (ushort)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (ushort)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar10) = bVar21;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar10) =

                 bVar8;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar10) =

                 bVar11;

          }

          else if (uVar12 == 4) {

            *puVar10 = (uint)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                       (uint)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                       (uint)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                       (uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

        }

        puVar10 = (uint *)((longlong)puVar10 + (longlong)(int)uVar12);

        puVar7 = (uint *)((longlong)puVar7 + (longlong)(int)uVar17);

LAB_1402970f3:

        if (uVar17 == 1) {

          uVar14 = (ulonglong)(byte)*puVar7;

        }

        else if (uVar17 == 2) {

          uVar14 = (ulonglong)(ushort)*puVar7;

        }

        else if (uVar17 == 3) {

          uVar14 = (ulonglong)(uint3)*puVar7;

        }

        else if (uVar17 == 4) {

          uVar14 = (ulonglong)*puVar7;

        }

        else {

          uVar14 = 0;

        }

        if (((uint)uVar14 & uVar23) != uVar9) {

          bVar21 = (&PTR_DAT_1403e28a0)[(byte)local_50[6]]

                   [(local_50[2] & uVar14) >> ((byte)local_50[7] & 0x3f)];

          bVar8 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x19)]

                  [(local_50[3] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1d) & 0x3f)];

          bVar11 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x1a)]

                   [(local_50[4] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1e) & 0x3f)];

          if (uVar12 == 1) {

            *(byte *)puVar10 =

                 (char)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 2) {

            *(ushort *)puVar10 =

                 (short)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (ushort)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (ushort)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (ushort)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar10) = bVar21;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar10) =

                 bVar8;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar10) =

                 bVar11;

          }

          else if (uVar12 == 4) {

            *puVar10 = (uint)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                       (uint)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                       (uint)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                       (uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

        }

        puVar10 = (uint *)((longlong)puVar10 + (longlong)(int)uVar12);

        puVar7 = (uint *)((longlong)puVar7 + (longlong)(int)uVar17);

LAB_14029735f:

        if (uVar17 == 1) {

          uVar6 = (uint)(byte)*puVar7;

        }

        else if (uVar17 == 2) {

          uVar6 = (uint)(ushort)*puVar7;

        }

        else if (uVar17 == 3) {

          uVar6 = (uint)(uint3)*puVar7;

        }

        else if (uVar17 == 4) {

          uVar6 = *puVar7;

        }

        else {

          uVar6 = 0;

        }

        if ((uVar6 & uVar23) != uVar9) {

          bVar21 = (&PTR_DAT_1403e28a0)[(byte)local_50[6]]

                   [(local_50[2] & uVar6) >> ((byte)local_50[7] & 0x3f)];

          bVar8 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x19)]

                  [(local_50[3] & uVar6) >> (*(byte *)((longlong)local_50 + 0x1d) & 0x3f)];

          bVar11 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x1a)]

                   [(local_50[4] & uVar6) >> (*(byte *)((longlong)local_50 + 0x1e) & 0x3f)];

          if (uVar12 == 1) {

            *(byte *)puVar10 =

                 (char)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 2) {

            *(ushort *)puVar10 =

                 (short)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (ushort)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (ushort)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (ushort)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar10) = bVar21;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar10) =

                 bVar8;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar10) =

                 bVar11;

          }

          else if (uVar12 == 4) {

            *puVar10 = (uint)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                       (uint)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                       (uint)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                       (uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

        }

        local_64 = local_64 - 1;

        puVar7 = (uint *)((longlong)puVar7 + (ulonglong)bVar1);

        puVar10 = (uint *)((longlong)puVar10 + (longlong)(int)uVar12);

        if ((int)local_64 < 1) break;

LAB_140296c1f:

        if (uVar17 == 1) {

          uVar14 = (ulonglong)(byte)*puVar7;

        }

        else if (uVar17 == 2) {

          uVar14 = (ulonglong)(ushort)*puVar7;

        }

        else if (uVar17 == 3) {

          uVar14 = (ulonglong)(uint3)*puVar7;

        }

        else if (uVar17 == 4) {

          uVar14 = (ulonglong)*puVar7;

        }

        else {

          uVar14 = 0;

        }

        if (((uint)uVar14 & uVar23) != uVar9) {

          bVar21 = (&PTR_DAT_1403e28a0)[(byte)local_50[6]]

                   [(local_50[2] & uVar14) >> ((byte)local_50[7] & 0x3f)];

          bVar8 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x19)]

                  [(local_50[3] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1d) & 0x3f)];

          bVar11 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)local_50 + 0x1a)]

                   [(local_50[4] & uVar14) >> (*(byte *)((longlong)local_50 + 0x1e) & 0x3f)];

          if (uVar12 == 1) {

            *(byte *)puVar10 =

                 (char)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 2) {

            *(ushort *)puVar10 =

                 (short)(uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f) |

                 (ushort)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (ushort)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (ushort)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f);

          }

          else if (uVar12 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar10) = bVar21;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar10) =

                 bVar8;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar10) =

                 bVar11;

          }

          else if (uVar12 == 4) {

            *puVar10 = (uint)(bVar21 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                       (uint)(bVar8 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                       (uint)(bVar11 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                       (uVar22 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

        }

        puVar10 = (uint *)((longlong)puVar10 + (longlong)(int)uVar12);

        puVar7 = (uint *)((longlong)puVar7 + (longlong)(int)uVar17);

      }

    }

    puVar7 = (uint *)((longlong)puVar7 + (longlong)iVar3);

    puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar4);

    local_res8 = local_res8 + -1;

  }

  return;

}




