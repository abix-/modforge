// Address: 0x1401bba40
// Ghidra name: FUN_1401bba40
// ============ 0x1401bba40 FUN_1401bba40 (size=189) ============


longlong *

FUN_1401bba40(longlong param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5,

             longlong param_6,longlong param_7)



{

  uint uVar1;

  undefined8 uVar2;

  longlong *plVar3;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  if (*(int *)(param_2 + 0x20) == *(int *)(param_2 + 0x24)) {

    uVar1 = *(int *)(param_2 + 0x24) * 2;

    *(uint *)(param_2 + 0x24) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_2 + 0x18),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_2 + 0x18) = uVar2;

  }

  plVar3 = (longlong *)FUN_1401841f0(0x40);

  plVar3[3] = param_5;

  plVar3[4] = param_6;

  plVar3[5] = param_7;

  *plVar3 = param_2;

  plVar3[1] = param_3;

  plVar3[2] = param_4;

  *(longlong *)(param_2 + 0x48) = *(longlong *)(param_2 + 0x48) + param_4;

  *(longlong **)(*(longlong *)(param_2 + 0x18) + (ulonglong)*(uint *)(param_2 + 0x20) * 8) = plVar3;

  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return plVar3;

}




