// Address: 0x1402278c0
// Ghidra name: FUN_1402278c0
// ============ 0x1402278c0 FUN_1402278c0 (size=126) ============


bool FUN_1402278c0(undefined8 param_1,undefined8 param_2)



{

  char cVar1;

  longlong lVar2;

  int7 extraout_var;

  

  lVar2 = FUN_14012cba0();

  if (-1 < lVar2) {

    FUN_14012cb40(param_1,param_2,0);

    if (-1 < extraout_var) {

      cVar1 = FUN_14012cd80(param_1,((int)lVar2 - (int)param_2) + -4);

      if (cVar1 != '\0') {

        lVar2 = FUN_14012cb40(param_1,lVar2,0);

        return lVar2 != 0;

      }

    }

  }

  return false;

}




