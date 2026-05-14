// Address: 0x14020be60
// Ghidra name: FUN_14020be60
// ============ 0x14020be60 FUN_14020be60 (size=125) ============


void FUN_14020be60(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)



{

  longlong lVar1;

  char *pcVar2;

  

  _guard_check_icall();

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (lVar1 == 0) {

    pcVar2 = "SetLED failed, device disconnected";

  }

  else {

    if (*(code **)(lVar1 + 0x90) != (code *)0x0) {

      (**(code **)(lVar1 + 0x90))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3,param_4);

      return;

    }

    pcVar2 = "That operation is not supported";

  }

  FUN_14012e850(pcVar2);

  return;

}




