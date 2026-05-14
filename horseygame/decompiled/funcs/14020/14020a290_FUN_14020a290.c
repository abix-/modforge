// Address: 0x14020a290
// Ghidra name: FUN_14020a290
// ============ 0x14020a290 FUN_14020a290 (size=218) ============


bool FUN_14020a290(longlong param_1,char *param_2,byte *param_3)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  byte bVar4;

  int iVar5;

  bool bVar6;

  

  iVar3 = 0;

  pcVar2 = &DAT_1403fd1e3;

  iVar5 = 0;

  bVar4 = 0;

  do {

    if ((pcVar2[-1] != '\0') && (*pcVar2 == '\0')) {

      *param_3 = bVar4;

      iVar5 = iVar5 + 1;

    }

    bVar4 = bVar4 + 1;

    pcVar2 = pcVar2 + 0x18;

  } while (bVar4 < 4);

  pcVar2 = &DAT_1403fd1e4;

  if (iVar5 == 1) {

    bVar4 = *param_3;

    (&DAT_1403fd1e4)[(ulonglong)bVar4 * 0x18] = (&DAT_1403fd1e4)[(ulonglong)bVar4 * 0x18] + '\x01';

    *param_2 = (&DAT_1403fd1e4)[(ulonglong)bVar4 * 0x18];

    bVar6 = true;

  }

  else {

    bVar4 = 0;

    *param_3 = 0;

    do {

      if (pcVar2[-1] == '\0') {

        cVar1 = FUN_14020b9f0(param_1,bVar4);

        if (cVar1 != '\0') {

          *param_3 = bVar4;

          iVar3 = iVar3 + 1;

          *pcVar2 = *pcVar2 + '\x01';

          *param_2 = *pcVar2;

        }

      }

      bVar4 = bVar4 + 1;

      pcVar2 = pcVar2 + 0x18;

    } while (bVar4 < 4);

    if (iVar3 == 1) {

      bVar6 = *(char *)(param_1 + 0x14) != '\0';

    }

    else {

      bVar6 = false;

    }

  }

  return bVar6;

}




