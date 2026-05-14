// Address: 0x14024cf80
// Ghidra name: FUN_14024cf80
// ============ 0x14024cf80 FUN_14024cf80 (size=11211) ============


ushort * FUN_14024cf80(longlong param_1,int param_2,int param_3,int param_4,uint param_5,int param_6

                      ,byte param_7,byte param_8,byte param_9,byte param_10,byte param_11)



{

  ushort *puVar1;

  longlong lVar2;

  longlong lVar3;

  bool bVar4;

  ushort uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  ushort *puVar10;

  uint uVar11;

  ushort *puVar12;

  uint uVar13;

  uint uVar14;

  int iVar15;

  uint uVar16;

  ulonglong uVar17;

  longlong lVar18;

  int iVar19;

  longlong lVar20;

  int iVar21;

  uint uVar22;

  uint uVar23;

  ushort *local_res8;

  uint local_res18;

  int local_80;

  uint local_7c;

  ulonglong local_78;

  ulonglong local_70;

  

  iVar19 = param_5;

  lVar2 = *(longlong *)(param_1 + 0x38);

  lVar20 = (longlong)param_2;

  if (param_6 - 1U < 2) {

    uVar14 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar22 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar13 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar14 = (uint)param_7;

    uVar22 = (uint)param_8;

    uVar13 = (uint)param_9;

  }

  uVar23 = param_10 ^ 0xff;

  param_6 = param_6 + -1;

  if (param_3 == param_5) {

    switch(param_6) {

    case 0:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar11) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar20) * 2);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar17 = (ulonglong)*puVar12;

        puVar10 = (ushort *)

                  ((ulonglong)

                   ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                          [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                   uVar23) * 0x80808081 & 0xffffffff);

        *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                  [(*(uint *)(lVar2 + 8) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff + uVar14 >>

                          (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) << (*(byte *)(lVar2 + 0x1c) & 0x1f)

                   | (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff + uVar13 >>

                            (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                  [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff + uVar22 >>

                          (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) << (*(byte *)(lVar2 + 0x1d) & 0x1f)

                   | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar23 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar23;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar23) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar23 + lVar20) * 2);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar17 = (ulonglong)*puVar12;

        uVar23 = uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)

                                ];

        if (0xff < uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                  [(*(uint *)(lVar2 + 8) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1c) & 0x3f)]) {

          uVar23 = 0xff;

        }

        uVar11 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                       [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                 uVar22;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                         [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                   uVar22) {

          uVar11 = 0xff;

        }

        uVar16 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                 uVar13;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                         [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                   uVar13) {

          uVar16 = 0xff;

        }

        uVar23 = uVar23 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f);

        uVar5 = (short)uVar23 << (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar23 >> 0x10),uVar5);

        *puVar12 = uVar5;

        puVar12 = puVar12 + 1;

      }

      break;

    default:

      uVar23 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar23;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar23) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar23 + lVar20) * 2);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar23 = uVar14 >> (8U - *(char *)(lVar2 + 0x18) & 0x1f);

        uVar5 = (short)uVar23 << (*(byte *)(lVar2 + 0x1c) & 0x1f);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar23 >> 0x10),uVar5);

        *puVar12 = (short)(uVar13 >> (8U - *(char *)(lVar2 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(uVar22 >> (8U - *(char *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) | uVar5 | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + 1;

      }

      break;

    case 3:

      uVar23 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar23;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar23) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar23 + lVar20) * 2);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar17 = (ulonglong)*puVar12;

        puVar10 = (ushort *)

                  ((ulonglong)

                   ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                          [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] *

                   uVar13) * 0x80808081 & 0xffffffff);

        *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                  [(*(uint *)(lVar2 + 8) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                          (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) << (*(byte *)(lVar2 + 0x1c) & 0x1f)

                   | (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                    [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar22) / 0xff >>

                            (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar2 + 0x1d) & 0x1f) |

                   (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                  [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar13) / 0xff >>

                          (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) << (*(byte *)(lVar2 + 0x1e) & 0x1f)

                   | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + 1;

      }

      break;

    case 7:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar11) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar20) * 2);

      }

      while (iVar19 != 0) {

        uVar17 = (ulonglong)*puVar12;

        iVar19 = iVar19 + -1;

        uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                        [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                 uVar23) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                        [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                 uVar14) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar16 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                        [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                 uVar23) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                        [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                 uVar22) / 0xff;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] *

                uVar23) / 0xff +

                ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] *

                uVar13) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        uVar9 = uVar9 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f);

        uVar5 = (short)uVar9 << (*(byte *)(lVar2 + 0x1e) & 0x1f);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar9 >> 0x10),uVar5);

        *puVar12 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1c) & 0x1f) | uVar5 |

                   (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + 1;

      }

      break;

    case 0xf:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5)) * param_3;

      puVar10 = (ushort *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar11) * 2);

        puVar10 = (ushort *)(ulonglong)param_11;

        puVar12 = puVar1 + 1;

        if (param_11 != 0) {

          puVar12 = puVar1;

        }

        iVar19 = param_2 - param_4;

        if (param_11 != 0) {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        iVar19 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar19 = param_4 - param_2;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar20) * 2);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar17 = (ulonglong)*puVar12;

        uVar11 = uVar14 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                 [(*(uint *)(lVar2 + 8) & uVar17) >>

                                  (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar16 = uVar22 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                 [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                  (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar9 = uVar13 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                 (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        uVar9 = uVar9 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f);

        uVar5 = (short)uVar9 << (*(byte *)(lVar2 + 0x1e) & 0x1f);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar9 >> 0x10),uVar5);

        *puVar12 = (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) |

                   (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1c) & 0x1f) | uVar5 | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(param_6) {

    case 0:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)((int)(iVar19 * param_5) + lVar20);

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

        if (param_11 == 0) {

          puVar12 = puVar12 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        puVar10 = (ushort *)(iVar19 * param_3 + lVar20);

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar17 = (ulonglong)*puVar12;

        puVar10 = (ushort *)

                  ((ulonglong)

                   ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                          [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                   uVar23) * 0x80808081 & 0xffffffff);

        *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                  [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff + uVar13 >>

                          (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) << (*(byte *)(lVar2 + 0x1e) & 0x1f)

                   | (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                    [(*(uint *)(lVar2 + 8) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff + uVar14 >>

                            (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                   (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                  [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff + uVar22 >>

                          (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) << (*(byte *)(lVar2 + 0x1d) & 0x1f)

                   | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + iVar19;

      }

      break;

    case 1:

    case 0x1f:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)((int)(iVar19 * param_5) + lVar20);

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

        if (param_11 == 0) {

          puVar12 = puVar12 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        puVar10 = (ushort *)(iVar19 * param_3 + lVar20);

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar17 = (ulonglong)*puVar12;

        uVar23 = uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)

                                ];

        if (0xff < uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                  [(*(uint *)(lVar2 + 8) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1c) & 0x3f)]) {

          uVar23 = 0xff;

        }

        uVar11 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                       [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                 uVar22;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                         [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                   uVar22) {

          uVar11 = 0xff;

        }

        uVar16 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                 uVar13;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                         [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                   uVar13) {

          uVar16 = 0xff;

        }

        uVar23 = uVar23 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f);

        uVar5 = (short)uVar23 << (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar23 >> 0x10),uVar5);

        *puVar12 = uVar5;

        puVar12 = puVar12 + iVar19;

      }

      break;

    default:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)((int)(iVar19 * param_5) + lVar20);

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

        if (param_11 == 0) {

          puVar12 = puVar12 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        puVar10 = (ushort *)(iVar19 * param_3 + lVar20);

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar23 = uVar14 >> (8U - *(char *)(lVar2 + 0x18) & 0x1f);

        uVar5 = (short)uVar23 << (*(byte *)(lVar2 + 0x1c) & 0x1f);

        puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar23 >> 0x10),uVar5);

        *puVar12 = (short)(uVar13 >> (8U - *(char *)(lVar2 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(uVar22 >> (8U - *(char *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) | uVar5 | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + iVar19;

      }

      break;

    case 3:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)((int)(iVar19 * param_5) + lVar20);

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

        if (param_11 == 0) {

          puVar12 = puVar12 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        puVar10 = (ushort *)(iVar19 * param_3 + lVar20);

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar10 * 2);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar17 = (ulonglong)*puVar12;

        puVar10 = (ushort *)

                  ((ulonglong)

                   ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                          [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                   uVar14) * 0x80808081 & 0xffffffff);

        *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                  [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar22) / 0xff >>

                          (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) << (*(byte *)(lVar2 + 0x1d) & 0x1f)

                   | (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar13) / 0xff >>

                            (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                  [(*(uint *)(lVar2 + 8) & uVar17) >>

                                   (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                          (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) << (*(byte *)(lVar2 + 0x1c) & 0x1f)

                   | *(ushort *)(lVar2 + 0x14);

        puVar12 = puVar12 + iVar19;

      }

      break;

    case 7:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar19 * param_5) + lVar20) * 2)

        ;

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar10 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

      }

      while (iVar21 != 0) {

        uVar17 = (ulonglong)*puVar10;

        iVar21 = iVar21 + -1;

        uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                        [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                 uVar23) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                        [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                 uVar14) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar16 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                        [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                 uVar23) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                        [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                 uVar22) / 0xff;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] *

                uVar23) / 0xff +

                ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                       [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] *

                uVar13) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        *puVar10 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                   (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

        puVar10 = puVar10 + iVar19;

      }

      break;

    case 0xf:

      iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

      if ((int)param_5 < param_3) {

        iVar21 = param_3 - param_5;

        puVar10 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar19 * param_5) + lVar20) * 2)

        ;

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar19;

        }

        else {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar21 = param_5 - param_3;

        }

        puVar10 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar17 = (ulonglong)*puVar10;

        uVar11 = uVar14 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                 [(*(uint *)(lVar2 + 8) & uVar17) >>

                                  (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar16 = uVar22 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                 [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                  (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar9 = uVar13 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                 (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        *puVar10 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                   (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                   (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

        puVar10 = puVar10 + iVar19;

      }

    }

  }

  else {

    uVar16 = param_3 - param_5;

    uVar11 = -(param_2 - param_4);

    if ((int)uVar11 < 0) {

      uVar11 = param_2 - param_4;

    }

    uVar9 = -uVar16;

    if ((int)-uVar16 < 0) {

      uVar9 = uVar16;

    }

    if (uVar11 == uVar9) {

      switch(param_6) {

      case 0:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          puVar10 = (ushort *)0xffffffff;

          puVar12 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(int)(iVar19 * param_5) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            puVar10 = (ushort *)(longlong)iVar21;

            puVar12 = puVar12 + (longlong)puVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar10 = (ushort *)0xffffffff;

          puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

        }

        uVar11 = uVar16 + 1;

        if (param_11 == 0) {

          uVar11 = uVar16;

        }

        if (uVar11 != 0) {

          do {

            uVar17 = (ulonglong)*puVar12;

            puVar10 = (ushort *)

                      ((ulonglong)

                       ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                              [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)

                              ] * uVar23) * 0x80808081 & 0xffffffff);

            *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                      [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff + uVar13

                              >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff + uVar14

                              >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                      [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff + uVar22

                              >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            puVar12 = puVar12 + iVar21;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      case 1:

      case 0x1f:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          puVar12 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(int)(iVar19 * param_5) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            puVar12 = puVar12 + iVar21;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

        }

        uVar23 = uVar16 + 1;

        if (param_11 == 0) {

          uVar23 = uVar16;

        }

        puVar10 = (ushort *)(ulonglong)uVar23;

        if (uVar23 != 0) {

          do {

            uVar17 = (ulonglong)*puVar12;

            uVar11 = (int)puVar10 - 1;

            uVar23 = uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                    [(*(uint *)(lVar2 + 8) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1c) & 0x3f)];

            if (0xff < uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)]) {

              uVar23 = 0xff;

            }

            uVar16 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                           [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                     uVar22;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                             [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)]

                       + uVar22) {

              uVar16 = 0xff;

            }

            uVar9 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                          [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                    uVar13;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                             [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)

                             ] + uVar13) {

              uVar9 = 0xff;

            }

            *puVar12 = (short)(uVar23 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            puVar12 = puVar12 + iVar21;

            puVar10 = (ushort *)(ulonglong)uVar11;

          } while (uVar11 != 0);

          puVar10 = (ushort *)0x0;

        }

        break;

      default:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          puVar10 = (ushort *)0xffffffff;

          puVar12 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(int)(iVar19 * param_5) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            puVar10 = (ushort *)(longlong)iVar21;

            puVar12 = puVar12 + (longlong)puVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar10 = (ushort *)0xffffffff;

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

        }

        uVar23 = uVar16 + 1;

        if (param_11 == 0) {

          uVar23 = uVar16;

        }

        if (uVar23 != 0) {

          do {

            uVar11 = uVar14 >> (8U - *(char *)(lVar2 + 0x18) & 0x1f);

            uVar5 = (short)uVar11 << (*(byte *)(lVar2 + 0x1c) & 0x1f);

            puVar10 = (ushort *)(ulonglong)CONCAT22((short)(uVar11 >> 0x10),uVar5);

            *puVar12 = (short)(uVar13 >> (8U - *(char *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(uVar22 >> (8U - *(char *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | uVar5 | *(ushort *)(lVar2 + 0x14);

            puVar12 = puVar12 + iVar21;

            uVar23 = uVar23 - 1;

          } while (uVar23 != 0);

        }

        break;

      case 3:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          puVar10 = (ushort *)0xffffffff;

          puVar12 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(int)(iVar19 * param_5) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            puVar10 = (ushort *)(longlong)iVar21;

            puVar12 = puVar12 + (longlong)puVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar10 = (ushort *)0xffffffff;

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          puVar12 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

        }

        uVar23 = uVar16 + 1;

        if (param_11 == 0) {

          uVar23 = uVar16;

        }

        if (uVar23 != 0) {

          do {

            uVar17 = (ulonglong)*puVar12;

            puVar10 = (ushort *)

                      ((ulonglong)

                       ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                              [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)

                              ] * uVar22) * 0x80808081 & 0xffffffff);

            *puVar12 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                      [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar13) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                      [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar22) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            puVar12 = puVar12 + iVar21;

            uVar23 = uVar23 - 1;

          } while (uVar23 != 0);

        }

        break;

      case 7:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (ushort *)

                       (*(longlong *)(param_1 + 0x18) +

                       ((longlong)(int)(param_5 * iVar19) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar21;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          local_res8 = (ushort *)(*(longlong *)(param_1 + 0x18) + (param_3 * iVar19 + lVar20) * 2);

          iVar21 = iVar21 + iVar19;

        }

        uVar11 = uVar16 + 1;

        if (param_11 == 0) {

          uVar11 = uVar16;

        }

        puVar10 = (ushort *)(ulonglong)uVar11;

        if (uVar11 != 0) {

          do {

            uVar17 = (ulonglong)*local_res8;

            uVar16 = (int)puVar10 - 1;

            uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                            [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                     uVar23) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                            [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                     uVar14) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar9 = (uVar23 * (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                    [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1d) & 0x3f)]) / 0xff +

                    (uVar22 * (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                    [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1d) & 0x3f)]) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar6 = (uVar23 * (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)]) / 0xff +

                    (uVar13 * (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)]) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            puVar10 = (ushort *)(ulonglong)uVar16;

            *local_res8 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                          (short)(uVar6 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                          (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            local_res8 = local_res8 + iVar21;

          } while (uVar16 != 0);

          puVar10 = (ushort *)0x0;

        }

        break;

      case 0xf:

        iVar19 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar2 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (ushort *)

                       (*(longlong *)(param_1 + 0x18) +

                       ((longlong)(int)(iVar19 * param_5) + (longlong)param_4) * 2);

          iVar21 = 1;

          if (param_2 < param_4) {

            iVar21 = -1;

          }

          iVar21 = iVar21 + iVar19;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar21;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar21 = 1;

          if (param_4 < param_2) {

            iVar21 = -1;

          }

          local_res8 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar19 * param_3 + lVar20) * 2);

          iVar21 = iVar21 + iVar19;

        }

        uVar11 = uVar16 + 1;

        if (param_11 == 0) {

          uVar11 = uVar16;

        }

        puVar10 = (ushort *)(ulonglong)uVar11;

        if (uVar11 != 0) {

          do {

            uVar17 = (ulonglong)*local_res8;

            uVar16 = (int)puVar10 - 1;

            uVar11 = uVar14 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                     [(*(uint *)(lVar2 + 8) & uVar17) >>

                                      (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar9 = uVar22 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                    [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar6 = uVar13 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            puVar10 = (ushort *)(ulonglong)uVar16;

            *local_res8 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                          (short)(uVar6 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                          (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            local_res8 = local_res8 + iVar21;

          } while (uVar16 != 0);

          puVar10 = (ushort *)0x0;

        }

      }

    }

    else {

      local_res18 = param_3;

      switch(param_6) {

      case 0:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar4 = (int)uVar11 < (int)uVar16;

        if (bVar4) {

          local_7c = uVar11 * 2;

          local_res18 = local_7c - uVar16;

          iVar19 = uVar11 - uVar16;

        }

        else {

          local_7c = uVar16 * 2;

          local_res18 = local_7c - uVar11;

          iVar19 = uVar16 - uVar11;

          uVar16 = uVar11;

        }

        uVar11 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar4;

        }

        uVar9 = -(uint)bVar4;

        if (param_3 <= (int)param_5) {

          uVar9 = (uint)bVar4;

        }

        puVar10 = (ushort *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar10 = (ushort *)0x1;

        }

        uVar7 = (uint)puVar10;

        uVar6 = uVar16 + 1;

        if (param_11 == 0) {

          uVar6 = uVar16;

        }

        if (0 < (int)uVar6) {

          lVar20 = lVar20 * 2;

          lVar18 = -2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          local_70 = (ulonglong)uVar6;

          do {

            puVar10 = (ushort *)

                      ((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                       *(longlong *)(param_1 + 0x18) + lVar20);

            uVar17 = (ulonglong)*puVar10;

            *puVar10 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                      [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff + uVar22

                              >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                      [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff + uVar13

                              >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff + uVar14

                              >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            uVar16 = iVar19 * 2;

            uVar6 = uVar7;

            if ((int)local_res18 < 0) {

              lVar3 = (longlong)(int)uVar11 * 2;

              uVar16 = local_7c;

              uVar6 = uVar9;

            }

            param_3 = param_3 + uVar6;

            local_res18 = local_res18 + uVar16;

            puVar10 = (ushort *)(ulonglong)local_res18;

            lVar20 = lVar20 + lVar3;

            local_70 = local_70 - 1;

          } while (local_70 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar23 = -(param_4 - param_2);

        if ((int)uVar23 < 0) {

          uVar23 = param_4 - param_2;

        }

        uVar11 = -(param_5 - param_3);

        if ((int)uVar11 < 0) {

          uVar11 = param_5 - param_3;

        }

        bVar4 = (int)uVar23 < (int)uVar11;

        if (bVar4) {

          local_80 = uVar23 * 2;

          local_res18 = local_80 - uVar11;

          iVar19 = uVar23 - uVar11;

        }

        else {

          local_80 = uVar11 * 2;

          local_res18 = local_80 - uVar23;

          iVar19 = uVar11 - uVar23;

          uVar11 = uVar23;

        }

        uVar23 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar23 = (uint)!bVar4;

        }

        uVar16 = -(uint)bVar4;

        if (param_3 <= (int)param_5) {

          uVar16 = (uint)bVar4;

        }

        puVar10 = (ushort *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar10 = (ushort *)0x1;

        }

        uVar6 = (uint)puVar10;

        uVar9 = uVar11 + 1;

        if (param_11 == 0) {

          uVar9 = uVar11;

        }

        if (0 < (int)uVar9) {

          lVar20 = lVar20 * 2;

          lVar18 = -2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          local_78 = (ulonglong)uVar9;

          do {

            puVar10 = (ushort *)

                      ((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                       *(longlong *)(param_1 + 0x18) + lVar20);

            uVar17 = (ulonglong)*puVar10;

            uVar11 = uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                    [(*(uint *)(lVar2 + 8) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1c) & 0x3f)];

            if (0xff < uVar14 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)]) {

              uVar11 = 0xff;

            }

            uVar9 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                          [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] +

                    uVar22;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                             [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)]

                       + uVar22) {

              uVar9 = 0xff;

            }

            uVar7 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                          [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)] +

                    uVar13;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                             [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)

                             ] + uVar13) {

              uVar7 = 0xff;

            }

            *puVar10 = (short)(uVar11 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(uVar7 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(uVar9 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            iVar21 = iVar19 * 2;

            uVar11 = uVar6;

            if ((int)local_res18 < 0) {

              lVar3 = (longlong)(int)uVar23 * 2;

              iVar21 = local_80;

              uVar11 = uVar16;

            }

            param_3 = param_3 + uVar11;

            local_res18 = local_res18 + iVar21;

            puVar10 = (ushort *)(ulonglong)local_res18;

            lVar20 = lVar20 + lVar3;

            local_78 = local_78 - 1;

          } while (local_78 != 0);

        }

        break;

      default:

        uVar23 = -(param_4 - param_2);

        if ((int)uVar23 < 0) {

          uVar23 = param_4 - param_2;

        }

        uVar11 = param_5 - param_3;

        param_5 = -uVar11;

        if ((int)param_5 < 0) {

          param_5 = uVar11;

        }

        bVar4 = (int)uVar23 < (int)param_5;

        if (bVar4) {

          param_6 = uVar23 * 2;

          iVar15 = param_6 - param_5;

          iVar21 = uVar23 - param_5;

        }

        else {

          param_6 = param_5 * 2;

          iVar15 = param_6 - uVar23;

          iVar21 = param_5 - uVar23;

          param_5 = uVar23;

        }

        local_res18 = (uint)!bVar4;

        uVar23 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar23 = local_res18;

        }

        uVar11 = -(uint)bVar4;

        if (param_3 <= iVar19) {

          uVar11 = (uint)bVar4;

        }

        uVar16 = 0xffffffff;

        if (param_3 <= iVar19) {

          uVar16 = 1;

        }

        puVar10 = (ushort *)(ulonglong)param_5;

        uVar9 = param_5 + 1;

        if (param_11 == 0) {

          uVar9 = param_5;

        }

        if (0 < (int)uVar9) {

          uVar17 = (ulonglong)uVar9;

          lVar18 = -2;

          lVar20 = lVar20 * 2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          do {

            uVar9 = param_3 * *(int *)(param_1 + 0x10);

            puVar10 = (ushort *)(ulonglong)uVar9;

            *(ushort *)((longlong)(int)uVar9 + *(longlong *)(param_1 + 0x18) + lVar20) =

                 (short)(uVar13 >> (8U - *(char *)(lVar2 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                 (short)(uVar22 >> (8U - *(char *)(lVar2 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar2 + 0x1d) & 0x1f) |

                 (short)(uVar14 >> (8U - *(char *)(lVar2 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar2 + 0x1c) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            iVar19 = iVar21 * 2;

            uVar9 = uVar16;

            if (iVar15 < 0) {

              lVar3 = (longlong)(int)uVar23 * 2;

              iVar19 = param_6;

              uVar9 = uVar11;

            }

            param_3 = param_3 + uVar9;

            iVar15 = iVar15 + iVar19;

            lVar20 = lVar20 + lVar3;

            uVar17 = uVar17 - 1;

          } while (uVar17 != 0);

        }

        break;

      case 3:

        uVar23 = -(param_4 - param_2);

        if ((int)uVar23 < 0) {

          uVar23 = param_4 - param_2;

        }

        uVar11 = -(param_5 - param_3);

        if ((int)uVar11 < 0) {

          uVar11 = param_5 - param_3;

        }

        bVar4 = (int)uVar23 < (int)uVar11;

        if (bVar4) {

          local_80 = uVar23 * 2;

          local_res18 = local_80 - uVar11;

          iVar19 = uVar23 - uVar11;

        }

        else {

          local_80 = uVar11 * 2;

          local_res18 = local_80 - uVar23;

          iVar19 = uVar11 - uVar23;

          uVar11 = uVar23;

        }

        uVar23 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar23 = (uint)!bVar4;

        }

        uVar16 = -(uint)bVar4;

        if (param_3 <= (int)param_5) {

          uVar16 = (uint)bVar4;

        }

        puVar10 = (ushort *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar10 = (ushort *)0x1;

        }

        uVar6 = (uint)puVar10;

        uVar9 = uVar11 + 1;

        if (param_11 == 0) {

          uVar9 = uVar11;

        }

        if (0 < (int)uVar9) {

          lVar20 = lVar20 * 2;

          lVar18 = -2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          local_78 = (ulonglong)uVar9;

          do {

            puVar10 = (ushort *)

                      ((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                       *(longlong *)(param_1 + 0x18) + lVar20);

            uVar17 = (ulonglong)*puVar10;

            *puVar10 = (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                      [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar13) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                      [(*(uint *)(lVar2 + 8) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                      [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                       (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar22) / 0xff >>

                              (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            iVar21 = iVar19 * 2;

            uVar11 = uVar6;

            if ((int)local_res18 < 0) {

              lVar3 = (longlong)(int)uVar23 * 2;

              iVar21 = local_80;

              uVar11 = uVar16;

            }

            param_3 = param_3 + uVar11;

            local_res18 = local_res18 + iVar21;

            puVar10 = (ushort *)(ulonglong)local_res18;

            lVar20 = lVar20 + lVar3;

            local_78 = local_78 - 1;

          } while (local_78 != 0);

        }

        break;

      case 7:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar4 = (int)uVar11 < (int)uVar16;

        if (bVar4) {

          local_80 = uVar11 * 2;

          local_7c = local_80 - uVar16;

          iVar19 = uVar11 - uVar16;

        }

        else {

          local_80 = uVar16 * 2;

          local_7c = local_80 - uVar11;

          iVar19 = uVar16 - uVar11;

          uVar16 = uVar11;

        }

        uVar11 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar4;

        }

        uVar9 = -(uint)bVar4;

        if (param_3 <= (int)param_5) {

          uVar9 = (uint)bVar4;

        }

        puVar10 = (ushort *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar10 = (ushort *)0x1;

        }

        uVar7 = (uint)puVar10;

        uVar6 = uVar16 + 1;

        if (param_11 == 0) {

          uVar6 = uVar16;

        }

        if (0 < (int)uVar6) {

          lVar20 = lVar20 * 2;

          lVar18 = -2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          local_78 = (ulonglong)uVar6;

          do {

            puVar10 = (ushort *)

                      ((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                       *(longlong *)(param_1 + 0x18) + lVar20);

            uVar17 = (ulonglong)*puVar10;

            uVar16 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                            [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                     uVar23) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                            [(*(uint *)(lVar2 + 8) & uVar17) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] *

                     uVar14) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar6 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                           [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                    uVar23) / 0xff +

                    ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                           [(*(uint *)(lVar2 + 0xc) & uVar17) >> (*(byte *)(lVar2 + 0x1d) & 0x3f)] *

                    uVar22) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar8 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                           [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)]

                    * uVar23) / 0xff +

                    ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                           [(*(uint *)(lVar2 + 0x10) & uVar17) >> (*(byte *)(lVar2 + 0x1e) & 0x3f)]

                    * uVar13) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            *puVar10 = (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(uVar8 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(uVar6 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            iVar21 = iVar19 * 2;

            uVar16 = uVar7;

            if ((int)local_7c < 0) {

              lVar3 = (longlong)(int)uVar11 * 2;

              iVar21 = local_80;

              uVar16 = uVar9;

            }

            local_res18 = local_res18 + uVar16;

            local_7c = local_7c + iVar21;

            puVar10 = (ushort *)(ulonglong)local_7c;

            lVar20 = lVar20 + lVar3;

            local_78 = local_78 - 1;

          } while (local_78 != 0);

        }

        break;

      case 0xf:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar4 = (int)uVar11 < (int)uVar16;

        if (bVar4) {

          local_80 = uVar11 * 2;

          local_7c = local_80 - uVar16;

          iVar19 = uVar11 - uVar16;

        }

        else {

          local_80 = uVar16 * 2;

          local_7c = local_80 - uVar11;

          iVar19 = uVar16 - uVar11;

          uVar16 = uVar11;

        }

        uVar11 = -(uint)!bVar4;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar4;

        }

        uVar9 = -(uint)bVar4;

        if (param_3 <= (int)param_5) {

          uVar9 = (uint)bVar4;

        }

        puVar10 = (ushort *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar10 = (ushort *)0x1;

        }

        uVar7 = (uint)puVar10;

        uVar6 = uVar16 + 1;

        if (param_11 == 0) {

          uVar6 = uVar16;

        }

        if (0 < (int)uVar6) {

          lVar20 = lVar20 * 2;

          lVar18 = -2;

          if (param_2 <= param_4) {

            lVar18 = 2;

          }

          local_78 = (ulonglong)uVar6;

          do {

            puVar10 = (ushort *)

                      ((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                       *(longlong *)(param_1 + 0x18) + lVar20);

            uVar17 = (ulonglong)*puVar10;

            uVar16 = uVar14 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                                     [(*(uint *)(lVar2 + 8) & uVar17) >>

                                      (*(byte *)(lVar2 + 0x1c) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar6 = uVar22 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x19)]

                                    [(*(uint *)(lVar2 + 0xc) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1d) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar8 = uVar13 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                                    [(*(uint *)(lVar2 + 0x10) & uVar17) >>

                                     (*(byte *)(lVar2 + 0x1e) & 0x3f)] * uVar23) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            *puVar10 = (short)(uVar16 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1c) & 0x1f) |

                       (short)(uVar8 >> (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                       (short)(uVar6 >> (8 - *(byte *)(lVar2 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar2 + 0x1d) & 0x1f) | *(ushort *)(lVar2 + 0x14);

            lVar3 = lVar18;

            iVar21 = iVar19 * 2;

            uVar16 = uVar7;

            if ((int)local_7c < 0) {

              lVar3 = (longlong)(int)uVar11 * 2;

              iVar21 = local_80;

              uVar16 = uVar9;

            }

            local_res18 = local_res18 + uVar16;

            local_7c = local_7c + iVar21;

            puVar10 = (ushort *)(ulonglong)local_7c;

            lVar20 = lVar20 + lVar3;

            local_78 = local_78 - 1;

          } while (local_78 != 0);

        }

      }

    }

  }

  return puVar10;

}




