// Address: 0x1400cf7f0
// Ghidra name: FUN_1400cf7f0
// ============ 0x1400cf7f0 FUN_1400cf7f0 (size=339) ============


void FUN_1400cf7f0(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 *puVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0x168);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x168) = 0xffffffff;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x168) = iVar1 + -1;

  }

  iVar1 = *(int *)(param_1 + 0x15c);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;

    *(undefined1 *)(param_1 + 0x160) = 0;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x15c) = iVar1 + -1;

  }

  iVar1 = *(int *)(param_1 + 0x170);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x170) = 0xffffffff;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x170) = iVar1 + -1;

  }

  iVar1 = *(int *)(param_1 + 0x16c);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x16c) = iVar1 + -1;

  }

  iVar1 = *(int *)(param_1 + 0x230);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x230) = 0xffffffff;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x230) = iVar1 + -1;

  }

  iVar1 = *(int *)(param_1 + 0x18c);

  if (iVar1 == param_2) {

    *(undefined4 *)(param_1 + 0x18c) = 0xffffffff;

  }

  else if (param_2 < iVar1) {

    *(int *)(param_1 + 0x18c) = iVar1 + -1;

  }

  lVar2 = *(longlong *)(param_1 + 0x130);

  lVar4 = (longlong)param_2 * 8;

  if (*(longlong *)(param_1 + 0x148) == *(longlong *)(lVar2 + (longlong)param_2 * 8)) {

    *(undefined8 *)(param_1 + 0x148) = 0;

  }

  if (*(longlong *)(param_1 + 0x208) == *(longlong *)(lVar2 + lVar4)) {

    *(undefined8 *)(param_1 + 0x208) = 0;

  }

  puVar3 = *(undefined8 **)(lVar2 + lVar4);

  if (puVar3 != (undefined8 *)0x0) {

    (**(code **)*puVar3)(puVar3,1);

  }

  lVar4 = *(longlong *)(param_1 + 0x130) + lVar4;

  lVar2 = lVar4 + 8;

  FUN_1402f8e20(lVar4,lVar2,*(longlong *)(param_1 + 0x138) - lVar2);

  *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + -8;

  return;

}




