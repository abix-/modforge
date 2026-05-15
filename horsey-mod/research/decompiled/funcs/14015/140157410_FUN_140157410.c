// Address: 0x140157410
// Ghidra name: FUN_140157410
// ============ 0x140157410 FUN_140157410 (size=358) ============


bool FUN_140157410(undefined8 param_1)



{

  longlong lVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  int *piVar8;

  char *pcVar9;

  longlong lVar10;

  short local_res10 [4];

  short local_res18 [8];

  undefined4 local_38;

  undefined4 uStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  

  puVar7 = (undefined4 *)FUN_1401585d0(&local_38,param_1);

  lVar10 = 0;

  local_38 = *puVar7;

  uStack_34 = puVar7[1];

  uStack_30 = puVar7[2];

  uStack_2c = puVar7[3];

  FUN_1401582b0(&local_38,local_res10,local_res18,0,0);

  if ((local_res10[0] == 0x45e) && (local_res18[0] == 0x28e)) {

    bVar3 = false;

    bVar2 = false;

    cVar4 = FUN_14017e460(0x8000);

    if (cVar4 != '\0') {

      piVar8 = (int *)FUN_140177270(0);

      if (piVar8 != (int *)0x0) {

        iVar6 = *piVar8;

        bVar2 = false;

        bVar3 = false;

        while (iVar6 != 0) {

          if ((((!bVar3) && (iVar5 = FUN_1401771c0(iVar6), iVar5 == 1)) &&

              (pcVar9 = (char *)FUN_140176fc0(iVar6), pcVar9 != (char *)0x0)) &&

             (iVar5 = strcmp(pcVar9,"Sensor BMI320 Acc"), iVar5 == 0)) {

            bVar3 = true;

          }

          if (((!bVar2) && (iVar5 = FUN_1401771c0(iVar6), iVar5 == 2)) &&

             ((pcVar9 = (char *)FUN_140176fc0(iVar6), pcVar9 != (char *)0x0 &&

              (iVar6 = strcmp(pcVar9,"Sensor BMI320 Gyr"), iVar6 == 0)))) {

            bVar2 = true;

          }

          lVar1 = lVar10 + 4;

          lVar10 = lVar10 + 4;

          iVar6 = *(int *)(lVar1 + (longlong)piVar8);

        }

        FUN_1401841e0(piVar8);

      }

      FUN_14017e880(0x8000);

      if (bVar3) {

        return bVar2;

      }

    }

  }

  return false;

}




