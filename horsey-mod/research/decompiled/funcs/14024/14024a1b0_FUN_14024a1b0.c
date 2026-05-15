// Address: 0x14024a1b0
// Ghidra name: FUN_14024a1b0
// ============ 0x14024a1b0 FUN_14024a1b0 (size=3374) ============


undefined8

FUN_14024a1b0(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint *puVar8;

  int iVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  uint uVar15;

  

  uVar6 = (uint)param_4;

  iVar9 = 0xff - (uint)param_7;

  switch(param_3) {

  case 1:

    uVar15 = param_2[2];

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar14 = iVar7 - uVar15;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar2 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar2;

      if (uVar2 == 0) break;

      iVar7 = (int)(((int)(uVar15 + 3) >> 0x1f & 3U) + uVar15 + 3) >> 2;

      uVar10 = uVar15 & 3;

      uVar4 = (uint)param_5;

      uVar5 = (uint)param_6;

      if (uVar10 == 0) goto LAB_14024a294;

      if (uVar10 == 1) goto LAB_14024a3b4;

      if (uVar10 == 2) goto LAB_14024a354;

      if (uVar10 == 3) {

        while( true ) {

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 8 & 0xff) * iVar9) / 0xff + uVar4) * 0x100 |

                    (((uVar10 >> 0x10 & 0xff) * iVar9) / 0xff + uVar6) * 0x10000 |

                    ((uVar10 & 0xff) * iVar9) / 0xff + uVar5;

          puVar8 = puVar8 + 1;

LAB_14024a354:

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 8 & 0xff) * iVar9) / 0xff + uVar4) * 0x100 |

                    (((uVar10 >> 0x10 & 0xff) * iVar9) / 0xff + uVar6) * 0x10000 |

                    ((uVar10 & 0xff) * iVar9) / 0xff + uVar5;

          puVar8 = puVar8 + 1;

LAB_14024a3b4:

          uVar10 = *puVar8;

          iVar7 = iVar7 + -1;

          *puVar8 = (((uVar10 >> 8 & 0xff) * iVar9) / 0xff + uVar4) * 0x100 |

                    (((uVar10 >> 0x10 & 0xff) * iVar9) / 0xff + uVar6) * 0x10000 |

                    ((uVar10 & 0xff) * iVar9) / 0xff + uVar5;

          puVar8 = puVar8 + 1;

          if (iVar7 < 1) break;

