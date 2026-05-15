// Address: 0x1401aa200
// Ghidra name: FUN_1401aa200
// ============ 0x1401aa200 FUN_1401aa200 (size=169) ============


undefined8

FUN_1401aa200(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  char *pcVar1;

  

  pcVar1 = "unknown object";

  switch(param_4) {

  case 1:

    pcVar1 = "SDL_Window";

    break;

  case 2:

    pcVar1 = "SDL_Renderer";

    break;

  case 3:

    pcVar1 = "SDL_Texture";

    break;

  case 4:

    pcVar1 = "SDL_Joystick";

    break;

  case 5:

    pcVar1 = "SDL_Gamepad";

    break;

  case 6:

    pcVar1 = "SDL_Haptic";

    break;

  case 7:

    pcVar1 = "SDL_Sensor";

    break;

  case 8:

    pcVar1 = "hidapi device";

    break;

  case 9:

    pcVar1 = "hidapi joystick";

    break;

  case 10:

    pcVar1 = "thread";

    break;

  case 0xb:

    pcVar1 = "SDL_Tray";

  }

  FUN_14012e080(3,"Leaked %s (%p)",pcVar1,param_3);

  return 1;

}




