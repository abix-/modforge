// Address: 0x1401e0ab0
// Ghidra name: FUN_1401e0ab0
// ============ 0x1401e0ab0 FUN_1401e0ab0 (size=853) ============


undefined8 FUN_1401e0ab0(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  uVar1 = FUN_14016ea50(param_2);

  lVar3 = FUN_140174d30(uVar1,"SDL.window.win32.hwnd",0);

  if (lVar3 == 0) {

    uVar4 = FUN_14012e850("Couldn\'t get window handle");

    return uVar4;

  }

  FUN_140155450(param_1,param_3);

  if ((*(int *)(param_1 + 0x41) != 0x120005a0) && (*(int *)(param_1 + 0x41) != 0x12000500)) {

    uVar4 = FUN_14012e850("Unsupported output colorspace");

    return uVar4;

  }

  lVar3 = FUN_1401841a0(1,0x490);

  if (lVar3 != 0) {

    *(undefined8 *)(lVar3 + 0x44c) = 0x3f800000;

    *(undefined8 *)(lVar3 + 0x454) = 0;

    *(undefined8 *)(lVar3 + 0x45c) = 0x3f80000000000000;

    *(undefined8 *)(lVar3 + 0x464) = 0;

    *(undefined4 *)(lVar3 + 0x46c) = 0;

    *(undefined4 *)(lVar3 + 0x470) = 0;

    *(undefined4 *)(lVar3 + 0x474) = 0x3f800000;

    *(undefined4 *)(lVar3 + 0x478) = 0;

    *(undefined4 *)(lVar3 + 0x47c) = 0;

    *(undefined4 *)(lVar3 + 0x480) = 0;

    *(undefined4 *)(lVar3 + 0x484) = 0;

    *(undefined4 *)(lVar3 + 0x488) = 0x3f800000;

    param_1[0x5c] = lVar3;

    *param_1 = &LAB_1401e56c0;

    param_1[2] = FUN_1401e44f0;

    param_1[0xe] = FUN_1401e1650;

    param_1[0xf] = FUN_1401e46f0;

    param_1[0x10] = FUN_1401e20f0;

    param_1[3] = FUN_1401e1a10;

    param_1[0x12] = FUN_1401e47b0;

    param_1[0x13] = FUN_1401e4f80;

    param_1[0x14] = FUN_1401e4c50;

    param_1[0x15] = FUN_1401e2730;

    param_1[0x16] = FUN_1401e45b0;

    param_1[0x17] = &LAB_1401e4220;

    param_1[4] = FUN_140018e60;

    param_1[5] = FUN_140018e60;

    param_1[6] = FUN_1401e2950;

    param_1[7] = FUN_1401e2950;

    param_1[0xb] = FUN_1401e2b00;

    param_1[0xc] = FUN_1401e26c0;

    param_1[0xd] = FUN_1401e3700;

    param_1[0x18] = FUN_1401e34c0;

    param_1[0x19] = FUN_1401e33c0;

    param_1[0x1a] = FUN_1401e2180;

    param_1[0x1b] = FUN_1401e2150;

    param_1[0x1c] = FUN_1401e4260;

    FUN_1401e26c0(param_1);

    param_1[0x20] = PTR_s_direct3d11_1403e4b80;

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

    *(undefined4 *)(lVar3 + 0x44) = 8;

    *(undefined8 *)(lVar3 + 0x3c) = 0;

    param_1[0x23] = param_2;

    iVar2 = FUN_1401e0fc0(param_1);

    if (-1 < iVar2) {

      iVar2 = FUN_1401e1e80(param_1);

      if (-1 < iVar2) {

        if (0xb0ff < *(int *)(lVar3 + 0x158)) {

          iVar2 = FUN_1401a9950();

          if (iVar2 != 0) {

            FUN_14014b7f0(param_1,0x15151002);

            FUN_14014b7f0(param_1,0x15331002);

          }

        }

        return 1;

      }

    }

  }

  return 0;

}