LAB_14024a294:

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 8 & 0xff) * iVar9) / 0xff + uVar4) * 0x100 |

                    (((uVar10 >> 0x10 & 0xff) * iVar9) / 0xff + uVar6) * 0x10000 |

                    ((uVar10 & 0xff) * iVar9) / 0xff + uVar5;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar14;

        uVar2 = uVar2 - 1;

      }

      else {

        puVar8 = puVar8 + iVar14;

        uVar2 = uVar2 - 1;

      }

    }

    break;

  case 2:

  case 0x20:

    uVar6 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar7 = iVar9 - uVar6;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar9 = (int)(((int)(uVar6 + 3) >> 0x1f & 3U) + uVar6 + 3) >> 2;

      uVar2 = uVar6 & 3;

      uVar12 = 0xff;

      uVar10 = (uint)param_4;

      uVar1 = 0xff;

      uVar4 = (uint)param_5;

      uVar5 = (uint)param_6;

      if (uVar2 == 0) goto LAB_14024a742;

      if (uVar2 == 1) goto LAB_14024a808;

      if (uVar2 == 2) goto LAB_14024a7c6;

      if (uVar2 == 3) {

        while( true ) {

          uVar2 = (*puVar8 >> 0x10 & 0xff) + uVar10;

          if (0xff < uVar2) {

            uVar2 = uVar1;

          }

          uVar11 = *(byte *)((longlong)puVar8 + 1) + uVar4;

          if (0xff < uVar11) {

            uVar11 = uVar1;

          }

          uVar13 = (*puVar8 & 0xff) + uVar5;

          if (0xff < uVar13) {

            uVar13 = uVar12;

          }

          *puVar8 = (uVar2 << 8 | uVar11) << 8 | uVar13;

          puVar8 = puVar8 + 1;

LAB_14024a7c6:

          uVar2 = (*puVar8 >> 0x10 & 0xff) + uVar10;

          if (0xff < uVar2) {

            uVar2 = uVar1;

          }

          uVar11 = *(byte *)((longlong)puVar8 + 1) + uVar4;

          if (0xff < uVar11) {

            uVar11 = uVar1;

          }

          uVar13 = (*puVar8 & 0xff) + uVar5;

          if (0xff < uVar13) {

            uVar13 = uVar12;

          }

          *puVar8 = (uVar2 << 8 | uVar11) << 8 | uVar13;

          puVar8 = puVar8 + 1;

LAB_14024a808:

          uVar2 = (*puVar8 >> 0x10 & 0xff) + uVar10;

          if (0xff < uVar2) {

            uVar2 = uVar1;

          }

          uVar11 = *(byte *)((longlong)puVar8 + 1) + uVar4;

          if (0xff < uVar11) {

            uVar11 = uVar1;

          }

          uVar13 = (*puVar8 & 0xff) + uVar5;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          iVar9 = iVar9 + -1;

          *puVar8 = (uVar2 << 8 | uVar11) << 8 | uVar13;

          puVar8 = puVar8 + 1;

          if (iVar9 < 1) break;

LAB_14024a742:

          uVar2 = (*puVar8 >> 0x10 & 0xff) + uVar10;

          if (0xff < uVar2) {

            uVar2 = uVar1;

          }

          uVar11 = *(byte *)((longlong)puVar8 + 1) + uVar4;

          if (0xff < uVar11) {

            uVar11 = uVar1;

          }

          uVar13 = (*puVar8 & 0xff) + uVar5;

          if (0xff < uVar13) {

            uVar13 = uVar12;

          }

          *puVar8 = (uVar2 << 8 | uVar11) << 8 | uVar13;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar7;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar8 = puVar8 + iVar7;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  default:

    uVar6 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar7 = iVar9 - uVar6;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar9 = (int)(((int)(uVar6 + 3) >> 0x1f & 3U) + uVar6 + 3) >> 2;

      uVar2 = uVar6 & 3;

      if (uVar2 == 0) goto LAB_14024ae59;

      if (uVar2 == 1) goto LAB_14024ae98;

      if (uVar2 == 2) goto LAB_14024ae83;

      if (uVar2 == 3) {

        while( true ) {

          *puVar8 = (uint)CONCAT21(CONCAT11(param_4,param_5),param_6);

          puVar8 = puVar8 + 1;

LAB_14024ae83:

          *puVar8 = (uint)CONCAT21(CONCAT11(param_4,param_5),param_6);

          puVar8 = puVar8 + 1;

LAB_14024ae98:

          iVar9 = iVar9 + -1;

          *puVar8 = (uint)CONCAT21(CONCAT11(param_4,param_5),param_6);

          puVar8 = puVar8 + 1;

          if (iVar9 < 1) break;

LAB_14024ae59:

          *puVar8 = (uint)CONCAT21(CONCAT11(param_4,param_5),param_6);

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar7;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar8 = puVar8 + iVar7;

        uVar15 = uVar15 - 1;

      }

    }

    break;

  case 4:

    uVar15 = param_2[2];

    iVar9 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar7 = iVar9 - uVar15;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

    uVar2 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar2;

      if (uVar2 == 0) break;

      iVar9 = (int)(((int)(uVar15 + 3) >> 0x1f & 3U) + uVar15 + 3) >> 2;

      uVar10 = uVar15 & 3;

      uVar4 = (uint)param_5;

      uVar5 = (uint)param_6;

      if (uVar10 == 0) goto LAB_14024a8e2;

      if (uVar10 == 1) goto LAB_14024a9f0;

      if (uVar10 == 2) goto LAB_14024a996;

      if (uVar10 == 3) {

        while( true ) {

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 0x10 & 0xff) * uVar6) / 0xff << 8 |

                    ((uVar10 >> 8 & 0xff) * uVar4) / 0xff) << 8 | ((uVar10 & 0xff) * uVar5) / 0xff;

          puVar8 = puVar8 + 1;

LAB_14024a996:

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 0x10 & 0xff) * uVar6) / 0xff << 8 |

                    ((uVar10 >> 8 & 0xff) * uVar4) / 0xff) << 8 | ((uVar10 & 0xff) * uVar5) / 0xff;

          puVar8 = puVar8 + 1;

LAB_14024a9f0:

          uVar10 = *puVar8;

          iVar9 = iVar9 + -1;

          *puVar8 = (((uVar10 >> 0x10 & 0xff) * uVar6) / 0xff << 8 |

                    ((uVar10 >> 8 & 0xff) * uVar4) / 0xff) << 8 | ((uVar10 & 0xff) * uVar5) / 0xff;

          puVar8 = puVar8 + 1;

          if (iVar9 < 1) break;

