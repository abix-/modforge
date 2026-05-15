// Address: 0x1400470e0
// Ghidra name: FUN_1400470e0
// ============ 0x1400470e0 FUN_1400470e0 (size=133) ============


void FUN_1400470e0(undefined8 param_1,undefined8 param_2,longlong *param_3)



{

  char cVar1;

  longlong *plVar2;

  

  cVar1 = *(char *)((longlong)param_3 + 0x19);

  while (cVar1 == '\0') {

    FUN_1400470e0(param_1,param_2,param_3[2]);

    plVar2 = (longlong *)*param_3;

    FUN_140047910(param_3 + 8);

    FUN_140027900(param_3 + 4);

    FUN_1402c7088(param_3,0x58);

    param_3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  return;

}




