// Address: 0x14018d730
// Ghidra name: FUN_14018d730
// ============ 0x14018d730 FUN_14018d730 (size=654) ============


void FUN_14018d730(longlong param_1,char param_2,undefined8 param_3)



{

  undefined8 *puVar1;

  HWND hWnd;

  char cVar2;

  SHORT SVar3;

  int iVar4;

  longlong lVar5;

  HWND pHVar6;

  undefined8 uVar7;

  byte bVar8;

  float fVar9;

  float fVar10;

  tagPOINT local_res8;

  

  puVar1 = *(undefined8 **)(param_1 + 0x188);

  hWnd = (HWND)puVar1[1];

  lVar5 = FUN_140183290();

  pHVar6 = GetForegroundWindow();

  if (((lVar5 == param_1) != (pHVar6 == hWnd)) && ((pHVar6 == hWnd) == (bool)param_2)) {

    if (pHVar6 == hWnd) {

      cVar2 = FUN_14018d6c0(puVar1);

      if ((cVar2 != '\0') && ((*(uint *)(param_1 + 0x48) >> 0xe & 1) == 0)) {

        iVar4 = GetSystemMetrics(0x17);

        SVar3 = GetAsyncKeyState(1);

        if (SVar3 != 0) {

          bVar8 = 4;

          if (iVar4 == 0) {

            bVar8 = 1;

          }

          *(byte *)((longlong)puVar1 + 0x66) = *(byte *)((longlong)puVar1 + 0x66) | bVar8;

        }

        SVar3 = GetAsyncKeyState(2);

        if (SVar3 != 0) {

          bVar8 = 1;

          if (iVar4 == 0) {

            bVar8 = 4;

          }

          *(byte *)((longlong)puVar1 + 0x66) = *(byte *)((longlong)puVar1 + 0x66) | bVar8;

        }

        SVar3 = GetAsyncKeyState(4);

        if (SVar3 != 0) {

          *(byte *)((longlong)puVar1 + 0x66) = *(byte *)((longlong)puVar1 + 0x66) | 2;

        }

        SVar3 = GetAsyncKeyState(5);

        if (SVar3 != 0) {

          *(byte *)((longlong)puVar1 + 0x66) = *(byte *)((longlong)puVar1 + 0x66) | 8;

        }

        SVar3 = GetAsyncKeyState(6);

        if (SVar3 != 0) {

          *(byte *)((longlong)puVar1 + 0x66) = *(byte *)((longlong)puVar1 + 0x66) | 0x10;

        }

      }

      lVar5 = param_1;

      if (*(longlong *)(param_1 + 400) != 0) {

        lVar5 = *(longlong *)(param_1 + 400);

      }

      FUN_140183d70(lVar5);

      lVar5 = FUN_1401611a0();

      if (*(char *)(lVar5 + 0xc1) == '\0') {

        local_res8.x = (LONG)(short)param_3;

        local_res8.y = (LONG)(short)((ulonglong)param_3 >> 0x10);

        ScreenToClient(hWnd,&local_res8);

        fVar9 = (float)local_res8.y;

        fVar10 = (float)local_res8.x;

        uVar7 = FUN_14018c5c0();

        FUN_1401628f0(uVar7,param_1,0,0,fVar10,fVar9);

      }

      uVar7 = FUN_14018c5c0();

      FUN_14018bd90(uVar7,puVar1);

      FUN_14022c8c0(param_1);

      FUN_140220b60(puVar1[0x18]);

      SVar3 = GetKeyState(0x14);

      FUN_140184030(0x2000,(byte)SVar3 & 1);

      SVar3 = GetKeyState(0x90);

      FUN_140184030(0x1000,(byte)SVar3 & 1);

      SVar3 = GetKeyState(0x91);

      FUN_140184030(0x8000,(byte)SVar3 & 1);

      FUN_14022cbd0(*puVar1,1);

    }

    else {

      *(undefined1 *)((longlong)puVar1 + 0x6a) = 1;

      FUN_140183d70(0);

      lVar5 = FUN_1401611a0();

      if (*(char *)(lVar5 + 0xc1) != '\0') {

        FUN_140162ca0(0);

      }

      FUN_140225a20();

      FUN_14022c7f0(param_1);

      *(undefined1 *)((longlong)puVar1 + 0x6a) = 0;

    }

  }

  return;

}




