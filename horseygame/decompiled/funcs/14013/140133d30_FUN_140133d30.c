// Address: 0x140133d30
// Ghidra name: FUN_140133d30
// ============ 0x140133d30 FUN_140133d30 (size=253) ============


void FUN_140133d30(undefined8 *param_1,uint param_2,longlong param_3,int param_4)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

  }

  else if ((param_3 == 0) && (param_4 != 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","storage_textures");

  }

  else if (param_2 + param_4 < 9) {

    if (*(char *)(*(longlong *)*param_1 + 0x2ac) != '\0') {

      if (*(char *)(param_1 + 1) == '\0') {

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403e02e8,"SDL_BindGPUVertexStorageTextures_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x840);

        } while (iVar2 == 0);

        if (iVar2 != 1) {

          return;

        }

        pcVar1 = (code *)swi(3);

        (*pcVar1)();

        return;

      }

      if (param_4 != 0) {

        FUN_1402f94c0((ulonglong)param_2 + 0x78 + (longlong)param_1,1,param_4);

      }

    }

    (**(code **)(*(longlong *)*param_1 + 0xf0))

              ((longlong *)*param_1,(ulonglong)param_2,param_3,param_4);

  }

  else {

    FUN_14012e850("first_slot + num_bindings exceeds MAX_STORAGE_TEXTURES_PER_STAGE");

  }

  return;

}




