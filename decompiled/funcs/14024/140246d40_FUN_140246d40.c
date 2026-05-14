// Address: 0x140246d40
// Ghidra name: FUN_140246d40
// ============ 0x140246d40 FUN_140246d40 (size=4623) ============


undefined8

FUN_140246d40(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  ushort uVar1;

  uint uVar2;

  ulonglong uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  ushort uVar8;

  uint uVar9;

  int iVar10;

  ushort uVar11;

  uint uVar12;

  uint uVar13;

  ushort *puVar14;

  uint uVar15;

  int iVar16;

  

  iVar10 = 0xff - (uint)param_7;

  uVar9 = (uint)param_4;

  uVar8 = (ushort)param_4;

  switch(param_3) {

  case 1:

    uVar9 = param_2[2];

    iVar16 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar4 = iVar16 - uVar9;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar16 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar16 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar7 = uVar9 & 3;

      uVar11 = (ushort)param_5;

      uVar12 = (uint)param_6;

      if (uVar7 == 0) goto LAB_140246e2a;

      if (uVar7 == 1) goto LAB_140247001;

      if (uVar7 == 2) goto LAB_140246f64;

      if (uVar7 == 3) {

        while( true ) {

          uVar1 = *puVar14;

          *puVar14 = ((short)(((uint)(byte)PTR_DAT_1403e28d0[uVar1 >> 5 & 0x3f] * iVar10) / 0xff) +

                     uVar11) * 8 & 0xffe0 |

                     ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar1 >> 0xb] * iVar10) /

                             0xff) + uVar8) * 0x100 & 0xf81f |

                     (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] * iVar10) / 0xff + uVar12

                             >> 3);

          puVar14 = puVar14 + 1;

LAB_140246f64:

          uVar1 = *puVar14;

          *puVar14 = ((short)(((uint)(byte)PTR_DAT_1403e28d0[uVar1 >> 5 & 0x3f] * iVar10) / 0xff) +

                     uVar11) * 8 & 0xffe0 |

                     ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar1 >> 0xb] * iVar10) /

                             0xff) + uVar8) * 0x100 & 0xf81f |

                     (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] * iVar10) / 0xff + uVar12

                             >> 3);

          puVar14 = puVar14 + 1;

LAB_140247001:

          uVar1 = *puVar14;

          iVar16 = iVar16 + -1;

          *puVar14 = ((short)(((uint)(byte)PTR_DAT_1403e28d0[uVar1 >> 5 & 0x3f] * iVar10) / 0xff) +

                     uVar11) * 8 & 0xffe0 |

                     ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar1 >> 0xb] * iVar10) /

                             0xff) + uVar8) * 0x100 & 0xf81f |

                     (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] * iVar10) / 0xff + uVar12

                             >> 3);

          puVar14 = puVar14 + 1;

          if (iVar16 < 1) break;

