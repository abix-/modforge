// Address: 0x1401b12d0
// Ghidra name: FUN_1401b12d0
// ============ 0x1401b12d0 FUN_1401b12d0 (size=235) ============


void FUN_1401b12d0(longlong param_1,undefined8 *param_2,undefined8 *param_3)



{

  longlong lVar1;

  longlong *plVar2;

  longlong *plVar3;

  ulonglong local_38;

  ulonglong local_30;

  ulonglong local_28;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  plVar2 = (longlong *)*param_2;

  plVar3 = (longlong *)*param_3;

  FUN_14017caa0(*(undefined8 *)(lVar1 + 0x918));

  FUN_1401b5050(lVar1,param_1,0,*plVar2);

  local_38 = (ulonglong)*(uint *)(param_2 + 1);

  local_30 = (ulonglong)*(uint *)(param_3 + 1);

  local_28 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);

  (**(code **)(lVar1 + 0xa60))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar2 + 0x10),

             *(undefined8 *)(*plVar3 + 0x10),1,&local_38);

  FUN_1401b50b0(lVar1,param_1,0,*plVar2);

  FUN_1401bd730(param_1,*plVar3);

  FUN_1401bd730(param_1,*plVar2);

  FUN_1401bd7e0(param_1,*plVar2);

  FUN_14017cae0(*(undefined8 *)(lVar1 + 0x918));

  return;

}




