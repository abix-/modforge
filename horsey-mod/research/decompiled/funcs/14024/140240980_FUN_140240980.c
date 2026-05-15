// Address: 0x140240980
// Ghidra name: FUN_140240980
// ============ 0x140240980 FUN_140240980 (size=85) ============


void FUN_140240980(longlong param_1,int *param_2)



{

  undefined8 *puVar1;

  

  puVar1 = (undefined8 *)(param_1 + 0x28);

  if (param_2[1] != 0) {

    (*(code *)*puVar1)(param_2[1]);

    param_2[1] = 0;

  }

  if (param_2[2] != 0) {

    (*(code *)*puVar1)();

    param_2[2] = 0;

  }

  if (*param_2 != 0) {

    (*(code *)*puVar1)();

    *param_2 = 0;

  }

  return;

}




