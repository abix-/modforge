// Address: 0x140268680
// Ghidra name: FUN_140268680
// ============ 0x140268680 FUN_140268680 (size=186) ============


undefined4 FUN_140268680(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  longlong *plVar3;

  longlong *plVar4;

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x170);

  if (plVar3 == (longlong *)0x0) {

    return 0;

  }

  *plVar3 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar3;

  uVar2 = FUN_140269a80(param_1);

  *(undefined4 *)((longlong)plVar3 + 0x1c) = uVar2;

  *(undefined1 *)(plVar3 + 3) = 1;

  cVar1 = FUN_1401595e0(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22));

  *(char *)(plVar3 + 2) = cVar1;

  if (cVar1 == '\0') {

    plVar4 = plVar3 + 7;

    FUN_14026cf50(param_1,plVar4);

    FUN_14026cf50(param_1,(longlong)plVar4 + 4);

    FUN_140269130(plVar3);

  }

  FUN_14026cfc0(param_1);

  if (*(char *)(param_1 + 0x54) == '\0') {

    FUN_140207920(*(undefined8 *)(param_1 + 0x28));

  }

  else {

    cVar1 = FUN_140207f20();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  uVar2 = FUN_140208110(param_1,0);

  return uVar2;

}




