// Address: 0x1401861d0
// Ghidra name: FUN_1401861d0
// ============ 0x1401861d0 FUN_1401861d0 (size=45) ============


undefined8 FUN_1401861d0(longlong param_1)



{

  int iVar1;

  

  iVar1 = FUN_140186200();

  if ((-1 < iVar1) && (iVar1 < *(int *)(param_1 + 0xc))) {

    return *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (longlong)iVar1 * 8);

  }

  return 0;

}




