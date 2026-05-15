// Address: 0x1401694f0
// Ghidra name: FUN_1401694f0
// ============ 0x1401694f0 FUN_1401694f0 (size=172) ============


void FUN_1401694f0(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dcf0();

  if (lVar2 == 0) {

    FUN_1401730c0();

    return;

  }

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","mime_type");

    return;

  }

  if (*(code **)(lVar2 + 0x2b8) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140169557. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar2 + 0x2b8))(lVar2,param_1);

    return;

  }

  if (*(longlong *)(lVar2 + 0x2d0) != 0) {

    cVar1 = FUN_1401696e0(param_1);

    if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x000140169584. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(lVar2 + 0x2d0))(lVar2);

      return;

    }

  }

  FUN_140169620(lVar2,param_1);

  return;

}




