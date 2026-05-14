// Address: 0x140245b20
// Ghidra name: FUN_140245b20
// ============ 0x140245b20 FUN_140245b20 (size=4578) ============


undefined8

FUN_140245b20(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  ushort uVar1;

  ushort uVar2;

  ushort uVar3;

  uint uVar4;

  ulonglong uVar5;

  int iVar6;

  ushort *puVar7;

  ushort uVar8;

  int iVar9;

  ushort uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  ushort uVar17;

  int iVar18;

  uint uVar19;

  

  uVar11 = (uint)param_4;

  iVar9 = 0xff - (uint)param_7;

  uVar8 = (ushort)param_4;

  switch(param_3) {

  case 1:

    uVar11 = param_2[2];

    iVar18 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar18 - uVar11;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar18 * param_2[1]) + (longlong)*param_2) * 2);

    uVar19 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar19;

      if (uVar19 == 0) break;

      iVar18 = (int)(((int)(uVar11 + 3) >> 0x1f & 3U) + uVar11 + 3) >> 2;

      uVar15 = uVar11 & 3;

      uVar10 = (ushort)param_5;

      uVar13 = (uint)param_6;

      if (uVar15 == 0) goto LAB_140245c0a;

      if (uVar15 == 1) goto LAB_140245dde;

      if (uVar15 == 2) goto LAB_140245d42;

      if (uVar15 == 3) {

        while( true ) {

          uVar17 = *puVar7;

          *puVar7 = ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 10 & 0x1f] * iVar9)

                            / 0xff) + uVar8) * 0x80 & 0xfc1f |

                    ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 5 & 0x1f] * iVar9)

                            / 0xff) + uVar10) * 4 & 0xffe0 |

                    (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar17 & 0x1f] * iVar9) / 0xff + uVar13

                            >> 3);

          puVar7 = puVar7 + 1;

LAB_140245d42:

          uVar17 = *puVar7;

          *puVar7 = ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 10 & 0x1f] * iVar9)

                            / 0xff) + uVar8) * 0x80 & 0xfc1f |

                    ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 5 & 0x1f] * iVar9)

                            / 0xff) + uVar10) * 4 & 0xffe0 |

                    (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar17 & 0x1f] * iVar9) / 0xff + uVar13

                            >> 3);

          puVar7 = puVar7 + 1;

LAB_140245dde:

          uVar17 = *puVar7;

          iVar18 = iVar18 + -1;

          *puVar7 = ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 10 & 0x1f] * iVar9)

                            / 0xff) + uVar8) * 0x80 & 0xfc1f |

                    ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 5 & 0x1f] * iVar9)

                            / 0xff) + uVar10) * 4 & 0xffe0 |

                    (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar17 & 0x1f] * iVar9) / 0xff + uVar13

                            >> 3);

          puVar7 = puVar7 + 1;

          if (iVar18 < 1) break;

LAB_140245c0a:

          uVar17 = *puVar7;

          *puVar7 = ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 10 & 0x1f] * iVar9)

                            / 0xff) + uVar8) * 0x80 & 0xfc1f |

                    ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar17 >> 5 & 0x1f] * iVar9)

                            / 0xff) + uVar10) * 4 & 0xffe0 |

                    (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar17 & 0x1f] * iVar9) / 0xff + uVar13

                            >> 3);

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar6;

        uVar19 = uVar19 - 1;

      }

      else {

        puVar7 = puVar7 + iVar6;

        uVar19 = uVar19 - 1;

      }

    }

    break;

  case 2:

  case 0x20:

    uVar11 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar18 = iVar9 - uVar11;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

    uVar19 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar19;

      if (uVar19 == 0) break;

      iVar9 = (int)(((int)(uVar11 + 3) >> 0x1f & 3U) + uVar11 + 3) >> 2;

      uVar13 = uVar11 & 3;

      uVar12 = 0xff;

      uVar10 = (ushort)param_4;

      uVar17 = 0xff;

      uVar8 = (ushort)param_5;

      uVar15 = (uint)param_6;

      if (uVar13 == 0) goto LAB_140246298;

      if (uVar13 == 1) goto LAB_1402463fa;

      if (uVar13 == 2) goto LAB_140246384;

      if (uVar13 == 3) {

        while( true ) {

          uVar1 = *puVar7;

          uVar2 = (byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10)) {

            uVar2 = uVar17;

          }

          uVar3 = (byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8)) {

            uVar3 = uVar17;

          }

          uVar13 = (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15) {

            uVar13 = uVar12;

          }

          *puVar7 = ((uVar2 & 0xfff8) << 5 | uVar3 & 0xfff8) << 2 | (ushort)(uVar13 >> 3);

          puVar7 = puVar7 + 1;

LAB_140246384:

          uVar1 = *puVar7;

          uVar2 = (byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10)) {

            uVar2 = uVar17;

          }

          uVar3 = (byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8)) {

            uVar3 = uVar17;

          }

          uVar13 = (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15) {

            uVar13 = uVar12;

          }

          *puVar7 = ((uVar2 & 0xfff8) << 5 | uVar3 & 0xfff8) << 2 | (ushort)(uVar13 >> 3);

          puVar7 = puVar7 + 1;

