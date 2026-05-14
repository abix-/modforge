// Address: 0x14009c7a0
// Ghidra name: FUN_14009c7a0
// ============ 0x14009c7a0 FUN_14009c7a0 (size=39) ============


void FUN_14009c7a0(longlong param_1,char param_2)



{

  *(char *)(param_1 + 0x28) = param_2;

  if (param_2 != '\0') {

    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x18))();

    FUN_14003f740();

    return;

  }

  FUN_14003f7b0();

  return;

}




