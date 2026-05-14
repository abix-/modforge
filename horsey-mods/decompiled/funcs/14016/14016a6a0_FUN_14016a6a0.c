// Address: 0x14016a6a0
// Ghidra name: FUN_14016a6a0
// ============ 0x14016a6a0 FUN_14016a6a0 (size=222) ============


undefined8

FUN_14016a6a0(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,ulonglong param_6)



{

  undefined4 uVar1;

  undefined8 uVar2;

  

  uVar1 = FUN_1401746e0();

  if ((param_6 & 0xc0000) == 0) {

    FUN_14012e850(

                 "Popup windows must specify either the \'SDL_WINDOW_TOOLTIP\' or the \'SDL_WINDOW_POPUP_MENU\' flag"

                 );

    uVar2 = 0;

  }

  else {

    FUN_140175480(uVar1,"SDL.window.create.parent",param_1);

    FUN_140175360(uVar1,"SDL.window.create.x",(longlong)param_2);

    FUN_140175360(uVar1,"SDL.window.create.y",(longlong)param_3);

    FUN_140175360(uVar1,"SDL.window.create.width",(longlong)param_4);

    FUN_140175360(uVar1,"SDL.window.create.height",(longlong)param_5);

    FUN_140175360(uVar1,"SDL.window.create.flags",param_6);

    uVar2 = FUN_14016ae20(uVar1);

    FUN_1401747e0(uVar1);

  }

  return uVar2;

}




