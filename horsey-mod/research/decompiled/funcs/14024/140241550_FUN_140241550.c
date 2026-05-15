// Address: 0x140241550
// Ghidra name: FUN_140241550
// ============ 0x140241550 FUN_140241550 (size=3822) ============


undefined8

FUN_140241550(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  uint uVar1;

  ulonglong uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  undefined4 *puVar12;

  uint uVar13;

  uint *puVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  

  uVar8 = (uint)param_4;

  iVar7 = 0xff - (uint)param_7;

  switch(param_3) {

  case 1:

    uVar17 = param_2[2];

    iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar3 = iVar6 - uVar17;

    puVar14 = (uint *)(*(longlong *)(param_1 + 0x18) +

                      ((longlong)(iVar6 * param_2[1]) + (longlong)*param_2) * 4);

    uVar1 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar1;

      if (uVar1 == 0) break;

      iVar6 = (int)(((int)(uVar17 + 3) >> 0x1f & 3U) + uVar17 + 3) >> 2;

      uVar15 = uVar17 & 3;

      uVar9 = (uint)param_5;

      uVar4 = (uint)param_6;

      if (uVar15 == 0) goto LAB_14024163a;

      if (uVar15 == 1) goto LAB_1402417ab;

      if (uVar15 == 2) goto LAB_140241730;

      if (uVar15 == 3) {

        while( true ) {

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 8 & 0xff) * iVar7) / 0xff + uVar9) * 0x100 |

                     (((uVar15 >> 0x10 & 0xff) * iVar7) / 0xff + uVar8) * 0x10000 |

                     (((uVar15 >> 0x18) * iVar7) / 0xff + (uint)param_7) * 0x1000000 |

                     ((uVar15 & 0xff) * iVar7) / 0xff + uVar4;

          puVar14 = puVar14 + 1;

LAB_140241730:

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 8 & 0xff) * iVar7) / 0xff + uVar9) * 0x100 |

                     (((uVar15 >> 0x10 & 0xff) * iVar7) / 0xff + uVar8) * 0x10000 |

                     (((uVar15 >> 0x18) * iVar7) / 0xff + (uint)param_7) * 0x1000000 |

                     ((uVar15 & 0xff) * iVar7) / 0xff + uVar4;

          puVar14 = puVar14 + 1;

LAB_1402417ab:

          uVar15 = *puVar14;

          iVar6 = iVar6 + -1;

          *puVar14 = (((uVar15 >> 8 & 0xff) * iVar7) / 0xff + uVar9) * 0x100 |

                     (((uVar15 >> 0x10 & 0xff) * iVar7) / 0xff + uVar8) * 0x10000 |

                     (((uVar15 >> 0x18) * iVar7) / 0xff + (uint)param_7) * 0x1000000 |

                     ((uVar15 & 0xff) * iVar7) / 0xff + uVar4;

          puVar14 = puVar14 + 1;

          if (iVar6 < 1) break;

