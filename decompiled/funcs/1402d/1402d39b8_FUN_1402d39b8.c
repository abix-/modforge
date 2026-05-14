// Address: 0x1402d39b8
// Ghidra name: FUN_1402d39b8
// ============ 0x1402d39b8 FUN_1402d39b8 (size=195) ============


void FUN_1402d39b8(longlong param_1,ulonglong param_2,byte param_3)



{

  short *psVar1;

  ulonglong uVar2;

  short *psVar3;

  ushort uVar4;

  longlong lVar5;

  

  lVar5 = *(longlong *)(param_1 + 0x458);

  if (lVar5 == 0) {

    uVar2 = 0x100;

    lVar5 = param_1 + 0x50;

  }

  else {

    uVar2 = *(ulonglong *)(param_1 + 0x450) >> 2;

  }

  psVar1 = (short *)(lVar5 + (uVar2 - 1) * 2);

  *(short **)(param_1 + 0x40) = psVar1;

  psVar3 = psVar1;

  while ((0 < *(int *)(param_1 + 0x30) || (param_2 != 0))) {

    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;

    uVar4 = (short)param_2 + (short)(param_2 / 10) * -10 + 0x30;

    if (0x39 < uVar4) {

      uVar4 = (ushort)(char)((param_3 ^ 1) * ' ' + '\a' + (char)uVar4);

    }

    *psVar3 = (short)(char)uVar4;

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + -2;

    psVar3 = *(short **)(param_1 + 0x40);

    param_2 = param_2 / 10;

  }

  *(int *)(param_1 + 0x48) = (int)((longlong)psVar1 - (longlong)psVar3 >> 1);

  *(short **)(param_1 + 0x40) = psVar3 + 1;

  return;

}




