// Address: 0x140286550
// Ghidra name: FUN_140286550
// ============ 0x140286550 FUN_140286550 (size=435) ============


undefined8 FUN_140286550(void)



{

  char cVar1;

  int iVar2;

  HRESULT HVar3;

  DWORD DVar4;

  undefined8 uVar5;

  HMODULE pHVar6;

  uint uVar7;

  undefined **ppuVar8;

  int local_res8 [2];

  

  cVar1 = FUN_140142940("SDL_JOYSTICK_DIRECTINPUT",1);

  if (cVar1 == '\0') {

    DAT_1403fde50 = (longlong *)0x0;

    return 1;

  }

  iVar2 = FUN_1401a9610();

  if (iVar2 < 0) {

    uVar5 = FUN_140286ef0("CoInitialize",iVar2);

    return uVar5;

  }

  DAT_1403fde48 = 1;

  HVar3 = CoCreateInstance((IID *)&DAT_140350a20,(LPUNKNOWN)0x0,1,(IID *)&DAT_140350a30,

                           &DAT_1403fde50);

  if (HVar3 < 0) {

    uVar5 = FUN_140286ef0("CoCreateInstance",HVar3);

    return uVar5;

  }

  pHVar6 = GetModuleHandleW((LPCWSTR)0x0);

  if (pHVar6 == (HMODULE)0x0) {

    (**(code **)(*DAT_1403fde50 + 0x10))();

    DAT_1403fde50 = (longlong *)0x0;

    DVar4 = GetLastError();

    uVar5 = FUN_14012e850("GetModuleHandle() failed with error code %lu.",DVar4);

    return uVar5;

  }

  iVar2 = (**(code **)(*DAT_1403fde50 + 0x38))(DAT_1403fde50,pHVar6,0x800);

  if (iVar2 < 0) {

    (**(code **)(*DAT_1403fde50 + 0x10))();

    DAT_1403fde50 = (longlong *)0x0;

    uVar5 = FUN_140286ef0("IDirectInput::Initialize",iVar2);

    return uVar5;

  }

  cVar1 = FUN_140142940("SDL_JOYSTICK_CHECK_EZFRD64",1);

  if (cVar1 != '\0') {

    uVar7 = 0;

    ppuVar8 = &PTR_s_C__Windows_USB_Vibration_1403e7990;

    do {

      if (DAT_1403fde49 != '\0') goto LAB_1402866e0;

      local_res8[0] = 0;

      uVar5 = FUN_140178bd0(*ppuVar8,"*/EZFRD64.DLL",1,local_res8);

      if (0 < local_res8[0]) {

        DAT_1403fde49 = '\x01';

      }

      FUN_1401841e0(uVar5);

      uVar7 = uVar7 + 1;

      ppuVar8 = ppuVar8 + 1;

    } while (uVar7 < 2);

    if (DAT_1403fde49 != '\0') {

LAB_1402866e0:

      FUN_14012e2e0(7,"Broken EZFRD64.DLL detected, disabling DirectInput force feedback");

    }

  }

  return 1;

}




