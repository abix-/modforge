// Address: 0x14021a5f0
// Ghidra name: FUN_14021a5f0
// ============ 0x14021a5f0 FUN_14021a5f0 (size=146) ============


void FUN_14021a5f0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x690);

  if (lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0x10) != 0) {

      (**(code **)(lVar1 + 0x50))();

      *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10) = 0;

    }

    if (*(longlong *)(*(longlong *)(param_1 + 0x690) + 8) != 0) {

      FUN_140188670();

      *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 8) = 0;

    }

    if (**(longlong **)(param_1 + 0x690) != 0) {

      FUN_140188670();

      **(undefined8 **)(param_1 + 0x690) = 0;

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x690));

    *(undefined8 *)(param_1 + 0x690) = 0;

  }

  return;

}




