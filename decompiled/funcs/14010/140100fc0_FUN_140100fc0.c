// Address: 0x140100fc0
// Ghidra name: FUN_140100fc0
// ============ 0x140100fc0 FUN_140100fc0 (size=207) ============


void FUN_140100fc0(longlong param_1,longlong param_2,float param_3,float param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  float fVar3;

  longlong local_res8;

  

  uVar2 = DAT_14030400c;

  param_4 = param_4 * DAT_14030338c;

  fVar3 = param_3 * DAT_14030338c + *(float *)(*(longlong *)(param_1 + 0x300) + 0x28);

  *(float *)(param_2 + 0x28) = fVar3;

  *(float *)(param_2 + 0x2c) = param_4 + *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c);

  uVar1 = FUN_1400c5f70(fVar3,uVar2,

                        ((float)*(int *)(param_1 + 0x278) - DAT_140303380) * DAT_1403033ac);

  uVar2 = DAT_14030400c;

  *(undefined4 *)(param_2 + 0x28) = uVar1;

  uVar2 = FUN_1400c5f70(*(undefined4 *)(param_2 + 0x2c),uVar2,

                        ((float)*(int *)(param_1 + 0x27c) - DAT_140303380) * DAT_1403033ac);

  *(undefined4 *)(param_2 + 0x2c) = uVar2;

  *(undefined4 *)(param_2 + 0x18) = 0;

  local_res8 = param_2;

  FUN_14003e600(param_1 + 0xb8,&local_res8);

  return;

}




