// Address: 0x140123740
// Ghidra name: SDL_GetGamepadGUIDForID
// ============ 0x140123740 SDL_GetGamepadGUIDForID (size=35) ============


undefined8 * SDL_GetGamepadGUIDForID(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

                    /* 0x123740  334  SDL_GetGamepadGUIDForID */

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403dce68)(local_18);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




