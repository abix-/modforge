// Address: 0x1400a3eb0
// Ghidra name: FUN_1400a3eb0
// ============ 0x1400a3eb0 FUN_1400a3eb0 (size=2491) ============


/* WARNING: Removing unreachable block (ram,0x0001400a470e) */

/* WARNING: Removing unreachable block (ram,0x0001400a470b) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a3eb0(void)



{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  undefined8 *******pppppppuVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined8 ******ppppppuVar8;

  undefined8 ******ppppppuVar9;

  char ******ppppppcVar10;

  undefined4 *puVar11;

  longlong lVar12;

  undefined8 uVar13;

  char *pcVar14;

  longlong *plVar15;

  longlong lVar16;

  undefined8 *******pppppppuVar17;

  char *******pppppppcVar18;

  undefined8 *******pppppppuVar19;

  ulonglong uVar20;

  uint uVar21;

  undefined4 uVar22;

  longlong *plVar23;

  ulonglong uVar24;

  ulonglong uVar25;

  undefined4 uVar26;

  longlong *plVar27;

  undefined8 *******pppppppuVar28;

  longlong lVar29;

  ulonglong uVar30;

  uint *puVar31;

  uint *puVar32;

  ulonglong uVar33;

  int local_res8 [2];

  undefined4 local_res10 [2];

  longlong local_res18;

  undefined8 ******local_1a8;

  undefined8 ******ppppppuStack_1a0;

  undefined8 ******local_198;

  ulonglong uStack_190;

  undefined8 ******local_188;

  undefined8 ******ppppppuStack_180;

  undefined8 ******local_178;

  ulonglong uStack_170;

  char ******local_168;

  undefined8 uStack_160;

  longlong local_158;

  ulonglong uStack_150;

  byte local_148 [8];

  char ******local_140;

  undefined8 uStack_138;

  undefined1 local_130 [16];

  undefined **local_118 [14];

  undefined1 local_a8 [112];

  

  uVar25 = 0;

  uVar26 = 0;

  puVar11 = &DAT_1403ee4a4;

  uVar30 = uVar25;

  do {

    puVar11[-1] = (int)uVar30;

    *puVar11 = 100;

    *(undefined8 *)(puVar11 + 1) = 1;

    *(undefined8 *)(puVar11 + 3) = 0;

    *(undefined8 *)(puVar11 + 5) = 0;

    uVar21 = (int)uVar30 + 1;

    uVar30 = (ulonglong)uVar21;

    puVar11 = puVar11 + 8;

  } while ((int)uVar21 < 0xf0);

  FUN_140025e00(local_118);

  local_res10[0] = 0;

  local_198 = (undefined8 *******)0x9;

  uStack_190 = 0xf;

  local_1a8 = (undefined8 ******)s_genes_xml_14030cc50._0_8_;

  ppppppuStack_1a0 = (undefined8 ******)(ulonglong)(byte)s_genes_xml_14030cc50[8];

  lVar12 = FUN_1400c43d0(&local_1a8,local_res10);

  if (lVar12 != 0) {

    FUN_1400293d0(local_118,lVar12);

    uVar13 = FUN_140025320(local_118);

    lVar12 = FUN_140025320(uVar13);

    uVar20 = _UNK_14039caa8;

    lVar7 = _DAT_14039caa0;

    uVar30 = _UNK_14030cd48;

    pppppppuVar19 = _DAT_14030cd40;

    uVar6 = _UNK_1403041e8;

    uVar13 = _DAT_1403041e0;

    local_res18 = lVar12;

    while (lVar12 != 0) {

      ppppppuStack_1a0 = (undefined8 *******)0x0;

      local_198 = (undefined8 *******)0x0;

      uStack_190 = 0xf;

      local_1a8 = (undefined8 *******)0x0;

      pcVar14 = (char *)FUN_1400256d0(lVar12,&DAT_140304430);

      if (pcVar14 != (char *)0x0) {

        local_188 = (undefined8 *******)0x0;

        ppppppuStack_180 = (undefined8 *******)0x0;

        local_178 = (undefined8 *******)0x0;

        uStack_170 = 0;

        strlen(pcVar14);

        FUN_140027e30(&local_188,pcVar14);

        if (0xf < uStack_190) {

          if ((0xfff < uStack_190 + 1) &&

             (0x1f < (ulonglong)((longlong)local_1a8 + (-8 - (longlong)local_1a8[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_1a8 = local_188;

        ppppppuStack_1a0 = ppppppuStack_180;

        local_198 = local_178;

        uStack_190 = uStack_170;

      }

      uVar33 = uStack_190;

      ppppppuVar9 = local_198;

      ppppppuVar8 = local_1a8;

      plVar23 = (longlong *)DAT_1403f2fd8[1];

      cVar1 = *(char *)((longlong)plVar23 + 0x19);

      plVar27 = DAT_1403f2fd8;

      plVar15 = DAT_1403f2fd8;

      while (DAT_1403f2fd8 = plVar15, cVar1 == '\0') {

        plVar15 = plVar23 + 4;

        pppppppuVar17 = &local_1a8;

        if (0xf < uVar33) {

          pppppppuVar17 = (undefined8 *******)ppppppuVar8;

        }

        if (0xf < (ulonglong)plVar23[7]) {

          plVar15 = (longlong *)*plVar15;

        }

        pppppppuVar5 = (undefined8 *******)plVar23[6];

        pppppppuVar28 = pppppppuVar5;

        if (ppppppuVar9 < pppppppuVar5) {

          pppppppuVar28 = (undefined8 *******)ppppppuVar9;

        }

        uVar21 = memcmp(plVar15,pppppppuVar17,(size_t)pppppppuVar28);

        if (uVar21 == 0) {

          if (pppppppuVar5 < ppppppuVar9) {

            uVar21 = 0xffffffff;

          }

          else {

            uVar21 = (uint)(ppppppuVar9 < pppppppuVar5);

          }

        }

        plVar15 = plVar23 + 2;

        if (-1 < (int)uVar21) {

          plVar15 = plVar23;

          plVar27 = plVar23;

        }

        plVar23 = (longlong *)*plVar15;

        plVar15 = DAT_1403f2fd8;

        cVar1 = *(char *)((longlong)plVar23 + 0x19);

      }

      if (*(char *)((longlong)plVar27 + 0x19) == '\0') {

        plVar23 = plVar27 + 4;

        if (0xf < (ulonglong)plVar27[7]) {

          plVar23 = (longlong *)*plVar23;

        }

        pppppppuVar17 = &local_1a8;

        if (0xf < uVar33) {

          pppppppuVar17 = (undefined8 *******)ppppppuVar8;

        }

        pppppppuVar5 = (undefined8 *******)plVar27[6];

        pppppppuVar28 = (undefined8 *******)ppppppuVar9;

        if (pppppppuVar5 < ppppppuVar9) {

          pppppppuVar28 = pppppppuVar5;

        }

        uVar21 = memcmp(pppppppuVar17,plVar23,(size_t)pppppppuVar28);

        if (uVar21 == 0) {

          if (ppppppuVar9 < pppppppuVar5) {

            uVar21 = 0xffffffff;

          }

          else {

            uVar21 = (uint)(pppppppuVar5 < ppppppuVar9);

          }

        }

        if ((int)uVar21 < 0) goto LAB_1400a4156;

      }

      else {

LAB_1400a4156:

        plVar27 = plVar15;

      }

      lVar12 = local_res18;

      if ((plVar27 != plVar15) && (lVar16 = (longlong)(int)plVar27[8], (int)plVar27[8] != -1)) {

        FUN_140025730(local_res18,&DAT_14030cc5c,&DAT_1403ee4a4 + lVar16 * 8);

        FUN_140025730(lVar12,&DAT_14030cc60,&DAT_1403ee4a8 + lVar16 * 8);

        ppppppuStack_180 = (undefined8 *******)0x0;

        local_178 = pppppppuVar19;

        uStack_170 = uVar30;

        local_188 = (undefined8 *******)0x3067;

        local_res8[0] = 0;

        FUN_1400257d0(lVar12,&local_188,local_res8);

        (&DAT_1403ee4b0)[lVar16 * 8] =

             (float)local_res8[0] / (float)(int)(&DAT_1403ee4a8)[lVar16 * 8];

        pppppppuVar17 = &local_188;

        if (0xf < uStack_170) {

          pppppppuVar17 = (undefined8 *******)local_188;

        }

        *(undefined1 *)((longlong)pppppppuVar17 + 1) = 0x31;

        local_res8[0] = 0;

        FUN_1400257d0(lVar12,&local_188,local_res8);

        (&DAT_1403ee4b4)[lVar16 * 8] =

             (float)local_res8[0] / (float)(int)(&DAT_1403ee4a8)[lVar16 * 8];

        pppppppuVar17 = &local_188;

        if (0xf < uStack_170) {

          pppppppuVar17 = (undefined8 *******)local_188;

        }

        *(undefined1 *)((longlong)pppppppuVar17 + 1) = 0x32;

        local_res8[0] = 0;

        FUN_1400257d0(lVar12,&local_188,local_res8);

        (&DAT_1403ee4b8)[lVar16 * 8] =

             (float)local_res8[0] / (float)(int)(&DAT_1403ee4a8)[lVar16 * 8];

        pppppppuVar17 = &local_188;

        if (0xf < uStack_170) {

          pppppppuVar17 = (undefined8 *******)local_188;

        }

        *(undefined1 *)((longlong)pppppppuVar17 + 1) = 0x33;

        local_res8[0] = 0;

        FUN_1400257d0(lVar12,&local_188);

        (&DAT_1403ee4bc)[lVar16 * 8] =

             (float)local_res8[0] / (float)(int)(&DAT_1403ee4a8)[lVar16 * 8];

        uStack_160 = 0;

        local_158 = lVar7;

        uStack_150 = uVar20;

        local_168 = (char ******)0x0;

        pcVar14 = (char *)FUN_1400256d0(lVar12,&DAT_140305358);

        lVar29 = lVar7;

        uVar33 = uVar20;

        if (pcVar14 != (char *)0x0) {

          local_140 = (char ******)0x0;

          uStack_138 = 0;

          local_130 = ZEXT816(0);

          strlen(pcVar14);

          FUN_140027e30(&local_140,pcVar14);

          local_168 = local_140;

          uStack_160 = uStack_138;

          local_158 = local_130._0_8_;

          uStack_150 = local_130._8_8_;

          lVar29 = local_130._0_8_;

          uVar33 = local_130._8_8_;

        }

        ppppppcVar10 = local_168;

        local_res8[0] = 0;

        if (lVar29 == 4) {

          pppppppcVar18 = &local_168;

          if (0xf < uVar33) {

            pppppppcVar18 = (char *******)local_168;

          }

          if (*(char *)pppppppcVar18 == 'C') {

            uVar24 = 3;

LAB_1400a43a0:

            uVar22 = (undefined4)uVar24;

          }

          else {

            pppppppcVar18 = &local_168;

            if (0xf < uVar33) {

              pppppppcVar18 = (char *******)local_168;

            }

            if (*(char *)pppppppcVar18 == 'T') {

              uVar24 = 2;

              goto LAB_1400a43a0;

            }

            pppppppcVar18 = &local_168;

            if (0xf < uVar33) {

              pppppppcVar18 = (char *******)local_168;

            }

            uVar24 = uVar25;

            if (*(char *)pppppppcVar18 != 'A') goto LAB_1400a43a0;

            uVar22 = 1;

            uVar24 = 1;

          }

          cVar1 = *(char *)((longlong)local_res8 + uVar24);

          *(undefined1 *)((longlong)local_res8 + uVar24) = 1;

          (&DAT_1403f02a0)[lVar16 * 4] = uVar22;

          pppppppcVar18 = &local_168;

          if (0xf < uVar33) {

            pppppppcVar18 = (char *******)local_168;

          }

          if (*(char *)((longlong)pppppppcVar18 + 1) == 'C') {

            uVar24 = 3;

            uVar22 = 3;

          }

          else {

            pppppppcVar18 = &local_168;

            if (0xf < uVar33) {

              pppppppcVar18 = (char *******)local_168;

            }

            if (*(char *)((longlong)pppppppcVar18 + 1) == 'T') {

              uVar24 = 2;

              uVar22 = 2;

            }

            else {

              pppppppcVar18 = &local_168;

              if (0xf < uVar33) {

                pppppppcVar18 = (char *******)local_168;

              }

              uVar24 = uVar25;

              uVar22 = uVar26;

              if (*(char *)((longlong)pppppppcVar18 + 1) == 'A') {

                uVar22 = 1;

                uVar24 = 1;

              }

            }

          }

          cVar2 = *(char *)((longlong)local_res8 + uVar24);

          *(undefined1 *)((longlong)local_res8 + uVar24) = 1;

          (&DAT_1403f02a4)[lVar16 * 4] = uVar22;

          pppppppcVar18 = &local_168;

          if (0xf < uVar33) {

            pppppppcVar18 = (char *******)local_168;

          }

          if (*(char *)((longlong)pppppppcVar18 + 2) == 'C') {

            uVar24 = 3;

            uVar22 = 3;

          }

          else {

            pppppppcVar18 = &local_168;

            if (0xf < uVar33) {

              pppppppcVar18 = (char *******)local_168;

            }

            if (*(char *)((longlong)pppppppcVar18 + 2) == 'T') {

              uVar24 = 2;

              uVar22 = 2;

            }

            else {

              pppppppcVar18 = &local_168;

              if (0xf < uVar33) {

                pppppppcVar18 = (char *******)local_168;

              }

              uVar24 = uVar25;

              uVar22 = uVar26;

              if (*(char *)((longlong)pppppppcVar18 + 2) == 'A') {

                uVar22 = 1;

                uVar24 = 1;

              }

            }

          }

          cVar3 = *(char *)((longlong)local_res8 + uVar24);

          *(undefined1 *)((longlong)local_res8 + uVar24) = 1;

          (&DAT_1403f02a8)[lVar16 * 4] = uVar22;

          lVar29 = 0;

          pppppppcVar18 = &local_168;

          if (0xf < uVar33) {

            pppppppcVar18 = (char *******)local_168;

          }

          if (*(char *)((longlong)pppppppcVar18 + 3) == 'C') {

            lVar29 = 3;

            uVar22 = 3;

          }

          else {

            pppppppcVar18 = &local_168;

            if (0xf < uVar33) {

              pppppppcVar18 = (char *******)local_168;

            }

            if (*(char *)((longlong)pppppppcVar18 + 3) == 'T') {

              lVar29 = 2;

              uVar22 = 2;

            }

            else {

              pppppppcVar18 = &local_168;

              if (0xf < uVar33) {

                pppppppcVar18 = (char *******)local_168;

              }

              uVar22 = uVar26;

              if (*(char *)((longlong)pppppppcVar18 + 3) == 'A') {

                uVar22 = 1;

                lVar29 = 1;

              }

            }

          }

          cVar4 = *(char *)((longlong)local_res8 + lVar29);

          *(undefined1 *)((longlong)local_res8 + lVar29) = 1;

          (&DAT_1403f02ac)[lVar16 * 4] = uVar22;

          if ((cVar4 != '\0') || (cVar3 != '\0' || (cVar2 != '\0' || cVar1 != '\0')))

          goto LAB_1400a4570;

        }

        else {

LAB_1400a4570:

          *(undefined8 *)(&DAT_1403f02a0 + lVar16 * 4) = uVar13;

          *(undefined8 *)(&DAT_1403f02a8 + lVar16 * 4) = uVar6;

          FUN_1400c5c80(&DAT_1403f02a0 + lVar16 * 4,4);

          pppppppuVar17 = &local_1a8;

          if (0xf < uStack_190) {

            pppppppuVar17 = (undefined8 *******)local_1a8;

          }

          FUN_1400c4320("nuc letter map incomplete for %s",pppppppuVar17);

        }

        if (0xf < uVar33) {

          pppppppcVar18 = (char *******)ppppppcVar10;

          if ((0xfff < uVar33 + 1) &&

             (pppppppcVar18 = (char *******)ppppppcVar10[-1],

             (char *)0x1f < (char *)((longlong)ppppppcVar10 + (-8 - (longlong)pppppppcVar18)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(pppppppcVar18);

        }

        if (0xf < uStack_170) {

          if ((0xfff < uStack_170 + 1) &&

             (0x1f < (ulonglong)((longlong)local_188 + (-8 - (longlong)local_188[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      lVar12 = FUN_140025450(lVar12);

      local_res18 = lVar12;

      if (0xf < uStack_190) {

        if ((0xfff < uStack_190 + 1) &&

           (0x1f < (ulonglong)((longlong)local_1a8 + (-8 - (longlong)local_1a8[-1])))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    local_148[0] = 0;

    local_148[1] = 0;

    local_148[2] = 0;

    local_148[3] = 0;

    pppppppuVar19 = (undefined8 *******)FUN_1400285e0(0x20);

    local_198 = pppppppuVar19 + 4;

    local_148[4] = 0;

    local_148[5] = 0;

    local_148[6] = 0;

    local_148[7] = 0;

    uVar30 = uVar25;

    do {

      uVar20 = uVar30 + 1;

      if (local_148[uVar30] != local_148[uVar30 + 4]) {

        uVar21 = -(uint)(local_148[uVar30] < local_148[uVar30 + 4]) | 1;

        goto LAB_1400a46ce;

      }

      uVar30 = uVar20;

    } while (uVar20 != 4);

    uVar21 = 0;

LAB_1400a46ce:

    if (uVar21 == 0) {

      *pppppppuVar19 = (undefined8 ******)0x0;

      pppppppuVar19[1] = (undefined8 ******)0x0;

      pppppppuVar19[2] = (undefined8 ******)0x0;

      pppppppuVar19[3] = (undefined8 ******)0x0;

    }

    else {

      *pppppppuVar19 = (undefined8 ******)0x0;

      pppppppuVar19[1] = (undefined8 ******)0x0;

      pppppppuVar19[2] = (undefined8 ******)0x0;

      pppppppuVar19[3] = (undefined8 ******)0x0;

    }

    ppppppuStack_1a0 = pppppppuVar19 + 4;

    uStack_190 = 0xf0;

    *(undefined2 *)((longlong)pppppppuVar19 + 0x1e) = 0;

    puVar31 = &DAT_14030c690;

    uVar30 = uVar25;

    local_1a8 = pppppppuVar19;

    puVar32 = puVar31;

LAB_1400a4736:

    do {

      uVar21 = *puVar31;

      if (uVar21 != 0xffffffff) {

        uVar20 = (ulonglong)(longlong)(int)uVar21 >> 5;

        if ((*(uint *)((longlong)pppppppuVar19 + uVar20 * 4) & 1 << (sbyte)(uVar21 & 0x1f)) != 0) {

          FUN_1400c4320("Gene %d exists twice in chromoMap");

        }

        *(uint *)((longlong)pppppppuVar19 + uVar20 * 4) =

             *(uint *)((longlong)pppppppuVar19 + uVar20 * 4) | 1 << (uVar21 & 0x1f);

        uVar30 = uVar30 + 1;

        puVar31 = puVar31 + 1;

        if ((longlong)uVar30 < 0x10) goto LAB_1400a4736;

      }

      puVar31 = puVar32 + 0x11;

      uVar30 = uVar25;

      puVar32 = puVar31;

    } while ((longlong)puVar31 < 0x14030cbe0);

    do {

      if ((*(uint *)((longlong)pppppppuVar19 + (uVar25 >> 5) * 4) >> ((byte)uVar25 & 0x1f) & 1) == 0

         ) {

        FUN_1400c4320("Gene %d not in chromoMap",uVar30);

      }

      uVar21 = (int)uVar30 + 1;

      uVar25 = uVar25 + 1;

      uVar30 = (ulonglong)uVar21;

    } while ((int)uVar21 < 0xf0);

    FUN_1400308d0(&local_1a8);

  }

  local_118[0] = TiXmlDocument::vftable;

  FUN_140027900(local_a8);

  FUN_140024a60(local_118);

  return;

}




