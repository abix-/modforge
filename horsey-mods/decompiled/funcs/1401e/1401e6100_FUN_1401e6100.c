// Address: 0x1401e6100
// Ghidra name: FUN_1401e6100
// ============ 0x1401e6100 FUN_1401e6100 (size=247) ============


void FUN_1401e6100(undefined8 param_1,undefined4 param_2,undefined8 *param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  

  uVar1 = FUN_14014df00(param_2);

  uVar2 = FUN_14014dee0(param_2);

  uVar3 = FUN_14014de80(param_2);

  uVar4 = FUN_14014dec0(param_2);

  uVar5 = FUN_14014dea0(param_2);

  uVar6 = FUN_14014de60(param_2);

  *(undefined4 *)((longlong)param_3 + 0xc) = 0;

  *(undefined4 *)(param_3 + 5) = 0;

  FUN_1402f94c0((longlong)param_3 + 0x2d,0,0x11b);

  *(undefined4 *)(param_3 + 1) = 1;

  *param_3 = 0;

  uVar1 = FUN_1401e0080(uVar1);

  *(undefined4 *)(param_3 + 2) = uVar1;

  uVar1 = FUN_1401e0080(uVar4);

  *(undefined4 *)((longlong)param_3 + 0x14) = uVar1;

  uVar1 = FUN_1401e0040(uVar3);

  *(undefined4 *)(param_3 + 3) = uVar1;

  uVar1 = FUN_1401e0080(uVar2);

  *(undefined4 *)((longlong)param_3 + 0x1c) = uVar1;

  uVar1 = FUN_1401e0080(uVar5);

  *(undefined4 *)(param_3 + 4) = uVar1;

  uVar1 = FUN_1401e0040(uVar6);

  *(undefined4 *)((longlong)param_3 + 0x24) = uVar1;

  *(undefined1 *)((longlong)param_3 + 0x2c) = 0xf;

  return;

}




