// Address: 0x1402a05f0
// Ghidra name: FUN_1402a05f0
// ============ 0x1402a05f0 FUN_1402a05f0 (size=4132) ============


void FUN_1402a05f0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  int *piVar8;

  int *piVar9;

  longlong lVar10;

  undefined8 uVar11;

  longlong lVar12;

  byte bVar13;

  byte bVar14;

  uint uVar15;

  uint uVar16;

  int iVar17;

  int iVar18;

  int iVar19;

  uint uVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  uint *puVar23;

  ulonglong uVar24;

  longlong lVar25;

  int iVar26;

  ulonglong uVar27;

  uint uVar28;

  uint uVar29;

  int iVar30;

  ulonglong uVar31;

  int iVar32;

  ulonglong uVar33;

  uint uVar34;

  ulonglong uVar35;

  undefined8 uVar36;

  uint *puVar37;

  ulonglong uVar38;

  uint uVar39;

  uint uVar40;

  uint uVar41;

  byte local_res10;

  uint local_res18;

  uint local_res20;

  uint local_e8;

  uint local_d4;

  ulonglong local_a0;

  

  uVar5 = *(uint *)(param_1 + 0x78);

  piVar8 = *(int **)(param_1 + 0x48);

  uVar33 = 0;

  piVar9 = *(int **)(param_1 + 0x58);

  uVar35 = 0;

  lVar10 = *(longlong *)(param_1 + 0x60);

  uVar28 = 0;

  uVar11 = *(undefined8 *)(param_1 + 0x70);

  uVar38 = 0;

  uVar39 = 0;

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar27 = 0;

  uVar29 = 0;

  bVar2 = *(byte *)(param_1 + 0x81);

  uVar40 = 0;

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  lVar12 = *(longlong *)(param_1 + 0x50);

  uVar6 = *(uint *)(param_1 + 0x7c);

  uVar15 = (uint)*(byte *)((longlong)piVar8 + 5);

  uVar16 = (uint)*(byte *)((longlong)piVar9 + 5);

  uVar7 = piVar8[5];

  local_res18 = 0;

  local_res20 = 0;

  local_e8 = 0;

  local_d4 = 0;

  local_res10 = 0;

  lVar25 = param_1;

  uVar36 = uVar11;

  iVar17 = FUN_14029fe00(*piVar8);

  iVar18 = FUN_14029fe00(*piVar9);

  if (iVar18 == 0) {

    local_res10 = FUN_14017bb00(uVar36,0);

    uVar33 = 0;

    uVar35 = 0;

    lVar25 = param_1;

  }

  iVar19 = *(int *)(lVar25 + 0x3c);

  uVar31 = (ulonglong)iVar19;

  if (iVar19 == 0) {

    uVar21 = 0;

  }

  else {

    uVar21 = (ulonglong)((longlong)*(int *)(lVar25 + 0x14) << 0x10) / uVar31;

    lVar25 = param_1;

  }

  if (*(int *)(lVar25 + 0x38) == 0) {

    uVar22 = 0;

  }

  else {

    uVar22 = (ulonglong)((longlong)*(int *)(lVar25 + 0x10) << 0x10) /

             (ulonglong)(longlong)*(int *)(lVar25 + 0x38);

    lVar25 = param_1;

  }

  local_a0 = uVar21 >> 1;

  if (iVar19 != 0) {

    do {

      puVar37 = *(uint **)(lVar25 + 0x30);

      *(int *)(lVar25 + 0x3c) = (int)uVar31 + -1;

      iVar19 = *(int *)(lVar25 + 0x38);

      if (iVar19 != 0) {

        uVar31 = uVar22 >> 1;

        do {

          iVar19 = iVar19 + -1;

          puVar23 = (uint *)((uVar31 >> 0x10) * (ulonglong)uVar15 +

                             (longlong)*(int *)(lVar25 + 0x18) * (local_a0 >> 0x10) +

                            *(longlong *)(lVar25 + 8));

          if (iVar17 == 0) {

            uVar24 = (ulonglong)(byte)*puVar23;

            uVar38 = (ulonglong)(byte)*puVar23;

            lVar25 = *(longlong *)(lVar12 + 8);

            uVar39 = (uint)*(byte *)(lVar25 + uVar24 * 4);

            uVar33 = (ulonglong)*(byte *)(lVar25 + 1 + uVar24 * 4);

            uVar35 = (ulonglong)*(byte *)(lVar25 + 2 + uVar24 * 4);

            local_e8 = (uint)*(byte *)(lVar25 + 3 + uVar24 * 4);

LAB_1402a0b90:

            local_res18 = (uint)uVar33;

            local_res20 = (uint)uVar35;

          }

          else {

            if (iVar17 == 1) {

              if (uVar15 == 1) {

                uVar38 = (ulonglong)(byte)*puVar23;

              }

              else {

                if (uVar15 != 2) {

                  if (uVar15 == 3) {

                    uVar38 = 0;

                    local_e8 = 0xff;

                    uVar39 = (uint)*(byte *)((ulonglong)(*(byte *)(piVar8 + 7) >> 3) +

                                            (longlong)puVar23);

                    uVar33 = (ulonglong)

                             *(byte *)((ulonglong)(*(byte *)((longlong)piVar8 + 0x1d) >> 3) +

                                      (longlong)puVar23);

                    uVar35 = (ulonglong)

                             *(byte *)((ulonglong)(*(byte *)((longlong)piVar8 + 0x1e) >> 3) +

                                      (longlong)puVar23);

                  }

                  else {

                    if (uVar15 == 4) {

                      uVar38 = (ulonglong)*puVar23;

                      goto LAB_1402a0af9;

                    }

                    uVar38 = 0;

                    local_e8 = 0xff;

                    uVar35 = 0;

                    uVar33 = 0;

                    uVar39 = 0;

                  }

                  goto LAB_1402a0b90;

                }

                uVar38 = (ulonglong)(ushort)*puVar23;

              }

LAB_1402a0af9:

              local_e8 = 0xff;

              uVar39 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(piVar8 + 6)]

                                   [((uint)piVar8[2] & uVar38) >> (*(byte *)(piVar8 + 7) & 0x3f)];

              uVar33 = (ulonglong)

                       (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x19)]

                             [((uint)piVar8[3] & uVar38) >>

                              (*(byte *)((longlong)piVar8 + 0x1d) & 0x3f)];

              uVar35 = (ulonglong)

                       (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x1a)]

                             [((uint)piVar8[4] & uVar38) >>

                              (*(byte *)((longlong)piVar8 + 0x1e) & 0x3f)];

              goto LAB_1402a0b90;

            }

            if (iVar17 == 2) {

              if (uVar15 == 1) {

                uVar38 = (ulonglong)(byte)*puVar23;

              }

              else {

                if (uVar15 != 2) {

                  if (uVar15 == 3) {

                    uVar38 = 0;

                    local_e8 = 0xff;

                    uVar39 = (uint)*(byte *)((ulonglong)(*(byte *)(piVar8 + 7) >> 3) +

                                            (longlong)puVar23);

                    uVar33 = (ulonglong)

                             *(byte *)((ulonglong)(*(byte *)((longlong)piVar8 + 0x1d) >> 3) +

                                      (longlong)puVar23);

                    uVar35 = (ulonglong)

                             *(byte *)((ulonglong)(*(byte *)((longlong)piVar8 + 0x1e) >> 3) +

                                      (longlong)puVar23);

                  }

                  else if (uVar15 == 4) {

                    uVar20 = *puVar23;

                    uVar38 = (ulonglong)uVar20;

                    uVar39 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(piVar8 + 6)]

                                         [(piVar8[2] & uVar20) >> (*(byte *)(piVar8 + 7) & 0x3f)];

                    uVar33 = (ulonglong)

                             (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x19)]

                                   [(piVar8[3] & uVar20) >>

                                    (*(byte *)((longlong)piVar8 + 0x1d) & 0x3f)];

                    uVar35 = (ulonglong)

                             (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x1a)]

                                   [(piVar8[4] & uVar20) >>

                                    (*(byte *)((longlong)piVar8 + 0x1e) & 0x3f)];

                    local_e8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x1b)]

                                           [(uVar20 & piVar8[5]) >>

                                            (*(byte *)((longlong)piVar8 + 0x1f) & 0x3f)];

                  }

                  else {

                    uVar38 = 0;

                    uVar35 = 0;

                    uVar33 = 0;

                    local_e8 = 0;

                    uVar39 = 0;

                  }

                  goto LAB_1402a0b90;

                }

                uVar38 = (ulonglong)(ushort)*puVar23;

              }

              uVar39 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(piVar8 + 6)]

                                   [((uint)piVar8[2] & uVar38) >> (*(byte *)(piVar8 + 7) & 0x3f)];

              uVar33 = (ulonglong)

                       (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x19)]

                             [((uint)piVar8[3] & uVar38) >>

                              (*(byte *)((longlong)piVar8 + 0x1d) & 0x3f)];

              uVar35 = (ulonglong)

                       (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x1a)]

                             [((uint)piVar8[4] & uVar38) >>

                              (*(byte *)((longlong)piVar8 + 0x1e) & 0x3f)];

              local_e8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar8 + 0x1b)]

                                     [(uVar38 & (uint)piVar8[5]) >>

                                      (*(byte *)((longlong)piVar8 + 0x1f) & 0x3f)];

              goto LAB_1402a0b90;

            }

            if (iVar17 == 3) {

              iVar26 = *piVar8;

              uVar20 = *puVar23;

              uVar38 = (ulonglong)uVar20;

              if (iVar26 == 0x16172004) {

                local_e8 = 0xff;

                uVar39 = uVar20 >> 0x16 & 0xff;

                uVar33 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                uVar35 = (ulonglong)(uVar20 >> 2) & 0xff;

              }

              else {

                if (iVar26 == 0x16372004) {

                  uVar39 = uVar20 >> 0x16;

                  bVar13 = (byte)(uVar20 >> 2);

                }

                else {

                  if (iVar26 == 0x16572004) {

                    local_e8 = 0xff;

                    uVar39 = uVar20 >> 2 & 0xff;

                    uVar33 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                    uVar35 = (ulonglong)(uVar20 >> 0x16) & 0xff;

                    goto LAB_1402a0b90;

                  }

                  if (iVar26 != 0x16772004) goto LAB_1402a0ba0;

                  uVar39 = uVar20 >> 2;

                  bVar13 = (byte)(uVar20 >> 0x16);

                }

                uVar39 = uVar39 & 0xff;

                uVar33 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                uVar35 = (ulonglong)bVar13;

                local_e8 = (uint)(byte)PTR_DAT_1403e28b0[uVar20 >> 0x1e];

              }

              goto LAB_1402a0b90;

            }

          }

