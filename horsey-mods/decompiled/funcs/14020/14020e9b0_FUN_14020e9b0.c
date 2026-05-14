// Address: 0x14020e9b0
// Ghidra name: FUN_14020e9b0
// ============ 0x14020e9b0 FUN_14020e9b0 (size=488) ============


void FUN_14020e9b0(void)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 local_res8 [4];

  undefined1 local_28 [40];

  

  if (DAT_1403fd2a8 == (undefined8 *)0x0) {

    uVar2 = FUN_14012fd40(L"Windows.Gaming.Input.ArcadeStick");

    iVar1 = (*DAT_1403fd288)(L"Windows.Gaming.Input.ArcadeStick",uVar2,local_28,local_res8);

    if (-1 < iVar1) {

      iVar1 = (*DAT_1403fd280)(local_res8[0],&DAT_140350568,&DAT_1403fd2a8);

      if (iVar1 < 0) {

        FUN_1401a9ef0("Couldn\'t find Windows.Gaming.Input.IArcadeStickStatics",iVar1);

      }

      else {

        (**(code **)*DAT_1403fd2a8)(DAT_1403fd2a8,&DAT_140350578,&DAT_1403fd2b0);

      }

    }

  }

  if (DAT_1403fd2b8 == 0) {

    uVar2 = FUN_14012fd40(L"Windows.Gaming.Input.FlightStick");

    iVar1 = (*DAT_1403fd288)(L"Windows.Gaming.Input.FlightStick",uVar2,local_28,local_res8);

    if (-1 < iVar1) {

      iVar1 = (*DAT_1403fd280)(local_res8[0],&DAT_140350588,&DAT_1403fd2b8);

      if (iVar1 < 0) {

        FUN_1401a9ef0("Couldn\'t find Windows.Gaming.Input.IFlightStickStatics",iVar1);

      }

    }

  }

  if (DAT_1403fd2c0 == (undefined8 *)0x0) {

    uVar2 = FUN_14012fd40(L"Windows.Gaming.Input.Gamepad");

    iVar1 = (*DAT_1403fd288)(L"Windows.Gaming.Input.Gamepad",uVar2,local_28,local_res8);

    if (-1 < iVar1) {

      iVar1 = (*DAT_1403fd280)(local_res8[0],&DAT_1403505b8,&DAT_1403fd2c0);

      if (iVar1 < 0) {

        FUN_1401a9ef0("Couldn\'t find Windows.Gaming.Input.IGamepadStatics",iVar1);

      }

      else {

        (**(code **)*DAT_1403fd2c0)(DAT_1403fd2c0,&DAT_1403505c8,&DAT_1403fd2c8);

      }

    }

  }

  if (DAT_1403fd2d0 == (undefined8 *)0x0) {

    uVar2 = FUN_14012fd40(L"Windows.Gaming.Input.RacingWheel");

    iVar1 = (*DAT_1403fd288)(L"Windows.Gaming.Input.RacingWheel",uVar2,local_28,local_res8);

    if (-1 < iVar1) {

      iVar1 = (*DAT_1403fd280)(local_res8[0],&DAT_1403505d8,&DAT_1403fd2d0);

      if (-1 < iVar1) {

        (**(code **)*DAT_1403fd2d0)(DAT_1403fd2d0,&DAT_1403505e8,&DAT_1403fd2d8);

        return;

      }

      FUN_1401a9ef0("Couldn\'t find Windows.Gaming.Input.IRacingWheelStatics",iVar1);

    }

  }

  return;

}




