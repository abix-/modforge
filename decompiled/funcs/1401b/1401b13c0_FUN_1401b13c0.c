// Address: 0x1401b13c0
// Ghidra name: FUN_1401b13c0
// ============ 0x1401b13c0 FUN_1401b13c0 (size=337) ============


void FUN_1401b13c0(longlong param_1,undefined8 *param_2,undefined8 *param_3)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong *plVar3;

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

  uVar2 = *param_2;

  plVar3 = (longlong *)*param_3;

  FUN_14017caa0(*(undefined8 *)(lVar1 + 0x918));

  plVar4 = (longlong *)

           FUN_1401bac70(uVar2,*(undefined4 *)((longlong)param_2 + 0xc),*(undefined4 *)(param_2 + 1)

                        );

  FUN_1401bd590(lVar1,param_1,1,plVar4);

  local_2c = *(undefined4 *)((longlong)param_2 + 0x1c);

  local_34 = *(undefined4 *)((longlong)param_2 + 0x14);

  local_30 = *(undefined4 *)(param_2 + 3);

  local_28 = *(undefined4 *)(param_2 + 4);

  local_24 = *(undefined4 *)((longlong)param_2 + 0x24);

  local_38 = *(undefined4 *)(param_2 + 2);

  local_48 = *(undefined4 *)(*plVar4 + 0x38);

  local_40 = *(undefined4 *)((longlong)param_2 + 0xc);

  local_44 = *(undefined4 *)(param_2 + 1);

  local_58 = (ulonglong)*(uint *)(param_3 + 1);

  local_50 = *(undefined4 *)((longlong)param_3 + 0xc);

  local_4c = *(undefined4 *)(param_3 + 2);

  local_3c = 1;

  (**(code **)(lVar1 + 0xa78))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar4 + 0x18),6,

             *(undefined8 *)(*plVar3 + 0x10),1,&local_58);

  FUN_1401bd5f0(lVar1,param_1,1,plVar4);

  FUN_1401bd730(param_1,*plVar3);

  FUN_1401bdb50(param_1,*plVar4);

  FUN_1401bdc00(param_1,*plVar4);

  FUN_14017cae0(*(undefined8 *)(lVar1 + 0x918));

  return;

}