LAB_14024a8e2:

          uVar10 = *puVar8;

          *puVar8 = (((uVar10 >> 0x10 & 0xff) * uVar6) / 0xff << 8 |

                    ((uVar10 >> 8 & 0xff) * uVar4) / 0xff) << 8 | ((uVar10 & 0xff) * uVar5) / 0xff;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar7;

        uVar2 = uVar2 - 1;

      }

      else {

        puVar8 = puVar8 + iVar7;

        uVar2 = uVar2 - 1;

      }

    }

    break;

  case 8:

    uVar15 = param_2[2];

    uVar10 = (uint)param_6;

    uVar4 = (uint)param_5;

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar14 = iVar7 - uVar15;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar2 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar2;

      if (uVar2 == 0) break;

      iVar7 = (int)(((int)(uVar15 + 3) >> 0x1f & 3U) + uVar15 + 3) >> 2;

      uVar5 = uVar15 & 3;

      if (uVar5 == 0) goto LAB_14024aaed;

      if (uVar5 == 1) goto LAB_14024ad09;

      if (uVar5 == 2) goto LAB_14024ac55;

      if (uVar5 == 3) {

        while( true ) {

          uVar5 = (uVar6 * *(byte *)((longlong)puVar8 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar8 + 2) * iVar9) / 0xff;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          uVar12 = (uVar4 * *(byte *)((longlong)puVar8 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar1 = (uVar10 * (byte)*puVar8) / 0xff + ((uint)(byte)*puVar8 * iVar9) / 0xff;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar8 = (uVar5 << 8 | uVar12) << 8 | uVar1;

          puVar8 = puVar8 + 1;

LAB_14024ac55:

          uVar5 = (uVar6 * *(byte *)((longlong)puVar8 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar8 + 2) * iVar9) / 0xff;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          uVar12 = (uVar4 * *(byte *)((longlong)puVar8 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar1 = (uVar10 * (byte)*puVar8) / 0xff + ((uint)(byte)*puVar8 * iVar9) / 0xff;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar8 = (uVar5 << 8 | uVar12) << 8 | uVar1;

          puVar8 = puVar8 + 1;

LAB_14024ad09:

          uVar5 = (uVar6 * *(byte *)((longlong)puVar8 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar8 + 2) * iVar9) / 0xff;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          uVar12 = (uVar4 * *(byte *)((longlong)puVar8 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar1 = (uVar10 * (byte)*puVar8) / 0xff + ((uint)(byte)*puVar8 * iVar9) / 0xff;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          iVar7 = iVar7 + -1;

          *puVar8 = (uVar5 << 8 | uVar12) << 8 | uVar1;

          puVar8 = puVar8 + 1;

          if (iVar7 < 1) break;

LAB_14024aaed:

          uVar5 = (uVar6 * *(byte *)((longlong)puVar8 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar8 + 2) * iVar9) / 0xff;

          if (0xff < uVar5) {

            uVar5 = 0xff;

          }

          uVar12 = (uVar4 * *(byte *)((longlong)puVar8 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff;

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

          uVar1 = (uVar10 * (byte)*puVar8) / 0xff + ((uint)(byte)*puVar8 * iVar9) / 0xff;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar8 = (uVar5 << 8 | uVar12) << 8 | uVar1;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar14;

        uVar2 = uVar2 - 1;

      }

      else {

        puVar8 = puVar8 + iVar14;

        uVar2 = uVar2 - 1;

      }

    }

    break;

  case 0x10:

    uVar6 = param_2[2];

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar14 = iVar7 - uVar6;

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar15 = param_2[3];

    while( true ) {

      uVar3 = (ulonglong)uVar15;

      if (uVar15 == 0) break;

      iVar7 = (int)(((int)(uVar6 + 3) >> 0x1f & 3U) + uVar6 + 3) >> 2;

      uVar2 = uVar6 & 3;

      if (uVar2 == 0) goto LAB_14024a4ba;

      if (uVar2 == 1) goto LAB_14024a628;

      if (uVar2 == 2) goto LAB_14024a5ae;

      if (uVar2 == 3) {

        while( true ) {

          uVar2 = ((*puVar8 >> 0x10 & 0xff) * iVar9) / 0xff + (uint)param_4;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          uVar10 = ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff + (uint)param_5;

          if (0xff < uVar10) {

            uVar10 = 0xff;

          }

          uVar4 = ((*puVar8 & 0xff) * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar8 = (uVar2 << 8 | uVar10) << 8 | uVar4;

          puVar8 = puVar8 + 1;

LAB_14024a5ae:

          uVar2 = ((*puVar8 >> 0x10 & 0xff) * iVar9) / 0xff + (uint)param_4;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          uVar10 = ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff + (uint)param_5;

          if (0xff < uVar10) {

            uVar10 = 0xff;

          }

          uVar4 = ((*puVar8 & 0xff) * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar8 = (uVar2 << 8 | uVar10) << 8 | uVar4;

          puVar8 = puVar8 + 1;

LAB_14024a628:

          uVar2 = ((*puVar8 >> 0x10 & 0xff) * iVar9) / 0xff + (uint)param_4;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          uVar10 = ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff + (uint)param_5;

          if (0xff < uVar10) {

            uVar10 = 0xff;

          }

          uVar4 = ((*puVar8 & 0xff) * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          iVar7 = iVar7 + -1;

          *puVar8 = (uVar2 << 8 | uVar10) << 8 | uVar4;

          puVar8 = puVar8 + 1;

          if (iVar7 < 1) break;

LAB_14024a4ba:

          uVar2 = ((*puVar8 >> 0x10 & 0xff) * iVar9) / 0xff + (uint)param_4;

          if (0xff < uVar2) {

            uVar2 = 0xff;

          }

          uVar10 = ((uint)*(byte *)((longlong)puVar8 + 1) * iVar9) / 0xff + (uint)param_5;

          if (0xff < uVar10) {

            uVar10 = 0xff;

          }

          uVar4 = ((*puVar8 & 0xff) * iVar9) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          *puVar8 = (uVar2 << 8 | uVar10) << 8 | uVar4;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar8 + iVar14;

        uVar15 = uVar15 - 1;

      }

      else {

        puVar8 = puVar8 + iVar14;

        uVar15 = uVar15 - 1;

      }

    }

  }

  return CONCAT71((int7)(uVar3 >> 8),1);

}




