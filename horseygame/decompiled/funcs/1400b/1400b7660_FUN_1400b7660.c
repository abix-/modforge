// Address: 0x1400b7660
// Ghidra name: FUN_1400b7660
// ============ 0x1400b7660 FUN_1400b7660 (size=57) ============


longlong FUN_1400b7660(longlong param_1,char param_2,char param_3)



{

  int iVar1;

  uint7 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x1fc);

  uVar2 = (uint7)(uint3)((uint)iVar1 >> 8);

  if ((((0 < iVar1) || (param_3 != '\0')) && (iVar1 < *(int *)(param_1 + 0x200))) &&

     (((*(char *)(param_1 + 0x205) == '\0' && (*(char *)(param_1 + 0x206) == '\0')) &&

      ((param_2 != '\0' || (*(int *)(param_1 + 0x1c) < 4)))))) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




