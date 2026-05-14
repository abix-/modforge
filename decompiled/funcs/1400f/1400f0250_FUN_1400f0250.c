// Address: 0x1400f0250
// Ghidra name: FUN_1400f0250
// ============ 0x1400f0250 FUN_1400f0250 (size=412) ============


bool FUN_1400f0250(longlong param_1)



{

  longlong *plVar1;

  byte bVar2;

  char cVar3;

  int iVar4;

  byte *pbVar5;

  char *pcVar6;

  

  plVar1 = (longlong *)(param_1 + 0xb8);

  pbVar5 = (byte *)*plVar1;

  if (pbVar5 < *(byte **)(param_1 + 0xc0)) {

    pbVar5 = pbVar5 + 1;

    *plVar1 = (longlong)pbVar5;

  }

  else if (*(int *)(param_1 + 0x30) != 0) {

    FUN_1400ed820();

    *plVar1 = *plVar1 + 1;

    pbVar5 = (byte *)*plVar1;

  }

  if (*(byte **)(param_1 + 0xc0) <= pbVar5) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400f02d0;

    FUN_1400ed820(param_1);

    pbVar5 = (byte *)*plVar1;

  }

  bVar2 = *pbVar5;

  pbVar5 = pbVar5 + 1;

  *plVar1 = (longlong)pbVar5;

  if (1 < bVar2) {

    return false;

  }

LAB_1400f02d0:

  if (*(byte **)(param_1 + 0xc0) <= pbVar5) {

    if (*(int *)(param_1 + 0x30) == 0) {

      return false;

    }

    FUN_1400ed820(param_1);

    pbVar5 = *(byte **)(param_1 + 0xb8);

  }

  bVar2 = *pbVar5;

  *(byte **)(param_1 + 0xb8) = pbVar5 + 1;

  if (((((bVar2 == 1) || (bVar2 == 2)) || (bVar2 == 3)) || ((bVar2 == 9 || (bVar2 == 10)))) ||

     (bVar2 == 0xb)) {

    FUN_1400e8ad0(param_1);

    FUN_1400e8ad0(param_1);

    if (*(ulonglong *)(param_1 + 0xb8) < *(ulonglong *)(param_1 + 0xc0)) {

      *(ulonglong *)(param_1 + 0xb8) = *(ulonglong *)(param_1 + 0xb8) + 1;

    }

    else if (*(int *)(param_1 + 0x30) != 0) {

      FUN_1400ed820(param_1);

      *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 1;

    }

    FUN_1400e8ad0(param_1);

    FUN_1400e8ad0(param_1);

    iVar4 = FUN_1400e8ad0(param_1);

    if ((0 < iVar4) && (iVar4 = FUN_1400e8ad0(param_1), 0 < iVar4)) {

      pcVar6 = *(char **)(param_1 + 0xb8);

      if (*(char **)(param_1 + 0xc0) <= pcVar6) {

        if (*(int *)(param_1 + 0x30) == 0) {

          return false;

        }

        FUN_1400ed820(param_1);

        pcVar6 = *(char **)(param_1 + 0xb8);

      }

      cVar3 = *pcVar6;

      *(char **)(param_1 + 0xb8) = pcVar6 + 1;

      if ((cVar3 != '\b') && ((cVar3 - 0x10U & 0xf7) != 0)) {

        return cVar3 == ' ';

      }

      return true;

    }

  }

  return false;

}