LAB_14024163a:

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 8 & 0xff) * iVar7) / 0xff + uVar9) * 0x100 |

                     (((uVar15 >> 0x10 & 0xff) * iVar7) / 0xff + uVar8) * 0x10000 |

                     (((uVar15 >> 0x18) * iVar7) / 0xff + (uint)param_7) * 0x1000000 |

                     ((uVar15 & 0xff) * iVar7) / 0xff + uVar4;

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar3;

        uVar1 = uVar1 - 1;

      }

      else {

        puVar14 = puVar14 + iVar3;

        uVar1 = uVar1 - 1;

      }

    }

    break;

  case 2:

  case 0x20:

    uVar8 = param_2[2];

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar7 - uVar8;

    puVar14 = (uint *)(*(longlong *)(param_1 + 0x18) +

                      ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar17 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar17;

      if (uVar17 == 0) break;

      iVar7 = (int)(((int)(uVar8 + 3) >> 0x1f & 3U) + uVar8 + 3) >> 2;

      uVar1 = uVar8 & 3;

      uVar11 = 0xff;

      uVar4 = (uint)param_4;

      uVar16 = 0xff;

      uVar9 = (uint)param_5;

      uVar15 = (uint)param_6;

      if (uVar1 == 0) goto LAB_140241c04;

      if (uVar1 == 1) goto LAB_140241cfa;

      if (uVar1 == 2) goto LAB_140241ca8;

      if (uVar1 == 3) {

        while( true ) {

          uVar1 = *puVar14;

          uVar5 = (uVar1 >> 0x10 & 0xff) + uVar4;

          if (0xff < uVar5) {

            uVar5 = uVar16;

          }

          uVar10 = *(byte *)((longlong)puVar14 + 1) + uVar9;

          if (0xff < uVar10) {

            uVar10 = uVar16;

          }

          uVar13 = (uVar1 & 0xff) + uVar15;

          if (0xff < uVar13) {

            uVar13 = uVar11;

          }

          *puVar14 = (((uVar1 >> 0x18) << 8 | uVar5) << 8 | uVar10) << 8 | uVar13;

          puVar14 = puVar14 + 1;

LAB_140241ca8:

          uVar1 = *puVar14;

          uVar5 = (uVar1 >> 0x10 & 0xff) + uVar4;

          if (0xff < uVar5) {

            uVar5 = uVar16;

          }

          uVar10 = *(byte *)((longlong)puVar14 + 1) + uVar9;

          if (0xff < uVar10) {

            uVar10 = uVar16;

          }

          uVar13 = (uVar1 & 0xff) + uVar15;

          if (0xff < uVar13) {

            uVar13 = uVar11;

          }

          *puVar14 = (((uVar1 >> 0x18) << 8 | uVar5) << 8 | uVar10) << 8 | uVar13;

          puVar14 = puVar14 + 1;

LAB_140241cfa:

          uVar1 = *puVar14;

          uVar5 = (uVar1 >> 0x10 & 0xff) + uVar4;

          if (0xff < uVar5) {

            uVar5 = uVar16;

          }

          uVar10 = *(byte *)((longlong)puVar14 + 1) + uVar9;

          if (0xff < uVar10) {

            uVar10 = uVar16;

          }

          uVar13 = (uVar1 & 0xff) + uVar15;

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

          iVar7 = iVar7 + -1;

          *puVar14 = (((uVar1 >> 0x18) << 8 | uVar5) << 8 | uVar10) << 8 | uVar13;

          puVar14 = puVar14 + 1;

          if (iVar7 < 1) break;

LAB_140241c04:

          uVar1 = *puVar14;

          uVar5 = (uVar1 >> 0x10 & 0xff) + uVar4;

          if (0xff < uVar5) {

            uVar5 = uVar16;

          }

          uVar10 = *(byte *)((longlong)puVar14 + 1) + uVar9;

          if (0xff < uVar10) {

            uVar10 = uVar16;

          }

          uVar13 = (uVar1 & 0xff) + uVar15;

          if (0xff < uVar13) {

            uVar13 = uVar11;

          }

          *puVar14 = (((uVar1 >> 0x18) << 8 | uVar5) << 8 | uVar10) << 8 | uVar13;

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar6;

        uVar17 = uVar17 - 1;

      }

      else {

        puVar14 = puVar14 + iVar6;

        uVar17 = uVar17 - 1;

      }

    }

    break;

  default:

    uVar8 = param_2[2];

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar7 - uVar8;

    puVar12 = (undefined4 *)

              (*(longlong *)(param_1 + 0x18) +

              ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar17 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar17;

      if (uVar17 == 0) break;

      iVar7 = (int)(((int)(uVar8 + 3) >> 0x1f & 3U) + uVar8 + 3) >> 2;

      uVar1 = uVar8 & 3;

      if (uVar1 == 0) goto LAB_1402423a9;

      if (uVar1 == 1) goto LAB_1402423f7;

      if (uVar1 == 2) goto LAB_1402423dd;

      if (uVar1 == 3) {

        while( true ) {

          *puVar12 = CONCAT31(CONCAT21(CONCAT11(param_7,param_4),param_5),param_6);

          puVar12 = puVar12 + 1;

LAB_1402423dd:

          *puVar12 = CONCAT31(CONCAT21(CONCAT11(param_7,param_4),param_5),param_6);

          puVar12 = puVar12 + 1;

LAB_1402423f7:

          iVar7 = iVar7 + -1;

          *puVar12 = CONCAT31(CONCAT21(CONCAT11(param_7,param_4),param_5),param_6);

          puVar12 = puVar12 + 1;

          if (iVar7 < 1) break;

LAB_1402423a9:

          *puVar12 = CONCAT31(CONCAT21(CONCAT11(param_7,param_4),param_5),param_6);

          puVar12 = puVar12 + 1;

        }

        puVar12 = puVar12 + iVar6;

        uVar17 = uVar17 - 1;

      }

      else {

        puVar12 = puVar12 + iVar6;

        uVar17 = uVar17 - 1;

      }

    }

    break;

  case 4:

    uVar17 = param_2[2];

    iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar6 = iVar7 - uVar17;

    puVar14 = (uint *)(*(longlong *)(param_1 + 0x18) +

                      ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

    uVar1 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar1;

      if (uVar1 == 0) break;

      iVar7 = (int)(((int)(uVar17 + 3) >> 0x1f & 3U) + uVar17 + 3) >> 2;

      uVar15 = uVar17 & 3;

      uVar9 = (uint)param_5;

      uVar4 = (uint)param_6;

      if (uVar15 == 0) goto LAB_140241de2;

      if (uVar15 == 1) goto LAB_140241f0e;

      if (uVar15 == 2) goto LAB_140241eaa;

      if (uVar15 == 3) {

        while( true ) {

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 0x10 & 0xff) * uVar8) / 0xff << 8 |

                     ((uVar15 >> 8 & 0xff) * uVar9) / 0xff) << 8 | ((uVar15 & 0xff) * uVar4) / 0xff

                     | uVar15 & 0xff000000;

          puVar14 = puVar14 + 1;

LAB_140241eaa:

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 0x10 & 0xff) * uVar8) / 0xff << 8 |

                     ((uVar15 >> 8 & 0xff) * uVar9) / 0xff) << 8 | ((uVar15 & 0xff) * uVar4) / 0xff

                     | uVar15 & 0xff000000;

          puVar14 = puVar14 + 1;

