// Address: 0x14022a1e0
// Ghidra name: FUN_14022a1e0
// ============ 0x14022a1e0 FUN_14022a1e0 (size=1173) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_14022a1e0(longlong param_1,longlong param_2,HWND param_3,longlong param_4)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  BOOL BVar4;

  uint uVar5;

  longlong *hData;

  HDC pHVar6;

  LONG_PTR LVar7;

  undefined8 uVar8;

  code *pcVar9;

  HWND pHVar10;

  LPWSTR lpString;

  longlong lVar11;

  undefined1 *puVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  undefined4 uVar15;

  tagPOINT local_res8;

  undefined1 auStackY_88 [32];

  int local_48;

  int local_44;

  int local_40 [2];

  tagRECT local_38;

  

  puVar12 = auStackY_88;

  lVar11 = *(longlong *)(param_1 + 0x680);

  hData = (longlong *)FUN_1401841a0(1,0xe0);

  if (hData == (longlong *)0x0) {

    return 0;

  }

  *hData = param_2;

  hData[1] = (longlong)param_3;

  hData[2] = param_4;

  pHVar6 = GetDC(param_3);

  hData[3] = (longlong)pHVar6;

  LVar7 = GetWindowLongPtrW(param_3,-6);

  hData[5] = LVar7;

  hData[10] = -1;

  hData[0xb] = -1;

  hData[0x18] = lVar11;

  *(undefined1 *)((longlong)hData + 0x62) = 1;

  uVar2 = FUN_140229d10();

  *(undefined4 *)(hData + 0x17) = uVar2;

  iVar3 = GetSystemMetrics(0x1000);

  *(undefined4 *)(hData + 0x15) = 1;

  uVar15 = 0;

  *(undefined4 *)(hData + 0x14) = 0;

  *(uint *)((longlong)hData + 0x9c) = -(uint)(iVar3 != 0) & 0xfffffffe;

  uVar2 = 1;

  if (iVar3 != 0) {

    uVar2 = 3;

  }

  *(undefined4 *)((longlong)hData + 0xa4) = uVar2;

  cVar1 = FUN_140142940("SDL_WINDOW_RETAIN_CONTENT",0);

  if (cVar1 == '\0') {

    uVar15 = 0x100;

  }

  *(undefined4 *)(hData + 0x1a) = uVar15;

  BVar4 = SetPropW(param_3,L"SDL_WindowData",hData);

  if (BVar4 == 0) {

    ReleaseDC(param_3,(HDC)hData[3]);

    FUN_1401841e0(hData);

    uVar8 = FUN_1401a9ed0("SetProp() failed");

    return uVar8;

  }

  *(longlong **)(param_2 + 0x188) = hData;

  if ((*(uint *)(param_2 + 0x48) >> 0xb & 1) != 0) {

    pcVar9 = (code *)GetWindowLongPtrW(param_3,-4);

    hData[8] = (longlong)pcVar9;

    if (pcVar9 != FUN_14018da20) {

      SetWindowLongPtrW(param_3,-4,0x14018da20);

    }

  }

  uVar5 = GetWindowLongW(param_3,-0x10);

  uVar14 = *(ulonglong *)(param_2 + 0x48) & 0xfffffffffffffff7;

  if ((uVar5 >> 0x1c & 1) == 0) {

    uVar14 = *(ulonglong *)(param_2 + 0x48) | 8;

  }

  uVar13 = uVar14 | 0x10;

  if ((uVar5 & 0x80000000) == 0) {

    uVar13 = uVar14 & 0xffffffffffffffef;

  }

  if ((uVar5 >> 0x12 & 1) == 0) {

    if ((uVar5 & 0x80000000) == 0) {

      uVar13 = uVar13 & 0xffffffffffffffdf;

    }

  }

  else {

    uVar13 = uVar13 | 0x20;

  }

  uVar14 = uVar13 | 0x80;

  if ((uVar5 >> 0x18 & 1) == 0) {

    uVar14 = uVar13 & 0xffffffffffffff7f;

  }

  uVar13 = uVar14 | 0x40;

  if ((uVar5 >> 0x1d & 1) == 0) {

    uVar13 = uVar14 & 0xffffffffffffffbf;

  }

  *(ulonglong *)(param_2 + 0x48) = uVar13;

  if ((((uVar13 & 0x40) == 0) && (BVar4 = GetClientRect(param_3,&local_38), BVar4 != 0)) &&

     (cVar1 = FUN_1401aa1d0(&local_38), cVar1 != '\0')) {

    local_48 = local_38.right;

    local_res8.x = local_38.bottom;

    if ((*(uint *)(param_2 + 0x48) >> 0xb & 1) == 0) {

      if (((*(int *)(param_2 + 0x74) != 0) && (*(int *)(param_2 + 0x74) != local_38.right)) ||

         ((*(int *)(param_2 + 0x78) != 0 && (*(int *)(param_2 + 0x78) != local_38.bottom)))) {

        FUN_14022a7f0(param_2,local_40,&local_44,&local_48);

        *(undefined1 *)((longlong)hData + 99) = 1;

        SetWindowPos(param_3,(HWND)0x0,local_40[0],local_44,local_48,local_res8.x,

                     *(uint *)(hData + 0x1a) | 0x214);

        *(undefined1 *)((longlong)hData + 99) = 0;

        goto LAB_14022a435;

      }

    }

    else {

      *(LONG *)(param_2 + 0x74) = local_38.right;

      *(LONG *)(param_2 + 0x84) = local_38.right;

      *(LONG *)(param_2 + 0x78) = local_38.bottom;

      *(LONG *)(param_2 + 0x88) = local_38.bottom;

    }

    *(LONG *)(param_2 + 0x24) = local_38.bottom;

    *(LONG *)(param_2 + 0x20) = local_38.right;

  }

