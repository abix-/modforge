// Address: 0x14024fc30
// Ghidra name: FUN_14024fc30
// ============ 0x14024fc30 FUN_14024fc30 (size=10981) ============


uint * FUN_14024fc30(longlong param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                    byte param_7,byte param_8,byte param_9,byte param_10,byte param_11)



{

  uint *puVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  bool bVar5;

  int iVar6;

  uint uVar7;

  uint *puVar8;

  uint uVar9;

  uint *puVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  int iVar17;

  ulonglong uVar18;

  longlong lVar19;

  int iVar20;

  longlong lVar21;

  int iVar22;

  uint uVar23;

  uint uVar24;

  uint *local_res8;

  uint local_res18;

  int local_80;

  uint local_7c;

  ulonglong local_78;

  ulonglong local_70;

  

  lVar3 = *(longlong *)(param_1 + 0x38);

  lVar21 = (longlong)param_2;

  if (param_6 - 1U < 2) {

    uVar12 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar23 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar24 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar12 = (uint)param_7;

    uVar23 = (uint)param_8;

    uVar24 = (uint)param_9;

  }

  uVar11 = param_10 ^ 0xff;

  param_6 = param_6 + -1;

  if (param_3 == param_5) {

    switch(param_6) {

    case 0:

      uVar9 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar9;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar9) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar9 + lVar21) * 4);

      }

      for (; iVar20 != 0; iVar20 = iVar20 + -1) {

        uVar9 = *puVar10;

        puVar8 = (uint *)((ulonglong)

                          ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                                 [(*(uint *)(lVar3 + 0xc) & uVar9) >>

                                  (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) * 0x80808081 &

                         0xffffffff);

        *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                    uVar11) / 0xff + uVar24 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                           [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                    uVar11) / 0xff + uVar12 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                           [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                    uVar11) / 0xff + uVar23 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar11) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar21) * 4);

      }

      for (; iVar20 != 0; iVar20 = iVar20 + -1) {

        uVar11 = *puVar10;

        uVar9 = uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                               [(*(uint *)(lVar3 + 8) & uVar11) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)]

        ;

        if (0xff < uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                  [(*(uint *)(lVar3 + 8) & uVar11) >>

                                   (*(byte *)(lVar3 + 0x1c) & 0x3f)]) {

          uVar9 = 0xff;

        }

        uVar14 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                       [(*(uint *)(lVar3 + 0xc) & uVar11) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                 uVar23;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                         [(*(uint *)(lVar3 + 0xc) & uVar11) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                   uVar23) {

          uVar14 = 0xff;

        }

        uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(*(uint *)(lVar3 + 0x10) & uVar11) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                 uVar24;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                         [(*(uint *)(lVar3 + 0x10) & uVar11) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                   uVar24) {

          uVar13 = 0xff;

        }

        uVar11 = (uVar9 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) << (*(byte *)(lVar3 + 0x1c) & 0x1f)

                 | (uVar13 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                 (uVar14 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar8 = (uint *)(ulonglong)uVar11;

        *puVar10 = uVar11;

        puVar10 = puVar10 + 1;

      }

      break;

    default:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar11) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar21) * 4);

      }

      for (; iVar20 != 0; iVar20 = iVar20 + -1) {

        uVar11 = (uVar23 >> (8U - *(char *)(lVar3 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1d) & 0x1f);

        puVar8 = (uint *)(ulonglong)uVar11;

        *puVar10 = (uVar12 >> (8U - *(char *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                   (uVar24 >> (8U - *(char *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) | uVar11 | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + 1;

      }

      break;

    case 3:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar11) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar21) * 4);

      }

      for (; iVar20 != 0; iVar20 = iVar20 + -1) {

        uVar11 = *puVar10;

        puVar8 = (uint *)((ulonglong)

                          ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                 [(*(uint *)(lVar3 + 0x10) & uVar11) >>

                                  (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar24) * 0x80808081 &

                         0xffffffff);

        *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                           [(*(uint *)(lVar3 + 0xc) & uVar11) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                    uVar23) / 0xff >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                           [(*(uint *)(lVar3 + 8) & uVar11) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                    uVar12) / 0xff >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar11) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                    * uVar24) / 0xff >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + 1;

      }

      break;

    case 7:

      uVar9 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar9;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar9) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar9 + lVar21) * 4);

      }

      while (iVar20 != 0) {

        uVar9 = *puVar10;

        iVar20 = iVar20 + -1;

        uVar14 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                        [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                 uVar11) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                        [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                 uVar12) / 0xff;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                        [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                 uVar11) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                        [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                 uVar23) / 0xff;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                uVar11) / 0xff +

                ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                uVar24) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        uVar9 = (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) << (*(byte *)(lVar3 + 0x1e) & 0x1f)

                | (uVar13 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) << (*(byte *)(lVar3 + 0x1c) & 0x1f)

                | *(uint *)(lVar3 + 0x14);

        puVar8 = (uint *)(ulonglong)uVar9;

        *puVar10 = uVar9;

        puVar10 = puVar10 + 1;

      }

      break;

    case 0xf:

      uVar9 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5)) * param_3;

      puVar8 = (uint *)(ulonglong)uVar9;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar9) * 4);

        puVar8 = (uint *)(ulonglong)param_11;

        puVar10 = puVar1 + 1;

        if (param_11 != 0) {

          puVar10 = puVar1;

        }

        iVar20 = param_2 - param_4;

        if (param_11 != 0) {

          iVar20 = iVar20 + 1;

        }

      }

      else {

        iVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar20 = param_4 - param_2;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar9 + lVar21) * 4);

      }

      for (; iVar20 != 0; iVar20 = iVar20 + -1) {

        uVar9 = *puVar10;

        uVar14 = uVar12 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                 [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)

                                 ] * uVar11) / 0xff;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = uVar23 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                                 [(*(uint *)(lVar3 + 0xc) & uVar9) >>

                                  (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) / 0xff;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar9 = uVar24 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                 (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        uVar9 = (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) << (*(byte *)(lVar3 + 0x1e) & 0x1f);

        puVar8 = (uint *)(ulonglong)uVar9;

        *puVar10 = (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) | uVar9 |

                   (uVar13 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(param_6) {

    case 0:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(iVar20 * param_5 + lVar21);

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        puVar8 = (uint *)(iVar20 * param_3 + lVar21);

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar9 = *puVar10;

        puVar8 = (uint *)((ulonglong)

                          ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                 [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                  (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) * 0x80808081 &

                         0xffffffff);

        *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                           [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                    uVar11) / 0xff + uVar23 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                           [(uVar9 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                    uVar11) / 0xff + uVar12 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                    uVar11) / 0xff + uVar24 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + iVar20;

      }

      break;

    case 1:

    case 0x1f:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(iVar20 * param_5 + lVar21);

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        puVar8 = (uint *)(iVar20 * param_3 + lVar21);

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar11 = *puVar10;

        uVar9 = uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                               [(uVar11 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)]

        ;

        if (0xff < uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                  [(uVar11 & *(uint *)(lVar3 + 8)) >>

                                   (*(byte *)(lVar3 + 0x1c) & 0x3f)]) {

          uVar9 = 0xff;

        }

        uVar14 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                       [(uVar11 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                 uVar23;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                         [(uVar11 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                   uVar23) {

          uVar14 = 0xff;

        }

        uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(uVar11 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                 uVar24;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                         [(uVar11 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                   uVar24) {

          uVar13 = 0xff;

        }

        uVar11 = (uVar9 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) << (*(byte *)(lVar3 + 0x1c) & 0x1f)

                 | (uVar13 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                 (uVar14 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar8 = (uint *)(ulonglong)uVar11;

        *puVar10 = uVar11;

        puVar10 = puVar10 + iVar20;

      }

      break;

    default:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(iVar20 * param_5 + lVar21);

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        puVar8 = (uint *)(iVar20 * param_3 + lVar21);

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar11 = (uVar23 >> (8U - *(char *)(lVar3 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1d) & 0x1f);

        puVar8 = (uint *)(ulonglong)uVar11;

        *puVar10 = (uVar12 >> (8U - *(char *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                   (uVar24 >> (8U - *(char *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) | uVar11 | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + iVar20;

      }

      break;

    case 3:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(iVar20 * param_5 + lVar21);

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

        if (param_11 == 0) {

          puVar10 = puVar10 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        puVar8 = (uint *)(iVar20 * param_3 + lVar21);

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar8 * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar11 = *puVar10;

        puVar8 = (uint *)((ulonglong)

                          ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                 [(uVar11 & *(uint *)(lVar3 + 8)) >>

                                  (*(byte *)(lVar3 + 0x1c) & 0x3f)] * uVar12) * 0x80808081 &

                         0xffffffff);

        *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                           [(uVar11 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                    uVar23) / 0xff >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(uVar11 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                    * uVar24) / 0xff >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                           [(uVar11 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                    uVar12) / 0xff >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar3 + 0x1c) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar10 = puVar10 + iVar20;

      }

      break;

    case 7:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_5 + lVar21) * 4);

        if (param_11 == 0) {

          puVar8 = puVar8 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar9 = *puVar8;

        uVar14 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                        [(uVar9 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                 uVar11) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                        [(uVar9 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                 uVar12) / 0xff;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                        [(uVar9 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                 uVar11) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                        [(uVar9 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                 uVar23) / 0xff;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(uVar9 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                uVar11) / 0xff +

                ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                       [(uVar9 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                uVar24) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        *puVar8 = (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                  (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                  (uVar13 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar8 = puVar8 + iVar20;

      }

      break;

    case 0xf:

      iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

      if (param_5 < param_3) {

        iVar22 = param_3 - param_5;

        puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_5 + lVar21) * 4);

        if (param_11 == 0) {

          puVar8 = puVar8 + iVar20;

        }

        else {

          iVar22 = iVar22 + 1;

        }

      }

      else {

        iVar22 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar22 = param_5 - param_3;

        }

        puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

      }

      for (; iVar22 != 0; iVar22 = iVar22 + -1) {

        uVar9 = *puVar8;

        uVar14 = uVar12 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                 [(uVar9 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)

                                 ] * uVar11) / 0xff;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = uVar23 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                                 [(*(uint *)(lVar3 + 0xc) & uVar9) >>

                                  (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) / 0xff;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar9 = uVar24 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                 (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff;

        if (0xff < uVar9) {

          uVar9 = 0xff;

        }

        *puVar8 = (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                  (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                  (uVar13 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                  (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

        puVar8 = puVar8 + iVar20;

      }

    }

  }

  else {

    uVar14 = param_3 - param_5;

    uVar9 = -(param_2 - param_4);

    if ((int)uVar9 < 0) {

      uVar9 = param_2 - param_4;

    }

    uVar13 = -uVar14;

    if ((int)-uVar14 < 0) {

      uVar13 = uVar14;

    }

    if (uVar9 == uVar13) {

      switch(param_6) {

      case 0:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            puVar8 = (uint *)(longlong)iVar22;

            puVar10 = puVar10 + (longlong)puVar8;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

        }

        uVar9 = uVar14 + 1;

        if (param_11 == 0) {

          uVar9 = uVar14;

        }

        if (uVar9 != 0) {

          do {

            uVar14 = *puVar10;

            puVar8 = (uint *)((ulonglong)

                              ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                     [(*(uint *)(lVar3 + 0x10) & uVar14) >>

                                      (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) * 0x80808081 &

                             0xffffffff);

            *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                               [(*(uint *)(lVar3 + 8) & uVar14) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)]

                        * uVar11) / 0xff + uVar12 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                               [(*(uint *)(lVar3 + 0xc) & uVar14) >>

                                (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) / 0xff + uVar23 >>

                       (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) << (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                               [(*(uint *)(lVar3 + 0x10) & uVar14) >>

                                (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff + uVar24 >>

                       (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) << (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                       *(uint *)(lVar3 + 0x14);

            puVar10 = puVar10 + iVar22;

            uVar9 = uVar9 - 1;

          } while (uVar9 != 0);

        }

        break;

      case 1:

      case 0x1f:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            puVar8 = (uint *)(longlong)iVar22;

            puVar10 = puVar10 + (longlong)puVar8;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

        }

        uVar11 = uVar14 + 1;

        if (param_11 == 0) {

          uVar11 = uVar14;

        }

        if (uVar11 != 0) {

          do {

            uVar9 = *puVar10;

            uVar14 = uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                    [(*(uint *)(lVar3 + 8) & uVar9) >>

                                     (*(byte *)(lVar3 + 0x1c) & 0x3f)];

            if (0xff < uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                      [(*(uint *)(lVar3 + 8) & uVar9) >>

                                       (*(byte *)(lVar3 + 0x1c) & 0x3f)]) {

              uVar14 = 0xff;

            }

            uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                           [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                     uVar23;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                             [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)]

                       + uVar23) {

              uVar13 = 0xff;

            }

            uVar15 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                     uVar24;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                             [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                       + uVar24) {

              uVar15 = 0xff;

            }

            uVar9 = (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                    (*(byte *)(lVar3 + 0x1c) & 0x1f);

            puVar8 = (uint *)(ulonglong)uVar9;

            *puVar10 = (uVar15 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1d) & 0x1f) | uVar9 | *(uint *)(lVar3 + 0x14);

            puVar10 = puVar10 + iVar22;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      default:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            puVar8 = (uint *)(longlong)iVar22;

            puVar10 = puVar10 + (longlong)puVar8;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          puVar8 = (uint *)0xffffffff;

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

        }

        uVar11 = uVar14 + 1;

        if (param_11 == 0) {

          uVar11 = uVar14;

        }

        if (uVar11 != 0) {

          do {

            uVar9 = (uVar23 >> (8U - *(char *)(lVar3 + 0x19) & 0x1f)) <<

                    (*(byte *)(lVar3 + 0x1d) & 0x1f);

            puVar8 = (uint *)(ulonglong)uVar9;

            *puVar10 = (uVar12 >> (8U - *(char *)(lVar3 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                       (uVar24 >> (8U - *(char *)(lVar3 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1e) & 0x1f) | uVar9 | *(uint *)(lVar3 + 0x14);

            puVar10 = puVar10 + iVar22;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      case 3:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            puVar8 = (uint *)(longlong)iVar22;

            puVar10 = puVar10 + (longlong)puVar8;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          puVar8 = (uint *)0xffffffff;

          puVar10 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

        }

        uVar11 = uVar14 + 1;

        if (param_11 == 0) {

          uVar11 = uVar14;

        }

        if (uVar11 != 0) {

          do {

            uVar9 = *puVar10;

            puVar8 = (uint *)((ulonglong)

                              ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                     [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                      (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar24) * 0x80808081 &

                             0xffffffff);

            *puVar10 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                               [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)

                               ] * uVar23) / 0xff >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                               [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)]

                        * uVar12) / 0xff >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                               [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar24) / 0xff >>

                       (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) << (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                       *(uint *)(lVar3 + 0x14);

            puVar10 = puVar10 + iVar22;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      case 7:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar22;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

          iVar22 = iVar22 + iVar20;

        }

        uVar9 = uVar14 + 1;

        if (param_11 == 0) {

          uVar9 = uVar14;

        }

        puVar8 = (uint *)(ulonglong)uVar9;

        if (uVar9 != 0) {

          do {

            uVar9 = *local_res8;

            uVar13 = (int)puVar8 - 1;

            uVar14 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                            [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                     uVar11) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                            [(*(uint *)(lVar3 + 8) & uVar9) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                     uVar12) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar15 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                            [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                     uVar11) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                            [(*(uint *)(lVar3 + 0xc) & uVar9) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] *

                     uVar23) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                    uVar11) / 0xff +

                    ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(*(uint *)(lVar3 + 0x10) & uVar9) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] *

                    uVar24) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            puVar8 = (uint *)(ulonglong)uVar13;

            *local_res8 = (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                          (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                          (uVar15 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            local_res8 = local_res8 + iVar22;

          } while (uVar13 != 0);

          puVar8 = (uint *)0x0;

        }

        break;

      case 0xf:

        iVar20 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar3 + 5);

        if (param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((longlong)(iVar20 * param_5) + (longlong)param_4) * 4);

          iVar22 = 1;

          if (param_2 < param_4) {

            iVar22 = -1;

          }

          iVar22 = iVar22 + iVar20;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar22;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar22 = 1;

          if (param_4 < param_2) {

            iVar22 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar20 * param_3 + lVar21) * 4);

          iVar22 = iVar22 + iVar20;

        }

        uVar9 = uVar14 + 1;

        if (param_11 == 0) {

          uVar9 = uVar14;

        }

        puVar8 = (uint *)(ulonglong)uVar9;

        if (uVar9 != 0) {

          do {

            uVar9 = *local_res8;

            uVar13 = (int)puVar8 - 1;

            uVar14 = uVar12 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                     [(*(uint *)(lVar3 + 8) & uVar9) >>

                                      (*(byte *)(lVar3 + 0x1c) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar15 = uVar23 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                                     [(*(uint *)(lVar3 + 0xc) & uVar9) >>

                                      (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar9 = uVar24 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                    [(*(uint *)(lVar3 + 0x10) & uVar9) >>

                                     (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            *local_res8 = (uVar9 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                          (uVar15 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                          (uVar14 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar3 + 0x1c) & 0x1f) | *(uint *)(lVar3 + 0x14);

            local_res8 = local_res8 + iVar22;

            puVar8 = (uint *)(ulonglong)uVar13;

          } while (uVar13 != 0);

          puVar8 = (uint *)0x0;

        }

      }

    }

    else {

      local_res18 = param_3;

      switch(param_6) {

      case 0:

        uVar9 = -(param_4 - param_2);

        if ((int)uVar9 < 0) {

          uVar9 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar5 = (int)uVar9 < (int)uVar14;

        if (bVar5) {

          local_7c = uVar9 * 2;

          local_res18 = local_7c - uVar14;

          iVar20 = uVar9 - uVar14;

        }

        else {

          local_7c = uVar14 * 2;

          local_res18 = local_7c - uVar9;

          iVar20 = uVar14 - uVar9;

          uVar14 = uVar9;

        }

        uVar9 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar9 = (uint)!bVar5;

        }

        uVar13 = -(uint)bVar5;

        if (param_3 <= param_5) {

          uVar13 = (uint)bVar5;

        }

        puVar8 = (uint *)0xffffffff;

        if (param_3 <= param_5) {

          puVar8 = (uint *)0x1;

        }

        uVar7 = (uint)puVar8;

        uVar15 = uVar14 + 1;

        if (param_11 == 0) {

          uVar15 = uVar14;

        }

        if (0 < (int)uVar15) {

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          local_78 = (ulonglong)uVar15;

          do {

            puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                              *(longlong *)(param_1 + 0x18) + lVar21);

            uVar14 = *puVar8;

            *puVar8 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                              [(*(uint *)(lVar3 + 0xc) & uVar14) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)

                              ] * uVar11) / 0xff + uVar23 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f))

                      << (*(byte *)(lVar3 + 0x1d) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                              [(uVar14 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)]

                       * uVar11) / 0xff + uVar12 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                              [(*(uint *)(lVar3 + 0x10) & uVar14) >>

                               (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff + uVar24 >>

                      (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) << (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                      *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            uVar15 = iVar20 * 2;

            uVar14 = uVar7;

            if ((int)local_res18 < 0) {

              lVar4 = (longlong)(int)uVar9 * 4;

              uVar15 = local_7c;

              uVar14 = uVar13;

            }

            param_3 = param_3 + uVar14;

            local_res18 = local_res18 + uVar15;

            puVar8 = (uint *)(ulonglong)local_res18;

            lVar21 = lVar21 + lVar4;

            local_78 = local_78 - 1;

          } while (local_78 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar9 = -(param_5 - param_3);

        if ((int)uVar9 < 0) {

          uVar9 = param_5 - param_3;

        }

        bVar5 = (int)uVar11 < (int)uVar9;

        if (bVar5) {

          local_80 = uVar11 * 2;

          local_res18 = local_80 - uVar9;

          iVar20 = uVar11 - uVar9;

        }

        else {

          local_80 = uVar9 * 2;

          local_res18 = local_80 - uVar11;

          iVar20 = uVar9 - uVar11;

          uVar9 = uVar11;

        }

        uVar11 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar5;

        }

        uVar14 = -(uint)bVar5;

        if (param_3 <= param_5) {

          uVar14 = (uint)bVar5;

        }

        puVar8 = (uint *)0xffffffff;

        if (param_3 <= param_5) {

          puVar8 = (uint *)0x1;

        }

        uVar15 = (uint)puVar8;

        uVar13 = uVar9 + 1;

        if (param_11 == 0) {

          uVar13 = uVar9;

        }

        if (0 < (int)uVar13) {

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          local_70 = (ulonglong)uVar13;

          do {

            puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                              *(longlong *)(param_1 + 0x18) + lVar21);

            uVar9 = *puVar8;

            uVar13 = uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                    [(uVar9 & *(uint *)(lVar3 + 8)) >>

                                     (*(byte *)(lVar3 + 0x1c) & 0x3f)];

            if (0xff < uVar12 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                      [(uVar9 & *(uint *)(lVar3 + 8)) >>

                                       (*(byte *)(lVar3 + 0x1c) & 0x3f)]) {

              uVar13 = 0xff;

            }

            uVar7 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                          [(uVar9 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)] +

                    uVar23;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                             [(uVar9 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)]

                       + uVar23) {

              uVar7 = 0xff;

            }

            uVar16 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                           [(uVar9 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)] +

                     uVar24;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                             [(uVar9 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                       + uVar24) {

              uVar16 = 0xff;

            }

            *puVar8 = (uVar13 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                      (uVar16 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                      (uVar7 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            iVar22 = iVar20 * 2;

            uVar9 = uVar15;

            if ((int)local_res18 < 0) {

              lVar4 = (longlong)(int)uVar11 * 4;

              iVar22 = local_80;

              uVar9 = uVar14;

            }

            param_3 = param_3 + uVar9;

            local_res18 = local_res18 + iVar22;

            puVar8 = (uint *)(ulonglong)local_res18;

            lVar21 = lVar21 + lVar4;

            local_70 = local_70 - 1;

          } while (local_70 != 0);

        }

        break;

      default:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar9 = -(param_5 - param_3);

        if ((int)uVar9 < 0) {

          uVar9 = param_5 - param_3;

        }

        bVar5 = (int)uVar11 < (int)uVar9;

        if (bVar5) {

          param_6 = uVar11 * 2;

          iVar22 = param_6 - uVar9;

          iVar20 = uVar11 - uVar9;

        }

        else {

          param_6 = uVar9 * 2;

          iVar22 = param_6 - uVar11;

          iVar20 = uVar9 - uVar11;

          uVar9 = uVar11;

        }

        puVar8 = (uint *)(ulonglong)bVar5;

        uVar11 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar5;

        }

        puVar10 = (uint *)(ulonglong)-(uint)bVar5;

        if (param_3 <= param_5) {

          puVar10 = puVar8;

        }

        iVar17 = -1;

        if (param_3 <= param_5) {

          iVar17 = 1;

        }

        uVar14 = uVar9 + 1;

        if (param_11 == 0) {

          uVar14 = uVar9;

        }

        if (0 < (int)uVar14) {

          uVar18 = (ulonglong)uVar14;

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          do {

            uVar9 = param_3 * *(int *)(param_1 + 0x10);

            puVar8 = (uint *)(ulonglong)uVar9;

            *(uint *)((longlong)(int)uVar9 + *(longlong *)(param_1 + 0x18) + lVar21) =

                 (uVar12 >> (8U - *(char *)(lVar3 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                 (uVar24 >> (8U - *(char *)(lVar3 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                 (uVar23 >> (8U - *(char *)(lVar3 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            iVar2 = iVar20 * 2;

            iVar6 = iVar17;

            if (iVar22 < 0) {

              lVar4 = (longlong)(int)uVar11 * 4;

              iVar2 = param_6;

              iVar6 = (int)puVar10;

            }

            param_3 = param_3 + iVar6;

            iVar22 = iVar22 + iVar2;

            lVar21 = lVar21 + lVar4;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

        break;

      case 3:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar9 = -(param_5 - param_3);

        if ((int)uVar9 < 0) {

          uVar9 = param_5 - param_3;

        }

        bVar5 = (int)uVar11 < (int)uVar9;

        if (bVar5) {

          local_80 = uVar11 * 2;

          local_res18 = local_80 - uVar9;

          iVar20 = uVar11 - uVar9;

        }

        else {

          local_80 = uVar9 * 2;

          local_res18 = local_80 - uVar11;

          iVar20 = uVar9 - uVar11;

          uVar9 = uVar11;

        }

        uVar11 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar5;

        }

        uVar14 = -(uint)bVar5;

        if (param_3 <= param_5) {

          uVar14 = (uint)bVar5;

        }

        puVar8 = (uint *)0xffffffff;

        if (param_3 <= param_5) {

          puVar8 = (uint *)0x1;

        }

        uVar15 = (uint)puVar8;

        uVar13 = uVar9 + 1;

        if (param_11 == 0) {

          uVar13 = uVar9;

        }

        if (0 < (int)uVar13) {

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          local_70 = (ulonglong)uVar13;

          do {

            puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                              *(longlong *)(param_1 + 0x18) + lVar21);

            uVar9 = *puVar8;

            *puVar8 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                              [(uVar9 & *(uint *)(lVar3 + 0x10)) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)

                              ] * uVar24) / 0xff >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                              [(uVar9 & *(uint *)(lVar3 + 8)) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                       uVar12) / 0xff >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                              [(uVar9 & *(uint *)(lVar3 + 0xc)) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)]

                       * uVar23) / 0xff >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            iVar22 = iVar20 * 2;

            uVar9 = uVar15;

            if ((int)local_res18 < 0) {

              lVar4 = (longlong)(int)uVar11 * 4;

              iVar22 = local_80;

              uVar9 = uVar14;

            }

            param_3 = param_3 + uVar9;

            local_res18 = local_res18 + iVar22;

            puVar8 = (uint *)(ulonglong)local_res18;

            lVar21 = lVar21 + lVar4;

            local_70 = local_70 - 1;

          } while (local_70 != 0);

        }

        break;

      case 7:

        uVar9 = -(param_4 - param_2);

        if ((int)uVar9 < 0) {

          uVar9 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar5 = (int)uVar9 < (int)uVar14;

        if (bVar5) {

          local_80 = uVar9 * 2;

          local_7c = local_80 - uVar14;

          iVar20 = uVar9 - uVar14;

        }

        else {

          local_80 = uVar14 * 2;

          local_7c = local_80 - uVar9;

          iVar20 = uVar14 - uVar9;

          uVar14 = uVar9;

        }

        uVar9 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar9 = (uint)!bVar5;

        }

        uVar13 = -(uint)bVar5;

        if (param_3 <= param_5) {

          uVar13 = (uint)bVar5;

        }

        puVar8 = (uint *)0xffffffff;

        if (param_3 <= param_5) {

          puVar8 = (uint *)0x1;

        }

        uVar7 = (uint)puVar8;

        uVar15 = uVar14 + 1;

        if (param_11 == 0) {

          uVar15 = uVar14;

        }

        if (0 < (int)uVar15) {

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          local_70 = (ulonglong)uVar15;

          do {

            puVar8 = (uint *)((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                              *(longlong *)(param_1 + 0x18) + lVar21);

            uVar14 = *puVar8;

            uVar15 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                            [(*(uint *)(lVar3 + 8) & uVar14) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                     uVar11) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                            [(*(uint *)(lVar3 + 8) & uVar14) >> (*(byte *)(lVar3 + 0x1c) & 0x3f)] *

                     uVar12) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar16 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                            [(*(uint *)(lVar3 + 0xc) & uVar14) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)]

                     * uVar11) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                            [(*(uint *)(lVar3 + 0xc) & uVar14) >> (*(byte *)(lVar3 + 0x1d) & 0x3f)]

                     * uVar23) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar14 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                            [(*(uint *)(lVar3 + 0x10) & uVar14) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                     * uVar11) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                            [(*(uint *)(lVar3 + 0x10) & uVar14) >> (*(byte *)(lVar3 + 0x1e) & 0x3f)]

                     * uVar24) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            *puVar8 = (uVar15 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                      (uVar14 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                      (uVar16 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            iVar22 = iVar20 * 2;

            uVar14 = uVar7;

            if ((int)local_7c < 0) {

              lVar4 = (longlong)(int)uVar9 * 4;

              iVar22 = local_80;

              uVar14 = uVar13;

            }

            local_res18 = local_res18 + uVar14;

            local_7c = local_7c + iVar22;

            puVar8 = (uint *)(ulonglong)local_7c;

            lVar21 = lVar21 + lVar4;

            local_70 = local_70 - 1;

          } while (local_70 != 0);

        }

        break;

      case 0xf:

        uVar9 = -(param_4 - param_2);

        if ((int)uVar9 < 0) {

          uVar9 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar5 = (int)uVar9 < (int)uVar14;

        if (bVar5) {

          local_80 = uVar9 * 2;

          local_7c = local_80 - uVar14;

          iVar20 = uVar9 - uVar14;

        }

        else {

          local_80 = uVar14 * 2;

          local_7c = local_80 - uVar9;

          iVar20 = uVar14 - uVar9;

          uVar14 = uVar9;

        }

        uVar9 = -(uint)!bVar5;

        if (param_2 <= param_4) {

          uVar9 = (uint)!bVar5;

        }

        uVar13 = -(uint)bVar5;

        if (param_3 <= param_5) {

          uVar13 = (uint)bVar5;

        }

        puVar8 = (uint *)0xffffffff;

        if (param_3 <= param_5) {

          puVar8 = (uint *)0x1;

        }

        uVar7 = (uint)puVar8;

        uVar15 = uVar14 + 1;

        if (param_11 == 0) {

          uVar15 = uVar14;

        }

        if (0 < (int)uVar15) {

          lVar21 = lVar21 * 4;

          lVar19 = -4;

          if (param_2 <= param_4) {

            lVar19 = 4;

          }

          local_70 = (ulonglong)uVar15;

          do {

            puVar8 = (uint *)((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                              *(longlong *)(param_1 + 0x18) + lVar21);

            uVar14 = *puVar8;

            uVar15 = uVar12 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x18)]

                                     [(uVar14 & *(uint *)(lVar3 + 8)) >>

                                      (*(byte *)(lVar3 + 0x1c) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar16 = uVar23 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x19)]

                                     [(*(uint *)(lVar3 + 0xc) & uVar14) >>

                                      (*(byte *)(lVar3 + 0x1d) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar14 = uVar24 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar3 + 0x1a)]

                                     [(*(uint *)(lVar3 + 0x10) & uVar14) >>

                                      (*(byte *)(lVar3 + 0x1e) & 0x3f)] * uVar11) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            *puVar8 = (uVar15 >> (8 - *(byte *)(lVar3 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1c) & 0x1f) |

                      (uVar14 >> (8 - *(byte *)(lVar3 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1e) & 0x1f) |

                      (uVar16 >> (8 - *(byte *)(lVar3 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar3 + 0x1d) & 0x1f) | *(uint *)(lVar3 + 0x14);

            lVar4 = lVar19;

            iVar22 = iVar20 * 2;

            uVar14 = uVar7;

            if ((int)local_7c < 0) {

              lVar4 = (longlong)(int)uVar9 * 4;

              iVar22 = local_80;

              uVar14 = uVar13;

            }

            local_res18 = local_res18 + uVar14;

            local_7c = local_7c + iVar22;

            puVar8 = (uint *)(ulonglong)local_7c;

            lVar21 = lVar21 + lVar4;

            local_70 = local_70 - 1;

          } while (local_70 != 0);

        }

      }

    }

  }

  return puVar8;

}




