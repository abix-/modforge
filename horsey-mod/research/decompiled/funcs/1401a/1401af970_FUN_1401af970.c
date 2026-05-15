// Address: 0x1401af970
// Ghidra name: FUN_1401af970
// ============ 0x1401af970 FUN_1401af970 (size=477) ============


void FUN_1401af970(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined1 param_7)



{

  longlong lVar1;

  longlong *plVar2;

  longlong *plVar3;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar4;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

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

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x110);

  FUN_14017caa0(*(undefined8 *)(lVar1 + 0x918));

  plVar2 = (longlong *)

           FUN_1401bac70(*param_2,*(undefined4 *)((longlong)param_2 + 0xc),

                         *(undefined4 *)(param_2 + 1));

  plVar3 = (longlong *)

           FUN_1401bbea0(lVar1,param_1,*param_3,*(undefined4 *)((longlong)param_3 + 0xc),

                         *(undefined4 *)(param_3 + 1),param_7,CONCAT44(uVar4,2));

  FUN_1401bd590(lVar1,param_1,1,plVar2);

  local_58 = *(undefined4 *)(param_2 + 2);

  local_60 = *(undefined4 *)((longlong)param_2 + 0xc);

  local_54 = *(undefined4 *)((longlong)param_2 + 0x14);

  local_50 = *(undefined4 *)(param_2 + 3);

  local_68 = *(undefined4 *)(*plVar2 + 0x38);

  local_64 = *(undefined4 *)(param_2 + 1);

  local_3c = *(undefined4 *)(param_3 + 2);

  local_38 = *(undefined4 *)((longlong)param_3 + 0x14);

  local_34 = *(undefined4 *)(param_3 + 3);

  local_5c = 1;

  local_4c = *(undefined4 *)(*plVar3 + 0x38);

  local_44 = *(undefined4 *)((longlong)param_3 + 0xc);

  local_48 = *(undefined4 *)(param_3 + 1);

  local_2c = param_5;

  local_28 = param_6;

  local_40 = 1;

  local_30 = param_4;

  (**(code **)(lVar1 + 0xa68))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar2 + 0x18),6,

             *(undefined8 *)(*plVar3 + 0x18),7,1,&local_68);

  FUN_1401bd5f0(lVar1,param_1,1,plVar2);

  FUN_1401bd5f0(lVar1,param_1,2,plVar3);

  FUN_1401bdb50(param_1,*plVar2);

  FUN_1401bdb50(param_1,*plVar3);

  FUN_1401bdc00(param_1,*plVar2);

  FUN_1401bdc00(param_1,*plVar3);

  FUN_14017cae0(*(undefined8 *)(lVar1 + 0x918));

  return;

}




