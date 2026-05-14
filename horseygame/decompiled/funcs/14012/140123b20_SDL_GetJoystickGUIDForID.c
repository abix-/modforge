// Address: 0x140123b20
// Ghidra name: SDL_GetJoystickGUIDForID
// ============ 0x140123b20 SDL_GetJoystickGUIDForID (size=35) ============


undefined8 * SDL_GetJoystickGUIDForID(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

                    /* 0x123b20  391  SDL_GetJoystickGUIDForID */

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403dd030)(local_18);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




