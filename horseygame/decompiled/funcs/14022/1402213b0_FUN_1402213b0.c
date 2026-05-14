// Address: 0x1402213b0
// Ghidra name: FUN_1402213b0
// ============ 0x1402213b0 FUN_1402213b0 (size=356) ============


undefined8 FUN_1402213b0(longlong param_1,char *param_2)



{

  int iVar1;

  UINT uFormat;

  undefined8 uVar2;

  HGLOBAL hMem;

  LPVOID pvVar3;

  HANDLE pvVar4;

  UINT local_res8 [2];

  SIZE_T local_res18;

  

  local_res8[0] = 0;

  uVar2 = (**(code **)(param_1 + 0x360))(*(undefined8 *)(param_1 + 0x370),param_2,&local_res18);

  iVar1 = strcmp(param_2,"image/bmp");

  if (iVar1 == 0) {

    hMem = (HGLOBAL)FUN_140220bd0(uVar2,local_res18,local_res8);

    uFormat = local_res8[0];

    if (hMem == (HANDLE)0x0) {

      return 0;

    }

  }

  else {

    iVar1 = strcmp(param_2,"image/png");

    if (iVar1 != 0) {

      FUN_14012e850("Unknown image format");

      return 0;

    }

    uFormat = FUN_1402209e0();

    hMem = GlobalAlloc(2,local_res18);

    if (hMem == (HGLOBAL)0x0) {

      FUN_14012e770();

      return 0;

    }

    pvVar3 = GlobalLock(hMem);

    if (pvVar3 == (LPVOID)0x0) {

      FUN_1401a9ed0("GlobalLock()");

      GlobalFree(hMem);

      return 0;

    }

    FUN_1402f8e20(pvVar3,uVar2,local_res18);

    GlobalUnlock(hMem);

  }

  pvVar4 = SetClipboardData(uFormat,hMem);

  if (pvVar4 == (HANDLE)0x0) {

    uVar2 = FUN_1401a9ed0("Couldn\'t set clipboard data");

    return uVar2;

  }

  return 1;

}




