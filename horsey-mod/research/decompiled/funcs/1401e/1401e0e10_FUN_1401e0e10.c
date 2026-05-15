// Address: 0x1401e0e10
// Ghidra name: FUN_1401e0e10
// ============ 0x1401e0e10 FUN_1401e0e10 (size=424) ============


longlong * FUN_1401e0e10(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  int iVar8;

  longlong lVar9;

  longlong *local_res8;

  undefined8 local_138;

  undefined4 local_130;

  undefined4 local_12c;

  undefined4 local_128;

  undefined4 local_124;

  undefined4 local_120;

  undefined4 local_11c;

  undefined4 local_118;

  undefined1 local_114;

  undefined1 local_113 [235];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar2 = FUN_14014df00(param_2);

  uVar3 = FUN_14014dee0(param_2);

  uVar4 = FUN_14014de80(param_2);

  uVar5 = FUN_14014dec0(param_2);

  uVar6 = FUN_14014dea0(param_2);

  uVar7 = FUN_14014de60(param_2);

  local_res8 = (longlong *)0x0;

  FUN_1402f94c0(local_113,0,0xe3);

  local_130 = 1;

  local_138 = 0;

  local_12c = FUN_1401e0080(uVar2);

  local_128 = FUN_1401e0080(uVar5);

  local_124 = FUN_1401e0040(uVar4);

  local_120 = FUN_1401e0080(uVar3);

  local_11c = FUN_1401e0080(uVar6);

  local_118 = FUN_1401e0040(uVar7);

  local_114 = 0xf;

  iVar8 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0xa0))

                    (*(longlong **)(lVar1 + 0x20),&local_138,&local_res8);

  if (iVar8 < 0) {

    FUN_1401a9ef0("ID3D11Device1::CreateBlendState",iVar8);

    local_res8 = (longlong *)0x0;

  }

  else {

    lVar9 = FUN_140184230(*(undefined8 *)(lVar1 + 0x110),

                          ((longlong)*(int *)(lVar1 + 0x108) + 1) * 0x10);

    if (lVar9 == 0) {

      if (local_res8 != (longlong *)0x0) {

        (**(code **)(*local_res8 + 0x10))();

      }

      local_res8 = (longlong *)0x0;

    }

    else {

      *(undefined4 *)(lVar9 + (longlong)*(int *)(lVar1 + 0x108) * 0x10) = param_2;

      *(longlong **)(lVar9 + 8 + (longlong)*(int *)(lVar1 + 0x108) * 0x10) = local_res8;

      *(int *)(lVar1 + 0x108) = *(int *)(lVar1 + 0x108) + 1;

      *(longlong *)(lVar1 + 0x110) = lVar9;

    }

  }

  return local_res8;

}