LAB_1402a0ba0:

          if ((uVar5 & 0x400) == 0) {

LAB_1402a0be8:

            if ((uVar5 & 0x3f0) != 0) {

              if (iVar18 == 0) {

                uVar24 = (ulonglong)(byte)*puVar37;

                lVar25 = *(longlong *)(lVar10 + 8);

                uVar28 = (uint)*(byte *)(lVar25 + uVar24 * 4);

                uVar27 = (ulonglong)*(byte *)(lVar25 + 1 + uVar24 * 4);

                uVar29 = (uint)*(byte *)(lVar25 + 2 + uVar24 * 4);

                uVar40 = (uint)*(byte *)(lVar25 + 3 + uVar24 * 4);

              }

              else if (iVar18 == 1) {

                if (uVar16 == 1) {

                  uVar24 = (ulonglong)(byte)*puVar37;

                }

                else {

                  if (uVar16 != 2) {

                    if (uVar16 == 3) {

                      uVar40 = 0xff;

                      uVar28 = (uint)*(byte *)((ulonglong)(*(byte *)(piVar9 + 7) >> 3) +

                                              (longlong)puVar37);

                      uVar27 = (ulonglong)

                               *(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1d) >> 3) +

                                        (longlong)puVar37);

                      uVar29 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1e) >> 3)

                                              + (longlong)puVar37);

                    }

                    else {

                      if (uVar16 == 4) {

                        uVar24 = (ulonglong)*puVar37;

                        goto LAB_1402a0e0a;

                      }

                      uVar29 = 0;

                      uVar27 = 0;

                      uVar28 = 0;

                      uVar40 = 0xff;

                    }

                    goto LAB_1402a0e85;

                  }

                  uVar24 = (ulonglong)(ushort)*puVar37;

                }

