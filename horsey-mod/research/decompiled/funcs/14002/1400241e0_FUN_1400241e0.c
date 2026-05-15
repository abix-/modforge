// Address: 0x1400241e0
// Ghidra name: FUN_1400241e0
// ============ 0x1400241e0 FUN_1400241e0 (size=25) ============


longlong FUN_1400241e0(longlong param_1,int *param_2,int param_3)



{

  uint7 uVar1;

  

  uVar1 = (uint7)((ulonglong)*(longlong *)(param_2 + 2) >> 8);

  if ((*(longlong *)(param_1 + 8) == *(longlong *)(*(longlong *)(param_2 + 2) + 8)) &&

     (*param_2 == param_3)) {

    return CONCAT71(uVar1,1);

  }

  return (ulonglong)uVar1 << 8;

}




