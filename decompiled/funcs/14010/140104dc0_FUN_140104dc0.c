// Address: 0x140104dc0
// Ghidra name: FUN_140104dc0
// ============ 0x140104dc0 FUN_140104dc0 (size=28) ============


void FUN_140104dc0(longlong param_1,int param_2,int param_3,byte param_4)



{

  byte *pbVar1;

  int *piVar2;

  longlong lVar3;

  

  lVar3 = (longlong)param_2;

  pbVar1 = (byte *)(param_1 + 800 + lVar3 * 8);

  *pbVar1 = *pbVar1 | param_4;

  piVar2 = (int *)(param_1 + 0x31c + lVar3 * 8);

  *piVar2 = *piVar2 + param_3;

  *(undefined1 *)(param_1 + 0x321 + lVar3 * 8) = 1;

  return;

}




