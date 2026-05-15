// Address: 0x1400e5690
// Ghidra name: FUN_1400e5690
// ============ 0x1400e5690 FUN_1400e5690 (size=3598) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400e5690(uint *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5)



{

  byte *pbVar1;

  undefined1 *puVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  char *pcVar10;

  longlong lVar11;

  ulonglong uVar12;

  undefined1 *puVar13;

  longlong lVar14;

  undefined1 uVar15;

  byte bVar16;

  ulonglong uVar17;

  uint uVar18;

  uint uVar19;

  ulonglong uVar20;

  uint uVar21;

  char cVar22;

  ulonglong uVar23;

  int iVar24;

  undefined1 *puVar25;

  bool bVar26;

  uint local_4a8;

  uint local_4a4;

  uint local_4a0;

  int local_49c;

  uint local_498;

  int local_494;

  int local_490;

  int local_48c;

  int local_488;

  uint local_480;

  int local_478;

  undefined1 auStack_448 [1032];

  

  pcVar10 = *(char **)(param_1 + 0x2e);

  local_4a4 = 0;

  local_4a8 = 0;

  iVar24 = 0;

  local_4a0 = 0;

  local_498 = 0;

  if (*(char **)(param_1 + 0x30) <= pcVar10) {

    if (param_1[0xc] == 0) goto LAB_1400e647f;

    FUN_1400ed820();

    pcVar10 = *(char **)(param_1 + 0x2e);

  }

  cVar3 = *pcVar10;

  pcVar10 = pcVar10 + 1;

  *(char **)(param_1 + 0x2e) = pcVar10;

  if (cVar3 != 'B') {

LAB_1400e647f:

    _DAT_1403f4c40 = "not BMP";

    return 0;

  }

  if (*(char **)(param_1 + 0x30) <= pcVar10) {

    if (param_1[0xc] == 0) goto LAB_1400e647f;

    FUN_1400ed820(param_1);

    pcVar10 = *(char **)(param_1 + 0x2e);

  }

  cVar3 = *pcVar10;

  *(char **)(param_1 + 0x2e) = pcVar10 + 1;

  if (cVar3 != 'M') goto LAB_1400e647f;

  FUN_1400e8b80(param_1);

  FUN_1400e8b80(param_1);

  FUN_1400e8b80(param_1);

  FUN_1400e8b80(param_1);

  iVar4 = FUN_1400e8b80(param_1);

  iVar5 = FUN_1400e8b80(param_1);

  iVar4 = iVar5 * 0x10000 + iVar4;

  iVar5 = FUN_1400e8b80(param_1);

  iVar6 = FUN_1400e8b80(param_1);

  iVar5 = iVar5 + iVar6 * 0x10000;

  if (iVar5 == 0xc) {

LAB_1400e57fc:

    uVar7 = FUN_1400e8b80(param_1);

    *param_1 = uVar7;

    uVar7 = FUN_1400e8b80(param_1);

  }

  else {

    if (((iVar5 != 0x28) && (iVar5 != 0x38)) && (iVar5 != 0x6c)) {

      _DAT_1403f4c40 = "unknown BMP";

      return 0;

    }

    if (iVar5 == 0xc) goto LAB_1400e57fc;

    iVar6 = FUN_1400e8b80(param_1);

    iVar8 = FUN_1400e8b80(param_1);

    *param_1 = iVar8 * 0x10000 + iVar6;

    iVar6 = FUN_1400e8b80(param_1);

    iVar8 = FUN_1400e8b80(param_1);

    uVar7 = iVar8 * 0x10000 + iVar6;

  }

  param_1[1] = uVar7;

  iVar6 = FUN_1400e8b80(param_1);

  if (iVar6 != 1) goto LAB_1400e6473;

  iVar6 = FUN_1400e8b80(param_1);

  if (iVar6 == 1) {

    _DAT_1403f4c40 = "monochrome";

    return 0;

  }

  uVar7 = param_1[1];

  uVar18 = -uVar7;

  if ((int)-uVar7 < 0) {

    uVar18 = uVar7;

  }

  param_1[1] = uVar18;

  if (iVar5 == 0xc) {

    if (iVar6 < 0x18) {

      iVar24 = (iVar4 + -0x26) / 3;

    }

  }

  else {

    iVar8 = FUN_1400e8c60(param_1);

    if (iVar8 - 1U < 2) {

      _DAT_1403f4c40 = "BMP RLE";

      return 0;

    }

    FUN_1400e8c60(param_1);

    FUN_1400e8c60(param_1);

    FUN_1400e8c60(param_1);

    FUN_1400e8c60(param_1);

    FUN_1400e8c60(param_1);

    if (iVar5 == 0x28) {

LAB_1400e5978:

      if ((iVar6 - 0x10U & 0xffffffef) == 0) {

        if (iVar8 == 0) {

          bVar26 = iVar6 != 0x20;

          local_4a4 = 0xff0000;

          if (bVar26) {

            local_4a4 = 0x7c00;

          }

          local_4a8 = 0xff00;

          if (bVar26) {

            local_4a8 = 0x3e0;

          }

          local_4a0 = 0xff;

          if (bVar26) {

            local_4a0 = 0x1f;

          }

          local_498 = 0xff000000;

          if (bVar26) {

            local_498 = 0;

          }

        }

        else {

          if (iVar8 != 3) {

LAB_1400e6473:

            _DAT_1403f4c40 = "bad BMP";

            return 0;

          }

          local_4a4 = FUN_1400e8c60(param_1);

          local_4a8 = FUN_1400e8c60(param_1);

          local_4a0 = FUN_1400e8c60(param_1);

          if ((local_4a4 == local_4a8) && (local_4a8 == local_4a0)) goto LAB_1400e6473;

        }

      }

    }

    else {

      if (iVar5 == 0x38) {

        FUN_1400e8c60(param_1);

        FUN_1400e8c60(param_1);

        FUN_1400e8c60(param_1);

        FUN_1400e8c60(param_1);

        goto LAB_1400e5978;

      }

      local_4a4 = FUN_1400e8c60(param_1);

      local_4a8 = FUN_1400e8c60(param_1);

      local_4a0 = FUN_1400e8c60(param_1);

      local_498 = FUN_1400e8c60(param_1);

      FUN_1400e8c60(param_1);

      lVar11 = 0xc;

      do {

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        lVar11 = lVar11 + -1;

      } while (lVar11 != 0);

    }

    if (iVar6 < 0x10) {

      iVar24 = (iVar4 - iVar5) + -0xe >> 2;

    }

  }

  uVar18 = (local_498 != 0) + 3;

  param_1[2] = uVar18;

  if (2 < (int)param_5) {

    uVar18 = param_5;

  }

  lVar11 = _malloc_base();

  if (lVar11 == 0) {

    _DAT_1403f4c40 = "outofmem";

    return 0;

  }

  uVar12 = 0;

  cVar3 = '\0';

  if (iVar6 < 0x10) {

    if ((iVar24 == 0) || (0x100 < iVar24)) {

      thunk_FUN_1402e9a80(lVar11);

      _DAT_1403f4c40 = "invalid";

      return 0;

    }

    uVar20 = uVar12;

    if (0 < iVar24) {

      do {

        puVar13 = *(undefined1 **)(param_1 + 0x2e);

        if (puVar13 < *(undefined1 **)(param_1 + 0x30)) {

          uVar15 = *puVar13;

          puVar13 = puVar13 + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        else if (param_1[0xc] == 0) {

          uVar15 = 0;

        }

        else {

          FUN_1400ed820(param_1);

          uVar15 = **(undefined1 **)(param_1 + 0x2e);

          puVar13 = *(undefined1 **)(param_1 + 0x2e) + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        auStack_448[uVar20 * 4 + 2] = uVar15;

        if (puVar13 < *(undefined1 **)(param_1 + 0x30)) {

          uVar15 = *puVar13;

          puVar13 = puVar13 + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        else if (param_1[0xc] == 0) {

          uVar15 = 0;

        }

        else {

          FUN_1400ed820(param_1);

          uVar15 = **(undefined1 **)(param_1 + 0x2e);

          puVar13 = *(undefined1 **)(param_1 + 0x2e) + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        auStack_448[uVar20 * 4 + 1] = uVar15;

        if (puVar13 < *(undefined1 **)(param_1 + 0x30)) {

          uVar15 = *puVar13;

          puVar13 = puVar13 + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        else if (param_1[0xc] == 0) {

          uVar15 = 0;

        }

        else {

          FUN_1400ed820(param_1);

          uVar15 = **(undefined1 **)(param_1 + 0x2e);

          puVar13 = *(undefined1 **)(param_1 + 0x2e) + 1;

          *(undefined1 **)(param_1 + 0x2e) = puVar13;

        }

        auStack_448[uVar20 * 4] = uVar15;

        if (iVar5 != 0xc) {

          if (puVar13 < *(undefined1 **)(param_1 + 0x30)) {

            *(undefined1 **)(param_1 + 0x2e) = puVar13 + 1;

          }

          else if (param_1[0xc] != 0) {

            FUN_1400ed820();

            *(longlong *)(param_1 + 0x2e) = *(longlong *)(param_1 + 0x2e) + 1;

          }

        }

        auStack_448[uVar20 * 4 + 3] = 0xff;

        uVar20 = uVar20 + 1;

      } while ((longlong)uVar20 < (longlong)iVar24);

    }

    FUN_1400ed890(param_1,((iVar4 - ((iVar5 != 0xc) + 3) * iVar24) - iVar5) + -0xe);

    if (iVar6 == 4) {

      uVar19 = *param_1 + 1 >> 1;

    }

    else {

      if (iVar6 != 8) {

        thunk_FUN_1402e9a80(lVar11);

        _DAT_1403f4c40 = "bad bpp";

        return 0;

      }

      uVar19 = *param_1;

    }

    uVar21 = param_1[1];

    uVar19 = -uVar19 & 3;

    iVar24 = 0;

    if (0 < (int)uVar21) {

      do {

        iVar4 = 0;

        if (0 < (int)*param_1) {

          do {

            pbVar1 = *(byte **)(param_1 + 0x2e);

            if (pbVar1 < *(byte **)(param_1 + 0x30)) {

              uVar21 = (uint)*pbVar1;

              *(byte **)(param_1 + 0x2e) = pbVar1 + 1;

            }

            else if (param_1[0xc] == 0) {

              uVar21 = 0;

            }

            else {

              FUN_1400ed820(param_1);

              uVar21 = (uint)**(byte **)(param_1 + 0x2e);

              *(byte **)(param_1 + 0x2e) = *(byte **)(param_1 + 0x2e) + 1;

            }

            uVar9 = uVar21;

            if (iVar6 == 4) {

              uVar9 = uVar21 >> 4;

            }

            lVar14 = (ulonglong)uVar9 * 4;

            iVar5 = (int)uVar12;

            uVar20 = (ulonglong)(uVar21 & 0xf);

            if (iVar6 != 4) {

              uVar20 = 0;

            }

            *(undefined1 *)(iVar5 + lVar11) = auStack_448[lVar14];

            uVar21 = iVar5 + 3;

            *(undefined1 *)((longlong)iVar5 + 1 + lVar11) = auStack_448[lVar14 + 1];

            *(undefined1 *)((iVar5 + 2) + lVar11) = auStack_448[lVar14 + 2];

            if (uVar18 == 4) {

              lVar14 = (longlong)(int)uVar21;

              uVar21 = iVar5 + 4;

              *(undefined1 *)(lVar14 + lVar11) = 0xff;

            }

            uVar12 = (ulonglong)uVar21;

            if (iVar4 + 1U == *param_1) break;

            if (iVar6 == 8) {

              pbVar1 = *(byte **)(param_1 + 0x2e);

              if (pbVar1 < *(byte **)(param_1 + 0x30)) {

                uVar20 = (ulonglong)*pbVar1;

                *(byte **)(param_1 + 0x2e) = pbVar1 + 1;

              }

              else if (param_1[0xc] == 0) {

                uVar20 = 0;

              }

              else {

                FUN_1400ed820(param_1);

                uVar20 = (ulonglong)**(byte **)(param_1 + 0x2e);

                *(byte **)(param_1 + 0x2e) = *(byte **)(param_1 + 0x2e) + 1;

              }

            }

            lVar14 = uVar20 * 4;

            *(undefined1 *)((int)uVar21 + lVar11) = auStack_448[lVar14];

            uVar9 = uVar21 + 3;

            *(undefined1 *)((longlong)(int)uVar21 + 1 + lVar11) = auStack_448[lVar14 + 1];

            *(undefined1 *)((int)(uVar21 + 2) + lVar11) = auStack_448[lVar14 + 2];

            if (uVar18 == 4) {

              lVar14 = (longlong)(int)uVar9;

              uVar9 = uVar21 + 4;

              *(undefined1 *)(lVar14 + lVar11) = 0xff;

            }

            uVar12 = (ulonglong)uVar9;

            iVar4 = iVar4 + 2;

          } while (iVar4 < (int)*param_1);

        }

        if ((*(longlong *)(param_1 + 4) == 0) ||

           (uVar21 = param_1[0x2e], (int)uVar19 <= (int)(param_1[0x30] - uVar21))) {

          *(ulonglong *)(param_1 + 0x2e) = *(longlong *)(param_1 + 0x2e) + (ulonglong)uVar19;

        }

        else {

          *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x30);

          (**(code **)(param_1 + 6))

                    (*(undefined8 *)(param_1 + 10),uVar19 - (param_1[0x30] - uVar21));

        }

        uVar21 = param_1[1];

        iVar24 = iVar24 + 1;

      } while (iVar24 < (int)uVar21);

    }

    goto LAB_1400e637d;

  }

  local_494 = 0;

  local_490 = 0;

  local_48c = 0;

  uVar20 = 0;

  local_488 = 0;

  FUN_1400ed890(param_1,(iVar4 - iVar5) + -0xe);

  if (iVar6 == 0x18) {

    iVar24 = 1;

    local_480 = *param_1 & 3;

    local_49c = 1;

    uVar20 = uVar12;

    cVar22 = cVar3;

  }

  else {

    if (iVar6 == 0x10) {

      uVar21 = *param_1 * -2 & 3;

LAB_1400e5eb6:

      if (((local_4a4 == 0) || (local_4a8 == 0)) || (local_480 = uVar21, local_4a0 == 0)) {

        thunk_FUN_1402e9a80(lVar11);

        _DAT_1403f4c40 = "bad masks";

        return 0;

      }

    }

    else {

      local_480 = 0;

      uVar21 = 0;

      if (((iVar6 != 0x20) || (uVar21 = 0, local_4a0 != 0xff)) ||

         ((uVar21 = 0, local_4a8 != 0xff00 || (uVar21 = 0, local_4a4 != 0xff0000))))

      goto LAB_1400e5eb6;

      if (local_498 == 0xff000000) {

        iVar24 = 2;

        local_480 = 0;

        local_49c = 2;

        cVar3 = '\0';

        cVar22 = '\0';

        goto LAB_1400e5fe4;

      }

    }

    local_49c = 0;

    uVar23 = (ulonglong)local_4a8;

    uVar17 = (ulonglong)local_498;

    local_494 = FUN_1400e99f0(local_4a4);

    local_494 = local_494 + -7;

    uVar21 = (local_4a4 >> 1 & 0x55555555) + (local_4a4 & 0x55555555);

    uVar21 = (uVar21 >> 2 & 0x33333333) + (uVar21 & 0x33333333);

    uVar21 = (uVar21 >> 4) + uVar21 & 0xf0f0f0f;

    uVar21 = uVar21 + (uVar21 >> 8);

    uVar20 = (ulonglong)((uVar21 >> 0x10) + uVar21 & 0xff);

    iVar24 = local_494;

    local_490 = FUN_1400e99f0(uVar23 & 0xffffffff);

    cVar3 = (char)iVar24;

    local_490 = local_490 + -7;

    iVar24 = local_490;

    local_48c = FUN_1400e99f0(local_4a0);

    cVar22 = (char)iVar24;

    local_48c = local_48c + -7;

    local_488 = FUN_1400e99f0(uVar17 & 0xffffffff);

    iVar24 = 0;

    local_488 = local_488 + -7;

  }

LAB_1400e5fe4:

  uVar21 = param_1[1];

  local_478 = 0;

  if (0 < (int)uVar21) {

    do {

      iVar4 = 0;

      if (iVar24 == 0) {

        if (0 < (int)*param_1) {

          puVar13 = (undefined1 *)((int)uVar12 + lVar11);

          do {

            uVar21 = FUN_1400e8b80(param_1);

            if (iVar6 != 0x10) {

              iVar24 = FUN_1400e8b80(param_1);

              uVar21 = iVar24 * 0x10000 + uVar21;

            }

            if (local_494 < 0) {

              iVar24 = (uVar21 & local_4a4) << (-cVar3 & 0x1fU);

            }

            else {

              iVar24 = (int)(uVar21 & local_4a4) >> ((byte)local_494 & 0x1f);

            }

            uVar15 = (undefined1)iVar24;

            uVar19 = (uint)uVar20;

            uVar17 = uVar20;

            iVar5 = iVar24;

            if (uVar19 < 8) {

              do {

                uVar9 = (int)uVar17 + uVar19;

                iVar5 = iVar5 + (iVar24 >> ((byte)uVar17 & 0x1f));

                uVar15 = (undefined1)iVar5;

                uVar17 = (ulonglong)uVar9;

              } while ((int)uVar9 < 8);

            }

            *puVar13 = uVar15;

            if (local_490 < 0) {

              iVar24 = (uVar21 & local_4a8) << (-cVar22 & 0x1fU);

            }

            else {

              iVar24 = (int)(uVar21 & local_4a8) >> ((byte)local_490 & 0x1f);

            }

            uVar15 = (undefined1)iVar24;

            uVar17 = uVar20;

            iVar5 = iVar24;

            if (uVar19 < 8) {

              do {

                bVar16 = (byte)uVar17;

                uVar9 = (int)uVar17 + uVar19;

                uVar17 = (ulonglong)uVar9;

                iVar5 = iVar5 + (iVar24 >> (bVar16 & 0x1f));

                uVar15 = (undefined1)iVar5;

              } while ((int)uVar9 < 8);

            }

            puVar13[1] = uVar15;

            if (local_48c < 0) {

              iVar24 = (uVar21 & local_4a0) << (-(byte)local_48c & 0x1f);

            }

            else {

              iVar24 = (int)(uVar21 & local_4a0) >> ((byte)local_48c & 0x1f);

            }

            uVar15 = (undefined1)iVar24;

            uVar17 = uVar20;

            iVar5 = iVar24;

            if (uVar19 < 8) {

              do {

                uVar9 = (int)uVar17 + uVar19;

                iVar5 = iVar5 + (iVar24 >> ((byte)uVar17 & 0x1f));

                uVar15 = (undefined1)iVar5;

                uVar17 = (ulonglong)uVar9;

              } while ((int)uVar9 < 8);

            }

            puVar13[2] = uVar15;

            uVar9 = (int)uVar12 + 3;

            puVar25 = puVar13 + 3;

            if (local_498 == 0) {

              iVar24 = 0xff;

            }

            else {

              if (local_488 < 0) {

                iVar5 = (uVar21 & local_498) << (-(byte)local_488 & 0x1f);

              }

              else {

                iVar5 = (int)(uVar21 & local_498) >> ((byte)local_488 & 0x1f);

              }

              uVar17 = uVar20;

              iVar24 = iVar5;

              if (uVar19 < 8) {

                do {

                  uVar21 = (int)uVar17 + uVar19;

                  iVar24 = iVar24 + (iVar5 >> ((byte)uVar17 & 0x1f));

                  uVar17 = (ulonglong)uVar21;

                } while ((int)uVar21 < 8);

              }

            }

            if (uVar18 == 4) {

              uVar9 = (int)uVar12 + 4;

              *puVar25 = (char)iVar24;

              puVar25 = puVar13 + 4;

            }

            uVar12 = (ulonglong)uVar9;

            iVar4 = iVar4 + 1;

            puVar13 = puVar25;

          } while (iVar4 < (int)*param_1);

        }

      }

      else if (0 < (int)*param_1) {

        puVar13 = (undefined1 *)((int)uVar12 + lVar11);

        do {

          puVar25 = *(undefined1 **)(param_1 + 0x2e);

          if (puVar25 < *(undefined1 **)(param_1 + 0x30)) {

            uVar15 = *puVar25;

            *(undefined1 **)(param_1 + 0x2e) = puVar25 + 1;

          }

          else if (param_1[0xc] == 0) {

            uVar15 = 0;

          }

          else {

            FUN_1400ed820(param_1);

            uVar15 = **(undefined1 **)(param_1 + 0x2e);

            *(undefined1 **)(param_1 + 0x2e) = *(undefined1 **)(param_1 + 0x2e) + 1;

          }

          puVar13[2] = uVar15;

          puVar25 = *(undefined1 **)(param_1 + 0x2e);

          if (puVar25 < *(undefined1 **)(param_1 + 0x30)) {

            uVar15 = *puVar25;

            *(undefined1 **)(param_1 + 0x2e) = puVar25 + 1;

          }

          else if (param_1[0xc] == 0) {

            uVar15 = 0;

          }

          else {

            FUN_1400ed820(param_1);

            uVar15 = **(undefined1 **)(param_1 + 0x2e);

            *(undefined1 **)(param_1 + 0x2e) = *(undefined1 **)(param_1 + 0x2e) + 1;

          }

          puVar13[1] = uVar15;

          puVar25 = *(undefined1 **)(param_1 + 0x2e);

          if (puVar25 < *(undefined1 **)(param_1 + 0x30)) {

            uVar15 = *puVar25;

            *(undefined1 **)(param_1 + 0x2e) = puVar25 + 1;

          }

          else if (param_1[0xc] == 0) {

            uVar15 = 0;

          }

          else {

            FUN_1400ed820(param_1);

            uVar15 = **(undefined1 **)(param_1 + 0x2e);

            *(undefined1 **)(param_1 + 0x2e) = *(undefined1 **)(param_1 + 0x2e) + 1;

          }

          *puVar13 = uVar15;

          uVar21 = (int)uVar12 + 3;

          puVar25 = puVar13 + 3;

          if (local_49c == 2) {

            puVar2 = *(undefined1 **)(param_1 + 0x2e);

            if (puVar2 < *(undefined1 **)(param_1 + 0x30)) {

              uVar15 = *puVar2;

              *(undefined1 **)(param_1 + 0x2e) = puVar2 + 1;

            }

            else if (param_1[0xc] == 0) {

              uVar15 = 0;

            }

            else {

              FUN_1400ed820(param_1);

              uVar15 = **(undefined1 **)(param_1 + 0x2e);

              *(undefined1 **)(param_1 + 0x2e) = *(undefined1 **)(param_1 + 0x2e) + 1;

            }

          }

          else {

            uVar15 = 0xff;

          }

          if (uVar18 == 4) {

            uVar21 = (int)uVar12 + 4;

            *puVar25 = uVar15;

            puVar25 = puVar13 + 4;

          }

          uVar12 = (ulonglong)uVar21;

          iVar4 = iVar4 + 1;

          puVar13 = puVar25;

        } while (iVar4 < (int)*param_1);

      }

      if ((*(longlong *)(param_1 + 4) == 0) ||

         (uVar21 = param_1[0x2e], (int)local_480 <= (int)(param_1[0x30] - uVar21))) {

        *(ulonglong *)(param_1 + 0x2e) = *(longlong *)(param_1 + 0x2e) + (ulonglong)local_480;

      }

      else {

        *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x30);

        (**(code **)(param_1 + 6))

                  (*(undefined8 *)(param_1 + 10),local_480 - (param_1[0x30] - uVar21));

      }

      uVar21 = param_1[1];

      local_478 = local_478 + 1;

      iVar24 = local_49c;

    } while (local_478 < (int)uVar21);

  }

LAB_1400e637d:

  if ((0 < (int)uVar7) && (uVar7 = 0, (uVar21 & 0xfffffffe) != 0 && -1 < (int)uVar21)) {

    do {

      uVar19 = *param_1;

      puVar13 = (undefined1 *)((ulonglong)((uVar21 + ~uVar7) * uVar19 * uVar18) + lVar11);

      if (0 < (int)(uVar19 * uVar18)) {

        lVar14 = ((ulonglong)(uVar19 * uVar7 * uVar18) + lVar11) - (longlong)puVar13;

        uVar21 = 0;

        do {

          uVar21 = uVar21 + 1;

          uVar15 = puVar13[lVar14];

          puVar13[lVar14] = *puVar13;

          *puVar13 = uVar15;

          puVar13 = puVar13 + 1;

        } while ((int)uVar21 < (int)(uVar18 * *param_1));

      }

      uVar21 = param_1[1];

      uVar7 = uVar7 + 1;

    } while ((int)uVar7 < (int)uVar21 >> 1);

  }

  if (((param_5 != 0) && (param_5 != uVar18)) &&

     (lVar11 = FUN_1400e6f80(lVar11,uVar18,param_5,*param_1,uVar21), lVar11 == 0)) {

    return 0;

  }

  *param_2 = *param_1;

  *param_3 = param_1[1];

  if (param_4 != (uint *)0x0) {

    *param_4 = param_1[2];

    return lVar11;

  }

  return lVar11;

}




