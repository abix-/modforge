// Address: 0x140086910
// Ghidra name: FUN_140086910
// ============ 0x140086910 FUN_140086910 (size=3007) ============


undefined8 *

FUN_140086910(longlong param_1,undefined8 *param_2,float param_3,undefined8 param_4,uint param_5,

             byte *param_6)



{

  longlong *plVar1;

  byte bVar2;

  undefined1 (*pauVar3) [16];

  ulonglong uVar4;

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined8 ***pppuVar8;

  byte bVar9;

  int iVar10;

  size_t sVar11;

  undefined8 ****ppppuVar12;

  ulonglong uVar13;

  longlong lVar14;

  undefined8 uVar15;

  ulonglong *puVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  uint uVar20;

  int iVar21;

  ulonglong uVar22;

  undefined8 *puVar23;

  uint uVar24;

  longlong lVar25;

  byte *pbVar26;

  longlong lVar27;

  ulonglong uVar28;

  longlong lVar29;

  int iVar30;

  byte *pbVar31;

  undefined4 uVar32;

  float fVar33;

  byte *local_c0;

  undefined1 local_b8;

  undefined7 uStack_b7;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 ***local_98;

  undefined8 uStack_90;

  ulonglong local_88;

  ulonglong local_80;

  ulonglong local_78;

  ulonglong uStack_70;

  ulonglong local_68;

  ulonglong uStack_60;

  

  *(undefined4 *)((longlong)param_2 + 0xc) = 0;

  plVar1 = param_2 + 3;

  *plVar1 = 0;

  param_2[4] = 0;

  param_2[5] = 0;

  *param_2 = 0;

  *(undefined4 *)(param_2 + 1) = 0;

  *(undefined4 *)((longlong)param_2 + 0x14) = 0x3f800000;

  *(uint *)(param_2 + 2) = param_5;

  fVar33 = 0.0;

  local_c0 = param_6;

  uVar20 = 0;

  uVar24 = 0;

  bVar9 = *param_6;

  pbVar26 = param_6;

  pbVar31 = param_6;

  if (bVar9 != 0) {

    do {

      if (uVar20 == 0) {

        param_5 = 0xff >> ((&DAT_14030ad90)[bVar9] & 0x1f) & (uint)bVar9;

      }

      else {

        param_5 = bVar9 & 0x3f | param_5 << 6;

      }

      bVar9 = (&DAT_14030ad90)[(uVar20 + 0x10) * 0x10 + (uint)(byte)(&DAT_14030ad90)[bVar9]];

      uVar20 = uVar24;

      if (bVar9 == 0) {

        if (param_5 == 10) {

          uVar32 = FUN_1400c5c10();

          *(undefined4 *)(param_2 + 1) = uVar32;

          fVar33 = 0.0;

          local_98 = (undefined8 ****)0x0;

          uStack_90 = 0;

          local_88 = 0;

          local_80 = 0;

          sVar11 = strlen((char *)param_6);

          FUN_140027e30(&local_98,param_6,sVar11);

          uVar22 = local_80;

          pppuVar8 = local_98;

          local_b8 = 0;

          uStack_b7 = 0;

          uStack_b0 = 0;

          local_a8 = 0;

          uStack_a0 = 0;

          uVar18 = (longlong)pbVar26 - (longlong)param_6;

          if (local_88 < (ulonglong)((longlong)pbVar26 - (longlong)param_6)) {

            uVar18 = local_88;

          }

          ppppuVar12 = &local_98;

          if (0xf < local_80) {

            ppppuVar12 = (undefined8 ****)local_98;

          }

          if (0x7fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

            FUN_140024130();

          }

          if (uVar18 < 0x10) {

            uStack_a0 = 0xf;

            local_a8 = uVar18;

            FUN_1402f8e20(&local_b8,ppppuVar12);

            (&local_b8)[uVar18] = 0;

          }

          else {

            uVar22 = uVar18 | 0xf;

            if (uVar22 < 0x8000000000000000) {

              if (uVar22 < 0x16) {

                uVar22 = 0x16;

              }

            }

            else {

              uVar22 = 0x7fffffffffffffff;

            }

            lVar14 = FUN_1400285e0(uVar22 + 1);

            local_b8 = (undefined1)lVar14;

            uStack_b7 = (undefined7)((ulonglong)lVar14 >> 8);

            local_a8 = uVar18;

            uStack_a0 = uVar22;

            FUN_1402f8e20(lVar14,ppppuVar12);

            *(undefined1 *)(lVar14 + uVar18) = 0;

            uVar22 = local_80;

          }

          pauVar3 = (undefined1 (*) [16])param_2[4];

          if (pauVar3 == (undefined1 (*) [16])param_2[5]) {

            FUN_140087c70();

            uVar18 = uStack_a0;

          }

          else {

            auVar5._1_7_ = uStack_b7;

            auVar5[0] = local_b8;

            auVar5._8_8_ = uStack_b0;

            *pauVar3 = auVar5;

            *(undefined4 *)pauVar3[1] = (undefined4)local_a8;

            *(undefined4 *)(pauVar3[1] + 4) = local_a8._4_4_;

            *(undefined4 *)(pauVar3[1] + 8) = (undefined4)uStack_a0;

            *(undefined4 *)(pauVar3[1] + 0xc) = uStack_a0._4_4_;

            local_b8 = 0;

            param_2[4] = param_2[4] + 0x20;

            uVar18 = 0xf;

          }

          if (0xf < uVar18) {

            if ((0xfff < uVar18 + 1) &&

               (0x1f < (CONCAT71(uStack_b7,local_b8) -

                       *(longlong *)(CONCAT71(uStack_b7,local_b8) + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          if (0xf < uVar22) {

            ppppuVar12 = (undefined8 ****)pppuVar8;

            if ((0xfff < uVar22 + 1) &&

               (ppppuVar12 = (undefined8 ****)pppuVar8[-1],

               0x1f < (ulonglong)((longlong)pppuVar8 + (-8 - (longlong)ppppuVar12))))

            goto LAB_1400874a8;

            FUN_1402c7088(ppppuVar12);

          }

          param_6 = pbVar26 + 1;

          pbVar31 = param_6;

          uVar20 = 0;

          local_c0 = param_6;

        }

        else {

          if (param_5 < 0x2165) {

            bVar2 = (&DAT_1403eaf30)[param_5];

            uVar20 = (uint)bVar2;

            if (bVar2 == 0) goto LAB_140086fad;

            if (bVar2 == 0x20) {

              uVar32 = FUN_1400c5c10();

              *(undefined4 *)(param_2 + 1) = uVar32;

              pbVar31 = pbVar26;

              local_c0 = pbVar26;

            }

            else if (bVar2 == 0xff) goto LAB_140086c1e;

          }

          else {

LAB_140086c1e:

            uVar20 = param_5 & 0x80000007;

            if ((int)uVar20 < 0) {

              uVar20 = (uVar20 - 1 | 0xfffffff8) + 1;

            }

            uVar20 = uVar20 + 0x12;

          }

          iVar21 = *(int *)((longlong)(int)uVar20 * 0x118 + 0x20 + param_1);

          if (0 < (int)uVar24) {

            iVar21 = iVar21 + *(char *)((longlong)(int)uVar24 * 0x118 + (longlong)(int)uVar20 + 0x28

                                       + param_1);

          }

          fVar33 = (float)iVar21 + fVar33;

          if (param_3 < fVar33) {

            fVar33 = 0.0;

            sVar11 = strlen((char *)param_6);

            local_98 = (undefined8 ****)0x0;

            uStack_90 = 0;

            if (param_6 == pbVar31) {

              local_88 = 0;

              local_80 = 0;

              FUN_140027e30(&local_98,param_6,sVar11);

              uVar22 = local_80;

              pppuVar8 = local_98;

              local_b8 = 0;

              uStack_b7 = 0;

              uStack_b0 = 0;

              local_a8 = 0;

              uStack_a0 = 0;

              uVar18 = (longlong)pbVar26 - (longlong)param_6;

              if (local_88 < (ulonglong)((longlong)pbVar26 - (longlong)param_6)) {

                uVar18 = local_88;

              }

              ppppuVar12 = &local_98;

              if (0xf < local_80) {

                ppppuVar12 = (undefined8 ****)local_98;

              }

              if (0x7fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

                FUN_140024130();

              }

              if (uVar18 < 0x10) {

                uStack_a0 = 0xf;

                local_a8 = uVar18;

                FUN_1402f8e20(&local_b8,ppppuVar12);

                (&local_b8)[uVar18] = 0;

              }

              else {

                uVar22 = uVar18 | 0xf;

                if (uVar22 < 0x8000000000000000) {

                  if (uVar22 < 0x16) {

                    uVar22 = 0x16;

                  }

                }

                else {

                  uVar22 = 0x7fffffffffffffff;

                }

                lVar14 = FUN_1400285e0(uVar22 + 1);

                local_b8 = (undefined1)lVar14;

                uStack_b7 = (undefined7)((ulonglong)lVar14 >> 8);

                local_a8 = uVar18;

                uStack_a0 = uVar22;

                FUN_1402f8e20(lVar14,ppppuVar12);

                *(undefined1 *)(uVar18 + lVar14) = 0;

                uVar22 = local_80;

              }

              pauVar3 = (undefined1 (*) [16])param_2[4];

              if (pauVar3 == (undefined1 (*) [16])param_2[5]) {

                FUN_140087c70();

                uVar18 = uStack_a0;

              }

              else {

                auVar6._1_7_ = uStack_b7;

                auVar6[0] = local_b8;

                auVar6._8_8_ = uStack_b0;

                *pauVar3 = auVar6;

                *(undefined4 *)pauVar3[1] = (undefined4)local_a8;

                *(undefined4 *)(pauVar3[1] + 4) = local_a8._4_4_;

                *(undefined4 *)(pauVar3[1] + 8) = (undefined4)uStack_a0;

                *(undefined4 *)(pauVar3[1] + 0xc) = uStack_a0._4_4_;

                local_b8 = 0;

                param_2[4] = param_2[4] + 0x20;

                uVar18 = 0xf;

              }

              if (0xf < uVar18) {

                if ((0xfff < uVar18 + 1) &&

                   (0x1f < (CONCAT71(uStack_b7,local_b8) -

                           *(longlong *)(CONCAT71(uStack_b7,local_b8) + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                FUN_1402c7088();

              }

              if (0xf < uVar22) {

                ppppuVar12 = (undefined8 ****)pppuVar8;

                if ((0xfff < uVar22 + 1) &&

                   (ppppuVar12 = (undefined8 ****)pppuVar8[-1],

                   0x1f < (ulonglong)((longlong)pppuVar8 + (-8 - (longlong)ppppuVar12))))

                goto LAB_1400874a8;

                FUN_1402c7088(ppppuVar12);

              }

            }

            else {

              local_88 = 0;

              local_80 = 0;

              FUN_140027e30(&local_98,param_6,sVar11);

              uVar22 = local_80;

              pppuVar8 = local_98;

              local_b8 = 0;

              uStack_b7 = 0;

              uStack_b0 = 0;

              local_a8 = 0;

              uStack_a0 = 0;

              uVar18 = (longlong)pbVar31 - (longlong)param_6;

              if (local_88 < (ulonglong)((longlong)pbVar31 - (longlong)param_6)) {

                uVar18 = local_88;

              }

              ppppuVar12 = &local_98;

              if (0xf < local_80) {

                ppppuVar12 = (undefined8 ****)local_98;

              }

              if (0x7fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

                FUN_140024130();

              }

              if (uVar18 < 0x10) {

                uStack_a0 = 0xf;

                local_a8 = uVar18;

                FUN_1402f8e20(&local_b8,ppppuVar12);

                (&local_b8)[uVar18] = 0;

                pbVar26 = pbVar31;

              }

              else {

                uVar22 = uVar18 | 0xf;

                if (uVar22 < 0x8000000000000000) {

                  if (uVar22 < 0x16) {

                    uVar22 = 0x16;

                  }

                }

                else {

                  uVar22 = 0x7fffffffffffffff;

                }

                lVar14 = FUN_1400285e0(uVar22 + 1);

                local_b8 = (undefined1)lVar14;

                uStack_b7 = (undefined7)((ulonglong)lVar14 >> 8);

                local_a8 = uVar18;

                uStack_a0 = uVar22;

                FUN_1402f8e20(lVar14,ppppuVar12);

                *(undefined1 *)(lVar14 + uVar18) = 0;

                uVar22 = local_80;

                pbVar26 = local_c0;

              }

              pauVar3 = (undefined1 (*) [16])param_2[4];

              if (pauVar3 == (undefined1 (*) [16])param_2[5]) {

                FUN_140087c70();

                uVar18 = uStack_a0;

              }

              else {

                auVar7._1_7_ = uStack_b7;

                auVar7[0] = local_b8;

                auVar7._8_8_ = uStack_b0;

                *pauVar3 = auVar7;

                *(undefined4 *)pauVar3[1] = (undefined4)local_a8;

                *(undefined4 *)(pauVar3[1] + 4) = local_a8._4_4_;

                *(undefined4 *)(pauVar3[1] + 8) = (undefined4)uStack_a0;

                *(undefined4 *)(pauVar3[1] + 0xc) = uStack_a0._4_4_;

                local_b8 = 0;

                param_2[4] = param_2[4] + 0x20;

                uVar18 = 0xf;

              }

              if (0xf < uVar18) {

                if ((0xfff < uVar18 + 1) &&

                   (0x1f < (CONCAT71(uStack_b7,local_b8) -

                           *(longlong *)(CONCAT71(uStack_b7,local_b8) + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                FUN_1402c7088();

              }

              if (0xf < uVar22) {

                ppppuVar12 = (undefined8 ****)pppuVar8;

                if ((0xfff < uVar22 + 1) &&

                   (ppppuVar12 = (undefined8 ****)pppuVar8[-1],

                   0x1f < (ulonglong)((longlong)pppuVar8 + (-8 - (longlong)ppppuVar12))))

                goto LAB_1400874a8;

                FUN_1402c7088(ppppuVar12);

              }

            }

            param_6 = pbVar26 + 1;

            pbVar31 = param_6;

            local_c0 = param_6;

          }

        }

      }

LAB_140086fad:

      uVar24 = uVar20;

      uVar20 = (uint)bVar9;

      pbVar26 = pbVar26 + 1;

      bVar9 = *pbVar26;

    } while (bVar9 != 0);

    if (param_6 < pbVar26) {

      local_98 = (undefined8 ****)0x0;

      uStack_90 = 0;

      local_88 = 0;

      local_80 = 0;

      sVar11 = strlen((char *)param_6);

      FUN_140027e30(&local_98,param_6,sVar11);

      uVar22 = local_80;

      pppuVar8 = local_98;

      local_b8 = 0;

      uStack_b7 = 0;

      uStack_b0 = 0;

      local_a8 = 0;

      uStack_a0 = 0;

      uVar18 = (longlong)pbVar26 - (longlong)param_6;

      if (local_88 < (ulonglong)((longlong)pbVar26 - (longlong)param_6)) {

        uVar18 = local_88;

      }

      ppppuVar12 = &local_98;

      if (0xf < local_80) {

        ppppuVar12 = (undefined8 ****)local_98;

      }

      if (0x7fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      if (uVar18 < 0x10) {

        uStack_a0 = 0xf;

        local_a8 = uVar18;

        FUN_1402f8e20(&local_b8,ppppuVar12);

        (&local_b8)[uVar18] = 0;

      }

      else {

        uVar13 = uVar18 | 0xf;

        uVar28 = 0x7fffffffffffffff;

        if ((uVar13 < 0x8000000000000000) && (uVar28 = uVar13, uVar13 < 0x16)) {

          uVar28 = 0x16;

        }

        lVar14 = FUN_1400285e0(uVar28 + 1);

        local_b8 = (undefined1)lVar14;

        uStack_b7 = (undefined7)((ulonglong)lVar14 >> 8);

        local_a8 = uVar18;

        uStack_a0 = uVar28;

        FUN_1402f8e20(lVar14,ppppuVar12);

        *(undefined1 *)(lVar14 + uVar18) = 0;

      }

      puVar23 = (undefined8 *)param_2[4];

      if (puVar23 == (undefined8 *)param_2[5]) {

        FUN_140087c70();

        uVar18 = uStack_a0;

      }

      else {

        *puVar23 = CONCAT71(uStack_b7,local_b8);

        puVar23[1] = uStack_b0;

        puVar23[2] = local_a8;

        puVar23[3] = uStack_a0;

        local_b8 = 0;

        param_2[4] = param_2[4] + 0x20;

        uVar18 = 0xf;

      }

      if (0xf < uVar18) {

        if ((0xfff < uVar18 + 1) &&

           (0x1f < (CONCAT71(uStack_b7,local_b8) - *(longlong *)(CONCAT71(uStack_b7,local_b8) + -8))

                   - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if (0xf < uVar22) {

        ppppuVar12 = (undefined8 ****)pppuVar8;

        if ((0xfff < uVar22 + 1) &&

           (ppppuVar12 = (undefined8 ****)pppuVar8[-1],

           0x1f < (ulonglong)((longlong)pppuVar8 + (-8 - (longlong)ppppuVar12)))) {

LAB_1400874a8:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(ppppuVar12);

      }

      uVar32 = FUN_1400c5c10();

      *(undefined4 *)(param_2 + 1) = uVar32;

    }

  }

  iVar21 = 0x10;

  iVar30 = 0;

  lVar14 = param_2[4];

  lVar25 = *plVar1;

  if (lVar14 - lVar25 >> 5 != 0) {

    lVar29 = 0;

    lVar27 = 0;

    uVar22 = (ulonglong)param_5;

    do {

      if (iVar21 == 0x10) {

        lVar14 = (longlong)iVar30;

      }

      else {

        uVar15 = FUN_14008d760(&local_98,&DAT_14039bf30,(&PTR_DAT_1403d9d30)[iVar21]);

        puVar23 = (undefined8 *)(*plVar1 + lVar27);

        if (0xf < (ulonglong)puVar23[3]) {

          puVar23 = (undefined8 *)*puVar23;

        }

        puVar16 = (ulonglong *)FUN_140027810(uVar15,puVar23);

        uVar18 = *puVar16;

        uVar28 = puVar16[1];

        uVar13 = puVar16[2];

        uVar19 = puVar16[3];

        puVar16[2] = 0;

        puVar16[3] = 0xf;

        *(undefined1 *)puVar16 = 0;

        puVar16 = (ulonglong *)(*plVar1 + lVar27);

        local_78 = uVar18;

        uStack_70 = uVar28;

        local_68 = uVar13;

        uStack_60 = uVar19;

        if (puVar16 != &local_78) {

          if (0xf < puVar16[3]) {

            uVar4 = *puVar16;

            uVar17 = uVar4;

            if ((0xfff < puVar16[3] + 1) &&

               (uVar17 = *(ulonglong *)(uVar4 - 8), 0x1f < (uVar4 - uVar17) - 8))

            goto LAB_1400874c1;

            FUN_1402c7088(uVar17);

          }

          *puVar16 = uVar18;

          puVar16[1] = uVar28;

          puVar16[2] = uVar13;

          puVar16[3] = uVar19;

          uVar19 = 0xf;

          local_78 = local_78 & 0xffffffffffffff00;

        }

        if (0xf < uVar19) {

          if ((0xfff < uVar19 + 1) && (0x1f < (local_78 - *(longlong *)(local_78 - 8)) - 8)) {

LAB_1400874c1:

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        lVar14 = lVar29;

        if (0xf < local_80) {

          if ((0xfff < local_80 + 1) &&

             (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      uVar24 = 0;

      lVar25 = *plVar1;

      pbVar26 = (byte *)(lVar14 * 0x20 + lVar25);

      if (0xf < *(ulonglong *)(pbVar26 + 0x18)) {

        pbVar26 = *(byte **)pbVar26;

      }

      bVar9 = *pbVar26;

      while (bVar9 != 0) {

        if (uVar24 == 0) {

          uVar20 = 0xff >> ((&DAT_14030ad90)[bVar9] & 0x1f) & (uint)bVar9;

        }

        else {

          uVar20 = bVar9 & 0x3f | (int)uVar22 << 6;

        }

        uVar22 = (ulonglong)uVar20;

        iVar10 = uVar24 + 0x10;

        uVar24 = (uint)(byte)(&DAT_14030ad90)[iVar10 * 0x10 + (uint)(byte)(&DAT_14030ad90)[bVar9]];

        if ((((&DAT_14030ad90)[iVar10 * 0x10 + (uint)(byte)(&DAT_14030ad90)[bVar9]] == 0) &&

            (uVar20 < 0x2165)) && ((byte)((&DAT_1403eaf30)[uVar22] - 1) < 0x11)) {

          iVar21 = (byte)(&DAT_1403eaf30)[uVar22] - 1;

        }

        pbVar26 = pbVar26 + 1;

        bVar9 = *pbVar26;

      }

      iVar30 = iVar30 + 1;

      lVar29 = lVar29 + 1;

      lVar27 = lVar27 + 0x20;

      lVar14 = param_2[4];

    } while ((ulonglong)(longlong)iVar30 < (ulonglong)(lVar14 - lVar25 >> 5));

  }

  *(float *)((longlong)param_2 + 0xc) =

       (float)(ulonglong)

              ((lVar14 - lVar25 >> 5) * (longlong)*(int *)(param_1 + 0xc) -

              (longlong)(*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)));

  return param_2;

}




