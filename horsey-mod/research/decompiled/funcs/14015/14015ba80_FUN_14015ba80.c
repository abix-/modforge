// Address: 0x14015ba80
// Ghidra name: FUN_14015ba80
// ============ 0x14015ba80 FUN_14015ba80 (size=137) ============


bool FUN_14015ba80(ulonglong param_1,ulonglong param_2,undefined2 param_3,undefined8 param_4)



{

  char cVar1;

  bool bVar2;

  

  cVar1 = FUN_14015bf20(param_1,param_2,&PTR_s_SDL_JOYSTICK_BLACKLIST_DEVICES_1403e2450);

  if (cVar1 == '\0') {

    cVar1 = FUN_140142940("SDL_JOYSTICK_ROG_CHAKRAM",0);

    if (cVar1 == '\0') {

      cVar1 = FUN_14015bf20(param_1 & 0xffff,param_2 & 0xffff,&PTR_s_SDL_ROG_GAMEPAD_MICE_1403e2540)

      ;

      if (cVar1 != '\0') goto LAB_14015baf2;

    }

    cVar1 = FUN_140142200(param_1 & 0xffff,param_2 & 0xffff,param_3,param_4);

    bVar2 = cVar1 != '\0';

  }

  else {

LAB_14015baf2:

    bVar2 = true;

  }

  return bVar2;

}




