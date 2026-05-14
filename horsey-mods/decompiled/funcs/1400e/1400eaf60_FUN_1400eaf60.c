// Address: 0x1400eaf60
// Ghidra name: FUN_1400eaf60
// ============ 0x1400eaf60 FUN_1400eaf60 (size=2956) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400eaf60(undefined8 *param_1,int param_2,uint param_3)



{

  uint *puVar1;

  int *piVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  byte bVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  longlong lVar10;

  undefined1 uVar11;

  uint uVar12;

  char *pcVar13;

  ulonglong uVar14;

  uint uVar15;

  undefined1 *puVar16;

  ulonglong uVar17;

  uint uVar18;

  uint uVar19;

  byte *pbVar20;

  byte bVar21;

  uint uVar22;

  byte local_res8;

  char local_1464 [4];

  int local_1460;

  int local_145c;

  undefined8 local_1458;

  undefined1 auStack_1448 [1024];

  longlong local_1048;

  longlong local_1040;

  longlong local_1030;

  longlong local_1028;

  longlong local_1020;

  undefined4 local_1018;

  undefined8 uStack_48;

  

  uStack_48 = 0x1400eaf87;

  local_res8 = 0;

  uVar15 = 0;

  bVar3 = true;

  local_1460 = 0;

  local_145c = 0;

  puVar1 = (uint *)*param_1;

  param_1[2] = 0;

  param_1[1] = 0;

  param_1[3] = 0;

  bVar4 = false;

  iVar7 = FUN_1400e6900(puVar1);

  if (iVar7 == 0) {

    return 0;

  }

  uVar19 = uVar15;

  uVar22 = uVar15;

  if (param_2 == 1) {

    return 1;

  }

  do {

    iVar7 = FUN_1400e8ad0(puVar1);

    iVar8 = FUN_1400e8ad0(puVar1);

    uVar18 = iVar7 * 0x10000 + iVar8;

    iVar8 = FUN_1400e8ad0(puVar1);

    iVar9 = FUN_1400e8ad0(puVar1);

    iVar7 = local_1460;

    uVar12 = iVar9 + iVar8 * 0x10000;

    local_1458 = CONCAT44(uVar12,uVar18);

    if (uVar12 < 0x49484453) {

      if (uVar12 == 0x49484452) {

        if (!bVar3) {

          _DAT_1403f4c40 = "multiple IHDR";

          return 0;

        }

        uVar19 = 0;

        bVar3 = false;

        if (uVar18 != 0xd) {

          _DAT_1403f4c40 = "bad IHDR len";

          return 0;

        }

        iVar7 = FUN_1400e8ad0(puVar1);

        iVar8 = FUN_1400e8ad0(puVar1);

        uVar12 = iVar8 + iVar7 * 0x10000;

        *puVar1 = uVar12;

        if (0x1000000 < uVar12) {

LAB_1400eb3ae:

          _DAT_1403f4c40 = "too large";

          return 0;

        }

        iVar7 = FUN_1400e8ad0(puVar1);

        iVar8 = FUN_1400e8ad0(puVar1);

        uVar12 = iVar8 + iVar7 * 0x10000;

        puVar1[1] = uVar12;

        if (0x1000000 < uVar12) goto LAB_1400eb3ae;

        pcVar13 = *(char **)(puVar1 + 0x2e);

        if (pcVar13 < *(char **)(puVar1 + 0x30)) {

          cVar5 = *pcVar13;

        }

        else {

          if (puVar1[0xc] == 0) goto LAB_1400eba44;

          FUN_1400ed820(puVar1);

          pcVar13 = *(char **)(puVar1 + 0x2e);

          cVar5 = *pcVar13;

        }

        pbVar20 = (byte *)(pcVar13 + 1);

        *(byte **)(puVar1 + 0x2e) = pbVar20;

        if (cVar5 != '\b') {

LAB_1400eba44:

          _DAT_1403f4c40 = "8bit only";

          return 0;

        }

        if (pbVar20 < *(byte **)(puVar1 + 0x30)) {

          bVar21 = *pbVar20;

          pbVar20 = (byte *)(pcVar13 + 2);

LAB_1400eb254:

          uVar17 = (ulonglong)bVar21;

          *(byte **)(puVar1 + 0x2e) = pbVar20;

          if (6 < bVar21) {

LAB_1400eb278:

            _DAT_1403f4c40 = "bad ctype";

            return 0;

          }

          if (bVar21 == 3) {

            local_res8 = 3;

          }

          else if ((bVar21 & 1) != 0) goto LAB_1400eb278;

        }

        else {

          if (puVar1[0xc] != 0) {

            FUN_1400ed820(puVar1);

            bVar21 = **(byte **)(puVar1 + 0x2e);

            pbVar20 = *(byte **)(puVar1 + 0x2e) + 1;

            goto LAB_1400eb254;

          }

          uVar17 = 0;

        }

        if (pbVar20 < *(byte **)(puVar1 + 0x30)) {

          bVar21 = *pbVar20;

LAB_1400eb2bb:

          pbVar20 = pbVar20 + 1;

          *(byte **)(puVar1 + 0x2e) = pbVar20;

          if (bVar21 != 0) {

            _DAT_1403f4c40 = "bad comp method";

            return 0;

          }

        }

        else if (puVar1[0xc] != 0) {

          FUN_1400ed820(puVar1);

          pbVar20 = *(byte **)(puVar1 + 0x2e);

          bVar21 = *pbVar20;

          goto LAB_1400eb2bb;

        }

        if (pbVar20 < *(byte **)(puVar1 + 0x30)) {

          bVar21 = *pbVar20;

LAB_1400eb2f7:

          pbVar20 = pbVar20 + 1;

          *(byte **)(puVar1 + 0x2e) = pbVar20;

          if (bVar21 != 0) {

            _DAT_1403f4c40 = "bad filter method";

            return 0;

          }

        }

        else if (puVar1[0xc] != 0) {

          FUN_1400ed820(puVar1);

          pbVar20 = *(byte **)(puVar1 + 0x2e);

          bVar21 = *pbVar20;

          goto LAB_1400eb2f7;

        }

        if (pbVar20 < *(byte **)(puVar1 + 0x30)) {

          bVar21 = *pbVar20;

LAB_1400eb333:

          uVar19 = (uint)bVar21;

          *(byte **)(puVar1 + 0x2e) = pbVar20 + 1;

          if (1 < bVar21) {

            _DAT_1403f4c40 = "bad interlace method";

            return 0;

          }

        }

        else if (puVar1[0xc] != 0) {

          FUN_1400ed820(puVar1);

          pbVar20 = *(byte **)(puVar1 + 0x2e);

          bVar21 = *pbVar20;

          goto LAB_1400eb333;

        }

        if ((*puVar1 == 0) || (uVar12 = puVar1[1], uVar12 == 0)) {

          _DAT_1403f4c40 = "0-pixel image";

          return 0;

        }

        uVar14 = 0x40000000 / (ulonglong)*puVar1;

        if (local_res8 == 0) {

          uVar18 = ((uint)(uVar17 >> 2) & 1) + ((uint)uVar17 & 2 | 1);

          puVar1[2] = uVar18;

          if ((uint)(uVar14 / uVar18) < uVar12) goto LAB_1400eb3ae;

          if (param_2 == 2) {

            return 1;

          }

        }

        else {

          puVar1[2] = 1;

          if ((uint)(uVar14 >> 2) < uVar12) goto LAB_1400eb3ae;

        }

      }

      else if (uVar12 == 0x43674249) {

        local_145c = DAT_1403f4c4c;

        if ((*(longlong *)(puVar1 + 4) == 0) || ((int)uVar18 <= (int)(puVar1[0x30] - puVar1[0x2e])))

        {

          *(longlong *)(puVar1 + 0x2e) = *(longlong *)(puVar1 + 0x2e) + (longlong)(int)uVar18;

        }

        else {

          *(undefined8 *)(puVar1 + 0x2e) = *(undefined8 *)(puVar1 + 0x30);

          (**(code **)(puVar1 + 6))(*(undefined8 *)(puVar1 + 10));

        }

      }

      else {

        if (uVar12 != 0x49444154) {

          if (uVar12 != 0x49454e44) goto LAB_1400eb3ce;

          if (bVar3) goto LAB_1400ebacd;

          if (param_2 != 0) {

            return 1;

          }

          lVar10 = param_1[1];

          if (lVar10 == 0) {

            _DAT_1403f4c40 = "no IDAT";

            return 0;

          }

          local_1030 = _malloc_base(0x4000);

          iVar7 = local_145c;

          if (local_1030 == 0) {

            param_1[2] = 0;

            return 0;

          }

          local_1040 = local_1460 + lVar10;

          local_1020 = local_1030 + 0x4000;

          local_1018 = 1;

          local_1048 = lVar10;

          local_1028 = local_1030;

          iVar8 = FUN_1400ebcd0(&local_1048,local_145c == 0);

          if (iVar8 == 0) {

            thunk_FUN_1402e9a80(local_1028);

            param_1[2] = 0;

            return 0;

          }

          iVar8 = (int)local_1030 - (int)local_1028;

          param_1[2] = local_1028;

          if (local_1028 == 0) {

            return 0;

          }

          thunk_FUN_1402e9a80(param_1[1]);

          param_1[1] = 0;

          uVar15 = puVar1[2] + 1;

          if ((((param_3 != uVar15) || (param_3 == 3)) || (local_res8 != 0)) && (!bVar4)) {

            uVar15 = puVar1[2];

          }

          puVar1[3] = uVar15;

          iVar8 = FUN_1400e73c0(param_1,param_1[2],iVar8,uVar15,uVar19);

          if (iVar8 == 0) {

            return 0;

          }

          if (bVar4) {

            pcVar13 = (char *)param_1[3];

            uVar15 = ((int *)*param_1)[1] * *(int *)*param_1;

            uVar17 = (ulonglong)uVar15;

            if (uVar15 != 0) {

              if (puVar1[3] == 2) {

                do {

                  cVar5 = -1;

                  if (*pcVar13 == local_1464[0]) {

                    cVar5 = '\0';

                  }

                  pcVar13[1] = cVar5;

                  uVar17 = uVar17 - 1;

                  pcVar13 = pcVar13 + 2;

                } while (uVar17 != 0);

              }

              else {

                do {

                  if (((*pcVar13 == local_1464[0]) && (pcVar13[1] == local_1464[1])) &&

                     (pcVar13[2] == local_1464[2])) {

                    pcVar13[3] = '\0';

                  }

                  pcVar13 = pcVar13 + 4;

                  uVar17 = uVar17 - 1;

                } while (uVar17 != 0);

              }

            }

          }

          if ((iVar7 != 0) && (2 < (int)puVar1[3])) {

            piVar2 = (int *)*param_1;

            pbVar20 = (byte *)param_1[3];

            uVar15 = piVar2[1] * *piVar2;

            if (uVar15 != 0) {

              if (piVar2[3] == 3) {

                uVar17 = (ulonglong)uVar15;

                do {

                  bVar21 = *pbVar20;

                  *pbVar20 = pbVar20[2];

                  pbVar20[2] = bVar21;

                  pbVar20 = pbVar20 + 3;

                  uVar17 = uVar17 - 1;

                } while (uVar17 != 0);

              }

              else if (DAT_1403f4c48 == 0) {

                uVar17 = (ulonglong)uVar15;

                do {

                  bVar21 = *pbVar20;

                  *pbVar20 = pbVar20[2];

                  pbVar20[2] = bVar21;

                  pbVar20 = pbVar20 + 4;

                  uVar17 = uVar17 - 1;

                } while (uVar17 != 0);

              }

              else {

                uVar17 = (ulonglong)uVar15;

                do {

                  bVar21 = *pbVar20;

                  bVar6 = pbVar20[2];

                  if (pbVar20[3] != 0) {

                    uVar15 = (uint)pbVar20[3];

                    pbVar20[1] = (byte)(((uint)pbVar20[1] * 0xff) / uVar15);

                    bVar21 = (byte)(((uint)bVar21 * 0xff) / uVar15);

                    bVar6 = (byte)(((uint)bVar6 * 0xff) / uVar15);

                  }

                  *pbVar20 = bVar6;

                  pbVar20[2] = bVar21;

                  pbVar20 = pbVar20 + 4;

                  uVar17 = uVar17 - 1;

                } while (uVar17 != 0);

              }

            }

          }

          if (local_res8 != 0) {

            puVar1[2] = (uint)local_res8;

            puVar1[3] = (uint)local_res8;

            uVar15 = (uint)local_res8;

            if (2 < (int)param_3) {

              puVar1[3] = param_3;

              uVar15 = param_3;

            }

            pbVar20 = (byte *)param_1[3];

            uVar19 = ((int *)*param_1)[1] * *(int *)*param_1;

            lVar10 = _malloc_base(uVar19 * uVar15);

            if (lVar10 == 0) {

LAB_1400eb92e:

              _DAT_1403f4c40 = "outofmem";

              return 0;

            }

            if (uVar19 != 0) {

              uVar17 = (ulonglong)uVar19;

              puVar16 = (undefined1 *)(lVar10 + 2);

              if (uVar15 == 3) {

                do {

                  uVar14 = (ulonglong)*pbVar20;

                  pbVar20 = pbVar20 + 1;

                  puVar16[-2] = auStack_1448[uVar14 * 4];

                  uVar11 = auStack_1448[uVar14 * 4 + 1];

                  *puVar16 = auStack_1448[uVar14 * 4 + 2];

                  puVar16[-1] = uVar11;

                  uVar17 = uVar17 - 1;

                  puVar16 = puVar16 + 3;

                } while (uVar17 != 0);

              }

              else {

                do {

                  uVar14 = (ulonglong)*pbVar20;

                  pbVar20 = pbVar20 + 1;

                  puVar16[-2] = auStack_1448[uVar14 * 4];

                  puVar16[-1] = auStack_1448[uVar14 * 4 + 1];

                  uVar11 = auStack_1448[uVar14 * 4 + 2];

                  puVar16[1] = auStack_1448[uVar14 * 4 + 3];

                  *puVar16 = uVar11;

                  uVar17 = uVar17 - 1;

                  puVar16 = puVar16 + 4;

                } while (uVar17 != 0);

              }

            }

            thunk_FUN_1402e9a80(param_1[3]);

            param_1[3] = lVar10;

          }

          thunk_FUN_1402e9a80(param_1[2]);

          param_1[2] = 0;

          return 1;

        }

        if (bVar3) goto LAB_1400ebacd;

        if ((local_res8 != 0) && (uVar22 == 0)) {

          _DAT_1403f4c40 = "no PLTE";

          return 0;

        }

        if (param_2 == 2) {

          puVar1[2] = (uint)local_res8;

          return 1;

        }

        if (uVar15 < uVar18 + local_1460) {

          if (uVar15 != 0) goto LAB_1400eb0e0;

          uVar15 = 0x1000;

          if (0x1000 < uVar18) {

            uVar15 = uVar18;

          }

          for (; uVar15 < uVar18 + local_1460; uVar15 = uVar15 * 2) {

LAB_1400eb0e0:

          }

          lVar10 = _realloc_base(param_1[1],uVar15);

          if (lVar10 == 0) goto LAB_1400eb92e;

          param_1[1] = lVar10;

        }

        iVar8 = FUN_1400e8d60(puVar1);

        if (iVar8 == 0) {

          _DAT_1403f4c40 = "outofdata";

          return 0;

        }

        local_1460 = iVar7 + uVar18;

      }

    }

    else if (uVar12 == 0x504c5445) {

      if (bVar3) goto LAB_1400ebacd;

      if ((0x300 < uVar18) || (uVar22 = uVar18 / 3, uVar22 * 3 != uVar18)) {

        _DAT_1403f4c40 = "invalid PLTE";

        return 0;

      }

      uVar12 = 0;

      if (uVar22 != 0) {

        do {

          puVar16 = *(undefined1 **)(puVar1 + 0x2e);

          if (puVar16 < *(undefined1 **)(puVar1 + 0x30)) {

            uVar11 = *puVar16;

            puVar16 = puVar16 + 1;

            *(undefined1 **)(puVar1 + 0x2e) = puVar16;

          }

          else if (puVar1[0xc] == 0) {

            uVar11 = 0;

          }

          else {

            FUN_1400ed820(puVar1);

            uVar11 = **(undefined1 **)(puVar1 + 0x2e);

            puVar16 = *(undefined1 **)(puVar1 + 0x2e) + 1;

            *(undefined1 **)(puVar1 + 0x2e) = puVar16;

          }

          uVar18 = uVar12 * 4;

          auStack_1448[uVar18] = uVar11;

          if (puVar16 < *(undefined1 **)(puVar1 + 0x30)) {

            uVar11 = *puVar16;

            puVar16 = puVar16 + 1;

            *(undefined1 **)(puVar1 + 0x2e) = puVar16;

          }

          else if (puVar1[0xc] == 0) {

            uVar11 = 0;

          }

          else {

            FUN_1400ed820();

            uVar11 = **(undefined1 **)(puVar1 + 0x2e);

            puVar16 = *(undefined1 **)(puVar1 + 0x2e) + 1;

            *(undefined1 **)(puVar1 + 0x2e) = puVar16;

          }

          auStack_1448[uVar18 + 1] = uVar11;

          if (puVar16 < *(undefined1 **)(puVar1 + 0x30)) {

            uVar11 = *puVar16;

            *(undefined1 **)(puVar1 + 0x2e) = puVar16 + 1;

          }

          else if (puVar1[0xc] == 0) {

            uVar11 = 0;

          }

          else {

            FUN_1400ed820();

            uVar11 = **(undefined1 **)(puVar1 + 0x2e);

            *(undefined1 **)(puVar1 + 0x2e) = *(undefined1 **)(puVar1 + 0x2e) + 1;

          }

          uVar12 = uVar12 + 1;

          auStack_1448[uVar18 + 2] = uVar11;

          auStack_1448[uVar18 + 3] = 0xff;

        } while (uVar12 < uVar22);

      }

    }

    else if (uVar12 == 0x74524e53) {

      if (bVar3) goto LAB_1400ebacd;

      if (param_1[1] != 0) {

        _DAT_1403f4c40 = "tRNS after IDAT";

        return 0;

      }

      if (local_res8 == 0) {

        uVar12 = puVar1[2];

        if ((uVar12 & 1) == 0) {

          _DAT_1403f4c40 = "tRNS with alpha";

          return 0;

        }

        if (uVar18 != uVar12 * 2) goto LAB_1400ebaa9;

        iVar7 = 0;

        bVar4 = true;

        if (0 < (int)uVar12) {

          pcVar13 = local_1464;

          do {

            cVar5 = FUN_1400e8ad0(puVar1);

            iVar7 = iVar7 + 1;

            *pcVar13 = cVar5;

            pcVar13 = pcVar13 + 1;

          } while (iVar7 < (int)puVar1[2]);

        }

      }

      else {

        if (param_2 == 2) {

          puVar1[2] = 4;

          return 1;

        }

        if (uVar22 == 0) {

          _DAT_1403f4c40 = "tRNS before PLTE";

          return 0;

        }

        if (uVar22 < uVar18) {

LAB_1400ebaa9:

          _DAT_1403f4c40 = "bad tRNS len";

          return 0;

        }

        uVar12 = 0;

        local_res8 = 4;

        if (uVar18 != 0) {

          do {

            puVar16 = *(undefined1 **)(puVar1 + 0x2e);

            if (puVar16 < *(undefined1 **)(puVar1 + 0x30)) {

              uVar11 = *puVar16;

              *(undefined1 **)(puVar1 + 0x2e) = puVar16 + 1;

            }

            else if (puVar1[0xc] == 0) {

              uVar11 = 0;

            }

            else {

              FUN_1400ed820(puVar1);

              uVar11 = **(undefined1 **)(puVar1 + 0x2e);

              *(undefined1 **)(puVar1 + 0x2e) = *(undefined1 **)(puVar1 + 0x2e) + 1;

            }

            iVar7 = uVar12 * 4;

            uVar12 = uVar12 + 1;

            auStack_1448[iVar7 + 3] = uVar11;

          } while (uVar12 < uVar18);

        }

      }

    }

    else {

LAB_1400eb3ce:

      if (bVar3) {

LAB_1400ebacd:

        _DAT_1403f4c40 = "first not IHDR";

        return 0;

      }

      if ((uVar12 >> 0x1d & 1) == 0) {

        s_XXXX_chunk_not_known_1403db0cf[1] = (char)(uVar12 >> 0x18);

        s_XXXX_chunk_not_known_1403db0cf[2] = (char)(uVar12 >> 0x10);

        s_XXXX_chunk_not_known_1403db0cf[3] = (char)(uVar12 >> 8);

        s_XXXX_chunk_not_known_1403db0cf[4] = (char)uVar12;

        _DAT_1403f4c40 = s_XXXX_chunk_not_known_1403db0cf + 1;

        return 0;

      }

      if ((*(longlong *)(puVar1 + 4) == 0) || ((int)uVar18 <= (int)(puVar1[0x30] - puVar1[0x2e]))) {

        *(longlong *)(puVar1 + 0x2e) = *(longlong *)(puVar1 + 0x2e) + (longlong)(int)uVar18;

      }

      else {

        *(undefined8 *)(puVar1 + 0x2e) = *(undefined8 *)(puVar1 + 0x30);

        (**(code **)(puVar1 + 6))(*(undefined8 *)(puVar1 + 10));

      }

    }

    FUN_1400e8ad0(puVar1);

    FUN_1400e8ad0(puVar1);

  } while( true );

}




