// Address: 0x140196db0
// Ghidra name: FUN_140196db0
// ============ 0x140196db0 FUN_140196db0 (size=2291) ============


longlong FUN_140196db0(int *param_1,undefined8 *param_2,ulonglong *param_3,undefined8 *param_4,

                      ulonglong *param_5)



{

  byte bVar1;

  uint *puVar2;

  byte bVar3;

  uint uVar4;

  ulonglong uVar5;

  ushort uVar6;

  ushort *puVar7;

  byte *pbVar8;

  byte *pbVar9;

  longlong lVar10;

  ulonglong uVar11;

  ushort uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  uint *puVar16;

  bool bVar17;

  bool bVar18;

  

  uVar5 = 0;

  if (param_1 == (int *)0xffffffffffffffff) {

    return -1;

  }

  if (param_2 == (undefined8 *)0x0) {

    return 0;

  }

  puVar2 = (uint *)*param_2;

  if (puVar2 == (uint *)0x0) {

    return 0;

  }

  if ((((param_4 == (undefined8 *)0x0) || (pbVar9 = (byte *)*param_4, pbVar9 == (byte *)0x0)) ||

      (param_5 == (ulonglong *)0x0)) || (uVar11 = *param_5, uVar11 == 0)) {

LAB_140197678:

    lVar10 = -2;

  }

  else {

    if (param_3 == (ulonglong *)0x0) {

      uVar15 = 0;

    }

    else {

      uVar15 = *param_3;

    }

    if (*param_1 == 4) {

      uVar13 = uVar15 >> 1;

      if (uVar13 != 0) {

        pbVar8 = (byte *)((longlong)puVar2 + 1);

        do {

          if (pbVar8[-1] == 0xff) {

            if (*pbVar8 == 0xfe) {

              *param_1 = 5;

              goto LAB_140196f08;

            }

          }

          else if ((pbVar8[-1] == 0xfe) && (*pbVar8 == 0xff)) {

            *param_1 = 6;

            goto LAB_140196f08;

          }

          pbVar8 = pbVar8 + 2;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      *param_1 = 6;

    }

    else if (*param_1 == 7) {

      uVar13 = uVar15 >> 2;

      if (uVar13 != 0) {

        puVar7 = (ushort *)((longlong)puVar2 + 2);

        do {

          if ((byte)puVar7[-1] == 0xff) {

            if (((*(byte *)((longlong)puVar7 + -1) == 0xfe) && ((byte)*puVar7 == 0)) &&

               (*(byte *)((longlong)puVar7 + 1) == 0)) {

              *param_1 = 8;

              goto LAB_140196f08;

            }

          }

          else if ((((byte)puVar7[-1] == 0) && (*(byte *)((longlong)puVar7 + -1) == 0)) &&

                  (((byte)*puVar7 == 0xfe && (*(byte *)((longlong)puVar7 + 1) == 0xff)))) {

            *param_1 = 9;

            goto LAB_140196f08;

          }

          puVar7 = puVar7 + 2;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      *param_1 = 9;

    }

LAB_140196f08:

    if (param_1[1] == 4) {

      if (uVar11 < 2) goto LAB_140197678;

      pbVar9[0] = 0xff;

      pbVar9[1] = 0xfe;

      pbVar9 = pbVar9 + 2;

      uVar11 = uVar11 - 2;

      param_1[1] = 6;

    }

    else if (param_1[1] == 7) {

      if (uVar11 < 4) goto LAB_140197678;

      pbVar9[0] = 0xff;

      pbVar9[1] = 0xfe;

      pbVar9[2] = 0;

      pbVar9[3] = 0;

      pbVar9 = pbVar9 + 4;

      uVar11 = uVar11 - 4;

      param_1[1] = 9;

    }

    lVar10 = 0;

    while (uVar15 != 0) {

      uVar13 = uVar15;

      puVar16 = puVar2;

      switch(*param_1) {

      case 1:

        puVar16 = (uint *)((longlong)puVar2 + 1);

        uVar5 = (ulonglong)((byte)*puVar2 & 0x7f);

        uVar13 = uVar15 - 1;

        break;

      case 2:

        uVar5 = (ulonglong)(byte)*puVar2;

        puVar16 = (uint *)((longlong)puVar2 + 1);

        uVar13 = uVar15 - 1;

        break;

      case 3:

        bVar3 = (byte)*puVar2;

        uVar13 = 0;

        uVar14 = 0;

        bVar17 = false;

        uVar4 = (uint)bVar3;

        if (bVar3 < 0xf0) {

          if (bVar3 < 0xe0) {

            if (bVar3 < 0xc0) {

              uVar5 = 0xfffd;

              if (-1 < (char)bVar3) {

                uVar5 = (ulonglong)bVar3;

              }

            }

            else if ((bVar3 & 0xe0) == 0xc0) {

              uVar14 = 1;

              uVar5 = (ulonglong)(uVar4 & 0x1f);

              bVar17 = (bVar3 & 0xde) == 0xc0;

            }

            else {

              uVar5 = 0xfffd;

              uVar14 = uVar13;

            }

          }

          else if ((bVar3 & 0xf0) == 0xe0) {

            if (((bVar3 == 0xe0) && (1 < uVar15)) && (bVar17 = false, (*puVar2 & 0xe000) == 0x8000))

            {

              bVar17 = true;

            }

            uVar5 = (ulonglong)(uVar4 & 0xf);

            uVar14 = 2;

          }

          else {

            uVar5 = 0xfffd;

            uVar14 = uVar13;

          }

        }

        else if ((bVar3 & 0xf8) == 0xf0) {

          if (((bVar3 == 0xf0) && (1 < uVar15)) && (bVar17 = false, (*puVar2 & 0xf000) == 0x8000)) {

            bVar17 = true;

          }

          uVar5 = (ulonglong)(uVar4 & 7);

          uVar14 = 3;

        }

        else {

          uVar5 = 0xfffd;

          uVar14 = uVar13;

        }

        uVar13 = uVar15 - 1;

        if (uVar13 < uVar14) {

          return -4;

        }

        while (puVar16 = (uint *)((longlong)puVar16 + 1), uVar14 != 0) {

          pbVar8 = (byte *)((longlong)puVar2 + 1);

          puVar2 = (uint *)((longlong)puVar2 + 1);

          uVar14 = uVar14 - 1;

          if ((*pbVar8 & 0xc0) != 0x80) {

            uVar5 = 0xfffd;

            break;

          }

          uVar5 = (ulonglong)(*pbVar8 & 0x3f | (int)uVar5 << 6);

          uVar13 = uVar13 - 1;

        }

        if ((((bVar17) || (uVar4 = (uint)uVar5, uVar4 - 0xd800 < 0x800)) || (uVar4 - 0xfffe < 2)) ||

           (0x10ffff < uVar4)) {

          uVar5 = 0xfffd;

        }

        break;

      case 5:

        if (uVar15 < 2) {

          return -4;

        }

        uVar13 = uVar15 - 2;

        puVar16 = (uint *)((longlong)puVar2 + 2);

        uVar6 = CONCAT11((byte)*puVar2,*(byte *)((longlong)puVar2 + 1));

        if ((ushort)(uVar6 + 0x2800) < 0x800) {

          if (uVar6 < 0xdc00) {

            if (uVar13 < 2) {

              return -4;

            }

            bVar3 = *(byte *)puVar16;

            bVar1 = *(byte *)((longlong)puVar2 + 3);

LAB_14019719b:

            puVar16 = puVar2 + 1;

            uVar13 = uVar15 - 4;

            if ((ushort)(CONCAT11(bVar3,bVar1) + 0x2400) < 0x400) {

              uVar5 = (ulonglong)(((uVar6 & 0x3ff) << 10 | CONCAT11(bVar3,bVar1) & 0x3ff) + 0x10000)

              ;

              break;

            }

          }

          uVar5 = 0xfffd;

        }

        else {

LAB_1401971d0:

          uVar13 = uVar15 - 2;

          uVar5 = (ulonglong)uVar6;

          puVar16 = (uint *)((longlong)puVar2 + 2);

        }

        break;

      case 6:

        if (uVar15 < 2) {

          return -4;

        }

        uVar6 = (ushort)*puVar2;

        uVar13 = uVar15 - 2;

        puVar16 = (uint *)((longlong)puVar2 + 2);

        if (0x7ff < (ushort)(uVar6 + 0x2800)) goto LAB_1401971d0;

        if (uVar6 < 0xdc00) {

          if (uVar13 < 2) {

            return -4;

          }

          bVar3 = *(byte *)((longlong)puVar2 + 3);

          bVar1 = *(byte *)puVar16;

          goto LAB_14019719b;

        }

        uVar5 = 0xfffd;

        break;

      case 8:

      case 0xc:

        if (uVar15 < 4) {

          return -4;

        }

        puVar16 = puVar2 + 1;

        uVar5 = (ulonglong)

                CONCAT31(CONCAT21(CONCAT11((byte)*puVar2,*(byte *)((longlong)puVar2 + 1)),

                                  *(byte *)((longlong)puVar2 + 2)),*(byte *)((longlong)puVar2 + 3));

        uVar13 = uVar15 - 4;

        break;

      case 9:

      case 0xd:

        if (uVar15 < 4) {

          return -4;

        }

        puVar16 = puVar2 + 1;

        uVar5 = (ulonglong)*puVar2;

        uVar13 = uVar15 - 4;

        break;

      case 10:

        if (uVar15 < 2) {

          return -4;

        }

        puVar16 = (uint *)((longlong)puVar2 + 2);

        uVar5 = (ulonglong)CONCAT11((byte)*puVar2,*(byte *)((longlong)puVar2 + 1));

        uVar13 = uVar15 - 2;

        break;

      case 0xb:

        if (uVar15 < 2) {

          return -4;

        }

        puVar16 = (uint *)((longlong)puVar2 + 2);

        uVar5 = (ulonglong)(ushort)*puVar2;

        uVar13 = uVar15 - 2;

      }

      bVar3 = (byte)uVar5;

      uVar4 = (uint)uVar5;

      switch(param_1[1]) {

      case 1:

        if (uVar11 != 0) {

          bVar17 = uVar4 < 0x7f;

          bVar18 = uVar4 == 0x7f;

          goto LAB_140197302;

        }

        goto LAB_140197678;

      case 2:

        if (uVar11 == 0) goto LAB_140197678;

        bVar17 = uVar4 < 0xff;

        bVar18 = uVar4 == 0xff;

LAB_140197302:

        if (!bVar17 && !bVar18) {

          bVar3 = 0x3f;

        }

        *pbVar9 = bVar3;

        pbVar9 = pbVar9 + 1;

        uVar11 = uVar11 - 1;

        break;

      case 3:

        if (uVar4 < 0x110000) {

          if (uVar4 < 0x80) {

            if (uVar11 == 0) goto LAB_140197678;

            *pbVar9 = bVar3;

            pbVar9 = pbVar9 + 1;

            uVar11 = uVar11 - 1;

          }

          else if (uVar4 < 0x800) {

            if (uVar11 < 2) goto LAB_140197678;

            *pbVar9 = (byte)(uVar5 >> 6) & 0x1f | 0xc0;

            pbVar9[1] = bVar3 & 0x3f | 0x80;

            pbVar9 = pbVar9 + 2;

            uVar11 = uVar11 - 2;

          }

          else {

            if (uVar4 < 0x10000) goto LAB_1401973a9;

            if (uVar11 < 4) goto LAB_140197678;

            *pbVar9 = (byte)(uVar5 >> 0x12) & 7 | 0xf0;

            pbVar9[1] = (byte)(uVar5 >> 0xc) & 0x3f | 0x80;

            pbVar9[2] = (byte)(uVar5 >> 6) & 0x3f | 0x80;

            pbVar9[3] = bVar3 & 0x3f | 0x80;

            pbVar9 = pbVar9 + 4;

            uVar11 = uVar11 - 4;

          }

        }

        else {

          uVar5 = 0xfffd;

LAB_1401973a9:

          if (uVar11 < 3) goto LAB_140197678;

          *pbVar9 = (byte)(uVar5 >> 0xc) & 0xf | 0xe0;

          pbVar9[1] = (byte)(uVar5 >> 6) & 0x3f | 0x80;

          pbVar9[2] = (byte)uVar5 & 0x3f | 0x80;

          pbVar9 = pbVar9 + 3;

          uVar11 = uVar11 - 3;

        }

        break;

      case 5:

        if (uVar4 < 0x110000) {

          if (0xffff < uVar4) {

            if (3 < uVar11) {

              uVar4 = uVar4 - 0x10000;

              uVar5 = (ulonglong)uVar4;

              uVar6 = (ushort)uVar4 & 0x3ff;

              uVar12 = (ushort)(uVar4 >> 10) & 0x3ff;

              pbVar9[3] = (byte)uVar6;

              pbVar9[1] = (byte)uVar12;

              *pbVar9 = (byte)(uVar12 >> 8) | 0xd8;

              pbVar9[2] = (byte)(uVar6 >> 8) | 0xdc;

              pbVar9 = pbVar9 + 4;

              uVar11 = uVar11 - 4;

              break;

            }

            goto LAB_140197678;

          }

        }

        else {

          uVar5 = 0xfffd;

        }

        if (uVar11 < 2) goto LAB_140197678;

        pbVar9[1] = (byte)uVar5;

        *pbVar9 = (byte)(uVar5 >> 8);

        pbVar9 = pbVar9 + 2;

        uVar11 = uVar11 - 2;

        break;

      case 6:

        if (uVar4 < 0x110000) {

          if (0xffff < uVar4) {

            if (3 < uVar11) {

              uVar4 = uVar4 - 0x10000;

              uVar5 = (ulonglong)uVar4;

              uVar6 = (ushort)uVar4 & 0x3ff;

              uVar12 = (ushort)(uVar4 >> 10) & 0x3ff;

              pbVar9[2] = (byte)uVar6;

              *pbVar9 = (byte)uVar12;

              pbVar9[1] = (byte)(uVar12 >> 8) | 0xd8;

              pbVar9[3] = (byte)(uVar6 >> 8) | 0xdc;

              pbVar9 = pbVar9 + 4;

              uVar11 = uVar11 - 4;

              break;

            }

            goto LAB_140197678;

          }

        }

        else {

          uVar5 = 0xfffd;

        }

        if (uVar11 < 2) goto LAB_140197678;

        *pbVar9 = (byte)uVar5;

        pbVar9[1] = (byte)(uVar5 >> 8);

        pbVar9 = pbVar9 + 2;

        uVar11 = uVar11 - 2;

        break;

      case 8:

        if (0x10ffff < uVar4) {

          uVar5 = 0xfffd;

        }

        goto LAB_1401975ed;

      case 9:

        if (0x10ffff < uVar4) {

          uVar5 = 0xfffd;

        }

        goto LAB_140197628;

      case 10:

        if (0xffff < uVar4) {

          uVar5 = 0xfffd;

        }

        if (uVar11 < 2) goto LAB_140197678;

        pbVar9[1] = (byte)uVar5;

        *pbVar9 = (byte)(uVar5 >> 8);

        pbVar9 = pbVar9 + 2;

        uVar11 = uVar11 - 2;

        break;

      case 0xb:

        if (0xffff < uVar4) {

          uVar5 = 0xfffd;

        }

        if (uVar11 < 2) goto LAB_140197678;

        *pbVar9 = (byte)uVar5;

        pbVar9[1] = (byte)(uVar5 >> 8);

        pbVar9 = pbVar9 + 2;

        uVar11 = uVar11 - 2;

        break;

      case 0xc:

        if (0x7fffffff < uVar4) {

          uVar5 = 0xfffd;

        }

LAB_1401975ed:

        if (uVar11 < 4) goto LAB_140197678;

        pbVar9[3] = (byte)uVar5;

        *pbVar9 = (byte)(uVar5 >> 0x18);

        pbVar9[1] = (byte)(uVar5 >> 0x10);

        pbVar9[2] = (byte)(uVar5 >> 8);

LAB_140197648:

        pbVar9 = pbVar9 + 4;

        uVar11 = uVar11 - 4;

        break;

      case 0xd:

        if (0x7fffffff < uVar4) {

          uVar5 = 0xfffd;

        }

LAB_140197628:

        if (3 < uVar11) {

          *pbVar9 = (byte)uVar5;

          pbVar9[3] = (byte)(uVar5 >> 0x18);

          pbVar9[2] = (byte)(uVar5 >> 0x10);

          pbVar9[1] = (byte)(uVar5 >> 8);

          goto LAB_140197648;

        }

        goto LAB_140197678;

      }

      *param_2 = puVar16;

      lVar10 = lVar10 + 1;

      *param_3 = uVar13;

      *param_4 = pbVar9;

      *param_5 = uVar11;

      puVar2 = puVar16;

      uVar15 = uVar13;

    }

  }

  return lVar10;

}




