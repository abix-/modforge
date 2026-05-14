// Address: 0x140134590
// Ghidra name: FUN_140134590
// ============ 0x140134590 FUN_140134590 (size=191) ============


undefined8 FUN_140134590(longlong param_1,undefined4 *param_2)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return 0;

  }

  if ((*(char *)(param_1 + 0x2ac) != '\0') && ((uint)param_2[1] < 4)) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403dfd78,"SDL_CreateGPUBuffer_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x56d);

    } while (iVar2 == 0);

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      uVar3 = (*pcVar1)();

      return uVar3;

    }

  }

  uVar3 = FUN_140174e70(param_2[2],"SDL.gpu.buffer.create.name",0);

                    /* WARNING: Could not recover jumptable at 0x00014013464c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x298),*param_2,param_2[1],uVar3);

  return uVar3;

}




