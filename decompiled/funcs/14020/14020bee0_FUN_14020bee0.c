// Address: 0x14020bee0
// Ghidra name: FUN_14020bee0
// ============ 0x14020bee0 FUN_14020bee0 (size=117) ============


void FUN_14020bee0(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  longlong lVar1;

  char *pcVar2;

  

  _guard_check_icall();

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (lVar1 == 0) {

    pcVar2 = "SendEffect failed, device disconnected";

  }

  else {

    if (*(code **)(lVar1 + 0x98) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014020bf2e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(lVar1 + 0x98))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3);

      return;

    }

    pcVar2 = "That operation is not supported";

  }

  FUN_14012e850(pcVar2);

  return;

}




