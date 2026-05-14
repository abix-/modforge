// Address: 0x14019f370
// Ghidra name: FUN_14019f370
// ============ 0x14019f370 FUN_14019f370 (size=197) ============


ulonglong FUN_14019f370(longlong *param_1)



{

  byte bVar1;

  char cVar2;

  longlong lVar3;

  char *pcVar4;

  byte *pbVar5;

  

  bVar1 = *(byte *)(param_1 + 0x905);

  if (bVar1 != 0xff) {

    *(undefined1 *)(param_1 + 0x905) = 0xff;

    return (ulonglong)bVar1;

  }

  lVar3 = *param_1;

  pcVar4 = *(char **)(lVar3 + 0xc0);

  if (*(char **)(lVar3 + 200) <= pcVar4) {

    if (*(int *)(lVar3 + 0x30) == 0) goto LAB_14019f428;

    FUN_1401a4400(lVar3);

    pcVar4 = *(char **)(lVar3 + 0xc0);

  }

  cVar2 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(lVar3 + 0xc0) = pcVar4;

  if (cVar2 == -1) {

    do {

      lVar3 = *param_1;

      pbVar5 = *(byte **)(lVar3 + 0xc0);

      if (*(byte **)(lVar3 + 200) <= pbVar5) {

        if (*(int *)(lVar3 + 0x30) == 0) {

          return 0;

        }

        FUN_1401a4400(lVar3);

        pbVar5 = *(byte **)(lVar3 + 0xc0);

      }

      bVar1 = *pbVar5;

      *(byte **)(lVar3 + 0xc0) = pbVar5 + 1;

    } while (bVar1 == 0xff);

    return (ulonglong)bVar1;

  }

LAB_14019f428:

  return CONCAT71((int7)((ulonglong)pcVar4 >> 8),0xff);

}




