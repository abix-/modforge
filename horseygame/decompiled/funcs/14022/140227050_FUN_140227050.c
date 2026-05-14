// Address: 0x140227050
// Ghidra name: FUN_140227050
// ============ 0x140227050 FUN_140227050 (size=16) ============


void FUN_140227050(longlong *param_1)



{

  if (param_1 != (longlong *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014022705c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x10))(param_1,*(code **)(*param_1 + 0x10));

    return;

  }

  return;

}




