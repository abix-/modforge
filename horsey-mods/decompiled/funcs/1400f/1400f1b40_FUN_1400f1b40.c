// Address: 0x1400f1b40
// Ghidra name: FUN_1400f1b40
// ============ 0x1400f1b40 FUN_1400f1b40 (size=3197) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1400f1b40(longlong param_1,undefined8 param_2,ulonglong *param_3)



{

  short *psVar1;

  short *psVar2;

  byte *pbVar3;

  byte *pbVar4;

  byte *pbVar5;

  byte bVar6;

  byte bVar7;

  short sVar8;

  short sVar9;

  undefined1 auVar10 [16];

  float fVar11;

  undefined8 uVar12;

  undefined8 uVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  byte bVar20;

  ushort uVar21;

  byte bVar22;

  longlong lVar23;

  byte *pbVar24;

  short *psVar25;

  byte *pbVar26;

  longlong lVar27;

  int iVar28;

  int iVar29;

  ulonglong uVar30;

  ulonglong uVar31;

  undefined1 *puVar32;

  ulonglong uVar33;

  undefined2 *puVar34;

  longlong lVar35;

  ulonglong uVar36;

  undefined2 uVar37;

  int iVar38;

  undefined2 uVar39;

  longlong lVar40;

  ulonglong uVar41;

  double dVar42;

  undefined1 auVar43 [16];

  float fVar44;

  float fVar45;

  float fVar46;

  float fVar47;

  float fVar48;

  float fVar49;

  float fVar50;

  float fVar51;

  longlong local_res8;

  int local_114;

  int local_110;

  int local_10c;

  byte *local_100;

  float local_f0;

  float fStack_e8;

  

  lVar27 = *(longlong *)(param_1 + 8);

  uVar19 = 0;

  local_114 = 0;

  iVar14 = FUN_1400f3c70();

  *param_3 = 0;

  uVar13 = _UNK_140310308;

  uVar12 = _DAT_140310300;

  fVar11 = DAT_1403102f0;

  if (iVar14 < 0) {

LAB_1400f2768:

    uVar19 = 0;

  }

  else {

    lVar35 = (longlong)iVar14;

    uVar21 = (ushort)*(byte *)(lVar35 + lVar27) * 0x100 + (ushort)*(byte *)(lVar35 + 1 + lVar27);

    local_res8 = CONCAT44(local_res8._4_4_,(uint)uVar21);

    if ((short)uVar21 < 1) {

      uVar18 = uVar19;

      if (uVar21 == 0xffff) {

        pbVar24 = (byte *)(lVar27 + 10 + lVar35);

        uVar31 = uVar19;

        do {

          lVar27 = 0;

          bVar22 = pbVar24[1];

          fVar48 = 0.0;

          bVar20 = pbVar24[3];

          fVar49 = 0.0;

          bVar6 = pbVar24[2];

          pbVar26 = pbVar24 + 4;

          local_res8 = 0;

          if ((bVar22 & 2) != 0) {

            if ((bVar22 & 1) == 0) {

              iVar14 = (int)(char)*pbVar26;

              iVar16 = (int)(char)pbVar24[5];

              pbVar26 = pbVar24 + 6;

            }

            else {

              iVar14 = (int)(short)((ushort)pbVar24[5] + (ushort)*pbVar26 * 0x100);

              iVar16 = (int)(short)((ushort)pbVar24[7] + (ushort)pbVar24[6] * 0x100);

              pbVar26 = pbVar24 + 8;

            }

            fVar49 = (float)iVar16;

            fVar48 = (float)iVar14;

          }

          pbVar24 = pbVar26;

          if ((bVar22 & 8) == 0) {

            if ((bVar22 & 0x40) == 0) {

              if ((char)bVar22 < '\0') {

                pbVar26 = pbVar24 + 4;

                pbVar3 = pbVar24 + 5;

                local_f0 = (float)(int)(short)((ushort)pbVar24[1] + (ushort)*pbVar24 * 0x100) *

                           fVar11;

                pbVar4 = pbVar24 + 6;

                pbVar5 = pbVar24 + 7;

                fVar47 = (float)(int)(short)((ushort)pbVar24[3] + (ushort)pbVar24[2] * 0x100) *

                         fVar11;

                pbVar24 = pbVar24 + 8;

                fStack_e8 = (float)(int)(short)((ushort)*pbVar3 + (ushort)*pbVar26 * 0x100) * fVar11

                ;

                fVar46 = (float)(int)(short)((ushort)*pbVar5 + (ushort)*pbVar4 * 0x100) * fVar11;

              }

              else {

                fVar46 = (float)((ulonglong)uVar13 >> 0x20);

                fStack_e8 = (float)uVar13;

                fVar47 = (float)((ulonglong)uVar12 >> 0x20);

                local_f0 = (float)uVar12;

              }

            }

            else {

              pbVar26 = pbVar24 + 1;

              fStack_e8 = 0.0;

              bVar7 = *pbVar24;

              fVar47 = 0.0;

              pbVar3 = pbVar24 + 2;

              pbVar4 = pbVar24 + 3;

              pbVar24 = pbVar24 + 4;

              local_f0 = (float)(int)(short)((ushort)*pbVar26 + (ushort)bVar7 * 0x100) * fVar11;

              fVar46 = (float)(int)(short)((ushort)*pbVar4 + (ushort)*pbVar3 * 0x100) * fVar11;

            }

          }

          else {

            pbVar26 = pbVar24 + 1;

            fStack_e8 = 0.0;

            bVar7 = *pbVar24;

            fVar47 = 0.0;

            pbVar24 = pbVar24 + 2;

            local_f0 = (float)(int)(short)((ushort)*pbVar26 + (ushort)bVar7 * 0x100) * fVar11;

            fVar46 = local_f0;

          }

          dVar42 = (double)(fVar47 * fVar47 + local_f0 * local_f0);

          if (dVar42 < 0.0) {

            dVar42 = (double)FUN_1402da600();

          }

          else {

            auVar43._8_8_ = 0;

            auVar43._0_8_ = dVar42;

            auVar43 = sqrtpd(ZEXT816(0),auVar43);

            dVar42 = auVar43._0_8_;

          }

          fVar51 = (float)dVar42;

          dVar42 = (double)(fVar46 * fVar46 + fStack_e8 * fStack_e8);

          if (dVar42 < 0.0) {

            dVar42 = (double)FUN_1402da600();

          }

          else {

            auVar10._8_8_ = 0;

            auVar10._0_8_ = dVar42;

            auVar43 = sqrtpd(ZEXT816(0),auVar10);

            dVar42 = auVar43._0_8_;

          }

          fVar50 = (float)dVar42;

          iVar14 = FUN_1400f1b40(param_1,(uint)bVar6 * 0x100 + (uint)bVar20,&local_res8);

          lVar35 = (longlong)iVar14;

          uVar18 = uVar31;

          if (0 < iVar14) {

            if (lVar35 < 4) {

              if (0 < iVar14) goto LAB_1400f25e4;

            }

            else {

              lVar23 = (lVar35 - 4U >> 2) + 1;

              lVar40 = lVar23 * 4;

              do {

                fVar45 = (float)(int)*(short *)(local_res8 + 2 + lVar27);

                sVar8 = *(short *)(local_res8 + lVar27);

                *(short *)(local_res8 + lVar27) =

                     (short)(int)((local_f0 * (float)(int)sVar8 + fStack_e8 * fVar45 + fVar48) *

                                 fVar51);

                *(short *)(local_res8 + 2 + lVar27) =

                     (short)(int)((fVar47 * (float)(int)sVar8 + fVar46 * fVar45 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(local_res8 + 6 + lVar27);

                fVar44 = (float)(int)*(short *)(local_res8 + 4 + lVar27);

                *(short *)(local_res8 + 4 + lVar27) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(local_res8 + 6 + lVar27) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(local_res8 + 0xc + lVar27);

                fVar44 = (float)(int)*(short *)(local_res8 + 10 + lVar27);

                *(short *)(local_res8 + 10 + lVar27) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(local_res8 + 0xc + lVar27) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(local_res8 + 0x10 + lVar27);

                fVar44 = (float)(int)*(short *)(local_res8 + 0xe + lVar27);

                *(short *)(local_res8 + 0xe + lVar27) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(local_res8 + 0x10 + lVar27) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(lVar27 + 0x16 + local_res8);

                fVar44 = (float)(int)*(short *)(lVar27 + 0x14 + local_res8);

                *(short *)(lVar27 + 0x14 + local_res8) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(lVar27 + 0x16 + local_res8) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(lVar27 + 0x1a + local_res8);

                fVar44 = (float)(int)*(short *)(lVar27 + 0x18 + local_res8);

                *(short *)(lVar27 + 0x18 + local_res8) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(lVar27 + 0x1a + local_res8) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(lVar27 + 0x20 + local_res8);

                fVar44 = (float)(int)*(short *)(lVar27 + 0x1e + local_res8);

                *(short *)(lVar27 + 0x1e + local_res8) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(lVar27 + 0x20 + local_res8) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                fVar45 = (float)(int)*(short *)(lVar27 + 0x24 + local_res8);

                fVar44 = (float)(int)*(short *)(lVar27 + 0x22 + local_res8);

                *(short *)(lVar27 + 0x22 + local_res8) =

                     (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                *(short *)(lVar27 + 0x24 + local_res8) =

                     (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                lVar27 = lVar27 + 0x28;

                lVar23 = lVar23 + -1;

              } while (lVar23 != 0);

              lVar27 = lVar40;

              if (lVar40 < lVar35) {

LAB_1400f25e4:

                lVar40 = lVar27 * 10;

                lVar27 = lVar35 - lVar27;

                do {

                  fVar45 = (float)(int)*(short *)(lVar40 + 2 + local_res8);

                  sVar8 = *(short *)(lVar40 + local_res8);

                  *(short *)(lVar40 + local_res8) =

                       (short)(int)(((float)(int)sVar8 * local_f0 + fVar45 * fStack_e8 + fVar48) *

                                   fVar51);

                  *(short *)(lVar40 + 2 + local_res8) =

                       (short)(int)(((float)(int)sVar8 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50

                                   );

                  fVar45 = (float)(int)*(short *)(lVar40 + 6 + local_res8);

                  fVar44 = (float)(int)*(short *)(lVar40 + 4 + local_res8);

                  *(short *)(lVar40 + 4 + local_res8) =

                       (short)(int)((fVar44 * local_f0 + fVar45 * fStack_e8 + fVar48) * fVar51);

                  *(short *)(lVar40 + 6 + local_res8) =

                       (short)(int)((fVar44 * fVar47 + fVar45 * fVar46 + fVar49) * fVar50);

                  lVar40 = lVar40 + 10;

                  lVar27 = lVar27 + -1;

                } while (lVar27 != 0);

              }

            }

            iVar16 = (int)uVar19;

            uVar18 = _malloc_base((longlong)(iVar14 + iVar16) * 10);

            if (uVar18 == 0) {

              if (uVar31 != 0) {

                thunk_FUN_1402e9a80(uVar31);

              }

              if (local_res8 != 0) {

                thunk_FUN_1402e9a80();

              }

              goto LAB_1400f2768;

            }

            if (0 < iVar16) {

              FUN_1402f8e20(uVar18,uVar31,(longlong)iVar16 * 10);

            }

            FUN_1402f8e20(uVar18 + (longlong)iVar16 * 10,local_res8,lVar35 * 10);

            if (uVar31 != 0) {

              thunk_FUN_1402e9a80(uVar31);

            }

            thunk_FUN_1402e9a80(local_res8);

            uVar19 = (ulonglong)(uint)(iVar14 + iVar16);

          }

          uVar31 = uVar18;

        } while ((bVar22 & 0x20) != 0);

      }

    }

    else {

      local_100 = (byte *)(lVar27 + 10 + lVar35);

      lVar40 = (longlong)((short)uVar21 * 2);

      iVar14 = (uint)local_100[lVar40 + -1] + (uint)local_100[lVar40 + -2] * 0x100;

      pbVar24 = (byte *)((ulonglong)*(byte *)(lVar40 + lVar35 + 10 + lVar27) * 0x100 +

                         lVar40 + (ulonglong)*(byte *)(lVar40 + lVar35 + 0xb + lVar27) + lVar35 +

                        lVar27 + 0xc);

      uVar18 = _malloc_base((longlong)((short)uVar21 * 2 + 1 + iVar14) * 10);

      if (uVar18 == 0) goto LAB_1400f2768;

      uVar17 = iVar14 + 1;

      local_10c = 0;

      uVar36 = (ulonglong)uVar17;

      bVar22 = 0;

      uVar31 = uVar19;

      if (uVar17 == 0) {

        iVar14 = 0;

        iVar16 = 0;

        local_110 = local_114;

        iVar15 = local_114;

        iVar28 = local_114;

        iVar29 = local_114;

      }

      else {

        puVar32 = (undefined1 *)(uVar18 + 8 + lVar40 * 10);

        uVar30 = uVar19;

        uVar33 = uVar36;

        do {

          if (bVar22 == 0) {

            uVar30 = (ulonglong)*pbVar24;

            bVar20 = *pbVar24 & 8;

            if (bVar20 != 0) {

              bVar22 = pbVar24[1];

            }

            pbVar24 = pbVar24 + (ulonglong)(bVar20 != 0) + 1;

          }

          else {

            bVar22 = bVar22 - 1;

          }

          *puVar32 = (char)uVar30;

          puVar32 = puVar32 + 10;

          uVar33 = uVar33 - 1;

        } while (uVar33 != 0);

        puVar34 = (undefined2 *)(lVar40 * 10 + uVar18);

        uVar30 = uVar19;

        uVar33 = uVar36;

        do {

          if ((*(byte *)(puVar34 + 4) & 2) == 0) {

            if ((*(byte *)(puVar34 + 4) & 0x10) == 0) {

              uVar30 = (ulonglong)

                       (uint)((int)uVar30 +

                             (int)(short)((ushort)pbVar24[1] + (ushort)*pbVar24 * 0x100));

              pbVar24 = pbVar24 + 2;

            }

          }

          else {

            bVar22 = *pbVar24;

            pbVar24 = pbVar24 + 1;

            uVar17 = (uint)bVar22;

            if ((*(byte *)(puVar34 + 4) & 0x10) == 0) {

              uVar17 = -(uint)bVar22;

            }

            uVar30 = (ulonglong)((int)uVar30 + uVar17);

          }

          *puVar34 = (short)uVar30;

          puVar34 = puVar34 + 5;

          uVar33 = uVar33 - 1;

        } while (uVar33 != 0);

        puVar34 = (undefined2 *)(uVar18 + (lVar40 * 5 + 1) * 2);

        uVar30 = uVar19;

        uVar33 = uVar36;

        do {

          if ((*(byte *)(puVar34 + 3) & 4) == 0) {

            if ((*(byte *)(puVar34 + 3) & 0x20) == 0) {

              uVar30 = (ulonglong)

                       (uint)((int)uVar30 +

                             (int)(short)((ushort)pbVar24[1] + (ushort)*pbVar24 * 0x100));

              pbVar24 = pbVar24 + 2;

            }

          }

          else {

            bVar22 = *pbVar24;

            pbVar24 = pbVar24 + 1;

            uVar17 = (uint)bVar22;

            if ((*(byte *)(puVar34 + 3) & 0x20) == 0) {

              uVar17 = -(uint)bVar22;

            }

            uVar30 = (ulonglong)((int)uVar30 + uVar17);

          }

          *puVar34 = (short)uVar30;

          puVar34 = puVar34 + 5;

          uVar33 = uVar33 - 1;

        } while (uVar33 != 0);

        local_114 = 0;

        iVar14 = 0;

        local_110 = 0;

        iVar16 = 0;

        iVar38 = 0;

        lVar27 = 0;

        psVar25 = (short *)(uVar18 + (longlong)((short)local_res8 * 2) * 10);

        uVar30 = uVar19;

        uVar33 = uVar19;

        uVar41 = uVar19;

        do {

          iVar15 = (int)uVar19;

          bVar22 = *(byte *)(psVar25 + 4);

          sVar8 = *psVar25;

          sVar9 = psVar25[1];

          local_res8 = CONCAT71(local_res8._1_7_,bVar22);

          iVar28 = (int)uVar30;

          if (local_10c == iVar38) {

            if (lVar27 != 0) {

              iVar15 = FUN_1400f3d40(uVar18,uVar19,uVar30,uVar31,iVar16,iVar14,local_110,local_114,

                                     (int)uVar33,(int)uVar41);

              bVar22 = (byte)local_res8;

            }

            iVar16 = (int)sVar8;

            iVar14 = (int)sVar9;

            uVar31 = (ulonglong)(~(uint)bVar22 & 1);

            if ((~(uint)bVar22 & 1) != 0) {

              psVar1 = psVar25 + 5;

              psVar2 = psVar25 + 6;

              local_110 = iVar16;

              local_114 = iVar14;

              if ((*(byte *)(psVar25 + 9) & 1) == 0) {

                iVar14 = *psVar2 + iVar14 >> 1;

                iVar16 = *psVar1 + iVar16 >> 1;

              }

              else {

                iVar38 = iVar38 + 1;

                lVar27 = lVar27 + 1;

                psVar25 = psVar25 + 5;

                iVar14 = (int)*psVar2;

                iVar16 = (int)*psVar1;

              }

            }

            lVar35 = (longlong)iVar15;

            uVar19 = (ulonglong)(iVar15 + 1);

            *(undefined4 *)(uVar18 + 4 + lVar35 * 10) = 0;

            uVar30 = 0;

            *(undefined1 *)(uVar18 + 8 + lVar35 * 10) = 1;

            *(short *)(uVar18 + lVar35 * 10) = (short)iVar16;

            *(short *)(uVar18 + 2 + lVar35 * 10) = (short)iVar14;

            local_10c = (uint)*local_100 * 0x100 + local_100[1] + 1;

            local_100 = local_100 + 2;

          }

          else {

            uVar39 = (undefined2)uVar41;

            uVar37 = (undefined2)uVar33;

            if ((bVar22 & 1) == 0) {

              if (iVar28 != 0) {

                lVar35 = (longlong)iVar15;

                *(undefined1 *)(uVar18 + 8 + lVar35 * 10) = 3;

                *(short *)(uVar18 + lVar35 * 10) = (short)((int)uVar33 + (int)sVar8 >> 1);

                *(short *)(uVar18 + 2 + lVar35 * 10) = (short)((int)uVar41 + (int)sVar9 >> 1);

                uVar19 = (ulonglong)(iVar15 + 1);

                *(undefined2 *)(uVar18 + 4 + lVar35 * 10) = uVar37;

                *(undefined2 *)(uVar18 + 6 + lVar35 * 10) = uVar39;

              }

              uVar33 = (ulonglong)(uint)(int)sVar8;

              uVar41 = (ulonglong)(uint)(int)sVar9;

              uVar30 = 1;

            }

            else {

              lVar35 = (longlong)iVar15;

              if (iVar28 == 0) {

                uVar39 = 0;

                uVar37 = 0;

              }

              *(char *)(uVar18 + 8 + lVar35 * 10) = (iVar28 != 0) + '\x02';

              *(short *)(uVar18 + lVar35 * 10) = sVar8;

              *(short *)(uVar18 + 2 + lVar35 * 10) = sVar9;

              *(undefined2 *)(uVar18 + 4 + lVar35 * 10) = uVar37;

              *(undefined2 *)(uVar18 + 6 + lVar35 * 10) = uVar39;

              uVar30 = 0;

              uVar19 = (ulonglong)(iVar15 + 1);

            }

          }

          iVar29 = (int)uVar30;

          iVar28 = (int)uVar33;

          iVar15 = (int)uVar41;

          iVar38 = iVar38 + 1;

          lVar27 = lVar27 + 1;

          psVar25 = psVar25 + 5;

        } while (lVar27 < (longlong)uVar36);

      }

      uVar17 = FUN_1400f3d40(uVar18,uVar19,iVar29,uVar31,iVar16,iVar14,local_110,local_114,iVar28,

                             iVar15);

      uVar19 = (ulonglong)uVar17;

    }

    *param_3 = uVar18;

  }

  return uVar19;

}