LAB_1402a0e0a:

                uVar40 = 0xff;

                uVar28 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(piVar9 + 6)]

                                     [((uint)piVar9[2] & uVar24) >> (*(byte *)(piVar9 + 7) & 0x3f)];

                uVar27 = (ulonglong)

                         (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar9 + 0x19)]

                               [((uint)piVar9[3] & uVar24) >>

                                (*(byte *)((longlong)piVar9 + 0x1d) & 0x3f)];

                uVar29 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar9 + 0x1a)]

                                     [((uint)piVar9[4] & uVar24) >>

                                      (*(byte *)((longlong)piVar9 + 0x1e) & 0x3f)];

              }

              else if (iVar18 == 2) {

                if (uVar16 == 1) {

                  uVar24 = (ulonglong)(byte)*puVar37;

                }

                else {

                  if (uVar16 != 2) {

                    if (uVar16 == 3) {

                      uVar40 = 0xff;

                      uVar28 = (uint)*(byte *)((ulonglong)(*(byte *)(piVar9 + 7) >> 3) +

                                              (longlong)puVar37);

                      uVar27 = (ulonglong)

                               *(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1d) >> 3) +

                                        (longlong)puVar37);

                      uVar29 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1e) >> 3)

                                              + (longlong)puVar37);

                    }

                    else {

                      if (uVar16 == 4) {

                        uVar24 = (ulonglong)*puVar37;

                        goto LAB_1402a0d2f;

                      }

                      uVar40 = 0;

                      uVar29 = 0;

                      uVar27 = 0;

                      uVar28 = 0;

                    }

                    goto LAB_1402a0e85;

                  }

                  uVar24 = (ulonglong)(ushort)*puVar37;

                }