LAB_14022a435:

  if ((*(byte *)(param_2 + 0x48) & 0x40) == 0) {

    local_res8.x = 0;

    local_res8.y = 0;

    BVar4 = ClientToScreen(param_3,&local_res8);

    if (BVar4 != 0) {

      if ((*(uint *)(param_2 + 0x48) >> 0xb & 1) != 0) {

        *(LONG *)(param_2 + 0x6c) = local_res8.x;

        *(LONG *)(param_2 + 0x7c) = local_res8.x;

        *(LONG *)(param_2 + 0x70) = local_res8.y;

        *(LONG *)(param_2 + 0x80) = local_res8.y;

      }

      *(LONG *)(param_2 + 0x18) = local_res8.x;

      *(LONG *)(param_2 + 0x1c) = local_res8.y;

    }

  }

  FUN_14022cbd0(param_2,0);

  pHVar10 = GetFocus();

  if (pHVar10 == param_3) {

    *(ulonglong *)(param_2 + 0x48) = *(ulonglong *)(param_2 + 0x48) | 0x200;

    FUN_140183d70(param_2);

    FUN_14022c8c0(param_2);

  }

  FUN_14022bb20(param_1,param_2,(ushort)((uint)*(undefined4 *)(param_2 + 0x48) >> 0x10) & 0xff01);

  pcVar9 = *(code **)(lVar11 + 0x40);

  if (pcVar9 != (code *)0x0) {

    (*pcVar9)(param_3,3);

  }

  if ((hData[2] != 0) && (*(longlong *)(param_2 + 0x1a8) == 0)) {

    *(undefined1 *)((longlong)hData + 0xad) = 1;

  }

  *(undefined1 *)((longlong)hData + 0x62) = 0;

  if ((*(uint *)(param_2 + 0x48) >> 0xb & 1) != 0) {

    iVar3 = GetWindowTextLengthW(param_3);

    uVar14 = (longlong)(iVar3 + 1) * 2;

    if (uVar14 < 0x80) {

      uVar13 = uVar14 + 0xf;

      if (uVar13 <= uVar14) {

        uVar13 = 0xffffffffffffff0;

      }

      lpString = (LPWSTR)((longlong)&local_48 + -(uVar13 & 0xfffffffffffffff0));

      puVar12 = auStackY_88 + -(uVar13 & 0xfffffffffffffff0);

    }

    else {

      lpString = (LPWSTR)FUN_1401841f0(uVar14);

      puVar12 = auStackY_88;

    }

    if (lpString != (LPWSTR)0x0) {

      *(undefined8 *)(puVar12 + -8) = 0x14022a5da;

      iVar3 = GetWindowTextW(param_3,lpString,iVar3 + 1);

      if (0 < iVar3) {

        *(undefined8 *)(puVar12 + -8) = 0x14022a5e6;

        lVar11 = FUN_14012fd40(lpString);

        *(undefined8 *)(puVar12 + -8) = 0x14022a604;

        uVar8 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lpString,lVar11 * 2 + 2);

        *(undefined8 *)(param_2 + 8) = uVar8;

      }

      if (0x7f < uVar14) {

        *(undefined8 *)(puVar12 + -8) = 0x14022a619;

        FUN_1401841e0(lpString);

      }

    }

  }

  *(undefined8 *)(puVar12 + -8) = 0x14022a621;

  uVar2 = FUN_14016ea50(param_2);

  lVar11 = hData[1];

  *(undefined8 *)(puVar12 + -8) = 0x14022a635;

  FUN_140175480(uVar2,"SDL.window.win32.hwnd",lVar11);

  lVar11 = hData[3];

  *(undefined8 *)(puVar12 + -8) = 0x14022a647;

  FUN_140175480(uVar2,"SDL.window.win32.hdc",lVar11);

  lVar11 = hData[5];

  *(undefined8 *)(puVar12 + -8) = 0x14022a659;

  FUN_140175480(uVar2,"SDL.window.win32.instance",lVar11);

  return 1;

}




