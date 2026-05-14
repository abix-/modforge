// Address: 0x1400734d0
// Ghidra name: FUN_1400734d0
// ============ 0x1400734d0 FUN_1400734d0 (size=48) ============


void FUN_1400734d0(longlong param_1,uint param_2)



{

  ulonglong uVar1;

  

  if (0 < (int)param_2) {

    uVar1 = (ulonglong)param_2;

    do {

      FUN_1400745d0(param_1);

      param_1 = param_1 + 0x20;

      uVar1 = uVar1 - 1;

    } while (uVar1 != 0);

  }

  return;

}




