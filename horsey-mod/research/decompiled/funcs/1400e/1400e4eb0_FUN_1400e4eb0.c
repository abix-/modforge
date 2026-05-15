// Address: 0x1400e4eb0
// Ghidra name: FUN_1400e4eb0
// ============ 0x1400e4eb0 FUN_1400e4eb0 (size=103) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int FUN_1400e4eb0(longlong param_1,int param_2,longlong param_3,int param_4)



{

  int iVar1;

  longlong local_1008;

  longlong local_1000;

  longlong local_ff0;

  longlong local_fe8;

  longlong local_fe0;

  undefined4 local_fd8;

  undefined8 uStack_8;

  

  uStack_8 = 0x1400e4eba;

  local_1000 = param_4 + param_3;

  local_fe0 = param_2 + param_1;

  local_fd8 = 0;

  local_1008 = param_3;

  local_ff0 = param_1;

  local_fe8 = param_1;

  iVar1 = FUN_1400ebcd0(&local_1008,0);

  if (iVar1 != 0) {

    return (int)local_ff0 - (int)local_fe8;

  }

  return -1;

}




