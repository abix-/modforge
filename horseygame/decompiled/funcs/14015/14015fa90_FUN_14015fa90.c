// Address: 0x14015fa90
// Ghidra name: FUN_14015fa90
// ============ 0x14015fa90 FUN_14015fa90 (size=428) ============


void FUN_14015fa90(longlong param_1,int param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  

  if (((0 < param_2) && (param_1 != 0)) && (lVar6 = (longlong)param_2, param_2 != 0)) {

    lVar3 = 0;

    lVar4 = lVar3;

    do {

      puVar1 = *(undefined8 **)(param_1 + lVar4 * 8);

      if (puVar1 != (undefined8 *)0x0) {

        while( true ) {

          FUN_140179b40(*puVar1);

          lVar5 = puVar1[0x18];

          FUN_140179b60(*puVar1);

          if (lVar5 != 0) {

            FUN_140179b40(**(undefined8 **)(lVar5 + 8));

          }

          FUN_140179b40(*puVar1);

          if (lVar5 == puVar1[0x18]) break;

          FUN_140179b60(*puVar1);

          if (lVar5 != 0) {

            FUN_140179b60(**(undefined8 **)(lVar5 + 8));

          }

        }

      }

      lVar4 = lVar4 + 1;

      lVar5 = lVar3;

    } while (lVar4 < lVar6);

    do {

      lVar4 = *(longlong *)(param_1 + lVar5 * 8);

      if (((lVar4 != 0) && (lVar2 = *(longlong *)(lVar4 + 0xc0), lVar2 != 0)) &&

         (*(char *)(lVar2 + 0x21) == '\0')) {

        if (*(longlong *)(lVar2 + 0x18) == lVar4) {

          *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(lVar4 + 200);

        }

        if (*(longlong *)(lVar4 + 0xd0) != 0) {

          *(undefined8 *)(*(longlong *)(lVar4 + 0xd0) + 200) = *(undefined8 *)(lVar4 + 200);

        }

        if (*(longlong *)(lVar4 + 200) != 0) {

          *(undefined8 *)(*(longlong *)(lVar4 + 200) + 0xd0) = *(undefined8 *)(lVar4 + 0xd0);

        }

        *(undefined8 *)(lVar4 + 200) = 0;

        *(undefined8 *)(lVar4 + 0xd0) = 0;

      }

      lVar5 = lVar5 + 1;

    } while (lVar5 < lVar6);

    do {

      puVar1 = *(undefined8 **)(param_1 + lVar3 * 8);

      if (puVar1 != (undefined8 *)0x0) {

        lVar4 = puVar1[0x18];

        puVar1[0x18] = 0;

        FUN_140179b60(*puVar1);

        if (lVar4 != 0) {

          FUN_14015fec0(*(undefined8 *)(lVar4 + 8));

          FUN_140179b60(**(undefined8 **)(lVar4 + 8));

        }

      }

      lVar3 = lVar3 + 1;

    } while (lVar3 < lVar6);

  }

  return;

}




