// Address: 0x1401b9390
// Ghidra name: FUN_1401b9390
// ============ 0x1401b9390 FUN_1401b9390 (size=472) ============


void FUN_1401b9390(longlong param_1,longlong param_2)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar4;

  ulonglong uVar3;

  

  if (param_2 != 0) {

    uVar4 = 0;

    uVar3 = uVar4;

    if (*(uint *)(param_2 + 0x60) != 0) {

      do {

        FUN_1401bcad0(param_1,**(undefined8 **)

                                (*(longlong *)

                                  (*(longlong *)

                                    (*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50) + 0x48) +

                                0x10));

        (**(code **)(param_1 + 0xbb0))

                  (*(undefined8 *)(param_1 + 0x570),

                   **(undefined8 **)

                     (*(longlong *)

                       (*(longlong *)(*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50) + 0x48) +

                     0x10),0);

        FUN_1401841e0(*(undefined8 *)

                       (*(longlong *)

                         (*(longlong *)(*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50) + 0x48)

                       + 0x10));

        FUN_1401841e0(*(undefined8 *)

                       (*(longlong *)(*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50) + 0x48));

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50));

        uVar2 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar2;

      } while (uVar2 < *(uint *)(param_2 + 0x60));

    }

    FUN_1401841e0(*(undefined8 *)(param_2 + 0x58));

    *(undefined8 *)(param_2 + 0x58) = 0;

    if (*(longlong *)(param_2 + 0x70) != 0) {

      (**(code **)(param_1 + 0xbe0))

                (*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x70),0);

      *(undefined8 *)(param_2 + 0x70) = 0;

    }

    if (*(longlong *)(param_2 + 0x78) != 0) {

      (**(code **)(param_1 + 0xbe0))

                (*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x78),0);

      *(undefined8 *)(param_2 + 0x78) = 0;

    }

    if (*(longlong *)(param_2 + 0x80) != 0) {

      (**(code **)(param_1 + 0xbe0))

                (*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x80),0);

      *(undefined8 *)(param_2 + 0x80) = 0;

    }

    if (*(uint *)(param_2 + 0x60) != 0) {

      do {

        lVar1 = *(longlong *)(uVar4 * 8 + *(longlong *)(param_2 + 0x88));

        if (lVar1 != 0) {

          (**(code **)(param_1 + 0xbe0))(*(undefined8 *)(param_1 + 0x570),lVar1,0);

          *(undefined8 *)(uVar4 * 8 + *(longlong *)(param_2 + 0x88)) = 0;

        }

        uVar2 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar2;

      } while (uVar2 < *(uint *)(param_2 + 0x60));

    }

    FUN_1401841e0(*(undefined8 *)(param_2 + 0x88));

    *(undefined4 *)(param_2 + 0x60) = 0;

    *(undefined8 *)(param_2 + 0x88) = 0;

  }

  return;

}




