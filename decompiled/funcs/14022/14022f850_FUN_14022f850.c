// Address: 0x14022f850
// Ghidra name: FUN_14022f850
// ============ 0x14022f850 FUN_14022f850 (size=421) ============


undefined1 * FUN_14022f850(byte *param_1,char *param_2,byte *param_3,char *param_4)



{

  byte bVar1;

  size_t sVar2;

  size_t sVar3;

  size_t sVar4;

  size_t sVar5;

  undefined1 *puVar6;

  byte *pbVar7;

  byte *pbVar8;

  longlong lVar9;

  int iVar10;

  byte local_res8;

  undefined1 local_res9;

  

  iVar10 = 0;

  bVar1 = *param_1;

  pbVar8 = param_1;

  while (bVar1 != 0) {

    pbVar8 = pbVar8 + 1;

    iVar10 = iVar10 + (uint)(bVar1 == 0x3b);

    bVar1 = *pbVar8;

  }

  sVar2 = strlen((char *)param_3);

  sVar3 = strlen((char *)param_1);

  sVar4 = strlen(param_2);

  sVar5 = strlen(param_4);

  lVar9 = (sVar2 - 1) * (longlong)iVar10 + sVar3 + sVar4 + sVar5 + 1;

  puVar6 = (undefined1 *)FUN_1401841f0(lVar9);

  if (puVar6 == (undefined1 *)0x0) {

LAB_14022f9c9:

    puVar6 = (undefined1 *)0x0;

  }

  else {

    *puVar6 = 0;

    FUN_14012f120(puVar6,param_2,lVar9);

    iVar10 = strcmp((char *)param_1,"*");

    if (iVar10 == 0) {

      FUN_14012f120(puVar6,&DAT_14030f898,lVar9);

    }

    else {

      bVar1 = *param_1;

      pbVar8 = param_1;

      while (bVar1 != 0) {

        if (((byte)(bVar1 + 0x9f) < 0x1a) ||

           (((byte)(bVar1 - 0x2d) < 0x33 &&

            ((0x43ffffff01ffbU >> ((ulonglong)(bVar1 - 0x2d) & 0x3f) & 1) != 0)))) {

          local_res9 = 0;

          pbVar7 = &local_res8;

          local_res8 = bVar1;

        }

        else {

          if (bVar1 != 0x3b) {

            FUN_14012e850("Invalid character \'%c\' in pattern (Only [a-zA-Z0-9_.-] allowed, or a single *)"

                          ,(int)(char)*pbVar8);

            FUN_1401841e0(puVar6);

            goto LAB_14022f9c9;

          }

          if ((pbVar8 == param_1) || (pbVar7 = param_3, pbVar8[-1] == 0x3b)) goto LAB_14022f92c;

        }

        FUN_14012f120(puVar6,pbVar7,lVar9);

        pbVar7 = pbVar8 + 1;

        pbVar8 = pbVar8 + 1;

        bVar1 = *pbVar7;

      }

    }

    sVar2 = strlen((char *)param_1);

    if (param_1[sVar2 - 1] == 0x3b) {

LAB_14022f92c:

      FUN_14012e850("Empty pattern not allowed");

      FUN_1401841e0(puVar6);

      puVar6 = (undefined1 *)0x0;

    }

    else {

      FUN_14012f120(puVar6,param_4,lVar9);

    }

  }

  return puVar6;

}




