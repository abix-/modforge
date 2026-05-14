// Address: 0x14020bde0
// Ghidra name: FUN_14020bde0
// ============ 0x14020bde0 FUN_14020bde0 (size=119) ============


void FUN_14020bde0(longlong param_1,undefined2 param_2,undefined2 param_3)



{

  longlong lVar1;

  char *pcVar2;

  

  _guard_check_icall();

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (lVar1 == 0) {

    pcVar2 = "Rumble failed, device disconnected";

  }

  else {

    if (*(code **)(lVar1 + 0x88) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014020be30. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(lVar1 + 0x88))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3);

      return;

    }

    pcVar2 = "That operation is not supported";

  }

  FUN_14012e850(pcVar2);

  return;

}




