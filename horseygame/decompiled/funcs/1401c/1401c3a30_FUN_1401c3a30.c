// Address: 0x1401c3a30
// Ghidra name: FUN_1401c3a30
// ============ 0x1401c3a30 FUN_1401c3a30 (size=373) ============


void FUN_1401c3a30(longlong param_1,undefined8 *param_2,undefined8 *param_3,int param_4,int param_5,

                  int param_6,undefined1 param_7)



{

  longlong *plVar1;

  longlong *plVar2;

  undefined8 in_stack_ffffffffffffff50;

  undefined4 uVar3;

  int local_98;

  int local_94;

  int local_90;

  int local_8c;

  int local_88;

  int local_84;

  undefined8 local_80;

  undefined4 local_78;

  undefined4 local_70;

  undefined8 local_50;

  undefined4 local_48;

  undefined4 local_40;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);

  plVar1 = (longlong *)

           FUN_1401c9f20(*param_2,*(undefined4 *)((longlong)param_2 + 0xc),

                         *(undefined4 *)(param_2 + 1));

  plVar2 = (longlong *)

           FUN_1401ca910(param_1,*param_3,*(undefined4 *)((longlong)param_3 + 0xc),

                         *(undefined4 *)(param_3 + 1),param_7,CONCAT44(uVar3,0x400));

  FUN_1401cb470(param_1,0x800,plVar1);

  local_78 = 0;

  local_70 = *(undefined4 *)((longlong)plVar1 + 0x14);

  local_80 = *(undefined8 *)(*plVar1 + 0x20);

  local_48 = 0;

  local_40 = *(undefined4 *)((longlong)plVar2 + 0x14);

  local_90 = *(int *)(param_2 + 3);

  local_50 = *(undefined8 *)(*plVar2 + 0x20);

  local_98 = *(int *)(param_2 + 2);

  local_94 = *(int *)((longlong)param_2 + 0x14);

  local_88 = local_94 + param_5;

  local_8c = local_98 + param_4;

  local_84 = param_6 + local_90;

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x80))

            (*(longlong **)(param_1 + 0x120),&local_50,*(undefined4 *)(param_3 + 2),

             *(undefined4 *)((longlong)param_3 + 0x14),*(undefined4 *)(param_3 + 3),&local_80,

             &local_98);

  FUN_1401cb4c0(param_1,0x800,plVar1);

  FUN_1401cb4c0(param_1,0x400,plVar2);

  FUN_1401cb900(param_1,*plVar1);

  FUN_1401cb900(param_1,*plVar2);

  return;

}




