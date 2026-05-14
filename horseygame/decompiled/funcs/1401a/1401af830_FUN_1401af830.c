// Address: 0x1401af830
// Ghidra name: FUN_1401af830
// ============ 0x1401af830 FUN_1401af830 (size=307) ============


void FUN_1401af830(longlong param_1,undefined8 *param_2,undefined8 *param_3,ulonglong param_4,

                  undefined1 param_5)



{

  longlong lVar1;

  longlong *plVar2;

  undefined8 uVar3;

  longlong lVar4;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar5;

  ulonglong local_38;

  ulonglong local_30;

  ulonglong local_28;

  

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x110);

  plVar2 = (longlong *)*param_2;

  uVar3 = *param_3;

  FUN_14017caa0(*(undefined8 *)(lVar1 + 0x918));

  lVar4 = FUN_1401bbe40(lVar1,param_1,uVar3,param_5,CONCAT44(uVar5,1));

  FUN_1401b5050(lVar1,param_1,0,*plVar2);

  local_38 = (ulonglong)*(uint *)(param_2 + 1);

  local_30 = (ulonglong)*(uint *)(param_3 + 1);

  local_28 = param_4 & 0xffffffff;

  (**(code **)(lVar1 + 0xa60))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(*plVar2 + 0x10),

             *(undefined8 *)(lVar4 + 0x10),1,&local_38);

  FUN_1401b50b0(lVar1,param_1,0,*plVar2);

  FUN_1401b50b0(lVar1,param_1,1,lVar4);

  FUN_1401bd730(param_1,*plVar2);

  FUN_1401bd730(param_1,lVar4);

  FUN_1401bd7e0(param_1,*plVar2);

  FUN_1401bd7e0(param_1,lVar4);

  FUN_14017cae0(*(undefined8 *)(lVar1 + 0x918));

  return;

}




