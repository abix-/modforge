// Address: 0x14017e320
// Ghidra name: FUN_14017e320
// ============ 0x14017e320 FUN_14017e320 (size=22) ============


void FUN_14017e320(uint param_1)



{

  int iVar1;

  

  iVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {

    }

  }

  if ((param_1 != 0) && (-1 < iVar1)) {

    (&DAT_1403fc648)[iVar1] = (&DAT_1403fc648)[iVar1] + '\x01';

  }

  return;

}




