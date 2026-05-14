// Address: 0x1402646f0
// Ghidra name: FUN_1402646f0
// ============ 0x1402646f0 FUN_1402646f0 (size=42) ============


void FUN_1402646f0(longlong param_1,int param_2)



{

  longlong lVar1;

  

  lVar1 = (longlong)(param_2 * 6);

  *(undefined4 *)(lVar1 + 0x18 + param_1) = 0x28282828;

  *(undefined4 *)(lVar1 + 0x30 + param_1) = 0xd8d8d8d8;

  *(undefined2 *)(lVar1 + 0x34 + param_1) = 0xd8d8;

  *(undefined2 *)(lVar1 + 0x1c + param_1) = 0x2828;

  return;

}




