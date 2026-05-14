// Address: 0x1401e5d40
// Ghidra name: FUN_1401e5d40
// ============ 0x1401e5d40 FUN_1401e5d40 (size=876) ============


undefined1 FUN_1401e5d40(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  undefined1 uVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  

  uVar2 = FUN_14016ea50(param_2);

  lVar4 = FUN_140174d30(uVar2,"SDL.window.win32.hwnd",0);

  if (lVar4 == 0) {

    uVar1 = FUN_14012e850("Couldn\'t get window handle");

    return uVar1;

  }

  uVar5 = FUN_14016e130(param_2);

  if ((uVar5 >> 0x1e & 1) != 0) {

    uVar1 = FUN_14012e850("The direct3d12 renderer doesn\'t work with transparent windows");

    return uVar1;

  }

  FUN_140155450(param_1,param_3);

  if ((*(int *)(param_1 + 0x41) != 0x120005a0) && (*(int *)(param_1 + 0x41) != 0x12000500)) {

    uVar1 = FUN_14012e850("Unsupported output colorspace");

    return uVar1;

  }

  lVar4 = FUN_1401841a0(1,0x42358);

  if (lVar4 != 0) {

    *(undefined8 *)(lVar4 + 0x4230c) = 0x3f800000;

    *(undefined8 *)(lVar4 + 0x42314) = 0;

    *(undefined8 *)(lVar4 + 0x4231c) = 0x3f80000000000000;

    *(undefined8 *)(lVar4 + 0x42324) = 0;

    *(undefined4 *)(lVar4 + 0x4232c) = 0;

    *(undefined4 *)(lVar4 + 0x42330) = 0;

    *(undefined4 *)(lVar4 + 0x42334) = 0x3f800000;

    *(undefined4 *)(lVar4 + 0x42338) = 0;

    *(undefined4 *)(lVar4 + 0x4233c) = 0;

    *(undefined4 *)(lVar4 + 0x42340) = 0;

    *(undefined4 *)(lVar4 + 0x42344) = 0;

    *(undefined4 *)(lVar4 + 0x42348) = 0x3f800000;

    param_1[0x5c] = lVar4;

    *param_1 = &LAB_1401eb200;

    param_1[2] = FUN_1401e44f0;

    param_1[0xe] = FUN_1401e6b30;

    param_1[0xf] = FUN_1401ea350;

    param_1[0x10] = FUN_1401e7c30;

    param_1[3] = FUN_1401e7230;

    param_1[0x12] = FUN_1401ea3b0;

    param_1[0x13] = FUN_1401eab10;

    param_1[0x14] = FUN_1401ea9f0;

    param_1[0x15] = FUN_1401e8370;

    param_1[0x16] = FUN_1401ea0c0;

    param_1[0x17] = FUN_1401e9d30;

    param_1[4] = FUN_140018e60;

    param_1[5] = FUN_140018e60;

    param_1[6] = FUN_1401e2950;

    param_1[7] = FUN_1401e2950;

    param_1[0xb] = FUN_1401e2b00;

    param_1[0xc] = FUN_1401e82b0;

    param_1[0xd] = FUN_1401e90d0;

    param_1[0x18] = FUN_1401e8c00;

    param_1[0x19] = FUN_1401e8a10;

    param_1[0x1a] = FUN_1401e7cc0;

    param_1[0x1b] = FUN_1401e7c80;

    param_1[0x1c] = &LAB_1401e9de0;

    FUN_1401e82b0(param_1);

    param_1[0x20] = PTR_s_direct3d12_1403e4b90;

    FUN_14014b7f0(param_1,0x16362004);

    FUN_14014b7f0(param_1,0x16762004);

    FUN_14014b7f0(param_1,0x16161804);

    FUN_14014b7f0(param_1,0x16772004);

    FUN_14014b7f0(param_1,0x1a204008);

    FUN_14014b7f0(param_1,0x13000801);

    FUN_14014b7f0(param_1,0x32315659);

    FUN_14014b7f0(param_1,0x56555949);

    FUN_14014b7f0(param_1,0x3231564e);

    FUN_14014b7f0(param_1,0x3132564e);

    FUN_14014b7f0(param_1,0x30313050);

    uVar2 = FUN_14014f090(param_1);

    FUN_140175360(uVar2,"SDL.renderer.max_texture_size",0x4000);

    *(undefined4 *)(lVar4 + 0x58) = 0;

    *(undefined4 *)(lVar4 + 0x5c) = 0x200;

    param_1[0x23] = param_2;

    iVar3 = FUN_1401e6200(param_1);

    if (-1 < iVar3) {

      iVar3 = FUN_1401e7960(param_1);

      return -1 < iVar3;

    }

  }

  return false;

}




