// Address: 0x14027a7b0
// Ghidra name: FUN_14027a7b0
// ============ 0x14027a7b0 FUN_14027a7b0 (size=54) ============


void FUN_14027a7b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  if (cVar1 != *(char *)((longlong)param_1 + 0x14)) {

    *(char *)((longlong)param_1 + 0x14) = cVar1;

    FUN_14027a830(param_1);

    FUN_1402089a0(*param_1);

    return;

  }

  return;

}