LAB_1402a0d2f:

                uVar28 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(piVar9 + 6)]

                                     [((uint)piVar9[2] & uVar24) >> (*(byte *)(piVar9 + 7) & 0x3f)];

                uVar27 = (ulonglong)

                         (byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar9 + 0x19)]

                               [((uint)piVar9[3] & uVar24) >>

                                (*(byte *)((longlong)piVar9 + 0x1d) & 0x3f)];

                uVar29 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar9 + 0x1a)]

                                     [((uint)piVar9[4] & uVar24) >>

                                      (*(byte *)((longlong)piVar9 + 0x1e) & 0x3f)];

                uVar40 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)piVar9 + 0x1b)]

                                     [((uint)piVar9[5] & uVar24) >>

                                      (*(byte *)((longlong)piVar9 + 0x1f) & 0x3f)];

              }

              else if (iVar18 == 3) {

                iVar26 = *piVar9;

                uVar20 = *puVar37;

                if (iVar26 == 0x16172004) {

                  uVar40 = 0xff;

                  uVar28 = uVar20 >> 0x16 & 0xff;

                  uVar29 = uVar20 >> 2 & 0xff;

                  uVar27 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                }

                else if (iVar26 == 0x16372004) {

                  bVar13 = (byte)(uVar20 >> 0x16);

                  bVar14 = (byte)(uVar20 >> 2);

LAB_1402a0c8f:

                  uVar28 = (uint)bVar13;

                  uVar27 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                  uVar29 = (uint)bVar14;

                  uVar40 = (uint)(byte)PTR_DAT_1403e28b0[uVar20 >> 0x1e];

                }

                else if (iVar26 == 0x16572004) {

                  uVar40 = 0xff;

                  uVar28 = uVar20 >> 2 & 0xff;

                  uVar29 = uVar20 >> 0x16 & 0xff;

                  uVar27 = (ulonglong)(uVar20 >> 0xc) & 0xff;

                }

                else if (iVar26 == 0x16772004) {

                  bVar13 = (byte)(uVar20 >> 2);

                  bVar14 = (byte)(uVar20 >> 0x16);

                  goto LAB_1402a0c8f;

                }

              }

            }

