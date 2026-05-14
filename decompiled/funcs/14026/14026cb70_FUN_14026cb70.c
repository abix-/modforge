// Address: 0x14026cb70
// Ghidra name: FUN_14026cb70
// ============ 0x14026cb70 FUN_14026cb70 (size=54) ============


void FUN_14026cb70(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  if (cVar1 != *(char *)((longlong)param_1 + 0x12)) {

    *(char *)((longlong)param_1 + 0x12) = cVar1;

    FUN_14026d300(param_1);

    FUN_1402089a0(*param_1);

    return;

  }

  return;

}




