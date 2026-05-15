// Address: 0x1400a3200
// Ghidra name: FUN_1400a3200
// ============ 0x1400a3200 FUN_1400a3200 (size=179) ============


float FUN_1400a3200(longlong param_1,longlong param_2)



{

  char cVar1;

  char cVar2;

  int iVar3;

  char cVar4;

  char cVar5;

  char *pcVar6;

  longlong lVar7;

  int iVar8;

  char cVar9;

  char cVar10;

  

  pcVar6 = (char *)(param_2 + 0xf0);

  iVar8 = 0;

  lVar7 = 0xf0;

  do {

    cVar1 = *pcVar6;

    cVar9 = pcVar6[-0xf0];

    cVar2 = pcVar6[param_1 - param_2];

    cVar10 = pcVar6[(param_1 - param_2) + -0xf0];

    pcVar6 = pcVar6 + 1;

    cVar5 = cVar9;

    if (cVar1 < cVar9) {

      cVar5 = cVar1;

    }

    cVar4 = cVar10;

    if (cVar2 < cVar10) {

      cVar4 = cVar2;

    }

    iVar3 = iVar8 + 1;

    if (cVar4 == cVar5) {

      iVar3 = iVar8;

    }

    if (cVar10 < cVar2) {

      cVar10 = cVar2;

    }

    if (cVar9 < cVar1) {

      cVar9 = cVar1;

    }

    iVar8 = iVar3 + 1;

    if (cVar10 == cVar9) {

      iVar8 = iVar3;

    }

    lVar7 = lVar7 + -1;

  } while (lVar7 != 0);

  return ((float)iVar8 / DAT_14030cd34) * DAT_14039ca34;

}




