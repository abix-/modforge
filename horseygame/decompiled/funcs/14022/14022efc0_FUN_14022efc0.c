// Address: 0x14022efc0
// Ghidra name: FUN_14022efc0
// ============ 0x14022efc0 FUN_14022efc0 (size=2115) ============


undefined8

FUN_14022efc0(int param_1,char *param_2,longlong param_3,byte param_4,code *param_5,

             undefined8 param_6,char *param_7,char *param_8,char *param_9,FARPROC param_10,

             uint param_11)



{

  int iVar1;

  HRESULT HVar2;

  undefined4 uVar3;

  HMODULE hModule;

  longlong lVar4;

  size_t sVar5;

  FARPROC *ppFVar6;

  INT_PTR IVar7;

  undefined8 uVar8;

  FARPROC *ppFVar9;

  longlong lVar10;

  FARPROC pFVar11;

  short sVar12;

  IID *rclsid;

  uint uVar13;

  FARPROC *ppFVar14;

  FARPROC *ppFVar15;

  ulonglong uVar16;

  code *pcVar17;

  char cVar18;

  FARPROC *ppFVar19;

  uint local_res8 [2];

  FARPROC *local_c8;

  longlong local_c0;

  longlong *local_b8;

  FARPROC *local_b0;

  uint local_a8 [2];

  LPVOID local_a0;

  uint local_98 [2];

  longlong *local_90;

  longlong *local_88;

  longlong local_80;

  FARPROC *local_78;

  FARPROC local_70;

  undefined8 local_68;

  longlong *local_60;

  longlong local_58;

  longlong *local_50;

  longlong *local_48 [2];

  

  ppFVar14 = (FARPROC *)0x0;

  local_res8[0] = 0;

  local_b8 = (longlong *)0x0;

  local_50 = (longlong *)0x0;

  local_88 = (longlong *)0x0;

  if (param_1 != 1) {

    local_res8[0] = (uint)param_4;

  }

  local_60 = (longlong *)0x0;

  local_90 = (longlong *)0x0;

  local_48[0] = (longlong *)0x0;

  ppFVar19 = (FARPROC *)0x0;

  local_a0 = (LPVOID)0x0;

  local_c8 = (FARPROC *)0x0;

  uVar8 = 0;

  local_78 = (FARPROC *)0x0;

  local_58 = 0;

  local_80 = 0;

  local_c0 = 0;

  local_b0 = (FARPROC *)0x0;

  hModule = GetModuleHandleW(L"shell32.dll");

  ppFVar15 = ppFVar14;

  if ((hModule == (HMODULE)0x0) ||

     (local_70 = GetProcAddress(hModule,"SHCreateItemFromParsingName"), ppFVar15 = (FARPROC *)0x0,

     local_70 == (FARPROC)0x0)) {

LAB_14022f6e6:

    local_c8 = ppFVar15;

    local_c0 = 0;

    ppFVar6 = (FARPROC *)0x0;

    ppFVar15 = ppFVar19;

    goto LAB_14022f6e9;

  }

  uVar16 = (ulonglong)(int)param_11;

  if ((param_10 != (FARPROC)0x0) && (0 < (int)param_11)) {

    local_c8 = (FARPROC *)FUN_1401841a0(0x10);

    ppFVar15 = local_c8;

    if (local_c8 == (FARPROC *)0x0) goto LAB_14022f6e6;

    if (param_11 != 0) {

      do {

        *ppFVar15 = param_10;

        lVar4 = FUN_14012fd40(param_10);

        param_10 = param_10 + lVar4 * 2 + 2;

        ppFVar15[1] = param_10;

        lVar4 = FUN_14012fd40(param_10);

        param_10 = param_10 + lVar4 * 2 + 2;

        uVar16 = uVar16 - 1;

        ppFVar15 = ppFVar15 + 2;

      } while (uVar16 != 0);

      uVar16 = (ulonglong)param_11;

    }

  }

  ppFVar9 = (FARPROC *)0x0;

  ppFVar15 = local_c8;

  if (param_7 != (char *)0x0) {

    sVar5 = strlen(param_7);

    local_58 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_7,sVar5 + 1);

    if (local_58 == 0) goto LAB_14022f6e6;

  }

  if (param_8 != (char *)0x0) {

    sVar5 = strlen(param_8);

    local_80 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_8,sVar5 + 1);

    if (local_80 == 0) goto LAB_14022f6e6;

  }

  ppFVar15 = ppFVar14;

  if (param_9 != (char *)0x0) {

    sVar5 = strlen(param_9);

    local_c0 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_9,sVar5 + 1);

    ppFVar6 = ppFVar14;

    if (local_c0 == 0) goto LAB_14022f6e9;

  }

  if (param_2 == (char *)0x0) {

    ppFVar15 = (FARPROC *)0x0;

  }

  else {

    sVar5 = strlen(param_2);

    ppFVar6 = (FARPROC *)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_2,sVar5 + 1);

    local_b0 = ppFVar6;

    if (ppFVar6 == (FARPROC *)0x0) goto LAB_14022f6e9;

    sVar12 = *(short *)ppFVar6;

    ppFVar15 = ppFVar6;

    ppFVar19 = ppFVar14;

    if (sVar12 != 0) {

      do {

        if ((sVar12 == 0x2f) || (sVar12 == 0x5c)) {

          ppFVar19 = ppFVar15;

        }

        sVar12 = *(short *)((longlong)ppFVar15 + 2);

        ppFVar15 = (FARPROC *)((longlong)ppFVar15 + 2);

      } while (sVar12 != 0);

      if (ppFVar19 != (FARPROC *)0x0) {

        *(short *)ppFVar19 = 0;

        lVar4 = FUN_14012fd40((FARPROC *)((longlong)ppFVar19 + 2));

        ppFVar15 = ppFVar6;

        ppFVar19 = (FARPROC *)((longlong)ppFVar19 + 2);

        if (lVar4 == 0) {

          ppFVar19 = (FARPROC *)0x0;

        }

        goto LAB_14022f22c;

      }

    }

    local_b0 = (FARPROC *)0x0;

    ppFVar15 = (FARPROC *)0x0;

    ppFVar19 = ppFVar6;

  }

