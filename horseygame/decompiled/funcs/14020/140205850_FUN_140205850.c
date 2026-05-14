// Address: 0x140205850
// Ghidra name: FUN_140205850
// ============ 0x140205850 FUN_140205850 (size=170) ============


void FUN_140205850(longlong param_1)



{

  int local_18;

  int local_14;

  int local_10;

  int local_c;

  

  FUN_1401384e0(*(undefined8 *)(param_1 + 0x90),param_1 + 0xe8);

  if (*(char *)(param_1 + 0x110) != '\0') {

    FUN_140138240(*(undefined8 *)(param_1 + 0x90),param_1 + 0x100);

    *(undefined1 *)(param_1 + 0x111) = 1;

    return;

  }

  if (*(char *)(param_1 + 0x111) != '\0') {

    local_18 = (int)*(float *)(param_1 + 0xe8);

    local_14 = (int)*(float *)(param_1 + 0xec);

    local_10 = (int)*(float *)(param_1 + 0xf0);

    local_c = (int)*(float *)(param_1 + 0xf4);

    FUN_140138240(*(undefined8 *)(param_1 + 0x90),&local_18);

    *(undefined1 *)(param_1 + 0x111) = 0;

  }

  return;

}




