// Address: 0x1400efab0
// Ghidra name: FUN_1400efab0
// ============ 0x1400efab0 FUN_1400efab0 (size=1941) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 * FUN_1400efab0(longlong param_1,int *param_2,int *param_3,uint *param_4,uint param_5)



{

  int *piVar1;

  bool bVar2;

  undefined4 uVar3;

  int iVar4;

  uint uVar5;

  byte *pbVar6;

  undefined1 *puVar7;

  longlong lVar8;

  undefined1 *puVar9;

  byte bVar10;

  undefined1 uVar11;

  uint uVar12;

  ulonglong uVar13;

  uint uVar14;

  uint uVar15;

  byte bVar16;

  undefined4 *puVar17;

  int iVar18;

  uint uVar19;

  int iVar20;

  int iVar21;

  uint uVar22;

  byte bVar23;

  byte bVar24;

  int iVar25;

  byte local_res8;

  byte local_98;

  byte local_97;

  undefined4 local_94;

  uint local_8c;

  longlong local_88;

  uint local_80;

  int local_7c;

  int local_78;

  int local_74;

  int *local_70;

  undefined1 *local_68;

  uint local_60;

  int local_5c;

  longlong local_58;

  longlong local_50;

  undefined1 *local_48;

  longlong local_40;

  ulonglong local_38;

  

  pbVar6 = *(byte **)(param_1 + 0xb8);

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    pbVar6 = pbVar6 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  else if (*(int *)(param_1 + 0x30) != 0) {

    FUN_1400ed820();

    pbVar6 = (byte *)(*(longlong *)(param_1 + 0xb8) + 1);

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  piVar1 = (int *)(param_1 + 0x30);

  local_70 = piVar1;

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    local_97 = *pbVar6;

    pbVar6 = pbVar6 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  else if (*piVar1 == 0) {

    local_97 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    local_97 = **(byte **)(param_1 + 0xb8);

    pbVar6 = *(byte **)(param_1 + 0xb8) + 1;

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    bVar10 = *pbVar6;

    *(byte **)(param_1 + 0xb8) = pbVar6 + 1;

  }

  else if (*piVar1 == 0) {

    bVar10 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    bVar10 = **(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

  }

  local_80 = (uint)bVar10;

  uVar3 = FUN_1400e8b80(param_1);

  local_7c = FUN_1400e8b80(param_1);

  pbVar6 = *(byte **)(param_1 + 0xb8);

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    bVar10 = *pbVar6;

    *(byte **)(param_1 + 0xb8) = pbVar6 + 1;

  }

  else if (*piVar1 == 0) {

    bVar10 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    bVar10 = **(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

  }

  FUN_1400e8b80(param_1);

  FUN_1400e8b80(param_1);

  local_78 = FUN_1400e8b80(param_1);

  local_74 = FUN_1400e8b80();

  pbVar6 = *(byte **)(param_1 + 0xb8);

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    uVar15 = (uint)*pbVar6;

    pbVar6 = pbVar6 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  else if (*piVar1 == 0) {

    uVar15 = 0;

  }

  else {

    FUN_1400ed820();

    uVar15 = (uint)**(byte **)(param_1 + 0xb8);

    pbVar6 = *(byte **)(param_1 + 0xb8) + 1;

    *(byte **)(param_1 + 0xb8) = pbVar6;

  }

  if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

    uVar13 = (ulonglong)*pbVar6;

    *(byte **)(param_1 + 0xb8) = pbVar6 + 1;

  }

  else if (*local_70 == 0) {

    uVar13 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    uVar13 = (ulonglong)**(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

  }

  local_40 = 0;

  local_8c = 0;

  uVar12 = local_80 - 8;

  if (local_80 < 8) {

    uVar12 = local_80;

  }

  local_5c = 1 - ((uint)(uVar13 >> 5) & 1);

  if ((((0 < local_78) && (0 < local_74)) && (uVar12 - 1 < 3)) && ((uVar15 - 8 & 0xe7) == 0)) {

    *param_2 = local_78;

    *param_3 = local_74;

    uVar12 = (uint)bVar10;

    if (local_97 == 0) {

      uVar12 = uVar15;

    }

    local_60 = uVar12 >> 3;

    *param_4 = local_60;

    if (3 < param_5 - 1) {

      param_5 = local_60;

    }

    uVar15 = local_74 * local_78;

    puVar7 = (undefined1 *)_malloc_base((longlong)(int)(uVar15 * param_5));

    if (puVar7 != (undefined1 *)0x0) {

      local_68 = puVar7;

      FUN_1400ed890();

      if (local_97 == 0) {

LAB_1400efe0b:

        bVar10 = 0;

        uVar14 = 0;

        uVar22 = 0;

        local_98 = 0;

        bVar23 = 0;

        local_res8 = 0;

        uVar5 = 0;

        if (0 < (int)uVar15) {

          bVar2 = true;

          local_38 = (ulonglong)uVar15;

          local_48 = local_68;

          local_50 = 0;

          local_88 = 0;

          local_58 = 0;

          puVar7 = local_68;

          uVar15 = local_94;

          bVar16 = local_94._1_1_;

          uVar19 = uVar5;

          do {

            iVar4 = 0;

            if (local_80 < 8) {

LAB_1400efee0:

              piVar1 = local_70;

              if (local_97 == 0) {

                if (uVar12 != 0) {

                  puVar17 = &local_94;

                  do {

                    puVar7 = *(undefined1 **)(param_1 + 0xb8);

                    if (puVar7 < *(undefined1 **)(param_1 + 0xc0)) {

                      uVar11 = *puVar7;

                      *(undefined1 **)(param_1 + 0xb8) = puVar7 + 1;

                    }

                    else if (*piVar1 == 0) {

                      uVar11 = 0;

                    }

                    else {

                      FUN_1400ed820(param_1);

                      uVar11 = **(undefined1 **)(param_1 + 0xb8);

                      *(undefined1 **)(param_1 + 0xb8) = *(undefined1 **)(param_1 + 0xb8) + 1;

                    }

                    *(undefined1 *)puVar17 = uVar11;

                    iVar4 = iVar4 + 8;

                    puVar17 = (undefined4 *)((longlong)puVar17 + 1);

                  } while (iVar4 < (int)uVar12);

                  goto LAB_1400effe5;

                }

              }

              else {

                pbVar6 = *(byte **)(param_1 + 0xb8);

                if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

                  bVar10 = *pbVar6;

                  *(byte **)(param_1 + 0xb8) = pbVar6 + 1;

                }

                else if (*local_70 == 0) {

                  bVar10 = 0;

                }

                else {

                  FUN_1400ed820(param_1);

                  bVar10 = **(byte **)(param_1 + 0xb8);

                  *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                }

                uVar14 = 0;

                if ((int)(uint)bVar10 < local_7c) {

                  uVar14 = (uint)bVar10;

                }

                if (uVar12 != 0) {

                  puVar17 = &local_94;

                  puVar7 = (undefined1 *)((ulonglong)(uVar14 * local_60) + local_40);

                  do {

                    iVar4 = iVar4 + 8;

                    *(undefined1 *)puVar17 = *puVar7;

                    puVar17 = (undefined4 *)((longlong)puVar17 + 1);

                    puVar7 = puVar7 + 1;

                  } while (iVar4 < (int)uVar12);

LAB_1400effe5:

                  uVar15 = local_94;

                  bVar16 = local_94._1_1_;

                }

              }

              bVar24 = (byte)uVar15;

              if (uVar12 == 8) {

                local_98 = 0xff;

                uVar14 = uVar15 & 0xff;

                uVar22 = uVar15 & 0xff;

                local_res8 = bVar24;

              }

              else if (uVar12 == 0x10) {

                uVar14 = uVar15 & 0xff;

                uVar22 = uVar15 & 0xff;

                local_res8 = bVar24;

                local_98 = bVar16;

              }

              else {

                bVar24 = local_94._2_1_;

                if (uVar12 == 0x18) {

                  uVar14 = (uint)bVar16;

                  local_98 = 0xff;

                  uVar22 = uVar15 & 0xff;

                  local_res8 = bVar16;

                }

                else if (uVar12 == 0x20) {

                  uVar14 = (uint)bVar16;

                  uVar22 = uVar15 & 0xff;

                  local_98 = local_94._3_1_;

                  local_res8 = bVar16;

                }

                else {

                  uVar14 = (uint)local_res8;

                  bVar24 = bVar23;

                }

              }

              bVar2 = false;

              puVar7 = local_68;

              bVar10 = local_98;

              bVar23 = bVar24;

              uVar19 = local_8c;

            }

            else {

              if (uVar19 == 0) {

                pbVar6 = *(byte **)(param_1 + 0xb8);

                if (pbVar6 < *(byte **)(param_1 + 0xc0)) {

                  uVar5 = (uint)*pbVar6;

                  *(byte **)(param_1 + 0xb8) = pbVar6 + 1;

                }

                else if (*local_70 == 0) {

                  uVar5 = 0;

                }

                else {

                  FUN_1400ed820(param_1);

                  uVar5 = (uint)**(byte **)(param_1 + 0xb8);

                  *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                }

                local_8c = (uVar5 & 0x7f) + 1;

                uVar5 = uVar5 >> 7;

                goto LAB_1400efee0;

              }

              if ((uVar5 == 0) || (bVar2)) goto LAB_1400efee0;

            }

            if (param_5 == 1) {

              *local_48 = (char)(uVar14 * 0x96 + (uint)bVar23 * 0x4d + uVar22 * 0x1d >> 8);

            }

            else if (param_5 == 2) {

              puVar7[local_50 + 1] = bVar10;

              puVar7[local_50] = (char)(uVar14 * 0x96 + (uint)bVar23 * 0x4d + uVar22 * 0x1d >> 8);

            }

            else if (param_5 == 3) {

              puVar7[local_88] = bVar23;

              puVar7[local_88 + 1] = (char)uVar14;

              puVar7[local_88 + 2] = (char)uVar22;

            }

            else if (param_5 == 4) {

              puVar7[local_58] = bVar23;

              puVar7[local_58 + 1] = (char)uVar14;

              puVar7[local_58 + 2] = (char)uVar22;

              puVar7[local_58 + 3] = bVar10;

            }

            local_58 = local_58 + 4;

            local_8c = uVar19 - 1;

            local_50 = local_50 + 2;

            local_88 = local_88 + 3;

            local_48 = local_48 + 1;

            local_38 = local_38 - 1;

            uVar14 = (uint)local_res8;

            uVar19 = local_8c;

          } while (local_38 != 0);

        }

        puVar7 = local_68;

        iVar4 = 0;

        if (local_5c != 0) {

          iVar21 = local_78 * param_5;

          iVar20 = (local_74 + -1) * local_78 * param_5;

          iVar25 = iVar4;

          do {

            if (0 < iVar21) {

              lVar8 = (longlong)iVar20 - (longlong)iVar4;

              puVar9 = local_68 + iVar4;

              iVar18 = iVar21;

              do {

                iVar18 = iVar18 + -1;

                uVar11 = *puVar9;

                *puVar9 = puVar9[lVar8];

                puVar9[lVar8] = uVar11;

                puVar9 = puVar9 + 1;

              } while (0 < iVar18);

            }

            iVar4 = iVar4 + iVar21;

            iVar20 = iVar20 - iVar21;

            iVar25 = iVar25 + 2;

          } while (iVar25 < local_74);

        }

        if (local_40 != 0) {

          thunk_FUN_1402e9a80(local_40);

          return puVar7;

        }

        return local_68;

      }

      FUN_1400ed890(param_1,uVar3);

      iVar4 = (int)((uint)bVar10 * local_7c + ((int)((uint)bVar10 * local_7c) >> 0x1f & 7U)) >> 3;

      lVar8 = _malloc_base((longlong)iVar4);

      if (lVar8 != 0) {

        local_40 = lVar8;

        iVar4 = FUN_1400e8d60(param_1,lVar8,iVar4);

        if (iVar4 == 0) {

          thunk_FUN_1402e9a80(puVar7);

          thunk_FUN_1402e9a80(lVar8);

          _DAT_1403f4c40 = "bad palette";

          return (undefined1 *)0x0;

        }

        goto LAB_1400efe0b;

      }

    }

    _DAT_1403f4c40 = "outofmem";

  }

  return (undefined1 *)0x0;

}




