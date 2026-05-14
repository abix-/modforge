// Address: 0x1401bd200
// Ghidra name: FUN_1401bd200
// ============ 0x1401bd200 FUN_1401bd200 (size=109) ============


void FUN_1401bd200(longlong param_1,undefined4 *param_2)



{

  *(undefined4 *)(param_1 + 0x200) = *param_2;

  *(undefined4 *)(param_1 + 0x208) = param_2[2];

  *(undefined4 *)(param_1 + 0x210) = param_2[4];

  *(undefined4 *)(param_1 + 0x214) = param_2[5];

  *(float *)(param_1 + 0x204) = (float)param_2[1] + (float)param_2[3];

  *(uint *)(param_1 + 0x20c) = param_2[3] ^ DAT_14039cac0;

                    /* WARNING: Could not recover jumptable at 0x0001401bd26a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*(longlong *)(param_1 + 0x110) + 0xae8))(*(undefined8 *)(param_1 + 0x118),0,1);

  return;

}




