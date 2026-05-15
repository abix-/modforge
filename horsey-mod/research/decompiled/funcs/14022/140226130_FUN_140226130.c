// Address: 0x140226130
// Ghidra name: FUN_140226130
// ============ 0x140226130 FUN_140226130 (size=141) ============


float FUN_140226130(longlong param_1,undefined8 param_2)



{

  code *pcVar1;

  int iVar2;

  HDC hdc;

  int local_res8 [2];

  undefined1 local_res18 [16];

  

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x680) + 0xd8);

  if (((pcVar1 == (code *)0x0) || (iVar2 = (*pcVar1)(param_2,0,local_res8,local_res18), iVar2 != 0))

     || (iVar2 = local_res8[0], local_res8[0] == 0)) {

    hdc = GetDC((HWND)0x0);

    if (hdc != (HDC)0x0) {

      iVar2 = GetDeviceCaps(hdc,0x58);

      ReleaseDC((HWND)0x0,hdc);

      if (iVar2 != 0) goto LAB_1402261a8;

    }

    iVar2 = 0x60;

  }

LAB_1402261a8:

  return (float)iVar2 / DAT_140304040;

}