LAB_140246e2a:

          uVar1 = *puVar14;

          *puVar14 = ((short)(((uint)(byte)PTR_DAT_1403e28d0[uVar1 >> 5 & 0x3f] * iVar10) / 0xff) +

                     uVar11) * 8 & 0xffe0 |

                     ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar1 >> 0xb] * iVar10) /

                             0xff) + uVar8) * 0x100 & 0xf81f |

                     (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar1 & 0x1f] * iVar10) / 0xff + uVar12

                             >> 3);

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar4;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar14 = puVar14 + iVar4;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  case 2:

  case 0x20:

    uVar9 = param_2[2];

    iVar10 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar16 = iVar10 - uVar9;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar10 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar10 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar7 = uVar9 & 3;

      uVar8 = (ushort)param_4;

      uVar12 = (uint)param_5;

      uVar5 = (uint)param_6;

      if (uVar7 == 0) goto LAB_1402474b6;

      if (uVar7 == 1) goto LAB_140247612;

      if (uVar7 == 2) goto LAB_14024759e;

      if (uVar7 == 3) {

        while( true ) {

          uVar11 = *puVar14;

          uVar1 = (byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8)) {

            uVar1 = 0xff;

          }

          uVar7 = (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12;

          if (0xff < (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12) {

            uVar7 = 0xff;

          }

          uVar6 = (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5) {

            uVar6 = 0xff;

          }

          *puVar14 = ((uVar1 & 0xfff8) << 5 | (ushort)uVar7 & 0xfffc) << 3 | (ushort)(uVar6 >> 3);

          puVar14 = puVar14 + 1;

LAB_14024759e:

          uVar11 = *puVar14;

          uVar1 = (byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8)) {

            uVar1 = 0xff;

          }

          uVar7 = (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12;

          if (0xff < (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12) {

            uVar7 = 0xff;

          }

          uVar6 = (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5) {

            uVar6 = 0xff;

          }

          *puVar14 = ((uVar1 & 0xfff8) << 5 | (ushort)uVar7 & 0xfffc) << 3 | (ushort)(uVar6 >> 3);

          puVar14 = puVar14 + 1;

LAB_140247612:

          uVar11 = *puVar14;

          uVar1 = (byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8)) {

            uVar1 = 0xff;

          }

          uVar7 = (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12;

          if (0xff < (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12) {

            uVar7 = 0xff;

          }

          uVar6 = (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5) {

            uVar6 = 0xff;

          }

          iVar10 = iVar10 + -1;

          *puVar14 = ((uVar1 & 0xfff8) << 5 | (ushort)uVar7 & 0xfffc) << 3 | (ushort)(uVar6 >> 3);

          puVar14 = puVar14 + 1;

          if (iVar10 < 1) break;

LAB_1402474b6:

          uVar11 = *puVar14;

          uVar1 = (byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8;

          if (0xff < (ushort)((byte)PTR_DAT_1403e28c8[uVar11 >> 0xb] + uVar8)) {

            uVar1 = 0xff;

          }

          uVar7 = (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12;

          if (0xff < (byte)PTR_DAT_1403e28d0[uVar11 >> 5 & 0x3f] + uVar12) {

            uVar7 = 0xff;

          }

          uVar6 = (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5;

          if (0xff < (byte)PTR_DAT_1403e28c8[uVar11 & 0x1f] + uVar5) {

            uVar6 = 0xff;

          }

          *puVar14 = ((uVar1 & 0xfff8) << 5 | (ushort)uVar7 & 0xfffc) << 3 | (ushort)(uVar6 >> 3);

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar16;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar14 = puVar14 + iVar16;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  default:

    uVar9 = param_2[2];

    iVar10 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar16 = iVar10 - uVar9;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar10 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar10 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar7 = uVar9 & 3;

      uVar11 = (ushort)param_5;

      uVar8 = (ushort)param_4;

      if (uVar7 == 0) goto LAB_140247e70;

      if (uVar7 == 1) goto LAB_140247eee;

      if (uVar7 == 2) goto LAB_140247ec4;

      if (uVar7 == 3) {

        while( true ) {

          *puVar14 = ((uVar8 & 0xfff8) << 5 | uVar11 & 0xfffc) << 3 | (ushort)(param_6 >> 3);

          puVar14 = puVar14 + 1;

LAB_140247ec4:

          *puVar14 = ((uVar8 & 0xfff8) << 5 | uVar11 & 0xfffc) << 3 | (ushort)(param_6 >> 3);

          puVar14 = puVar14 + 1;

LAB_140247eee:

          iVar10 = iVar10 + -1;

          *puVar14 = ((uVar8 & 0xfff8) << 5 | uVar11 & 0xfffc) << 3 | (ushort)(param_6 >> 3);

          puVar14 = puVar14 + 1;

          if (iVar10 < 1) break;

LAB_140247e70:

          *puVar14 = ((uVar8 & 0xfff8) << 5 | uVar11 & 0xfffc) << 3 | (ushort)(param_6 >> 3);

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar16;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar14 = puVar14 + iVar16;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  case 4:

    uVar15 = param_2[2];

    iVar10 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar16 = iVar10 - uVar15;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar10 * param_2[1]) + (longlong)*param_2) * 2);

    uVar7 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar7;

      if (uVar7 == 0) break;

      iVar10 = (int)(((int)(uVar15 + 3) >> 0x1f & 3U) + uVar15 + 3) >> 2;

      uVar12 = uVar15 & 3;

      uVar6 = (uint)param_5;

      uVar5 = (uint)param_6;

      if (uVar12 == 0) goto LAB_14024773c;

      if (uVar12 == 1) goto LAB_1402478ce;

      if (uVar12 == 2) goto LAB_140247848;

      if (uVar12 == 3) {

        while( true ) {

          uVar8 = *puVar14;

          *puVar14 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * uVar9) / 0xff) & 0xfff8) <<

                      5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * uVar6) /

                                  0xff) & 0xfffc) << 3 |

                     (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar5) / 0xff >> 3

                             );

          puVar14 = puVar14 + 1;

LAB_140247848:

          uVar8 = *puVar14;

          *puVar14 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * uVar9) / 0xff) & 0xfff8) <<

                      5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * uVar6) /

                                  0xff) & 0xfffc) << 3 |

                     (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar5) / 0xff >> 3

                             );

          puVar14 = puVar14 + 1;

