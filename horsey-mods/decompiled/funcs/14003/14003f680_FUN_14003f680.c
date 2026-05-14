// Address: 0x14003f680
// Ghidra name: FUN_14003f680
// ============ 0x14003f680 FUN_14003f680 (size=93) ============


void FUN_14003f680(void)



{

  longlong lVar1;

  

  if ((DAT_1403ea292 == '\0') && (DAT_1403ea293 != '\0')) {

    if ((DAT_1403ea290 == '\0') || (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0x58), lVar1 == 0)) {

      DAT_1403ea298 = 0.0;

    }

    else {

      DAT_1403ea298 = *(double *)(lVar1 + 0x20) / (double)**(int **)(lVar1 + 0x28);

    }

    DAT_1403ea290 = 0;

    FUN_1400450b0();

    return;

  }

  return;

}




