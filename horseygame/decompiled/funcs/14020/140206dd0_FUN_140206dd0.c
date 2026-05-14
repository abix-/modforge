// Address: 0x140206dd0
// Ghidra name: FUN_140206dd0
// ============ 0x140206dd0 FUN_140206dd0 (size=97) ============


void FUN_140206dd0(undefined8 param_1,undefined1 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  char cVar1;

  longlong local_res18 [2];

  

  local_res18[0] = 0;

  cVar1 = FUN_140207e40(param_1,local_res18);

  if (cVar1 != '\0') {

    UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(local_res18[0] + 0x68) + 0x80);

                    /* WARNING: Could not recover jumptable at 0x000140206e18. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*UNRECOVERED_JUMPTABLE)(local_res18[0],param_1,param_2,UNRECOVERED_JUMPTABLE);

    return;

  }

  FUN_14012e850("SetSensorsEnabled failed, device disconnected");

  return;

}




