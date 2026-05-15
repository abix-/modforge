// Address: 0x140178c00
// Ghidra name: FUN_140178c00
// ============ 0x140178c00 FUN_140178c00 (size=659) ============


undefined8 *

FUN_140178c00(char *param_1,longlong param_2,uint param_3,int *param_4,code *param_5,

             undefined8 param_6,undefined8 param_7)



{

  char cVar1;

  int iVar2;

  size_t sVar3;

  char *pcVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 *puVar8;

  char *pcVar9;

  int *piVar10;

  uint uVar11;

  int local_res8 [2];

  code *local_68;

  longlong local_60;

  int local_58;

  uint local_54;

  code *local_50;

  undefined8 local_48;

  undefined8 local_40;

  longlong local_38;

  longlong local_30;

  

  piVar10 = local_res8;

  if (param_4 != (int *)0x0) {

    piVar10 = param_4;

  }

  *piVar10 = 0;

  if (param_1 != (char *)0x0) {

    sVar3 = strlen(param_1);

    pcVar9 = (char *)0x0;

    if ((1 < sVar3) && ((param_1[sVar3 - 1] == '/' || (param_1[sVar3 - 1] == '\\')))) {

      param_1 = (char *)FUN_14012f0d0(param_1);

      if (param_1 == (char *)0x0) {

        return (undefined8 *)0x0;

      }

      for (pcVar4 = param_1 + (sVar3 - 1);

          (pcVar9 = param_1, param_1 < pcVar4 && ((*pcVar4 == '/' || (*pcVar4 == '\\'))));

          pcVar4 = pcVar4 + -1) {

        *pcVar4 = '\0';

        sVar3 = sVar3 - 1;

      }

    }

    uVar11 = param_3 & 0xfffffffe;

    if (param_2 != 0) {

      uVar11 = param_3;

    }

    lVar5 = 0;

    if (((uVar11 & 1) == 0) || (lVar5 = FUN_1401785d0(param_2), lVar5 != 0)) {

      local_58 = 0;

      local_30 = FUN_14012c080();

      if (local_30 != 0) {

        local_68 = FUN_140178f60;

        local_38 = 0;

        if (param_2 == 0) {

          local_68 = (code *)&LAB_140178780;

        }

        local_60 = param_2;

        if (lVar5 != 0) {

          local_60 = lVar5;

        }

        local_50 = param_5;

        local_48 = param_6;

        local_40 = param_7;

        local_54 = uVar11;

        if (*param_1 != '\0') {

          iVar2 = strcmp(param_1,"/");

          if ((iVar2 == 0) || (iVar2 = strcmp(param_1,"\\"), iVar2 == 0)) {

            local_38 = 1;

          }

          else {

            local_38 = sVar3 + 1;

          }

        }

        puVar7 = (undefined8 *)0x0;

        cVar1 = (*local_50)(param_1,FUN_140178790,&local_68,local_40);

        if (cVar1 != '\0') {

          lVar6 = FUN_14012be60(local_30);

          puVar7 = (undefined8 *)FUN_1401841f0(lVar6 + (longlong)(local_58 + 1) * 8);

          if (puVar7 != (undefined8 *)0x0) {

            if (0 < local_58) {

              FUN_14012cb40(local_30,0,0);

              pcVar4 = (char *)(puVar7 + (local_58 + 1));

              FUN_14012c730(local_30,pcVar4,lVar6);

              iVar2 = 0;

              puVar8 = puVar7;

              if (0 < local_58) {

                do {

                  *puVar8 = pcVar4;

                  sVar3 = strlen(pcVar4);

                  iVar2 = iVar2 + 1;

                  pcVar4 = pcVar4 + sVar3 + 1;

                  puVar8 = puVar8 + 1;

                } while (iVar2 < local_58);

              }

            }

            puVar7[local_58] = 0;

            *piVar10 = local_58;

          }

        }

        FUN_14012bd50(local_30);

        FUN_1401841e0(lVar5);

        FUN_1401841e0(pcVar9);

        return puVar7;

      }

      FUN_1401841e0(lVar5);

    }

    FUN_1401841e0(pcVar9);

    return (undefined8 *)0x0;

  }

  FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

  return (undefined8 *)0x0;

}