LAB_1402478ce:

          uVar8 = *puVar14;

          iVar10 = iVar10 + -1;

          *puVar14 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * uVar9) / 0xff) & 0xfff8) <<

                      5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * uVar6) /

                                  0xff) & 0xfffc) << 3 |

                     (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar5) / 0xff >> 3

                             );

          puVar14 = puVar14 + 1;

          if (iVar10 < 1) break;

LAB_14024773c:

          uVar8 = *puVar14;

          *puVar14 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * uVar9) / 0xff) & 0xfff8) <<

                      5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * uVar6) /

                                  0xff) & 0xfffc) << 3 |

                     (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * uVar5) / 0xff >> 3

                             );

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar16;

        uVar7 = uVar7 - 1;

      }

      else {

        puVar14 = puVar14 + iVar16;

        uVar7 = uVar7 - 1;

      }

    }

    break;

  case 8:

    uVar15 = param_2[2];

    uVar5 = (uint)param_6;

    uVar12 = (uint)param_5;

    iVar16 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar4 = iVar16 - uVar15;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar16 * param_2[1]) + (longlong)*param_2) * 2);

    uVar7 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar7;

      if (uVar7 == 0) break;

      _param_7 = (int)(uVar15 + 3 + ((int)(uVar15 + 3) >> 0x1f & 3U)) >> 2;

      uVar6 = uVar15 & 3;

      if (uVar6 == 0) goto LAB_140247a0c;

      if (uVar6 == 1) goto LAB_140247cd0;

      if (uVar6 == 2) goto LAB_140247be4;

      if (uVar6 == 3) {

        while( true ) {

          uVar8 = *puVar14;

          uVar6 = (uVar9 * (byte)PTR_DAT_1403e28c8[uVar8 >> 0xb]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff;

          if (0xff < uVar6) {

            uVar6 = 0xff;

          }

          uVar13 = (uVar12 * (byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar2 = (uVar5 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          *puVar14 = (((ushort)uVar6 & 0xfff8) << 5 | (ushort)uVar13 & 0xfffc) << 3 |

                     (ushort)(uVar2 >> 3);

          puVar14 = puVar14 + 1;

LAB_140247be4:

          uVar8 = *puVar14;

          uVar6 = (uVar9 * (byte)PTR_DAT_1403e28c8[uVar8 >> 0xb]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff;

          if (0xff < uVar6) {

            uVar6 = 0xff;

          }

          uVar13 = (uVar12 * (byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar2 = (uVar5 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          *puVar14 = (((ushort)uVar6 & 0xfff8) << 5 | (ushort)uVar13 & 0xfffc) << 3 |

                     (ushort)(uVar2 >> 3);

          puVar14 = puVar14 + 1;

LAB_140247cd0:

          uVar8 = *puVar14;

          uVar6 = (uVar9 * (byte)PTR_DAT_1403e28c8[uVar8 >> 0xb]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff;

          if (0xff < uVar6) {

            uVar6 = 0xff;

          }

          uVar13 = (uVar12 * (byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar2 = (uVar5 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          _param_7 = _param_7 + -1;

          *puVar14 = (((ushort)uVar6 & 0xfff8) << 5 | (ushort)uVar13 & 0xfffc) << 3 |

                     (ushort)(uVar2 >> 3);

          puVar14 = puVar14 + 1;

          if (_param_7 < 1) break;

LAB_140247a0c:

          uVar8 = *puVar14;

          uVar6 = (uVar9 * (byte)PTR_DAT_1403e28c8[uVar8 >> 0xb]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff;

          if (0xff < uVar6) {

            uVar6 = 0xff;

          }

          uVar13 = (uVar12 * (byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f]) / 0xff +

                   ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          uVar2 = (uVar5 * (byte)PTR_DAT_1403e28c8[uVar8 & 0x1f]) / 0xff +

                  ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          *puVar14 = (((ushort)uVar6 & 0xfff8) << 5 | (ushort)uVar13 & 0xfffc) << 3 |

                     (ushort)(uVar2 >> 3);

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar4;

        uVar7 = uVar7 - 1;

      }

      else {

        puVar14 = puVar14 + iVar4;

        uVar7 = uVar7 - 1;

      }

    }

    break;

  case 0x10:

    uVar9 = param_2[2];

    iVar16 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar4 = iVar16 - uVar9;

    puVar14 = (ushort *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar16 * param_2[1]) + (longlong)*param_2) * 2);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar16 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar7 = uVar9 & 3;

      if (uVar7 == 0) goto LAB_14024715c;

      if (uVar7 == 1) goto LAB_14024735d;

      if (uVar7 == 2) goto LAB_1402472b2;

      if (uVar7 == 3) {

        while( true ) {

          uVar8 = *puVar14;

          uVar7 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff + (uint)param_4;

          if (0xff < uVar7) {

            uVar7 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff +

                   (uint)param_5;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar5 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff + (uint)param_6;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          *puVar14 = (((ushort)uVar7 & 0xfff8) << 5 | (ushort)uVar12 & 0xfffc) << 3 |

                     (ushort)(uVar5 >> 3);

          puVar14 = puVar14 + 1;

LAB_1402472b2:

          uVar8 = *puVar14;

          uVar7 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff + (uint)param_4;

          if (0xff < uVar7) {

            uVar7 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff +

                   (uint)param_5;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar5 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff + (uint)param_6;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          *puVar14 = (((ushort)uVar7 & 0xfff8) << 5 | (ushort)uVar12 & 0xfffc) << 3 |

                     (ushort)(uVar5 >> 3);

          puVar14 = puVar14 + 1;

LAB_14024735d:

          uVar8 = *puVar14;

          uVar7 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff + (uint)param_4;

          if (0xff < uVar7) {

            uVar7 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff +

                   (uint)param_5;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar5 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff + (uint)param_6;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          iVar16 = iVar16 + -1;

          *puVar14 = (((ushort)uVar7 & 0xfff8) << 5 | (ushort)uVar12 & 0xfffc) << 3 |

                     (ushort)(uVar5 >> 3);

          puVar14 = puVar14 + 1;

          if (iVar16 < 1) break;

LAB_14024715c:

          uVar8 = *puVar14;

          uVar7 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 >> 0xb] * iVar10) / 0xff + (uint)param_4;

          if (0xff < uVar7) {

            uVar7 = 0xff;

          }

          uVar12 = ((uint)(byte)PTR_DAT_1403e28d0[uVar8 >> 5 & 0x3f] * iVar10) / 0xff +

                   (uint)param_5;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar5 = ((uint)(byte)PTR_DAT_1403e28c8[uVar8 & 0x1f] * iVar10) / 0xff + (uint)param_6;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          *puVar14 = (((ushort)uVar7 & 0xfff8) << 5 | (ushort)uVar12 & 0xfffc) << 3 |

                     (ushort)(uVar5 >> 3);

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar4;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar14 = puVar14 + iVar4;

        uVar15 = uVar15 - 1;

      }

    }

  }

  return CONCAT71((int7)(uVar3 >> 8),1);

}




