// Address: 0x14000c840
// Ghidra name: FUN_14000c840
// ============ 0x14000c840 FUN_14000c840 (size=91) ============


void FUN_14000c840(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  fVar1 = param_3 * DAT_14039ca50 * *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc);

  *param_2 = fVar1;

  *(undefined8 *)(param_2 + 1) = *(undefined8 *)(param_1 + 0x10);

  param_2[3] = (*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +

                *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10) +

               *(float *)(param_1 + 0xc) * DAT_14039ca34 * *(float *)(param_1 + 0xc)) * fVar1;

  return;

}




