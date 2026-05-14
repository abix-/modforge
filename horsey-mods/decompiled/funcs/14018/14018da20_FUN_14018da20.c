// Address: 0x14018da20
// Ghidra name: FUN_14018da20
// ============ 0x14018da20 FUN_14018da20 (size=7970) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



LRESULT FUN_14018da20(HWND param_1,UINT param_2,HDROP param_3,POINT param_4)



{

  longlong *plVar1;

  byte bVar2;

  code *pcVar3;

  WNDPROC lpPrevWndFunc;

  undefined2 uVar4;

  char cVar5;

  ushort uVar6;

  DWORD DVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  LONG LVar11;

  uint uVar12;

  undefined4 uVar13;

  int iVar14;

  BOOL BVar15;

  int iVar16;

  DWORD DVar17;

  int iVar18;

  UINT UVar19;

  UINT UVar20;

  longlong *plVar21;

  LRESULT LVar22;

  ulonglong uVar23;

  HBRUSH hbr;

  HDC hDC;

  HMONITOR hMonitor;

  longlong lVar24;

  undefined1 *puVar25;

  longlong lVar26;

  LPARAM LVar27;

  HMENU pHVar28;

  POINT PVar29;

  LPWSTR lpszFile;

  undefined8 uVar30;

  HCURSOR hCursor;

  undefined1 *puVar31;

  undefined1 *puVar32;

  LONG LVar33;

  LRESULT LVar34;

  byte *pbVar35;

  undefined8 uVar36;

  char *pcVar37;

  short sVar38;

  short sVar39;

  UINT iFile;

  bool bVar40;

  float fVar41;

  float fVar42;

  float fVar43;

  HWND local_res8;

  UINT local_res10 [2];

  HDROP local_res18;

  POINT local_res20;

  undefined1 auStackY_1c8 [32];

  bool local_188 [8];

  POINT local_180;

  undefined8 uStack_178;

  undefined1 local_170 [8];

  tagPOINT tStack_168;

  uint local_160 [2];

  tagPOINT local_158;

  undefined8 uStack_150;

  int local_148;

  int local_144;

  int local_140;

  int local_13c;

  tagMONITORINFO local_138;

  tagPAINTSTRUCT local_108;

  uint local_a8;

  uint local_a4;

  

  puVar31 = auStackY_1c8;

  puVar25 = auStackY_1c8;

  LVar34 = -1;

  local_res8 = param_1;

  local_res10[0] = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  plVar21 = (longlong *)FUN_14018c660();

  if (plVar21 == (longlong *)0x0) {

    plVar21 = GetPropW(param_1,L"SDL_WindowData");

  }

  puVar32 = auStackY_1c8;

  if (plVar21 == (longlong *)0x0) goto LAB_14018da9d;

  if (((DAT_1403fcba8 != 0) && ((int)plVar21[0xe] != 0)) &&

     (cVar5 = FUN_14018b610(&local_res8,local_res10,&local_res18,&local_res20),

     param_3 = local_res18, param_2 = local_res10[0], cVar5 == '\0')) {

    return 0;

  }

  cVar5 = FUN_140225560(param_1,param_2,param_3,&local_res20);

  PVar29 = local_res20;

  if (cVar5 != '\0') {

    return 0;

  }

  sVar38 = (short)param_3;

  if (param_2 < 0x101) {

    if (param_2 == 0x100) {

switchD_14018e5d0_caseD_104:

      cVar5 = FUN_14018bd10(param_3,local_res20);

      LVar34 = 0;

      puVar32 = auStackY_1c8;

      if (cVar5 == '\0') {

        local_188[0] = false;

        local_160[0] = local_160[0] & 0xffff0000;

        iVar14 = FUN_14018fc00(local_res20,param_3,local_160,local_188);

        if (((iVar14 == 0x3d) && (uVar6 = FUN_140183440(), (uVar6 & 0x300) != 0)) &&

           (cVar5 = FUN_14018bd00(), cVar5 != '\0')) {

          FUN_1401cda90(*plVar21,0x210,0,0);

        }

        if (((local_188[0] != false) || (*(char *)(plVar21[0x18] + 0x129) == '\0')) ||

           (*(char *)(*plVar21 + 0x138) != '\0')) {

          uVar4 = (undefined2)local_160[0];

          uVar30 = FUN_14018c5c0();

          FUN_140183990(uVar30,0,uVar4,iVar14);

          param_2 = local_res10[0];

        }

LAB_14018e6a3:

        LVar34 = 0;

        puVar32 = auStackY_1c8;

      }

    }

    else {

      puVar32 = auStackY_1c8;

      if (param_2 - 6 < 0xaa) {

        switch(param_2) {

        case 6:

          DVar7 = GetMessagePos();

          FUN_14018d730(*plVar21,sVar38 != 0,DVar7);

          break;

        case 7:

          lVar26 = *plVar21;

          DVar7 = GetMessagePos();

          FUN_14018d730(lVar26,1,DVar7);

          break;

        case 8:

          goto switchD_14018db6c_caseD_8;

        case 0xf:

          BVar15 = GetUpdateRect(param_1,(LPRECT)&local_138,0);

          if (BVar15 != 0) {

            uVar12 = GetWindowLongW(param_1,-0x14);

            if ((uVar12 >> 0x19 & 1) != 0) {

              BeginPaint(param_1,&local_108);

              EndPaint(param_1,&local_108);

            }

            ValidateRect(param_1,(RECT *)0x0);

            FUN_1401cda90(*plVar21,0x204,0,0);

          }

LAB_14018e1a7:

          LVar34 = 0;

          break;

        case 0x10:

          FUN_1401cda90(*plVar21,0x210,0,0);

          LVar34 = 0;

          break;

        case 0x14:

          cVar5 = FUN_14018bcd0(plVar21);

          if (cVar5 == '\0') {

            return 1;

          }

          *(undefined1 *)(plVar21[0x18] + 0xf8) = 1;

          GetClientRect(param_1,(LPRECT)&local_138);

          hbr = CreateSolidBrush(0);

          hDC = GetDC(param_1);

          FillRect(hDC,(RECT *)&local_138,hbr);

          DeleteObject(hbr);

          return 1;

        case 0x18:

          FUN_1401cda90(*plVar21,0x203 - (uint)(param_3 != (HDROP)0x0),0,0);

          break;

        case 0x1a:

          if (param_3 == (HDROP)0x0) {

            if ((local_res20 != (POINT)0x0) &&

               (iVar14 = FUN_14012fbc0(local_res20,L"ImmersiveColorSet"), iVar14 == 0)) {

              uVar13 = FUN_140181430();

              FUN_140170610(uVar13);

              FUN_1401a9fe0(param_1);

            }

          }

          else {

            if ((param_3 == (HDROP)0x4) || (param_3 == (HDROP)0x71)) {

              FUN_140228540();

            }

            if (param_3 == (HDROP)0x2f) {

              uVar30 = FUN_14016dcf0();

              FUN_140227370(uVar30);

            }

          }

          break;

        case 0x20:

          hCursor = DAT_1403fdc68;

          if ((short)local_res20.x != 1) {

            if ((DAT_1403e2909 != '\0') || (DAT_1403fdc68 != (HCURSOR)0x0)) break;

            hCursor = (HCURSOR)0x0;

          }

          SetCursor(hCursor);

          LVar34 = 1;

          break;

        case 0x21:

          if ((*(uint *)(*plVar21 + 0x48) & 0xc0000) != 0) {

            return 3;

          }

          for (lVar26 = *(longlong *)(*plVar21 + 0x1a8); lVar26 != 0;

              lVar26 = *(longlong *)(lVar26 + 0x1a8)) {

            if ((*(uint *)(lVar26 + 0x48) & 0x8200) == 0x8200) {

              return 3;

            }

          }

          break;

        case 0x24:

          if (*(char *)((longlong)plVar21 + 99) == '\0') {

            GetWindowRect(param_1,(LPRECT)local_170);

            uVar13 = local_170._0_4_;

            local_158.x = local_170._4_4_;

            FUN_14016ed40(*plVar21,local_160,&local_148);

            FUN_14016e450(*plVar21,&local_13c,&local_140);

            FUN_14016e3b0(*plVar21,&local_144,(tagRECT *)&local_180);

            local_13c = local_13c - local_160[0];

            local_140 = local_140 - local_148;

            iVar14 = 0;

            iVar16 = iVar14;

            if ((local_144 != 0) && (local_180.x != 0)) {

              local_144 = local_144 - local_160[0];

              local_180.x = local_180.x - local_148;

              iVar16 = 1;

            }

            uVar23 = FUN_14016e130(*plVar21);

            if (((uVar23 & 0x10) == 0) && ((*(uint *)(*plVar21 + 0x48) & 0xc0000) == 0)) {

              tStack_168.y = local_148;

              tStack_168.x = local_160[0];

              local_170._0_4_ = 0;

              local_170._4_4_ = 0;

              FUN_14022a8c0(param_1,local_170,0);

              local_160[0] = tStack_168.x - local_170._0_4_;

              local_148 = tStack_168.y - local_170._4_4_;

            }

            PVar29 = local_res20;

            uVar23 = FUN_14016e130(*plVar21);

            if ((uVar23 & 0x20) == 0) {

              *(uint *)((longlong)PVar29 + 8) = local_160[0];

              *(int *)((longlong)PVar29 + 0xc) = local_148;

              *(LONG *)((longlong)PVar29 + 0x14) = local_158.x;

              *(undefined4 *)((longlong)PVar29 + 0x10) = uVar13;

              *(uint *)((longlong)PVar29 + 0x18) = local_160[0];

              *(int *)((longlong)PVar29 + 0x1c) = local_148;

              *(uint *)((longlong)PVar29 + 0x20) = local_160[0];

              *(int *)((longlong)PVar29 + 0x24) = local_148;

            }

            else {

              uVar23 = FUN_14016e130(*plVar21);

              if ((uVar23 & 0x10) != 0) {

                uVar8 = GetSystemMetrics(0);

                iVar9 = GetSystemMetrics(1);

                uVar12 = uVar8;

                if ((int)uVar8 < (int)local_160[0]) {

                  uVar12 = local_160[0];

                }

                *(uint *)((longlong)PVar29 + 8) = uVar12;

                iVar18 = iVar9;

                if (iVar9 < local_148) {

                  iVar18 = local_148;

                }

                *(int *)((longlong)PVar29 + 0xc) = iVar18;

                iVar10 = (int)(uVar8 - local_160[0]) / 2;

                iVar18 = iVar14;

                if (iVar10 < 1) {

                  iVar18 = iVar10;

                }

                *(int *)((longlong)PVar29 + 0x10) = iVar18;

                iVar9 = (iVar9 - local_148) / 2;

                if (iVar9 < 1) {

                  iVar14 = iVar9;

                }

                *(int *)((longlong)PVar29 + 0x14) = iVar14;

              }

              *(uint *)((longlong)PVar29 + 0x18) = local_160[0] + local_13c;

              *(int *)((longlong)PVar29 + 0x1c) = local_148 + local_140;

              if (iVar16 != 0) {

                *(uint *)((longlong)PVar29 + 0x20) = local_160[0] + local_144;

                *(int *)((longlong)PVar29 + 0x24) = local_148 + local_180.x;

                LVar34 = 0;

                break;

              }

            }

            LVar34 = 0;

          }

          break;

        case 0x46:

          if (*(char *)((longlong)plVar21 + 99) == '\0') {

            if ((int)plVar21[0xe] != 0) {

              if ((*(int *)((longlong)plVar21 + 0x74) == *(int *)((longlong)local_res20 + 0x18)) &&

                 ((int)plVar21[0xf] == *(int *)((longlong)local_res20 + 0x1c))) {

                *(uint *)((longlong)local_res20 + 0x20) =

                     *(uint *)((longlong)local_res20 + 0x20) | 1;

              }

              *(int *)((longlong)plVar21 + 0x74) = *(int *)((longlong)local_res20 + 0x18);

              LVar34 = 0;

              *(int *)(plVar21 + 0xf) = *(int *)((longlong)local_res20 + 0x1c);

            }

          }

          else {

            LVar34 = 0;

          }

          break;

        case 0x47:

          LVar33 = *(LONG *)(*plVar21 + 100);

          local_180.x = LVar33;

          if ((*(byte *)((longlong)local_res20 + 0x20) & 0x40) != 0) {

            FUN_1401cda90(*plVar21,0x202,0,0);

          }

          LVar11 = IsIconic(param_1);

          local_158.x = LVar11;

          BVar15 = IsZoomed(param_1);

          lVar26 = *plVar21;

          if (LVar11 == 0) {

            if (BVar15 == 0) {

              if ((*(ulonglong *)(lVar26 + 0x48) & 0xc0) != 0) {

                FUN_1401cda90(lVar26,0x20b,0,0);

                lVar26 = *plVar21;

                if ((*(byte *)(lVar26 + 0x48) & 1) == 0) {

                  *(undefined1 *)((longlong)plVar21 + 0x6b) = 0;

                  bVar2 = *(byte *)(lVar26 + 0x48);

                  uVar30 = FUN_14016dcf0();

                  FUN_14022c540(uVar30,lVar26,bVar2 >> 5 & 1);

                  LVar11 = local_158.x;

                }

                LVar33 = local_180.x;

              }

            }

            else {

              if ((*(ulonglong *)(lVar26 + 0x48) & 0x40) != 0) {

                FUN_1401cda90(lVar26,0x20b,0,0);

              }

              FUN_1401cda90(*plVar21,0x20a,0,0);

              *(undefined1 *)((longlong)plVar21 + 0x6b) = 1;

            }

          }

          else {

            FUN_1401cda90(lVar26,0x209,0,0);

          }

          if ((*(byte *)((longlong)PVar29 + 0x20) & 0x80) != 0) {

            FUN_1401cda90(*plVar21,0x203,0,0);

          }

          if ((LVar11 == 0) && (*(char *)((longlong)plVar21 + 0x62) == '\0')) {

            if (*(char *)((longlong)plVar21 + 0x6c) == '\0') {

              BVar15 = GetClientRect(param_1,(LPRECT)local_170);

              if ((BVar15 != 0) && (cVar5 = FUN_1401aa1d0(local_170), cVar5 != '\0')) {

                ClientToScreen(param_1,(LPPOINT)local_170);

                ClientToScreen(param_1,&tStack_168);

                local_140 = local_170._0_4_;

                local_144 = local_170._4_4_;

                FUN_14016f0f0(*plVar21,(ulonglong)local_170 & 0xffffffff,local_170._4_4_,&local_140)

                ;

                FUN_1401cda90(*plVar21,0x205,local_140,local_144);

              }

              BVar15 = GetClientRect(param_1,(LPRECT)local_170);

              if ((BVar15 != 0) && (cVar5 = FUN_1401aa1d0(local_170), cVar5 != '\0')) {

                FUN_1401cda90(*plVar21,0x206,(ulonglong)tStack_168 & 0xffffffff,tStack_168.y);

              }

            }

            FUN_14022c8c0(*plVar21);

            if (*(int *)(*plVar21 + 100) != LVar33) {

              FUN_14022cbd0(*plVar21,1);

            }

            for (lVar26 = *(longlong *)(*plVar21 + 0x1b0); lVar26 != 0;

                lVar26 = *(longlong *)(lVar26 + 0x1c0)) {

              if (((*(ulonglong *)(lVar26 + 0x48) & 0xc0000) != 0) &&

                 ((*(ulonglong *)(lVar26 + 0x48) & 8) == 0)) {

                FUN_14022c420(lVar26,0x110,0);

              }

            }

          }

          break;

        case 0x51:

          FUN_140225bd0(CONCAT71((int7)((ulonglong)

                                        (IMAGE_DOS_HEADER_140000000.e_magic +

                                        (&switchD_14018db6c::switchdataD_14018f944)

                                        [(&switchD_14018db6c::switchdataD_14018f998)[param_2 - 6]])

                                       >> 8),1));

          LVar34 = 1;

          break;

        case 0x7e:

          uVar30 = FUN_14016dcf0();

          FUN_140226f30(uVar30);

          break;

        case 0x83:

          uVar23 = *(ulonglong *)(*plVar21 + 0x48);

          if (((param_3 == (HDROP)0x1) && ((uVar23 & 0x10) != 0)) && ((uVar23 & 1) == 0)) {

            BVar15 = GetWindowPlacement(param_1,(WINDOWPLACEMENT *)&local_108);

            if ((BVar15 == 0) || (local_108.fErase != 3)) {

              if ((uVar23 & 0x20) != 0) {

                return 0;

              }

              if (*(char *)((longlong)plVar21 + 0x6b) != '\0') {

                return 0;

              }

              lVar26 = *plVar21;

              bVar40 = *(char *)(lVar26 + 0x10c) == '\0';

              lVar24 = 0x98;

              if (bVar40) {

                lVar24 = 0x88;

              }

              iVar14 = *(int *)(lVar24 + lVar26);

              lVar24 = 0x94;

              if (bVar40) {

                lVar24 = 0x84;

              }

              *(int *)((longlong)PVar29 + 8) = *(int *)(lVar24 + lVar26) + *(int *)PVar29;

              *(int *)((longlong)PVar29 + 0xc) = *(int *)((longlong)PVar29 + 4) + iVar14;

              return 0;

            }

            hMonitor = MonitorFromWindow(param_1,0);

            if (hMonitor == (HMONITOR)0x0) {

              local_158 = *(POINT *)(*plVar21 + 0x6c);

              hMonitor = MonitorFromPoint(local_158,2);

              if (hMonitor == (HMONITOR)0x0) {

                return 0;

              }

            }

            local_138.rcWork.bottom = 0;

            local_138.dwFlags = 0;

            local_138.rcMonitor.left = 0;

            local_138.rcMonitor.top = 0;

            local_138.rcMonitor.right = 0;

            local_138.cbSize = 0x28;

            local_138.rcMonitor.bottom = 0;

            local_138.rcWork.left = 0;

            local_138.rcWork.top = 0;

            local_138.rcWork.right = 0;

            BVar15 = GetMonitorInfoW(hMonitor,&local_138);

            if (BVar15 == 0) {

              return 0;

            }

            *(ulonglong *)PVar29 = CONCAT44(local_138.rcWork.top,local_138.rcWork.left);

            *(ulonglong *)((longlong)PVar29 + 8) =

                 CONCAT44(local_138.rcWork.bottom,local_138.rcWork.right);

            return 0;

          }

          break;

        case 0x84:

          lVar26 = *plVar21;

          if ((*(uint *)(lVar26 + 0x48) >> 0x12 & 1) != 0) {

            return -1;

          }

          if (*(longlong *)(lVar26 + 0x160) != 0) {

            local_158.y = (int)local_res20.x._2_2_;

            local_158.x = (int)(short)local_res20.x;

            BVar15 = ScreenToClient(param_1,&local_158);

            if (BVar15 != 0) {

              local_180.x = local_158.x;

              local_180.y = local_158.y;

              uVar13 = (**(code **)(lVar26 + 0x160))

                                 (lVar26,(tagRECT *)&local_180,*(undefined8 *)(lVar26 + 0x168));

              switch(uVar13) {

              case 0:

                return 1;

              case 1:

                uVar12 = FUN_140161040(0,0);

                if ((uVar12 != 0) && ((uVar12 & 1) == 0)) {

                  FUN_140162ca0(lVar26);

                  return 1;

                }

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 2;

              case 2:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0xd;

              case 3:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0xc;

              case 4:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0xe;

              case 5:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0xb;

              case 6:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0x11;

              case 7:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0xf;

              case 8:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 0x10;

              case 9:

                FUN_1401cda90(*plVar21,0x211,0,0);

                return 10;

              }

            }

          }

          break;

        case 0x86:

          lVar26 = *plVar21;

          *(undefined2 *)((longlong)plVar21 + 0x67) = 0x101;

          DVar7 = GetMessagePos();

          FUN_14018d730(lVar26,param_3 != (HDROP)0x0,DVar7);

          puVar32 = auStackY_1c8;

          param_2 = local_res10[0];

          if ((*(byte *)(*plVar21 + 0x48) & 0x10) != 0) {

            local_res20.x = -1;

            local_res20.y = -1;

            puVar32 = auStackY_1c8;

          }

          goto switchD_14018e5d0_caseD_103;

        case 0xa1:

          *(undefined1 *)((longlong)plVar21 + 0x65) = 1;

          LVar22 = SendMessageW(param_1,0x84,(WPARAM)param_3,(LPARAM)local_res20);

          if (LVar22 == 2) {

            GetCursorPos(&local_158);

            ScreenToClient(param_1,&local_158);

            PostMessageW(param_1,0x200,0,

                         (ulonglong)(uint)((int)(short)local_158.y << 0x10 | local_158.x));

          }

          break;

        case 0xae:

        case 0xaf:

          LVar34 = (ulonglong)((*(byte *)(*plVar21 + 0x48) & 0x10) != 0) - 1;

        }

switchD_14018db6c_caseD_9:

        puVar32 = auStackY_1c8;

        param_2 = local_res10[0];

      }

    }

    goto switchD_14018e5d0_caseD_103;

  }

  if (param_2 < 0x201) {

    if (param_2 == 0x200) {

      lVar26 = *plVar21;

      if (((*(ulonglong *)(lVar26 + 0x48) >> 9 & 1) != 0) &&

         (((*(ulonglong *)(lVar26 + 0x48) & 0x8100) != 0 ||

          ((0 < *(int *)(lVar26 + 0x158) && (0 < *(int *)(lVar26 + 0x15c))))))) {

        *(undefined1 *)(plVar21 + 0xd) = 1;

      }

      if (*(char *)((longlong)plVar21 + 0xac) == '\0') {

        local_138.rcMonitor.top = (LONG)plVar21[1];

        local_138.rcMonitor.right = (LONG)((ulonglong)plVar21[1] >> 0x20);

        local_138.cbSize = 0x18;

        local_138.rcMonitor.left = 2;

        BVar15 = TrackMouseEvent((LPTRACKMOUSEEVENT)&local_138);

        if (BVar15 != 0) {

          *(undefined1 *)((longlong)plVar21 + 0xac) = 1;

        }

        uVar30 = FUN_14018c5c0();

        FUN_14018bd90(uVar30,plVar21);

      }

      if (*(char *)(plVar21[0x18] + 0x128) == '\0') {

        LVar27 = GetMessageExtraInfo();

        iVar14 = FUN_14018b9b0(LVar27);

        if ((iVar14 == 1) && (local_res20 != *(POINT *)(plVar21 + 0xb))) {

          uVar30 = FUN_14018c5c0();

          FUN_1401628f0(uVar30,lVar26,0,0);

        }

      }

      goto switchD_14018db6c_caseD_9;

    }

    puVar32 = auStackY_1c8;

    switch(param_2) {

    case 0x101:

    case 0x105:

      cVar5 = FUN_14018bd10(param_3,local_res20);

      if (cVar5 == '\0') {

        local_188[0] = false;

        local_160[0] = local_160[0] & 0xffff0000;

        iVar14 = FUN_14018fc00(local_res20,param_3,local_160,local_188);

        lVar26 = FUN_140183330(0);

        if (((local_188[0] == false) && (*(char *)(plVar21[0x18] + 0x129) != '\0')) &&

           (*(char *)(*plVar21 + 0x138) == '\0')) goto LAB_14018e6a3;

        uVar4 = (undefined2)local_160[0];

        if ((iVar14 == 0x46) && (*(char *)(lVar26 + 0x46) == '\0')) {

          uVar30 = FUN_14018c5c0();

          FUN_140183990(uVar30,0,uVar4,0x46);

        }

        uVar30 = FUN_14018c5c0();

        FUN_140183990(uVar30,0,uVar4,iVar14);

        LVar34 = 0;

        goto switchD_14018db6c_caseD_9;

      }

      LVar34 = 0;

      puVar32 = auStackY_1c8;

      break;

    case 0x102:

      cVar5 = FUN_140172fc0(*plVar21);

      PVar29 = local_180;

      sVar39 = 0;

      if (cVar5 != '\0') {

        if (param_3 + -0x3600 < (HDROP)0x400) {

          *(short *)(plVar21 + 0xc) = sVar38;

          LVar34 = 0;

          puVar32 = auStackY_1c8;

          break;

        }

        if ((short)plVar21[0xc] != 0) {

          sVar39 = sVar38;

          sVar38 = (short)plVar21[0xc];

        }

        local_180.x._2_2_ = sVar39;

        local_180.x._0_2_ = sVar38;

        local_180.y._2_2_ = PVar29.y._2_2_;

        local_180.y._0_2_ = 0;

        iVar14 = FUN_1401aa170(0xfde9,0x80,(tagRECT *)&local_180,0xffffffff);

        if (0 < iVar14) {

          FUN_140183cd0(&local_158);

        }

      }

      *(undefined2 *)(plVar21 + 0xc) = 0;

      LVar34 = 0;

      puVar32 = auStackY_1c8;

      break;

    case 0x104:

      goto switchD_14018e5d0_caseD_104;

    case 0x109:

      if (param_3 == (HDROP)0xffff) {

        LVar34 = 1;

        puVar32 = auStackY_1c8;

      }

      else {

        cVar5 = FUN_140172fc0(*plVar21);

        if (cVar5 == '\0') goto LAB_14018eb07;

        puVar25 = (undefined1 *)FUN_14012ed70((ulonglong)param_3 & 0xffffffff,&local_158);

        *puVar25 = 0;

        FUN_140183cd0(&local_158);

        LVar34 = 0;

        puVar32 = auStackY_1c8;

      }

      break;

    case 0x112:

      if ((DAT_1403fc6d9 == '\0') && (((uint)param_3 & 0xfff0) == 0xf100)) {

        return 0;

      }

      uVar12 = (uint)param_3 & 0xfff0;

      if (((uVar12 == 0xf140) || (puVar32 = auStackY_1c8, uVar12 == 0xf170)) &&

         (lVar26 = FUN_14016dcf0(), puVar32 = auStackY_1c8, *(char *)(lVar26 + 0x31a) != '\0')) {

        return 0;

      }

      break;

    case 0x113:

      puVar32 = auStackY_1c8;

      if (param_3 == (HDROP)FUN_14021a9a0) {

        FUN_14016f930(*plVar21);

        return 0;

      }

      break;

    case 0x121:

switchD_14018db6c_caseD_8:

      lVar26 = *plVar21;

      DVar7 = GetMessagePos();

      FUN_14018d730(lVar26,0,DVar7);

      goto switchD_14018db6c_caseD_9;

    }

    goto switchD_14018e5d0_caseD_103;

  }

  puVar32 = auStackY_1c8;

  switch(param_2) {

  case 0x201:

  case 0x202:

  case 0x203:

  case 0x204:

  case 0x205:

  case 0x206:

  case 0x207:

  case 0x208:

  case 0x209:

  case 0x20b:

  case 0x20c:

  case 0x20d:

    puVar32 = auStackY_1c8;

    if (*(char *)(plVar21[0x18] + 0x128) == '\0') {

      LVar27 = GetMessageExtraInfo();

      iVar14 = FUN_14018b9b0(LVar27);

      puVar32 = auStackY_1c8;

      if ((iVar14 == 1) && (puVar32 = auStackY_1c8, local_res20 != *(POINT *)(plVar21 + 0xb))) {

        uVar30 = FUN_14018c5c0();

        FUN_14018c450(uVar30,param_3,plVar21,0);

        puVar32 = auStackY_1c8;

      }

    }

    break;

  case 0x20a:

  case 0x20e:

    puVar32 = auStackY_1c8;

    if (*(char *)(plVar21[0x18] + 0x128) == '\0') {

      lVar26 = *plVar21;

      uVar30 = FUN_14018c5c0();

      if (param_2 == 0x20a) {

        FUN_1401629c0(uVar30,lVar26,0);

        puVar32 = auStackY_1c8;

      }

      else {

        FUN_1401629c0(uVar30,lVar26,0);

        puVar32 = auStackY_1c8;

      }

    }

    break;

  case 0x211:

  case 0x231:

    if ((DAT_1403fcba8 != 0) &&

       (cVar5 = FUN_14018b610(&local_res8,local_res10,&local_res18,&local_res20),

       param_3 = local_res18, param_2 = local_res10[0], cVar5 == '\0')) {

      return 0;

    }

    *(int *)(plVar21 + 0xe) = (int)plVar21[0xe] + 1;

    puVar32 = auStackY_1c8;

    if ((int)plVar21[0xe] == 1) {

      local_170._0_4_ = 0;

      local_170._4_4_ = 0;

      tStack_168.x = 0;

      tStack_168.y = 0;

      GetWindowRect((HWND)plVar21[1],(LPRECT)local_170);

      lVar26 = *plVar21;

      *(LONG *)((longlong)plVar21 + 0x74) = tStack_168.x - local_170._0_4_;

      *(LONG *)(plVar21 + 0xf) = tStack_168.y - local_170._4_4_;

      *(undefined4 *)((longlong)plVar21 + 0x7c) = *(undefined4 *)(lVar26 + 0x18);

      *(int *)((longlong)plVar21 + 0x84) = *(int *)(lVar26 + 0x20) + *(int *)(lVar26 + 0x18);

      *(undefined4 *)(plVar21 + 0x10) = *(undefined4 *)(lVar26 + 0x1c);

      *(int *)(plVar21 + 0x11) = *(int *)(lVar26 + 0x24) + *(int *)(lVar26 + 0x1c);

      SetTimer(param_1,0x14021a9a0,10,(TIMERPROC)0x0);

      FUN_1401837c0();

      puVar32 = auStackY_1c8;

    }

    break;

  case 0x212:

  case 0x232:

    plVar1 = plVar21 + 0xe;

    *(int *)plVar1 = (int)*plVar1 + -1;

    puVar32 = auStackY_1c8;

    if ((int)*plVar1 == 0) {

      KillTimer(param_1,0x14021a9a0);

      puVar32 = auStackY_1c8;

    }

    break;

  case 0x214:

    local_158.x = local_res20.x;

    local_158.y = local_res20.y;

    local_180 = *(POINT *)local_res20;

    uStack_178 = *(ulonglong *)((longlong)local_res20 + 8);

    fVar41 = *(float *)(*plVar21 + 0x38);

    fVar42 = *(float *)(*plVar21 + 0x3c);

    if (fVar42 != fVar41) {

      local_188[0] = false;

    }

    else {

      local_188[0] = true;

    }

    local_188[0] = fVar42 == fVar41;

    if ((fVar41 <= 0.0) && (puVar32 = auStackY_1c8, fVar42 <= 0.0)) break;

    SetRectEmpty((LPRECT)local_170);

    pHVar28 = GetMenu(param_1);

    DVar7 = GetWindowLongW(param_1,-0x14);

    DVar17 = GetWindowLongW(param_1,-0x10);

    BVar15 = AdjustWindowRectEx((LPRECT)local_170,DVar17,(uint)(pHVar28 != (HMENU)0x0),DVar7);

    if (BVar15 == 0) {

      LVar34 = -1;

      goto switchD_14018db6c_caseD_9;

    }

    uStack_178._4_4_ = uStack_178._4_4_ - tStack_168.y;

    iVar14 = ((int)uStack_178 - tStack_168.x) - (local_180.x - local_170._0_4_);

    uStack_178 = CONCAT44(uStack_178._4_4_,(int)uStack_178 - tStack_168.x);

    iVar16 = uStack_178._4_4_ - (local_180.y - local_170._4_4_);

    local_180.y = local_180.y - local_170._4_4_;

    local_180.x = local_180.x - local_170._0_4_;

    fVar41 = (float)iVar14;

    fVar42 = fVar41 / (float)iVar16;

    if (local_188[0] == false) {

      if ((param_3 == (HDROP)0x1) || (param_3 == (HDROP)0x2)) {

        fVar41 = *(float *)(*plVar21 + 0x3c);

        if (((0.0 < fVar41) && (fVar41 < fVar42)) ||

           ((fVar41 = *(float *)(*plVar21 + 0x38), 0.0 < fVar41 && (fVar42 < fVar41))))

        goto LAB_14018f2e1;

      }

      else if ((param_3 == (HDROP)0x3) || (param_3 == (HDROP)0x6)) {

        fVar43 = *(float *)(*plVar21 + 0x38);

        if ((fVar43 <= 0.0) || (fVar43 <= fVar42)) {

          fVar43 = *(float *)(*plVar21 + 0x3c);

          if (0.0 < fVar43) {

            bVar40 = fVar42 < fVar43;

            goto LAB_14018f27b;

          }

        }

        else {

          fVar41 = (float)thunk_FUN_1402e1d00(fVar41 / fVar43);

          iVar16 = (int)fVar41;

        }

      }

      else {

        fVar43 = *(float *)(*plVar21 + 0x3c);

        if ((0.0 < fVar43) && (fVar43 < fVar42)) goto LAB_14018f2e1;

        fVar43 = *(float *)(*plVar21 + 0x38);

        if (0.0 < fVar43) {

          bVar40 = fVar43 < fVar42;

LAB_14018f27b:

          if (!bVar40 && fVar43 != fVar42) {

            fVar41 = (float)thunk_FUN_1402e1d00(fVar41 / fVar43);

            iVar16 = (int)fVar41;

          }

        }

      }

    }

    else if ((param_3 == (HDROP)0x1) || (param_3 == (HDROP)0x2)) {

      fVar41 = (float)thunk_FUN_1402e1d00(fVar41 / *(float *)(*plVar21 + 0x3c));

      iVar16 = (int)fVar41;

    }

    else {

LAB_14018f2e1:

      fVar41 = (float)thunk_FUN_1402e1d00();

      iVar14 = (int)fVar41;

    }

    switch(param_3) {

    case (HDROP)0x1:

      local_180.x = (int)uStack_178 - iVar14;

      goto LAB_14018f318;

    case (HDROP)0x2:

      uStack_178 = (ulonglong)(uint)(local_180.x + iVar14);

LAB_14018f318:

      if (local_188[0] != false) {

        local_180.y = (((int)plVar21[0x11] + (int)plVar21[0x10]) - iVar16) / 2;

      }

      goto LAB_14018f3af;

    case (HDROP)0x3:

      if (local_188[0] != false) {

        local_180.y = 0;

        local_180.x = ((*(int *)((longlong)plVar21 + 0x84) + *(int *)((longlong)plVar21 + 0x7c)) -

                      iVar14) / 2;

      }

    case (HDROP)0x5:

      uStack_178 = CONCAT44(uStack_178._4_4_,local_180.x + iVar14);

      local_180.y = uStack_178._4_4_ - iVar16;

      break;

    case (HDROP)0x4:

      local_180.y = uStack_178._4_4_ - iVar16;

      local_180.x = (int)uStack_178 - iVar14;

      break;

    case (HDROP)0x6:

      if (local_188[0] != false) {

        local_180.x = ((*(int *)((longlong)plVar21 + 0x84) + *(int *)((longlong)plVar21 + 0x7c)) -

                      iVar14) / 2;

      }

    case (HDROP)0x8:

      uStack_178 = (ulonglong)(uint)(local_180.x + iVar14);

LAB_14018f3af:

      uStack_178 = CONCAT44(local_180.y + iVar16,(int)uStack_178);

      break;

    case (HDROP)0x7:

      local_180.x = (int)uStack_178 - iVar14;

      goto LAB_14018f3af;

    }

    pHVar28 = GetMenu(param_1);

    DVar7 = GetWindowLongW(param_1,-0x14);

    DVar17 = GetWindowLongW(param_1,-0x10);

    BVar15 = AdjustWindowRectEx((LPRECT)&local_180,DVar17,(uint)(pHVar28 != (HMENU)0x0),DVar7);

    LVar34 = -1;

    puVar32 = auStackY_1c8;

    param_2 = local_res10[0];

    if (BVar15 != 0) {

      *(POINT *)local_158 = local_180;

      *(ulonglong *)((longlong)local_158 + 8) = uStack_178;

      puVar32 = auStackY_1c8;

    }

    break;

  case 0x215:

    *(undefined1 *)((longlong)plVar21 + 0x65) = 0;

    uVar30 = FUN_14018c5c0();

    FUN_14018bd90(uVar30,plVar21);

    puVar32 = auStackY_1c8;

    break;

  case 0x233:

    UVar19 = DragQueryFileW(param_3,0xffffffff,(LPWSTR)0x0,0);

    iFile = 0;

    if (UVar19 != 0) {

      do {

        UVar20 = DragQueryFileW(param_3,iFile,(LPWSTR)0x0,0);

        lpszFile = (LPWSTR)FUN_1401841f0((ulonglong)(UVar20 + 1) * 2);

        if (lpszFile != (LPWSTR)0x0) {

          UVar20 = DragQueryFileW(param_3,iFile,lpszFile,UVar20 + 1);

          if (UVar20 != 0) {

            FUN_14012fd40(lpszFile);

            uVar30 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lpszFile);

            FUN_14022dfd0(*plVar21,0);

            FUN_1401841e0(uVar30);

          }

          FUN_1401841e0(lpszFile);

        }

        iFile = iFile + 1;

      } while (iFile < UVar19);

    }

    FUN_14022dfa0(*plVar21);

    DragFinish(param_3);

    return 0;

  case 0x240:

    puVar32 = auStackY_1c8;

    if ((*(longlong *)(plVar21[0x18] + 0x38) != 0) &&

       (puVar32 = auStackY_1c8, *(longlong *)(plVar21[0x18] + 0x30) != 0)) {

      uVar23 = (ulonglong)param_3 & 0xffff;

      local_180 = (POINT)(uVar23 * 0x30);

      if ((ulonglong)local_180 < 0x80) {

        PVar29 = (POINT)((longlong)local_180 + 0xf);

        if ((ulonglong)PVar29 <= (ulonglong)local_180) {

          PVar29.x = -0x10;

          PVar29.y = 0xfffffff;

        }

        puVar31 = auStackY_1c8 + -((ulonglong)PVar29 & 0xfffffffffffffff0);

        PVar29 = (POINT)((longlong)local_188 + -((ulonglong)PVar29 & 0xfffffffffffffff0));

      }

      else {

        PVar29 = (POINT)FUN_1401841f0();

      }

      local_158 = PVar29;

      if (PVar29 == (POINT)0x0) {

LAB_14018f693:

        if (0x7f < (ulonglong)local_180) {

          *(undefined8 *)(puVar31 + -8) = 0x14018f6a5;

          FUN_1401841e0(PVar29);

        }

        pcVar3 = *(code **)(plVar21[0x18] + 0x30);

        *(undefined8 *)(puVar31 + -8) = 0x14018f6b9;

        (*pcVar3)(local_res20);

        return 0;

      }

      pcVar3 = *(code **)(plVar21[0x18] + 0x38);

      *(undefined8 *)(puVar31 + -8) = 0x14018f4b1;

      iVar14 = (*pcVar3)(local_res20,uVar23,PVar29,0x30);

      if (iVar14 == 0) goto LAB_14018f693;

      *(undefined8 *)(puVar31 + -8) = 0x14018f4c6;

      BVar15 = GetClientRect(param_1,(LPRECT)local_170);

      if (BVar15 != 0) {

        *(undefined8 *)(puVar31 + -8) = 0x14018f4d7;

        cVar5 = FUN_1401aa1d0(local_170);

        if (cVar5 != '\0') {

          *(undefined8 *)(puVar31 + -8) = 0x14018f4ec;

          ClientToScreen(param_1,(LPPOINT)local_170);

          *(undefined8 *)(puVar31 + -8) = 0x14018f4f9;

          ClientToScreen(param_1,&tStack_168);

          uVar13 = DAT_14039ca44;

          fVar41 = DAT_14039ca34;

          iVar14 = tStack_168.y * 100;

          tStack_168.x = tStack_168.x * 100;

          tStack_168.y = iVar14;

          local_170._4_4_ = local_170._4_4_ * 100;

          local_170._0_4_ = local_170._0_4_ * 100;

          PVar29 = local_158;

          if ((int)uVar23 != 0) {

            pbVar35 = (byte *)((longlong)local_158 + 0x14);

            iVar16 = tStack_168.x;

            while( true ) {

              iVar16 = iVar16 - local_170._0_4_;

              pcVar37 = "touch";

              iVar14 = iVar14 - local_170._4_4_;

              iVar9 = *(int *)(pbVar35 + -4) + 1;

              uVar30 = *(undefined8 *)(pbVar35 + -0xc);

              if ((*pbVar35 & 0x40) != 0) {

                pcVar37 = "pen";

              }

              *(undefined8 *)(puVar31 + -8) = 0x14018f568;

              iVar18 = FUN_140185f90(uVar30,0,pcVar37);

              if (-1 < iVar18) {

                fVar42 = fVar41;

                if (1 < iVar16) {

                  fVar42 = (float)(*(int *)(pbVar35 + -0x14) - local_170._0_4_) /

                           (float)(iVar16 + -1);

                }

                fVar43 = fVar41;

                if (1 < iVar14) {

                  fVar43 = (float)(*(int *)(pbVar35 + -0x10) - local_170._4_4_) /

                           (float)(iVar14 + -1);

                }

                if ((*pbVar35 & 2) != 0) {

                  lVar26 = *plVar21;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f5c9;

                  uVar36 = FUN_14018c5c0();

                  *(undefined4 *)(puVar31 + 0x38) = uVar13;

                  *(float *)(puVar31 + 0x30) = fVar43;

                  *(float *)(puVar31 + 0x28) = fVar42;

                  *(undefined4 *)(puVar31 + 0x20) = 0x700;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f5f5;

                  FUN_1401865d0(uVar36,uVar30,iVar9,lVar26);

                }

                if ((*pbVar35 & 1) != 0) {

                  lVar26 = *plVar21;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f602;

                  uVar36 = FUN_14018c5c0();

                  *(undefined4 *)(puVar31 + 0x30) = uVar13;

                  *(float *)(puVar31 + 0x28) = fVar43;

                  *(float *)(puVar31 + 0x20) = fVar42;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f626;

                  FUN_140186970(uVar36,uVar30,iVar9,lVar26);

                }

                if ((*pbVar35 & 4) != 0) {

                  lVar26 = *plVar21;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f633;

                  uVar36 = FUN_14018c5c0();

                  *(undefined4 *)(puVar31 + 0x38) = uVar13;

                  *(float *)(puVar31 + 0x30) = fVar43;

                  *(float *)(puVar31 + 0x28) = fVar42;

                  *(undefined4 *)(puVar31 + 0x20) = 0x701;

                  *(undefined8 *)(puVar31 + -8) = 0x14018f65f;

                  FUN_1401865d0(uVar36,uVar30,iVar9,lVar26);

                }

              }

              pbVar35 = pbVar35 + 0x30;

              uVar23 = uVar23 - 1;

              PVar29 = local_158;

              if (uVar23 == 0) break;

              iVar14 = tStack_168.y;

              iVar16 = tStack_168.x;

            }

          }

          goto LAB_14018f693;

        }

      }

      puVar32 = puVar31;

      if (0x7f < (ulonglong)local_180) {

        *(undefined8 *)(puVar31 + -8) = 0x14018f68a;

        FUN_1401841e0(PVar29);

      }

    }

    break;

  case 0x245:

  case 0x246:

  case 0x247:

    local_180.x = 1;

    puVar32 = auStackY_1c8;

    if ((*(code **)(plVar21[0x18] + 0x68) == (code *)0x0) ||

       (iVar14 = (**(code **)(plVar21[0x18] + 0x68))

                           ((ulonglong)param_3 & 0xffff,(tagRECT *)&local_180),

       puVar32 = auStackY_1c8, iVar14 == 0)) break;

    if ((param_2 != 0x245) || (local_180.x != 4)) {

      puVar32 = auStackY_1c8;

      if (local_180.x == 3) {

        iVar14 = FUN_1401a82c0(1);

        if (((iVar14 != 0) && (*(code **)(plVar21[0x18] + 0x70) != (code *)0x0)) &&

           (iVar16 = (**(code **)(plVar21[0x18] + 0x70))((ulonglong)param_3 & 0xffff,&local_108),

           iVar16 != 0)) {

          uVar30 = FUN_14018c5c0();

          lVar26 = *plVar21;

          uVar6 = (ushort)((ulonglong)param_3 >> 0x10) & 0x14;

          if (uVar6 != 0x14) {

            FUN_1401a8cc0(uVar30,iVar14,lVar26,

                          CONCAT31((uint3)(local_a8 >> 9),(char)(local_a8 >> 1)) & 0xffffff01);

          }

          if ((*(code **)(plVar21[0x18] + 0x78) == (code *)0x0) ||

             (iVar16 = (**(code **)(plVar21[0x18] + 0x78))

                                 (local_108.rcPaint._4_8_,&local_138,local_170), iVar16 == 0)) {

            local_158.y = (int)local_res20.x._2_2_;

            local_158.x = (int)(short)local_res20.x;

            ScreenToClient((HWND)plVar21[1],&local_158);

          }

          else {

            FUN_14016e7f0(lVar26,&local_158,&local_144);

          }

          FUN_1401a8920(uVar30,iVar14,lVar26);

          FUN_1401a8750(uVar30,iVar14,lVar26,1);

          FUN_1401a8750(uVar30,iVar14,lVar26,2);

          if ((local_a4 & 1) != 0) {

            FUN_1401a8590(uVar30,iVar14,lVar26,0);

          }

          if ((local_a4 & 2) != 0) {

            FUN_1401a8590(uVar30,iVar14,lVar26,4);

          }

          if ((local_a4 & 4) != 0) {

            FUN_1401a8590(uVar30,iVar14,lVar26,1);

          }

          if ((local_a4 & 8) != 0) {

            FUN_1401a8590(uVar30,iVar14,lVar26,2);

          }

          if (uVar6 != 0x14) goto LAB_14018e1a7;

          FUN_1401a8cc0(uVar30,iVar14,lVar26,

                        CONCAT31((uint3)(local_a8 >> 9),(char)(local_a8 >> 1)) & 0xffffff01);

          LVar34 = 0;

        }

        goto switchD_14018db6c_caseD_9;

      }

      break;

    }

    LVar34 = 0;

    *(POINT *)(plVar21 + 0xb) = local_res20;

    goto LAB_14018f8d8;

  case 0x249:

    local_180.x = 1;

    puVar32 = auStackY_1c8;

    if (((*(code **)(plVar21[0x18] + 0x68) != (code *)0x0) &&

        (iVar14 = (**(code **)(plVar21[0x18] + 0x68))

                            ((ulonglong)param_3 & 0xffff,(tagRECT *)&local_180),

        puVar32 = auStackY_1c8, iVar14 != 0)) && (puVar32 = auStackY_1c8, local_180.x == 3)) {

      iVar14 = FUN_1401a82c0(1);

      lVar26 = *plVar21;

      if (iVar14 == 0) {

        local_138.rcMonitor.left = 0x42b40000;

        local_138.rcMonitor.top = 0;

        local_138.rcMonitor.bottom = 3;

        local_138.rcWork.left = 0;

        local_138.cbSize = 0x9f;

        local_138.rcMonitor.right = 1;

        uVar30 = FUN_14018c5c0();

        FUN_1401a8170(uVar30,0,lVar26,&local_138);

        LVar34 = 0;

        puVar32 = auStackY_1c8;

      }

      else {

        uVar30 = FUN_14018c5c0();

        FUN_1401a8b60(uVar30,iVar14,lVar26,1);

        LVar34 = 0;

        puVar32 = auStackY_1c8;

      }

    }

    break;

  case 0x24a:

  case 0x24c:

    local_180.x = 1;

    puVar32 = auStackY_1c8;

    if (((*(code **)(plVar21[0x18] + 0x68) != (code *)0x0) &&

        (iVar14 = (**(code **)(plVar21[0x18] + 0x68))

                            ((ulonglong)param_3 & 0xffff,(tagRECT *)&local_180),

        puVar32 = auStackY_1c8, iVar14 != 0)) &&

       ((puVar32 = auStackY_1c8, local_180.x == 3 &&

        (iVar14 = FUN_1401a82c0(1), puVar32 = auStackY_1c8, iVar14 != 0)))) {

      if ((param_2 == 0x24c) || (((ulonglong)param_3 >> 0x10 & 4) == 0)) {

        lVar26 = *plVar21;

        uVar30 = FUN_14018c5c0();

        FUN_1401a8b60(uVar30,iVar14,lVar26,0);

        param_2 = local_res10[0];

      }

LAB_14018eb07:

      LVar34 = 0;

      puVar32 = auStackY_1c8;

    }

    break;

  case 0x2a3:

    lVar26 = *plVar21;

    if ((*(uint *)(lVar26 + 0x48) >> 0xe & 1) == 0) {

      lVar24 = FUN_140161230();

      if (((lVar24 == lVar26) && (lVar26 = FUN_1401611a0(), *(char *)(lVar26 + 0xc1) == '\0')) &&

         (BVar15 = IsIconic(param_1), BVar15 == 0)) {

        DVar7 = GetMessagePos();

        local_158.y = (int)(short)(DVar7 >> 0x10);

        local_158.x = (int)(short)DVar7;

        ScreenToClient(param_1,&local_158);

        lVar26 = FUN_1401611a0();

        if (*(char *)(lVar26 + 0xf0) == '\0') {

          lVar26 = *plVar21;

          uVar30 = FUN_14018c5c0();

          FUN_1401628f0(uVar30,lVar26,0,0);

          param_2 = local_res10[0];

        }

        else {

          *(undefined1 *)(lVar26 + 0xf0) = 0;

          lVar24 = *plVar21;

          if (*(char *)(lVar26 + 0xec) == '\0') {

            uVar30 = FUN_14018c5c0();

            uVar36 = 0;

          }

          else {

            uVar30 = FUN_14018c5c0();

            uVar36 = 0xffffffff;

          }

          FUN_1401628f0(uVar30,lVar24,uVar36,0);

        }

      }

      lVar26 = FUN_1401611a0();

      if (*(char *)(lVar26 + 0xc1) == '\0') {

        FUN_140162ca0(0);

      }

    }

    *(undefined1 *)((longlong)plVar21 + 0xac) = 0;

    LVar34 = 0;

    puVar32 = auStackY_1c8;

    break;

  case 0x2cc:

    return 0x198319;

  case 0x2e0:

    if (*(char *)((longlong)plVar21 + 99) == '\0') {

      lVar26 = *plVar21;

      local_170._0_4_ = 0;

      local_170._4_4_ = 0;

      tStack_168.x = *(int *)(lVar26 + 0x20);

      tStack_168.y = *(int *)(lVar26 + 0x24);

      if ((*(byte *)(lVar26 + 0x48) & 0x10) == 0) {

        FUN_14022a8c0(param_1,local_170,(ulonglong)param_3 >> 0x10 & 0xffff);

      }

      *(undefined1 *)((longlong)plVar21 + 99) = 1;

      SetWindowPos(param_1,(HWND)0x0,*(int *)PVar29,*(int *)((longlong)PVar29 + 4),

                   tStack_168.x - local_170._0_4_,tStack_168.y - local_170._4_4_,0x14);

      *(undefined1 *)((longlong)plVar21 + 99) = 0;

    }

    return 0;

  case 0x2e4:

    pcVar3 = *(code **)(plVar21[0x18] + 0xc0);

    puVar32 = auStackY_1c8;

    if ((pcVar3 != (code *)0x0) &&

       (puVar32 = auStackY_1c8, *(longlong *)(plVar21[0x18] + 0xb8) != 0)) {

      uVar13 = (*pcVar3)(param_1);

      PVar29 = local_res20;

      local_158.x = 0;

      local_158.y = 0;

      uStack_150 = 0;

      if ((*(uint *)(*plVar21 + 0x48) & 0xc0010) == 0) {

        FUN_14022a8c0(param_1,&local_158,uVar13);

      }

      tStack_168.x = (local_158.x - (int)uStack_150) + *(int *)PVar29;

      tStack_168.y = (local_158.y - uStack_150._4_4_) + *(int *)((longlong)PVar29 + 4);

      local_170._0_4_ = 0;

      local_170._4_4_ = 0;

      if ((*(uint *)(*plVar21 + 0x48) & 0xc0010) == 0) {

        FUN_14022a8c0(param_1,local_170,(ulonglong)param_3 & 0xffffffff);

      }

      *(LONG *)((longlong)PVar29 + 4) = tStack_168.y - local_170._4_4_;

      *(LONG *)PVar29 = tStack_168.x - local_170._0_4_;

      return 1;

    }

  }

