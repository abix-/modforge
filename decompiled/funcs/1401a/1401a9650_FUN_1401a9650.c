// Address: 0x1401a9650
// Ghidra name: FUN_1401a9650
// ============ 0x1401a9650 FUN_1401a9650 (size=655) ============


HICON FUN_1401a9650(undefined8 param_1)



{

  int nWidth;

  int nHeight;

  longlong lVar1;

  HDC hdc;

  HBITMAP ho;

  HBITMAP h;

  HDC hdc_00;

  HGDIOBJ h_00;

  HICON pHVar2;

  int x;

  int y;

  longlong lVar3;

  void *local_res10;

  HDC local_res18;

  HBITMAP local_res20;

  ICONINFO local_88;

  BITMAPINFO local_68;

  

  lVar1 = FUN_140145bb0(param_1,0x16362004);

  if (lVar1 != 0) {

    nWidth = *(int *)(lVar1 + 8);

    y = 0;

    nHeight = *(int *)(lVar1 + 0xc);

    local_68.bmiHeader.biHeight = -nHeight;

    local_68.bmiHeader.biSizeImage = 0;

    local_68.bmiHeader.biXPelsPerMeter = 0;

    local_68.bmiHeader.biYPelsPerMeter = 0;

    local_68.bmiHeader.biClrUsed = 0;

    local_68.bmiHeader.biClrImportant = 0;

    local_68.bmiColors[0].rgbBlue = '\0';

    local_68.bmiColors[0].rgbGreen = '\0';

    local_68.bmiColors[0].rgbRed = '\0';

    local_68.bmiColors[0].rgbReserved = '\0';

    local_68.bmiHeader.biSize = 0x28;

    local_68.bmiHeader.biPlanes = 1;

    local_68.bmiHeader.biBitCount = 0x20;

    local_68.bmiHeader.biCompression = 0;

    local_68.bmiHeader.biWidth = nWidth;

    hdc = GetDC((HWND)0x0);

    local_res10 = (void *)0x0;

    local_res18 = hdc;

    ho = CreateDIBSection(hdc,&local_68,0,&local_res10,(HANDLE)0x0,0);

    local_res20 = ho;

    if (ho == (HBITMAP)0x0) {

      ReleaseDC((HWND)0x0,hdc);

      FUN_140146010(lVar1);

      pHVar2 = (HICON)0x0;

    }

    else {

      FUN_1402f8e20(local_res10,*(undefined8 *)(lVar1 + 0x18),(longlong)(nHeight * nWidth * 4));

      FUN_140146010(lVar1);

      h = CreateBitmap(nWidth,nHeight,1,1,(void *)0x0);

      if (h == (HBITMAP)0x0) {

        DeleteObject(ho);

        ReleaseDC((HWND)0x0,hdc);

        pHVar2 = (HICON)0x0;

      }

      else {

        hdc_00 = CreateCompatibleDC(hdc);

        h_00 = SelectObject(hdc_00,h);

        if (0 < nHeight) {

          lVar1 = 0;

          do {

            x = 0;

            lVar3 = lVar1;

            if (0 < nWidth) {

              do {

                SetPixel(hdc_00,x,y,

                         -(uint)(*(char *)(lVar3 + 3 + (longlong)local_res10) != '\0') & 0xffffff);

                x = x + 1;

                lVar3 = lVar3 + 4;

              } while (x < nWidth);

            }

            y = y + 1;

            lVar1 = lVar1 + (longlong)nWidth * 4;

            hdc = local_res18;

            ho = local_res20;

          } while (y < nHeight);

        }

        local_88.fIcon = 1;

        local_88.xHotspot = 0;

        local_88.yHotspot = 0;

        local_88.hbmMask = h;

        local_88.hbmColor = ho;

        pHVar2 = CreateIconIndirect(&local_88);

        SelectObject(hdc_00,h_00);

        DeleteDC(hdc_00);

        DeleteObject(ho);

        DeleteObject(h);

        ReleaseDC((HWND)0x0,hdc);

      }

    }

    return pHVar2;

  }

  return (HICON)0x0;

}




