// Address: 0x140206cd0
// Ghidra name: FUN_140206cd0
// ============ 0x140206cd0 FUN_140206cd0 (size=124) ============


void FUN_140206cd0(undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)



{

  char cVar1;

  longlong local_18 [2];

  

  local_18[0] = 0;

  cVar1 = FUN_140207e40(param_1,local_18);

  if (cVar1 == '\0') {

    FUN_14012e850("SetLED failed, device disconnected");

  }

  else {

    (**(code **)(*(longlong *)(local_18[0] + 0x68) + 0x70))

              (local_18[0],param_1,param_2,param_3,param_4);

  }

  return;

}




