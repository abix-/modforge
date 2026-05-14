// Address: 0x140074ba0
// Ghidra name: FUN_140074ba0
// ============ 0x140074ba0 FUN_140074ba0 (size=118) ============


void FUN_140074ba0(undefined8 param_1,undefined8 param_2,longlong *param_3)



{

  char cVar1;

  longlong *plVar2;

  

  cVar1 = *(char *)((longlong)param_3 + 0x19);

  while (cVar1 == '\0') {

    FUN_140074ba0(param_1,param_2,param_3[2]);

    plVar2 = (longlong *)*param_3;

    FUN_140027900(param_3 + 4);

    FUN_1402c7088(param_3,0x48);

    param_3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  return;

}




