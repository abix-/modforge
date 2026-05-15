// Address: 0x1400cb9e0
// Ghidra name: FUN_1400cb9e0
// ============ 0x1400cb9e0 FUN_1400cb9e0 (size=115) ============


void FUN_1400cb9e0(longlong param_1,undefined4 param_2,undefined8 param_3,char param_4)



{

  int iVar1;

  

  *(undefined4 *)(param_1 + 0x1a0) = param_2;

  *(undefined8 *)(param_1 + 0x1a4) = param_3;

  if (param_4 != '\0') {

    iVar1 = FUN_140072ca0(param_2);

    *(float *)(param_1 + 0x1a4) = *(float *)(param_1 + 0x1a4) - (float)(iVar1 / 2);

    iVar1 = FUN_140072cc0(*(undefined4 *)(param_1 + 0x1a0));

    *(float *)(param_1 + 0x1a8) = *(float *)(param_1 + 0x1a8) - (float)(iVar1 / 2);

  }

  return;

}




