// Address: 0x140227160
// Ghidra name: FUN_140227160
// ============ 0x140227160 FUN_140227160 (size=459) ============


void FUN_140227160(undefined8 param_1,LPCWSTR param_2,int param_3,longlong param_4)



{

  longlong lVar1;

  HDC hdc;

  HBITMAP hbm;

  tagBITMAPINFO local_438 [24];

  

  lVar1 = *(longlong *)(param_4 + 0x20);

  *(undefined4 *)(lVar1 + 0x48) = 0x7c0000;

  if ((param_3 == -1) &&

     (hdc = CreateDCW(param_2,(LPCWSTR)0x0,(LPCWSTR)0x0,(DEVMODEW *)0x0), hdc != (HDC)0x0)) {

    FUN_1402f94c0(&local_438[0].bmiHeader.biWidth,0,0x424);

    local_438[0].bmiHeader.biSize = 0x28;

    hbm = CreateCompatibleBitmap(hdc,1,1);

    GetDIBits(hdc,hbm,0,1,(LPVOID)0x0,local_438,0);

    GetDIBits(hdc,hbm,0,1,(LPVOID)0x0,local_438,0);

    DeleteObject(hbm);

    DeleteDC(hdc);

    if (local_438[0].bmiHeader.biCompression != 3) {

      if (local_438[0].bmiHeader.biCompression != 0) {

        return;

      }

      if (local_438[0].bmiHeader.biBitCount != 0x18) {

        if (local_438[0].bmiHeader.biBitCount != 8) {

          if (local_438[0].bmiHeader.biBitCount != 4) {

            return;

          }

          goto switchD_1402272fc_caseD_4;

        }

        goto switchD_1402272fc_caseD_8;

      }

switchD_1402272fc_caseD_18:

      *(undefined4 *)(param_4 + 4) = 0x17101803;

      return;

    }

    if (local_438[0].bmiColors[0] == (RGBQUAD)0xff) {

      *(undefined4 *)(param_4 + 4) = 0x16561804;

      return;

    }

    if (local_438[0].bmiColors[0] == (RGBQUAD)0x7c00) goto switchD_1402272fc_caseD_f;

    if (local_438[0].bmiColors[0] != (RGBQUAD)0xf800) {

      if (local_438[0].bmiColors[0] != (RGBQUAD)0xff0000) {

        return;

      }

      *(undefined4 *)(param_4 + 4) = 0x16161804;

      return;

    }

switchD_1402272fc_caseD_10:

    *(undefined4 *)(param_4 + 4) = 0x15151002;

  }

  else {

    if (*(int *)(param_4 + 4) != 0) {

      return;

    }

    if ((*(uint *)(lVar1 + 0x48) & 0x40000) == 0) {

      return;

    }

    switch(*(undefined4 *)(lVar1 + 0xa8)) {

    case 4:

switchD_1402272fc_caseD_4:

      *(undefined4 *)(param_4 + 4) = 0x12100400;

      return;

    case 8:

switchD_1402272fc_caseD_8:

      *(undefined4 *)(param_4 + 4) = 0x13000801;

      return;

    case 0xf:

switchD_1402272fc_caseD_f:

      *(undefined4 *)(param_4 + 4) = 0x15130f02;

      break;

    case 0x10:

      goto switchD_1402272fc_caseD_10;

    case 0x18:

      goto switchD_1402272fc_caseD_18;

    case 0x20:

      *(undefined4 *)(param_4 + 4) = 0x16161804;

    }

  }

  return;

}




