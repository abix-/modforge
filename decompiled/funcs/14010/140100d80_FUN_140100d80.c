// Address: 0x140100d80
// Ghidra name: FUN_140100d80
// ============ 0x140100d80 FUN_140100d80 (size=163) ============


void FUN_140100d80(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  float fVar1;

  float fVar2;

  undefined4 local_res8;

  undefined4 uStackX_c;

  

  local_res8 = (float)param_3;

  uStackX_c = (float)((ulonglong)param_3 >> 0x20);

  uStackX_c = uStackX_c * DAT_14030338c;

  fVar1 = (float)FUN_1400c5f70(local_res8 * DAT_14030338c,DAT_14030407c,DAT_1403033b4);

  fVar2 = (float)FUN_1400c5f70(uStackX_c,DAT_14030b66c,DAT_14030401c);

  FUN_140100e30(param_1,param_2,

                CONCAT44(fVar2 + *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c),

                         fVar1 + *(float *)(*(longlong *)(param_1 + 0x300) + 0x28)));

  return;

}




