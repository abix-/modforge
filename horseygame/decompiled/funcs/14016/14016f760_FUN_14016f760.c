// Address: 0x14016f760
// Ghidra name: FUN_14016f760
// ============ 0x14016f760 FUN_14016f760 (size=282) ============


void FUN_14016f760(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  

  if ((*(char *)(param_1 + 0x10d) != '\0') && ((*(byte *)(param_1 + 0x48) & 1) != 0)) {

    cVar1 = FUN_140142940("SDL_VIDEO_MATCH_EXCLUSIVE_MODE_ON_MOVE",1);

    if ((cVar1 == '\0') || ((*(int *)(param_1 + 0xa8) == 0 && (*(int *)(param_1 + 0xac) == 0)))) {

      *(undefined8 *)(param_1 + 200) = 0;

      *(undefined8 *)(param_1 + 0xd0) = 0;

      *(undefined8 *)(param_1 + 0xd8) = 0;

      *(undefined8 *)(param_1 + 0xe0) = 0;

      *(undefined8 *)(param_1 + 0xe8) = 0;

    }

    else {

      uVar2 = FUN_14016d450();

      cVar1 = FUN_14016cf30(uVar2,*(undefined4 *)(param_1 + 0xa8),*(undefined4 *)(param_1 + 0xac),

                            *(undefined4 *)(param_1 + 0xb4),

                            DAT_14039ca44 < *(float *)(param_1 + 0xb0),(undefined8 *)(param_1 + 200)

                           );

      if (((cVar1 == '\0') || (*(int *)(param_1 + 0xa8) != *(int *)(param_1 + 0xd0))) ||

         (*(int *)(param_1 + 0xac) != *(int *)(param_1 + 0xd4))) {

        *(undefined8 *)(param_1 + 200) = 0;

        *(undefined8 *)(param_1 + 0xd0) = 0;

        *(undefined8 *)(param_1 + 0xd8) = 0;

        *(undefined8 *)(param_1 + 0xe0) = 0;

        *(undefined8 *)(param_1 + 0xe8) = 0;

      }

    }

    if ((*(byte *)(param_1 + 0x48) & 0x49) == 1) {

      FUN_140173190(param_1,2,1);

    }

  }

  FUN_14016a520(param_1);

  return;

}




