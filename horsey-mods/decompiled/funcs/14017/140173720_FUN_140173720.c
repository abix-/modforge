// Address: 0x140173720
// Ghidra name: FUN_140173720
// ============ 0x140173720 FUN_140173720 (size=165) ============


void FUN_140173720(longlong param_1,longlong param_2)



{

  if (*(longlong *)(param_1 + 0x1a8) != 0) {

    if (*(longlong *)(param_1 + 0x1c0) != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0x1c0) + 0x1b8) = *(undefined8 *)(param_1 + 0x1b8);

    }

    if (*(longlong *)(param_1 + 0x1b8) == 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0x1a8) + 0x1b0) = *(undefined8 *)(param_1 + 0x1c0);

      *(undefined8 *)(param_1 + 0x1a8) = 0;

    }

    else {

      *(undefined8 *)(*(longlong *)(param_1 + 0x1b8) + 0x1c0) = *(undefined8 *)(param_1 + 0x1c0);

      *(undefined8 *)(param_1 + 0x1a8) = 0;

    }

  }

  if (param_2 != 0) {

    *(longlong *)(param_1 + 0x1a8) = param_2;

    *(undefined8 *)(param_1 + 0x1c0) = *(undefined8 *)(param_2 + 0x1b0);

    if (*(longlong *)(param_2 + 0x1b0) != 0) {

      *(longlong *)(*(longlong *)(param_2 + 0x1b0) + 0x1b8) = param_1;

    }

    *(longlong *)(param_2 + 0x1b0) = param_1;

  }

  return;

}




