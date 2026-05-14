// Address: 0x14025fef0
// Ghidra name: FUN_14025fef0
// ============ 0x14025fef0 FUN_14025fef0 (size=3749) ============


void FUN_14025fef0(longlong *param_1,undefined8 param_2,longlong param_3,int param_4,int param_5,

                  int param_6,int param_7,int param_8,int param_9,int param_10,int param_11,

                  int param_12,int param_13,int param_14,int param_15,int param_16,int param_17,

                  int param_18,int param_19,int param_20,uint param_21,uint param_22,uint param_23,

                  char param_24,int param_25,int param_26)



{

  byte bVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  int iVar12;

  int iVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  int iVar16;

  int iVar17;

  uint *puVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  uint uVar22;

  uint *puVar23;

  uint uVar24;

  uint uVar25;

  uint uVar26;

  uint uVar27;

  uint uVar28;

  longlong lVar29;

  longlong lVar30;

  int iVar31;

  int iVar32;

  longlong *plVar34;

  uint uVar35;

  uint uVar36;

  int iStackX_14;

  uint local_res18;

  uint local_f8;

  int local_f4;

  longlong local_d8;

  longlong local_c8;

  longlong local_c0;

  int local_a8;

  ulonglong local_88;

  ulonglong local_80;

  ulonglong local_78;

  ulonglong local_70;

  undefined8 uVar33;

  

  lVar7 = *param_1;

  lVar8 = param_1[9];

  lVar9 = param_1[0xb];

  lVar10 = *(longlong *)(lVar7 + 0x48);

  bVar1 = *(byte *)(lVar8 + 5);

  bVar2 = *(byte *)(lVar9 + 5);

  lVar29 = param_1[6];

  uVar3 = *(uint *)(param_1 + 0xf);

  local_88 = (ulonglong)*(byte *)(param_1 + 0x10);

  local_80 = (ulonglong)*(byte *)((longlong)param_1 + 0x81);

  local_78 = (ulonglong)*(byte *)((longlong)param_1 + 0x82);

  local_70 = (ulonglong)*(byte *)((longlong)param_1 + 0x83);

  uVar4 = *(uint *)((longlong)param_1 + 0x7c);

  uVar5 = *(uint *)(lVar8 + 0x14);

  uVar33 = param_2;

  plVar34 = param_1;

  iVar12 = FUN_1402630c0(lVar9);

  iVar32 = (int)uVar33;

  iVar6 = *(int *)(param_3 + 0xc);

  local_a8 = 0;

  iVar31 = iVar6;

  iVar13 = FUN_1402630c0(lVar8);

  if (0 < iVar31) {

    lVar11 = plVar34[8];

    iVar31 = *(int *)(param_3 + 8);

    do {

      local_c8 = (longlong)param_19;

      local_c0 = (longlong)param_20;

      local_d8 = (longlong)param_18;

      local_f4 = 0;

      if (0 < iVar31) {

        do {

          uVar26 = (uint)bVar1;

          if (((local_d8 + param_5 < 0) || (param_6 + local_c8 < 0)) || (param_7 + local_c0 < 0)) {

LAB_140260cb3:

            local_d8 = local_d8 + param_8;

            local_c8 = local_c8 + param_10;

            local_c0 = local_c0 + param_12;

          }

          else {

            puVar23 = (uint *)((int)(local_f4 * (uint)bVar2) + lVar29);

            uVar14 = (param_15 * local_c8 + param_14 * local_d8 + (longlong)iVar32) /

                     (longlong)param_4;

            iStackX_14 = (int)((ulonglong)param_2 >> 0x20);

            uVar15 = (param_17 * local_c8 + param_16 * local_d8 + (longlong)iStackX_14) /

                     (longlong)param_4;

            iVar16 = (int)uVar15;

            iVar17 = (int)uVar14;

            if (param_25 == 1) {

              if (iVar17 < 0) {

                iVar17 = 0;

              }

              else if (*(int *)(lVar7 + 8) <= iVar17) {

                iVar17 = *(int *)(lVar7 + 8) + -1;

              }

            }

            else if (param_25 == 2) {

              iVar17 = (int)((longlong)

                             ((ulonglong)(uint)(iVar17 >> 0x1f) << 0x20 | uVar14 & 0xffffffff) %

                            (longlong)*(int *)(lVar7 + 8));

              if (iVar17 < 0) {

                iVar17 = iVar17 + -1 + *(int *)(lVar7 + 8);

              }

            }

            if (param_26 == 1) {

              if (iVar16 < 0) {

                iVar16 = 0;

              }

              else if (*(int *)(lVar7 + 0xc) <= iVar16) {

                iVar16 = *(int *)(lVar7 + 0xc) + -1;

              }

            }

            else if (param_26 == 2) {

              iVar16 = (int)((longlong)

                             ((ulonglong)(uint)(iVar16 >> 0x1f) << 0x20 | uVar15 & 0xffffffff) %

                            (longlong)*(int *)(lVar7 + 0xc));

              if (iVar16 < 0) {

                iVar16 = iVar16 + -1 + *(int *)(lVar7 + 0xc);

              }

            }

            puVar18 = (uint *)((longlong)(iVar16 * (int)param_1[3]) +

                               (longlong)(int)(iVar17 * uVar26) + param_1[1]);

            if (iVar13 == -2) {

              uVar14 = (ulonglong)(byte)*puVar18;

              lVar30 = *(longlong *)(lVar10 + 8);

              uVar35 = (uint)*(byte *)(lVar30 + uVar14 * 4);

              uVar36 = (uint)*(byte *)(lVar30 + 1 + uVar14 * 4);

              local_res18 = (uint)*(byte *)(lVar30 + 2 + uVar14 * 4);

              local_f8 = (uint)*(byte *)(lVar30 + 3 + uVar14 * 4);

LAB_1402603f4:

              uVar26 = (uint)uVar14;

            }

            else {

              if (iVar13 != 0) {

                if (iVar13 < 0) {

                  if (uVar26 == 1) {

                    uVar14 = (ulonglong)(byte)*puVar18;

                  }

                  else {

                    if (uVar26 != 2) {

                      if (uVar26 == 3) {

                        uVar26 = 0;

                        local_f8 = 0xff;

                        uVar35 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) +

                                                (longlong)puVar18);

                        uVar36 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) +

                                                (longlong)puVar18);

                        local_res18 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) +

                                                     (longlong)puVar18);

                      }

                      else {

                        if (uVar26 == 4) {

                          uVar14 = (ulonglong)*puVar18;

                          goto LAB_14026035e;

                        }

                        uVar26 = 0;

                        local_f8 = 0xff;

                        local_res18 = 0;

                        uVar36 = 0;

                        uVar35 = 0;

                      }

                      goto LAB_1402603f8;

                    }

                    uVar14 = (ulonglong)(ushort)*puVar18;

                  }

LAB_14026035e:

                  uVar26 = (uint)uVar14;

                  local_f8 = 0xff;

                  uVar35 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                                       [(*(uint *)(lVar8 + 8) & uVar14) >>

                                        (*(byte *)(lVar8 + 0x1c) & 0x3f)];

                  uVar36 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                                       [(*(uint *)(lVar8 + 0xc) & uVar14) >>

                                        (*(byte *)(lVar8 + 0x1d) & 0x3f)];

                  local_res18 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                                            [(*(uint *)(lVar8 + 0x10) & uVar14) >>

                                             (*(byte *)(lVar8 + 0x1e) & 0x3f)];

                  goto LAB_1402603f8;

                }

                uVar26 = *puVar18;

                uVar14 = (ulonglong)uVar26;

                uVar35 = uVar26 >> 0x16 & 0xff;

                uVar36 = uVar26 >> 0xc & 0xff;

                local_res18 = uVar26 >> 2 & 0xff;

                local_f8 = (uint)(byte)PTR_DAT_1403e28b0[uVar26 >> 0x1e];

                goto LAB_1402603f4;

              }

              if (uVar26 == 1) {

                uVar14 = (ulonglong)(byte)*puVar18;

LAB_140260218:

                uVar35 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                                     [(*(uint *)(lVar8 + 8) & uVar14) >>

                                      (*(byte *)(lVar8 + 0x1c) & 0x3f)];

                uVar36 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                                     [(*(uint *)(lVar8 + 0xc) & uVar14) >>

                                      (*(byte *)(lVar8 + 0x1d) & 0x3f)];

                local_res18 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                                          [(*(uint *)(lVar8 + 0x10) & uVar14) >>

                                           (*(byte *)(lVar8 + 0x1e) & 0x3f)];

                local_f8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1b)]

                                       [(*(uint *)(lVar8 + 0x14) & uVar14) >>

                                        (*(byte *)(lVar8 + 0x1f) & 0x3f)];

                goto LAB_1402603f4;

              }

              if (uVar26 == 2) {

                uVar14 = (ulonglong)(ushort)*puVar18;

                goto LAB_140260218;

              }

              if (uVar26 == 3) {

                uVar26 = 0;

                local_f8 = 0xff;

                uVar35 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) +

                                        (longlong)puVar18);

                uVar36 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) +

                                        (longlong)puVar18);

                local_res18 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) +

                                             (longlong)puVar18);

              }

              else {

                if (uVar26 == 4) {

                  uVar14 = (ulonglong)*puVar18;

                  goto LAB_140260218;

                }

                uVar26 = 0;

                local_res18 = 0;

                uVar36 = 0;

                local_f8 = 0;

                uVar35 = 0;

              }

            }

