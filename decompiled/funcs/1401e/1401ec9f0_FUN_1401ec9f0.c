// Address: 0x1401ec9f0
// Ghidra name: FUN_1401ec9f0
// ============ 0x1401ec9f0 FUN_1401ec9f0 (size=248) ============


void FUN_1401ec9f0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int *piVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  piVar2 = *(int **)(param_2 + 0x138);

  FUN_1401ebd30();

  if (*(longlong *)(lVar1 + 0x218) == param_2) {

    *(undefined8 *)(lVar1 + 0x218) = 0;

    *(undefined8 *)(lVar1 + 0x248) = 0;

  }

  if (*(longlong *)(lVar1 + 0x220) == param_2) {

    *(undefined8 *)(lVar1 + 0x220) = 0;

  }

  if (piVar2 != (int *)0x0) {

    if ((*piVar2 != 0) && ((char)piVar2[1] == '\0')) {

      (**(code **)(lVar1 + 0x88))(1,piVar2);

    }

    if ((char)piVar2[0x15] != '\0') {

      if ((char)piVar2[0x17] == '\0') {

        (**(code **)(lVar1 + 0x88))(1,piVar2 + 0x16);

      }

      if ((char)piVar2[0x19] == '\0') {

        (**(code **)(lVar1 + 0x88))(1,piVar2 + 0x18);

      }

    }

    if ((*(char *)((longlong)piVar2 + 0x55) != '\0') && ((char)piVar2[0x17] == '\0')) {

      (**(code **)(lVar1 + 0x88))(1,piVar2 + 0x16);

    }

    FUN_1401841e0(*(undefined8 *)(piVar2 + 0xe));

    FUN_1401841e0(piVar2);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