LAB_14022f22c:

  ppFVar6 = ppFVar15;

  iVar1 = FUN_1401a9610();

  ppFVar15 = ppFVar19;

  if (iVar1 < 0) goto LAB_14022f6e9;

  rclsid = (IID *)&DAT_140357c80;

  if (param_1 == 1) {

    rclsid = (IID *)&DAT_140357c90;

  }

  HVar2 = CoCreateInstance(rclsid,(LPUNKNOWN)0x0,1,(IID *)&DAT_140357ca0,&local_b8);

  if ((((-1 < HVar2) &&

       (iVar1 = (**(code **)*local_b8)(local_b8,&DAT_140357cb0,&local_88), -1 < iVar1)) &&

      ((cVar18 = (char)local_res8[0], cVar18 == '\0' ||

       (iVar1 = (**(code **)*local_b8)(local_b8,&DAT_140357cc0,&local_50), -1 < iVar1)))) &&

     (iVar1 = (**(code **)(*local_88 + 0x50))(local_88,local_a8), -1 < iVar1)) {

    uVar13 = local_a8[0] | 8;

    if (cVar18 != '\0') {

      uVar13 = local_a8[0] | 0x208;

    }

    if (param_1 == 1) {

      local_a8[0] = uVar13 | 2;

    }

    else {

      local_a8[0] = uVar13;

      if (param_1 == 2) {

        local_a8[0] = uVar13 | 0x20;

      }

    }

    iVar1 = (**(code **)(*local_88 + 0x48))();

    if ((((((-1 < iVar1) &&

           ((local_c0 == 0 || (iVar1 = (**(code **)(*local_88 + 0xd8))(), -1 < iVar1)))) &&

          ((local_80 == 0 || (iVar1 = (**(code **)(*local_b8 + 0x90))(), -1 < iVar1)))) &&

         (((lVar4 = local_58, local_58 == 0 ||

           (iVar1 = (**(code **)(*local_b8 + 0x88))(local_b8,local_58), -1 < iVar1)) &&

          ((local_c8 == (FARPROC *)0x0 ||

           (iVar1 = (**(code **)(*local_b8 + 0x20))(local_b8,uVar16 & 0xffffffff), -1 < iVar1))))))

        && ((ppFVar6 == (FARPROC *)0x0 ||

            ((IVar7 = (*local_70)(ppFVar6,0,&DAT_140398d88,local_48), -1 < (int)IVar7 &&

             (iVar1 = (**(code **)(*local_b8 + 0x60))(local_b8,local_48[0]), -1 < iVar1)))))) &&

       ((ppFVar19 == (FARPROC *)0x0 ||

        (iVar1 = (**(code **)(*local_b8 + 0x78))(local_b8,ppFVar19), -1 < iVar1)))) {

      if (param_3 == 0) {

        uVar8 = 0;

        pcVar17 = *(code **)(*local_b8 + 0x18);

      }

      else {

        uVar3 = FUN_14016ea50(param_3);

        uVar8 = FUN_140174d30(uVar3,"SDL.window.win32.hwnd",0);

        pcVar17 = *(code **)(*local_b8 + 0x18);

      }

      iVar1 = (*pcVar17)(local_b8,uVar8);

      if (iVar1 == -0x7ff8fb39) {

        local_70 = (FARPROC)0x0;

        iVar1 = (**(code **)(*local_b8 + 0x30))(local_b8,local_res8);

        ppFVar9 = ppFVar14;

        if (-1 < iVar1) {

          ppFVar9 = &local_70;

          uVar13 = local_res8[0];

LAB_14022f46a:

          (*param_5)(param_6,ppFVar9,uVar13 - 1);

          uVar8 = 1;

          goto LAB_14022f477;

        }

      }

      else if (-1 < iVar1) {

        if (cVar18 == '\0') {

          iVar1 = (**(code **)(*local_b8 + 0xa0))(local_b8,&local_90);

          if (((-1 < iVar1) &&

              (iVar1 = (**(code **)(*local_b8 + 0x30))(local_b8,local_res8), -1 < iVar1)) &&

             (iVar1 = (**(code **)(*local_90 + 0x28))(local_90,0x80058000,&local_a0), -1 < iVar1)) {

            lVar10 = FUN_14012fd40(local_a0);

            pFVar11 = (FARPROC)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_a0,lVar10 * 2 + 2);

            ppFVar6 = local_b0;

            if (pFVar11 != (FARPROC)0x0) {

              local_68 = 0;

              local_70 = pFVar11;

              (*param_5)(param_6,&local_70,local_res8[0] - 1);

              uVar8 = 1;

              FUN_1401841e0(pFVar11);

              goto LAB_14022f477;

            }

          }

        }

        else {

          iVar1 = (**(code **)(*local_50 + 0xd8))(local_50,&local_60);

          if (((-1 < iVar1) &&

              (iVar1 = (**(code **)(*local_b8 + 0x30))(local_b8,&local_70), -1 < iVar1)) &&

             ((iVar1 = (**(code **)(*local_60 + 0x38))(local_60,local_98), -1 < iVar1 &&

              (ppFVar9 = (FARPROC *)FUN_1401841a0(local_98[0] + 1,8), ppFVar9 != (FARPROC *)0x0))))

          {

            uVar13 = 0;

            ppFVar14 = ppFVar9;

            local_78 = ppFVar9;

            if (local_98[0] != 0) {

              do {

                iVar1 = (**(code **)(*local_60 + 0x40))(local_60,uVar13,&local_90);

                ppFVar6 = local_b0;

                if ((iVar1 < 0) ||

                   (iVar1 = (**(code **)(*local_90 + 0x28))(local_90,0x80058000,&local_a0),

                   ppFVar6 = local_b0, iVar1 < 0)) goto LAB_14022f684;

                lVar10 = FUN_14012fd40(local_a0);

                pFVar11 = (FARPROC)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_a0,lVar10 * 2 + 2);

                *ppFVar14 = pFVar11;

                ppFVar14 = ppFVar14 + 1;

                CoTaskMemFree(local_a0);

                local_a0 = (LPVOID)0x0;

                (**(code **)(*local_90 + 0x10))();

                uVar13 = uVar13 + 1;

                local_90 = (longlong *)0x0;

              } while (uVar13 < local_98[0]);

            }

            uVar13 = (uint)local_70;

            goto LAB_14022f46a;

          }

        }

      }

