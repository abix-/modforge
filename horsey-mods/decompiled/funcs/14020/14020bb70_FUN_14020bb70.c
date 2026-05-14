// Address: 0x14020bb70
// Ghidra name: FUN_14020bb70
// ============ 0x14020bb70 FUN_14020bb70 (size=47) ============


void FUN_14020bb70(undefined8 param_1,undefined4 param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_14020d2c0();

  if ((lVar1 != 0) && (*(code **)(lVar1 + 0x78) != (code *)0x0)) {

                    /* WARNING: Could not recover jumptable at 0x00014020bb96. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x78))(*(undefined8 *)(lVar1 + 0x68),param_2);

    return;

  }

  return;

}




