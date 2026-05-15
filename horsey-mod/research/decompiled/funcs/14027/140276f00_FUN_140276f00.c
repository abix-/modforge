// Address: 0x140276f00
// Ghidra name: FUN_140276f00
// ============ 0x140276f00 FUN_140276f00 (size=170) ============


void FUN_140276f00(int *param_1,int *param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  

  iVar1 = *param_2;

  iVar2 = *param_1;

  fVar3 = (float)thunk_FUN_1402cfda0(param_3);

  fVar4 = (float)thunk_FUN_1402cdc50(param_3);

  *param_1 = (int)(fVar3 * (float)iVar2 - fVar4 * (float)iVar1);

  fVar3 = (float)thunk_FUN_1402cfda0(param_3);

  fVar4 = (float)thunk_FUN_1402cdc50(param_3);

  *param_2 = (int)(fVar4 * (float)iVar2 + fVar3 * (float)iVar1);

  return;

}




