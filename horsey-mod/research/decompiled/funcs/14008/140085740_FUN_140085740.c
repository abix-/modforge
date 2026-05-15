// Address: 0x140085740
// Ghidra name: FUN_140085740
// ============ 0x140085740 FUN_140085740 (size=3003) ============


/* WARNING: Removing unreachable block (ram,0x000140085bfb) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140085740(undefined8 *param_1,byte param_2)



{

  char cVar1;

  undefined1 uVar2;

  byte bVar3;

  undefined1 uVar4;

  undefined1 uVar5;

  undefined1 uVar6;

  undefined1 uVar7;

  int iVar8;

  undefined8 uVar9;

  longlong *plVar10;

  undefined8 uVar11;

  longlong lVar12;

  byte *pbVar13;

  longlong lVar14;

  byte *pbVar15;

  ulonglong *puVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  undefined8 *****pppppuVar19;

  ulonglong uVar20;

  undefined8 *puVar21;

  uint uVar22;

  uint uVar23;

  char local_res18;

  char cStackX_19;

  undefined1 uStackX_1a;

  undefined1 uStackX_1b;

  longlong local_168;

  undefined8 *puStack_160;

  undefined8 *local_158;

  longlong local_150;

  undefined2 *puStack_148;

  undefined2 *local_140;

  undefined8 ****local_138;

  ulonglong uStack_130;

  ulonglong local_128;

  ulonglong uStack_120;

  uint local_118;

  undefined4 local_114;

  longlong local_110;

  undefined8 local_108;

  longlong local_100 [3];

  ulonglong local_e8;

  undefined **local_d8 [14];

  undefined1 local_68 [48];

  

  FUN_140087710();

  FUN_140025e00(local_d8);

  uVar9 = FUN_1400c4e00();

  uVar9 = FUN_1400748b0(local_100,uVar9,param_1);

  plVar10 = (longlong *)FUN_140027810(uVar9,".fxml");

  local_138 = (undefined8 ****)*plVar10;

  uStack_130 = plVar10[1];

  local_128 = plVar10[2];

  uStack_120 = plVar10[3];

  plVar10[2] = 0;

  plVar10[3] = 0xf;

  *(undefined1 *)plVar10 = 0;

  pppppuVar19 = &local_138;

  if (0xf < uStack_120) {

    pppppuVar19 = (undefined8 *****)local_138;

  }

  cVar1 = FUN_140025f00(local_d8,pppppuVar19);

  if (0xf < uStack_120) {

    pppppuVar19 = (undefined8 *****)local_138;

    if ((0xfff < uStack_120 + 1) &&

       (pppppuVar19 = (undefined8 *****)local_138[-1],

       0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)pppppuVar19)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(pppppuVar19);

  }

  local_128 = _DAT_14039caa0;

  uStack_120 = _UNK_14039caa8;

  local_138 = (undefined8 ****)((ulonglong)local_138 & 0xffffffffffffff00);

  if (0xf < local_e8) {

    if ((0xfff < local_e8 + 1) && (0x1f < (local_100[0] - *(longlong *)(local_100[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  if (cVar1 != '\0') {

    uVar9 = FUN_140025320(local_d8);

    local_108 = uVar9;

    uVar11 = FUN_140025360(uVar9,&DAT_14030af34);

    uVar11 = FUN_140025dc0(uVar11);

    uVar2 = FUN_1402d89dc(uVar11);

    uVar11 = FUN_140025360(uVar9,"line_gap");

    uVar11 = FUN_140025dc0(uVar11);

    bVar3 = FUN_1402d89dc(uVar11);

    uVar11 = FUN_140025360(uVar9,"space_w");

    uVar11 = FUN_140025dc0(uVar11);

    local_114 = FUN_1402d89dc(uVar11);

    if (param_2 != 0) {

      bVar3 = param_2;

    }

    local_118 = (uint)bVar3;

    local_168 = 0;

    puStack_160 = (undefined8 *)0x0;

    local_158 = (undefined8 *)0x0;

    local_150 = 0;

    puStack_148 = (undefined2 *)0x0;

    local_140 = (undefined2 *)0x0;

    uVar11 = FUN_140025360(uVar9,"glyphs");

    lVar12 = FUN_140025320(uVar11);

    local_110 = lVar12;

    if (lVar12 != 0) {

      uVar22 = CONCAT13(uStackX_1b,CONCAT12(uStackX_1a,CONCAT11(cStackX_19,local_res18)));

      do {

        uVar23 = 0;

        local_res18 = -1;

        local_110 = lVar12;

        uVar9 = FUN_140025360(lVar12,&DAT_14030af60);

        pbVar13 = (byte *)FUN_140025dc0(uVar9);

        if (pbVar13 != (byte *)0x0) {

          bVar3 = *pbVar13;

          if (bVar3 != 0) {

            do {

              uVar20 = (ulonglong)bVar3;

              if (uVar23 == 0) {

                uVar22 = 0xff >> ((&DAT_14030ad90)[uVar20] & 0x1f) & (uint)bVar3;

              }

              else {

                uVar22 = bVar3 & 0x3f | uVar22 << 6;

              }

              iVar8 = uVar23 + 0x10;

              uVar23 = (uint)(byte)(&DAT_14030ad90)

                                   [iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]];

              pbVar13 = pbVar13 + 1;

              bVar3 = *pbVar13;

            } while (bVar3 != 0);

            if ((&DAT_14030ad90)[iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]] != 0) {

              puVar21 = param_1;

              if (0xf < (ulonglong)param_1[3]) {

                puVar21 = (undefined8 *)*param_1;

              }

              FUN_1400c4320("Font %s glyph %s is malformed UTF8",puVar21);

            }

          }

          if ((0x2164 < uVar22) || (local_res18 = (&DAT_1403eaf30)[uVar22], local_res18 == -1)) {

            puVar21 = param_1;

            if (0xf < (ulonglong)param_1[3]) {

              puVar21 = (undefined8 *)*param_1;

            }

            FUN_1400c4320("Font %s codepoint %d is unsupported",puVar21);

          }

        }

        uVar9 = FUN_140025360(lVar12,&DAT_14030a29c);

        uVar9 = FUN_140025dc0(uVar9);

        cStackX_19 = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,&DAT_14030a2a0);

        uVar9 = FUN_140025dc0(uVar9);

        uStackX_1a = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,&DAT_14039bee0);

        uVar9 = FUN_140025dc0(uVar9);

        uStackX_1b = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,&DAT_14030a2a4);

        uVar9 = FUN_140025dc0(uVar9);

        uVar4 = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,"off_x");

        uVar9 = FUN_140025dc0(uVar9);

        uVar5 = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,"off_y");

        uVar9 = FUN_140025dc0(uVar9);

        uVar6 = FUN_1402d89dc(uVar9);

        uVar9 = FUN_140025360(lVar12,&DAT_14030afc4);

        uVar9 = FUN_140025dc0(uVar9);

        uVar7 = FUN_1402d89dc(uVar9);

        if (puStack_160 == local_158) {

          lVar12 = (longlong)puStack_160 - local_168 >> 3;

          if (lVar12 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar20 = lVar12 + 1;

          uVar17 = (longlong)local_158 - local_168 >> 3;

          if (0x1fffffffffffffff - (uVar17 >> 1) < uVar17) {

            uVar18 = 0x1fffffffffffffff;

          }

          else {

            uVar17 = uVar17 + (uVar17 >> 1);

            uVar18 = uVar20;

            if (uVar20 <= uVar17) {

              uVar18 = uVar17;

            }

            if (0x1fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          lVar14 = FUN_1400285e0(uVar18 * 8);

          *(ulonglong *)(lVar14 + lVar12 * 8) =

               CONCAT17(uVar7,CONCAT16(uVar6,CONCAT15(uVar5,CONCAT14(uVar4,CONCAT13(uStackX_1b,

                                                                                    CONCAT12(

                                                  uStackX_1a,CONCAT11(cStackX_19,local_res18)))))));

          FUN_1402f8e20(lVar14,local_168);

          if (local_168 != 0) {

            if ((0xfff < ((longlong)local_158 - local_168 & 0xfffffffffffffff8U)) &&

               (0x1f < (local_168 - *(longlong *)(local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          puStack_160 = (undefined8 *)(lVar14 + uVar20 * 8);

          local_158 = (undefined8 *)(lVar14 + uVar18 * 8);

          lVar12 = local_110;

          local_168 = lVar14;

        }

        else {

          *puStack_160 = CONCAT17(uVar7,CONCAT16(uVar6,CONCAT15(uVar5,CONCAT14(uVar4,CONCAT13(

                                                  uStackX_1b,

                                                  CONCAT12(uStackX_1a,

                                                           CONCAT11(cStackX_19,local_res18)))))));

          puStack_160 = puStack_160 + 1;

        }

        lVar12 = FUN_140025450(lVar12);

      } while (lVar12 != 0);

      local_110 = 0;

      uVar9 = local_108;

    }

    lVar12 = FUN_140025360(uVar9,"kerning");

    if ((lVar12 != 0) && (lVar12 = FUN_140025320(lVar12), lVar12 != 0)) {

      uVar22 = CONCAT13(uStackX_1b,CONCAT12(uStackX_1a,CONCAT11(cStackX_19,local_res18)));

      do {

        local_res18 = -1;

        cStackX_19 = -1;

        uVar9 = FUN_140025360(lVar12,&DAT_14030afd0);

        pbVar13 = (byte *)FUN_140025dc0(uVar9);

        uVar9 = FUN_140025360(lVar12,"right");

        pbVar15 = (byte *)FUN_140025dc0(uVar9);

        if ((pbVar13 != (byte *)0x0) && (pbVar15 != (byte *)0x0)) {

          uVar23 = 0;

          bVar3 = *pbVar13;

          if (bVar3 != 0) {

            do {

              uVar20 = (ulonglong)bVar3;

              if (uVar23 == 0) {

                uVar22 = 0xff >> ((&DAT_14030ad90)[uVar20] & 0x1f) & (uint)bVar3;

              }

              else {

                uVar22 = bVar3 & 0x3f | uVar22 << 6;

              }

              iVar8 = uVar23 + 0x10;

              uVar23 = (uint)(byte)(&DAT_14030ad90)

                                   [iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]];

              pbVar13 = pbVar13 + 1;

              bVar3 = *pbVar13;

            } while (bVar3 != 0);

            if ((&DAT_14030ad90)[iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]] != 0) {

              puVar21 = param_1;

              if (0xf < (ulonglong)param_1[3]) {

                puVar21 = (undefined8 *)*param_1;

              }

              FUN_1400c4320("Font %s kerning %s is malformed UTF8",puVar21);

            }

          }

          local_res18 = -1;

          if (uVar22 < 0x2165) {

            local_res18 = (&DAT_1403eaf30)[uVar22];

          }

          uVar23 = 0;

          bVar3 = *pbVar15;

          if (bVar3 != 0) {

            do {

              uVar20 = (ulonglong)bVar3;

              if (uVar23 == 0) {

                uVar22 = 0xff >> ((&DAT_14030ad90)[uVar20] & 0x1f) & (uint)bVar3;

              }

              else {

                uVar22 = bVar3 & 0x3f | uVar22 << 6;

              }

              iVar8 = uVar23 + 0x10;

              uVar23 = (uint)(byte)(&DAT_14030ad90)

                                   [iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]];

              pbVar15 = pbVar15 + 1;

              bVar3 = *pbVar15;

            } while (bVar3 != 0);

            if ((&DAT_14030ad90)[iVar8 * 0x10 + (uint)(byte)(&DAT_14030ad90)[uVar20]] != 0) {

              puVar21 = param_1;

              if (0xf < (ulonglong)param_1[3]) {

                puVar21 = (undefined8 *)*param_1;

              }

              FUN_1400c4320("Font %s kerning %s is malformed UTF8",puVar21);

            }

          }

          if (uVar22 < 0x2165) {

            cStackX_19 = (&DAT_1403eaf30)[uVar22];

          }

          else {

            cStackX_19 = -1;

          }

        }

        uVar9 = FUN_140025360(lVar12,&DAT_14030b008);

        uVar9 = FUN_140025dc0(uVar9);

        uVar4 = FUN_1402d89dc(uVar9);

        if ((local_res18 != -1) && (cStackX_19 != -1)) {

          if (puStack_148 == local_140) {

            FUN_140087ab0(&local_150);

          }

          else {

            *puStack_148 = CONCAT11(cStackX_19,local_res18);

            *(undefined1 *)(puStack_148 + 1) = uVar4;

            puStack_148 = (undefined2 *)((longlong)puStack_148 + 3);

          }

        }

        lVar12 = FUN_140025450(lVar12);

      } while (lVar12 != 0);

    }

    FUN_1400755a0(0xffffffff);

    FUN_140075710(1);

    FUN_140075710(uVar2);

    FUN_140075710((undefined1)local_118);

    FUN_140075710((undefined1)local_114);

    FUN_140075730((longlong)puStack_160 - local_168 >> 3);

    FUN_140075730(((longlong)puStack_148 - local_150) / 3);

    uVar20 = 0;

    uVar17 = uVar20;

    uVar18 = uVar20;

    if ((longlong)puStack_160 - local_168 >> 3 != 0) {

      do {

        FUN_140075710(*(undefined1 *)(uVar17 + local_168));

        FUN_140075710(*(undefined1 *)(uVar17 + 1 + local_168));

        FUN_140075710(*(undefined1 *)(uVar17 + 2 + local_168));

        FUN_140075710(*(undefined1 *)(uVar17 + 3 + local_168));

        FUN_140075710(*(undefined1 *)(uVar17 + 4 + local_168));

        FUN_1400756f0(*(undefined1 *)(uVar17 + 5 + local_168));

        FUN_1400756f0(*(undefined1 *)(uVar17 + 6 + local_168));

        FUN_140075710(*(undefined1 *)(uVar17 + 7 + local_168));

        uVar22 = (int)uVar18 + 1;

        uVar17 = uVar17 + 8;

        uVar18 = (ulonglong)uVar22;

      } while ((ulonglong)(longlong)(int)uVar22 <

               (ulonglong)((longlong)puStack_160 - local_168 >> 3));

    }

    uVar17 = uVar20;

    if (((longlong)puStack_148 - local_150) / 3 != 0) {

      do {

        FUN_140075710(*(undefined1 *)(local_150 + uVar20));

        FUN_140075710(*(undefined1 *)(local_150 + 1 + uVar20));

        FUN_1400756f0(*(undefined1 *)(local_150 + 2 + uVar20));

        uVar22 = (int)uVar17 + 1;

        uVar20 = uVar20 + 3;

        uVar17 = (ulonglong)uVar22;

      } while ((ulonglong)(longlong)(int)uVar22 <

               (ulonglong)(((longlong)puStack_148 - local_150) / 3));

    }

    uVar9 = FUN_1400c4e00();

    uVar9 = FUN_1400748b0(local_100,uVar9,param_1);

    puVar16 = (ulonglong *)FUN_140027810(uVar9,&DAT_14030b010);

    local_138 = (undefined8 ****)*puVar16;

    uStack_130 = puVar16[1];

    local_128 = puVar16[2];

    uStack_120 = puVar16[3];

    puVar16[2] = 0;

    puVar16[3] = 0xf;

    *(undefined1 *)puVar16 = 0;

    FUN_1400755f0(&local_138);

    if (0xf < uStack_120) {

      if ((0xfff < uStack_120 + 1) &&

         (0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)local_138[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_128 = _DAT_14039caa0;

    uStack_120 = _UNK_14039caa8;

    local_138 = (undefined8 ****)((ulonglong)local_138 & 0xffffffffffffff00);

    if (0xf < local_e8) {

      if ((0xfff < local_e8 + 1) && (0x1f < (local_100[0] - *(longlong *)(local_100[0] + -8)) - 8U))

      {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (local_150 != 0) {

      lVar12 = local_150;

      if ((0xfff < (ulonglong)((((longlong)local_140 - local_150) / 3) * 3)) &&

         (lVar12 = *(longlong *)(local_150 + -8), 0x1f < (local_150 - lVar12) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(lVar12);

      local_150 = 0;

      puStack_148 = (undefined2 *)0x0;

      local_140 = (undefined2 *)0x0;

    }

    if (local_168 != 0) {

      if ((0xfff < ((longlong)local_158 - local_168 & 0xfffffffffffffff8U)) &&

         (0x1f < (local_168 - *(longlong *)(local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  local_d8[0] = TiXmlDocument::vftable;

  FUN_140027900(local_68);

  FUN_140024a60(local_d8);

  FUN_140027900(param_1);

  return;

}




