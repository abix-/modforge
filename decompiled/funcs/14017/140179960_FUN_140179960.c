// Address: 0x140179960
// Ghidra name: FUN_140179960
// ============ 0x140179960 FUN_140179960 (size=54) ============


void FUN_140179960(longlong param_1)



{

  int *piVar1;

  DWORD DVar2;

  

  DVar2 = GetCurrentThreadId();

  if (*(DWORD *)(param_1 + 0xc) == DVar2) {

    piVar1 = (int *)(param_1 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      *(undefined4 *)(param_1 + 0xc) = 0;

                    /* WARNING: Could not recover jumptable at 0x000140179989. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fc538)(param_1);

      return;

    }

  }

  return;

}




