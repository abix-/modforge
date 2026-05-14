// Address: 0x14015e620
// Ghidra name: FUN_14015e620
// ============ 0x14015e620 FUN_14015e620 (size=100) ============


undefined8 FUN_14015e620(int param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_140142960("SDL_AUDIO_DEVICE_SAMPLE_FRAMES");

  if ((lVar1 != 0) && (uVar2 = thunk_FUN_1402d89dc(lVar1), 0 < (int)uVar2)) {

    return uVar2;

  }

  if (param_1 < 0x5623) {

    return 0x200;

  }

  if (48000 < param_1) {

    uVar2 = 0x1000;

    if (param_1 < 0x17701) {

      uVar2 = 0x800;

    }

    return uVar2;

  }

  return 0x400;

}




