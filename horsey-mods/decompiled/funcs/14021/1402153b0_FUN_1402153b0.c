// Address: 0x1402153b0
// Ghidra name: FUN_1402153b0
// ============ 0x1402153b0 FUN_1402153b0 (size=284) ============


int FUN_1402153b0(longlong param_1,undefined8 param_2,int param_3)



{

  longlong lVar1;

  longlong lVar2;

  longlong *plVar3;

  int iVar4;

  undefined4 uVar5;

  int local_res8 [2];

  uint local_res20 [2];

  undefined8 local_28 [2];

  

  lVar1 = *(longlong *)(param_1 + 200);

  local_28[0] = 0;

  local_res8[0] = 0;

  local_res20[0] = 0;

  lVar2 = *(longlong *)(lVar1 + 0x20);

  while( true ) {

    if ((lVar2 == 0) || (iVar4 = FUN_140138fe0(lVar1 + 0x40), iVar4 != 0)) {

      return -1;

    }

    plVar3 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x20);

    iVar4 = (**(code **)(*plVar3 + 0x18))(plVar3,local_28,local_res8,local_res20,0,0);

    if (iVar4 == 0x8890001) {

      return 0;

    }

    FUN_1402156d0(param_1);

    lVar1 = *(longlong *)(param_1 + 200);

    if (iVar4 == 0) break;

    lVar2 = *(longlong *)(lVar1 + 0x20);

  }

  iVar4 = local_res8[0] * *(int *)(lVar1 + 0x3c);

  if (param_3 < iVar4) {

    iVar4 = param_3;

  }

  if ((local_res20[0] & 2) == 0) {

    FUN_1402f8e20(param_2,local_28[0],(longlong)iVar4);

  }

  else {

    FUN_1402f94c0(param_2,*(undefined4 *)(param_1 + 0x88));

  }

  plVar3 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x20);

  uVar5 = (**(code **)(*plVar3 + 0x20))(plVar3,local_res8[0]);

  FUN_1402156d0(param_1,uVar5);

  return iVar4;

}




