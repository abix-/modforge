// Address: 0x14021fb40
// Ghidra name: FUN_14021fb40
// ============ 0x14021fb40 FUN_14021fb40 (size=1034) ============


ulonglong FUN_14021fb40(uint *param_1,undefined4 *param_2)



{

  int *piVar1;

  longlong lVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  ulonglong uVar6;

  HMODULE pHVar7;

  size_t sVar8;

  undefined8 uVar9;

  char *_Str;

  INT_PTR IVar10;

  undefined8 *puVar11;

  uint uVar12;

  uint uVar13;

  ulonglong uVar14;

  undefined4 uVar15;

  ulonglong uVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  undefined4 local_res8;

  int local_res18 [2];

  longlong local_res20;

  ulonglong local_128;

  HMODULE local_120;

  undefined8 local_118;

  undefined8 local_110;

  INT_PTR local_108;

  undefined8 local_100;

  FARPROC local_f8;

  FARPROC local_f0;

  undefined4 local_e8;

  ulonglong local_e4;

  undefined8 local_dc;

  undefined8 local_d4;

  undefined8 local_cc;

  ulonglong local_c4;

  undefined8 local_bc;

  undefined8 local_b4;

  uint local_ac;

  longlong local_a8;

  int local_a0;

  undefined8 local_9c;

  undefined8 uStack_94;

  undefined8 local_8c;

  undefined8 uStack_84;

  undefined8 local_7c;

  undefined8 uStack_74;

  undefined8 local_6c;

  undefined8 uStack_64;

  undefined8 local_5c;

  undefined8 uStack_54;

  undefined4 local_4c;

  

  uVar6 = 0;

  local_128 = 0;

  local_100 = 0;

  if (0x1555555555555555 < (ulonglong)(longlong)(int)param_1[8]) {

    uVar6 = FUN_14012e770();

    return uVar6;

  }

  pHVar7 = GetModuleHandleW(L"user32.dll");

  local_f0 = GetProcAddress(pHVar7,"SetThreadDpiAwarenessContext");

  local_108 = -1;

  if (local_f0 != (FARPROC)0x0) {

    local_108 = (*local_f0)(0xfffffffffffffffc);

  }

  pHVar7 = LoadLibraryW(L"comctl32.dll");

  local_120 = pHVar7;

  if (pHVar7 != (HMODULE)0x0) {

    local_f8 = GetProcAddress(pHVar7,"TaskDialogIndirect");

    if (local_f8 == (FARPROC)0x0) {

      FreeLibrary(pHVar7);

    }

    else {

      uVar14 = uVar6;

      if (*(longlong *)(param_1 + 2) != 0) {

        uVar14 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_1 + 2) + 0x188) + 8);

      }

      sVar8 = strlen(*(char **)(param_1 + 6));

      uVar9 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,*(undefined8 *)(param_1 + 6),sVar8 + 1);

      local_118 = uVar9;

      sVar8 = strlen(*(char **)(param_1 + 4));

      local_110 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,*(undefined8 *)(param_1 + 4),sVar8 + 1);

      uVar12 = *param_1;

      local_dc = 0;

      local_d4 = 0x1000000;

      local_bc = 0;

      local_a8 = 0;

      local_4c = 0;

      local_e8 = 0xa0;

      local_9c = 0;

      uStack_94 = 0;

      local_8c = 0;

      uStack_84 = 0;

      local_7c = 0;

      uStack_74 = 0;

      local_6c = 0;

      uStack_64 = 0;

      local_5c = 0;

      uStack_54 = 0;

      if ((uVar12 & 0x10) == 0) {

        if ((uVar12 & 0x20) == 0) {

          local_c4 = (ulonglong)(-(uint)((uVar12 & 0x40) != 0) & 0xfffd);

        }

        else {

          local_c4 = 0xffff;

        }

      }

      else {

        local_c4 = 0xfffe;

      }

      local_ac = param_1[8];

      local_e4 = uVar14;

      local_cc = local_110;

      local_b4 = uVar9;

      local_res20 = FUN_1401841f0((longlong)(int)local_ac * 0xc);

      uVar12 = param_1[8];

      local_a0 = 0;

      local_res8 = 0;

      uVar14 = uVar6;

      uVar16 = uVar6;

      uVar18 = uVar6;

      uVar17 = uVar6;

      uVar15 = 0;

      if (0 < (int)uVar12) {

        do {

          uVar13 = (uint)uVar14;

          uVar4 = uVar13;

          if ((*param_1 & 0x80) == 0) {

            uVar4 = ~uVar13 + uVar12;

          }

          piVar1 = (int *)(local_res20 + (longlong)(int)uVar4 * 0xc);

          if ((*(byte *)(uVar17 + *(longlong *)(param_1 + 10)) & 2) == 0) {

            iVar5 = uVar13 + 100;

          }

          else {

            local_res8 = *(undefined4 *)(uVar17 + 4 + *(longlong *)(param_1 + 10));

            iVar5 = 2;

          }

          *piVar1 = iVar5;

          _Str = (char *)FUN_14021f6b0(&local_128,&local_100,

                                       *(undefined8 *)(uVar17 + 8 + *(longlong *)(param_1 + 10)));

          if (_Str == (char *)0x0) {

            FreeLibrary(local_120);

            FUN_1401841e0(local_128);

            FUN_1401841e0(local_118);

            FUN_1401841e0(local_110);

            lVar2 = local_res20;

            if (0 < (longlong)uVar16) {

              puVar11 = (undefined8 *)(local_res20 + 4);

              do {

                FUN_1401841e0(*puVar11);

                puVar11 = (undefined8 *)((longlong)puVar11 + 0xc);

                uVar16 = uVar16 - 1;

              } while (uVar16 != 0);

            }

            uVar6 = FUN_1401841e0(lVar2);

            return uVar6 & 0xffffffffffffff00;

          }

          sVar8 = strlen(_Str);

          uVar9 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,_Str,sVar8 + 1);

          *(undefined8 *)(piVar1 + 1) = uVar9;

          if ((*(byte *)(uVar17 + *(longlong *)(param_1 + 10)) & 1) != 0) {

            local_a0 = *piVar1;

          }

          uVar12 = param_1[8];

          uVar14 = (ulonglong)(uVar13 + 1);

          uVar16 = uVar16 + 1;

          uVar17 = uVar17 + 0x10;

          uVar18 = local_128;

          uVar15 = local_res8;

        } while ((int)(uVar13 + 1) < (int)uVar12);

      }

      lVar2 = local_res20;

      local_a8 = local_res20;

      IVar10 = (*local_f8)(&local_e8,local_res18,0,0);

      FreeLibrary(local_120);

      FUN_1401841e0(uVar18);

      FUN_1401841e0(local_118);

      FUN_1401841e0(local_110);

      if (0 < (int)param_1[8]) {

        puVar11 = (undefined8 *)(lVar2 + 4);

        do {

          FUN_1401841e0(*puVar11);

          uVar12 = (int)uVar6 + 1;

          uVar6 = (ulonglong)uVar12;

          puVar11 = (undefined8 *)((longlong)puVar11 + 0xc);

        } while ((int)uVar12 < (int)param_1[8]);

      }

      FUN_1401841e0(lVar2);

      if (-1 < (int)IVar10) {

        if (local_res18[0] != 2) {

          if ((99 < local_res18[0]) && (local_res18[0] < (int)(param_1[8] + 100))) {

            bVar3 = 1;

            *param_2 = *(undefined4 *)

                        (*(longlong *)(param_1 + 10) + 4 + (longlong)(local_res18[0] + -100) * 0x10)

            ;

            goto LAB_14021ff16;

          }

          uVar15 = 0xffffffff;

        }

        bVar3 = 1;

        *param_2 = uVar15;

        goto LAB_14021ff16;

      }

    }

  }

  bVar3 = FUN_14021ff50(param_1,param_2);

LAB_14021ff16:

  if (local_f0 != (FARPROC)0x0) {

    (*local_f0)(local_108);

  }

  return (ulonglong)bVar3;

}




