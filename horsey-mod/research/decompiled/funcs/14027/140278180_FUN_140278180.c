// Address: 0x140278180
// Ghidra name: FUN_140278180
// ============ 0x140278180 FUN_140278180 (size=104) ============


void FUN_140278180(longlong param_1)



{

  undefined4 uVar1;

  longlong *plVar2;

  

  plVar2 = (longlong *)FUN_1401841a0(1,0x98);

  if (plVar2 == (longlong *)0x0) {

    return;

  }

  *plVar2 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar2;

  if (*(short *)(param_1 + 0x20) == 0x57e) {

    uVar1 = FUN_140279a40(param_1);

    *(undefined4 *)((longlong)plVar2 + 0x1c) = uVar1;

    FUN_140279dd0(param_1);

  }

  FUN_140208110(param_1,0);

  return;

}




