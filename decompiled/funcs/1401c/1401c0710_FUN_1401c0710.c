// Address: 0x1401c0710
// Ghidra name: FUN_1401c0710
// ============ 0x1401c0710 FUN_1401c0710 (size=364) ============


void FUN_1401c0710(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined1 param_4)



{

  longlong lVar1;

  longlong *plVar2;

  undefined8 uVar3;

  longlong *plVar4;

  ulonglong local_58;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  plVar2 = (longlong *)*param_2;

  uVar3 = *param_3;

  FUN_14017caa0(*(undefined8 *)(lVar1 + 0x918));

  plVar4 = (longlong *)

           FUN_1401bbea0(lVar1,param_1,uVar3,*(undefined4 *)((longlong)param_3 + 0xc),

                         *(undefined4 *)(param_3 + 1),param_4,2);

  local_2c = *(undefined4 *)((longlong)param_3 + 0x1c);

  local_28 = *(undefined4 *)(param_3 + 4);

  local_24 = *(undefined4 *)((longlong)param_3 + 0x24);

  local_38 = *(undefined4 *)(param_3 + 2);

  local_34 = *(undefined4 *)((longlong)param_3 + 0x14);

  local_30 = *(undefined4 *)(param_3 + 3);

  local_40 = *(undefined4 *)((longlong)param_3 + 0xc);

  local_48 = *(undefined4 *)(*plVar4 + 0x38);

  local_44 = *(undefined4 *)(param_3 + 1);

  local_58 = (ulonglong)*(uint *)(param_2 + 1);

  local_50 = *(undefined4 *)((longlong)param_2 + 0xc);

  local_4c = *(undefined4 *)(param_2 + 2);

  local_3c = 1;

  (**(code **)(lVar1 + 0xa70))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar2 + 0x10),

             *(undefined8 *)(*plVar4 + 0x18),7,1,&local_58);

  FUN_1401bd5f0(lVar1,param_1,2,plVar4);

  FUN_1401bd730(param_1,*plVar2);

  FUN_1401bdb50(param_1,*plVar4);

  FUN_1401bdc00(param_1,*plVar4);

  FUN_14017cae0(*(undefined8 *)(lVar1 + 0x918));

  return;

}




