// Address: 0x140196470
// Ghidra name: FUN_140196470
// ============ 0x140196470 FUN_140196470 (size=46) ============


void FUN_140196470(short *param_1)



{

  short sVar1;

  

  sVar1 = *param_1;

  while (sVar1 != 0) {

    sVar1 = FUN_140190620(sVar1);

    *param_1 = sVar1;

    param_1 = param_1 + 1;

    sVar1 = *param_1;

  }

  return;

}




