// Address: 0x1402cb390
// Ghidra name: FUN_1402cb390
// ============ 0x1402cb390 FUN_1402cb390 (size=336) ============


undefined8 FUN_1402cb390(longlong param_1,byte *param_2,byte *param_3)



{

  char cVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  char *pcVar7;

  byte *pbVar8;

  

  iVar3 = *(int *)(param_1 + 8);

  lVar6 = 0;

  if ((iVar3 != 0) && (lVar4 = FUN_1402c8e50(), lVar4 + iVar3 != 0)) {

    iVar3 = *(int *)(param_1 + 8);

    lVar4 = lVar6;

    if (iVar3 != 0) {

      lVar4 = FUN_1402c8e50();

      lVar4 = iVar3 + lVar4;

    }

    if ((*(char *)(lVar4 + 0x10) != '\0') &&

       (((*(byte *)(param_1 + 4) & 0x80) == 0 || ((*param_2 & 0x10) == 0)))) {

      iVar3 = *(int *)(param_1 + 8);

      lVar4 = lVar6;

      if (iVar3 != 0) {

        lVar4 = FUN_1402c8e50();

        lVar4 = iVar3 + lVar4;

      }

      lVar5 = FUN_1402c8e64();

      if (lVar4 != *(int *)(param_2 + 4) + lVar5) {

        iVar3 = *(int *)(param_1 + 8);

        if (iVar3 != 0) {

          lVar6 = FUN_1402c8e50();

          lVar6 = iVar3 + lVar6;

        }

        iVar3 = *(int *)(param_2 + 4);

        lVar4 = FUN_1402c8e64();

        pcVar7 = (char *)(lVar6 + 0x10);

        lVar6 = ((longlong)iVar3 + 0x10 + lVar4) - (longlong)pcVar7;

        do {

          cVar1 = *pcVar7;

          cVar2 = pcVar7[lVar6];

          if (cVar1 != cVar2) break;

          pcVar7 = pcVar7 + 1;

        } while (cVar2 != '\0');

        if (cVar1 != cVar2) {

          return 0;

        }

      }

      pbVar8 = (byte *)(param_1 + 4);

      if (((*param_2 & 2) != 0) && ((*pbVar8 & 8) == 0)) {

        return 0;

      }

      if (((*param_3 & 1) != 0) && ((*pbVar8 & 1) == 0)) {

        return 0;

      }

      if (((*param_3 & 4) != 0) && ((*pbVar8 & 4) == 0)) {

        return 0;

      }

      if (((*param_3 & 2) != 0) && ((*(byte *)(param_1 + 4) & 2) == 0)) {

        return 0;

      }

      return 1;

    }

  }

  return 1;

}




