// Address: 0x1401af2b0
// Ghidra name: FUN_1401af2b0
// ============ 0x1401af2b0 FUN_1401af2b0 (size=624) ============


void FUN_1401af2b0(longlong param_1,undefined8 *param_2)



{

  longlong lVar1;

  longlong *plVar2;

  longlong *plVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  undefined8 in_stack_ffffffffffffff38;

  undefined4 uVar9;

  undefined4 local_b8;

  undefined4 local_b4;

  undefined4 local_b0;

  undefined4 local_ac;

  int local_a8;

  int local_a4;

  int local_a0;

  int local_9c;

  int local_98;

  int local_94;

  undefined4 local_90;

  undefined4 local_8c;

  undefined4 local_88;

  undefined4 local_84;

  int local_80;

  int local_7c;

  int local_78;

  int local_74;

  int local_70;

  int local_6c;

  int *local_68;

  undefined4 local_60;

  int local_5c;

  undefined4 local_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined1 local_30;

  undefined4 local_2f;

  undefined2 local_2b;

  undefined1 local_29;

  

  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x110);

  if (*(int *)*param_2 == 2) {

    iVar4 = *(int *)((longlong)param_2 + 0xc);

    uVar7 = 0;

  }

  else {

    uVar7 = *(undefined4 *)((longlong)param_2 + 0xc);

    iVar4 = 0;

  }

  if (*(int *)param_2[4] == 2) {

    iVar6 = *(int *)((longlong)param_2 + 0x2c);

    iVar8 = iVar6;

    iVar5 = 0;

  }

  else {

    iVar6 = *(int *)((longlong)param_2 + 0x2c);

    iVar8 = 0;

    iVar5 = iVar6;

  }

  if (*(int *)(param_2 + 8) == 1) {

    local_60 = *(undefined4 *)(param_2 + 5);

    local_58 = *(undefined4 *)((longlong)param_2 + 0x44);

    uStack_54 = *(undefined4 *)(param_2 + 9);

    uStack_50 = *(undefined4 *)((longlong)param_2 + 0x4c);

    uStack_4c = *(undefined4 *)(param_2 + 10);

    local_30 = *(undefined1 *)((longlong)param_2 + 0x5c);

    local_40 = 0;

    local_38 = 0;

    local_2f = 0;

    local_2b = 0;

    local_29 = 0;

    local_48 = 1;

    local_68 = (int *)param_2[4];

    local_5c = iVar6;

    FUN_1401ae360(param_1,&local_68,1,0);

    FUN_1401b1cc0(param_1);

  }

  plVar2 = (longlong *)FUN_1401bac70(*param_2,uVar7,*(undefined4 *)(param_2 + 1));

  plVar3 = (longlong *)

           FUN_1401bbea0(lVar1,param_1,param_2[4],iVar5,*(undefined4 *)(param_2 + 5),

                         *(undefined1 *)((longlong)param_2 + 0x5c),CONCAT44(uVar9,2));

  FUN_1401bd590(lVar1,param_1,1,plVar2);

  local_94 = iVar4 + 1;

  local_b8 = *(undefined4 *)(*plVar2 + 0x38);

  local_b0 = (undefined4)plVar2[1];

  iVar6 = *(int *)((longlong)param_2 + 0x14);

  local_98 = *(int *)((longlong)param_2 + 0x1c) + iVar6;

  local_ac = 1;

  local_b4 = *(undefined4 *)((longlong)plVar2 + 0xc);

  iVar5 = *(int *)(param_2 + 2);

  local_a8 = iVar5;

  local_9c = *(int *)(param_2 + 3) + iVar5;

  if ((*(uint *)((longlong)param_2 + 0x54) & 1) != 0) {

    local_a8 = *(int *)(param_2 + 3) + iVar5;

    local_9c = iVar5;

  }

  local_a4 = iVar6;

  if ((*(uint *)((longlong)param_2 + 0x54) & 2) != 0) {

    local_a4 = local_98;

    local_98 = iVar6;

  }

  local_7c = *(int *)((longlong)param_2 + 0x34);

  local_90 = *(undefined4 *)(*plVar3 + 0x38);

  local_88 = (undefined4)plVar3[1];

  local_80 = *(int *)(param_2 + 6);

  local_84 = 1;

  local_8c = *(undefined4 *)((longlong)plVar3 + 0xc);

  local_74 = local_80 + *(int *)(param_2 + 7);

  local_6c = iVar8 + 1;

  local_70 = *(int *)((longlong)param_2 + 0x3c) + local_7c;

  local_a0 = iVar4;

  local_78 = iVar8;

  (**(code **)(lVar1 + 0xa40))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar2 + 0x18),6,

             *(undefined8 *)(*plVar3 + 0x18),7,1,&local_b8,

             *(undefined4 *)(&DAT_1403e4268 + (longlong)*(int *)(param_2 + 0xb) * 4));

  FUN_1401bd5f0(lVar1,param_1,1,plVar2);

  FUN_1401bd5f0(lVar1,param_1,2,plVar3);

  FUN_1401bdb50(param_1,*plVar2);

  FUN_1401bdb50(param_1,*plVar3);

  return;

}




