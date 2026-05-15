// Address: 0x14009e850
// Ghidra name: FUN_14009e850
// ============ 0x14009e850 FUN_14009e850 (size=531) ============


void FUN_14009e850(longlong param_1,float param_2,float param_3,undefined8 param_4,float param_5,

                  uint param_6,undefined8 param_7)



{

  ulonglong *puVar1;

  char *pcVar2;

  char *pcVar3;

  char cVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  float fVar10;

  float fVar11;

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  float fVar14;

  undefined4 in_XMM3_Dc;

  undefined4 in_XMM3_Dd;

  undefined1 *puVar15;

  undefined4 uVar16;

  

  fVar14 = (float)param_4;

  puVar15 = &stack0x00000040;

  iVar7 = 0;

  puVar1 = (ulonglong *)FUN_140023ec0();

  FUN_1402d7d00(*puVar1 | 2,&DAT_1403ee0a0,0x3ff,param_7,0,puVar15);

  pcVar8 = (char *)0x0;

  pcVar2 = &DAT_1403ee0a0;

  pcVar9 = &DAT_1403ee0a0;

  while( true ) {

    while( true ) {

      iVar5 = 0;

      lVar6 = 0;

      cVar4 = *pcVar2;

      while (((cVar4 != '\0' && (pcVar2[lVar6] != ' ')) && (pcVar2[lVar6] != '\n'))) {

        lVar6 = lVar6 + 1;

        iVar5 = iVar5 + 1;

        cVar4 = pcVar2[lVar6];

      }

      cVar4 = pcVar2[lVar6];

      pcVar2[lVar6] = '\0';

      fVar10 = (float)FUN_14009ebd0(param_1,pcVar9,0);

      uVar16 = (undefined4)((ulonglong)puVar15 >> 0x20);

      pcVar2[lVar6] = cVar4;

      if (fVar14 < fVar10) {

        if (pcVar2 == pcVar9) {

          pcVar9 = pcVar2 + (iVar5 + 1);

          pcVar2[lVar6] = '\n';

          cVar4 = '\n';

          iVar7 = iVar7 + 1;

        }

        else {

          *pcVar8 = '\n';

          pcVar9 = pcVar8 + 1;

          cVar4 = pcVar2[lVar6];

          iVar7 = iVar7 + 1;

        }

      }

      pcVar3 = pcVar2 + (iVar5 + 1);

      if (cVar4 != '\n') break;

      iVar7 = iVar7 + 1;

      pcVar8 = pcVar2 + iVar5;

      pcVar2 = pcVar3;

      pcVar9 = pcVar3;

    }

    if (cVar4 == '\0') break;

    pcVar8 = pcVar2 + iVar5;

    pcVar2 = pcVar3;

  }

  fVar10 = *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x24) *

           (float)iVar7;

  if ((param_6 & 3) == 1) {

    param_2 = param_2 + fVar14;

  }

  else if ((param_6 & 3) == 2) {

    auVar12._8_4_ = in_XMM3_Dc;

    auVar12._0_8_ = param_4;

    auVar12._12_4_ = in_XMM3_Dd;

    auVar13._4_12_ = auVar12._4_12_;

    auVar13._0_4_ = fVar14 * DAT_14039ca34;

    fVar11 = (float)FUN_1402d0350(auVar13._0_8_);

    param_2 = fVar11 + param_2;

  }

  if ((param_6 & 0xc) == 4) {

    param_5 = param_5 - fVar10;

  }

  else {

    if ((param_6 & 0xc) != 8) goto LAB_14009ea13;

    param_5 = (float)FUN_1402d0350((param_5 - fVar10) * DAT_14039ca34);

  }

  param_3 = param_5 + param_3;

LAB_14009ea13:

  FUN_14009e2f0(param_1,param_2,param_3,param_6,&DAT_1403ee0a0,CONCAT44(uVar16,(int)fVar14));

  return;

}




