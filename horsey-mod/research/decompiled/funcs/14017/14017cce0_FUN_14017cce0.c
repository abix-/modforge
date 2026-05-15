// Address: 0x14017cce0
// Ghidra name: FUN_14017cce0
// ============ 0x14017cce0 FUN_14017cce0 (size=48) ============


void FUN_14017cce0(undefined8 *param_1)



{

  if (param_1 != (undefined8 *)0x0) {

    if ((HANDLE)*param_1 != (HANDLE)0x0) {

      CloseHandle((HANDLE)*param_1);

      *param_1 = 0;

    }

    FUN_1401841e0(param_1);

  }

  return;

}




