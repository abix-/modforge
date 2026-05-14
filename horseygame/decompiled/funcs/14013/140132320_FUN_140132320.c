// Address: 0x140132320
// Ghidra name: FUN_140132320
// ============ 0x140132320 FUN_140132320 (size=192) ============


void FUN_140132320(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  longlong *plVar2;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    FUN_140130b40();

    plVar1 = (longlong *)(param_1 + 400);

    for (plVar2 = *(longlong **)(param_1 + 0x1a0); plVar2 != (longlong *)0x0;

        plVar2 = (longlong *)plVar2[2]) {

      if (*plVar2 == param_2) {

        if ((*(char *)(param_1 + 0x1b4) == '\0') && (*(int *)(param_1 + 0x1b0) == 0)) {

          (**(code **)(param_1 + 0x28))(param_1,param_2);

          *(undefined8 *)(param_2 + 0x18) = 0;

          *(undefined4 *)(param_2 + 0x10) = 0;

        }

        plVar2[1] = 0;

        plVar1[2] = plVar2[2];

        plVar2[2] = *(longlong *)(param_1 + 0x188);

        *(longlong **)(param_1 + 0x188) = plVar2;

        break;

      }

      plVar1 = plVar2;

    }

    FUN_140130b70(param_1);

  }

  return;

}




