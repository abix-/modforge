// Address: 0x1401b9570
// Ghidra name: FUN_1401b9570
// ============ 0x1401b9570 FUN_1401b9570 (size=530) ============


void FUN_1401b9570(longlong param_1,longlong param_2)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  uVar4 = 0;

  if (*(int *)(param_2 + 0x44) != 0) {

    do {

      if (*(longlong *)(*(longlong *)(param_2 + 0x48) + 0x10 + uVar4 * 0x28) != 0) {

        uVar3 = 0;

        uVar2 = 0;

        if (*(int *)(param_2 + 0x3c) != 0) {

          do {

            FUN_1401bcad0(param_1,*(undefined8 *)

                                   (*(longlong *)

                                     (*(longlong *)(param_2 + 0x48) + 0x10 + uVar4 * 0x28) +

                                   uVar3 * 8));

            uVar2 = *(uint *)(param_2 + 0x3c);

            uVar1 = (int)uVar3 + 1;

            uVar3 = (ulonglong)uVar1;

          } while (uVar1 < uVar2);

        }

        uVar3 = 0;

        if (uVar2 != 0) {

          do {

            (**(code **)(param_1 + 0xbb0))

                      (*(undefined8 *)(param_1 + 0x570),

                       *(undefined8 *)

                        (*(longlong *)(*(longlong *)(param_2 + 0x48) + 0x10 + uVar4 * 0x28) +

                        uVar3 * 8),0);

            uVar2 = (int)uVar3 + 1;

            uVar3 = (ulonglong)uVar2;

          } while (uVar2 < *(uint *)(param_2 + 0x3c));

        }

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x10 + uVar4 * 0x28));

      }

      if (*(longlong *)(*(longlong *)(param_2 + 0x48) + 0x18 + uVar4 * 0x28) != 0) {

        (**(code **)(param_1 + 0xbb0))(*(undefined8 *)(param_1 + 0x570));

      }

      if (*(longlong *)(*(longlong *)(param_2 + 0x48) + 0x20 + uVar4 * 0x28) != 0) {

        FUN_1401bcad0(param_1);

        (**(code **)(param_1 + 0xbb0))

                  (*(undefined8 *)(param_1 + 0x570),

                   *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x20 + uVar4 * 0x28));

      }

      uVar2 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar2;

    } while (uVar2 < *(uint *)(param_2 + 0x44));

  }

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x48));

  if (*(longlong *)(param_2 + 0x20) != 0) {

    (**(code **)(param_1 + 0xbb0))(*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x20),0)

    ;

  }

  if (*(longlong *)(param_2 + 0x18) != 0) {

    (**(code **)(param_1 + 0xba8))(*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x18),0)

    ;

  }

  if (*(longlong *)(param_2 + 0x10) != 0) {

    FUN_1401bcc70(param_1);

  }

  FUN_1401841e0(param_2);

  return;

}




