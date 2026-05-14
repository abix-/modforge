// Address: 0x1401840e0
// Ghidra name: FUN_1401840e0
// ============ 0x1401840e0 FUN_1401840e0 (size=61) ============


void FUN_1401840e0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)



{

  if (param_1 != (undefined8 *)0x0) {

    *param_1 = _malloc_base;

  }

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = _calloc_base;

  }

  if (param_3 != (undefined8 *)0x0) {

    *param_3 = _realloc_base;

  }

  if (param_4 != (undefined8 *)0x0) {

    *param_4 = thunk_FUN_1402e9a80;

  }

  return;

}




