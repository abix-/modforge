// Address: 0x1401bd180
// Ghidra name: FUN_1401bd180
// ============ 0x1401bd180 FUN_1401bd180 (size=71) ============


void FUN_1401bd180(longlong param_1,undefined4 *param_2)



{

  *(undefined4 *)(param_1 + 0x218) = *param_2;

  *(undefined4 *)(param_1 + 0x21c) = param_2[1];

  *(undefined4 *)(param_1 + 0x220) = param_2[2];

  *(undefined4 *)(param_1 + 0x224) = param_2[3];

                    /* WARNING: Could not recover jumptable at 0x0001401bd1c4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*(longlong *)(param_1 + 0x110) + 0xad8))(*(undefined8 *)(param_1 + 0x118),0,1);

  return;

}




