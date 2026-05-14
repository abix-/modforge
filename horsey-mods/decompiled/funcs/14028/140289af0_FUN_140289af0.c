// Address: 0x140289af0
// Ghidra name: FUN_140289af0
// ============ 0x140289af0 FUN_140289af0 (size=104) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140289af0(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4)



{

  FUN_1402895a0(0,param_1);

  FUN_1402895a0(1,param_2,param_3,param_4);

  _DAT_1403e79ac = param_3;

  DAT_1403e79b0 = param_4;

                    /* WARNING: Could not recover jumptable at 0x000140289b55. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*DAT_1403fde80 + 0x30))

            (DAT_1403fde80,&PTR_PTR_1403e79a0,*(code **)(*DAT_1403fde80 + 0x30));

  return;

}