LAB_1402603f8:

            if ((uVar3 >> 10 & 1) == 0) {

LAB_14026043f:

              uVar26 = uVar3 & 0x350;

              if (uVar26 == 0) {

LAB_140260653:

                uVar27 = 0;

                uVar19 = 0;

                uVar21 = 0;

                uVar24 = 0;

              }

              else if (iVar12 == 0) {

                if (bVar2 == 1) {

                  uVar14 = (ulonglong)(byte)*puVar23;

                }

                else if (bVar2 == 2) {

                  uVar14 = (ulonglong)(ushort)*puVar23;

                }

                else {

                  if (bVar2 == 3) {

                    uVar27 = 0xff;

                    uVar24 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1c) >> 3) +

                                            (longlong)puVar23);

                    uVar21 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1d) >> 3) +

                                            (longlong)puVar23);

                    uVar19 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1e) >> 3) +

                                            (longlong)puVar23);

                    goto LAB_14026065b;

                  }

                  if (bVar2 != 4) goto LAB_140260653;

                  uVar14 = (ulonglong)*puVar23;

                }

                uVar24 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                     [(*(uint *)(lVar9 + 8) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1c) & 0x3f)];

                uVar21 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                     [(*(uint *)(lVar9 + 0xc) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1d) & 0x3f)];

                uVar19 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                     [(*(uint *)(lVar9 + 0x10) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1e) & 0x3f)];

                uVar27 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1b)]

                                     [(*(uint *)(lVar9 + 0x14) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1f) & 0x3f)];

              }

              else if (iVar12 < 0) {

                if (bVar2 == 1) {

                  uVar14 = (ulonglong)(byte)*puVar23;

                }

                else {

                  if (bVar2 != 2) {

                    if (bVar2 == 3) {

                      uVar27 = 0xff;

                      uVar24 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1c) >> 3) +

                                              (longlong)puVar23);

                      uVar21 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1d) >> 3) +

                                              (longlong)puVar23);

                      uVar19 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1e) >> 3) +

                                              (longlong)puVar23);

                    }

                    else {

                      if (bVar2 == 4) {

                        uVar14 = (ulonglong)*puVar23;

                        goto LAB_1402605c5;

                      }

                      uVar19 = 0;

                      uVar21 = 0;

                      uVar24 = 0;

                      uVar27 = 0xff;

                    }

                    goto LAB_14026065b;

                  }

                  uVar14 = (ulonglong)(ushort)*puVar23;

                }

