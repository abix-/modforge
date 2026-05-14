// Address: 0x1401bac70
// Ghidra name: FUN_1401bac70
// ============ 0x1401bac70 FUN_1401bac70 (size=45) ============


longlong FUN_1401bac70(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  uint uVar1;

  

  uVar1 = FUN_1401bb2e0(param_3,param_2,*(undefined4 *)(param_1 + 0x18));

  return *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48) + (ulonglong)uVar1 * 0x28;

}




