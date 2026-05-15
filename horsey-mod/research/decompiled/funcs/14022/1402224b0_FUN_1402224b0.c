// Address: 0x1402224b0
// Ghidra name: FUN_1402224b0
// ============ 0x1402224b0 FUN_1402224b0 (size=221) ============


undefined8 FUN_1402224b0(longlong param_1)



{

  char cVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  

  lVar3 = *(longlong *)(param_1 + 0x680);

  lVar4 = *(longlong *)(lVar3 + 0x138);

  cVar1 = *(char *)(lVar3 + 0x128);

  cVar2 = *(char *)(lVar3 + 0x129);

  FUN_140179b40();

  uVar5 = 0;

  *(uint *)(lVar4 + 0x20) = -(uint)(cVar2 != '\0') & 0x10 | -(uint)(cVar1 != '\0') & 0x20;

  uVar7 = uVar5;

  if (0 < *(int *)(lVar4 + 0x10)) {

    do {

      lVar3 = *(longlong *)(uVar5 + *(longlong *)(lVar4 + 0x18));

      if ((*(longlong **)(lVar3 + 0x20) != (longlong *)0x0) && (cVar1 == '\0')) {

        (**(code **)(**(longlong **)(lVar3 + 0x20) + 0x10))();

        *(undefined8 *)(lVar3 + 0x20) = 0;

      }

      if ((*(longlong **)(lVar3 + 0x28) != (longlong *)0x0) && (cVar2 == '\0')) {

        (**(code **)(**(longlong **)(lVar3 + 0x28) + 0x10))();

        *(undefined8 *)(lVar3 + 0x28) = 0;

      }

      uVar6 = (int)uVar7 + 1;

      uVar5 = uVar5 + 8;

      uVar7 = (ulonglong)uVar6;

    } while ((int)uVar6 < *(int *)(lVar4 + 0x10));

  }

  FUN_140179b60(*(undefined8 *)(lVar4 + 0x28));

  return 1;

}




