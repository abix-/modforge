// Address: 0x140207b60
// Ghidra name: FUN_140207b60
// ============ 0x140207b60 FUN_140207b60 (size=285) ============


undefined ** FUN_140207b60(undefined8 *param_1)



{

  short sVar1;

  undefined **ppuVar2;

  char cVar3;

  undefined **ppuVar4;

  uint uVar5;

  

  if (0 < *(int *)(param_1 + 0x15)) {

    return &PTR_s_SDL_JOYSTICK_HIDAPI_COMBINED_1403e6980;

  }

  cVar3 = FUN_14015ba80(*(undefined2 *)(param_1 + 4),*(undefined2 *)((longlong)param_1 + 0x22),

                        *(undefined2 *)((longlong)param_1 + 0x24),*param_1);

  if ((cVar3 == '\0') &&

     ((((sVar1 = *(short *)(param_1 + 4), sVar1 == 0x28de || (sVar1 == 0x4b4)) || (sVar1 == 0x37d7))

      || (((*(short *)(param_1 + 10) == 0 || (*(short *)(param_1 + 10) == 1)) &&

          ((sVar1 = *(short *)((longlong)param_1 + 0x52), sVar1 == 0 ||

           (((sVar1 - 4U & 0xfffa) == 0 && (sVar1 != 9)))))))))) {

    uVar5 = 0;

    ppuVar4 = &PTR_PTR_1403e4d40;

    do {

      ppuVar2 = (undefined **)*ppuVar4;

      if ((*(char *)(ppuVar2 + 1) != '\0') &&

         (cVar3 = (*(code *)ppuVar2[5])

                            (param_1,*param_1,*(undefined4 *)((longlong)param_1 + 0x5c),

                             *(undefined2 *)(param_1 + 4),*(undefined2 *)((longlong)param_1 + 0x22),

                             *(undefined2 *)((longlong)param_1 + 0x24),*(undefined4 *)(param_1 + 8),

                             *(undefined4 *)((longlong)param_1 + 0x44),*(undefined4 *)(param_1 + 9),

                             *(undefined4 *)((longlong)param_1 + 0x4c)), cVar3 != '\0')) {

        return ppuVar2;

      }

      uVar5 = uVar5 + 1;

      ppuVar4 = ppuVar4 + 1;

    } while (uVar5 < 0x1a);

  }

  return (undefined **)0x0;

}