LAB_1402a0e85:

            if ((uVar5 & 1) != 0) {

              uVar39 = (uVar39 * bVar1) / 0xff;

              local_res18 = ((int)uVar33 * (uint)bVar2) / 0xff;

              uVar33 = (ulonglong)local_res18;

              local_res20 = ((int)uVar35 * (uint)bVar3) / 0xff;

              uVar35 = (ulonglong)local_res20;

            }

            if ((uVar5 & 2) != 0) {

              local_e8 = (local_e8 * bVar4) / 0xff;

            }

            if (((uVar5 & 0x50) != 0) && (local_e8 < 0xff)) {

              uVar39 = (local_e8 * uVar39) / 0xff;

              local_res18 = (local_e8 * (int)uVar33) / 0xff;

              uVar33 = (ulonglong)local_res18;

              local_res20 = (local_e8 * (int)uVar35) / 0xff;

              uVar35 = (ulonglong)local_res20;

            }

            uVar20 = uVar5 & 0x3f0;

            iVar26 = (int)uVar27;

            iVar32 = (int)uVar33;

            uVar34 = (uint)uVar35;

            if (uVar20 < 0x41) {

              if (uVar20 == 0x40) {

LAB_1402a11b6:

                uVar28 = uVar28 + uVar39;

                if (0xff < uVar28) {

                  uVar28 = 0xff;

                }

                uVar27 = (ulonglong)(uint)(iVar26 + iVar32);

                if (0xff < (uint)(iVar26 + iVar32)) {

                  uVar27 = 0xff;

                }

                uVar29 = uVar29 + uVar34;

                if (0xff < uVar29) {

                  uVar29 = 0xff;

                }

              }

              else if (uVar20 == 0) {

                uVar27 = uVar33 & 0xffffffff;

                uVar28 = uVar39;

                uVar29 = uVar34;

                uVar40 = local_e8;

              }

              else if (uVar20 == 0x10) {

                iVar30 = 0xff - local_e8;

                uVar27 = (ulonglong)((uint)(iVar30 * iVar26) / 0xff + iVar32);

                uVar28 = (iVar30 * uVar28) / 0xff + uVar39;

                uVar29 = (iVar30 * uVar29) / 0xff + uVar34;

                uVar40 = (iVar30 * uVar40) / 0xff + local_e8;

              }

              else if (uVar20 == 0x20) {

                iVar30 = 0xff - local_e8;

                uVar28 = (iVar30 * uVar28) / 0xff + uVar39;

                if (0xff < uVar28) {

                  uVar28 = 0xff;

                }

                uVar20 = (uint)(iVar30 * iVar26) / 0xff + iVar32;

                if (0xff < uVar20) {

                  uVar20 = 0xff;

                }

                uVar27 = (ulonglong)uVar20;

                uVar29 = (iVar30 * uVar29) / 0xff + uVar34;

                if (0xff < uVar29) {

                  uVar29 = 0xff;

                }

                uVar40 = local_e8 + (iVar30 * uVar40) / 0xff;

                if (0xff < uVar40) {

                  uVar40 = 0xff;

                }

              }

            }

            else {

              if (uVar20 == 0x80) goto LAB_1402a11b6;

              if (uVar20 == 0x100) {

                uVar28 = (uVar28 * uVar39) / 0xff;

                uVar27 = (ulonglong)((uint)(iVar26 * iVar32) / 0xff);

                uVar29 = (uVar29 * uVar34) / 0xff;

              }

              else if (uVar20 == 0x200) {

                uVar28 = (((uVar39 - local_e8) + 0xff) * uVar28) / 0xff;

                if (0xff < uVar28) {

                  uVar28 = 0xff;

                }

                uVar20 = (((iVar32 - local_e8) + 0xff) * iVar26) / 0xff;

                if (0xff < uVar20) {

                  uVar20 = 0xff;

                }

                uVar27 = (ulonglong)uVar20;

                uVar29 = (((uVar34 - local_e8) + 0xff) * uVar29) / 0xff;

                if (0xff < uVar29) {

                  uVar29 = 0xff;

                }

              }

            }

            uVar20 = 0xff;

            uVar34 = (uint)uVar27;

            if (iVar18 == 0) {

              uVar20 = ((uVar28 << 8 | uVar34) << 8 | uVar29) << 8 | uVar40;

              if (uVar20 != local_d4) {

                local_res10 = FUN_14017bb00(uVar11,uVar20,lVar10);

                uVar33 = (ulonglong)local_res18;

                uVar35 = (ulonglong)local_res20;

                local_d4 = uVar20;

              }

              *(byte *)puVar37 = local_res10;

            }

            else if (iVar18 == 1) {

              if (uVar16 == 1) {

                *(byte *)puVar37 =

                     (char)(uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                     (char)(uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                     (char)(uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                     (*(byte *)(piVar9 + 7) & 0x1f) | *(byte *)(piVar9 + 5);

              }

              else if (uVar16 == 2) {

                *(ushort *)puVar37 =

                     (short)(uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                     (short)(uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                     (short)(uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                     (*(byte *)(piVar9 + 7) & 0x1f) | *(ushort *)(piVar9 + 5);

              }

              else if (uVar16 == 3) {

LAB_1402a1330:

                *(byte *)((ulonglong)(*(byte *)(piVar9 + 7) >> 3) + (longlong)puVar37) =

                     (byte)uVar28;

                *(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1d) >> 3) + (longlong)puVar37)

                     = (byte)uVar27;

                *(byte *)((ulonglong)(*(byte *)((longlong)piVar9 + 0x1e) >> 3) + (longlong)puVar37)

                     = (byte)uVar29;

              }

              else if (uVar16 == 4) {

                *puVar37 = (uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                           (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                           (uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                           (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                           (uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                           (*(byte *)(piVar9 + 7) & 0x1f) | piVar9[5];

              }

            }

            else if (iVar18 == 2) {

              if (uVar16 == 1) {

                *(char *)puVar37 =

                     (char)(uVar40 >> (8U - *(char *)((longlong)piVar9 + 0x1b) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1f) & 0x1f) |

                     (char)(uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                     (char)(uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                     (char)(uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                     (*(byte *)(piVar9 + 7) & 0x1f);

              }

              else if (uVar16 == 2) {

                *(short *)puVar37 =

                     (short)(uVar40 >> (8U - *(char *)((longlong)piVar9 + 0x1b) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1f) & 0x1f) |

                     (short)(uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                     (short)(uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                     (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                     (short)(uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                     (*(byte *)(piVar9 + 7) & 0x1f);

              }

              else {

                if (uVar16 == 3) goto LAB_1402a1330;

                if (uVar16 == 4) {

                  *puVar37 = (uVar40 >> (8U - *(char *)((longlong)piVar9 + 0x1b) & 0x1f)) <<

                             (*(byte *)((longlong)piVar9 + 0x1f) & 0x1f) |

                             (uVar29 >> (8U - *(char *)((longlong)piVar9 + 0x1a) & 0x1f)) <<

                             (*(byte *)((longlong)piVar9 + 0x1e) & 0x1f) |

                             (uVar34 >> (8U - *(char *)((longlong)piVar9 + 0x19) & 0x1f)) <<

                             (*(byte *)((longlong)piVar9 + 0x1d) & 0x1f) |

                             (uVar28 >> (8U - (char)piVar9[6] & 0x1f)) <<

                             (*(byte *)(piVar9 + 7) & 0x1f);

                }

              }

            }

            else if (iVar18 == 3) {

              iVar26 = *piVar9;

              uVar41 = uVar20;

              if ((iVar26 == 0x16172004) || (uVar41 = uVar40, iVar26 == 0x16372004)) {

                if (uVar28 == 0) {

                  uVar28 = 0;

                }

                else {

                  uVar28 = uVar28 * 4 | 3;

                }

                if (uVar34 == 0) {

                  uVar27 = 0;

                }

                else {

                  uVar27 = (ulonglong)(uVar34 * 4 | 3);

                }

                if (uVar29 == 0) {

                  uVar29 = 0;

                }

                else {

                  uVar29 = uVar29 * 4 | 3;

                }

                uVar40 = (uVar41 * 3) / 0xff;

                *puVar37 = ((uVar40 << 10 | uVar28) << 10 | (uint)uVar27) << 10 | uVar29;

              }

              else if ((iVar26 == 0x16572004) || (uVar20 = uVar40, iVar26 == 0x16772004)) {

                if (uVar28 == 0) {

                  uVar28 = 0;

                }

                else {

                  uVar28 = uVar28 * 4 | 3;

                }

                if (uVar34 == 0) {

                  uVar27 = 0;

                }

                else {

                  uVar27 = (ulonglong)(uVar34 * 4 | 3);

                }

                if (uVar29 == 0) {

                  uVar29 = 0;

                }

                else {

                  uVar29 = uVar29 * 4 | 3;

                }

                uVar40 = (uVar20 * 3) / 0xff;

                *puVar37 = ((uVar40 << 10 | uVar29) << 10 | (uint)uVar27) << 10 | uVar28;

              }

              else {

                *puVar37 = 0;

              }

            }

          }

          else {

            if (uVar15 == 3) {

              uVar38 = (ulonglong)

                       ((int)uVar35 << (*(byte *)((longlong)piVar8 + 0x1e) & 0x1f) |

                        (int)uVar33 << (*(byte *)((longlong)piVar8 + 0x1d) & 0x1f) |

                       uVar39 << (*(byte *)(piVar8 + 7) & 0x1f));

            }

            if ((~uVar7 & (uint)uVar38) != (uVar6 & ~uVar7)) goto LAB_1402a0be8;

          }

          puVar37 = (uint *)((longlong)puVar37 + (ulonglong)uVar16);

          uVar31 = uVar31 + uVar22;

          lVar25 = param_1;

        } while (iVar19 != 0);

      }

      local_a0 = local_a0 + uVar21;

      *(longlong *)(lVar25 + 0x30) =

           *(longlong *)(lVar25 + 0x30) + (longlong)*(int *)(lVar25 + 0x40);

      uVar31 = (ulonglong)*(uint *)(lVar25 + 0x3c);

    } while (*(uint *)(lVar25 + 0x3c) != 0);

  }

  *(undefined4 *)(lVar25 + 0x3c) = 0xffffffff;

  return;

}