LAB_1402605c5:

                uVar24 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                     [(*(uint *)(lVar9 + 8) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1c) & 0x3f)];

                uVar21 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                     [(*(uint *)(lVar9 + 0xc) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1d) & 0x3f)];

                uVar27 = 0xff;

                uVar19 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                     [(*(uint *)(lVar9 + 0x10) & uVar14) >>

                                      (*(byte *)(lVar9 + 0x1e) & 0x3f)];

              }

              else {

                uVar27 = *puVar23;

                uVar24 = uVar27 >> 0x16 & 0xff;

                uVar21 = uVar27 >> 0xc & 0xff;

                uVar19 = uVar27 >> 2 & 0xff;

                uVar27 = (uint)(byte)PTR_DAT_1403e28b0[uVar27 >> 0x1e];

              }

LAB_14026065b:

              if (param_24 == '\0') {

                lVar30 = (longlong)param_4;

                local_88 = (longlong)

                           ((ulonglong)(param_23 & 0xff) * local_c0 +

                            (ulonglong)(param_22 & 0xff) * local_c8 +

                           (ulonglong)(param_21 & 0xff) * local_d8) / lVar30;

                local_80 = (longlong)

                           ((ulonglong)param_23._1_1_ * local_c0 +

                            (ulonglong)param_22._1_1_ * local_c8 +

                           (ulonglong)param_21._1_1_ * local_d8) / lVar30;

                local_78 = (longlong)

                           ((ulonglong)param_23._2_1_ * local_c0 +

                            (ulonglong)param_22._2_1_ * local_c8 +

                           (ulonglong)param_21._2_1_ * local_d8) / lVar30;

                local_70 = (longlong)

                           ((ulonglong)param_23._3_1_ * local_c0 +

                            (ulonglong)param_22._3_1_ * local_c8 +

                           (ulonglong)param_21._3_1_ * local_d8) / lVar30;

              }

              if ((uVar3 & 1) != 0) {

                uVar35 = (uVar35 * (int)local_88) / 0xff;

                uVar36 = (uVar36 * (int)local_80) / 0xff;

                local_res18 = (local_res18 * (int)local_78) / 0xff;

              }

              if ((uVar3 & 2) != 0) {

                local_f8 = (local_f8 * (int)local_70) / 0xff;

              }

              if (((uVar3 & 0x50) != 0) && (local_f8 < 0xff)) {

                uVar35 = (local_f8 * uVar35) / 0xff;

                uVar36 = (local_f8 * uVar36) / 0xff;

                local_res18 = (local_f8 * local_res18) / 0xff;

              }

              uVar20 = local_res18;

              uVar25 = uVar35;

              uVar22 = uVar36;

              uVar28 = local_f8;

              if (uVar26 != 0) {

                if (uVar26 == 0x10) {

                  iVar17 = 0xff - local_f8;

                  uVar20 = (uVar19 * iVar17) / 0xff + local_res18;

                  uVar25 = (uVar24 * iVar17) / 0xff + uVar35;

                  uVar22 = (uVar21 * iVar17) / 0xff + uVar36;

                  uVar28 = (uVar27 * iVar17) / 0xff + local_f8;

                }

                else {

                  uVar28 = uVar27;

                  if (uVar26 == 0x40) {

                    uVar25 = uVar24 + uVar35;

                    if (0xff < uVar25) {

                      uVar25 = 0xff;

                    }

                    uVar22 = uVar21 + uVar36;

                    if (0xff < uVar22) {

                      uVar22 = 0xff;

                    }

                    uVar20 = uVar19 + local_res18;

                    if (0xff < uVar19 + local_res18) {

                      uVar20 = 0xff;

                    }

                  }

                  else if (uVar26 == 0x100) {

                    uVar20 = (uVar19 * local_res18) / 0xff;

                    uVar25 = (uVar24 * uVar35) / 0xff;

                    uVar22 = (uVar21 * uVar36) / 0xff;

                  }

                  else {

                    uVar20 = uVar19;

                    uVar25 = uVar24;

                    uVar22 = uVar21;

                    if (uVar26 == 0x200) {

                      uVar25 = (((uVar35 - local_f8) + 0xff) * uVar24) / 0xff;

                      if (0xff < uVar25) {

                        uVar25 = 0xff;

                      }

                      uVar22 = (((uVar36 - local_f8) + 0xff) * uVar21) / 0xff;

                      if (0xff < uVar22) {

                        uVar22 = 0xff;

                      }

                      uVar20 = (((local_res18 - local_f8) + 0xff) * uVar19) / 0xff;

                      if (0xff < uVar20) {

                        uVar20 = 0xff;

                      }

                    }

                  }

                }

              }

              if (iVar12 == 0) {

                if (bVar2 == 1) {

                  *(char *)puVar23 =

                       (char)(uVar28 >> (8U - *(char *)(lVar9 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1f) & 0x1f) |

                       (char)(uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                       (char)(uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                       (char)(uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1c) & 0x1f);

                }

                else if (bVar2 == 2) {

                  *(short *)puVar23 =

                       (short)(uVar28 >> (8U - *(char *)(lVar9 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1f) & 0x1f) |

                       (short)(uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                       (short)(uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                       (short)(uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1c) & 0x1f);

                }

                else if (bVar2 == 3) {

LAB_140260a28:

                  *(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1c) >> 3) + (longlong)puVar23) =

                       (byte)uVar25;

                  *(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1d) >> 3) + (longlong)puVar23) =

                       (byte)uVar22;

                  *(byte *)((ulonglong)(*(byte *)(lVar9 + 0x1e) >> 3) + (longlong)puVar23) =

                       (byte)uVar20;

                }

                else if (bVar2 == 4) {

                  *puVar23 = (uVar28 >> (8U - *(char *)(lVar9 + 0x1b) & 0x1f)) <<

                             (*(byte *)(lVar9 + 0x1f) & 0x1f) |

                             (uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                             (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                             (uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                             (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                             (uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                             (*(byte *)(lVar9 + 0x1c) & 0x1f);

                }

              }

              else if (iVar12 < 0) {

                if (bVar2 == 1) {

                  *(byte *)puVar23 =

                       (char)(uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                       (char)(uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                       (char)(uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1c) & 0x1f) | *(byte *)(lVar9 + 0x14);

                }

                else if (bVar2 == 2) {

                  *(ushort *)puVar23 =

                       (short)(uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                       (short)(uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                       (short)(uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar9 + 0x1c) & 0x1f) | *(ushort *)(lVar9 + 0x14);

                }

                else {

                  if (bVar2 == 3) goto LAB_140260a28;

                  if (bVar2 == 4) {

                    *puVar23 = (uVar20 >> (8U - *(char *)(lVar9 + 0x1a) & 0x1f)) <<

                               (*(byte *)(lVar9 + 0x1e) & 0x1f) |

                               (uVar22 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                               (*(byte *)(lVar9 + 0x1d) & 0x1f) |

                               (uVar25 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                               (*(byte *)(lVar9 + 0x1c) & 0x1f) | *(uint *)(lVar9 + 0x14);

                  }

                }

              }

              else {

                if (uVar25 == 0) {

                  uVar26 = 0;

                }

                else {

                  uVar26 = uVar25 << 0x16 | 0x300000;

                }

                if (uVar22 == 0) {

                  uVar35 = 0;

                }

                else {

                  uVar35 = uVar22 << 0xc | 0xc00;

                }

                if (uVar20 == 0) {

                  uVar36 = 0;

                }

                else {

                  uVar36 = uVar20 * 4 | 3;

                }

                *puVar23 = (uVar28 * 3) / 0xff << 0x1e | uVar35 | uVar26 | uVar36;

              }

              goto LAB_140260cb3;

            }

            if (bVar1 == 3) {

              uVar26 = local_res18 << (*(byte *)(lVar8 + 0x1e) & 0x1f) |

                       uVar36 << (*(byte *)(lVar8 + 0x1d) & 0x1f) |

                       uVar35 << (*(byte *)(lVar8 + 0x1c) & 0x1f);

            }

            if ((uVar26 & ~uVar5) != (uVar4 & ~uVar5)) goto LAB_14026043f;

          }

          local_f4 = local_f4 + 1;

        } while (local_f4 < iVar31);

      }

      local_a8 = local_a8 + 1;

      param_19 = param_19 + param_11;

      param_18 = param_18 + param_9;

      lVar29 = lVar29 + (int)lVar11;

      param_20 = param_20 + param_13;

    } while (local_a8 < iVar6);

  }

  return;

}




