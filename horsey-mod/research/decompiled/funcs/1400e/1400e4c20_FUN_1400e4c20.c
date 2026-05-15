// Address: 0x1400e4c20
// Ghidra name: FUN_1400e4c20
// ============ 0x1400e4c20 FUN_1400e4c20 (size=171) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



longlong FUN_1400e4c20(longlong param_1,int param_2,int param_3,int *param_4)



{

  int iVar1;

  longlong local_1008;

  longlong local_1000;

  longlong local_ff0;

  longlong local_fe8;

  longlong local_fe0;

  undefined4 local_fd8;

  undefined8 uStack_10;

  

  uStack_10 = 0x1400e4c3a;

  local_ff0 = _malloc_base((longlong)param_3);

  if (local_ff0 != 0) {

    local_1000 = param_2 + param_1;

    local_fe0 = local_ff0 + param_3;

    local_fd8 = 1;

    local_1008 = param_1;

    local_fe8 = local_ff0;

    iVar1 = FUN_1400ebcd0(&local_1008,1);

    if (iVar1 != 0) {

      if (param_4 == (int *)0x0) {

        return local_fe8;

      }

      *param_4 = (int)local_ff0 - (int)local_fe8;

      return local_fe8;

    }

    thunk_FUN_1402e9a80(local_fe8);

  }

  return 0;

}




