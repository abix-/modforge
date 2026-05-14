// Address: 0x1400472e0
// Ghidra name: FUN_1400472e0
// ============ 0x1400472e0 FUN_1400472e0 (size=51) ============


void FUN_1400472e0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = param_1[1];

  for (lVar2 = *param_1; lVar2 != lVar1; lVar2 = lVar2 + 0x40) {

    FUN_140027900(lVar2 + 8);

  }

  return;

}




