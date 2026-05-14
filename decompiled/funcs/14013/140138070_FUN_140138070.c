// Address: 0x140138070
// Ghidra name: FUN_140138070
// ============ 0x140138070 FUN_140138070 (size=157) ============


ulonglong FUN_140138070(longlong param_1,uint param_2)



{

  code *pcVar1;

  int iVar2;

  ulonglong uVar3;

  

  if (param_1 == 0) {

    uVar3 = FUN_14012e850("Invalid GPU device");

    return uVar3 & 0xffffffffffffff00;

  }

  if (*(char *)(param_1 + 0x2ac) == '\0') {

LAB_1401380da:

    if (param_2 == 0) {

      param_2 = 1;

      goto LAB_1401380f0;

    }

  }

  else if (2 < param_2 - 1) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0f78,"SDL_SetGPUAllowedFramesInFlight_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xcaa);

    } while (iVar2 == 0);

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      uVar3 = (*pcVar1)();

      return uVar3;

    }

    goto LAB_1401380da;

  }

  if (3 < param_2) {

    param_2 = 3;

  }

LAB_1401380f0:

                    /* WARNING: Could not recover jumptable at 0x00014013810a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar3 = (**(code **)(param_1 + 0x220))(*(undefined8 *)(param_1 + 0x298),param_2);

  return uVar3;

}




