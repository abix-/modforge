// Address: 0x14022ccc0
// Ghidra name: FUN_14022ccc0
// ============ 0x14022ccc0 FUN_14022ccc0 (size=688) ============


undefined8

FUN_14022ccc0(undefined8 param_1,longlong param_2,uint *param_3,void **param_4,uint *param_5)



{

  longlong lVar1;

  ulonglong uVar2;

  uint uVar3;

  BITMAPINFO *lpbmi;

  HBITMAP pHVar4;

  HDC pHVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  uint uVar8;

  int local_res10 [2];

  ulonglong uVar9;

  int local_38;

  undefined1 local_34 [12];

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  FUN_14016ebe0(param_2,&local_38,local_res10);

  if (*(HDC *)(lVar1 + 0x20) != (HDC)0x0) {

    DeleteDC(*(HDC *)(lVar1 + 0x20));

  }

  if (*(HGDIOBJ *)(lVar1 + 0x30) != (HGDIOBJ)0x0) {

    DeleteObject(*(HGDIOBJ *)(lVar1 + 0x30));

  }

  lpbmi = (BITMAPINFO *)FUN_1401841f0(0x428);

  if (lpbmi == (BITMAPINFO *)0x0) {

    return 0;

  }

  FUN_1402f94c0(&(lpbmi->bmiHeader).biWidth,0,0x424);

  uVar8 = 1;

  (lpbmi->bmiHeader).biSize = 0x28;

  pHVar4 = CreateCompatibleBitmap(*(HDC *)(lVar1 + 0x18),1,1);

  GetDIBits(*(HDC *)(lVar1 + 0x18),pHVar4,0,0,(LPVOID)0x0,lpbmi,0);

  uVar9 = 0;

  GetDIBits(*(HDC *)(lVar1 + 0x18),pHVar4,0,0,(LPVOID)0x0,lpbmi,0);

  DeleteObject(pHVar4);

  uVar2 = *(ulonglong *)(param_2 + 0x48);

  *param_3 = 0;

  if ((lpbmi->bmiHeader).biCompression == 3) {

    uVar7 = (ulonglong)(lpbmi->bmiHeader).biSize;

    uVar3 = FUN_14017aa70((uint)(lpbmi->bmiHeader).biBitCount * (uint)(lpbmi->bmiHeader).biPlanes,

                          *(undefined4 *)

                           ((longlong)&(((BITMAPINFO *)(lpbmi->bmiColors + -10))->bmiHeader).biSize

                           + uVar7),*(undefined4 *)((longlong)(lpbmi->bmiColors + -9) + uVar7),

                          *(undefined4 *)((longlong)(lpbmi->bmiColors + -8) + uVar7),

                          uVar9 & 0xffffffff00000000);

    *param_3 = uVar3;

    if ((uVar3 != 0) && ((uVar2 & 0x40000000) == 0)) goto LAB_14022ce74;

  }

  uVar3 = 0x16161804;

  if ((uVar2 & 0x40000000) != 0) {

    uVar3 = 0x16362004;

  }

  *param_3 = uVar3;

  FUN_1402f94c0(lpbmi,0,0x428);

  (lpbmi->bmiHeader).biSize = 0x28;

  (lpbmi->bmiHeader).biPlanes = 1;

  (lpbmi->bmiHeader).biBitCount = 0x20;

  (lpbmi->bmiHeader).biCompression = -(uint)((uVar2 & 0x40000000) != 0) & 3;

  if ((uVar2 & 0x40000000) != 0) {

    FUN_14017a540(0x16362004,local_34,lpbmi->bmiColors,lpbmi + 1,&lpbmi[1].bmiHeader.biWidth,

                  &lpbmi[1].bmiHeader.biHeight);

  }

LAB_14022ce74:

  uVar3 = *param_3;

  if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

    uVar8 = uVar3 & 0xff;

  }

  else if ((((uVar3 == 0x32595559) || (uVar3 == 0x59565955)) || (uVar3 == 0x55595659)) ||

          (uVar3 == 0x30313050)) {

    uVar8 = 2;

  }

  *param_5 = uVar8 * local_38 + 3 & 0xfffffffc;

  (lpbmi->bmiHeader).biWidth = local_38;

  (lpbmi->bmiHeader).biHeight = -local_res10[0];

  (lpbmi->bmiHeader).biSizeImage = local_res10[0] * *param_5;

  pHVar5 = CreateCompatibleDC(*(HDC *)(lVar1 + 0x18));

  *(HDC *)(lVar1 + 0x20) = pHVar5;

  pHVar4 = CreateDIBSection(*(HDC *)(lVar1 + 0x18),lpbmi,0,param_4,(HANDLE)0x0,0);

  *(HBITMAP *)(lVar1 + 0x30) = pHVar4;

  FUN_1401841e0(lpbmi);

  if (*(HGDIOBJ *)(lVar1 + 0x30) == (HGDIOBJ)0x0) {

    uVar6 = FUN_1401a9ed0("Unable to create DIB");

    return uVar6;

  }

  SelectObject(*(HDC *)(lVar1 + 0x20),*(HGDIOBJ *)(lVar1 + 0x30));

  return 1;

}




