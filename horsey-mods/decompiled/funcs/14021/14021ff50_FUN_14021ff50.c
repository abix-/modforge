// Address: 0x14021ff50
// Ghidra name: FUN_14021ff50
// ============ 0x14021ff50 FUN_14021ff50 (size=1492) ============


ulonglong FUN_14021ff50(uint *param_1,undefined4 *param_2)



{

  int iVar1;

  uint uVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  ulonglong uVar6;

  HDC hdc;

  HFONT h;

  size_t sVar7;

  LPCWSTR lpchText;

  undefined8 *puVar8;

  longlong lVar9;

  ulonglong uVar10;

  HWND hWndParent;

  INT_PTR IVar11;

  int iVar12;

  char *pcVar13;

  int iVar14;

  byte *pbVar15;

  undefined1 uVar16;

  int iVar17;

  int iVar18;

  short sVar19;

  ushort uVar20;

  int iVar21;

  uint uVar22;

  ulonglong uVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  undefined8 in_stack_fffffffffffffca8;

  undefined4 uVar28;

  undefined8 uVar27;

  tagRECT local_338;

  int local_328;

  int local_324;

  int local_320;

  int local_31c;

  ulonglong local_318;

  tagSIZE local_310;

  undefined8 local_308;

  HWND local_300;

  LOGFONTW local_2f8;

  tagTEXTMETRICW local_298;

  undefined4 local_258 [102];

  LOGFONTW local_c0;

  

  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffca8 >> 0x20);

  uVar6 = 0;

  local_318 = 0;

  sVar19 = 0;

  local_308 = 0;

  local_300 = (HWND)0x0;

  fVar24 = (float)FUN_14021fae0();

  fVar25 = (float)thunk_FUN_1402e1d00(fVar24 * DAT_140304030);

  local_31c = (int)fVar25;

  fVar26 = (float)thunk_FUN_1402e1d00(fVar24 * DAT_140303fe8);

  iVar4 = (int)fVar26;

  fVar26 = (float)thunk_FUN_1402e1d00(fVar24 * DAT_140303fd0);

  iVar18 = (int)fVar26;

  fVar26 = (float)thunk_FUN_1402e1d00(fVar24 * DAT_1403033a4);

  iVar21 = (int)fVar26;

  local_320 = iVar21;

  local_324 = GetSystemMetrics(0xb);

  local_328 = GetSystemMetrics(0xc);

  fVar24 = (float)thunk_FUN_1402e1d00(fVar24 * DAT_140303754);

  iVar12 = (int)fVar24;

  if (0xff9b < (int)param_1[8]) {

    uVar6 = FUN_14012e850("Number of buttons exceeds limit of %d",0xff9b);

    return uVar6;

  }

  uVar5 = *param_1 & 0x70;

  if (uVar5 == 0x10) {

    sVar19 = 0x7f01;

  }

  else if (uVar5 == 0x20) {

    sVar19 = 0x7f03;

  }

  else if (uVar5 == 0x40) {

    sVar19 = 0x7f04;

  }

  hdc = CreateCompatibleDC((HDC)0x0);

  local_258[0] = 0x1f8;

  SystemParametersInfoW(0x29,0,local_258,0);

  local_2f8.lfFaceName[0x1e] = local_c0.lfFaceName[0x1e];

  local_2f8.lfFaceName[0x1f] = local_c0.lfFaceName[0x1f];

  local_2f8.lfHeight = local_c0.lfHeight;

  local_2f8.lfWidth = local_c0.lfWidth;

  local_2f8.lfEscapement = local_c0.lfEscapement;

  local_2f8.lfOrientation = local_c0.lfOrientation;

  local_2f8.lfWeight = local_c0.lfWeight;

  local_2f8.lfItalic = local_c0.lfItalic;

  local_2f8.lfUnderline = local_c0.lfUnderline;

  local_2f8.lfStrikeOut = local_c0.lfStrikeOut;

  local_2f8.lfCharSet = local_c0.lfCharSet;

  local_2f8.lfOutPrecision = local_c0.lfOutPrecision;

  local_2f8.lfClipPrecision = local_c0.lfClipPrecision;

  local_2f8.lfQuality = local_c0.lfQuality;

  local_2f8.lfPitchAndFamily = local_c0.lfPitchAndFamily;

  local_2f8.lfFaceName[0] = local_c0.lfFaceName[0];

  local_2f8.lfFaceName[1] = local_c0.lfFaceName[1];

  local_2f8.lfFaceName[2] = local_c0.lfFaceName[2];

  local_2f8.lfFaceName[3] = local_c0.lfFaceName[3];

  local_2f8.lfFaceName[4] = local_c0.lfFaceName[4];

  local_2f8.lfFaceName[5] = local_c0.lfFaceName[5];

  local_2f8.lfFaceName[6] = local_c0.lfFaceName[6];

  local_2f8.lfFaceName[7] = local_c0.lfFaceName[7];

  local_2f8.lfFaceName[8] = local_c0.lfFaceName[8];

  local_2f8.lfFaceName[9] = local_c0.lfFaceName[9];

  local_2f8.lfFaceName[10] = local_c0.lfFaceName[10];

  local_2f8.lfFaceName[0xb] = local_c0.lfFaceName[0xb];

  local_2f8.lfFaceName[0xc] = local_c0.lfFaceName[0xc];

  local_2f8.lfFaceName[0xd] = local_c0.lfFaceName[0xd];

  local_2f8.lfFaceName[0xe] = local_c0.lfFaceName[0xe];

  local_2f8.lfFaceName[0xf] = local_c0.lfFaceName[0xf];

  local_2f8.lfFaceName[0x10] = local_c0.lfFaceName[0x10];

  local_2f8.lfFaceName[0x11] = local_c0.lfFaceName[0x11];

  local_2f8.lfFaceName[0x12] = local_c0.lfFaceName[0x12];

  local_2f8.lfFaceName[0x13] = local_c0.lfFaceName[0x13];

  local_2f8.lfFaceName[0x14] = local_c0.lfFaceName[0x14];

  local_2f8.lfFaceName[0x15] = local_c0.lfFaceName[0x15];

  local_2f8.lfFaceName[0x16] = local_c0.lfFaceName[0x16];

  local_2f8.lfFaceName[0x17] = local_c0.lfFaceName[0x17];

  local_2f8.lfFaceName[0x18] = local_c0.lfFaceName[0x18];

  local_2f8.lfFaceName[0x19] = local_c0.lfFaceName[0x19];

  local_2f8.lfFaceName[0x1a] = local_c0.lfFaceName[0x1a];

  local_2f8.lfFaceName[0x1b] = local_c0.lfFaceName[0x1b];

  local_2f8.lfFaceName[0x1c] = local_c0.lfFaceName[0x1c];

  local_2f8.lfFaceName[0x1d] = local_c0.lfFaceName[0x1d];

  h = CreateFontIndirectW(&local_2f8);

  SelectObject(hdc,h);

  GetTextMetricsW(hdc,&local_298);

  GetTextExtentPoint32A(hdc,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",0x34,&local_310);

  DAT_1403fdba4 = (local_310.cx / 0x1a + 1) / 2;

  DAT_1403fdba8 = local_298.tmHeight;

  sVar7 = strlen(*(char **)(param_1 + 6));

  lpchText = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,*(undefined8 *)(param_1 + 6),sVar7 + 1

                                   );

  local_338.left = 0;

  local_338.top = 0;

  local_338.right = 0;

  local_338.bottom = 0;

  DrawTextW(hdc,lpchText,-1,&local_338,0x2c00);

  local_338.top = local_338.top + iVar18;

  local_338.bottom = local_338.bottom + iVar18 + 2;

  local_338.left = local_338.left + iVar18;

  local_338.right = local_338.right + 2 + iVar18;

  DeleteDC(hdc);

  FUN_1401841e0(lpchText);

  iVar17 = local_338.bottom + (iVar18 * 2 - local_338.top);

  iVar14 = (iVar18 * 2 - local_338.left) + local_338.right;

  if (sVar19 != 0) {

    iVar14 = iVar14 + iVar12 + local_324;

    local_338.left = local_338.left + iVar12 + local_324;

    local_338.right = local_338.right + iVar12 + local_324;

  }

  iVar1 = (int)fVar25 + iVar21;

  iVar21 = iVar1 * param_1[8] + iVar21;

  if (iVar21 <= iVar14) {

    iVar21 = iVar14;

  }

  if ((sVar19 != 0) && (iVar14 = local_328 + iVar12 * 2, iVar17 < iVar14)) {

    iVar17 = iVar14;

  }

  iVar18 = iVar17 + iVar18 + iVar4;

  puVar8 = (undefined8 *)FUN_14021f4b0(iVar21,iVar18,*(undefined8 *)(param_1 + 4));

  uVar10 = 0;

  if (puVar8 == (undefined8 *)0x0) {

LAB_14022043a:

    return uVar10 & 0xffffffffffffff00;

  }

  if (sVar19 != 0) {

    uVar27 = CONCAT44(uVar28,local_328);

    cVar3 = FUN_14021f2f0(puVar8,iVar12,iVar12,local_324,uVar27,sVar19);

    uVar28 = (undefined4)((ulonglong)uVar27 >> 0x20);

    if (cVar3 == '\0') goto LAB_14022030a;

  }

  uVar27 = CONCAT44(uVar28,local_338.bottom - local_338.top);

  cVar3 = FUN_14021f350(puVar8,local_338.left,local_338.top,local_338.right - local_338.left,uVar27,

                        *(undefined8 *)(param_1 + 6));

  if (cVar3 == '\0') {

LAB_14022030a:

    uVar6 = FUN_14021f870(puVar8);

    return uVar6 & 0xffffffffffffff00;

  }

  uVar5 = param_1[8];

  iVar18 = iVar18 - local_320;

  iVar21 = iVar21 - uVar5 * iVar1;

  uVar10 = uVar6;

  uVar23 = uVar6;

  if (0 < (int)uVar5) {

    do {

      uVar28 = (undefined4)((ulonglong)uVar27 >> 0x20);

      uVar16 = 0;

      uVar22 = (uint)uVar23;

      uVar2 = uVar22;

      if ((*param_1 & 0x80) == 0) {

        uVar2 = ~uVar22 + uVar5;

      }

      pbVar15 = (byte *)((longlong)(int)uVar2 * 0x10 + *(longlong *)(param_1 + 10));

      if (((*pbVar15 & 1) != 0) &&

         (uVar20 = (short)uVar6 + 1, uVar6 = (ulonglong)uVar20, uVar20 == 1)) {

        uVar16 = 1;

      }

      lVar9 = FUN_14021f6b0(&local_318,&local_308,*(undefined8 *)(pbVar15 + 8));

      iVar12 = local_31c;

      if (lVar9 == 0) {

LAB_140220428:

        FUN_14021f870(puVar8);

        uVar10 = FUN_1401841e0(local_318);

        goto LAB_14022043a;

      }

      uVar27 = CONCAT44(uVar28,iVar4);

      cVar3 = FUN_14021f070(puVar8,iVar21,iVar18 - iVar4,local_31c,uVar27,lVar9,

                            (int)((longlong)pbVar15 - *(longlong *)(param_1 + 10) >> 4) + 100,uVar16

                           );

      if (cVar3 == '\0') goto LAB_140220428;

      uVar5 = param_1[8];

      iVar21 = iVar21 + local_320 + iVar12;

      uVar10 = local_318;

      uVar23 = (ulonglong)(uVar22 + 1);

    } while ((int)(uVar22 + 1) < (int)uVar5);

  }

  FUN_1401841e0(uVar10);

  hWndParent = local_300;

  if (*(longlong *)(param_1 + 2) != 0) {

    hWndParent = *(HWND *)(*(longlong *)(*(longlong *)(param_1 + 2) + 0x188) + 8);

  }

  IVar11 = DialogBoxIndirectParamW

                     ((HINSTANCE)0x0,(LPCDLGTEMPLATEW)*puVar8,hWndParent,FUN_14021f8d0,

                      (LPARAM)param_1);

  if (IVar11 < 100) {

    if (IVar11 == 0x14) {

      uVar6 = 1;

      *param_2 = 0xffffffff;

      goto LAB_1402204f7;

    }

    if (IVar11 == 0) {

      pcVar13 = "Invalid parent window handle";

    }

    else if (IVar11 == -1) {

      pcVar13 = "The message box encountered an error.";

    }

    else if (IVar11 - 0x32U < 3) {

      pcVar13 = "Invalid message box pointer in dialog procedure";

    }

    else {

      if (IVar11 != 0x35) goto LAB_1402204e0;

      pcVar13 = "Couldn\'t find dialog control of the default enter-key button";

    }

  }

  else {

    if (IVar11 + -100 < (longlong)(int)param_1[8]) {

      uVar6 = 1;

      *param_2 = *(undefined4 *)(*(longlong *)(param_1 + 10) + -0x63c + IVar11 * 0x10);

      goto LAB_1402204f7;

    }

LAB_1402204e0:

    pcVar13 = "An unknown error occurred";

  }

  FUN_14012e850(pcVar13);

  uVar6 = 0;

LAB_1402204f7:

  FUN_14021f870(puVar8);

  return uVar6;

}




