// Address: 0x14027b860
// Ghidra name: thunk_FUN_1401597c0
// ============ 0x14027b860 thunk_FUN_1401597c0 (size=5) ============


undefined8 thunk_FUN_1401597c0(short param_1,short param_2)



{

  undefined8 uVar1;

  

  if (param_1 != 0x45e) {

    return 0x400;

  }

  uVar1 = 0x2e3;

  if (((param_2 != 0x2e3) && (uVar1 = 0xb00, param_2 != 0xb00)) && (uVar1 = 0xb05, param_2 != 0xb05)

     ) {

    return CONCAT71(0xb,param_2 == 0xb22);

  }

  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);

}




