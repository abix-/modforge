// Address: 0x1402da218
// Ghidra name: FUN_1402da218
// ============ 0x1402da218 FUN_1402da218 (size=59) ============


void FUN_1402da218(ulonglong param_1)



{

  byte bVar1;

  

  if (DAT_1403fed18 == DAT_1403e8b00) {

    bVar1 = 0x40 - ((byte)DAT_1403e8b00 & 0x3f) & 0x3f;

    DAT_1403fed18 = (param_1 >> bVar1 | param_1 << 0x40 - bVar1) ^ DAT_1403e8b00;

    return;

  }

                    /* WARNING: Subroutine does not return */

  FUN_1402cf8b8();

}




