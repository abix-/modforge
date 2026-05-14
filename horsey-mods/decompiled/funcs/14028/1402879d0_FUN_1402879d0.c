// Address: 0x1402879d0
// Ghidra name: FUN_1402879d0
// ============ 0x1402879d0 FUN_1402879d0 (size=423) ============


undefined8 FUN_1402879d0(void)



{

  char cVar1;

  int iVar2;

  HRESULT HVar3;

  DWORD DVar4;

  undefined8 uVar5;

  HMODULE pHVar6;

  uint uVar7;

  bool bVar8;

  undefined8 *puVar9;

  undefined4 uVar10;

  

  if (DAT_1403fde60 != (longlong *)0x0) {

    uVar5 = FUN_14012e850("Haptic: SubSystem already open.");

    return uVar5;

  }

  cVar1 = FUN_140142940("SDL_JOYSTICK_DIRECTINPUT",1);

  if (cVar1 != '\0') {

    iVar2 = FUN_1401a9610();

    if (iVar2 < 0) {

      uVar5 = FUN_1402878d0("Coinitialize",iVar2);

      return uVar5;

    }

    DAT_1403fde58 = 1;

    uVar7 = 1;

    puVar9 = &DAT_1403fde60;

    HVar3 = CoCreateInstance((IID *)&DAT_140350a20,(LPUNKNOWN)0x0,1,(IID *)&DAT_140350a30,

                             &DAT_1403fde60);

    if (HVar3 < 0) {

      FUN_14021ada0();

      uVar5 = FUN_1402878d0("CoCreateInstance",HVar3);

      return uVar5;

    }

    pHVar6 = GetModuleHandleW((LPCWSTR)0x0);

    if (pHVar6 == (HMODULE)0x0) {

      FUN_14021ada0();

      DVar4 = GetLastError();

      uVar5 = FUN_14012e850("GetModuleHandle() failed with error code %lu.",DVar4);

      return uVar5;

    }

    iVar2 = (**(code **)(*DAT_1403fde60 + 0x38))(DAT_1403fde60,pHVar6,0x800);

    if (iVar2 < 0) {

      FUN_14021ada0();

      uVar5 = FUN_1402878d0("Initializing DirectInput device",iVar2);

      return uVar5;

    }

    bVar8 = false;

    do {

      uVar10 = (undefined4)((ulonglong)puVar9 >> 0x20);

      if (bVar8) {

        iVar2 = FUN_14017ec60(0x200);

        uVar10 = (undefined4)((ulonglong)puVar9 >> 0x20);

        if (iVar2 == 0) goto LAB_140287b13;

      }

      else {

LAB_140287b13:

        puVar9 = (undefined8 *)CONCAT44(uVar10,0x101);

        iVar2 = (**(code **)(*DAT_1403fde60 + 0x20))(DAT_1403fde60,uVar7,FUN_1402878e0,0,puVar9);

        if (iVar2 < 0) {

          FUN_14021ada0();

          uVar5 = FUN_1402878d0("Enumerating DirectInput devices",iVar2);

          return uVar5;

        }

      }

      uVar7 = uVar7 + 1;

      bVar8 = uVar7 == 4;

    } while (uVar7 < 5);

  }

  return 1;

}




