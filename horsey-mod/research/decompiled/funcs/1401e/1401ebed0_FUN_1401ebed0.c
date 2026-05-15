// Address: 0x1401ebed0
// Ghidra name: FUN_1401ebed0
// ============ 0x1401ebed0 FUN_1401ebed0 (size=144) ============


void FUN_1401ebed0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(char *)(lVar1 + 8) != '\0') {

    if (*(char *)(lVar1 + 9) == '\0') {

      if (*(longlong *)(lVar1 + 0xd8) != 0) {

        do {

          iVar3 = (**(code **)(lVar1 + 0xd8))();

        } while (iVar3 != 0);

      }

    }

    else if (*(int *)(lVar1 + 0xc) != 0) {

      iVar3 = 0;

      if (0 < *(int *)(lVar1 + 0xc)) {

        lVar2 = 0;

        do {

          FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar1 + 0x10) + lVar2));

          iVar3 = iVar3 + 1;

          lVar2 = lVar2 + 8;

        } while (iVar3 < *(int *)(lVar1 + 0xc));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x10));

      *(undefined4 *)(lVar1 + 0xc) = 0;

      *(undefined8 *)(lVar1 + 0x10) = 0;

      return;

    }

  }

  return;

}




