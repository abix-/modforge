// Address: 0x14020a730
// Ghidra name: FUN_14020a730
// ============ 0x14020a730 FUN_14020a730 (size=309) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14020a730(void)



{

  char cVar1;

  int iVar2;

  code *pcVar3;

  code *pcVar4;

  undefined8 uVar5;

  undefined8 local_res10 [3];

  undefined1 local_28 [32];

  

  cVar1 = FUN_140142940("SDL_JOYSTICK_WGI",1);

  if (cVar1 != '\0') {

    _DAT_1403fd240 = _DAT_1403fd240 + 1;

    if ((DAT_1403fd23c == '\0') && (iVar2 = FUN_1401a9e50(), -1 < iVar2)) {

      _DAT_1403fd23c = 0x101;

      pcVar3 = (code *)FUN_1401a9aa0("WindowsCreateStringReference");

      pcVar4 = (code *)FUN_1401a9aa0("RoGetActivationFactory");

      if ((pcVar3 != (code *)0x0) && (pcVar4 != (code *)0x0)) {

        uVar5 = FUN_14012fd40(L"Windows.Gaming.Input.Gamepad");

        iVar2 = (*pcVar3)(L"Windows.Gaming.Input.Gamepad",uVar5,local_28,local_res10);

        if (-1 < iVar2) {

          (*pcVar4)(local_res10[0],&DAT_14034ffc0,&DAT_1403fd248);

        }

        if (DAT_1403fd248 != (longlong *)0x0) {

          DAT_1403fd23e = 1;

          iVar2 = (**(code **)(*DAT_1403fd248 + 0x30))

                            (DAT_1403fd248,&PTR_PTR_1403e4ef0,&DAT_1403fd250);

          if (iVar2 < 0) {

            FUN_14012e850("add_GamepadAdded() failed: 0x%lx",iVar2);

          }

          iVar2 = (**(code **)(*DAT_1403fd248 + 0x40))

                            (DAT_1403fd248,&PTR_PTR_1403e4f20,&DAT_1403fd258);

          if (iVar2 < 0) {

            FUN_14012e850("add_GamepadRemoved() failed: 0x%lx",iVar2);

          }

        }

      }

    }

  }

  return;

}




