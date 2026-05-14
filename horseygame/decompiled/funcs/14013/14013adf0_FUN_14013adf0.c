// Address: 0x14013adf0
// Ghidra name: FUN_14013adf0
// ============ 0x14013adf0 FUN_14013adf0 (size=495) ============


uint FUN_14013adf0(undefined8 *param_1,uint param_2,int param_3,uint param_4,uint param_5,

                  char param_6)



{

  uint uVar1;

  uint *puVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  undefined8 uVar6;

  uint *puVar7;

  int iVar8;

  undefined8 *puVar9;

  ulonglong uVar10;

  uint uVar11;

  ulonglong uVar13;

  ulonglong uVar12;

  

  uVar12 = 0;

  uVar11 = 0;

  FUN_140179b40(DAT_1403fbea0);

  if (DAT_1403fbea8 == '\0') {

    if (param_3 == 2) {

      FUN_14012e850("The event system has been shut down");

    }

    FUN_140179b60(DAT_1403fbea0);

    return 0xffffffff;

  }

  uVar10 = uVar12;

  uVar13 = uVar12;

  puVar9 = param_1;

  puVar7 = DAT_1403fbeb8;

  if (param_3 == 0) {

    if (param_1 == (undefined8 *)0x0) {

      FUN_140179b60(DAT_1403fbea0);

      FUN_14012e850("Parameter \'%s\' is invalid","events");

      return 0xffffffff;

    }

    if (0 < (int)param_2) {

      uVar10 = (ulonglong)param_2;

      do {

        iVar8 = FUN_140139030(param_1);

        uVar11 = (int)uVar12 + iVar8;

        uVar12 = (ulonglong)uVar11;

        param_1 = param_1 + 0x10;

        uVar10 = uVar10 - 1;

      } while (uVar10 != 0);

    }

  }

  else {

    while ((puVar7 != (uint *)0x0 &&

           ((uVar11 = (uint)uVar12, param_1 == (undefined8 *)0x0 ||

            ((longlong)uVar13 < (longlong)(int)param_2))))) {

      uVar1 = *puVar7;

      puVar2 = *(uint **)(puVar7 + 0x24);

      if ((param_4 <= uVar1) && (uVar1 <= param_5)) {

        if (param_1 != (undefined8 *)0x0) {

          uVar6 = *(undefined8 *)(puVar7 + 2);

          *puVar9 = *(undefined8 *)puVar7;

          puVar9[1] = uVar6;

          uVar6 = *(undefined8 *)(puVar7 + 6);

          puVar9[2] = *(undefined8 *)(puVar7 + 4);

          puVar9[3] = uVar6;

          uVar6 = *(undefined8 *)(puVar7 + 10);

          puVar9[4] = *(undefined8 *)(puVar7 + 8);

          puVar9[5] = uVar6;

          uVar6 = *(undefined8 *)(puVar7 + 0xe);

          puVar9[6] = *(undefined8 *)(puVar7 + 0xc);

          puVar9[7] = uVar6;

          uVar6 = *(undefined8 *)(puVar7 + 0x12);

          puVar9[8] = *(undefined8 *)(puVar7 + 0x10);

          puVar9[9] = uVar6;

          uVar6 = *(undefined8 *)(puVar7 + 0x16);

          puVar9[10] = *(undefined8 *)(puVar7 + 0x14);

          puVar9[0xb] = uVar6;

          uVar3 = puVar7[0x19];

          uVar4 = puVar7[0x1a];

          uVar5 = puVar7[0x1b];

          *(uint *)(puVar9 + 0xc) = puVar7[0x18];

          *(uint *)((longlong)puVar9 + 100) = uVar3;

          *(uint *)(puVar9 + 0xd) = uVar4;

          *(uint *)((longlong)puVar9 + 0x6c) = uVar5;

          uVar3 = puVar7[0x1d];

          uVar4 = puVar7[0x1e];

          uVar5 = puVar7[0x1f];

          *(uint *)(puVar9 + 0xe) = puVar7[0x1c];

          *(uint *)((longlong)puVar9 + 0x74) = uVar3;

          *(uint *)(puVar9 + 0xf) = uVar4;

          *(uint *)((longlong)puVar9 + 0x7c) = uVar5;

          if (param_3 == 2) {

            FUN_140139320();

          }

        }

        if (uVar1 == 0x7f00) {

          if (param_6 != '\0') {

            if ((param_1 == (undefined8 *)0x0) || (param_3 != 2)) {

              uVar10 = (ulonglong)((int)uVar10 + 1);

            }

            iVar8 = FUN_140138fe0(&DAT_1403fb690);

            if (iVar8 <= (int)uVar10) goto LAB_14013af8e;

          }

        }

        else {

LAB_14013af8e:

          uVar12 = (ulonglong)(uVar11 + 1);

          uVar13 = uVar13 + 1;

          puVar9 = puVar9 + 0x10;

        }

      }

      uVar11 = (uint)uVar12;

      puVar7 = puVar2;

    }

  }

  FUN_140179b60(DAT_1403fbea0);

  if ((0 < (int)uVar11) && (param_3 == 0)) {

    FUN_14013b580();

  }

  return uVar11;

}




