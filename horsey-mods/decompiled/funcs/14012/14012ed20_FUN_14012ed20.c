// Address: 0x14012ed20
// Ghidra name: FUN_14012ed20
// ============ 0x14012ed20 FUN_14012ed20 (size=79) ============


void FUN_14012ed20(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  

  if (param_2 == (longlong *)0x0) {

    FUN_1401300a0(param_1,4);

    return;

  }

  lVar1 = *param_1;

  FUN_1401300a0(param_1,*param_2);

  *param_2 = *param_2 + (lVar1 - *param_1);

  return;

}




