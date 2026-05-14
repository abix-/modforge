// Address: 0x1400e8c90
// Ghidra name: FUN_1400e8c90
// ============ 0x1400e8c90 FUN_1400e8c90 (size=197) ============


ulonglong FUN_1400e8c90(longlong *param_1)



{

  byte bVar1;

  char cVar2;

  longlong lVar3;

  char *pcVar4;

  byte *pbVar5;

  

  bVar1 = *(byte *)(param_1 + 0x6d9);

  if (bVar1 != 0xff) {

    *(undefined1 *)(param_1 + 0x6d9) = 0xff;

    return (ulonglong)bVar1;

  }

  lVar3 = *param_1;

  pcVar4 = *(char **)(lVar3 + 0xb8);

  if (*(char **)(lVar3 + 0xc0) <= pcVar4) {

    if (*(int *)(lVar3 + 0x30) == 0) goto LAB_1400e8d48;

    FUN_1400ed820(lVar3);

    pcVar4 = *(char **)(lVar3 + 0xb8);

  }

  cVar2 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(lVar3 + 0xb8) = pcVar4;

  if (cVar2 == -1) {

    do {

      lVar3 = *param_1;

      pbVar5 = *(byte **)(lVar3 + 0xb8);

      if (*(byte **)(lVar3 + 0xc0) <= pbVar5) {

        if (*(int *)(lVar3 + 0x30) == 0) {

          return 0;

        }

        FUN_1400ed820(lVar3);

        pbVar5 = *(byte **)(lVar3 + 0xb8);

      }

      bVar1 = *pbVar5;

      *(byte **)(lVar3 + 0xb8) = pbVar5 + 1;

    } while (bVar1 == 0xff);

    return (ulonglong)bVar1;

  }

LAB_1400e8d48:

  return CONCAT71((int7)((ulonglong)pcVar4 >> 8),0xff);

}




