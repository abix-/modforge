// Address: 0x14020bf60
// Ghidra name: FUN_14020bf60
// ============ 0x14020bf60 FUN_14020bf60 (size=112) ============


undefined8 FUN_14020bf60(longlong param_1,undefined1 param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  _guard_check_icall();

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (lVar1 == 0) {

    uVar2 = FUN_14012e850("SetSensorsEnabled failed, device disconnected");

    return uVar2;

  }

  if (*(code **)(lVar1 + 0xa0) == (code *)0x0) {

    uVar2 = 1;

  }

  else {

    uVar2 = (**(code **)(lVar1 + 0xa0))(*(undefined8 *)(lVar1 + 0x68),param_2);

    if ((char)uVar2 == '\0') {

      return uVar2;

    }

  }

  *(undefined1 *)(lVar1 + 0xe8) = param_2;

  return uVar2;

}




