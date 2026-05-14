// Address: 0x14025f570
// Ghidra name: FUN_14025f570
// ============ 0x14025f570 FUN_14025f570 (size=1397) ============


void FUN_14025f570(longlong param_1,int param_2,int param_3,int param_4,int param_5,

                  undefined4 param_6,char param_7)



{

  undefined4 *puVar1;

  bool bVar2;

  uint uVar3;

  longlong lVar4;

  undefined4 uVar5;

  int iVar6;

  longlong lVar7;

  ulonglong uVar8;

  uint uVar9;

  longlong lVar10;

  int iVar11;

  undefined4 *puVar12;

  uint uVar13;

  int iVar14;

  int iVar15;

  uint uVar16;

  uint uVar17;

  undefined1 local_res18 [8];

  undefined1 local_38;

  undefined1 local_37 [15];

  

  uVar5 = param_6;

  iVar6 = param_5;

  lVar7 = *(longlong *)(param_1 + 0x38);

  lVar10 = (longlong)param_2;

  if (param_3 == param_5) {

    lVar7 = (longlong)((*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar7 + 5)) * param_3);

    if (param_4 < param_2) {

      puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x18) + (lVar7 + param_4) * 4);

      puVar12 = puVar1 + 1;

      if (param_7 != '\0') {

        puVar12 = puVar1;

      }

      uVar9 = param_2 - param_4;

      if (param_7 != '\0') {

        uVar9 = uVar9 + 1;

      }

    }

    else {

      uVar9 = (param_4 - param_2) + 1;

      if (param_7 == '\0') {

        uVar9 = param_4 - param_2;

      }

      puVar12 = (undefined4 *)(*(longlong *)(param_1 + 0x18) + (lVar7 + lVar10) * 4);

    }

    if (uVar9 != 0) {

      for (uVar8 = (ulonglong)uVar9; uVar8 != 0; uVar8 = uVar8 - 1) {

        *puVar12 = param_6;

        puVar12 = puVar12 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar7 + 5);

    if (param_5 < param_3) {

      iVar11 = param_3 - param_5;

      puVar12 = (undefined4 *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_5 + lVar10) * 4);

      if (param_7 == '\0') {

        puVar12 = puVar12 + iVar6;

      }

      else {

        iVar11 = iVar11 + 1;

      }

    }

    else {

      iVar11 = (param_5 - param_3) + 1;

      if (param_7 == '\0') {

        iVar11 = param_5 - param_3;

      }

      puVar12 = (undefined4 *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar10) * 4);

    }

    for (; iVar11 != 0; iVar11 = iVar11 + -1) {

      *puVar12 = param_6;

      puVar12 = puVar12 + iVar6;

    }

  }

  else {

    iVar15 = param_3 - param_5;

    iVar11 = -(param_2 - param_4);

    if (iVar11 < 0) {

      iVar11 = param_2 - param_4;

    }

    iVar14 = -iVar15;

    if (-iVar15 < 0) {

      iVar14 = iVar15;

    }

    if (iVar11 == iVar14) {

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar7 + 5);

      if (param_5 < param_3) {

        puVar12 = (undefined4 *)

                  (*(longlong *)(param_1 + 0x18) +

                  ((longlong)(iVar6 * param_5) + (longlong)param_4) * 4);

        iVar11 = 1;

        if (param_2 < param_4) {

          iVar11 = -1;

        }

        iVar11 = iVar11 + iVar6;

        if (param_7 == '\0') {

          puVar12 = puVar12 + iVar11;

        }

      }

      else {

        iVar15 = param_5 - param_3;

        puVar12 = (undefined4 *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar10) * 4);

        iVar11 = 1;

        if (param_4 < param_2) {

          iVar11 = -1;

        }

        iVar11 = iVar11 + iVar6;

      }

      iVar6 = iVar15 + 1;

      if (param_7 == '\0') {

        iVar6 = iVar15;

      }

      if (iVar6 != 0) {

        do {

          *puVar12 = param_6;

          puVar12 = puVar12 + iVar11;

          iVar6 = iVar6 + -1;

        } while (iVar6 != 0);

      }

    }

    else {

      FUN_14017b4a0(param_6,lVar7,*(undefined8 *)(param_1 + 0x48),local_37,&local_38,local_res18,

                    &param_5);

      uVar9 = -(param_4 - param_2);

      if ((int)uVar9 < 0) {

        uVar9 = param_4 - param_2;

      }

      uVar13 = -(iVar6 - param_3);

      if ((int)uVar13 < 0) {

        uVar13 = iVar6 - param_3;

      }

      if (*(int *)(lVar7 + 8) == 0xff0000) {

        if (*(int *)(lVar7 + 0x14) == 0) {

          bVar2 = (int)uVar9 < (int)uVar13;

          if (bVar2) {

            iVar11 = uVar9 * 2;

            iVar15 = iVar11 - uVar13;

            iVar14 = uVar9 - uVar13;

          }

          else {

            iVar11 = uVar13 * 2;

            iVar15 = iVar11 - uVar9;

            iVar14 = uVar13 - uVar9;

            uVar13 = uVar9;

          }

          uVar9 = -(uint)!bVar2;

          if (param_2 <= param_4) {

            uVar9 = (uint)!bVar2;

          }

          uVar3 = -(uint)bVar2;

          if (param_3 <= iVar6) {

            uVar3 = (uint)bVar2;

          }

          uVar17 = 0xffffffff;

          if (param_3 <= iVar6) {

            uVar17 = 1;

          }

          uVar16 = uVar13 + 1;

          if (param_7 == '\0') {

            uVar16 = uVar13;

          }

          if (0 < (int)uVar16) {

            uVar8 = (ulonglong)uVar16;

            lVar7 = -4;

            lVar10 = lVar10 * 4;

            if (param_2 <= param_4) {

              lVar7 = 4;

            }

            do {

              *(undefined4 *)

               (param_3 * *(int *)(param_1 + 0x10) + lVar10 + *(longlong *)(param_1 + 0x18)) = uVar5

              ;

              lVar4 = lVar7;

              uVar13 = uVar17;

              iVar6 = iVar14 * 2;

              if (iVar15 < 0) {

                lVar4 = (longlong)(int)uVar9 * 4;

                uVar13 = uVar3;

                iVar6 = iVar11;

              }

              iVar15 = iVar15 + iVar6;

              param_3 = param_3 + uVar13;

              lVar10 = lVar10 + lVar4;

              uVar8 = uVar8 - 1;

            } while (uVar8 != 0);

          }

        }

        else {

          bVar2 = (int)uVar9 < (int)uVar13;

          if (bVar2) {

            iVar11 = uVar9 * 2;

            iVar15 = iVar11 - uVar13;

            iVar14 = uVar9 - uVar13;

          }

          else {

            iVar11 = uVar13 * 2;

            iVar15 = iVar11 - uVar9;

            iVar14 = uVar13 - uVar9;

            uVar13 = uVar9;

          }

          uVar9 = -(uint)!bVar2;

          if (param_2 <= param_4) {

            uVar9 = (uint)!bVar2;

          }

          uVar3 = -(uint)bVar2;

          if (param_3 <= iVar6) {

            uVar3 = (uint)bVar2;

          }

          uVar17 = 0xffffffff;

          if (param_3 <= iVar6) {

            uVar17 = 1;

          }

          uVar16 = uVar13 + 1;

          if (param_7 == '\0') {

            uVar16 = uVar13;

          }

          if (0 < (int)uVar16) {

            uVar8 = (ulonglong)uVar16;

            lVar7 = -4;

            lVar10 = lVar10 * 4;

            if (param_2 <= param_4) {

              lVar7 = 4;

            }

            do {

              *(undefined4 *)

               (param_3 * *(int *)(param_1 + 0x10) + lVar10 + *(longlong *)(param_1 + 0x18)) = uVar5

              ;

              lVar4 = lVar7;

              uVar13 = uVar17;

              iVar6 = iVar14 * 2;

              if (iVar15 < 0) {

                lVar4 = (longlong)(int)uVar9 * 4;

                uVar13 = uVar3;

                iVar6 = iVar11;

              }

              iVar15 = iVar15 + iVar6;

              param_3 = param_3 + uVar13;

              lVar10 = lVar10 + lVar4;

              uVar8 = uVar8 - 1;

            } while (uVar8 != 0);

          }

        }

      }

      else {

        bVar2 = (int)uVar9 < (int)uVar13;

        if (bVar2) {

          iVar11 = uVar9 * 2;

          iVar15 = iVar11 - uVar13;

          iVar14 = uVar9 - uVar13;

        }

        else {

          iVar11 = uVar13 * 2;

          iVar15 = iVar11 - uVar9;

          iVar14 = uVar13 - uVar9;

          uVar13 = uVar9;

        }

        uVar9 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar9 = (uint)!bVar2;

        }

        uVar3 = -(uint)bVar2;

        if (param_3 <= iVar6) {

          uVar3 = (uint)bVar2;

        }

        uVar17 = 0xffffffff;

        if (param_3 <= iVar6) {

          uVar17 = 1;

        }

        uVar16 = uVar13 + 1;

        if (param_7 == '\0') {

          uVar16 = uVar13;

        }

        if (0 < (int)uVar16) {

          uVar8 = (ulonglong)uVar16;

          lVar7 = -4;

          lVar10 = lVar10 * 4;

          if (param_2 <= param_4) {

            lVar7 = 4;

          }

          do {

            *(undefined4 *)

             (param_3 * *(int *)(param_1 + 0x10) + lVar10 + *(longlong *)(param_1 + 0x18)) = uVar5;

            lVar4 = lVar7;

            uVar13 = uVar17;

            iVar6 = iVar14 * 2;

            if (iVar15 < 0) {

              lVar4 = (longlong)(int)uVar9 * 4;

              uVar13 = uVar3;

              iVar6 = iVar11;

            }

            iVar15 = iVar15 + iVar6;

            param_3 = param_3 + uVar13;

            lVar10 = lVar10 + lVar4;

            uVar8 = uVar8 - 1;

          } while (uVar8 != 0);

        }

      }

    }

  }

  return;

}




