// Address: 0x1401e7e30
// Ghidra name: FUN_1401e7e30
// ============ 0x1401e7e30 FUN_1401e7e30 (size=50) ============


void FUN_1401e7e30(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  *(undefined8 *)(lVar1 + (param_2 + 0x227) * 0x10) = *(undefined8 *)(lVar1 + 0x2260);

  *(longlong *)(lVar1 + 0x2260) = lVar1 + 0x2268 + param_2 * 0x10;

  return;

}




