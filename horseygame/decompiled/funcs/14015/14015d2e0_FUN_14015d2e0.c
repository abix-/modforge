// Address: 0x14015d2e0
// Ghidra name: FUN_14015d2e0
// ============ 0x14015d2e0 FUN_14015d2e0 (size=158) ============


void FUN_14015d2e0(char param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  if (param_2[2] == 0) {

    param_2[2] = 0xac44;

    lVar3 = FUN_140142960("SDL_AUDIO_FREQUENCY");

    if (lVar3 != 0) {

      iVar1 = thunk_FUN_1402d89dc(lVar3);

      if (0 < iVar1) {

        param_2[2] = iVar1;

      }

    }

  }

  if (param_2[1] == 0) {

    param_2[1] = 2 - (uint)(param_1 != '\0');

    lVar3 = FUN_140142960("SDL_AUDIO_CHANNELS");

    if (lVar3 != 0) {

      iVar1 = thunk_FUN_1402d89dc(lVar3);

      if (0 < iVar1) {

        param_2[1] = iVar1;

      }

    }

  }

  if (*param_2 == 0) {

    uVar4 = FUN_140142960("SDL_AUDIO_FORMAT");

    iVar2 = FUN_14015d120(uVar4);

    iVar1 = 0x8010;

    if (iVar2 != 0) {

      iVar1 = iVar2;

    }

    *param_2 = iVar1;

  }

  return;

}




