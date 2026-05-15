// Address: 0x140135420
// Ghidra name: FUN_140135420
// ============ 0x140135420 FUN_140135420 (size=387) ============


undefined8 FUN_140135420(longlong param_1,longlong param_2)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return 0;

  }

  if (*(char *)(param_1 + 0x2ac) == '\0') {

LAB_140135591:

                    /* WARNING: Could not recover jumptable at 0x0001401355a0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x298));

    return uVar3;

  }

  if (*(uint *)(param_2 + 0x18) == 0) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403df7a8,"SDL_CreateGPUShader_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4af);

    } while (iVar2 == 0);

  }

  else if ((*(uint *)(param_1 + 0x2a8) & *(uint *)(param_2 + 0x18)) == 0) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403df7d8,"SDL_CreateGPUShader_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4b3);

    } while (iVar2 == 0);

  }

  else if (*(uint *)(param_2 + 0x20) < 0x11) {

    if (*(uint *)(param_2 + 0x24) < 9) {

      if (*(uint *)(param_2 + 0x28) < 9) {

        if (*(uint *)(param_2 + 0x2c) < 5) goto LAB_140135591;

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403df898,"SDL_CreateGPUShader_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4c7);

        } while (iVar2 == 0);

      }

      else {

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403df868,"SDL_CreateGPUShader_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4c2);

        } while (iVar2 == 0);

      }

    }

    else {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403df838,"SDL_CreateGPUShader_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4bd);

      } while (iVar2 == 0);

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403df808,"SDL_CreateGPUShader_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4b8);

    } while (iVar2 == 0);

  }

  if (iVar2 != 1) {

    return 0;

  }

  pcVar1 = (code *)swi(3);

  uVar3 = (*pcVar1)();

  return uVar3;

}




