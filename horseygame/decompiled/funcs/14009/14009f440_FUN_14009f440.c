// Address: 0x14009f440
// Ghidra name: FUN_14009f440
// ============ 0x14009f440 FUN_14009f440 (size=92) ============


void FUN_14009f440(longlong *param_1)



{

  char cVar1;

  longlong *plVar2;

  longlong *plVar3;

  

  cVar1 = *(char *)((longlong)*(longlong **)(*param_1 + 8) + 0x19);

  plVar3 = *(longlong **)(*param_1 + 8);

  while (cVar1 == '\0') {

    FUN_14009f2f0(param_1,param_1,plVar3[2]);

    plVar2 = (longlong *)*plVar3;

    FUN_1402c7088(plVar3,0x30);

    plVar3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  FUN_1402c7088(*param_1,0x30);

  return;

}




