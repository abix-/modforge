// Address: 0x1401c5990
// Ghidra name: FUN_1401c5990
// ============ 0x1401c5990 FUN_1401c5990 (size=276) ============


longlong * FUN_1401c5990(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  longlong *plVar4;

  longlong lVar5;

  uint uVar6;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  FUN_140179b40(*(undefined8 *)(lVar1 + 0x208));

  if (*(int *)(lVar1 + 0x138) != 0) {

    uVar6 = *(int *)(lVar1 + 0x138) - 1;

    plVar4 = *(longlong **)(*(longlong *)(lVar1 + 0x130) + (ulonglong)uVar6 * 8);

    *(uint *)(lVar1 + 0x138) = uVar6;

LAB_1401c5a30:

    FUN_140179b60(*(undefined8 *)(lVar1 + 0x208));

    plVar4[1] = 0;

    plVar2 = *(longlong **)(*plVar4 + 0x10);

    iVar3 = (**(code **)(*plVar2 + 0x40))(plVar2,0,0,*plVar4 + 0x80);

    if (iVar3 < 0) {

      FUN_1401cb240(lVar1,"Failed to map buffer pool!",iVar3);

      return (longlong *)0x0;

    }

    FUN_1401cb9a0(param_1,plVar4);

    return plVar4;

  }

  plVar4 = (longlong *)FUN_1401841a0(1,0x10);

  if (plVar4 != (longlong *)0x0) {

    lVar5 = FUN_1401c7580(lVar1,0,0x8000,1,0);

    *plVar4 = lVar5;

    if (lVar5 != 0) goto LAB_1401c5a30;

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0x208));

  return (longlong *)0x0;

}




