// Address: 0x14021fae0
// Ghidra name: FUN_14021fae0
// ============ 0x14021fae0 FUN_14021fae0 (size=88) ============


float FUN_14021fae0(void)



{

  int iVar1;

  HDC hdc;

  

  hdc = GetDC((HWND)0x0);

  if (hdc != (HDC)0x0) {

    iVar1 = GetDeviceCaps(hdc,0x58);

    ReleaseDC((HWND)0x0,hdc);

    if (iVar1 != 0) goto LAB_14021fb1e;

  }

  iVar1 = 0x60;

LAB_14021fb1e:

  return (float)iVar1 / DAT_140304040;

}




