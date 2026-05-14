// Address: 0x1402143d0
// Ghidra name: FUN_1402143d0
// ============ 0x1402143d0 FUN_1402143d0 (size=104) ============


void FUN_1402143d0(longlong param_1,longlong param_2,longlong *param_3)



{

  longlong lVar1;

  

  lVar1 = *param_3;

  if ((param_1 < 0x80000000) && ((-lVar1 < 1 || (param_1 << 0x20 <= lVar1 + 0x7fffffffffffffff)))) {

    lVar1 = (param_1 << 0x20) - lVar1;

    if (lVar1 < 1) {

      *param_3 = -lVar1;

      return;

    }

  }

  else {

    lVar1 = 0x7fffffffffffffff;

  }

  *param_3 = ((lVar1 + -1) / param_2 + 1) * param_2 - lVar1;

  return;

}




