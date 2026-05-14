// Address: 0x140047050
// Ghidra name: FUN_140047050
// ============ 0x140047050 FUN_140047050 (size=133) ============


void FUN_140047050(undefined8 param_1,undefined8 param_2,longlong *param_3)



{

  char cVar1;

  longlong *plVar2;

  

  cVar1 = *(char *)((longlong)param_3 + 0x19);

  while (cVar1 == '\0') {

    FUN_140047050(param_1,param_2,param_3[2]);

    plVar2 = (longlong *)*param_3;

    FUN_140027900(param_3 + 8);

    FUN_140027900(param_3 + 4);

    FUN_1402c7088(param_3,0x60);

    param_3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  return;

}




