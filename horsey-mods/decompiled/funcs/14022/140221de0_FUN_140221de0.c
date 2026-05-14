// Address: 0x140221de0
// Ghidra name: FUN_140221de0
// ============ 0x140221de0 FUN_140221de0 (size=332) ============


undefined1 FUN_140221de0(longlong param_1,int param_2)



{

  int iVar1;

  undefined8 *puVar2;

  undefined1 uVar3;

  longlong lVar4;

  

  lVar4 = (longlong)param_2;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x28));

  if ((param_2 < 0) || (*(int *)(param_1 + 0x10) <= param_2)) {

    uVar3 = FUN_14012e850("GAMEINPUT_InternalRemoveByIndex argument idx %d is out of range",param_2)

    ;

  }

  else {

    puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0x18) + lVar4 * 8);

    if (puVar2 != (undefined8 *)0x0) {

      if (*(char *)((longlong)puVar2 + 0x1c) != '\0') {

        if ((*(byte *)(puVar2[1] + 0x68) & 0x20) != 0) {

          FUN_140162780(*(undefined4 *)(puVar2 + 3));

        }

        if ((*(byte *)(puVar2[1] + 0x68) & 0x10) != 0) {

          FUN_140183700(*(undefined4 *)(puVar2 + 3));

        }

        if ((longlong *)puVar2[4] != (longlong *)0x0) {

          (**(code **)(*(longlong *)puVar2[4] + 0x10))();

          puVar2[4] = 0;

        }

        if ((longlong *)puVar2[5] != (longlong *)0x0) {

          (**(code **)(*(longlong *)puVar2[5] + 0x10))();

          puVar2[5] = 0;

        }

      }

      (**(code **)(*(longlong *)*puVar2 + 0x10))();

      FUN_1401841e0(puVar2[2]);

      FUN_1401841e0(puVar2);

    }

    *(undefined8 *)(*(longlong *)(param_1 + 0x18) + lVar4 * 8) = 0;

    iVar1 = *(int *)(param_1 + 0x10);

    if (iVar1 == 1) {

      FUN_1401841e0(*(undefined8 *)(param_1 + 0x18));

      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

      uVar3 = 1;

      *(undefined8 *)(param_1 + 0x18) = 0;

    }

    else {

      if (param_2 != iVar1 + -1) {

        FUN_1402f8e20(*(longlong *)(param_1 + 0x18) + lVar4 * 8,

                      *(longlong *)(param_1 + 0x18) + (longlong)(param_2 + 1) * 8,

                      (longlong)((iVar1 - param_2) + -1) << 3);

      }

      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

      uVar3 = 1;

    }

  }

  FUN_140179b60(*(undefined8 *)(param_1 + 0x28));

  return uVar3;

}




