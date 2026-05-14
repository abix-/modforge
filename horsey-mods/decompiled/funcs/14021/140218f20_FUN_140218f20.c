// Address: 0x140218f20
// Ghidra name: FUN_140218f20
// ============ 0x140218f20 FUN_140218f20 (size=32) ============


void FUN_140218f20(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x690);

  if ((lVar1 != 0) && (param_2 != 0)) {

                    /* WARNING: Could not recover jumptable at 0x000140218f3c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x88))(*(undefined8 *)(lVar1 + 0x10));

    return;

  }

  return;

}




