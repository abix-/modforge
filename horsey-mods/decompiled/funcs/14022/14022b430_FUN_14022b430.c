// Address: 0x14022b430
// Ghidra name: FUN_14022b430
// ============ 0x14022b430 FUN_14022b430 (size=279) ============


undefined8

FUN_14022b430(undefined8 param_1,longlong param_2,int *param_3,int *param_4,int *param_5,

             int *param_6)



{

  HWND hWnd;

  BOOL BVar1;

  DWORD DVar2;

  undefined8 uVar3;

  tagPOINT local_res10;

  tagRECT local_28;

  tagRECT local_18;

  

  hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  BVar1 = GetClientRect(hWnd,&local_18);

  if (BVar1 == 0) {

    DVar2 = GetLastError();

    uVar3 = FUN_14012e850("GetClientRect() failed, error %08X",DVar2);

  }

  else {

    BVar1 = GetWindowRect(hWnd,&local_28);

    if (BVar1 == 0) {

      DVar2 = GetLastError();

      uVar3 = FUN_14012e850("GetWindowRect() failed, error %08X",DVar2);

    }

    else {

      local_res10.y = local_28.top;

      local_res10.x = local_28.left;

      BVar1 = ScreenToClient(hWnd,&local_res10);

      if (BVar1 != 0) {

        local_28.top = local_res10.y;

        local_28.left = local_res10.x;

        local_res10.y = local_28.bottom;

        local_res10.x = local_28.right;

        BVar1 = ScreenToClient(hWnd,&local_res10);

        if (BVar1 != 0) {

          *param_3 = local_18.top - local_28.top;

          *param_4 = local_18.left - local_28.left;

          *param_5 = local_res10.y - local_18.bottom;

          *param_6 = local_res10.x - local_18.right;

          return 1;

        }

      }

      DVar2 = GetLastError();

      uVar3 = FUN_14012e850("ScreenToClient() failed, error %08X",DVar2);

    }

  }

  return uVar3;

}




