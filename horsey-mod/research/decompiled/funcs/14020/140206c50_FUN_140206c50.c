// Address: 0x140206c50
// Ghidra name: FUN_140206c50
// ============ 0x140206c50 FUN_140206c50 (size=117) ============


void FUN_140206c50(undefined8 param_1,undefined2 param_2,undefined2 param_3)



{

  char cVar1;

  longlong local_res20;

  

  local_res20 = 0;

  cVar1 = FUN_140207e40(param_1,&local_res20);

  if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x000140206ca7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(longlong *)(local_res20 + 0x68) + 0x60))(local_res20,param_1,param_2,param_3);

    return;

  }

  FUN_14012e850("Rumble failed, device disconnected");

  return;

}




