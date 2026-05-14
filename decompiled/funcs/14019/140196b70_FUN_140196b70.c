// Address: 0x140196b70
// Ghidra name: FUN_140196b70
// ============ 0x140196b70 FUN_140196b70 (size=130) ============


void FUN_140196b70(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  

  FUN_1401841e0(*param_1);

  *param_1 = 0;

  if (param_2 != 0) {

    lVar1 = FUN_14012fd40(param_2);

    lVar1 = FUN_140197820(&DAT_14039c6f0,"WCHAR_T",param_2,lVar1 * 2 + 2);

    if (lVar1 != 0) {

      FUN_14012e850(&DAT_14039bf30,lVar1);

      FUN_1401841e0(lVar1);

      return;

    }

  }

  FUN_14012e710();

  return;

}




