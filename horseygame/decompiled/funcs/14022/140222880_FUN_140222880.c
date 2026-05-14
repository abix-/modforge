// Address: 0x140222880
// Ghidra name: FUN_140222880
// ============ 0x140222880 FUN_140222880 (size=479) ============


undefined4 FUN_140222880(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  int format;

  HWND hWnd;

  HDC hdc;

  longlong lVar1;

  char *pcVar2;

  undefined4 local_res8 [2];

  undefined4 local_res20 [2];

  undefined4 local_58;

  undefined1 local_54 [4];

  PIXELFORMATDESCRIPTOR local_50;

  

  local_res8[0] = 0;

  hWnd = CreateWindowExW(0,DAT_1403fcb80,DAT_1403fcb80,0x88000000,0,0,10,10,(HWND)0x0,(HMENU)0x0,

                         DAT_1403fcb90,(LPVOID)0x0);

  FUN_14018d5d0(param_1,hWnd);

  hdc = GetDC(hWnd);

  FUN_140223490(param_1,&local_50);

  format = ChoosePixelFormat(hdc,&local_50);

  SetPixelFormat(hdc,format,&local_50);

  lVar1 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x18))(hdc);

  if (lVar1 != 0) {

    (**(code **)(*(longlong *)(param_1 + 0x688) + 0x28))(hdc,lVar1);

    pcVar2 = *(char **)(param_1 + 0x688);

    if (*pcVar2 != '\0') {

      (**(code **)(pcVar2 + 0x38))(hdc,param_2,param_3,1,local_res8,local_54);

      pcVar2 = *(char **)(param_1 + 0x688);

      local_res20[0] = 0;

      if (pcVar2[7] != '\0') {

        local_58 = 0x20a9;

        (**(code **)(pcVar2 + 0x40))(hdc,local_res8[0],0,1,&local_58,local_res20);

        pcVar2 = *(char **)(param_1 + 0x688);

      }

      *(undefined4 *)(param_1 + 0x400) = local_res20[0];

    }

    (**(code **)(pcVar2 + 0x28))(hdc,0);

    (**(code **)(*(longlong *)(param_1 + 0x688) + 0x20))(lVar1);

  }

  ReleaseDC(hWnd,hdc);

  DestroyWindow(hWnd);

  FUN_14018d5d0(param_1,hWnd);

  return local_res8[0];

}




