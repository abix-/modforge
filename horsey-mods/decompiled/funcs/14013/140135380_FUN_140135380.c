// Address: 0x140135380
// Ghidra name: FUN_140135380
// ============ 0x140135380 FUN_140135380 (size=150) ============


undefined8 FUN_140135380(longlong param_1,longlong param_2)



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

  if (((*(char *)(param_1 + 0x2ac) == '\0') || (*(char *)(param_1 + 0x2af) == '\0')) ||

     (*(char *)(param_2 + 0x2c) == '\0')) {

                    /* WARNING: Could not recover jumptable at 0x000140135413. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x298));

    return uVar3;

  }

  do {

    iVar2 = FUN_14017f2a0(&DAT_1403df778,"SDL_CreateGPUSampler_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x498);

  } while (iVar2 == 0);

  if (iVar2 == 1) {

    pcVar1 = (code *)swi(3);

    uVar3 = (*pcVar1)();

    return uVar3;

  }

  return 0;

}




