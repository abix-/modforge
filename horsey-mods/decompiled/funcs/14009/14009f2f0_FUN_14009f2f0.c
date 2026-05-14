// Address: 0x14009f2f0
// Ghidra name: FUN_14009f2f0
// ============ 0x14009f2f0 FUN_14009f2f0 (size=85) ============


void FUN_14009f2f0(undefined8 param_1,undefined8 param_2,longlong *param_3)



{

  char cVar1;

  longlong *plVar2;

  

  cVar1 = *(char *)((longlong)param_3 + 0x19);

  while (cVar1 == '\0') {

    FUN_14009f2f0(param_1,param_2,param_3[2]);

    plVar2 = (longlong *)*param_3;

    FUN_1402c7088(param_3,0x30);

    param_3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  return;

}




