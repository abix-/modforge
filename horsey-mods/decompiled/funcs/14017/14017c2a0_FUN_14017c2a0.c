// Address: 0x14017c2a0
// Ghidra name: FUN_14017c2a0
// ============ 0x14017c2a0 FUN_14017c2a0 (size=102) ============


ulonglong FUN_14017c2a0(int *param_1,longlong param_2,int param_3,int param_4)



{

  int *piVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  ulonglong in_RAX;

  

  if (param_1 == (int *)0x0) {

    return in_RAX & 0xffffffffffffff00;

  }

  iVar4 = *param_1 - param_3;

  iVar3 = param_4;

  if (iVar4 < param_4) {

    iVar3 = iVar4;

  }

  lVar2 = *(longlong *)(param_1 + 2) + (longlong)param_3 * 4;

  if (param_2 != lVar2) {

    FUN_1402f8e20(lVar2,param_2,(longlong)iVar3 << 2);

  }

  piVar1 = param_1 + 4;

  *piVar1 = *piVar1 + 1;

  if (*piVar1 == 0) {

    param_1[4] = 1;

  }

  return (ulonglong)(param_4 <= iVar4);

}




