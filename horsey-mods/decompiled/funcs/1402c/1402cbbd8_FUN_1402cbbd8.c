// Address: 0x1402cbbd8
// Ghidra name: FUN_1402cbbd8
// ============ 0x1402cbbd8 FUN_1402cbbd8 (size=382) ============


undefined8 FUN_1402cbbd8(longlong param_1)



{

  undefined8 uVar1;

  undefined8 uVar2;

  int *piVar3;

  longlong *plVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  undefined1 local_48 [16];

  

  lVar6 = FUN_1402c97f8();

  uVar1 = *(undefined8 *)(lVar6 + 0x28);

  lVar6 = FUN_1402c97f8();

  uVar2 = *(undefined8 *)(lVar6 + 0x20);

  piVar3 = *(int **)(param_1 + 0x50);

  lVar6 = *(longlong *)(param_1 + 0x48);

  uVar8 = *(undefined8 *)(param_1 + 0x40);

  uVar9 = *(undefined8 *)(param_1 + 0x30);

  plVar4 = *(longlong **)(param_1 + 0x28);

  __except_validate_context_record(uVar8);

  lVar7 = FUN_1402c97f8();

  *(int **)(lVar7 + 0x20) = piVar3;

  lVar7 = FUN_1402c97f8();

  *(undefined8 *)(lVar7 + 0x28) = uVar8;

  lVar7 = FUN_1402c97f8();

  uVar8 = _CreateFrameInfo(local_48,*(undefined8 *)(*(longlong *)(lVar7 + 0x20) + 0x28));

  if (*(longlong *)(param_1 + 0x58) != 0) {

    FUN_1402c97f8();

  }

  uVar9 = _CallSettingFrame(uVar9,plVar4,0x100);

  FUN_1402c8dfc(uVar8);

  if ((((*piVar3 == -0x1f928c9d) && (piVar3[6] == 4)) &&

      ((piVar3[8] == 0x19930520 || (piVar3[8] + 0xe66cfadfU < 2)))) &&

     (iVar5 = _IsExceptionObjectToBeDestroyed(*(undefined8 *)(piVar3 + 10)), iVar5 != 0)) {

    FUN_1402c9000(piVar3,1);

  }

  lVar7 = FUN_1402c97f8();

  *(undefined8 *)(lVar7 + 0x20) = uVar2;

  lVar7 = FUN_1402c97f8();

  *(undefined8 *)(lVar7 + 0x28) = uVar1;

  *(undefined8 *)((longlong)*(int *)(lVar6 + 0x1c) + *plVar4) = 0xfffffffffffffffe;

  return uVar9;

}




