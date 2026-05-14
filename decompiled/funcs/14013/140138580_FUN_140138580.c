// Address: 0x140138580
// Ghidra name: FUN_140138580
// ============ 0x140138580 FUN_140138580 (size=198) ============


undefined8 FUN_140138580(longlong *param_1)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return 0;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_140138631:

    *(undefined1 *)((longlong)param_1 + 0x109) = 1;

                    /* WARNING: Could not recover jumptable at 0x000140138643. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(*param_1 + 600))();

    return uVar3;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) goto LAB_140138631;

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e10f8,"SDL_SubmitGPUCommandBufferAndAcquireFence_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xd4a);

    } while (iVar2 == 0);

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e10c8,"SDL_SubmitGPUCommandBufferAndAcquireFence_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xd45);

    } while (iVar2 == 0);

  }

  if (iVar2 != 1) {

    return 0;

  }

  pcVar1 = (code *)swi(3);

  uVar3 = (*pcVar1)();

  return uVar3;

}




