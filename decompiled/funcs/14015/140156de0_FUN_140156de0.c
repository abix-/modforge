// Address: 0x140156de0
// Ghidra name: FUN_140156de0
// ============ 0x140156de0 FUN_140156de0 (size=147) ============


void FUN_140156de0(undefined8 param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar3 = *(float *)(param_2 + 0x90);

  fVar1 = *(float *)(param_2 + 0x94);

  fVar2 = (float)thunk_FUN_1402d0350((float)*(int *)(param_2 + 0x28) * fVar3);

  *(int *)(param_2 + 0x38) = (int)fVar2;

  fVar2 = (float)thunk_FUN_1402d0350((float)*(int *)(param_2 + 0x2c) * fVar1);

  *(int *)(param_2 + 0x3c) = (int)fVar2;

  fVar3 = (float)thunk_FUN_1402e33f0((float)*(int *)(param_2 + 0x30) * fVar3);

  *(int *)(param_2 + 0x40) = (int)fVar3;

  fVar3 = (float)thunk_FUN_1402e33f0((float)*(int *)(param_2 + 0x34) * fVar1);

  *(int *)(param_2 + 0x44) = (int)fVar3;

  return;

}




