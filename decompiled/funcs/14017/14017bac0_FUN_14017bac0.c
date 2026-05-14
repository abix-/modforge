// Address: 0x14017bac0
// Ghidra name: FUN_14017bac0
// ============ 0x14017bac0 FUN_14017bac0 (size=60) ============


longlong FUN_14017bac0(int *param_1,int *param_2)



{

  int iVar1;

  uint7 uVar2;

  undefined4 extraout_var;

  

  iVar1 = *param_1;

  uVar2 = (uint7)(int3)((uint)iVar1 >> 8);

  if (*param_2 < iVar1) {

    return (ulonglong)uVar2 << 8;

  }

  if (param_1 != param_2) {

    iVar1 = memcmp(*(void **)(param_1 + 2),*(void **)(param_2 + 2),(longlong)iVar1 << 2);

    return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);

  }

  return CONCAT71(uVar2,1);

}




