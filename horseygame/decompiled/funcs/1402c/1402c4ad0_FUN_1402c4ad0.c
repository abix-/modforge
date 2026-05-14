// Address: 0x1402c4ad0
// Ghidra name: FUN_1402c4ad0
// ============ 0x1402c4ad0 FUN_1402c4ad0 (size=109) ============


void FUN_1402c4ad0(undefined8 param_1,longlong param_2)



{

  FUN_140179b40(DAT_1403fdeb8);

  if (*(longlong *)(param_2 + 0x78) != 0) {

    if (*(longlong *)(param_2 + 0x80) != 0) {

      *(longlong *)(*(longlong *)(param_2 + 0x80) + 0x78) = *(longlong *)(param_2 + 0x78);

    }

    *(undefined8 *)(*(longlong *)(param_2 + 0x78) + 0x80) = *(undefined8 *)(param_2 + 0x80);

    *(undefined8 *)(param_2 + 0x80) = 0;

    *(undefined8 *)(param_2 + 0x78) = 0;

    *(undefined4 *)(param_2 + 0x38) = 2;

    FUN_1402c4c90(param_2);

  }

  FUN_140179b60(DAT_1403fdeb8);

  return;

}




