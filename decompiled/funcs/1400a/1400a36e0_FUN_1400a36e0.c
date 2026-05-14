// Address: 0x1400a36e0
// Ghidra name: FUN_1400a36e0
// ============ 0x1400a36e0 FUN_1400a36e0 (size=1958) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a36e0(void)



{

  longlong ****pppplVar1;

  longlong ****pppplVar2;

  longlong ****pppplVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  longlong ****pppplVar6;

  uint uVar7;

  byte bVar8;

  char cVar9;

  int iVar10;

  longlong lVar11;

  size_t sVar12;

  undefined8 *puVar13;

  longlong ****pppplVar14;

  byte *pbVar15;

  char *pcVar16;

  uint uVar17;

  int iVar18;

  ulonglong uVar20;

  ulonglong uVar21;

  int iVar22;

  undefined8 *puVar23;

  ulonglong uVar24;

  ulonglong uVar25;

  char *_Str;

  char *pcVar26;

  int local_res8 [4];

  longlong ***local_98;

  undefined8 uStack_90;

  ulonglong local_88;

  ulonglong uStack_80;

  undefined1 local_78;

  undefined7 uStack_77;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  int local_58;

  char *pcVar19;

  

  pcVar19 = (char *)0x0;

  local_res8[0] = 0;

  local_88 = 10;

  uVar24 = 0xf;

  uStack_80 = 0xf;

  local_98 = (longlong ***)s_GeneEnum_h_14030cc30._0_8_;

  uStack_90 = (ulonglong)(ushort)s_GeneEnum_h_14030cc30._8_2_;

  lVar11 = FUN_1400c4790(&local_98,local_res8);

  if (lVar11 == 0) {

    puVar13 = (undefined8 *)FUN_1400c4e00();

    lVar11 = puVar13[2];

    if (0x7fffffffffffffffU - lVar11 < 9) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    if (0xf < (ulonglong)puVar13[3]) {

      puVar13 = (undefined8 *)*puVar13;

    }

    local_98 = (longlong ***)0x0;

    uStack_90._0_4_ = 0;

    uStack_90._4_4_ = 0;

    local_88 = 0;

    uStack_80 = 0;

    uVar25 = lVar11 + 9;

    pppplVar14 = &local_98;

    if (0xf < uVar25) {

      uVar24 = uVar25 | 0xf;

      if (uVar24 < 0x8000000000000000) {

        if (uVar24 < 0x16) {

          uVar24 = 0x16;

        }

      }

      else {

        uVar24 = 0x7fffffffffffffff;

      }

      pppplVar14 = (longlong ****)FUN_1400285e0(uVar24 + 1);

      local_98 = (longlong ***)pppplVar14;

    }

    local_88 = uVar25;

    uStack_80 = uVar24;

    FUN_1402f8e20(pppplVar14,puVar13);

    *(undefined8 *)((longlong)pppplVar14 + lVar11) = s_genes_dat_14030cc40._0_8_;

    *(char *)((longlong)pppplVar14 + lVar11 + 8) = s_genes_dat_14030cc40[8];

    *(undefined1 *)((longlong)pppplVar14 + uVar25) = 0;

    cVar9 = FUN_1400753f0(0,&local_98);

    if (0xf < uStack_80) {

      pppplVar14 = (longlong ****)local_98;

      if ((0xfff < uStack_80 + 1) &&

         (pppplVar14 = (longlong ****)local_98[-1],

         0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)pppplVar14)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(pppplVar14);

    }

    if (cVar9 != '\0') {

      iVar10 = FUN_140075da0();

      uVar5 = _UNK_14039caa8;

      uVar4 = _DAT_14039caa0;

      iVar22 = 0;

      if (0 < iVar10) {

        do {

          FUN_1400760f0(&local_98,&DAT_1403f11a0 + (longlong)iVar22 * 4);

          if (0xf < uStack_80) {

            if ((0xfff < uStack_80 + 1) &&

               (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          FUN_1400279c0(&local_78);

          pppplVar6 = DAT_1403f2fd8;

          pppplVar14 = (longlong ****)DAT_1403f2fd8[1];

          cVar9 = *(char *)((longlong)pppplVar14 + 0x19);

          pppplVar3 = pppplVar14;

          local_58 = iVar22;

          uVar7 = 0;

          pppplVar1 = DAT_1403f2fd8;

          uVar17 = (uint)uStack_90;

          while (uStack_90._0_4_ = uVar7, pppplVar2 = pppplVar14, cVar9 == '\0') {

            uStack_90._0_4_ = uVar17;

            bVar8 = FUN_140046de0(pppplVar2 + 4,&local_78);

            pppplVar14 = pppplVar2 + 2;

            if (bVar8 == 0) {

              pppplVar14 = pppplVar2;

              pppplVar1 = pppplVar2;

            }

            cVar9 = *(char *)((longlong)*pppplVar14 + 0x19);

            pppplVar14 = (longlong ****)*pppplVar14;

            pppplVar3 = pppplVar2;

            uVar7 = bVar8 ^ 1;

            uVar17 = (uint)uStack_90;

          }

          local_98 = (longlong ***)pppplVar3;

          if ((*(char *)((longlong)pppplVar1 + 0x19) != '\0') ||

             (cVar9 = FUN_140046de0(&local_78,pppplVar1 + 4), cVar9 != '\0')) {

            if (DAT_1403f2fe0 == 0x38e38e38e38e38e) {

                    /* WARNING: Subroutine does not return */

              FUN_1400478f0();

            }

            puVar13 = (undefined8 *)FUN_1402c704c(0x48);

            puVar13[4] = CONCAT71(uStack_77,local_78);

            puVar13[5] = uStack_70;

            *(undefined4 *)(puVar13 + 6) = (undefined4)local_68;

            *(undefined4 *)((longlong)puVar13 + 0x34) = local_68._4_4_;

            *(undefined4 *)(puVar13 + 7) = (undefined4)uStack_60;

            *(undefined4 *)((longlong)puVar13 + 0x3c) = uStack_60._4_4_;

            local_68 = uVar4;

            uStack_60 = uVar5;

            local_78 = 0;

            *(int *)(puVar13 + 8) = iVar22;

            *puVar13 = pppplVar6;

            puVar13[1] = pppplVar6;

            puVar13[2] = pppplVar6;

            *(undefined2 *)(puVar13 + 3) = 0;

            FUN_140047690(&DAT_1403f2fd8,&local_98);

          }

          FUN_140027900(&local_78);

          iVar22 = iVar22 + 1;

        } while (iVar22 < iVar10);

      }

    }

  }

  else {

    _Str = pcVar19;

    pcVar26 = pcVar19;

    if (0 < local_res8[0]) {

      do {

        iVar10 = (int)pcVar26;

        if (0xef < iVar10) break;

        iVar22 = (int)pcVar19;

        if (iVar22 < local_res8[0]) {

          pbVar15 = (byte *)(iVar22 + lVar11);

          do {

            if ((*pbVar15 < 0x3c) &&

               ((0x800100000002000U >> ((longlong)(char)*pbVar15 & 0x3fU) & 1) != 0)) break;

            uVar17 = (int)pcVar19 + 1;

            pcVar19 = (char *)(ulonglong)uVar17;

            pbVar15 = pbVar15 + 1;

          } while ((int)uVar17 < local_res8[0]);

        }

        iVar18 = (int)pcVar19;

        cVar9 = *(char *)(iVar18 + lVar11);

        if (cVar9 == ';') break;

        if ((iVar22 < iVar18) && (*(char *)(iVar22 + lVar11) == 'G')) {

          _Str = (char *)(lVar11 + 2 + (longlong)iVar22);

        }

        if (cVar9 == ',') {

          *(undefined1 *)(iVar18 + lVar11) = 0;

          pcVar19 = (char *)(ulonglong)(iVar18 + 1);

          if (_Str != (char *)0x0) {

            pcVar26 = (char *)(ulonglong)(iVar10 + 1);

            sVar12 = strlen(_Str);

            FUN_140027f50(&DAT_1403f11a0 + (longlong)iVar10 * 4,_Str,sVar12);

          }

        }

        uVar17 = (uint)pcVar19;

        if ((int)uVar17 < local_res8[0]) {

          pcVar16 = (char *)((int)uVar17 + lVar11);

          do {

            uVar17 = (uint)pcVar19;

            if (*pcVar16 == '\r') break;

            uVar17 = uVar17 + 1;

            pcVar19 = (char *)(ulonglong)uVar17;

            pcVar16 = pcVar16 + 1;

          } while ((int)uVar17 < local_res8[0]);

        }

        *(undefined1 *)((int)uVar17 + lVar11) = 0;

        *(undefined1 *)((longlong)(int)uVar17 + 1 + lVar11) = 0;

        pcVar19 = (char *)(ulonglong)(uVar17 + 2);

      } while ((int)(uVar17 + 2) < local_res8[0]);

    }

    uVar25 = 0xf;

    FUN_1400c4de0(lVar11);

    uVar5 = _UNK_14039caa8;

    uVar4 = _DAT_14039caa0;

    uVar24 = 0;

    do {

      iVar10 = (int)uVar24;

      FUN_1400279c0(&local_78,&DAT_1403f11a0 + uVar24 * 4);

      pppplVar6 = DAT_1403f2fd8;

      pppplVar14 = (longlong ****)DAT_1403f2fd8[1];

      uVar17 = 0;

      cVar9 = *(char *)((longlong)pppplVar14 + 0x19);

      local_58 = iVar10;

      pppplVar3 = pppplVar14;

      pppplVar1 = DAT_1403f2fd8;

      while (pppplVar2 = pppplVar14, cVar9 == '\0') {

        bVar8 = FUN_140046de0(pppplVar2 + 4,&local_78);

        uVar17 = bVar8 ^ 1;

        pppplVar14 = pppplVar2 + 2;

        if (bVar8 == 0) {

          pppplVar14 = pppplVar2;

          pppplVar1 = pppplVar2;

        }

        cVar9 = *(char *)((longlong)*pppplVar14 + 0x19);

        pppplVar14 = (longlong ****)*pppplVar14;

        pppplVar3 = pppplVar2;

      }

      uStack_90._4_4_ = (undefined4)(uStack_90 >> 0x20);

      uStack_90 = CONCAT44(uStack_90._4_4_,uVar17);

      local_98 = (longlong ***)pppplVar3;

      if ((*(char *)((longlong)pppplVar1 + 0x19) != '\0') ||

         (cVar9 = FUN_140046de0(&local_78,pppplVar1 + 4), cVar9 != '\0')) {

        if (DAT_1403f2fe0 == 0x38e38e38e38e38e) {

                    /* WARNING: Subroutine does not return */

          FUN_1400478f0();

        }

        puVar13 = (undefined8 *)FUN_1402c704c(0x48);

        puVar13[4] = CONCAT71(uStack_77,local_78);

        puVar13[5] = uStack_70;

        *(undefined4 *)(puVar13 + 6) = (undefined4)local_68;

        *(undefined4 *)((longlong)puVar13 + 0x34) = local_68._4_4_;

        *(undefined4 *)(puVar13 + 7) = (undefined4)uStack_60;

        *(undefined4 *)((longlong)puVar13 + 0x3c) = uStack_60._4_4_;

        local_68 = uVar4;

        uStack_60 = uVar5;

        local_78 = 0;

        *(int *)(puVar13 + 8) = iVar10;

        *puVar13 = pppplVar6;

        puVar13[1] = pppplVar6;

        puVar13[2] = pppplVar6;

        *(undefined2 *)(puVar13 + 3) = 0;

        FUN_140047690(&DAT_1403f2fd8,&local_98,puVar13);

      }

      uVar20 = 0;

      FUN_140027900(&local_78);

      uVar24 = (ulonglong)(iVar10 + 1U);

    } while ((int)(iVar10 + 1U) < 0xf0);

    FUN_1400755a0(0xffffffff);

    FUN_140075670(0xf0);

    puVar13 = &DAT_1403f11a0;

    do {

      local_98 = (longlong ***)0x0;

      uStack_90 = 0;

      local_88 = 0;

      uStack_80 = 0;

      puVar23 = &DAT_1403f11a0 + uVar20 * 4;

      if (0xf < (ulonglong)puVar13[3]) {

        puVar23 = (undefined8 *)*puVar13;

      }

      uVar24 = puVar13[2];

      if (0x7fffffffffffffff < uVar24) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      if (uVar24 < 0x10) {

        uStack_80 = 0xf;

        local_98 = (longlong ***)*puVar23;

        uStack_90 = puVar23[1];

        local_88 = uVar24;

      }

      else {

        uVar21 = uVar24 | 0xf;

        if (uVar21 < 0x8000000000000000) {

          if (uVar21 < 0x16) {

            uVar21 = 0x16;

          }

        }

        else {

          uVar21 = 0x7fffffffffffffff;

        }

        local_98 = (longlong ***)FUN_1400285e0(uVar21 + 1);

        local_88 = uVar24;

        uStack_80 = uVar21;

        FUN_1402f8e20(local_98,puVar23,uVar24 + 1);

      }

      FUN_140075850(&local_98);

      uVar17 = (int)uVar20 + 1;

      uVar20 = (ulonglong)uVar17;

      puVar13 = puVar13 + 4;

    } while ((int)uVar17 < 0xf0);

    puVar13 = (undefined8 *)FUN_1400c4e00();

    lVar11 = puVar13[2];

    if (0x7fffffffffffffffU - lVar11 < 9) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    if (0xf < (ulonglong)puVar13[3]) {

      puVar13 = (undefined8 *)*puVar13;

    }

    local_98 = (longlong ***)0x0;

    uStack_90 = 0;

    local_88 = 0;

    uStack_80 = 0;

    uVar24 = lVar11 + 9;

    pppplVar14 = &local_98;

    if (0xf < uVar24) {

      uVar25 = uVar24 | 0xf;

      if (uVar25 < 0x8000000000000000) {

        if (uVar25 < 0x16) {

          uVar25 = 0x16;

        }

      }

      else {

        uVar25 = 0x7fffffffffffffff;

      }

      pppplVar14 = (longlong ****)FUN_1400285e0(uVar25 + 1);

      local_98 = (longlong ***)pppplVar14;

    }

    local_88 = uVar24;

    uStack_80 = uVar25;

    FUN_1402f8e20(pppplVar14,puVar13);

    *(undefined8 *)((longlong)pppplVar14 + lVar11) = s_genes_dat_14030cc40._0_8_;

    *(char *)((longlong)pppplVar14 + lVar11 + 8) = s_genes_dat_14030cc40[8];

    *(undefined1 *)((longlong)pppplVar14 + uVar24) = 0;

    FUN_1400755f0(&local_98);

    if (0xf < uStack_80) {

      if ((0xfff < uStack_80 + 1) &&

         (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}




