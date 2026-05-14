// Address: 0x140132990
// Ghidra name: FUN_140132990
// ============ 0x140132990 FUN_140132990 (size=705) ============


longlong *

FUN_140132990(longlong *param_1,longlong param_2,uint param_3,longlong param_4,uint param_5)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  longlong *plVar4;

  uint uVar5;

  ulonglong uVar6;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return (longlong *)0x0;

  }

  if ((param_2 == 0) && (param_3 != 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","storage_texture_bindings");

    return (longlong *)0x0;

  }

  if ((param_4 == 0) && (param_5 != 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","storage_buffer_bindings");

    return (longlong *)0x0;

  }

  if (8 < param_3) {

    FUN_14012e850("Parameter \'%s\' is invalid","num_storage_texture_bindings");

    return (longlong *)0x0;

  }

  if (8 < param_5) {

    FUN_14012e850("Parameter \'%s\' is invalid","num_storage_buffer_bindings");

    return (longlong *)0x0;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_140132b33:

    (**(code **)(*param_1 + 0x150))(param_1,param_2,param_3,param_4,param_5);

    if (*(char *)(*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)(param_1 + 0x17) = 1;

      if (param_3 != 0) {

        FUN_1402f94c0(param_1 + 0x1d,1,param_3);

      }

      if (param_5 != 0) {

        FUN_1402f94c0(param_1 + 0x1e,1,param_5);

      }

    }

    return param_1 + 0x16;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) {

      uVar6 = 0;

      if (param_3 != 0) {

        do {

          lVar1 = *(longlong *)(param_2 + uVar6 * 0x18);

          if ((*(byte *)(lVar1 + 8) & 0x60) == 0) goto LAB_140132c00;

          if (*(uint *)(lVar1 + 0x14) <= *(uint *)(param_2 + 0xc + uVar6 * 0x18))

          goto LAB_140132bd0;

          if (*(uint *)(lVar1 + 0x18) <= *(uint *)(param_2 + 8 + uVar6 * 0x18)) goto LAB_140132ba0;

          uVar5 = (int)uVar6 + 1;

          uVar6 = (ulonglong)uVar5;

        } while (uVar5 < param_3);

      }

      goto LAB_140132b33;

    }

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e05b8,"SDL_BeginGPUComputePass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x990);

    } while (iVar3 == 0);

  }

  else {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0588,"SDL_BeginGPUComputePass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x98f);

    } while (iVar3 == 0);

  }

LAB_140132c54:

  if (iVar3 != 1) {

    return (longlong *)0x0;

  }

  pcVar2 = (code *)swi(3);

  plVar4 = (longlong *)(*pcVar2)();

  return plVar4;

LAB_140132c00:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e05e8,"SDL_BeginGPUComputePass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x995);

  } while (iVar3 == 0);

  goto LAB_140132c54;

LAB_140132bd0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e0618,"SDL_BeginGPUComputePass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x99a);

  } while (iVar3 == 0);

  goto LAB_140132c54;

LAB_140132ba0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e0648,"SDL_BeginGPUComputePass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x99f);

  } while (iVar3 == 0);

  goto LAB_140132c54;

}




