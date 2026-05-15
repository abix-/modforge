// Address: 0x1400ee410
// Ghidra name: FUN_1400ee410
// ============ 0x1400ee410 FUN_1400ee410 (size=318) ============


void FUN_1400ee410(longlong param_1,longlong param_2,int param_3,int param_4)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  undefined1 uVar3;

  longlong lVar4;

  undefined1 *puVar5;

  

  if (0 < param_3) {

    lVar4 = (longlong)param_3;

    uVar3 = 0xff;

    if (param_4 != 0) {

      uVar3 = 0;

    }

    puVar5 = (undefined1 *)(param_2 + 1);

    do {

      puVar1 = *(undefined1 **)(param_1 + 0xb8);

      if (puVar1 < *(undefined1 **)(param_1 + 0xc0)) {

        uVar2 = *puVar1;

        *(undefined1 **)(param_1 + 0xb8) = puVar1 + 1;

      }

      else if (*(int *)(param_1 + 0x30) == 0) {

        uVar2 = 0;

      }

      else {

        FUN_1400ed820(param_1);

        uVar2 = **(undefined1 **)(param_1 + 0xb8);

        *(undefined1 **)(param_1 + 0xb8) = *(undefined1 **)(param_1 + 0xb8) + 1;

      }

      puVar5[1] = uVar2;

      puVar1 = *(undefined1 **)(param_1 + 0xb8);

      if (puVar1 < *(undefined1 **)(param_1 + 0xc0)) {

        uVar2 = *puVar1;

        *(undefined1 **)(param_1 + 0xb8) = puVar1 + 1;

      }

      else if (*(int *)(param_1 + 0x30) == 0) {

        uVar2 = 0;

      }

      else {

        FUN_1400ed820(param_1);

        uVar2 = **(undefined1 **)(param_1 + 0xb8);

        *(undefined1 **)(param_1 + 0xb8) = *(undefined1 **)(param_1 + 0xb8) + 1;

      }

      *puVar5 = uVar2;

      puVar1 = *(undefined1 **)(param_1 + 0xb8);

      if (puVar1 < *(undefined1 **)(param_1 + 0xc0)) {

        uVar2 = *puVar1;

        *(undefined1 **)(param_1 + 0xb8) = puVar1 + 1;

      }

      else if (*(int *)(param_1 + 0x30) == 0) {

        uVar2 = 0;

      }

      else {

        FUN_1400ed820(param_1);

        uVar2 = **(undefined1 **)(param_1 + 0xb8);

        *(undefined1 **)(param_1 + 0xb8) = *(undefined1 **)(param_1 + 0xb8) + 1;

      }

      puVar5[-1] = uVar2;

      puVar5[2] = uVar3;

      puVar5 = puVar5 + 4;

      lVar4 = lVar4 + -1;

    } while (lVar4 != 0);

  }

  return;

}




