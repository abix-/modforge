// Address: 0x14015de70
// Ghidra name: FUN_14015de70
// ============ 0x14015de70 FUN_14015de70 (size=806) ============


void FUN_14015de70(longlong param_1)



{

  undefined4 *puVar1;

  bool bVar2;

  undefined4 *puVar3;

  char cVar4;

  longlong lVar5;

  undefined4 *puVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  int *piVar10;

  longlong lVar11;

  longlong lVar12;

  int iVar13;

  undefined4 *puVar14;

  undefined8 local_48;

  int local_40;

  undefined4 local_38 [2];

  longlong local_30;

  

  if (param_1 != 0) {

    cVar4 = *(char *)(param_1 + 0x94);

    FUN_14017cab0(DAT_1403fc128);

    iVar8 = *(int *)(param_1 + 0x50);

    iVar7 = DAT_1403fc148;

    if (cVar4 != '\0') {

      iVar7 = DAT_1403fc14c;

    }

    if (iVar8 == iVar7) {

      FUN_14017cae0(DAT_1403fc128);

      return;

    }

    iVar13 = iVar8;

    if (cVar4 != '\0') {

      iVar13 = DAT_1403fc148;

      DAT_1403fc14c = iVar8;

    }

    DAT_1403fc148 = iVar13;

    FUN_14017cae0(DAT_1403fc128);

    puVar14 = local_38;

    local_30 = 0;

    FUN_14015d3d0(param_1);

    FUN_14015cde0(param_1);

    lVar5 = FUN_14015cc50(iVar7);

    if (lVar5 == 0) {

      FUN_14015d3e0(param_1);

    }

    else {

      lVar11 = *(longlong *)(lVar5 + 0xd0);

      iVar8 = 0;

      bVar2 = false;

      local_48 = 0;

      local_40 = 0;

      if (lVar11 != 0) {

        local_48._4_4_ = 0;

        iVar7 = local_48._4_4_;

        iVar13 = iVar8;

        do {

          if (*(char *)(lVar11 + 0x20) != '\0') {

            lVar12 = *(longlong *)(lVar11 + 0x18);

            bVar2 = true;

            if (lVar12 != 0) {

              do {

                lVar9 = 0x3c;

                if (cVar4 == '\0') {

                  lVar9 = 0x30;

                }

                piVar10 = (int *)(lVar9 + lVar12);

                lVar12 = *(longlong *)(lVar12 + 200);

                if ((byte)iVar8 < (byte)*piVar10) {

                  iVar8 = *piVar10;

                }

                if (iVar7 < piVar10[1]) {

                  iVar7 = piVar10[1];

                }

                if (iVar13 < piVar10[2]) {

                  iVar13 = piVar10[2];

                }

              } while (lVar12 != 0);

              local_48 = CONCAT44(iVar7,iVar8);

              local_40 = iVar13;

            }

          }

          lVar11 = *(longlong *)(lVar11 + 0x38);

        } while (lVar11 != 0);

        if ((bVar2) && (cVar4 = FUN_14015cef0(param_1,&local_48), cVar4 != '\0')) {

          cVar4 = FUN_14015da30(lVar5 + 0x60,param_1 + 0x60,0,0);

          puVar1 = *(undefined4 **)(lVar5 + 0xd0);

          while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {

            puVar1 = *(undefined4 **)(puVar3 + 0xe);

            if (*(char *)(puVar3 + 8) != '\0') {

              FUN_14017cab0(DAT_1403fc128);

              if (*(longlong *)(puVar3 + 0xe) != 0) {

                *(undefined8 *)(*(longlong *)(puVar3 + 0xe) + 0x40) = *(undefined8 *)(puVar3 + 0x10)

                ;

              }

              if (*(longlong *)(puVar3 + 0x10) != 0) {

                *(undefined8 *)(*(longlong *)(puVar3 + 0x10) + 0x38) = *(undefined8 *)(puVar3 + 0xe)

                ;

              }

              if (*(undefined4 **)(lVar5 + 0xd0) == puVar3) {

                *(undefined8 *)(lVar5 + 0xd0) = *(undefined8 *)(puVar3 + 0xe);

              }

              *(longlong *)(puVar3 + 2) = param_1;

              *(undefined8 *)(puVar3 + 0x10) = 0;

              *(undefined8 *)(puVar3 + 0xe) = *(undefined8 *)(param_1 + 0xd0);

              *(undefined4 **)(param_1 + 0xd0) = puVar3;

              FUN_14017cae0(DAT_1403fc128);

              FUN_14015d3d0(param_1);

              FUN_14015fe40(lVar5);

              FUN_14015f9c0(*puVar3,*(undefined8 *)(puVar3 + 10),*(undefined8 *)(puVar3 + 0xc));

              if ((cVar4 == '\0') &&

                 (puVar6 = (undefined4 *)FUN_1401841f0(0x10), puVar6 != (undefined4 *)0x0)) {

                *puVar6 = 0x1102;

                puVar6[1] = *puVar3;

                *(undefined8 *)(puVar6 + 2) = 0;

                *(undefined4 **)(puVar14 + 2) = puVar6;

                puVar14 = puVar6;

              }

            }

          }

          FUN_14015fec0(lVar5);

          FUN_14015fec0(param_1);

          if (*(longlong *)(lVar5 + 0xd0) == 0) {

            FUN_14015c2e0(lVar5);

          }

        }

      }

      FUN_14015d3e0(lVar5);

      FUN_14015d3e0(param_1);

      FUN_14015fe40(lVar5);

    }

    if (local_30 != 0) {

      FUN_14017cab0(DAT_1403fc128);

      *(longlong *)(DAT_1403fc160 + 2) = local_30;

      DAT_1403fc160 = puVar14;

      FUN_14017cae0(DAT_1403fc128);

    }

  }

  return;

}




