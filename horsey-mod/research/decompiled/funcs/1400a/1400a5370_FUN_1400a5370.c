// Address: 0x1400a5370
// Ghidra name: FUN_1400a5370
// ============ 0x1400a5370 FUN_1400a5370 (size=49) ============


char FUN_1400a5370(int param_1,int param_2)



{

  longlong lVar1;

  

  lVar1 = (longlong)param_1;

  if ((&DAT_1403f02a0)[lVar1 * 4] == param_2) {

    return '\0';

  }

  if ((&DAT_1403f02a4)[lVar1 * 4] == param_2) {

    return '\x01';

  }

  return ((&DAT_1403f02a8)[lVar1 * 4] != param_2) + '\x02';

}




