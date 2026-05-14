// Address: 0x1402177a0
// Ghidra name: FUN_1402177a0
// ============ 0x1402177a0 FUN_1402177a0 (size=32) ============


void FUN_1402177a0(undefined8 *param_1,undefined8 *param_2)



{

  if ((ulonglong)param_1[2] < (ulonglong)param_1[3]) {

    *param_2 = *param_1;

    param_1[2] = param_1[2] + 1;

    *param_1 = param_2;

    return;

  }

  FUN_1401841e0(param_2);

  return;

}




