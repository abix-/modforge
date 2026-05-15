// Address: 0x1402d3770
// Ghidra name: FUN_1402d3770
// ============ 0x1402d3770 FUN_1402d3770 (size=160) ============


void FUN_1402d3770(longlong param_1,uint param_2,byte param_3)



{

  ushort *puVar1;

  ulonglong uVar2;

  ushort *puVar3;

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

  puVar1 = (ushort *)(lVar5 + (uVar2 - 1) * 2);

  *(ushort **)(param_1 + 0x40) = puVar1;

  puVar3 = puVar1;

  while ((0 < *(int *)(param_1 + 0x30) || (param_2 != 0))) {

    uVar4 = (ushort)param_2;

    param_2 = param_2 >> 4;

    uVar4 = (uVar4 & 0xf) + 0x30;

    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;

    if (0x39 < uVar4) {

      uVar4 = (ushort)(byte)((param_3 ^ 1) * ' ' + '\a' + (char)uVar4);

    }

    *puVar3 = uVar4;

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + -2;

    puVar3 = *(ushort **)(param_1 + 0x40);

  }

  *(int *)(param_1 + 0x48) = (int)((longlong)puVar1 - (longlong)puVar3 >> 1);

  *(ushort **)(param_1 + 0x40) = puVar3 + 1;

  return;

}




