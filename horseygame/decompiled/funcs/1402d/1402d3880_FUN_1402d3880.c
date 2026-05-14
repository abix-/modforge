// Address: 0x1402d3880
// Ghidra name: FUN_1402d3880
// ============ 0x1402d3880 FUN_1402d3880 (size=134) ============


void FUN_1402d3880(longlong param_1,ulonglong param_2)



{

  ulonglong uVar1;

  short *psVar2;

  longlong lVar3;

  short *psVar4;

  

  lVar3 = *(longlong *)(param_1 + 0x458);

  if (lVar3 == 0) {

    uVar1 = 0x100;

    lVar3 = param_1 + 0x50;

  }

  else {

    uVar1 = *(ulonglong *)(param_1 + 0x450) >> 2;

  }

  psVar4 = (short *)(lVar3 + uVar1 * 2 + -2);

  *(short **)(param_1 + 0x40) = psVar4;

  psVar2 = psVar4;

  for (; (0 < *(int *)(param_1 + 0x30) || (param_2 != 0)); param_2 = param_2 >> 3) {

    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;

    *psVar2 = ((ushort)param_2 & 7) + 0x30;

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + -2;

    psVar2 = *(short **)(param_1 + 0x40);

  }

  *(int *)(param_1 + 0x48) = (int)((longlong)psVar4 - (longlong)psVar2 >> 1);

  *(short **)(param_1 + 0x40) = psVar2 + 1;

  return;

}




