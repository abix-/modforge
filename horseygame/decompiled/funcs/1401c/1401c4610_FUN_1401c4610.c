// Address: 0x1401c4610
// Ghidra name: FUN_1401c4610
// ============ 0x1401c4610 FUN_1401c4610 (size=173) ============


void FUN_1401c4610(longlong param_1,longlong *param_2,longlong *param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_3;

  lVar2 = *(longlong *)(*param_2 + 0x10);

  FUN_1401c68f0(param_1,0x800,lVar2);

  lVar1 = *(longlong *)(lVar1 + 0x10);

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x78))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(lVar1 + 0x10),(int)param_3[1],

             *(undefined8 *)(lVar2 + 0x10),(int)param_2[1],*(undefined4 *)((longlong)param_2 + 0xc))

  ;

  FUN_1401c6930(param_1,0x800,lVar2);

  FUN_1401cb5f0(param_1,lVar2);

  FUN_1401cb5f0(param_1,lVar1);

  return;

}




