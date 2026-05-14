// Address: 0x140159840
// Ghidra name: FUN_140159840
// ============ 0x140159840 FUN_140159840 (size=72) ============


undefined2 FUN_140159840(longlong param_1)



{

  undefined2 uVar1;

  undefined2 uVar2;

  

  if (*(int *)(param_1 + 0x44) == 2) {

    return 1;

  }

  uVar1 = FUN_140158b60();

  uVar2 = FUN_140158e60(param_1);

  uVar1 = FUN_14015bf20(uVar2,uVar1,&PTR_s_SDL_JOYSTICK_ZERO_CENTERED_DEVIC_1403e2630);

  return uVar1;

}




