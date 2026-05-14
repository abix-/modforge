// Address: 0x1401c86a0
// Ghidra name: FUN_1401c86a0
// ============ 0x1401c86a0 FUN_1401c86a0 (size=214) ============


undefined4 * FUN_1401c86a0(void)



{

  ulonglong uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  longlong *plVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  int iVar7;

  ulonglong uVar8;

  

  lVar2 = FUN_1401c7e90();

  if (lVar2 == 0) {

    return (undefined4 *)0x0;

  }

  puVar3 = (undefined4 *)FUN_1401841a0(1,0x28);

  *puVar3 = 1;

  plVar4 = (longlong *)FUN_1401841f0(8);

  *(longlong **)(puVar3 + 2) = plVar4;

  *plVar4 = lVar2;

  puVar3[4] = 0x400;

  puVar3[5] = 0x400;

  uVar5 = FUN_1401841f0(0x8000);

  uVar8 = 0;

  *(undefined8 *)(puVar3 + 6) = uVar5;

  uVar6 = uVar8;

  do {

    uVar1 = uVar6 + 0x20;

    iVar7 = (int)uVar8;

    *(undefined4 **)(uVar6 + *(longlong *)(puVar3 + 6)) = puVar3;

    *(longlong *)(*(longlong *)(puVar3 + 6) + -0x18 + uVar1) = lVar2;

    *(int *)(*(longlong *)(puVar3 + 6) + -8 + uVar1) = iVar7;

    uVar8 = (ulonglong)(iVar7 + 1U);

    *(ulonglong *)(*(longlong *)(puVar3 + 6) + -0x10 + uVar1) =

         (ulonglong)(uint)(iVar7 * *(int *)(lVar2 + 0x24)) + *(longlong *)(lVar2 + 0x10);

    uVar6 = uVar1;

  } while (iVar7 + 1U < 0x400);

  uVar5 = FUN_140179a30();

  *(undefined8 *)(puVar3 + 8) = uVar5;

  return puVar3;

}