switchD_14018e5d0_caseD_103:

  puVar25 = puVar32;

  if (param_2 != 0) {

LAB_14018f8d8:

    if (param_2 == *(UINT *)(plVar21[0x18] + 0x38c)) {

      lVar26 = *plVar21;

      *(undefined1 *)((longlong)plVar21 + 0xbc) = 1;

      *(undefined8 *)(puVar25 + -8) = 0x14018f8f7;

      uVar30 = FUN_14016dcf0();

      *(undefined8 *)(puVar25 + -8) = 0x14018f902;

      FUN_14022ac50(uVar30,lVar26);

      param_2 = local_res10[0];

    }

  }

  lpPrevWndFunc = (WNDPROC)plVar21[8];

  if (lpPrevWndFunc == (WNDPROC)0x0) {

    puVar32 = puVar25;

    if (LVar34 < 0) {

LAB_14018da9d:

      *(POINT *)(puVar32 + 0x20) = local_res20;

      *(undefined8 *)(puVar32 + -8) = 0x14018dabf;

      LVar34 = CallWindowProcW(DefWindowProcW_exref,param_1,param_2,(WPARAM)param_3,

                               *(LPARAM *)(puVar32 + 0x20));

    }

  }

  else {

    *(POINT *)(puVar25 + 0x20) = local_res20;

    *(undefined8 *)(puVar25 + -8) = 0x14018f92c;

    LVar34 = CallWindowProcW(lpPrevWndFunc,param_1,param_2,(WPARAM)param_3,

                             *(LPARAM *)(puVar25 + 0x20));

  }

  return LVar34;

}




