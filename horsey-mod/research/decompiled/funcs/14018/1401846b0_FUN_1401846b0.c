// Address: 0x1401846b0
// Ghidra name: FUN_1401846b0
// ============ 0x1401846b0 FUN_1401846b0 (size=378) ============


undefined8 * FUN_1401846b0(char *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  undefined8 *puVar3;

  char cVar4;

  char *pcVar5;

  char *pcVar6;

  longlong lVar7;

  undefined8 *puVar8;

  undefined8 *puVar9;

  bool bVar10;

  

  if (param_2 != (int *)0x0) {

    *param_2 = 0;

  }

  while( true ) {

    if (param_1 == (char *)0x0) goto LAB_1401846fa;

    if ((*param_1 == '\0') || (iVar1 = FUN_140190430((int)*param_1), iVar1 == 0)) break;

    param_1 = param_1 + 1;

  }

  cVar4 = *param_1;

  if (cVar4 == '\0') goto LAB_1401846fa;

  lVar7 = 1;

  pcVar5 = param_1;

  do {

    bVar10 = cVar4 != ',';

    cVar4 = pcVar5[1];

    iVar1 = (int)lVar7 + 1;

    if (bVar10) {

      iVar1 = (int)lVar7;

    }

    pcVar5 = pcVar5 + 1;

    lVar7 = (longlong)iVar1;

  } while (cVar4 != '\0');

  puVar3 = (undefined8 *)FUN_1401841a0(1,pcVar5 + (1 - (longlong)param_1) + (lVar7 * 3 + 1) * 8);

  if (puVar3 == (undefined8 *)0x0) {

LAB_1401846fa:

    puVar3 = (undefined8 *)0x0;

  }

  else {

    puVar8 = puVar3 + lVar7 + 1;

    pcVar6 = (char *)(puVar8 + lVar7 * 2);

    FUN_1402f8e20(pcVar6,param_1,pcVar5 + (1 - (longlong)param_1));

    *puVar3 = puVar8;

    puVar9 = puVar3 + 1;

LAB_1401847a0:

    iVar2 = FUN_140190430((int)*pcVar6);

    while (iVar2 != 0) {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

      iVar2 = FUN_140190430((int)*pcVar5);

    }

    if (*pcVar6 != '\0') {

      *puVar8 = pcVar6;

      do {

        while( true ) {

          pcVar6 = pcVar6 + 1;

          while( true ) {

            cVar4 = *pcVar6;

            if (cVar4 != '_') break;

            *pcVar6 = '\0';

            pcVar6 = pcVar6 + 1;

            puVar8[1] = pcVar6;

          }

          iVar2 = FUN_140190430((int)cVar4);

          if (iVar2 == 0) break;

          *pcVar6 = '\0';

        }

        if (cVar4 == ',') {

          *pcVar6 = '\0';

          puVar8 = puVar8 + 2;

          pcVar6 = pcVar6 + 1;

          *puVar9 = puVar8;

          puVar9 = puVar9 + 1;

          break;

        }

      } while (cVar4 != '\0');

      goto LAB_1401847a0;

    }

    if (param_2 != (int *)0x0) {

      *param_2 = iVar1;

    }

  }

  return puVar3;

}