LAB_140241f0e:

          uVar15 = *puVar14;

          iVar7 = iVar7 + -1;

          *puVar14 = (((uVar15 >> 0x10 & 0xff) * uVar8) / 0xff << 8 |

                     ((uVar15 >> 8 & 0xff) * uVar9) / 0xff) << 8 | ((uVar15 & 0xff) * uVar4) / 0xff

                     | uVar15 & 0xff000000;

          puVar14 = puVar14 + 1;

          if (iVar7 < 1) break;

LAB_140241de2:

          uVar15 = *puVar14;

          *puVar14 = (((uVar15 >> 0x10 & 0xff) * uVar8) / 0xff << 8 |

                     ((uVar15 >> 8 & 0xff) * uVar9) / 0xff) << 8 | ((uVar15 & 0xff) * uVar4) / 0xff

                     | uVar15 & 0xff000000;

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar6;

        uVar1 = uVar1 - 1;

      }

      else {

        puVar14 = puVar14 + iVar6;

        uVar1 = uVar1 - 1;

      }

    }

    break;

  case 8:

    uVar17 = param_2[2];

    uVar15 = (uint)param_6;

    uVar9 = (uint)param_5;

    iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar3 = iVar6 - uVar17;

    puVar14 = (uint *)(*(longlong *)(param_1 + 0x18) +

                      ((longlong)(iVar6 * param_2[1]) + (longlong)*param_2) * 4);

    uVar1 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar1;

      if (uVar1 == 0) break;

      iVar6 = (int)(((int)(uVar17 + 3) >> 0x1f & 3U) + uVar17 + 3) >> 2;

      uVar4 = uVar17 & 3;

      if (uVar4 == 0) goto LAB_14024201c;

      if (uVar4 == 1) goto LAB_140242253;

      if (uVar4 == 2) goto LAB_140242196;

      if (uVar4 == 3) {

        while( true ) {

          uVar16 = *puVar14 & 0xff;

          uVar4 = (uVar8 * *(byte *)((longlong)puVar14 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar14 + 2) * iVar7) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar11 = (uVar9 * *(byte *)((longlong)puVar14 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff;

          if (0xff < uVar11) {

            uVar11 = 0xff;

          }

          uVar16 = (uVar15 * uVar16) / 0xff + (uVar16 * iVar7) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          *puVar14 = (((*puVar14 >> 0x18) << 8 | uVar4) << 8 | uVar11) << 8 | uVar16;

          puVar14 = puVar14 + 1;

LAB_140242196:

          uVar16 = *puVar14 & 0xff;

          uVar4 = (uVar8 * *(byte *)((longlong)puVar14 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar14 + 2) * iVar7) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar11 = (uVar9 * *(byte *)((longlong)puVar14 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff;

          if (0xff < uVar11) {

            uVar11 = 0xff;

          }

          uVar16 = (uVar15 * uVar16) / 0xff + (uVar16 * iVar7) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          *puVar14 = (((*puVar14 >> 0x18) << 8 | uVar4) << 8 | uVar11) << 8 | uVar16;

          puVar14 = puVar14 + 1;

LAB_140242253:

          uVar16 = *puVar14 & 0xff;

          uVar4 = (uVar8 * *(byte *)((longlong)puVar14 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar14 + 2) * iVar7) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar11 = (uVar9 * *(byte *)((longlong)puVar14 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff;

          if (0xff < uVar11) {

            uVar11 = 0xff;

          }

          uVar16 = (uVar15 * uVar16) / 0xff + (uVar16 * iVar7) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          iVar6 = iVar6 + -1;

          *puVar14 = (((*puVar14 >> 0x18) << 8 | uVar4) << 8 | uVar11) << 8 | uVar16;

          puVar14 = puVar14 + 1;

          if (iVar6 < 1) break;

LAB_14024201c:

          uVar16 = *puVar14 & 0xff;

          uVar4 = (uVar8 * *(byte *)((longlong)puVar14 + 2)) / 0xff +

                  ((uint)*(byte *)((longlong)puVar14 + 2) * iVar7) / 0xff;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar11 = (uVar9 * *(byte *)((longlong)puVar14 + 1)) / 0xff +

                   ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff;

          if (0xff < uVar11) {

            uVar11 = 0xff;

          }

          uVar16 = (uVar15 * uVar16) / 0xff + (uVar16 * iVar7) / 0xff;

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          *puVar14 = (((*puVar14 >> 0x18) << 8 | uVar4) << 8 | uVar11) << 8 | uVar16;

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar3;

        uVar1 = uVar1 - 1;

      }

      else {

        puVar14 = puVar14 + iVar3;

        uVar1 = uVar1 - 1;

      }

    }

    break;

  case 0x10:

    uVar8 = param_2[2];

    iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    iVar3 = iVar6 - uVar8;

    puVar14 = (uint *)(*(longlong *)(param_1 + 0x18) +

                      ((longlong)(iVar6 * param_2[1]) + (longlong)*param_2) * 4);

    uVar17 = param_2[3];

    while( true ) {

      uVar2 = (ulonglong)uVar17;

      if (uVar17 == 0) break;

      iVar6 = (int)(((int)(uVar8 + 3) >> 0x1f & 3U) + uVar8 + 3) >> 2;

      uVar1 = uVar8 & 3;

      if (uVar1 == 0) goto LAB_1402418dc;

      if (uVar1 == 1) goto LAB_140241abc;

      if (uVar1 == 2) goto LAB_140241a1c;

      if (uVar1 == 3) {

        while( true ) {

          uVar1 = *puVar14;

          uVar15 = ((uVar1 >> 0x10 & 0xff) * iVar7) / 0xff + (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar9 = ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff + (uint)param_5;

          if (0xff < uVar9) {

            uVar9 = 0xff;

          }

          uVar4 = ((uVar1 & 0xff) * iVar7) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar1 = ((uVar1 >> 0x18) * iVar7) / 0xff + (uint)param_7;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar14 = ((uVar1 << 8 | uVar15) << 8 | uVar9) << 8 | uVar4;

          puVar14 = puVar14 + 1;

LAB_140241a1c:

          uVar1 = *puVar14;

          uVar15 = ((uVar1 >> 0x10 & 0xff) * iVar7) / 0xff + (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar9 = ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff + (uint)param_5;

          if (0xff < uVar9) {

            uVar9 = 0xff;

          }

          uVar4 = ((uVar1 & 0xff) * iVar7) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar1 = ((uVar1 >> 0x18) * iVar7) / 0xff + (uint)param_7;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar14 = ((uVar1 << 8 | uVar15) << 8 | uVar9) << 8 | uVar4;

          puVar14 = puVar14 + 1;

LAB_140241abc:

          uVar1 = *puVar14;

          uVar15 = ((uVar1 >> 0x10 & 0xff) * iVar7) / 0xff + (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar9 = ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff + (uint)param_5;

          if (0xff < uVar9) {

            uVar9 = 0xff;

          }

          uVar4 = ((uVar1 & 0xff) * iVar7) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar1 = ((uVar1 >> 0x18) * iVar7) / 0xff + (uint)param_7;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          iVar6 = iVar6 + -1;

          *puVar14 = ((uVar1 << 8 | uVar15) << 8 | uVar9) << 8 | uVar4;

          puVar14 = puVar14 + 1;

          if (iVar6 < 1) break;

LAB_1402418dc:

          uVar1 = *puVar14;

          uVar15 = ((uVar1 >> 0x10 & 0xff) * iVar7) / 0xff + (uint)param_4;

          if (0xff < uVar15) {

            uVar15 = 0xff;

          }

          uVar9 = ((uint)*(byte *)((longlong)puVar14 + 1) * iVar7) / 0xff + (uint)param_5;

          if (0xff < uVar9) {

            uVar9 = 0xff;

          }

          uVar4 = ((uVar1 & 0xff) * iVar7) / 0xff + (uint)param_6;

          if (0xff < uVar4) {

            uVar4 = 0xff;

          }

          uVar1 = ((uVar1 >> 0x18) * iVar7) / 0xff + (uint)param_7;

          if (0xff < uVar1) {

            uVar1 = 0xff;

          }

          *puVar14 = ((uVar1 << 8 | uVar15) << 8 | uVar9) << 8 | uVar4;

          puVar14 = puVar14 + 1;

        }

        puVar14 = puVar14 + iVar3;

        uVar17 = uVar17 - 1;

      }

      else {

        puVar14 = puVar14 + iVar3;

        uVar17 = uVar17 - 1;

      }

    }

  }

  return CONCAT71((int7)(uVar2 >> 8),1);

}




