// Address: 0x1401f14c0
// Ghidra name: FUN_1401f14c0
// ============ 0x1401f14c0 FUN_1401f14c0 (size=207) ============


void FUN_1401f14c0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int *piVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  piVar2 = *(int **)(param_2 + 0x138);

  FUN_1401f0320();

  if (*(longlong *)(lVar1 + 0x278) == param_2) {

    *(undefined8 *)(lVar1 + 0x278) = 0;

    *(undefined8 *)(lVar1 + 0x2c8) = 0;

  }

  if (*(longlong *)(lVar1 + 0x280) == param_2) {

    *(undefined8 *)(lVar1 + 0x280) = 0;

  }

  if (piVar2 != (int *)0x0) {

    if ((*piVar2 != 0) && ((char)piVar2[1] == '\0')) {

      (**(code **)(lVar1 + 0x78))(1,piVar2);

    }

    if ((piVar2[10] != 0) && (piVar2[0xb] == 0)) {

      (**(code **)(lVar1 + 0x78))(1,piVar2 + 10);

    }

    if ((piVar2[0xc] != 0) && (piVar2[0xd] == 0)) {

      (**(code **)(lVar1 + 0x78))(1,piVar2 + 0xc);

    }

    FUN_1401841e0(*(undefined8 *)(piVar2 + 6));

    FUN_1401841e0(piVar2);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




