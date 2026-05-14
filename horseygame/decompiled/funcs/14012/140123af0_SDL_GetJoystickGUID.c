// Address: 0x140123af0
// Ghidra name: SDL_GetJoystickGUID
// ============ 0x140123af0 SDL_GetJoystickGUID (size=35) ============


undefined8 * SDL_GetJoystickGUID(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

                    /* 0x123af0  390  SDL_GetJoystickGUID */

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403dd028)(local_18);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




