// Address: 0x14020d890
// Ghidra name: FUN_14020d890
// ============ 0x14020d890 FUN_14020d890 (size=604) ============


undefined8 FUN_14020d890(void)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  uint uVar4;

  uint local_res8 [2];

  longlong *local_res10;

  longlong *local_res18;

  

  cVar1 = FUN_140142940("SDL_JOYSTICK_WGI",0);

  if (cVar1 != '\0') {

    iVar2 = FUN_1401a9e50();

    if (iVar2 < 0) {

      uVar3 = FUN_14012e850("RoInitialize() failed");

      return uVar3;

    }

    DAT_1403fd270 = 1;

    DAT_1403fd278 = (code *)FUN_1401a9aa0("CoIncrementMTAUsage");

    if (DAT_1403fd278 == (code *)0x0) {

      uVar3 = FUN_1401a9ed0("GetProcAddress failed for CoIncrementMTAUsage");

      return uVar3;

    }

    DAT_1403fd280 = FUN_1401a9aa0("RoGetActivationFactory");

    if (DAT_1403fd280 == 0) {

      uVar3 = FUN_1401a9ed0("GetProcAddress failed for RoGetActivationFactory");

      return uVar3;

    }

    DAT_1403fd288 = FUN_1401a9aa0("WindowsCreateStringReference");

    if (DAT_1403fd288 == 0) {

      uVar3 = FUN_1401a9ed0("GetProcAddress failed for WindowsCreateStringReference");

      return uVar3;

    }

    DAT_1403fd290 = FUN_1401a9aa0("WindowsDeleteString");

    if (DAT_1403fd290 == 0) {

      uVar3 = FUN_1401a9ed0("GetProcAddress failed for WindowsDeleteString");

      return uVar3;

    }

    DAT_1403fd298 = FUN_1401a9aa0("WindowsGetStringRawBuffer");

    if (DAT_1403fd298 == 0) {

      uVar3 = FUN_1401a9ed0("GetProcAddress failed for WindowsGetStringRawBuffer");

      return uVar3;

    }

    if ((DAT_1403fd300 == 0) && (iVar2 = (*DAT_1403fd278)(&DAT_1403fd300), iVar2 < 0)) {

      uVar3 = FUN_1401a9ef0("CoIncrementMTAUsage() failed",iVar2);

      return uVar3;

    }

    FUN_14020eba0();

    if (DAT_1403fd2a0 != (longlong *)0x0) {

      iVar2 = (**(code **)(*DAT_1403fd2a0 + 0x30))(DAT_1403fd2a0,&PTR_PTR_1403e50a8,&DAT_1403fd2e0);

      if (iVar2 < 0) {

        FUN_1401a9ef0("Windows.Gaming.Input.IRawGameControllerStatics.add_RawGameControllerAdded failed"

                      ,iVar2);

      }

      iVar2 = (**(code **)(*DAT_1403fd2a0 + 0x40))(DAT_1403fd2a0,&PTR_PTR_1403e50d8,&DAT_1403fd2e8);

      if (iVar2 < 0) {

        FUN_1401a9ef0("Windows.Gaming.Input.IRawGameControllerStatics.add_RawGameControllerRemoved failed"

                      ,iVar2);

      }

      iVar2 = (**(code **)(*DAT_1403fd2a0 + 0x50))(DAT_1403fd2a0,&local_res18);

      if (-1 < iVar2) {

        uVar4 = 0;

        local_res8[0] = 0;

        iVar2 = (**(code **)(*local_res18 + 0x38))(local_res18,local_res8);

        if ((-1 < iVar2) && (local_res8[0] != 0)) {

          do {

            local_res10 = (longlong *)0x0;

            iVar2 = (**(code **)(*local_res18 + 0x30))(local_res18,uVar4,&local_res10);

            if ((-1 < iVar2) && (local_res10 != (longlong *)0x0)) {

              FUN_14020d410(&PTR_PTR_1403e50a8,0);

              (**(code **)(*local_res10 + 0x10))();

            }

            uVar4 = uVar4 + 1;

          } while (uVar4 < local_res8[0]);

        }

        (**(code **)(*local_res18 + 0x10))();

      }

    }

  }

  return 1;

}




