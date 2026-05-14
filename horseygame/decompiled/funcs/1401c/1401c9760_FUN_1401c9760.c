// Address: 0x1401c9760
// Ghidra name: FUN_1401c9760
// ============ 0x1401c9760 FUN_1401c9760 (size=59) ============


void FUN_1401c9760(longlong *param_1)



{

  if (param_1 != (longlong *)0x0) {

    if ((longlong *)*param_1 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*param_1 + 0x10))();

    }

    if ((HANDLE)param_1[1] != (HANDLE)0x0) {

      CloseHandle((HANDLE)param_1[1]);

    }

    FUN_1401841e0(param_1);

  }

  return;

}




