// Address: 0x140230460
// Ghidra name: FUN_140230460
// ============ 0x140230460 FUN_140230460 (size=132) ============


char FUN_140230460(void)



{

  char cVar1;

  int iVar2;

  int local_18 [4];

  

  if (DAT_1403fdd40 != 0) {

    return '\x01';

  }

  DAT_1403fdd40 = FUN_1401885b0(PTR_s_KernelBase_dll_1403e5530);

  if (DAT_1403fdd40 == 0) {

    return '\0';

  }

  cVar1 = FUN_1402304f0();

  if ((cVar1 != '\0') && (iVar2 = (*DAT_1403fdd50)(local_18), -1 < iVar2)) {

    if (local_18[0] < 300) {

      FUN_140230bb0();

      return '\0';

    }

    return cVar1;

  }

  FUN_140230bb0();

  return '\0';

}




