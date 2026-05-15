// Address: 0x140136bc0
// Ghidra name: FUN_140136bc0
// ============ 0x140136bc0 FUN_140136bc0 (size=134) ============


ulonglong FUN_140136bc0(longlong param_1,int param_2,undefined8 param_3,ulonglong param_4)



{

  code *pcVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Invalid GPU device");

  }

  else if ((*(char *)(param_1 + 0x2ac) == '\0') || (param_2 - 1U < 0x68)) {

    if (((param_4 & 0x60) == 0) || (uVar2 = (ulonglong)param_2, (&DAT_1403deca0)[uVar2] != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x000140136c4a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(param_1 + 0x288))(*(undefined8 *)(param_1 + 0x298));

      return uVar2;

    }

  }

  else {

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403def68,"SDL_GPUTextureSupportsFormat_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x39f);

    } while ((int)uVar2 == 0);

    if ((int)uVar2 == 1) {

      pcVar1 = (code *)swi(3);

      uVar2 = (*pcVar1)();

      return uVar2;

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




