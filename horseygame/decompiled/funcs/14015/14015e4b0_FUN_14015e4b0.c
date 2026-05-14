// Address: 0x14015e4b0
// Ghidra name: FUN_14015e4b0
// ============ 0x14015e4b0 FUN_14015e4b0 (size=126) ============


char * FUN_14015e4b0(int param_1)



{

  if (param_1 < 0x8121) {

    if (param_1 == 0x8120) {

      return "SDL_AUDIO_F32LE";

    }

    if (param_1 == 8) {

      return "SDL_AUDIO_U8";

    }

    if (param_1 == 0x8008) {

      return "SDL_AUDIO_S8";

    }

    if (param_1 == 0x8010) {

      return "SDL_AUDIO_S16LE";

    }

    if (param_1 == 0x8020) {

      return "SDL_AUDIO_S32LE";

    }

  }

  else {

    if (param_1 == 0x9010) {

      return "SDL_AUDIO_S16BE";

    }

    if (param_1 == 0x9020) {

      return "SDL_AUDIO_S32BE";

    }

    if (param_1 == 0x9120) {

      return "SDL_AUDIO_F32BE";

    }

  }

  return "SDL_AUDIO_UNKNOWN";

}




