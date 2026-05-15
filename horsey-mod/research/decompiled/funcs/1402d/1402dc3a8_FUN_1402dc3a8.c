// Address: 0x1402dc3a8
// Ghidra name: FUN_1402dc3a8
// ============ 0x1402dc3a8 FUN_1402dc3a8 (size=7424) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8 FUN_1402dc3a8(uint *param_1,undefined8 *param_2)



{

  byte bVar1;

  longlong lVar2;

  sbyte sVar3;

  uint uVar4;

  uint uVar5;

  undefined4 *puVar6;

  ulonglong *puVar7;

  undefined8 uVar8;

  byte bVar9;

  int iVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  uint *puVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  ulonglong uVar19;

  uint uVar20;

  uint uVar21;

  uint uVar22;

  rsize_t rVar23;

  uint *puVar24;

  uint uVar25;

  uint uVar26;

  ulonglong uVar27;

  bool bVar28;

  undefined1 auStack_d78 [32];

  undefined8 *local_d58;

  uint local_d48;

  uint local_d44;

  uint local_d40;

  uint local_d3c;

  undefined8 local_d38;

  uint local_d30;

  uint *local_d28;

  undefined8 *local_d20;

  uint *local_d18;

  uint *local_d10;

  uint *local_d08;

  undefined4 local_cf8;

  uint local_cf4 [115];

  undefined4 local_b28;

  undefined1 local_b24 [460];

  uint local_958;

  uint local_954 [115];

  uint local_788;

  uint local_784 [115];

  uint local_5b8;

  uint local_5b4 [115];

  uint local_3e8;

  undefined8 local_3e4;

  uint local_218;

  uint local_214 [115];

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_d78;

  uVar26 = param_1[1];

  local_d30 = (-(uint)(*(char *)(param_2 + 1) != '\0') & 0x1d) + 0x19;

  local_788 = 0;

  puVar24 = param_1 + 2;

  uVar17 = 0;

  local_d44 = *param_1;

  if ((int)*param_1 < 0) {

    local_d44 = 0;

  }

  uVar27 = 0;

  uVar25 = 0;

  uVar20 = local_d44;

  if (uVar26 <= local_d44) {

    uVar20 = uVar26;

  }

  local_d44 = local_d44 - uVar20;

  local_d08 = (uint *)((longlong)param_1 + (ulonglong)uVar20 + 8);

  local_d10 = (uint *)((longlong)param_1 + (ulonglong)uVar26 + 8);

  local_d48 = (int)local_d10 - (int)local_d08;

  local_d28 = param_1;

  local_d20 = param_2;

  if (puVar24 != local_d08) {

    do {

      uVar26 = (uint)uVar27;

      if (uVar25 == 9) {

        if (uVar17 != 0) {

          uVar19 = 0;

          uVar12 = 0;

          do {

            uVar20 = (int)uVar12 + 1;

            uVar11 = (ulonglong)local_784[uVar12] * 1000000000 + uVar19;

            local_784[uVar12] = (uint)uVar11;

            uVar19 = uVar11 >> 0x20;

            uVar12 = (ulonglong)uVar20;

          } while (uVar20 != uVar17);

          uVar20 = (uint)(uVar11 >> 0x20);

          uVar17 = local_788;

          if (uVar20 != 0) {

            if (local_788 < 0x73) {

              local_784[local_788] = uVar20;

              local_788 = local_788 + 1;

              uVar17 = local_788;

            }

            else {

              local_788 = 0;

              uVar17 = 0;

            }

          }

        }

        if (uVar26 != 0) {

          uVar20 = 0;

          uVar25 = 0;

          if (uVar17 != 0) {

            do {

              uVar17 = uVar25 + 1;

              uVar12 = local_784[uVar25] + uVar27;

              local_784[uVar25] = (uint)uVar12;

              uVar27 = uVar12 >> 0x20;

              uVar26 = (uint)(uVar12 >> 0x20);

              uVar25 = uVar17;

            } while (uVar17 != local_788);

            uVar17 = local_788;

            uVar20 = local_788;

            if (uVar26 == 0) goto LAB_1402dc553;

          }

          if (uVar20 < 0x73) {

            local_784[uVar20] = uVar26;

            uVar17 = local_788 + 1;

            local_788 = uVar17;

          }

          else {

            uVar17 = 0;

            local_788 = 0;

          }

        }

LAB_1402dc553:

        uVar26 = 0;

        uVar25 = 0;

      }

      uVar20 = *puVar24;

      uVar25 = uVar25 + 1;

      puVar24 = (uint *)((longlong)puVar24 + 1);

      uVar26 = (uint)(byte)uVar20 + uVar26 * 10;

      uVar27 = (ulonglong)uVar26;

    } while (puVar24 != local_d08);

    if (uVar25 != 0) {

      for (uVar20 = uVar25 / 10; uVar20 != 0; uVar20 = uVar20 - local_d40) {

        local_d40 = uVar20;

        if (0x26 < uVar20) {

          local_d40 = 0x26;

        }

        uVar21 = local_d40 - 1;

        bVar9 = (&DAT_14038a8a2)[(ulonglong)uVar21 * 4];

        bVar1 = (&DAT_14038a8a3)[(ulonglong)uVar21 * 4];

        local_218 = (uint)bVar1 + (uint)bVar9;

        local_d3c = uVar20;

        FUN_1402f94c0(local_214,0,(ulonglong)bVar9 * 4);

        FUN_1402f8e20(local_214 + bVar9,

                      &DAT_140389f90 +

                      (ulonglong)*(ushort *)(&DAT_14038a8a0 + (ulonglong)uVar21 * 4) * 4,

                      (ulonglong)bVar1 << 2);

        uVar21 = local_784[0];

        if (local_218 < 2) {

          uVar12 = (ulonglong)local_214[0];

          if (local_214[0] == 0) {

LAB_1402dc624:

            local_788 = 0;

            uVar15 = 0;

            goto LAB_1402dc942;

          }

          uVar15 = uVar17;

          if ((local_214[0] == 1) || (uVar17 == 0)) goto LAB_1402dc942;

          uVar11 = 0;

          uVar19 = 0;

          do {

            uVar15 = (int)uVar19 + 1;

            uVar13 = local_784[uVar19] * uVar12 + uVar11;

            local_784[uVar19] = (uint)uVar13;

            uVar11 = uVar13 >> 0x20;

            uVar21 = (uint)(uVar13 >> 0x20);

            uVar19 = (ulonglong)uVar15;

          } while (uVar15 != uVar17);

LAB_1402dc677:

          uVar17 = 0;

          uVar15 = local_788;

          if (uVar21 == 0) goto LAB_1402dc942;

          if (local_788 < 0x73) {

            local_784[local_788] = uVar21;

            local_788 = local_788 + 1;

            uVar15 = local_788;

            goto LAB_1402dc942;

          }

          local_788 = 0;

          bVar28 = false;

        }

        else {

          if (uVar17 < 2) {

            uVar12 = (ulonglong)local_784[0];

            local_788 = local_218;

            if (local_218 != 0) {

              if (local_218 < 0x74) {

                FUN_1402f8e20();

              }

              else {

                FUN_1402f94c0(local_784,0,0x1cc);

                puVar6 = (undefined4 *)FUN_1402e68b0();

                *puVar6 = 0x22;

                FUN_1402cd454();

              }

            }

            if (uVar21 == 0) goto LAB_1402dc624;

            uVar15 = local_788;

            if ((uVar21 != 1) && (local_788 != 0)) {

              uVar11 = 0;

              uVar19 = 0;

              do {

                uVar17 = (int)uVar19 + 1;

                uVar13 = local_784[uVar19] * uVar12 + uVar11;

                local_784[uVar19] = (uint)uVar13;

                uVar11 = uVar13 >> 0x20;

                uVar21 = (uint)(uVar13 >> 0x20);

                uVar19 = (ulonglong)uVar17;

              } while (uVar17 != local_788);

              goto LAB_1402dc677;

            }

          }

          else {

            local_d18 = local_784;

            local_d38 = local_214;

            uVar20 = uVar17;

            if (local_218 < uVar17) {

              local_d38 = local_784;

              uVar20 = local_218;

              local_d18 = local_214;

            }

            local_788 = 0;

            local_5b8 = 0;

            uVar12 = 0;

            uVar21 = local_218;

            if (local_218 < uVar17) {

              uVar21 = uVar17;

            }

            if (uVar20 != 0) {

              do {

                uVar15 = (uint)uVar12;

                uVar17 = local_d18[uVar12];

                if (uVar17 == 0) {

                  if (uVar15 == local_788) {

                    local_788 = uVar15 + 1;

                    local_5b4[uVar12] = 0;

                    local_5b8 = local_788;

                  }

                }

                else {

                  uVar19 = 0;

                  uVar18 = uVar15;

                  if (uVar21 != 0) {

                    do {

                      uVar18 = (uint)uVar12;

                      uVar11 = uVar12;

                      if (uVar18 == 0x73) break;

                      if (uVar18 == local_788) {

                        local_5b4[uVar12] = 0;

                        local_5b8 = uVar18 + 1;

                      }

                      uVar11 = (ulonglong)(uVar18 + 1);

                      uVar19 = (ulonglong)local_d38[-uVar15 + uVar18] * (ulonglong)uVar17 + uVar19 +

                               (ulonglong)local_5b4[uVar12];

                      local_5b4[uVar12] = (uint)uVar19;

                      uVar19 = uVar19 >> 0x20;

                      uVar12 = uVar11;

                      local_788 = local_5b8;

                    } while (-uVar15 + uVar18 + 1 != uVar21);

                    uVar18 = (uint)uVar11;

                    uVar17 = (uint)uVar19;

                    while (uVar17 != 0) {

                      uVar18 = (uint)uVar11;

                      if (uVar18 == 0x73) goto LAB_1402dca14;

                      if (uVar18 == local_788) {

                        local_5b4[uVar11] = 0;

                        local_5b8 = uVar18 + 1;

                      }

                      uVar17 = local_5b4[uVar11];

                      uVar18 = uVar18 + 1;

                      local_5b4[uVar11] = (uint)(uVar17 + uVar19);

                      uVar17 = (uint)(uVar17 + uVar19 >> 0x20);

                      uVar19 = (ulonglong)uVar17;

                      uVar11 = (ulonglong)uVar18;

                      local_788 = local_5b8;

                    }

                  }

                  if (uVar18 == 0x73) goto LAB_1402dca14;

                }

                uVar12 = (ulonglong)(uVar15 + 1);

              } while (uVar15 + 1 != uVar20);

            }

            uVar15 = local_788;

            uVar20 = local_d3c;

            if (local_788 != 0) {

              if (local_788 < 0x74) {

                FUN_1402f8e20();

                uVar15 = local_788;

                uVar20 = local_d3c;

              }

              else {

                FUN_1402f94c0(local_784,0,0x1cc);

                puVar6 = (undefined4 *)FUN_1402e68b0();

                *puVar6 = 0x22;

                FUN_1402cd454();

                uVar15 = local_788;

                uVar20 = local_d3c;

              }

            }

          }

LAB_1402dc942:

          bVar28 = true;

          uVar17 = uVar15;

        }

        if (!bVar28) goto LAB_1402dca14;

      }

      if (uVar25 % 10 != 0) {

        uVar20 = *(uint *)(&DAT_14038a938 + (ulonglong)(uVar25 % 10 - 1) * 4);

        if (uVar20 == 0) {

LAB_1402dca14:

          local_788 = 0;

          uVar17 = 0;

        }

        else if ((uVar20 != 1) && (uVar17 != 0)) {

          uVar19 = 0;

          uVar12 = 0;

          do {

            uVar25 = (int)uVar12 + 1;

            uVar11 = (ulonglong)local_784[uVar12] * (ulonglong)uVar20 + uVar19;

            local_784[uVar12] = (uint)uVar11;

            uVar19 = uVar11 >> 0x20;

            uVar12 = (ulonglong)uVar25;

          } while (uVar25 != uVar17);

          uVar20 = (uint)(uVar11 >> 0x20);

          uVar17 = local_788;

          if (uVar20 != 0) {

            if (0x72 < local_788) goto LAB_1402dca14;

            local_784[local_788] = uVar20;

            local_788 = local_788 + 1;

            uVar17 = local_788;

          }

        }

      }

      if (uVar26 != 0) {

        uVar20 = 0;

        uVar25 = 0;

        if (uVar17 != 0) {

          do {

            uVar17 = uVar25 + 1;

            uVar26 = local_784[uVar25];

            local_784[uVar25] = (uint)(uVar26 + uVar27);

            uVar26 = (uint)(uVar26 + uVar27 >> 0x20);

            uVar27 = (ulonglong)uVar26;

            uVar25 = uVar17;

          } while (uVar17 != local_788);

          uVar17 = local_788;

          uVar20 = local_788;

          if (uVar26 == 0) goto LAB_1402dcaa0;

        }

        if (uVar20 < 0x73) {

          local_784[uVar20] = uVar26;

          local_788 = local_788 + 1;

          uVar17 = local_788;

        }

        else {

          local_788 = 0;

          uVar17 = 0;

        }

      }

    }

  }

LAB_1402dcaa0:

  if (local_d44 == 0) {

LAB_1402dcfd1:

    if (uVar17 == 0) goto LAB_1402dcfd6;

    local_d38 = (uint *)((ulonglong)local_d38 & 0xffffffff00000000);

    iVar10 = 0x1f;

    bVar28 = local_784[uVar17 - 1] == 0;

    if (!bVar28) {

      for (; local_784[uVar17 - 1] >> iVar10 == 0; iVar10 = iVar10 + -1) {

      }

    }

    if (bVar28) {

      iVar10 = 0;

    }

    else {

      iVar10 = iVar10 + 1;

    }

    local_d3c = (uVar17 - 1) * 0x20 + iVar10;

  }

  else {

    for (uVar26 = local_d44 / 10; uVar26 != 0; uVar26 = uVar26 - uVar20) {

      uVar20 = uVar26;

      if (0x26 < uVar26) {

        uVar20 = 0x26;

      }

      uVar25 = uVar20 - 1;

      bVar9 = (&DAT_14038a8a2)[(ulonglong)uVar25 * 4];

      bVar1 = (&DAT_14038a8a3)[(ulonglong)uVar25 * 4];

      local_218 = (uint)bVar1 + (uint)bVar9;

      local_d40 = uVar20;

      local_d3c = uVar26;

      FUN_1402f94c0(local_214,0,(ulonglong)bVar9 * 4);

      FUN_1402f8e20(local_214 + bVar9,

                    &DAT_140389f90 +

                    (ulonglong)*(ushort *)(&DAT_14038a8a0 + (ulonglong)uVar25 * 4) * 4,

                    (ulonglong)bVar1 << 2);

      uVar25 = local_784[0];

      if (local_218 < 2) {

        uVar27 = (ulonglong)local_214[0];

        if (local_214[0] == 0) {

LAB_1402dcb63:

          local_788 = 0;

          uVar21 = 0;

          goto LAB_1402dce70;

        }

        uVar21 = uVar17;

        if ((local_214[0] == 1) || (uVar17 == 0)) goto LAB_1402dce70;

        uVar19 = 0;

        uVar12 = 0;

        do {

          uVar21 = (int)uVar12 + 1;

          uVar11 = local_784[uVar12] * uVar27 + uVar19;

          local_784[uVar12] = (uint)uVar11;

          uVar19 = uVar11 >> 0x20;

          uVar25 = (uint)(uVar11 >> 0x20);

          uVar12 = (ulonglong)uVar21;

        } while (uVar21 != uVar17);

LAB_1402dcbb6:

        uVar17 = 0;

        uVar21 = local_788;

        if (uVar25 == 0) goto LAB_1402dce70;

        if (local_788 < 0x73) {

          local_784[local_788] = uVar25;

          local_788 = local_788 + 1;

          uVar21 = local_788;

          goto LAB_1402dce70;

        }

        local_788 = 0;

        bVar28 = false;

      }

      else {

        if (uVar17 < 2) {

          uVar27 = (ulonglong)local_784[0];

          local_788 = local_218;

          if (local_218 != 0) {

            if (local_218 < 0x74) {

              FUN_1402f8e20();

            }

            else {

              FUN_1402f94c0(local_784,0,0x1cc);

              puVar6 = (undefined4 *)FUN_1402e68b0();

              *puVar6 = 0x22;

              FUN_1402cd454();

            }

          }

          if (uVar25 == 0) goto LAB_1402dcb63;

          uVar21 = local_788;

          if ((uVar25 != 1) && (local_788 != 0)) {

            uVar19 = 0;

            uVar12 = 0;

            do {

              uVar17 = (int)uVar12 + 1;

              uVar11 = local_784[uVar12] * uVar27 + uVar19;

              local_784[uVar12] = (uint)uVar11;

              uVar19 = uVar11 >> 0x20;

              uVar25 = (uint)(uVar11 >> 0x20);

              uVar12 = (ulonglong)uVar17;

            } while (uVar17 != local_788);

            goto LAB_1402dcbb6;

          }

        }

        else {

          puVar24 = local_784;

          puVar14 = local_214;

          uVar26 = uVar17;

          if (local_218 < uVar17) {

            puVar14 = local_784;

            uVar26 = local_218;

            puVar24 = local_214;

          }

          local_788 = 0;

          local_5b8 = 0;

          uVar27 = 0;

          uVar20 = local_218;

          if (local_218 < uVar17) {

            uVar20 = uVar17;

          }

          if (uVar26 != 0) {

            do {

              uVar25 = (uint)uVar27;

              uVar17 = puVar24[uVar27];

              if (uVar17 == 0) {

                if (uVar25 == local_788) {

                  local_788 = uVar25 + 1;

                  local_5b4[uVar27] = 0;

                  local_5b8 = local_788;

                }

              }

              else {

                uVar12 = 0;

                uVar21 = uVar25;

                if (uVar20 != 0) {

                  do {

                    uVar21 = (uint)uVar27;

                    uVar19 = uVar27;

                    if (uVar21 == 0x73) break;

                    if (uVar21 == local_788) {

                      local_5b4[uVar27] = 0;

                      local_5b8 = uVar21 + 1;

                    }

                    uVar19 = (ulonglong)(uVar21 + 1);

                    uVar12 = (ulonglong)puVar14[-uVar25 + uVar21] * (ulonglong)uVar17 + uVar12 +

                             (ulonglong)local_5b4[uVar27];

                    local_5b4[uVar27] = (uint)uVar12;

                    uVar12 = uVar12 >> 0x20;

                    uVar27 = uVar19;

                    local_788 = local_5b8;

                  } while (-uVar25 + uVar21 + 1 != uVar20);

                  uVar21 = (uint)uVar19;

                  uVar17 = (uint)uVar12;

                  while (uVar17 != 0) {

                    uVar21 = (uint)uVar19;

                    if (uVar21 == 0x73) goto LAB_1402dcf4a;

                    if (uVar21 == local_788) {

                      local_5b4[uVar19] = 0;

                      local_5b8 = uVar21 + 1;

                    }

                    uVar17 = local_5b4[uVar19];

                    uVar21 = uVar21 + 1;

                    local_5b4[uVar19] = (uint)(uVar12 + uVar17);

                    uVar17 = (uint)(uVar12 + uVar17 >> 0x20);

                    uVar12 = (ulonglong)uVar17;

                    uVar19 = (ulonglong)uVar21;

                    local_788 = local_5b8;

                  }

                }

                if (uVar21 == 0x73) goto LAB_1402dcf4a;

              }

              uVar27 = (ulonglong)(uVar25 + 1);

            } while (uVar25 + 1 != uVar26);

          }

          uVar21 = local_788;

          uVar26 = local_d3c;

          uVar20 = local_d40;

          if (local_788 != 0) {

            if (local_788 < 0x74) {

              FUN_1402f8e20();

              uVar21 = local_788;

              uVar26 = local_d3c;

              uVar20 = local_d40;

            }

            else {

              FUN_1402f94c0(local_784,0,0x1cc);

              puVar6 = (undefined4 *)FUN_1402e68b0();

              *puVar6 = 0x22;

              FUN_1402cd454();

              uVar21 = local_788;

              uVar26 = local_d3c;

              uVar20 = local_d40;

            }

          }

        }

LAB_1402dce70:

        bVar28 = true;

        uVar17 = uVar21;

      }

      if (!bVar28) goto LAB_1402dcf4a;

    }

    if (local_d44 % 10 == 0) goto LAB_1402dcfd1;

    uVar26 = *(uint *)(&DAT_14038a938 + (ulonglong)(local_d44 % 10 - 1) * 4);

    if (uVar26 == 0) {

      local_788 = 0;

      uVar17 = 0;

      goto LAB_1402dcfd1;

    }

    if (uVar26 == 1) goto LAB_1402dcfd1;

    if (uVar17 != 0) {

      uVar12 = 0;

      uVar27 = 0;

      do {

        uVar20 = (int)uVar27 + 1;

        uVar19 = (ulonglong)local_784[uVar27] * (ulonglong)uVar26 + uVar12;

        local_784[uVar27] = (uint)uVar19;

        uVar12 = uVar19 >> 0x20;

        uVar27 = (ulonglong)uVar20;

      } while (uVar20 != uVar17);

      uVar26 = (uint)(uVar19 >> 0x20);

      uVar17 = local_788;

      if (uVar26 != 0) {

        if (0x72 < local_788) {

LAB_1402dcf4a:

          puVar7 = (ulonglong *)*local_d20;

          if (*(char *)(local_d20 + 1) == '\0') {

            *(uint *)puVar7 =

                 (-(uint)((char)local_d28[0xc2] != '\0') & 0x80000000) + 0x7f800000 |

                 (uint)*puVar7 & 0x7f800000;

          }

          else {

            *puVar7 = (-(ulonglong)((char)local_d28[0xc2] != '\0') & 0x8000000000000000) +

                      0x7ff0000000000000 | *puVar7 & 0x7ff0000000000000;

          }

          return 3;

        }

        local_784[local_788] = uVar26;

        local_788 = local_788 + 1;

        uVar17 = local_788;

      }

      goto LAB_1402dcfd1;

    }

LAB_1402dcfd6:

    local_d3c = 0;

  }

  puVar24 = local_d10;

  if ((local_d3c < local_d30) && (local_d48 != 0)) {

    uVar26 = 0;

    uVar27 = 0;

    local_958 = 0;

    uVar20 = 0;

    puVar14 = local_d08;

    if (local_d08 != local_d10) {

      do {

        uVar25 = (uint)uVar27;

        if (uVar20 == 9) {

          if (uVar26 != 0) {

            uVar19 = 0;

            uVar12 = 0;

            do {

              uVar20 = (int)uVar12 + 1;

              uVar11 = (ulonglong)local_954[uVar12] * 1000000000 + uVar19;

              local_954[uVar12] = (uint)uVar11;

              uVar19 = uVar11 >> 0x20;

              uVar12 = (ulonglong)uVar20;

            } while (uVar20 != uVar26);

            uVar20 = (uint)(uVar11 >> 0x20);

            uVar26 = local_958;

            if (uVar20 != 0) {

              if (local_958 < 0x73) {

                local_954[local_958] = uVar20;

                local_958 = local_958 + 1;

                uVar26 = local_958;

              }

              else {

                local_218 = 0;

                local_958 = 0;

                memcpy_s(local_954,0x1cc,local_214,0);

                uVar26 = local_958;

              }

            }

          }

          if (uVar25 != 0) {

            uVar12 = 0;

            uVar20 = 0;

            if (uVar26 != 0) {

              do {

                uVar26 = (int)uVar12 + 1;

                uVar19 = local_954[uVar12] + uVar27;

                local_954[uVar12] = (uint)uVar19;

                uVar27 = uVar19 >> 0x20;

                uVar25 = (uint)(uVar19 >> 0x20);

                uVar12 = (ulonglong)uVar26;

              } while (uVar26 != local_958);

              uVar20 = local_958;

              uVar26 = local_958;

              if (uVar25 == 0) goto LAB_1402dd171;

            }

            if (uVar20 < 0x73) {

              local_954[uVar20] = uVar25;

              local_958 = local_958 + 1;

              uVar26 = local_958;

            }

            else {

              local_218 = 0;

              local_958 = 0;

              memcpy_s(local_954,0x1cc,local_214,0);

              uVar26 = local_958;

            }

          }

LAB_1402dd171:

          uVar25 = 0;

          uVar20 = 0;

        }

        uVar21 = *puVar14;

        uVar20 = uVar20 + 1;

        puVar14 = (uint *)((longlong)puVar14 + 1);

        uVar25 = (uint)(byte)uVar21 + uVar25 * 10;

        uVar27 = (ulonglong)uVar25;

      } while (puVar14 != puVar24);

      if (uVar20 != 0) {

        uVar12 = (ulonglong)uVar20 / 10;

        uVar21 = (uint)uVar12;

        while (local_d40 = (uint)uVar12, uVar21 != 0) {

          uVar21 = local_d40;

          if (0x26 < local_d40) {

            uVar21 = 0x26;

          }

          local_d38 = (uint *)CONCAT44(local_d38._4_4_,uVar21);

          uVar12 = (ulonglong)(uVar21 - 1);

          bVar9 = (&DAT_14038a8a2)[uVar12 * 4];

          bVar1 = (&DAT_14038a8a3)[uVar12 * 4];

          local_218 = (uint)bVar1 + (uint)bVar9;

          FUN_1402f94c0(local_214,0,(ulonglong)bVar9 * 4);

          FUN_1402f8e20(local_214 + bVar9,

                        &DAT_140389f90 + (ulonglong)*(ushort *)(&DAT_14038a8a0 + uVar12 * 4) * 4,

                        (ulonglong)bVar1 << 2);

          uVar21 = local_954[0];

          if (local_218 < 2) {

            uVar12 = (ulonglong)local_214[0];

            if (local_214[0] == 0) {

LAB_1402dd247:

              local_218 = 0;

              puVar24 = local_214;

              local_958 = 0;

              rVar23 = 0;

              goto LAB_1402dd50f;

            }

            if ((local_214[0] == 1) || (uVar26 == 0)) goto LAB_1402dd527;

            uVar11 = 0;

            uVar19 = 0;

            do {

              uVar21 = (int)uVar19 + 1;

              uVar13 = local_954[uVar19] * uVar12 + uVar11;

              local_954[uVar19] = (uint)uVar13;

              uVar11 = uVar13 >> 0x20;

              uVar15 = (uint)(uVar13 >> 0x20);

              uVar19 = (ulonglong)uVar21;

            } while (uVar21 != uVar26);

LAB_1402dd2a7:

            uVar26 = local_958;

            if (uVar15 == 0) goto LAB_1402dd527;

            if (local_958 < 0x73) {

              local_954[local_958] = uVar15;

              local_958 = local_958 + 1;

              uVar26 = local_958;

              goto LAB_1402dd527;

            }

            local_218 = 0;

            local_958 = 0;

            memcpy_s(local_954,0x1cc,local_214,0);

            bVar28 = false;

            uVar26 = local_958;

          }

          else {

            puVar24 = local_214;

            if (uVar26 < 2) {

              local_958 = local_218;

              memcpy_s(local_954,0x1cc,puVar24,(ulonglong)local_218 << 2);

              if (uVar21 != 0) {

                uVar26 = local_958;

                if ((uVar21 != 1) && (local_958 != 0)) {

                  uVar19 = 0;

                  uVar12 = 0;

                  do {

                    uVar26 = (int)uVar12 + 1;

                    uVar11 = (ulonglong)local_954[uVar12] * (ulonglong)uVar21 + uVar19;

                    local_954[uVar12] = (uint)uVar11;

                    uVar19 = uVar11 >> 0x20;

                    uVar15 = (uint)(uVar11 >> 0x20);

                    uVar12 = (ulonglong)uVar26;

                  } while (uVar26 != local_958);

                  goto LAB_1402dd2a7;

                }

                goto LAB_1402dd527;

              }

              goto LAB_1402dd247;

            }

            local_d18 = local_954;

            local_d44 = uVar26;

            if (local_218 < uVar26) {

              puVar24 = local_954;

              local_d18 = local_214;

              local_d44 = local_218;

            }

            uVar15 = 0;

            local_958 = 0;

            uVar21 = local_218;

            if (local_218 < uVar26) {

              uVar21 = uVar26;

            }

            local_5b8 = 0;

            if (local_d44 != 0) {

              do {

                uVar26 = local_d18[uVar15];

                if (uVar26 == 0) {

                  if (uVar15 == local_958) {

                    local_958 = uVar15 + 1;

                    local_5b4[uVar15] = 0;

                    local_5b8 = local_958;

                  }

                }

                else {

                  uVar12 = 0;

                  uVar18 = uVar15;

                  if (uVar21 != 0) {

                    uVar19 = (ulonglong)uVar15;

                    do {

                      uVar18 = (uint)uVar19;

                      uVar11 = uVar19;

                      if (uVar18 == 0x73) break;

                      if (uVar18 == local_958) {

                        local_5b4[uVar19] = 0;

                        local_5b8 = uVar18 + 1;

                      }

                      uVar11 = (ulonglong)(uVar18 + 1);

                      uVar12 = (ulonglong)puVar24[-uVar15 + uVar18] * (ulonglong)uVar26 +

                               (ulonglong)local_5b4[uVar19] + uVar12;

                      local_5b4[uVar19] = (uint)uVar12;

                      uVar12 = uVar12 >> 0x20;

                      uVar19 = uVar11;

                      local_958 = local_5b8;

                    } while (-uVar15 + uVar18 + 1 != uVar21);

                    uVar18 = (uint)uVar11;

                    uVar26 = (uint)uVar12;

                    while (uVar26 != 0) {

                      uVar18 = (uint)uVar11;

                      if (uVar18 == 0x73) goto LAB_1402dd5ea;

                      if (uVar18 == local_958) {

                        local_5b4[uVar11] = 0;

                        local_5b8 = uVar18 + 1;

                      }

                      uVar26 = local_5b4[uVar11];

                      uVar18 = uVar18 + 1;

                      local_5b4[uVar11] = (uint)(uVar26 + uVar12);

                      uVar26 = (uint)(uVar26 + uVar12 >> 0x20);

                      uVar12 = (ulonglong)uVar26;

                      uVar11 = (ulonglong)uVar18;

                      local_958 = local_5b8;

                    }

                  }

                  if (uVar18 == 0x73) {

LAB_1402dd5ea:

                    local_b28 = 0;

                    local_958 = 0;

                    memcpy_s(local_954,0x1cc,local_b24,0);

                    goto LAB_1402dd611;

                  }

                }

                uVar15 = uVar15 + 1;

              } while (uVar15 != local_d44);

            }

            puVar24 = local_5b4;

            rVar23 = (ulonglong)local_958 << 2;

LAB_1402dd50f:

            memcpy_s(local_954,0x1cc,puVar24,rVar23);

            uVar26 = local_958;

LAB_1402dd527:

            bVar28 = true;

          }

          if (!bVar28) goto LAB_1402dd611;

          uVar21 = local_d40 - (int)local_d38;

          uVar12 = (ulonglong)uVar21;

        }

        if (uVar20 % 10 != 0) {

          uVar20 = *(uint *)(&DAT_14038a938 + (ulonglong)(uVar20 % 10 - 1) * 4);

          if (uVar20 == 0) {

LAB_1402dd611:

            local_cf8 = 0;

            local_958 = 0;

            memcpy_s(local_954,0x1cc,local_cf4,0);

            uVar26 = local_958;

          }

          else if ((uVar20 != 1) && (uVar26 != 0)) {

            uVar19 = 0;

            uVar12 = 0;

            do {

              uVar21 = (int)uVar12 + 1;

              uVar11 = (ulonglong)local_954[uVar12] * (ulonglong)uVar20 + uVar19;

              local_954[uVar12] = (uint)uVar11;

              uVar19 = uVar11 >> 0x20;

              uVar12 = (ulonglong)uVar21;

            } while (uVar21 != uVar26);

            uVar20 = (uint)(uVar11 >> 0x20);

            uVar26 = local_958;

            if (uVar20 != 0) {

              if (0x72 < local_958) goto LAB_1402dd611;

              local_954[local_958] = uVar20;

              local_958 = local_958 + 1;

              uVar26 = local_958;

            }

          }

        }

        if (uVar25 != 0) {

          uVar20 = 0;

          uVar21 = 0;

          if (uVar26 != 0) {

            do {

              uVar21 = uVar20 + 1;

              uVar26 = local_954[uVar20];

              local_954[uVar20] = (uint)(uVar26 + uVar27);

              uVar25 = (uint)(uVar26 + uVar27 >> 0x20);

              uVar27 = (ulonglong)uVar25;

              uVar20 = uVar21;

            } while (uVar21 != local_958);

            uVar21 = local_958;

            uVar26 = local_958;

            if (uVar25 == 0) goto LAB_1402dd6ce;

          }

          if (uVar21 < 0x73) {

            local_954[uVar21] = uVar25;

            local_958 = local_958 + 1;

            uVar26 = local_958;

          }

          else {

            local_cf8 = 0;

            local_958 = 0;

            memcpy_s(local_954,0x1cc,local_cf4,0);

            uVar26 = local_958;

          }

        }

      }

    }

LAB_1402dd6ce:

    if ((int)*local_d28 < 0) {

      local_d48 = local_d48 - *local_d28;

    }

    uVar25 = 1;

    local_3e4 = 1;

    local_3e8 = 1;

    for (uVar20 = local_d48 / 10; uVar20 != 0; uVar20 = uVar20 - (int)local_d38) {

      uVar21 = uVar20;

      if (0x26 < uVar20) {

        uVar21 = 0x26;

      }

      local_d38._4_4_ = (undefined4)((ulonglong)local_d38 >> 0x20);

      local_d38 = (uint *)CONCAT44(local_d38._4_4_,uVar21);

      uVar27 = (ulonglong)(uVar21 - 1);

      bVar9 = (&DAT_14038a8a2)[uVar27 * 4];

      bVar1 = (&DAT_14038a8a3)[uVar27 * 4];

      local_218 = (uint)bVar1 + (uint)bVar9;

      FUN_1402f94c0(local_214,0,(ulonglong)bVar9 * 4);

      FUN_1402f8e20(local_214 + bVar9,

                    &DAT_140389f90 + (ulonglong)*(ushort *)(&DAT_14038a8a0 + uVar27 * 4) * 4,

                    (ulonglong)bVar1 << 2);

      if (local_218 < 2) {

        uVar27 = (ulonglong)local_214[0];

        if (local_214[0] == 0) {

          local_cf8 = 0;

          local_3e8 = 0;

          memcpy_s(&local_3e4,0x1cc,local_cf4,0);

          uVar25 = local_3e8;

        }

        else if ((local_214[0] != 1) && (uVar25 != 0)) {

          uVar19 = 0;

          uVar12 = 0;

          do {

            uVar21 = (int)uVar12 + 1;

            uVar11 = *(uint *)((longlong)&local_3e4 + uVar12 * 4) * uVar27 + uVar19;

            *(int *)((longlong)&local_3e4 + uVar12 * 4) = (int)uVar11;

            uVar19 = uVar11 >> 0x20;

            uVar12 = (ulonglong)uVar21;

          } while (uVar21 != uVar25);

          iVar10 = (int)(uVar11 >> 0x20);

          uVar25 = local_3e8;

          if (iVar10 == 0) goto LAB_1402dd7d2;

          if (local_3e8 < 0x73) {

            *(int *)((longlong)&local_3e4 + (ulonglong)local_3e8 * 4) = iVar10;

            local_3e8 = local_3e8 + 1;

            uVar25 = local_3e8;

            goto LAB_1402dd7d2;

          }

          local_cf8 = 0;

          local_3e8 = 0;

          memcpy_s(&local_3e4,0x1cc,local_cf4,0);

          bVar28 = false;

          uVar25 = local_3e8;

          goto LAB_1402ddb0a;

        }

LAB_1402dd7d2:

        bVar28 = true;

      }

      else {

        puVar24 = local_214;

        if (uVar25 < 2) {

          uVar25 = (uint)local_3e4;

          uVar27 = local_3e4 & 0xffffffff;

          local_3e8 = local_218;

          memcpy_s(&local_3e4,0x1cc,puVar24,(ulonglong)local_218 << 2);

          if (uVar25 == 0) {

            local_cf8 = 0;

            puVar24 = local_cf4;

            local_3e8 = 0;

            rVar23 = 0;

            goto LAB_1402ddaf2;

          }

          if ((uVar25 != 1) && (local_3e8 != 0)) {

            uVar19 = 0;

            uVar12 = 0;

            do {

              uVar25 = (int)uVar12 + 1;

              uVar11 = *(uint *)((longlong)&local_3e4 + uVar12 * 4) * uVar27 + uVar19;

              *(int *)((longlong)&local_3e4 + uVar12 * 4) = (int)uVar11;

              uVar19 = uVar11 >> 0x20;

              uVar12 = (ulonglong)uVar25;

            } while (uVar25 != local_3e8);

            iVar10 = (int)(uVar11 >> 0x20);

            if (iVar10 != 0) {

              if (0x72 < local_3e8) {

                local_cf8 = 0;

                local_3e8 = 0;

                memcpy_s(&local_3e4,0x1cc,local_cf4,0);

                bVar28 = false;

                uVar25 = local_3e8;

                goto LAB_1402ddb0a;

              }

              *(int *)((longlong)&local_3e4 + (ulonglong)local_3e8 * 4) = iVar10;

              local_3e8 = local_3e8 + 1;

            }

          }

        }

        else {

          local_d18 = (uint *)&local_3e4;

          local_d40 = uVar25;

          if (local_218 < uVar25) {

            puVar24 = (uint *)&local_3e4;

            local_d18 = local_214;

            local_d40 = local_218;

          }

          uVar18 = 0;

          uVar21 = 0;

          uVar15 = local_218;

          if (local_218 < uVar25) {

            uVar15 = uVar25;

          }

          local_5b8 = 0;

          if (local_d40 != 0) {

            do {

              uVar25 = local_d18[uVar18];

              if (uVar25 == 0) {

                if (uVar18 == uVar21) {

                  uVar21 = uVar18 + 1;

                  local_5b4[uVar18] = 0;

                  local_5b8 = uVar21;

                }

              }

              else {

                uVar27 = 0;

                uVar22 = uVar18;

                if (uVar15 != 0) {

                  uVar12 = (ulonglong)uVar18;

                  do {

                    uVar22 = (uint)uVar12;

                    uVar19 = uVar12;

                    if (uVar22 == 0x73) break;

                    if (uVar22 == uVar21) {

                      local_5b4[uVar12] = 0;

                      local_5b8 = uVar22 + 1;

                    }

                    uVar19 = (ulonglong)(uVar22 + 1);

                    uVar27 = (ulonglong)puVar24[-uVar18 + uVar22] * (ulonglong)uVar25 + uVar27 +

                             (ulonglong)local_5b4[uVar12];

                    local_5b4[uVar12] = (uint)uVar27;

                    uVar27 = uVar27 >> 0x20;

                    uVar12 = uVar19;

                    uVar21 = local_5b8;

                  } while (-uVar18 + uVar22 + 1 != uVar15);

                  uVar22 = (uint)uVar19;

                  uVar25 = (uint)uVar27;

                  while (uVar25 != 0) {

                    uVar22 = (uint)uVar19;

                    if (uVar22 == 0x73) goto LAB_1402ddb85;

                    if (uVar22 == uVar21) {

                      local_5b4[uVar19] = 0;

                      local_5b8 = uVar22 + 1;

                    }

                    uVar25 = local_5b4[uVar19];

                    uVar22 = uVar22 + 1;

                    local_5b4[uVar19] = (uint)(uVar25 + uVar27);

                    uVar25 = (uint)(uVar25 + uVar27 >> 0x20);

                    uVar27 = (ulonglong)uVar25;

                    uVar19 = (ulonglong)uVar22;

                    uVar21 = local_5b8;

                  }

                }

                if (uVar22 == 0x73) {

LAB_1402ddb85:

                  local_b28 = 0;

                  local_3e8 = 0;

                  memcpy_s(&local_3e4,0x1cc,local_b24,0);

                  goto LAB_1402ddc2b;

                }

              }

              uVar18 = uVar18 + 1;

            } while (uVar18 != local_d40);

          }

          puVar24 = local_5b4;

          rVar23 = (ulonglong)uVar21 << 2;

          local_3e8 = uVar21;

LAB_1402ddaf2:

          memcpy_s(&local_3e4,0x1cc,puVar24,rVar23);

        }

        bVar28 = true;

        uVar25 = local_3e8;

      }

LAB_1402ddb0a:

      if (!bVar28) goto LAB_1402ddc2b;

    }

    if (local_d48 % 10 != 0) {

      uVar20 = *(uint *)(&DAT_14038a938 + (ulonglong)(local_d48 % 10 - 1) * 4);

      if (uVar20 == 0) {

        local_cf8 = 0;

        local_3e8 = 0;

        memcpy_s(&local_3e4,0x1cc,local_cf4,0);

        uVar25 = local_3e8;

      }

      else if ((uVar20 != 1) && (uVar25 != 0)) {

        uVar12 = 0;

        uVar27 = 0;

        do {

          uVar21 = (int)uVar27 + 1;

          uVar19 = (ulonglong)*(uint *)((longlong)&local_3e4 + uVar27 * 4) * (ulonglong)uVar20 +

                   uVar12;

          *(int *)((longlong)&local_3e4 + uVar27 * 4) = (int)uVar19;

          uVar12 = uVar19 >> 0x20;

          uVar27 = (ulonglong)uVar21;

        } while (uVar21 != uVar25);

        iVar10 = (int)(uVar19 >> 0x20);

        uVar25 = local_3e8;

        if (iVar10 != 0) {

          if (0x72 < local_3e8) {

LAB_1402ddc2b:

            local_cf8 = 0;

            local_3e8 = 0;

            memcpy_s(&local_3e4,0x1cc,local_cf4,0);

            uVar26 = local_d28[0xc2];

            if (*(char *)(local_d20 + 1) == '\0') {

              puVar24 = (uint *)FUN_1402dbe54();

              *puVar24 = -(uint)((char)uVar26 != '\0') & 0x80000000;

            }

            else {

              puVar7 = (ulonglong *)FUN_1402dbe18();

              *puVar7 = -(ulonglong)((char)uVar26 != '\0') & 0x8000000000000000;

            }

            return 2;

          }

          *(int *)((longlong)&local_3e4 + (ulonglong)local_3e8 * 4) = iVar10;

          local_3e8 = local_3e8 + 1;

          uVar25 = local_3e8;

        }

      }

    }

    if (uVar26 == 0) {

      uVar20 = 0;

    }

    else {

      local_d38 = (uint *)((ulonglong)local_d38 & 0xffffffff00000000);

      iVar10 = 0x1f;

      bVar28 = local_954[uVar26 - 1] == 0;

      if (!bVar28) {

        for (; local_954[uVar26 - 1] >> iVar10 == 0; iVar10 = iVar10 + -1) {

        }

      }

      if (bVar28) {

        iVar10 = 0;

      }

      else {

        iVar10 = iVar10 + 1;

      }

      uVar20 = (uVar26 - 1) * 0x20 + iVar10;

    }

    if (uVar25 == 0) {

      uVar21 = 0;

    }

    else {

      local_d38 = (uint *)((ulonglong)local_d38 & 0xffffffff00000000);

      puVar24 = (uint *)((longlong)&local_3e4 + (ulonglong)(uVar25 - 1) * 4);

      iVar10 = 0x1f;

      bVar28 = *puVar24 == 0;

      if (!bVar28) {

        for (; *puVar24 >> iVar10 == 0; iVar10 = iVar10 + -1) {

        }

      }

      if (bVar28) {

        iVar10 = 0;

      }

      else {

        iVar10 = iVar10 + 1;

      }

      uVar21 = (uVar25 - 1) * 0x20 + iVar10;

    }

    uVar20 = -(uint)(uVar20 < uVar21) & uVar21 - uVar20;

    local_d44 = uVar20;

    if (uVar20 != 0) {

      local_d48 = 0;

      uVar21 = uVar20 & 0x1f;

      uVar18 = uVar20 >> 5;

      local_d38 = (uint *)CONCAT44(local_d38._4_4_,0x20 - uVar21);

      bVar9 = (byte)(0x20 - uVar21);

      uVar15 = (1 << (bVar9 & 0x3f)) - 1;

      local_d40 = ~uVar15;

      iVar10 = 0x1f;

      bVar28 = local_954[uVar26 - 1] == 0;

      if (!bVar28) {

        for (; local_954[uVar26 - 1] >> iVar10 == 0; iVar10 = iVar10 + -1) {

        }

      }

      if (bVar28) {

        iVar10 = 0;

      }

      else {

        iVar10 = iVar10 + 1;

      }

      if ((uVar18 + uVar26 < 0x74) &&

         (local_d48 = (0x20U - iVar10 < uVar21) + uVar18 + uVar26, local_d48 < 0x74)) {

        uVar22 = local_d48 - 1;

        if (uVar22 != uVar18 - 1) {

          do {

            uVar4 = uVar22 - uVar18;

            if (uVar4 < uVar26) {

              uVar5 = local_954[uVar4];

            }

            else {

              uVar5 = 0;

            }

            if (uVar4 - 1 < uVar26) {

              uVar26 = local_954[uVar4 - 1];

            }

            else {

              uVar26 = 0;

            }

            local_954[uVar22] =

                 (uVar26 & local_d40) >> (bVar9 & 0x1f) | (uVar5 & uVar15) << (sbyte)uVar21;

            uVar22 = uVar22 - 1;

            uVar26 = local_958;

          } while (uVar22 != uVar18 - 1);

        }

        uVar21 = 0;

        local_958 = local_d48;

        uVar26 = local_d48;

        if (uVar18 != 0) {

          do {

            uVar27 = (ulonglong)uVar21;

            uVar21 = uVar21 + 1;

            local_954[uVar27] = 0;

          } while (uVar21 != uVar18);

        }

      }

      else {

        local_cf8 = 0;

        local_958 = 0;

        memcpy_s(local_954,0x1cc,local_cf4,0);

        uVar26 = local_958;

      }

    }

    uVar21 = local_d3c;

    local_d30 = local_d30 - local_d3c;

    uVar15 = local_d30;

    if (local_d3c != 0) {

      if (local_d30 < uVar20) {

        bVar28 = true;

        goto LAB_1402de05c;

      }

      uVar15 = local_d30 - uVar20;

    }

    if (uVar25 < uVar26) {

LAB_1402dde7a:

      bVar28 = false;

    }

    else {

      uVar18 = uVar26;

      if (uVar26 < uVar25) {

        bVar28 = true;

      }

      else {

        do {

          uVar18 = uVar18 - 1;

          if (uVar18 == 0xffffffff) goto LAB_1402dde7a;

          uVar25 = *(uint *)((longlong)&local_3e4 + (ulonglong)uVar18 * 4);

        } while (local_954[uVar18] == uVar25);

        bVar28 = local_954[uVar18] <= uVar25;

      }

    }

    if (bVar28) {

      uVar20 = uVar20 + 1;

    }

    uVar22 = uVar15 >> 5;

    sVar3 = (sbyte)(uVar15 & 0x1f);

    bVar9 = 0x20 - sVar3;

    uVar18 = (int)(1L << (bVar9 & 0x3f)) - 1;

    uVar25 = ~uVar18;

    local_d38 = (uint *)CONCAT44(local_d38._4_4_,uVar25);

    iVar10 = 0x1f;

    bVar28 = local_954[uVar26 - 1] == 0;

    if (!bVar28) {

      for (; local_954[uVar26 - 1] >> iVar10 == 0; iVar10 = iVar10 + -1) {

      }

    }

    if (bVar28) {

      iVar10 = 0;

    }

    else {

      iVar10 = iVar10 + 1;

    }

    local_d44 = uVar20;

    if ((uVar22 + uVar26 < 0x74) &&

       (uVar15 = (0x20U - iVar10 < (uVar15 & 0x1f)) + uVar22 + uVar26, uVar15 < 0x74)) {

      uVar4 = uVar15;

      while (uVar4 = uVar4 - 1, uVar4 != uVar22 - 1) {

        uVar5 = uVar4 - uVar22;

        if (uVar5 < uVar26) {

          uVar16 = local_954[uVar5];

        }

        else {

          uVar16 = 0;

        }

        if (uVar5 - 1 < uVar26) {

          uVar26 = local_954[uVar5 - 1];

        }

        else {

          uVar26 = 0;

        }

        local_954[uVar4] = (uVar26 & uVar25) >> (bVar9 & 0x1f) | (uVar16 & uVar18) << sVar3;

        uVar26 = local_958;

      }

      uVar26 = 0;

      local_958 = uVar15;

      if (uVar22 != 0) {

        do {

          uVar27 = (ulonglong)uVar26;

          uVar26 = uVar26 + 1;

          local_954[uVar27] = 0;

        } while (uVar26 != uVar22);

      }

    }

    else {

      local_cf8 = 0;

      local_958 = 0;

      memcpy_s(local_954,0x1cc,local_cf4,0);

    }

    uVar27 = FUN_1402de160(&local_958,&local_3e8);

    bVar28 = local_958 == 0;

    lVar2 = 0x3f;

    if (uVar27 != 0) {

      for (; uVar27 >> lVar2 == 0; lVar2 = lVar2 + -1) {

      }

    }

    if (uVar27 == 0) {

      uVar26 = 0;

    }

    else {

      uVar26 = (int)lVar2 + 1;

    }

    if (local_d30 < uVar26) {

      bVar9 = (char)uVar26 - (byte)local_d30;

      if ((!bVar28) || (bVar28 = true, (uVar27 & (1L << (bVar9 & 0x3f)) - 1U) != 0)) {

        bVar28 = false;

      }

      uVar27 = uVar27 >> (bVar9 & 0x3f);

    }

    local_d58 = local_d20;

    uVar12 = 0;

    if (uVar17 != 0) {

      uVar12 = (ulonglong)local_784[0];

    }

    uVar19 = 0;

    if (1 < uVar17) {

      uVar19 = (ulonglong)local_784[1];

    }

    uVar26 = ~uVar20;

    if (uVar21 != 0) {

      uVar26 = uVar21 - 2;

    }

    uVar8 = FUN_1402dbe90(uVar27 + ((uVar19 << 0x20) + uVar12 << ((byte)local_d30 & 0x3f)),uVar26,

                          (char)local_d28[0xc2],bVar28);

  }

  else {

    bVar28 = local_d48 != 0;

LAB_1402de05c:

    local_d58 = local_d20;

    uVar8 = FUN_1402dc248(&local_788,local_d3c,(char)local_d28[0xc2],bVar28);

  }

  return uVar8;

}




