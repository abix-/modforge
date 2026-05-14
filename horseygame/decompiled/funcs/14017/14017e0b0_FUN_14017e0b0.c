// Address: 0x14017e0b0
// Ghidra name: FUN_14017e0b0
// ============ 0x14017e0b0 FUN_14017e0b0 (size=131) ============


byte * FUN_14017e0b0(byte *param_1,char *param_2)



{

  byte bVar1;

  char cVar2;

  size_t sVar3;

  byte *pbVar4;

  char *pcVar5;

  

  sVar3 = strlen(param_2);

  param_1[0] = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  pbVar4 = param_1;

  pcVar5 = param_2;

  if ((sVar3 & 0xfffffffffffffffe) != 0) {

    do {

      if (0xf < (longlong)pbVar4 - (longlong)param_1) {

        return param_1;

      }

      bVar1 = FUN_14017e140(pcVar5[1]);

      cVar2 = FUN_14017e140(*pcVar5);

      pcVar5 = pcVar5 + 2;

      *pbVar4 = bVar1 | cVar2 << 4;

      pbVar4 = pbVar4 + 1;

    } while ((ulonglong)((longlong)pcVar5 - (longlong)param_2) < (sVar3 & 0xfffffffffffffffe));

  }

  return param_1;

}




