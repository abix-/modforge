// Address: 0x1400fff40
// Ghidra name: FUN_1400fff40
// ============ 0x1400fff40 FUN_1400fff40 (size=740) ============


void FUN_1400fff40(longlong param_1)



{

  longlong lVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  undefined4 uVar6;

  int iVar7;

  int iVar8;

  size_t sVar9;

  uint uVar10;

  ulonglong uVar12;

  longlong lVar13;

  uint uVar14;

  int iVar15;

  undefined8 *puVar16;

  int iVar17;

  undefined **ppuVar18;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 local_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  ulonglong uVar11;

  

  puVar16 = &local_78;

  uVar12 = 0;

  ppuVar18 = &PTR_s_Plain_1403dc340;

  local_78 = 0;

  uStack_70 = 0;

  local_68 = 0;

  uStack_60 = 0;

  local_58 = 0;

  uStack_50 = 0;

  local_48 = 0;

  uStack_40 = 0;

  local_38 = 0;

  uStack_30 = 0;

  uVar11 = uVar12;

  do {

    local_98 = 0;

    uStack_90 = 0;

    local_88 = 0;

    local_80 = 0;

    sVar9 = strlen(*ppuVar18);

    FUN_140027e30(&local_98,*ppuVar18,sVar9);

    uVar6 = FUN_14006fe60(&local_98);

    uVar10 = (int)uVar11 + 1;

    uVar11 = (ulonglong)uVar10;

    *(undefined4 *)puVar16 = uVar6;

    ppuVar18 = ppuVar18 + 1;

    puVar16 = (undefined8 *)((longlong)puVar16 + 4);

  } while (uVar10 < 10);

  iVar8 = *(int *)(param_1 + 0x278);

  iVar17 = *(int *)(param_1 + 0x27c);

  uVar11 = uVar12;

  if (0 < iVar8 * iVar17) {

    do {

      uVar12 = uVar12 + 0x28;

      uVar10 = (int)uVar11 + 1;

      *(undefined4 *)(*(longlong *)(param_1 + 0x270) + -0x20 + uVar12) =

           *(undefined4 *)

            ((longlong)&local_78 +

            (longlong)*(int *)(*(longlong *)(param_1 + 0x270) + -0x28 + uVar12) * 4);

      iVar8 = *(int *)(param_1 + 0x278);

      iVar17 = *(int *)(param_1 + 0x27c);

      uVar11 = (ulonglong)uVar10;

    } while ((int)uVar10 < iVar8 * iVar17);

  }

  iVar15 = 1;

  if (1 < iVar17 + -1) {

    do {

      iVar17 = 1;

      if (1 < iVar8 + -1) {

        do {

          lVar5 = *(longlong *)(param_1 + 0x270);

          iVar7 = iVar8 * iVar15 + iVar17;

          lVar13 = (longlong)iVar7;

          lVar1 = lVar13 * 0x28;

          iVar3 = *(int *)(lVar1 + lVar5);

          if ((iVar3 == 0) || (iVar3 == 0xf)) {

            iVar8 = FUN_1400c6580(4);

            piVar2 = (int *)(lVar1 + 8 + *(longlong *)(param_1 + 0x270));

            *piVar2 = *piVar2 + iVar8;

          }

          else if (iVar3 == 6) {

            iVar3 = *(int *)(lVar5 + -0x28 + lVar13 * 0x28);

            if ((iVar3 == 6) || (*(int *)(lVar5 + (longlong)(iVar7 - iVar8) * 0x28) == 6)) {

              iVar4 = *(int *)(lVar5 + 0x28 + lVar13 * 0x28);

              if ((iVar4 == 6) || (*(int *)(lVar5 + (longlong)(iVar7 - iVar8) * 0x28) == 6)) {

                if ((iVar3 == 6) || (*(int *)(lVar5 + (longlong)(iVar8 + iVar7) * 0x28) == 6)) {

                  if ((iVar4 != 6) && (*(int *)(lVar5 + (longlong)(iVar8 + iVar7) * 0x28) != 6)) {

                    piVar2 = (int *)(lVar5 + 8 + (longlong)iVar7 * 0x28);

                    *piVar2 = *piVar2 + 1;

                  }

                }

                else {

                  piVar2 = (int *)(lVar5 + 8 + (longlong)iVar7 * 0x28);

                  *piVar2 = *piVar2 + 2;

                }

              }

              else {

                piVar2 = (int *)(lVar5 + 8 + (longlong)iVar7 * 0x28);

                *piVar2 = *piVar2 + 3;

              }

            }

            else {

              piVar2 = (int *)(lVar1 + lVar5 + 8);

              *piVar2 = *piVar2 + 4;

            }

          }

          else if (iVar3 - 7U < 2) {

            uVar10 = (uint)(*(int *)(lVar5 + (longlong)(iVar7 - iVar8) * 0x28) == iVar3);

            uVar14 = uVar10 + 2;

            if (*(int *)(lVar5 + ((longlong)iVar7 + 1) * 0x28) != iVar3) {

              uVar14 = uVar10;

            }

            if (*(int *)(lVar5 + (longlong)(iVar8 + iVar7) * 0x28) == iVar3) {

              uVar14 = uVar14 + 4;

            }

            uVar10 = uVar14 + 8;

            if (*(int *)(lVar5 + -0x28 + (longlong)iVar7 * 0x28) != iVar3) {

              uVar10 = uVar14;

            }

            piVar2 = (int *)(lVar5 + 8 + (longlong)iVar7 * 0x28);

            *piVar2 = *piVar2 + uVar10;

          }

          iVar8 = *(int *)(param_1 + 0x278);

          iVar17 = iVar17 + 1;

        } while (iVar17 < iVar8 + -1);

      }

      iVar15 = iVar15 + 1;

    } while (iVar15 < *(int *)(param_1 + 0x27c) + -1);

  }

  return;

}




