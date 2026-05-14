// Address: 0x140136c50
// Ghidra name: FUN_140136c50
// ============ 0x140136c50 FUN_140136c50 (size=118) ============


ulonglong FUN_140136c50(longlong param_1,int param_2)



{

  code *pcVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Invalid GPU device");

    return uVar2 & 0xffffffffffffff00;

  }

  if ((*(char *)(param_1 + 0x2ac) != '\0') && (0x67 < param_2 - 1U)) {

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403def98,"SDL_GPUTextureSupportsSampleCount_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3b8);

    } while ((int)uVar2 == 0);

    if ((int)uVar2 == 1) {

      pcVar1 = (code *)swi(3);

      uVar2 = (*pcVar1)();

      return uVar2;

    }

    return uVar2 & 0xffffffffffffff00;

  }

                    /* WARNING: Could not recover jumptable at 0x000140136cc3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = (**(code **)(param_1 + 0x290))(*(undefined8 *)(param_1 + 0x298));

  return uVar2;

}




