// Address: 0x1401a5310
// Ghidra name: FUN_1401a5310
// ============ 0x1401a5310 FUN_1401a5310 (size=161) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401a5310(longlong param_1,int param_2,int param_3,int *param_4,undefined4 param_5)



{

  int iVar1;

  longlong lVar2;

  longlong local_1018;

  longlong local_1010;

  int local_ff8;

  undefined8 local_ff0;

  undefined8 uStack_10;

  

  uStack_10 = 0x1401a532a;

  lVar2 = thunk_FUN_1401841f0((longlong)param_3);

  if (lVar2 != 0) {

    local_1010 = param_2 + param_1;

    local_1018 = param_1;

    iVar1 = FUN_14019f030(&local_1018,lVar2,param_3,1,param_5);

    if (iVar1 != 0) {

      if (param_4 == (int *)0x0) {

        return local_ff0;

      }

      *param_4 = local_ff8 - (int)local_ff0;

      return local_ff0;

    }

    FUN_1401841e0(local_ff0);

  }

  return 0;

}




