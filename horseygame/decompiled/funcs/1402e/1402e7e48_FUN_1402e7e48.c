// Address: 0x1402e7e48
// Ghidra name: FUN_1402e7e48
// ============ 0x1402e7e48 FUN_1402e7e48 (size=54) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402e7e48(undefined8 *param_1,undefined8 *param_2)



{

  for (; param_1 != param_2; param_1 = param_1 + 1) {

    if ((code *)*param_1 != (code *)0x0) {

      (*(code *)*param_1)();

    }

  }

  return;

}




