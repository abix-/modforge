// Address: 0x1401635c0
// Ghidra name: FUN_1401635c0
// ============ 0x1401635c0 FUN_1401635c0 (size=48) ============


void FUN_1401635c0(longlong param_1)



{

  if (*(longlong *)(param_1 + 8) != 0) {

    (**(code **)(param_1 + 0x20))();

  }

                    /* WARNING: Could not recover jumptable at 0x0001401635ed. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x20))(param_1);

  return;

}




