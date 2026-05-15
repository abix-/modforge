// Address: 0x1401cc570
// Ghidra name: FUN_1401cc570
// ============ 0x1401cc570 FUN_1401cc570 (size=131) ============


void FUN_1401cc570(longlong param_1,longlong param_2,longlong param_3)



{

  undefined8 uVar1;

  uint uVar2;

  ulonglong uVar3;

  

  if ((*(char *)(param_1 + 0x98) != '\0') && (param_3 != 0)) {

    FUN_1401841e0(*(undefined8 *)(param_2 + 0x48));

    uVar1 = FUN_14012f0d0(param_3);

    uVar3 = 0;

    *(undefined8 *)(param_2 + 0x48) = uVar1;

    if (*(int *)(param_2 + 0x3c) != 0) {

      do {

        FUN_1401cb3d0(param_1,*(undefined8 *)

                               (*(longlong *)(*(longlong *)(param_2 + 0x30) + uVar3 * 8) + 0x20),

                      param_3);

        uVar2 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar2;

      } while (uVar2 < *(uint *)(param_2 + 0x3c));

    }

  }

  return;

}




