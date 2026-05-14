// Address: 0x1401c3960
// Ghidra name: FUN_1401c3960
// ============ 0x1401c3960 FUN_1401c3960 (size=202) ============


void FUN_1401c3960(longlong param_1,longlong *param_2,undefined8 *param_3,undefined4 param_4,

                  undefined1 param_5)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(*param_2 + 0x10);

  lVar2 = FUN_1401ca8a0(param_1,*param_3,param_5,0x400);

  FUN_1401c68f0(param_1,0x800,lVar1);

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x78))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(lVar2 + 0x10),

             *(undefined4 *)(param_3 + 1),*(undefined8 *)(lVar1 + 0x10),(int)param_2[1],param_4);

  FUN_1401c6930(param_1,0x800,lVar1);

  FUN_1401c6930(param_1,0x400,lVar2);

  FUN_1401cb5f0(param_1,lVar1);

  FUN_1401cb5f0(param_1,lVar2);

  return;

}




