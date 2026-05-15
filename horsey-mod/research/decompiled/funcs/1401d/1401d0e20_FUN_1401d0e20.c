// Address: 0x1401d0e20
// Ghidra name: FUN_1401d0e20
// ============ 0x1401d0e20 FUN_1401d0e20 (size=1568) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_1401d0e20(longlong param_1,int *param_2,byte *param_3,int *param_4)



{

  byte bVar1;

  ushort uVar2;

  int iVar3;

  longlong lVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  char cVar19;

  uint uVar20;

  int iVar21;

  uint uVar22;

  uint uVar23;

  uint *puVar24;

  int iVar25;

  ulonglong uVar26;

  uint uVar27;

  uint uVar28;

  int iVar29;

  ushort *puVar30;

  uint *puVar31;

  longlong lVar32;

  undefined1 auVar33 [16];

  uint uVar34;

  uint uVar35;

  uint uVar36;

  uint uVar37;

  uint uVar38;

  uint uVar39;

  uint uVar40;

  uint uVar41;

  uint uVar42;

  uint uVar43;

  uint uVar44;

  uint uVar45;

  undefined1 auVar46 [16];

  undefined1 auVar47 [16];

  undefined1 auVar48 [16];

  undefined1 auVar49 [16];

  undefined1 auVar50 [16];

  int local_res8;

  

  iVar3 = *(int *)(param_1 + 8);

  lVar4 = *(longlong *)(param_3 + 0x38);

  if (((*param_3 & 2) != 0) && (cVar19 = FUN_140146f20(param_3), cVar19 == '\0')) {

    return 0;

  }

  iVar25 = DAT_1403e8ad0;

  uVar18 = _UNK_14034a95c;

  uVar17 = _UNK_14034a958;

  uVar16 = _UNK_14034a954;

  uVar15 = _DAT_14034a950;

  uVar14 = _UNK_14034a92c;

  uVar13 = _UNK_14034a928;

  uVar12 = _UNK_14034a924;

  uVar11 = _DAT_14034a920;

  uVar10 = _UNK_14033c2bc;

  uVar9 = _UNK_14033c2b8;

  uVar23 = _UNK_14033c2b4;

  uVar28 = _DAT_14033c2b0;

  iVar29 = param_2[1];

  puVar24 = (uint *)(*(longlong *)(param_1 + 0x88) + 4);

  lVar32 = (longlong)(*(int *)(param_3 + 0x10) * param_4[1]) +

           (longlong)(int)((uint)*(byte *)(lVar4 + 5) * *param_4) + *(longlong *)(param_3 + 0x18);

  if (iVar29 != 0) {

    if (*(byte *)(lVar4 + 5) == 2) {

      do {

        iVar21 = 0;

        do {

          bVar1 = *(byte *)((longlong)puVar24 + 1);

          iVar21 = iVar21 + (uint)(byte)*puVar24;

          puVar24 = (uint *)((longlong)puVar24 + 2);

          if (bVar1 == 0) {

            if (iVar21 == 0) goto LAB_1401d141d;

          }

          else {

            puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)bVar1 + (uint)bVar1));

            iVar21 = iVar21 + (uint)bVar1;

          }

        } while (iVar21 < iVar3);

        puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)puVar24 & 2));

        iVar21 = 0;

        do {

          puVar30 = (ushort *)((longlong)puVar24 + 2);

          uVar22 = *puVar24;

          puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)*puVar30 * 4 + 4));

          iVar21 = (uint)(ushort)uVar22 + iVar21 + (uint)*puVar30;

        } while (iVar21 < iVar3);

        iVar29 = iVar29 + -1;

      } while (iVar29 != 0);

    }

    else {

      iVar29 = iVar29 * 2;

      do {

        iVar21 = 0;

        do {

          uVar2 = *(ushort *)((longlong)puVar24 + 2);

          iVar21 = iVar21 + (uint)(ushort)*puVar24;

          puVar24 = puVar24 + 1;

          if (uVar2 == 0) {

            if (iVar21 == 0) goto LAB_1401d141d;

          }

          else {

            puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)uVar2 * 4));

            iVar21 = iVar21 + (uint)uVar2;

          }

        } while (iVar21 < iVar3);

        iVar29 = iVar29 + -1;

      } while (iVar29 != 0);

    }

  }

  if ((*param_2 == 0) && (param_2[2] == *(int *)(param_1 + 8))) {

    if (*(char *)(lVar4 + 5) == '\x02') {

      if (((*(int *)(lVar4 + 0xc) == 0x7e0) || (*(int *)(lVar4 + 8) == 0x7e0)) ||

         (*(int *)(lVar4 + 0x10) == 0x7e0)) {

        iVar29 = param_2[3];

        do {

          iVar25 = 0;

          do {

            bVar1 = *(byte *)((longlong)puVar24 + 1);

            iVar25 = iVar25 + (uint)(byte)*puVar24;

            puVar24 = (uint *)((longlong)puVar24 + 2);

            if (bVar1 == 0) {

              if (iVar25 == 0) goto LAB_1401d141d;

            }

            else {

              FUN_1402f8e20(lVar32 + (longlong)iVar25 * 2,puVar24,(ulonglong)bVar1 * 2);

              puVar24 = (uint *)((longlong)puVar24 + (ulonglong)bVar1 * 2);

              iVar25 = iVar25 + (uint)bVar1;

            }

          } while (iVar25 < iVar3);

          puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)puVar24 & 2));

          iVar25 = 0;

          do {

            uVar2 = *(ushort *)((longlong)puVar24 + 2);

            iVar25 = iVar25 + (uint)(ushort)*puVar24;

            puVar24 = puVar24 + 1;

            if (uVar2 != 0) {

              uVar26 = (ulonglong)(uint)uVar2;

              puVar30 = (ushort *)(lVar32 + (longlong)iVar25 * 2);

              do {

                uVar28 = *puVar24;

                uVar23 = CONCAT22(*puVar30,*puVar30) & 0x7e0f81f;

                puVar24 = puVar24 + 1;

                uVar28 = (((uVar28 & 0x7e0f81f) - uVar23) * (uVar28 >> 5 & 0x1f) >> 5) + uVar23 &

                         0x7e0f81f;

                *puVar30 = (ushort)(uVar28 >> 0x10) | (ushort)uVar28;

                uVar26 = uVar26 - 1;

                puVar30 = puVar30 + 1;

              } while (uVar26 != 0);

              iVar25 = iVar25 + (uint)uVar2;

            }

          } while (iVar25 < iVar3);

          lVar32 = lVar32 + *(int *)(param_3 + 0x10);

          iVar29 = iVar29 + -1;

        } while (iVar29 != 0);

      }

      else {

        iVar29 = param_2[3];

        do {

          iVar25 = 0;

          do {

            bVar1 = *(byte *)((longlong)puVar24 + 1);

            iVar25 = iVar25 + (uint)(byte)*puVar24;

            puVar24 = (uint *)((longlong)puVar24 + 2);

            if (bVar1 == 0) {

              if (iVar25 == 0) goto LAB_1401d141d;

            }

            else {

              FUN_1402f8e20(lVar32 + (longlong)iVar25 * 2,puVar24,(ulonglong)bVar1 * 2);

              puVar24 = (uint *)((longlong)puVar24 + (ulonglong)bVar1 * 2);

              iVar25 = iVar25 + (uint)bVar1;

            }

          } while (iVar25 < iVar3);

          puVar24 = (uint *)((longlong)puVar24 + (ulonglong)((uint)puVar24 & 2));

          iVar25 = 0;

          do {

            uVar2 = *(ushort *)((longlong)puVar24 + 2);

            iVar25 = iVar25 + (uint)(ushort)*puVar24;

            puVar24 = puVar24 + 1;

            if (uVar2 != 0) {

              uVar26 = (ulonglong)(uint)uVar2;

              puVar30 = (ushort *)(lVar32 + (longlong)iVar25 * 2);

              do {

                uVar28 = *puVar24;

                uVar23 = CONCAT22(*puVar30,*puVar30) & 0x3e07c1f;

                puVar24 = puVar24 + 1;

                uVar28 = (((uVar28 & 0x3e07c1f) - uVar23) * (uVar28 >> 5 & 0x1f) >> 5) + uVar23 &

                         0x3e07c1f;

                *puVar30 = (ushort)(uVar28 >> 0x10) | (ushort)uVar28;

                uVar26 = uVar26 - 1;

                puVar30 = puVar30 + 1;

              } while (uVar26 != 0);

              iVar25 = iVar25 + (uint)uVar2;

            }

          } while (iVar25 < iVar3);

          lVar32 = lVar32 + *(int *)(param_3 + 0x10);

          iVar29 = iVar29 + -1;

        } while (iVar29 != 0);

      }

    }

    else if (*(char *)(lVar4 + 5) == '\x04') {

      local_res8 = param_2[3];

      do {

        iVar29 = 0;

        do {

          uVar2 = *(ushort *)((longlong)puVar24 + 2);

          iVar29 = iVar29 + (uint)(ushort)*puVar24;

          puVar24 = puVar24 + 1;

          if (uVar2 == 0) {

            if (iVar29 == 0) goto LAB_1401d141d;

          }

          else {

            FUN_1402f8e20(lVar32 + (longlong)iVar29 * 4,puVar24,(ulonglong)uVar2 * 4);

            puVar24 = puVar24 + uVar2;

            iVar29 = iVar29 + (uint)uVar2;

          }

        } while (iVar29 < iVar3);

        iVar29 = 0;

        do {

          uVar2 = *(ushort *)((longlong)puVar24 + 2);

          iVar29 = iVar29 + (uint)(ushort)*puVar24;

          puVar24 = puVar24 + 1;

          if (uVar2 != 0) {

            uVar22 = 0;

            puVar31 = (uint *)(lVar32 + (longlong)iVar29 * 4);

            uVar20 = (uint)uVar2;

            uVar27 = (uint)uVar2;

            if (uVar20 != 0) {

              if (((7 < uVar20) && (1 < iVar25)) &&

                 ((puVar24 + (uVar2 - 1) < puVar31 || (puVar31 + (uVar2 - 1) < puVar24)))) {

                uVar22 = 0;

                do {

                  uVar22 = uVar22 + 8;

                  uVar35 = *puVar24;

                  uVar37 = puVar24[1];

                  uVar39 = puVar24[2];

                  uVar41 = puVar24[3];

                  uVar34 = uVar28 & *puVar31;

                  uVar36 = uVar23 & puVar31[1];

                  uVar38 = uVar9 & puVar31[2];

                  uVar40 = uVar10 & puVar31[3];

                  uVar42 = uVar11 & *puVar31;

                  uVar43 = uVar12 & puVar31[1];

                  uVar44 = uVar13 & puVar31[2];

                  uVar45 = uVar14 & puVar31[3];

                  auVar46._0_4_ = uVar35 >> 0x18;

                  auVar46._4_4_ = uVar37 >> 0x18;

                  auVar46._8_4_ = uVar39 >> 0x18;

                  auVar46._12_4_ = uVar41 >> 0x18;

                  auVar33._0_4_ = (uVar11 & uVar35) - uVar42;

                  auVar33._4_4_ = (uVar12 & uVar37) - uVar43;

                  auVar33._8_4_ = (uVar13 & uVar39) - uVar44;

                  auVar33._12_4_ = (uVar14 & uVar41) - uVar45;

                  auVar33 = pmulld(auVar33,auVar46);

                  uVar5 = puVar24[4];

                  uVar6 = puVar24[5];

                  uVar7 = puVar24[6];

                  uVar8 = puVar24[7];

                  puVar24 = puVar24 + 8;

                  auVar48._0_4_ = (uVar28 & uVar35) - uVar34;

                  auVar48._4_4_ = (uVar23 & uVar37) - uVar36;

                  auVar48._8_4_ = (uVar9 & uVar39) - uVar38;

                  auVar48._12_4_ = (uVar10 & uVar41) - uVar40;

                  auVar49 = pmulld(auVar48,auVar46);

                  uVar34 = (auVar49._0_4_ >> 8) + uVar34;

                  uVar36 = (auVar49._4_4_ >> 8) + uVar36;

                  uVar38 = (auVar49._8_4_ >> 8) + uVar38;

                  uVar40 = (auVar49._12_4_ >> 8) + uVar40;

                  auVar47._0_4_ = uVar5 >> 0x18;

                  auVar47._4_4_ = uVar6 >> 0x18;

                  auVar47._8_4_ = uVar7 >> 0x18;

                  auVar47._12_4_ = uVar8 >> 0x18;

                  *puVar31 = ((auVar33._0_4_ >> 8) + uVar42 ^ uVar34) & uVar11 ^ uVar34 | uVar15;

                  puVar31[1] = ((auVar33._4_4_ >> 8) + uVar43 ^ uVar36) & uVar12 ^ uVar36 | uVar16;

                  puVar31[2] = ((auVar33._8_4_ >> 8) + uVar44 ^ uVar38) & uVar13 ^ uVar38 | uVar17;

                  puVar31[3] = ((auVar33._12_4_ >> 8) + uVar45 ^ uVar40) & uVar14 ^ uVar40 | uVar18;

                  uVar35 = uVar28 & puVar31[4];

                  uVar37 = uVar23 & puVar31[5];

                  uVar39 = uVar9 & puVar31[6];

                  uVar41 = uVar10 & puVar31[7];

                  uVar34 = uVar11 & puVar31[4];

                  uVar36 = uVar12 & puVar31[5];

                  uVar38 = uVar13 & puVar31[6];

                  uVar40 = uVar14 & puVar31[7];

                  auVar50._0_4_ = (uVar28 & uVar5) - uVar35;

                  auVar50._4_4_ = (uVar23 & uVar6) - uVar37;

                  auVar50._8_4_ = (uVar9 & uVar7) - uVar39;

                  auVar50._12_4_ = (uVar10 & uVar8) - uVar41;

                  auVar49._0_4_ = (uVar11 & uVar5) - uVar34;

                  auVar49._4_4_ = (uVar12 & uVar6) - uVar36;

                  auVar49._8_4_ = (uVar13 & uVar7) - uVar38;

                  auVar49._12_4_ = (uVar14 & uVar8) - uVar40;

                  auVar33 = pmulld(auVar49,auVar47);

                  auVar49 = pmulld(auVar50,auVar47);

                  uVar35 = (auVar49._0_4_ >> 8) + uVar35;

                  uVar37 = (auVar49._4_4_ >> 8) + uVar37;

                  uVar39 = (auVar49._8_4_ >> 8) + uVar39;

                  uVar41 = (auVar49._12_4_ >> 8) + uVar41;

                  puVar31[4] = ((auVar33._0_4_ >> 8) + uVar34 ^ uVar35) & uVar11 ^ uVar35 | uVar15;

                  puVar31[5] = ((auVar33._4_4_ >> 8) + uVar36 ^ uVar37) & uVar12 ^ uVar37 | uVar16;

                  puVar31[6] = ((auVar33._8_4_ >> 8) + uVar38 ^ uVar39) & uVar13 ^ uVar39 | uVar17;

                  puVar31[7] = ((auVar33._12_4_ >> 8) + uVar40 ^ uVar41) & uVar14 ^ uVar41 | uVar18;

                  puVar31 = puVar31 + 8;

                } while (uVar22 < (uVar20 & 0xfffffff8));

                if (uVar27 <= uVar22) goto LAB_1401d11cc;

              }

              uVar26 = (ulonglong)(uVar27 - uVar22);

              do {

                uVar22 = *puVar24;

                puVar24 = puVar24 + 1;

                uVar20 = *puVar31 & 0xff00ff;

                uVar35 = *puVar31 & 0xff00;

                uVar20 = (((uVar22 & 0xff00ff) - uVar20) * (uVar22 >> 0x18) >> 8) + uVar20;

                *puVar31 = ((((uVar22 & 0xff00) - uVar35) * (uVar22 >> 0x18) >> 8) + uVar35 ^ uVar20

                           ) & 0xff00 ^ uVar20 | 0xff000000;

                uVar26 = uVar26 - 1;

                puVar31 = puVar31 + 1;

              } while (uVar26 != 0);

            }

LAB_1401d11cc:

            iVar29 = iVar29 + uVar27;

          }

        } while (iVar29 < iVar3);

        lVar32 = lVar32 + *(int *)(param_3 + 0x10);

        local_res8 = local_res8 + -1;

      } while (local_res8 != 0);

    }

  }

  else {

    FUN_1401ce410(iVar3,puVar24,param_3,lVar32,param_2);

  }

LAB_1401d141d:

  if ((*param_3 & 2) != 0) {

    FUN_1401489e0(param_3);

  }

  return 1;

}




