// Address: 0x1402072d0
// Ghidra name: FUN_1402072d0
// ============ 0x1402072d0 FUN_1402072d0 (size=97) ============


undefined8 FUN_1402072d0(longlong param_1,undefined4 param_2)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x90),(longlong)*(int *)(param_1 + 0x8c) * 4 + 4);

  if (lVar2 == 0) {

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0x8c);

  *(longlong *)(param_1 + 0x90) = lVar2;

  *(undefined4 *)(lVar2 + (longlong)iVar1 * 4) = param_2;

  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;

  return CONCAT71((int7)(int3)((uint)iVar1 >> 8),1);

}




