// Address: 0x1401aaee0
// Ghidra name: FUN_1401aaee0
// ============ 0x1401aaee0 FUN_1401aaee0 (size=179) ============


longlong *

FUN_1401aaee0(undefined8 param_1,char param_2,longlong param_3,longlong param_4,longlong param_5,

             longlong param_6)



{

  int iVar1;

  longlong *plVar2;

  longlong lVar3;

  

  iVar1 = FUN_1401aaea0();

  plVar2 = (longlong *)FUN_1401841a0(1,0x40);

  if (plVar2 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  if (param_2 != '\0') {

    lVar3 = FUN_14017c930();

    *plVar2 = lVar3;

    if (lVar3 == 0) goto LAB_1401aaf49;

  }

  lVar3 = FUN_1401841a0(iVar1,0x18);

  plVar2[1] = lVar3;

  if (lVar3 != 0) {

    plVar2[2] = param_3;

    *(int *)(plVar2 + 6) = iVar1 + -1;

    plVar2[5] = param_6;

    plVar2[4] = param_5;

    plVar2[3] = param_4;

    return plVar2;

  }

LAB_1401aaf49:

  FUN_1401aafa0(plVar2);

  return (longlong *)0x0;

}




