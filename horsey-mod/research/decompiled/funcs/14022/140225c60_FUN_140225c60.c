// Address: 0x140225c60
// Ghidra name: FUN_140225c60
// ============ 0x140225c60 FUN_140225c60 (size=994) ============


void FUN_140225c60(longlong param_1,undefined8 param_2,longlong param_3,int *param_4)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  bool bVar5;

  char cVar6;

  int iVar7;

  BOOL BVar8;

  int iVar9;

  undefined4 uVar10;

  undefined8 uVar11;

  undefined8 *puVar12;

  int iVar13;

  longlong lVar14;

  LPCWSTR lpDevice;

  undefined4 uVar15;

  undefined4 local_res18 [2];

  int *local_res20;

  undefined1 local_470 [8];

  undefined8 local_468;

  undefined8 uStack_460;

  undefined8 local_448;

  undefined8 local_440;

  undefined8 uStack_438;

  undefined8 local_428;

  longlong lStack_420;

  undefined8 local_418;

  undefined8 uStack_410;

  undefined8 local_408;

  undefined8 uStack_400;

  undefined8 local_3f8;

  undefined8 uStack_3f0;

  undefined8 local_3e8;

  undefined8 uStack_3e0;

  undefined8 local_3d8;

  undefined8 uStack_3d0;

  undefined8 local_3c8;

  undefined8 uStack_3c0;

  longlong local_3b8;

  undefined8 uStack_3b0;

  undefined8 *local_3a8;

  _DISPLAY_DEVICEW local_398;

  

  iVar9 = *param_4;

  local_res20 = param_4;

  uVar15 = FUN_140226130();

  lpDevice = (LPCWSTR)(param_3 + 0x28);

  uVar11 = FUN_1402261c0(param_1,lpDevice);

  cVar6 = FUN_140226360(param_1,uVar11,param_2,lpDevice,0xffffffff,&local_468,local_470,local_res18)

  ;

  FUN_140227050(uVar11);

  if (cVar6 != '\0') {

    iVar13 = 0;

    if (0 < *(int *)(param_1 + 0x328)) {

      lVar14 = 0;

      do {

        lVar1 = *(longlong *)(*(longlong *)(lVar14 + *(longlong *)(param_1 + 0x330)) + 0x80);

        iVar7 = FUN_14012fbc0(lVar1,lpDevice);

        if (iVar7 == 0) {

          bVar5 = false;

          if ((*(int *)(lVar1 + 0x48) != 2) || (*(int *)(param_1 + 0x328) <= iVar9))

          goto LAB_140226016;

          iVar7 = iVar13;

          if (iVar9 != iVar13) {

            lVar14 = *(longlong *)(param_1 + 0x330);

            uVar11 = *(undefined8 *)(lVar14 + (longlong)iVar9 * 8);

            *(undefined8 *)(lVar14 + (longlong)iVar9 * 8) =

                 *(undefined8 *)(lVar14 + (longlong)iVar13 * 8);

            *(undefined8 *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar13 * 8) = uVar11;

            iVar7 = iVar9;

          }

          *(undefined8 *)(lVar1 + 0x40) = param_2;

          *(undefined4 *)(lVar1 + 0x48) = 0;

          uVar10 = FUN_14016d690(**(undefined4 **)

                                   (*(longlong *)(param_1 + 0x330) + (longlong)iVar7 * 8));

          FUN_140175480(uVar10,"SDL.display.windows.hmonitor",param_2);

          if (*(char *)(param_1 + 0x390) == '\0') {

            uVar11 = *(undefined8 *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar7 * 8);

            FUN_1401700f0(uVar11);

            FUN_140170370(uVar11,&local_468);

            local_448 = 0;

            cVar6 = FUN_1402262e0(param_1,uVar11,&local_440);

            if (cVar6 != '\0') {

              iVar7 = memcmp((void *)(lVar1 + 0x4c),&local_440,0x10);

              if (iVar7 != 0) {

                bVar5 = true;

                *(undefined8 *)(lVar1 + 0x4c) = local_440;

                *(undefined8 *)(lVar1 + 0x54) = uStack_438;

              }

            }

            if ((iVar9 != iVar13) || (bVar5)) {

              FUN_14021a690(uVar11,0x154,0,0);

            }

            FUN_14021a690(uVar11,0x151,local_res18[0],0);

            FUN_140170430(uVar11,uVar15);

            FUN_140226950(param_1,param_2,local_470);

            FUN_1401704a0(uVar11,local_470);

          }

          goto LAB_14022600d;

        }

        iVar13 = iVar13 + 1;

        lVar14 = lVar14 + 8;

      } while (iVar13 < *(int *)(param_1 + 0x328));

    }

    puVar12 = (undefined8 *)FUN_1401841a0(1,0x60);

    if (puVar12 != (undefined8 *)0x0) {

      uVar11 = *(undefined8 *)(param_3 + 0x30);

      *puVar12 = *(undefined8 *)lpDevice;

      puVar12[1] = uVar11;

      uVar11 = *(undefined8 *)(param_3 + 0x40);

      puVar12[2] = *(undefined8 *)(param_3 + 0x38);

      puVar12[3] = uVar11;

      uVar11 = *(undefined8 *)(param_3 + 0x50);

      puVar12[4] = *(undefined8 *)(param_3 + 0x48);

      puVar12[5] = uVar11;

      uVar10 = *(undefined4 *)(param_3 + 0x58);

      uVar2 = *(undefined4 *)(param_3 + 0x5c);

      uVar3 = *(undefined4 *)(param_3 + 0x60);

      uVar4 = *(undefined4 *)(param_3 + 100);

      puVar12[8] = param_2;

      *(undefined4 *)(puVar12 + 9) = 1;

      *(undefined4 *)(puVar12 + 6) = uVar10;

      *(undefined4 *)((longlong)puVar12 + 0x34) = uVar2;

      *(undefined4 *)(puVar12 + 7) = uVar3;

      *(undefined4 *)((longlong)puVar12 + 0x3c) = uVar4;

      local_3a8 = (undefined8 *)0x0;

      local_428 = 0;

      lStack_420 = 0;

      local_418 = 0;

      uStack_410 = 0;

      local_408 = 0;

      uStack_400 = 0;

      local_3f8 = 0;

      uStack_3f0 = 0;

      local_3e8 = 0;

      uStack_3e0 = 0;

      local_3d8 = 0;

      uStack_3d0 = 0;

      local_3c8 = 0;

      uStack_3c0 = 0;

      local_3b8 = 0;

      uStack_3b0 = 0;

      lStack_420 = FUN_140226610(*(undefined8 *)(param_1 + 0x680),lpDevice);

      if (lStack_420 == 0) {

        FUN_1402f94c0(local_398.DeviceName,0,0x344);

        local_398.cb = 0x348;

        BVar8 = EnumDisplayDevicesW(lpDevice,0,&local_398,0);

        if (BVar8 != 0) {

          lVar14 = FUN_14012fd40(local_398.DeviceString);

          lStack_420 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_398.DeviceString,lVar14 * 2 + 2

                                    );

        }

      }

      local_408 = local_468;

      uStack_400 = uStack_460;

      local_3e8 = local_448;

      uStack_3d0 = CONCAT44(uStack_3d0._4_4_,uVar15);

      local_3b8 = param_1;

      local_3a8 = puVar12;

      FUN_1402262e0(param_1,&local_428,(longlong)puVar12 + 0x4c);

      FUN_140226950(param_1,param_2,(longlong)&uStack_3d0 + 4);

      iVar9 = FUN_14016a0c0(&local_428,0);

      if (iVar9 == 0) {

        FUN_1401841e0(puVar12);

      }

      else {

        local_448 = 0;

        uVar15 = FUN_14016d690(iVar9);

        FUN_140175480(uVar15,"SDL.display.windows.hmonitor",param_2);

      }

      FUN_1401841e0(lStack_420);

LAB_14022600d:

      *local_res20 = *local_res20 + 1;

    }

LAB_140226016:

    FUN_1401841e0(local_448);

  }

  return;

}




