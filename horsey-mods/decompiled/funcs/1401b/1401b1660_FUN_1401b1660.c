// Address: 0x1401b1660
// Ghidra name: FUN_1401b1660
// ============ 0x1401b1660 FUN_1401b1660 (size=106) ============


void FUN_1401b1660(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  FUN_1401b3e30(lVar1,param_1);

                    /* WARNING: Could not recover jumptable at 0x0001401b16c7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(lVar1 + 0xa90))(*(undefined8 *)(param_1 + 0x118),param_2,param_3,param_4);

  return;

}




