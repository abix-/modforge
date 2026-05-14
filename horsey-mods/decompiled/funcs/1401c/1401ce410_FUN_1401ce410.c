// Address: 0x1401ce410
// Ghidra name: FUN_1401ce410
// ============ 0x1401ce410 FUN_1401ce410 (size=1816) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401ce410(int param_1,ushort *param_2,longlong param_3,longlong param_4,int *param_5)



{

  ushort *puVar1;

  uint *puVar2;

  byte bVar3;

  ushort uVar4;

  undefined2 uVar5;

  int iVar6;

  int iVar7;

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

  uint uVar19;

  uint uVar20;

  uint uVar21;

  uint uVar22;

  int iVar23;

  uint uVar24;

  uint *puVar25;

  uint uVar26;

  uint uVar27;

  int iVar28;

  longlong lVar29;

  ushort *puVar30;

  uint uVar31;

  longlong lVar32;

  uint uVar33;

  uint uVar34;

  uint uVar35;

  uint uVar36;

  undefined1 auVar37 [16];

  undefined1 auVar38 [16];

  uint uVar39;

  uint uVar40;

  uint uVar41;

  uint uVar42;

  undefined1 auVar43 [16];

  undefined1 auVar44 [16];

  undefined1 auVar45 [16];

  undefined1 auVar46 [16];

  int local_64;

  

  uVar19 = _UNK_14034a95c;

  uVar18 = _UNK_14034a958;

  uVar17 = _UNK_14034a954;

  uVar16 = _DAT_14034a950;

  uVar15 = _UNK_14034a92c;

  uVar14 = _UNK_14034a928;

  uVar13 = _UNK_14034a924;

  uVar12 = _DAT_14034a920;

  uVar11 = _UNK_14033c2bc;

  uVar27 = _UNK_14033c2b8;

  uVar24 = _UNK_14033c2b4;

  uVar21 = _DAT_14033c2b0;

  lVar32 = *(longlong *)(param_3 + 0x38);

  if (*(char *)(lVar32 + 5) == '\x02') {

    if (((*(int *)(lVar32 + 0xc) == 0x7e0) || (*(int *)(lVar32 + 8) == 0x7e0)) ||

       (*(int *)(lVar32 + 0x10) == 0x7e0)) {

      iVar6 = *param_5;

      iVar7 = param_5[2];

      local_64 = param_5[3];

      param_4 = param_4 + (longlong)iVar6 * -2;

      do {

        iVar28 = 0;

        do {

          bVar3 = *(byte *)((longlong)param_2 + 1);

          iVar28 = iVar28 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar3 == 0) {

            if (iVar28 == 0) {

              return;

            }

          }

          else {

            uVar21 = (uint)bVar3;

            iVar23 = iVar28;

            if (0 < iVar6 - iVar28) {

              uVar21 = (uVar21 - iVar6) + iVar28;

              iVar23 = iVar6;

            }

            uVar24 = (iVar7 + iVar6) - iVar23;

            if ((int)uVar21 <= (int)uVar24) {

              uVar24 = uVar21;

            }

            if (0 < (int)uVar24) {

              FUN_1402f8e20((longlong)iVar23 * 2 + param_4,param_2 + (iVar23 - iVar28),

                            (ulonglong)uVar24 * 2);

            }

            param_2 = param_2 + bVar3;

            iVar28 = iVar28 + (uint)bVar3;

          }

        } while (iVar28 < param_1);

        param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)param_2 & 2));

        iVar28 = 0;

        do {

          uVar4 = param_2[1];

          uVar21 = (uint)uVar4;

          iVar28 = iVar28 + (uint)*param_2;

          param_2 = param_2 + 2;

          if (uVar4 != 0) {

            iVar23 = iVar28;

            uVar24 = uVar21;

            if (0 < iVar6 - iVar28) {

              iVar23 = iVar6;

              uVar24 = (uVar21 - iVar6) + iVar28;

            }

            uVar27 = (iVar7 + iVar6) - iVar23;

            if ((int)uVar24 <= (int)uVar27) {

              uVar27 = uVar24;

            }

            if (0 < (int)uVar27) {

              lVar29 = 0;

              lVar32 = (longlong)iVar23 * 2 + param_4;

              if (0 < (int)uVar27) {

                do {

                  uVar5 = *(undefined2 *)(lVar32 + lVar29 * 2);

                  uVar24 = CONCAT22(uVar5,uVar5) & 0x7e0f81f;

                  uVar24 = (((*(uint *)(param_2 + (longlong)(iVar23 - iVar28) * 2 + lVar29 * 2) &

                             0x7e0f81f) - uVar24) *

                            (*(uint *)(param_2 + (longlong)(iVar23 - iVar28) * 2 + lVar29 * 2) >> 5

                            & 0x1f) >> 5) + uVar24 & 0x7e0f81f;

                  *(ushort *)(lVar32 + lVar29 * 2) = (ushort)(uVar24 >> 0x10) | (ushort)uVar24;

                  lVar29 = lVar29 + 1;

                } while (lVar29 < (int)uVar27);

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)(uVar21 * 4));

            iVar28 = iVar28 + (uint)uVar4;

          }

        } while (iVar28 < param_1);

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        local_64 = local_64 + -1;

      } while (local_64 != 0);

    }

    else {

      iVar6 = *param_5;

      iVar7 = param_5[2];

      local_64 = param_5[3];

      param_4 = param_4 + (longlong)iVar6 * -2;

      do {

        iVar28 = 0;

        do {

          bVar3 = *(byte *)((longlong)param_2 + 1);

          iVar28 = iVar28 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar3 == 0) {

            if (iVar28 == 0) {

              return;

            }

          }

          else {

            uVar21 = (uint)bVar3;

            iVar23 = iVar28;

            if (0 < iVar6 - iVar28) {

              uVar21 = (uVar21 - iVar6) + iVar28;

              iVar23 = iVar6;

            }

            uVar24 = (iVar7 + iVar6) - iVar23;

            if ((int)uVar21 <= (int)uVar24) {

              uVar24 = uVar21;

            }

            if (0 < (int)uVar24) {

              FUN_1402f8e20((longlong)iVar23 * 2 + param_4,param_2 + (iVar23 - iVar28),

                            (ulonglong)uVar24 * 2);

            }

            param_2 = param_2 + bVar3;

            iVar28 = iVar28 + (uint)bVar3;

          }

        } while (iVar28 < param_1);

        param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)param_2 & 2));

        iVar28 = 0;

        do {

          uVar4 = param_2[1];

          uVar21 = (uint)uVar4;

          iVar28 = iVar28 + (uint)*param_2;

          param_2 = param_2 + 2;

          if (uVar4 != 0) {

            iVar23 = iVar28;

            uVar24 = uVar21;

            if (0 < iVar6 - iVar28) {

              iVar23 = iVar6;

              uVar24 = (uVar21 - iVar6) + iVar28;

            }

            uVar27 = (iVar7 + iVar6) - iVar23;

            if ((int)uVar24 <= (int)uVar27) {

              uVar27 = uVar24;

            }

            if (0 < (int)uVar27) {

              lVar29 = 0;

              lVar32 = (longlong)iVar23 * 2 + param_4;

              if (0 < (int)uVar27) {

                do {

                  uVar5 = *(undefined2 *)(lVar32 + lVar29 * 2);

                  uVar24 = CONCAT22(uVar5,uVar5) & 0x3e07c1f;

                  uVar24 = (((*(uint *)(param_2 + (longlong)(iVar23 - iVar28) * 2 + lVar29 * 2) &

                             0x3e07c1f) - uVar24) *

                            (*(uint *)(param_2 + (longlong)(iVar23 - iVar28) * 2 + lVar29 * 2) >> 5

                            & 0x1f) >> 5) + uVar24 & 0x3e07c1f;

                  *(ushort *)(lVar32 + lVar29 * 2) = (ushort)(uVar24 >> 0x10) | (ushort)uVar24;

                  lVar29 = lVar29 + 1;

                } while (lVar29 < (int)uVar27);

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)(uVar21 * 4));

            iVar28 = iVar28 + (uint)uVar4;

          }

        } while (iVar28 < param_1);

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        local_64 = local_64 + -1;

      } while (local_64 != 0);

    }

  }

  else if (*(char *)(lVar32 + 5) == '\x04') {

    iVar6 = *param_5;

    iVar7 = param_5[2];

    local_64 = param_5[3];

    param_4 = param_4 + (longlong)iVar6 * -4;

    do {

      iVar28 = 0;

      do {

        uVar4 = param_2[1];

        iVar28 = iVar28 + (uint)*param_2;

        param_2 = param_2 + 2;

        if (uVar4 == 0) {

          if (iVar28 == 0) {

            return;

          }

        }

        else {

          uVar20 = (uint)uVar4;

          iVar23 = iVar28;

          if (0 < iVar6 - iVar28) {

            uVar20 = (uVar20 - iVar6) + iVar28;

            iVar23 = iVar6;

          }

          uVar22 = (iVar7 + iVar6) - iVar23;

          if ((int)uVar20 <= (int)uVar22) {

            uVar22 = uVar20;

          }

          if (0 < (int)uVar22) {

            FUN_1402f8e20((longlong)iVar23 * 4 + param_4,param_2 + (longlong)(iVar23 - iVar28) * 2,

                          (ulonglong)uVar22 << 2);

          }

          param_2 = param_2 + (ulonglong)uVar4 * 2;

          iVar28 = iVar28 + (uint)uVar4;

        }

      } while (iVar28 < param_1);

      iVar28 = 0;

      do {

        uVar4 = param_2[1];

        uVar20 = (uint)uVar4;

        iVar28 = iVar28 + (uint)*param_2;

        param_2 = param_2 + 2;

        if (uVar4 != 0) {

          iVar23 = iVar28;

          uVar22 = uVar20;

          if (0 < iVar6 - iVar28) {

            iVar23 = iVar6;

            uVar22 = (uVar20 - iVar6) + iVar28;

          }

          uVar26 = (iVar7 + iVar6) - iVar23;

          if ((int)uVar22 <= (int)uVar26) {

            uVar26 = uVar22;

          }

          if (0 < (int)uVar26) {

            lVar32 = 0;

            puVar30 = (ushort *)((longlong)iVar23 * 4 + param_4);

            puVar1 = param_2 + (longlong)(iVar23 - iVar28) * 2;

            if (((7 < uVar26) && (1 < DAT_1403e8ad0)) &&

               ((puVar1 + (longlong)(int)(uVar26 - 1) * 2 < puVar30 ||

                (puVar30 + (longlong)(int)(uVar26 - 1) * 2 < puVar1)))) {

              uVar22 = uVar26 & 0x80000007;

              if ((int)uVar22 < 0) {

                uVar22 = (uVar22 - 1 | 0xfffffff8) + 1;

              }

              puVar25 = (uint *)(puVar30 + 8);

              do {

                lVar32 = lVar32 + 8;

                puVar2 = (uint *)((longlong)puVar25 + ((longlong)puVar1 - (longlong)puVar30) + -0x10

                                 );

                uVar31 = *puVar2;

                uVar8 = puVar2[1];

                uVar9 = puVar2[2];

                uVar10 = puVar2[3];

                uVar39 = puVar25[-4] & uVar12;

                uVar40 = puVar25[-3] & uVar13;

                uVar41 = puVar25[-2] & uVar14;

                uVar42 = puVar25[-1] & uVar15;

                auVar37._0_4_ = uVar31 >> 0x18;

                auVar37._4_4_ = uVar8 >> 0x18;

                auVar37._8_4_ = uVar9 >> 0x18;

                auVar37._12_4_ = uVar10 >> 0x18;

                auVar43._0_4_ = (uVar31 & uVar12) - uVar39;

                auVar43._4_4_ = (uVar8 & uVar13) - uVar40;

                auVar43._8_4_ = (uVar9 & uVar14) - uVar41;

                auVar43._12_4_ = (uVar10 & uVar15) - uVar42;

                uVar33 = puVar25[-4] & uVar21;

                uVar34 = puVar25[-3] & uVar24;

                uVar35 = puVar25[-2] & uVar27;

                uVar36 = puVar25[-1] & uVar11;

                auVar46._0_4_ = (uVar31 & uVar21) - uVar33;

                auVar46._4_4_ = (uVar8 & uVar24) - uVar34;

                auVar46._8_4_ = (uVar9 & uVar27) - uVar35;

                auVar46._12_4_ = (uVar10 & uVar11) - uVar36;

                auVar44 = pmulld(auVar43,auVar37);

                auVar37 = pmulld(auVar46,auVar37);

                uVar33 = (auVar37._0_4_ >> 8) + uVar33;

                uVar34 = (auVar37._4_4_ >> 8) + uVar34;

                uVar35 = (auVar37._8_4_ >> 8) + uVar35;

                uVar36 = (auVar37._12_4_ >> 8) + uVar36;

                puVar25[-4] = ((auVar44._0_4_ >> 8) + uVar39 ^ uVar33) & uVar12 ^ uVar33 | uVar16;

                puVar25[-3] = ((auVar44._4_4_ >> 8) + uVar40 ^ uVar34) & uVar13 ^ uVar34 | uVar17;

                puVar25[-2] = ((auVar44._8_4_ >> 8) + uVar41 ^ uVar35) & uVar14 ^ uVar35 | uVar18;

                puVar25[-1] = ((auVar44._12_4_ >> 8) + uVar42 ^ uVar36) & uVar15 ^ uVar36 | uVar19;

                puVar2 = (uint *)((longlong)puVar25 + ((longlong)puVar1 - (longlong)puVar30));

                uVar31 = *puVar2;

                uVar8 = puVar2[1];

                uVar9 = puVar2[2];

                uVar10 = puVar2[3];

                auVar44._0_4_ = uVar31 >> 0x18;

                auVar44._4_4_ = uVar8 >> 0x18;

                auVar44._8_4_ = uVar9 >> 0x18;

                auVar44._12_4_ = uVar10 >> 0x18;

                uVar33 = *puVar25 & uVar21;

                uVar34 = puVar25[1] & uVar24;

                uVar35 = puVar25[2] & uVar27;

                uVar36 = puVar25[3] & uVar11;

                uVar39 = *puVar25 & uVar12;

                uVar40 = puVar25[1] & uVar13;

                uVar41 = puVar25[2] & uVar14;

                uVar42 = puVar25[3] & uVar15;

                auVar45._0_4_ = (uVar31 & uVar12) - uVar39;

                auVar45._4_4_ = (uVar8 & uVar13) - uVar40;

                auVar45._8_4_ = (uVar9 & uVar14) - uVar41;

                auVar45._12_4_ = (uVar10 & uVar15) - uVar42;

                auVar38._0_4_ = (uVar31 & uVar21) - uVar33;

                auVar38._4_4_ = (uVar8 & uVar24) - uVar34;

                auVar38._8_4_ = (uVar9 & uVar27) - uVar35;

                auVar38._12_4_ = (uVar10 & uVar11) - uVar36;

                auVar46 = pmulld(auVar45,auVar44);

                auVar37 = pmulld(auVar38,auVar44);

                uVar33 = (auVar37._0_4_ >> 8) + uVar33;

                uVar34 = (auVar37._4_4_ >> 8) + uVar34;

                uVar35 = (auVar37._8_4_ >> 8) + uVar35;

                uVar36 = (auVar37._12_4_ >> 8) + uVar36;

                *puVar25 = ((auVar46._0_4_ >> 8) + uVar39 ^ uVar33) & uVar12 ^ uVar33 | uVar16;

                puVar25[1] = ((auVar46._4_4_ >> 8) + uVar40 ^ uVar34) & uVar13 ^ uVar34 | uVar17;

                puVar25[2] = ((auVar46._8_4_ >> 8) + uVar41 ^ uVar35) & uVar14 ^ uVar35 | uVar18;

                puVar25[3] = ((auVar46._12_4_ >> 8) + uVar42 ^ uVar36) & uVar15 ^ uVar36 | uVar19;

                puVar25 = puVar25 + 8;

              } while (lVar32 < (int)(uVar26 - uVar22));

            }

            if (lVar32 < (int)uVar26) {

              lVar29 = (int)uVar26 - lVar32;

              puVar25 = (uint *)(puVar30 + lVar32 * 2);

              do {

                uVar22 = *(uint *)((longlong)puVar25 + ((longlong)puVar1 - (longlong)puVar30));

                uVar31 = *puVar25 & 0xff00;

                uVar26 = *puVar25 & 0xff00ff;

                uVar26 = (((uVar22 & 0xff00ff) - uVar26) * (uVar22 >> 0x18) >> 8) + uVar26;

                *puVar25 = ((((uVar22 & 0xff00) - uVar31) * (uVar22 >> 0x18) >> 8) + uVar31 ^ uVar26

                           ) & 0xff00 ^ uVar26 | 0xff000000;

                lVar29 = lVar29 + -1;

                puVar25 = puVar25 + 1;

              } while (lVar29 != 0);

            }

          }

          param_2 = (ushort *)((longlong)param_2 + (ulonglong)(uVar20 * 4));

          iVar28 = iVar28 + (uint)uVar4;

        }

      } while (iVar28 < param_1);

      param_4 = param_4 + *(int *)(param_3 + 0x10);

      local_64 = local_64 + -1;

    } while (local_64 != 0);

  }

  return;

}




