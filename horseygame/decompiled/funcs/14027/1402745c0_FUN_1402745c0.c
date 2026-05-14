// Address: 0x1402745c0
// Ghidra name: FUN_1402745c0
// ============ 0x1402745c0 FUN_1402745c0 (size=61) ============


void FUN_1402745c0(longlong param_1,int param_2)



{

  if (-1 < param_2) {

    *(byte *)(param_1 + 0x2b) =

         (&DAT_14037f2a8)[param_2 + (int)((ulonglong)(longlong)param_2 / 5) * -5] | 0x20;

    return;

  }

  *(undefined1 *)(param_1 + 0x2b) = 0;

  return;

}




