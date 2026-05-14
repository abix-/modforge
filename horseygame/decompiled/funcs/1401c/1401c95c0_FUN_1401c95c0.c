// Address: 0x1401c95c0
// Ghidra name: FUN_1401c95c0
// ============ 0x1401c95c0 FUN_1401c95c0 (size=111) ============


void FUN_1401c95c0(longlong param_1)



{

  if (param_1 != 0) {

    if (*(longlong *)(param_1 + 0x80) != 0) {

      (**(code **)(**(longlong **)(param_1 + 0x10) + 0x48))(*(longlong **)(param_1 + 0x10),0,0);

    }

    FUN_1401cade0(param_1 + 0x38);

    FUN_1401cade0(param_1 + 0x18);

    FUN_1401cade0(param_1 + 0x58);

    if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(param_1 + 0x10) + 0x10))();

    }

    FUN_1401841e0(param_1);

  }

  return;

}




