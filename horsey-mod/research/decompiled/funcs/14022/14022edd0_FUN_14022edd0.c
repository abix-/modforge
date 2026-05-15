// Address: 0x14022edd0
// Ghidra name: FUN_14022edd0
// ============ 0x14022edd0 FUN_14022edd0 (size=481) ============


void FUN_14022edd0(longlong *param_1)



{

  char *_Str;

  longlong lVar1;

  code *pcVar2;

  char cVar3;

  undefined4 uVar4;

  HWND pHVar5;

  size_t sVar6;

  HWND pHVar7;

  LPITEMIDLIST pidl;

  longlong lVar8;

  undefined8 uVar9;

  undefined8 *puVar10;

  undefined8 local_res8;

  undefined8 local_288;

  undefined8 local_280;

  _browseinfoW local_278;

  WCHAR local_238 [264];

  

  pHVar7 = (HWND)0x0;

  _Str = (char *)param_1[5];

  lVar8 = *param_1;

  lVar1 = param_1[4];

  pcVar2 = (code *)param_1[2];

  cVar3 = FUN_14022efc0(2,param_1[3],lVar8,(char)param_1[1] != '\0',pcVar2,lVar1,_Str,param_1[6],

                        param_1[7],0,0);

  if (cVar3 != '\0') {

    return;

  }

  pHVar5 = pHVar7;

  if (lVar8 != 0) {

    uVar4 = FUN_14016ea50(lVar8);

    pHVar5 = (HWND)FUN_140174d30(uVar4,"SDL.window.win32.hwnd",0);

  }

  if (_Str != (char *)0x0) {

    sVar6 = strlen(_Str);

    pHVar7 = (HWND)FUN_140197820("UTF-16LE",&DAT_14039c6f0,_Str,sVar6 + 1);

    if (pHVar7 == (HWND)0x0) {

      puVar10 = (undefined8 *)0x0;

      goto LAB_14022ef8a;

    }

  }

  local_278.pszDisplayName = local_238;

  local_278.pidlRoot = (LPCITEMIDLIST)0x0;

  local_278.lpfn = FUN_14022e520;

  local_278.lParam = param_1[3];

  local_278.ulFlags = 0x50;

  local_278.iImage = 0;

  local_278.hwndOwner = pHVar5;

  local_278.lpszTitle = (LPCWSTR)pHVar7;

  pidl = SHBrowseForFolderW(&local_278);

  FUN_1401841e0(pHVar7);

  if (pidl != (LPITEMIDLIST)0x0) {

    SHGetPathFromIDListW(pidl,local_238);

    lVar8 = FUN_14012fd40(local_238);

    uVar9 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_238,lVar8 * 2 + 2);

    local_280 = 0;

    local_288 = uVar9;

    (*pcVar2)(lVar1,&local_288,0xffffffff);

    FUN_1401841e0(uVar9);

    return;

  }

  local_res8 = 0;

  puVar10 = &local_res8;

LAB_14022ef8a:

  (*pcVar2)(lVar1,puVar10,0xffffffff);

  return;

}




