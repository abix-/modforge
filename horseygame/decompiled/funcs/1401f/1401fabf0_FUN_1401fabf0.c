// Address: 0x1401fabf0
// Ghidra name: FUN_1401fabf0
// ============ 0x1401fabf0 FUN_1401fabf0 (size=381) ============


undefined4 FUN_1401fabf0(longlong param_1)



{

  longlong *plVar1;

  longlong *plVar2;

  uint uVar3;

  longlong lVar4;

  ulonglong uVar5;

  undefined4 uVar6;

  undefined4 *puVar7;

  undefined4 local_res8 [2];

  undefined4 local_58;

  undefined8 local_54;

  longlong local_4c;

  undefined4 local_44;

  longlong *plStack_40;

  undefined4 uStack_38;

  undefined4 local_34;

  undefined8 local_30;

  longlong *local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  plVar1 = (longlong *)(param_1 + 0x698);

  if (*plVar1 == 0) {

    return 0;

  }

  if (*(longlong *)(param_1 + 0x710) != 0) {

    (*DAT_1403fcf10)();

    *(undefined8 *)(param_1 + 0x710) = 0;

  }

  *(undefined8 *)(param_1 + 0x2868) = 0;

  *(undefined1 *)(param_1 + 0x2928) = 1;

  (*DAT_1403fd038)(*plVar1);

  uVar3 = *(uint *)(param_1 + 0x28e0);

  plVar2 = (longlong *)(param_1 + 0x28c0);

  lVar4 = *plVar2;

  local_54 = 0;

  local_4c = 0;

  local_44 = 0;

  plStack_40 = (longlong *)0x0;

  uStack_38 = 0;

  local_34 = 0;

  local_30 = 1;

  local_20 = 0;

  local_18 = 0;

  local_res8[0] = 0x10000;

  local_58 = 4;

  if (uVar3 == 0) {

    if (lVar4 == 0) goto LAB_1401fad1e;

    uVar5 = 1;

    puVar7 = local_res8;

    plStack_40 = plVar2;

  }

  else {

    uVar5 = (ulonglong)((lVar4 != 0) + uVar3);

    if (lVar4 != 0) {

      *(longlong *)(*(longlong *)(param_1 + 0x28d8) + (ulonglong)uVar3 * 8) = lVar4;

      *(undefined4 *)(*(longlong *)(param_1 + 0x28d0) + (ulonglong)*(uint *)(param_1 + 0x28e0) * 4)

           = 0x10000;

    }

    puVar7 = *(undefined4 **)(param_1 + 0x28d0);

    *(undefined4 *)(param_1 + 0x28e0) = 0;

    plStack_40 = *(longlong **)(param_1 + 0x28d8);

  }

  local_4c = uVar5 << 0x20;

  uStack_38 = SUB84(puVar7,0);

  local_34 = (undefined4)((ulonglong)puVar7 >> 0x20);

LAB_1401fad1e:

  local_28 = plVar1;

  uVar6 = (*DAT_1403fd088)(*(undefined8 *)(param_1 + 0x650),1,&local_58,0);

  *plVar2 = 0;

  FUN_1402000b0(param_1);

  FUN_1401fdd80(param_1);

  return uVar6;

}




