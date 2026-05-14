// Address: 0x14018d180
// Ghidra name: FUN_14018d180
// ============ 0x14018d180 FUN_14018d180 (size=1090) ============


void FUN_14018d180(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  char cVar3;

  SHORT SVar4;

  DWORD DVar5;

  int iVar6;

  BOOL BVar7;

  longlong lVar8;

  longlong lVar9;

  undefined8 uVar10;

  undefined1 uVar11;

  int iVar12;

  undefined4 uVar13;

  tagPOINT local_res8;

  uint in_stack_ffffffffffffff78;

  tagMSG local_78;

  

  DVar5 = GetTickCount();

  iVar12 = 0;

  if (*(longlong *)(*(longlong *)(param_1 + 0x680) + 0x138) != 0) {

    FUN_140222190(param_1);

  }

  if (DAT_1403e2908 != '\0') {

    DAT_1403fcb98 = 1;

    in_stack_ffffffffffffff78 = 0;

    iVar6 = PeekMessageW(&local_78,(HWND)0x0,0,0,1);

    while (iVar6 != 0) {

      if ((DAT_1403fcba8 == (code *)0x0) ||

         (cVar3 = (*DAT_1403fcba8)(DAT_1403fcbb0,&local_78), cVar3 != '\0')) {

        if ((local_78.message == 0x200) && (DAT_1403fdc60 != 0)) {

          if (0 < (int)((DAT_1403fdc60 - local_78.time) + 1)) goto LAB_14018d261;

          DAT_1403fdc60 = 0;

        }

        FUN_14018d6b0();

        TranslateMessage(&local_78);

        DispatchMessageW(&local_78);

        if (((int)((DVar5 + 1) - local_78.time) < 1) && (iVar12 = iVar12 + 1, 3 < iVar12)) break;

      }

LAB_14018d261:

      in_stack_ffffffffffffff78 = 0;

      iVar6 = PeekMessageW(&local_78,(HWND)0x0,0,0,1);

    }

    DAT_1403fcb98 = 0;

  }

  lVar8 = FUN_140183330(0);

  if ((*(char *)(lVar8 + 0xe1) != '\0') && (SVar4 = GetKeyState(0xa0), -1 < SVar4)) {

    in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffff00;

    FUN_140183990(0,0,0,0xe1,in_stack_ffffffffffffff78);

  }

  if ((*(char *)(lVar8 + 0xe5) != '\0') && (SVar4 = GetKeyState(0xa1), -1 < SVar4)) {

    in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffff00;

    FUN_140183990(0,0,0,0xe5,in_stack_ffffffffffffff78);

  }

  lVar9 = FUN_140183290();

  if ((lVar9 == 0) || ((*(uint *)(lVar9 + 0x48) >> 0x14 & 1) == 0)) {

    if ((*(char *)(lVar8 + 0xe3) != '\0') && (SVar4 = GetKeyState(0x5b), -1 < SVar4)) {

      in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffff00;

      FUN_140183990(0,0,0,0xe3,in_stack_ffffffffffffff78);

    }

    if ((*(char *)(lVar8 + 0xe7) != '\0') && (SVar4 = GetKeyState(0x5c), -1 < SVar4)) {

      FUN_140183990(0,0,0,0xe7,in_stack_ffffffffffffff78 & 0xffffff00);

    }

  }

  for (lVar8 = *(longlong *)(param_1 + 0x348); lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x1a0)) {

    lVar9 = *(longlong *)(lVar8 + 0x188);

    if ((lVar9 != 0) && (*(undefined2 *)(lVar9 + 0x67) = 0, *(char *)(lVar9 + 0x68) != '\0')) {

      FUN_14022c8c0(lVar8);

    }

  }

  lVar8 = FUN_140183290();

  if ((((lVar8 != 0) && ((*(uint *)(lVar8 + 0x48) >> 0xe & 1) != 0)) &&

      (puVar1 = *(undefined8 **)(lVar8 + 0x188), *(char *)((longlong)puVar1 + 0xac) == '\0')) &&

     ((BVar7 = GetCursorPos(&local_res8), BVar7 != 0 &&

      (BVar7 = ScreenToClient((HWND)puVar1[1],&local_res8), BVar7 != 0)))) {

    iVar12 = GetSystemMetrics(0x17);

    uVar2 = *puVar1;

    uVar10 = FUN_14018c5c0();

    FUN_1401628f0(uVar10,uVar2,0,0,(float)local_res8.x,(float)local_res8.y);

    SVar4 = GetAsyncKeyState(1);

    uVar2 = *puVar1;

    uVar11 = 3;

    if (iVar12 == 0) {

      uVar11 = 1;

    }

    uVar10 = FUN_14018c5c0();

    FUN_1401628d0(uVar10,uVar2,0,uVar11,(byte)((ushort)SVar4 >> 0xf));

    SVar4 = GetAsyncKeyState(2);

    uVar2 = *puVar1;

    uVar13 = 1;

    if (iVar12 == 0) {

      uVar13 = 3;

    }

    uVar10 = FUN_14018c5c0();

    FUN_1401628d0(uVar10,uVar2,0,uVar13,(byte)((ushort)SVar4 >> 0xf));

    SVar4 = GetAsyncKeyState(4);

    uVar2 = *puVar1;

    uVar10 = FUN_14018c5c0();

    FUN_1401628d0(uVar10,uVar2,0,2,(byte)((ushort)SVar4 >> 0xf));

    SVar4 = GetAsyncKeyState(5);

    uVar2 = *puVar1;

    uVar10 = FUN_14018c5c0();

    FUN_1401628d0(uVar10,uVar2,0,4,(byte)((ushort)SVar4 >> 0xf));

    SVar4 = GetAsyncKeyState(6);

    uVar2 = *puVar1;

    uVar10 = FUN_14018c5c0();

    FUN_1401628d0(uVar10,uVar2,0,5,(byte)((ushort)SVar4 >> 0xf));

  }

  FUN_140225b90(param_1);

  return;

}