LAB_14022f684:

      local_b0 = ppFVar6;

      local_78 = ppFVar9;

      local_58 = lVar4;

      FUN_1401a9ed0("dialog");

      (*param_5)(param_6,0,0xffffffff);

      uVar8 = 1;

      CoUninitialize();

      goto LAB_14022f6e9;

    }

  }

LAB_14022f477:

  CoUninitialize();

  ppFVar6 = local_b0;

LAB_14022f6e9:

  if (local_50 != (longlong *)0x0) {

    (**(code **)(*local_50 + 0x10))();

  }

  if (local_88 != (longlong *)0x0) {

    (**(code **)(*local_88 + 0x10))();

  }

  if (local_b8 != (longlong *)0x0) {

    (**(code **)(*local_b8 + 0x10))();

  }

  if (local_90 != (longlong *)0x0) {

    (**(code **)(*local_90 + 0x10))();

  }

  if (local_48[0] != (longlong *)0x0) {

    (**(code **)(*local_48[0] + 0x10))();

  }

  if (local_60 != (longlong *)0x0) {

    (**(code **)(*local_60 + 0x10))();

  }

  if (local_a0 != (LPVOID)0x0) {

    CoTaskMemFree(local_a0);

  }

  if (ppFVar6 == (FARPROC *)0x0) {

    ppFVar6 = ppFVar15;

  }

  FUN_1401841e0(ppFVar6);

  FUN_1401841e0(local_58);

  FUN_1401841e0(local_80);

  FUN_1401841e0(local_c0);

  FUN_1401841e0(local_c8);

  ppFVar14 = local_78;

  if (local_78 != (FARPROC *)0x0) {

    pFVar11 = *local_78;

    ppFVar15 = local_78;

    while (pFVar11 != (FARPROC)0x0) {

      FUN_1401841e0();

      ppFVar19 = ppFVar15 + 1;

      ppFVar15 = ppFVar15 + 1;

      pFVar11 = *ppFVar19;

    }

    FUN_1401841e0(ppFVar14);

  }

  return uVar8;

}