LAB_1402463fa:

          uVar1 = *puVar7;

          uVar2 = (byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10)) {

            uVar2 = uVar17;

          }

          uVar3 = (byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8)) {

            uVar3 = uVar17;

          }

          uVar13 = (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15) {

            uVar13 = 0xff;

          }

          iVar9 = iVar9 + -1;

          *puVar7 = ((uVar2 & 0xfff8) << 5 | uVar3 & 0xfff8) << 2 | (ushort)(uVar13 >> 3);

          puVar7 = puVar7 + 1;

          if (iVar9 < 1) break;

LAB_140246298:

          uVar1 = *puVar7;

          uVar2 = (byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 10 & 0x1f] + uVar10)) {

            uVar2 = uVar17;

          }

          uVar3 = (byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar1 >> 5 & 0x1f] + uVar8)) {

            uVar3 = uVar17;

          }

          uVar13 = (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] + uVar15) {

            uVar13 = uVar12;

          }

          *puVar7 = ((uVar2 & 0xfff8) << 5 | uVar3 & 0xfff8) << 2 | (ushort)(uVar13 >> 3);

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar18;

        uVar19 = uVar19 - 1;

      }

      else {

        puVar7 = puVar7 + iVar18;

        uVar19 = uVar19 - 1;

      }

    }

    break;

  default:

    uVar11 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar18 = iVar9 - uVar11;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

    uVar19 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar19;

      if (uVar19 == 0) break;

      iVar9 = (int)(((int)(uVar11 + 3) >> 0x1f & 3U) + uVar11 + 3) >> 2;

      uVar15 = uVar11 & 3;

      uVar10 = (ushort)param_5;

      uVar8 = (ushort)param_4;

      if (uVar15 == 0) goto LAB_140246c11;

      if (uVar15 == 1) goto LAB_140246ca1;

      if (uVar15 == 2) goto LAB_140246c71;

      if (uVar15 == 3) {

        while( true ) {

          *puVar7 = ((uVar8 & 0xfff8) << 5 | uVar10 & 0xfff8) << 2 | (ushort)(param_6 >> 3);

          puVar7 = puVar7 + 1;

LAB_140246c71:

          *puVar7 = ((uVar8 & 0xfff8) << 5 | uVar10 & 0xfff8) << 2 | (ushort)(param_6 >> 3);

          puVar7 = puVar7 + 1;

LAB_140246ca1:

          iVar9 = iVar9 + -1;

          *puVar7 = ((uVar8 & 0xfff8) << 5 | uVar10 & 0xfff8) << 2 | (ushort)(param_6 >> 3);

          puVar7 = puVar7 + 1;

          if (iVar9 < 1) break;

LAB_140246c11:

          *puVar7 = ((uVar8 & 0xfff8) << 5 | uVar10 & 0xfff8) << 2 | (ushort)(param_6 >> 3);

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar18;

        uVar19 = uVar19 - 1;

      }

      else {

        puVar7 = puVar7 + iVar18;

        uVar19 = uVar19 - 1;

      }

    }

    break;

  case 4:

    uVar19 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar18 = iVar9 - uVar19;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar9 = (int)(((int)(uVar19 + 3) >> 0x1f & 3U) + uVar19 + 3) >> 2;

      uVar14 = uVar19 & 3;

      uVar13 = (uint)param_5;

      uVar12 = (uint)param_6;

      if (uVar14 == 0) goto LAB_14024651e;

      if (uVar14 == 1) goto LAB_1402466aa;

      if (uVar14 == 2) goto LAB_140246626;

      if (uVar14 == 3) {

        while( true ) {

          uVar8 = *puVar7;

          *puVar7 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * uVar11) / 0xff) &

                     0xfff8) << 5 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * uVar13) / 0xff

                            ) & 0xfff8) << 2 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar12) / 0xff >> 3

                            );

          puVar7 = puVar7 + 1;

LAB_140246626:

          uVar8 = *puVar7;

          *puVar7 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * uVar11) / 0xff) &

                     0xfff8) << 5 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * uVar13) / 0xff

                            ) & 0xfff8) << 2 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar12) / 0xff >> 3

                            );

          puVar7 = puVar7 + 1;

LAB_1402466aa:

          uVar8 = *puVar7;

          iVar9 = iVar9 + -1;

          *puVar7 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * uVar11) / 0xff) &

                     0xfff8) << 5 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * uVar13) / 0xff

                            ) & 0xfff8) << 2 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar12) / 0xff >> 3

                            );

          puVar7 = puVar7 + 1;

          if (iVar9 < 1) break;

