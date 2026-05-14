// Address: 0x140138cb0
// Ghidra name: FUN_140138cb0
// ============ 0x140138cb0 FUN_140138cb0 (size=150) ============


ulonglong FUN_140138cb0(longlong param_1,longlong param_2,uint param_3)



{

  code *pcVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Invalid GPU device");

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_2 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","window");

    return uVar2 & 0xffffffffffffff00;

  }

  if ((*(char *)(param_1 + 0x2ac) == '\0') || (param_3 < 4)) {

                    /* WARNING: Could not recover jumptable at 0x000140138d43. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(param_1 + 0x1f8))(*(undefined8 *)(param_1 + 0x298));

    return uVar2;

  }

  do {

    uVar2 = FUN_14017f2a0(&DAT_1403e0eb8,"SDL_WindowSupportsGPUSwapchainComposition_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc45);

  } while ((int)uVar2 == 0);

  if ((int)uVar2 != 1) {

    return uVar2 & 0xffffffffffffff00;

  }

  pcVar1 = (code *)swi(3);

  uVar2 = (*pcVar1)();

  return uVar2;

}




