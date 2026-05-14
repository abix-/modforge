// Address: 0x1401d4d80
// Ghidra name: FUN_1401d4d80
// ============ 0x1401d4d80 FUN_1401d4d80 (size=388) ============


void FUN_1401d4d80(undefined4 param_1,undefined8 param_2,int param_3,undefined8 param_4,

                  undefined4 param_5,int param_6)



{

  undefined8 uVar1;

  undefined8 uVar2;

  

  if (param_3 == 0x32595559) {

    if (param_6 == 0x55595659) {

      FUN_1401db620(param_1,param_2,param_4,param_5);

      return;

    }

    if (param_6 == 0x59565955) {

      FUN_1401d6370(param_1,param_2,param_4,param_5);

      return;

    }

  }

  else if (param_3 == 0x55595659) {

    if (param_6 == 0x32595559) {

      FUN_1401db620(param_1,param_2,param_4,param_5);

      return;

    }

    if (param_6 == 0x59565955) {

      FUN_1401db820(param_1,param_2,param_4,param_5);

      return;

    }

  }

  else if (param_3 == 0x59565955) {

    if (param_6 == 0x32595559) {

      FUN_1401d6370(param_1,param_2,param_4,param_5);

      return;

    }

    if (param_6 == 0x55595659) {

      FUN_1401d6570(param_1,param_2,param_4,param_5);

      return;

    }

  }

  uVar1 = FUN_14017af90();

  uVar2 = FUN_14017af90(param_3);

  FUN_14012e850("SDL_ConvertPixels_Packed4_to_Packed4: Unsupported YUV conversion: %s -> %s",uVar2,

                uVar1);

  return;

}




