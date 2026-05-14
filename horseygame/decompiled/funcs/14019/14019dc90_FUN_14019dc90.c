// Address: 0x14019dc90
// Ghidra name: FUN_14019dc90
// ============ 0x14019dc90 FUN_14019dc90 (size=122) ============


void FUN_14019dc90(longlong param_1,longlong param_2,int param_3,int param_4)



{

  longlong lVar1;

  undefined1 *puVar2;

  undefined1 *puVar3;

  

  lVar1 = (longlong)(param_3 + -1);

  if (-1 < lVar1) {

    if (param_4 == 1) {

      do {

        *(undefined1 *)(param_1 + 1 + lVar1 * 2) = 0xff;

        *(undefined1 *)(param_1 + lVar1 * 2) = *(undefined1 *)(param_2 + lVar1);

        lVar1 = lVar1 + -1;

      } while (-1 < lVar1);

      return;

    }

    puVar2 = (undefined1 *)(param_1 + 2 + lVar1 * 4);

    puVar3 = (undefined1 *)(param_2 + 1 + lVar1 * 3);

    do {

      lVar1 = lVar1 + -1;

      puVar2[1] = 0xff;

      *puVar2 = puVar3[1];

      puVar2[-1] = *puVar3;

      puVar2[-2] = puVar3[-1];

      puVar2 = puVar2 + -4;

      puVar3 = puVar3 + -3;

    } while (-1 < lVar1);

  }

  return;

}




