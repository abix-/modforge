// Address: 0x1402d3908
// Ghidra name: FUN_1402d3908
// ============ 0x1402d3908 FUN_1402d3908 (size=176) ============


void FUN_1402d3908(longlong param_1,ulonglong param_2,byte param_3)



{

  ulonglong uVar1;

  longlong lVar2;

  char *pcVar3;

  char *pcVar4;

  char cVar5;

  

  lVar2 = *(longlong *)(param_1 + 0x458);

  if (lVar2 == 0) {

    uVar1 = 0x200;

    lVar2 = param_1 + 0x50;

  }

  else {

    uVar1 = *(ulonglong *)(param_1 + 0x450) >> 1;

  }

  pcVar3 = (char *)(lVar2 + -1 + uVar1);

  *(char **)(param_1 + 0x40) = pcVar3;

  pcVar4 = pcVar3;

  while ((0 < *(int *)(param_1 + 0x30) || (param_2 != 0))) {

    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;

    cVar5 = (char)param_2 + (char)(param_2 / 10) * -10 + '0';

    if ('9' < cVar5) {

      cVar5 = (param_3 ^ 1) * ' ' + '\a' + cVar5;

    }

    *pcVar4 = cVar5;

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + -1;

    pcVar4 = *(char **)(param_1 + 0x40);

    param_2 = param_2 / 10;

  }

  *(int *)(param_1 + 0x48) = (int)pcVar3 - *(int *)(param_1 + 0x40);

  *(char **)(param_1 + 0x40) = pcVar4 + 1;

  return;

}




