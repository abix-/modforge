// Address: 0x1401bd130
// Ghidra name: FUN_1401bd130
// ============ 0x1401bd130 FUN_1401bd130 (size=66) ============


void FUN_1401bd130(longlong param_1,undefined4 *param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  

  *(undefined4 *)(param_1 + 0x228) = *param_2;

  *(undefined4 *)(param_1 + 0x22c) = param_2[1];

  *(undefined4 *)(param_1 + 0x230) = param_2[2];

  *(undefined4 *)(param_1 + 0x234) = param_2[3];

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x110) + 0xac8);

                    /* WARNING: Could not recover jumptable at 0x0001401bd16f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(undefined8 *)(param_1 + 0x118),param_1 + 0x228,UNRECOVERED_JUMPTABLE);

  return;

}