LAB_14024651e:

          uVar8 = *puVar7;

          *puVar7 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * uVar11) / 0xff) &

                     0xfff8) << 5 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * uVar13) / 0xff

                            ) & 0xfff8) << 2 |

                    (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar12) / 0xff >> 3

                            );

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar18;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar7 = puVar7 + iVar18;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  case 8:

    uVar19 = param_2[2];

    uVar13 = (uint)param_6;

    uVar12 = (uint)param_5;

    iVar18 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar18 - uVar19;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar18 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar18 = (int)(((int)(uVar19 + 3) >> 0x1f & 3U) + uVar19 + 3) >> 2;

      uVar14 = uVar19 & 3;

      if (uVar14 == 0) goto LAB_1402467e3;

      if (uVar14 == 1) goto LAB_140246a86;

      if (uVar14 == 2) goto LAB_1402469a5;

      if (uVar14 == 3) {

        while( true ) {

          uVar8 = *puVar7;

          uVar14 = (uVar11 * (byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar14) {

            uVar14 = 0xff;

          }

          uVar16 = (uVar12 * (byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          uVar4 = (uVar13 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar7 = (((ushort)uVar14 & 0xfff8) << 5 | (ushort)uVar16 & 0xfff8) << 2 |

                    (ushort)(uVar4 >> 3);

          puVar7 = puVar7 + 1;

LAB_1402469a5:

          uVar8 = *puVar7;

          uVar14 = (uVar11 * (byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar14) {

            uVar14 = 0xff;

          }

          uVar16 = (uVar12 * (byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          uVar4 = (uVar13 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar7 = (((ushort)uVar14 & 0xfff8) << 5 | (ushort)uVar16 & 0xfff8) << 2 |

                    (ushort)(uVar4 >> 3);

          puVar7 = puVar7 + 1;

LAB_140246a86:

          uVar8 = *puVar7;

          uVar14 = (uVar11 * (byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar14) {

            uVar14 = 0xff;

          }

          uVar16 = (uVar12 * (byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          uVar4 = (uVar13 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          iVar18 = iVar18 + -1;

          *puVar7 = (((ushort)uVar14 & 0xfff8) << 5 | (ushort)uVar16 & 0xfff8) << 2 |

                    (ushort)(uVar4 >> 3);

          puVar7 = puVar7 + 1;

          if (iVar18 < 1) break;

LAB_1402467e3:

          uVar8 = *puVar7;

          uVar14 = (uVar11 * (byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar14) {

            uVar14 = 0xff;

          }

          uVar16 = (uVar12 * (byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          uVar4 = (uVar13 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar7 = (((ushort)uVar14 & 0xfff8) << 5 | (ushort)uVar16 & 0xfff8) << 2 |

                    (ushort)(uVar4 >> 3);

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar6;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar7 = puVar7 + iVar6;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  case 0x10:

    uVar11 = param_2[2];

    iVar18 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar18 - uVar11;

    puVar7 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             ((longlong)(iVar18 * param_2[1]) + (longlong)*param_2) * 2);

    uVar19 = param_2[3];

    while( true ) {

      uVar5 = (ulonglong)uVar19;

      if (uVar19 == 0) break;

      iVar18 = (int)(((int)(uVar11 + 3) >> 0x1f & 3U) + uVar11 + 3) >> 2;

      uVar15 = uVar11 & 3;

      if (uVar15 == 0) goto LAB_140245f30;

      if (uVar15 == 1) goto LAB_14024613d;

      if (uVar15 == 2) goto LAB_14024608e;

      if (uVar15 == 3) {

        while( true ) {

          uVar8 = *puVar7;

          uVar15 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff +

                   (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar13 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff + (uint)param_5

          ;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          *puVar7 = (((ushort)uVar15 & 0xfff8) << 5 | (ushort)uVar13 & 0xfff8) << 2 |

                    (ushort)(uVar12 >> 3);

          puVar7 = puVar7 + 1;

LAB_14024608e:

          uVar8 = *puVar7;

          uVar15 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff +

                   (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar13 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff + (uint)param_5

          ;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          *puVar7 = (((ushort)uVar15 & 0xfff8) << 5 | (ushort)uVar13 & 0xfff8) << 2 |

                    (ushort)(uVar12 >> 3);

          puVar7 = puVar7 + 1;

LAB_14024613d:

          uVar8 = *puVar7;

          uVar15 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff +

                   (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar13 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff + (uint)param_5

          ;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          iVar18 = iVar18 + -1;

          *puVar7 = (((ushort)uVar15 & 0xfff8) << 5 | (ushort)uVar13 & 0xfff8) << 2 |

                    (ushort)(uVar12 >> 3);

          puVar7 = puVar7 + 1;

          if (iVar18 < 1) break;

LAB_140245f30:

          uVar8 = *puVar7;

          uVar15 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 10 & 0x1f] * iVar9) / 0xff +

                   (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar13 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 5 & 0x1f] * iVar9) / 0xff + (uint)param_5

          ;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          *puVar7 = (((ushort)uVar15 & 0xfff8) << 5 | (ushort)uVar13 & 0xfff8) << 2 |

                    (ushort)(uVar12 >> 3);

          puVar7 = puVar7 + 1;

        }

        puVar7 = puVar7 + iVar6;

        uVar19 = uVar19 - 1;

      }

      else {

        puVar7 = puVar7 + iVar6;

        uVar19 = uVar19 - 1;

      }

    }

  }

  return CONCAT71((int7)(uVar5 >> 8),1);

}




