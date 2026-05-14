// Address: 0x1401c72a0
// Ghidra name: FUN_1401c72a0
// ============ 0x1401c72a0 FUN_1401c72a0 (size=209) ============


ulonglong FUN_1401c72a0(int *param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  ulonglong in_RAX;

  int iVar3;

  int iVar4;

  

  if (param_2 == (undefined4 *)0x0) {

LAB_1401c735f:

    return in_RAX & 0xffffffffffffff00;

  }

  *param_2 = *(undefined4 *)(&DAT_1403e4958 + (longlong)*param_1 * 4);

  in_RAX = (ulonglong)*(uint *)(&DAT_1403e4948 + (longlong)param_1[1] * 4);

  iVar3 = param_1[2];

  param_2[1] = *(uint *)(&DAT_1403e4948 + (longlong)param_1[1] * 4);

  uVar2 = 0;

  if (iVar3 == 0) {

    uVar1 = 1;

  }

  else {

    uVar1 = uVar2;

    if (iVar3 != 1) goto LAB_1401c735f;

  }

  param_2[2] = uVar1;

  if ((char)param_1[6] == '\0') {

    iVar3 = 0;

    iVar4 = 0;

  }

  else {

    iVar3 = param_1[5];

    iVar4 = param_1[4];

    uVar2 = thunk_FUN_1402e1e60(param_1[3]);

  }

  param_2[3] = uVar2;

  param_2[4] = iVar4;

  param_2[5] = iVar3;

  param_2[6] = (uint)*(byte *)((longlong)param_1 + 0x19);

  *(undefined8 *)(param_2 + 7) = 0;

  *(undefined8 *)(param_2 + 9) = 0;

  return 1;

}




