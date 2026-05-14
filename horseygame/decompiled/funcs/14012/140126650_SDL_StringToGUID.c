// Address: 0x140126650
// Ghidra name: SDL_StringToGUID
// ============ 0x140126650 SDL_StringToGUID (size=35) ============


undefined8 * SDL_StringToGUID(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

                    /* 0x126650  1010  SDL_StringToGUID */

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403de140)(local_18);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




