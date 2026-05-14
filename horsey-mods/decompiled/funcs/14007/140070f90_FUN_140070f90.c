// Address: 0x140070f90
// Ghidra name: FUN_140070f90
// ============ 0x140070f90 FUN_140070f90 (size=92) ============


void FUN_140070f90(uint param_1)



{

  undefined8 uVar1;

  undefined1 uStackX_9;

  undefined1 uStackX_a;

  

  uVar1 = FUN_1400c43c0();

  uStackX_a = (undefined1)(param_1 >> 0x10);

  uStackX_9 = (undefined1)(param_1 >> 8);

  SDL_SetRenderDrawColor(uVar1,param_1 & 0xff,uStackX_9,uStackX_a,0xff);

  uVar1 = FUN_1400c43c0();

  SDL_RenderClear(uVar1);

  uVar1 = FUN_1400c43c0();

  SDL_SetRenderDrawColor(uVar1,0xff,0xff,0xff,0x19);

  return;

}




