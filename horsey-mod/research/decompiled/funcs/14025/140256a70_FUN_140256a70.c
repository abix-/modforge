// Address: 0x140256a70
// Ghidra name: FUN_140256a70
// ============ 0x140256a70 FUN_140256a70 (size=13679) ============


uint * FUN_140256a70(longlong param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,

                    byte param_7,byte param_8,byte param_9,byte param_10,byte param_11)



{

  uint *puVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  longlong lVar5;

  longlong lVar6;

  bool bVar7;

  byte bVar8;

  uint uVar9;

  uint uVar10;

  uint *puVar11;

  byte bVar12;

  byte bVar13;

  uint uVar14;

  uint *puVar15;

  longlong lVar16;

  uint uVar17;

  int iVar18;

  uint uVar19;

  uint uVar20;

  int iVar21;

  uint uVar22;

  longlong lVar23;

  ulonglong uVar24;

  uint uVar25;

  uint uVar26;

  int iVar27;

  uint uVar28;

  uint uVar29;

  uint *local_res8;

  uint local_res18;

  byte local_b8;

  byte local_b7;

  byte local_b6;

  byte local_b5;

  byte local_b4;

  byte local_b3;

  byte local_b2;

  uint local_b0;

  uint local_a0;

  ulonglong local_98;

  int local_90;

  uint *local_88;

  byte local_78;

  byte local_70;

  ulonglong local_60;

  byte local_50;

  byte local_48;

  

  iVar21 = param_5;

  lVar5 = *(longlong *)(param_1 + 0x38);

  lVar16 = (longlong)param_4;

  lVar23 = (longlong)param_2;

  if (param_6 - 1U < 2) {

    uVar29 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar26 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar17 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar29 = (uint)param_7;

    uVar26 = (uint)param_8;

    uVar17 = (uint)param_9;

  }

  uVar28 = param_10 ^ 0xff;

  param_6 = param_6 + -1;

  if (param_3 == param_5) {

    switch(param_6) {

    case 0:

      uVar14 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar14;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar23) * 4);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar14 = *puVar15;

        puVar11 = (uint *)((ulonglong)

                           ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                  [(*(uint *)(lVar5 + 0x10) & uVar14) >>

                                   (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar28) * 0x80808081 &

                          0xffffffff);

        *puVar15 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                           [(*(uint *)(lVar5 + 0x14) & uVar14) >> (*(byte *)(lVar5 + 0x1f) & 0x3f)]

                    * uVar28) / 0xff + (uint)param_10 >> (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                           [(*(uint *)(lVar5 + 8) & uVar14) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                    uVar28) / 0xff + uVar29 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(*(uint *)(lVar5 + 0xc) & uVar14) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                    uVar28) / 0xff + uVar26 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar28) / 0xff + uVar17 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f);

        puVar15 = puVar15 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar28 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar28;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar23) * 4);

      }

      while (iVar21 != 0) {

        uVar28 = *puVar15;

        iVar21 = iVar21 + -1;

        uVar14 = uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                [(uVar28 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)

                                ];

        if (0xff < uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                  [(uVar28 & *(uint *)(lVar5 + 8)) >>

                                   (*(byte *)(lVar5 + 0x1c) & 0x3f)]) {

          uVar14 = 0xff;

        }

        uVar19 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                       [(*(uint *)(lVar5 + 0xc) & uVar28) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                 uVar26;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                         [(*(uint *)(lVar5 + 0xc) & uVar28) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                   uVar26) {

          uVar19 = 0xff;

        }

        uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                       [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] +

                 uVar17;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                         [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] +

                   uVar17) {

          uVar10 = 0xff;

        }

        uVar28 = (uVar14 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                 (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                              [(*(uint *)(lVar5 + 0x14) & uVar28) >>

                               (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                       (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                 (uVar10 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                 (uVar19 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1d) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar28;

        *puVar15 = uVar28;

        puVar15 = puVar15 + 1;

      }

      break;

    case 2:

    case 4:

    case 5:

    case 6:

    case 8:

    case 9:

    case 10:

    case 0xb:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x10:

    case 0x11:

    case 0x12:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x16:

    case 0x17:

    case 0x18:

    case 0x19:

    case 0x1a:

    case 0x1b:

    case 0x1c:

    case 0x1d:

    case 0x1e:

    default:

      uVar28 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar28;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar23) * 4);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar28 = (uVar29 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar28;

        *puVar15 = (uVar26 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (uint)(param_10 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (uVar17 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) | uVar28;

        puVar15 = puVar15 + 1;

      }

      break;

    case 3:

      uVar28 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar28;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar28 + lVar23) * 4);

      }

      for (; iVar21 != 0; iVar21 = iVar21 + -1) {

        uVar28 = *puVar15;

        puVar11 = (uint *)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)];

        *puVar15 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar17) / 0xff >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(*(uint *)(lVar5 + 0xc) & uVar28) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                    uVar26) / 0xff >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                           [(uVar28 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                    uVar29) / 0xff >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                   (uint)(*(byte *)((ulonglong)

                                    ((*(uint *)(lVar5 + 0x14) & uVar28) >>

                                    (*(byte *)(lVar5 + 0x1f) & 0x3f)) + (longlong)puVar11) >>

                         (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f);

        puVar15 = puVar15 + 1;

      }

      break;

    case 7:

      uVar14 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar14;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar23) * 4);

      }

      while (iVar21 != 0) {

        uVar14 = *puVar15;

        iVar21 = iVar21 + -1;

        uVar19 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                        [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                        [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                 uVar29) / 0xff;

        if (0xff < uVar19) {

          uVar19 = 0xff;

        }

        uVar10 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                        [(uVar14 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                        [(uVar14 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                 uVar26) / 0xff;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                        [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                        [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] *

                 uVar17) / 0xff;

        if (0xff < uVar25) {

          uVar25 = 0xff;

        }

        uVar14 = (uVar25 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                 (uVar10 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                 (uVar19 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                 (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                              [(*(uint *)(lVar5 + 0x14) & uVar14) >>

                               (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                       (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar14;

        *puVar15 = uVar14;

        puVar15 = puVar15 + 1;

      }

      break;

    case 0xf:

      uVar14 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5)) * param_3;

      puVar11 = (uint *)(ulonglong)uVar14;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar16) * 4);

        puVar11 = (uint *)(ulonglong)param_11;

        puVar15 = puVar1 + 1;

        if (param_11 != 0) {

          puVar15 = puVar1;

        }

        iVar21 = param_2 - param_4;

        if (param_11 != 0) {

          iVar21 = iVar21 + 1;

        }

      }

      else {

        iVar21 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar21 = param_4 - param_2;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar23) * 4);

      }

      while (iVar21 != 0) {

        uVar14 = *puVar15;

        iVar21 = iVar21 + -1;

        uVar19 = uVar29 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                 [(*(uint *)(lVar5 + 8) & uVar14) >>

                                  (*(byte *)(lVar5 + 0x1c) & 0x3f)] * uVar28) / 0xff;

        if (0xff < uVar19) {

          uVar19 = 0xff;

        }

        uVar10 = uVar26 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                 [(*(uint *)(lVar5 + 0xc) & uVar14) >>

                                  (*(byte *)(lVar5 + 0x1d) & 0x3f)] * uVar28) / 0xff;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar25 = uVar17 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                 [(*(uint *)(lVar5 + 0x10) & uVar14) >>

                                  (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar28) / 0xff;

        if (0xff < uVar25) {

          uVar25 = 0xff;

        }

        uVar14 = (uint)param_10 +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                        [(*(uint *)(lVar5 + 0x14) & uVar14) >> (*(byte *)(lVar5 + 0x1f) & 0x3f)] *

                 uVar28) / 0xff;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar14 = (uVar14 >> (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1f) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar14;

        *puVar15 = (uVar25 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (uVar10 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (uVar19 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f) | uVar14;

        puVar15 = puVar15 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(param_6) {

    case 0:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar23) * 4);

        if (param_11 == 0) {

          puVar11 = puVar11 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

      }

      for (; iVar27 != 0; iVar27 = iVar27 + -1) {

        uVar14 = *puVar11;

        *puVar11 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar28) / 0xff + uVar17 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(uVar14 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                    uVar28) / 0xff + uVar26 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                           [(*(uint *)(lVar5 + 0x14) & uVar14) >> (*(byte *)(lVar5 + 0x1f) & 0x3f)]

                    * uVar28) / 0xff + (uint)param_10 >> (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                           [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                    uVar28) / 0xff + uVar29 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f);

        puVar11 = puVar11 + iVar21;

      }

      break;

    case 1:

    case 0x1f:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)((int)(iVar21 * param_5) + lVar23);

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar11 * 4);

        if (param_11 == 0) {

          puVar15 = puVar15 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        puVar11 = (uint *)(iVar21 * param_3 + lVar23);

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar11 * 4);

      }

      while (iVar27 != 0) {

        uVar28 = *puVar15;

        iVar27 = iVar27 + -1;

        uVar14 = uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                [(uVar28 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)

                                ];

        if (0xff < uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                  [(uVar28 & *(uint *)(lVar5 + 8)) >>

                                   (*(byte *)(lVar5 + 0x1c) & 0x3f)]) {

          uVar14 = 0xff;

        }

        uVar19 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                       [(uVar28 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                 uVar26;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                         [(uVar28 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                   uVar26) {

          uVar19 = 0xff;

        }

        uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                       [(uVar28 & *(uint *)(lVar5 + 0x10)) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] +

                 uVar17;

        if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                         [(uVar28 & *(uint *)(lVar5 + 0x10)) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] +

                   uVar17) {

          uVar10 = 0xff;

        }

        uVar28 = (uVar14 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                 (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                              [(uVar28 & *(uint *)(lVar5 + 0x14)) >>

                               (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                       (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                 (uVar10 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                 (uVar19 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1d) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar28;

        *puVar15 = uVar28;

        puVar15 = puVar15 + iVar21;

      }

      break;

    case 2:

    case 4:

    case 5:

    case 6:

    case 8:

    case 9:

    case 10:

    case 0xb:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x10:

    case 0x11:

    case 0x12:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x16:

    case 0x17:

    case 0x18:

    case 0x19:

    case 0x1a:

    case 0x1b:

    case 0x1c:

    case 0x1d:

    case 0x1e:

    default:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)((int)(iVar21 * param_5) + lVar23);

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar11 * 4);

        if (param_11 == 0) {

          puVar15 = puVar15 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        puVar11 = (uint *)(iVar21 * param_3 + lVar23);

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + (longlong)puVar11 * 4);

      }

      for (; iVar27 != 0; iVar27 = iVar27 + -1) {

        uVar28 = (uVar29 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f);

        puVar11 = (uint *)(ulonglong)uVar28;

        *puVar15 = (uVar26 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (uint)(param_10 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (uVar17 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) | uVar28;

        puVar15 = puVar15 + iVar21;

      }

      break;

    case 3:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar23) * 4);

        if (param_11 == 0) {

          puVar11 = puVar11 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

      }

      for (; iVar27 != 0; iVar27 = iVar27 + -1) {

        uVar28 = *puVar11;

        *puVar11 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar17) / 0xff >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(*(uint *)(lVar5 + 0xc) & uVar28) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                    uVar26) / 0xff >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                           [(*(uint *)(lVar5 + 8) & uVar28) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                    uVar29) / 0xff >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                   (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                [(*(uint *)(lVar5 + 0x14) & uVar28) >>

                                 (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                         (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f);

        puVar11 = puVar11 + iVar21;

      }

      break;

    case 7:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar23) * 4);

        if (param_11 == 0) {

          puVar11 = puVar11 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

      }

      while (iVar27 != 0) {

        uVar14 = *puVar11;

        iVar27 = iVar27 + -1;

        uVar19 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                        [(*(uint *)(lVar5 + 8) & uVar14) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                        [(*(uint *)(lVar5 + 8) & uVar14) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                 uVar29) / 0xff;

        if (0xff < uVar19) {

          uVar19 = 0xff;

        }

        uVar10 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                        [(*(uint *)(lVar5 + 0xc) & uVar14) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                        [(*(uint *)(lVar5 + 0xc) & uVar14) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                 uVar26) / 0xff;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                        [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] *

                 uVar28) / 0xff +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                        [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] *

                 uVar17) / 0xff;

        if (0xff < uVar25) {

          uVar25 = 0xff;

        }

        *puVar11 = (uVar19 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                   (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                [(*(uint *)(lVar5 + 0x14) & uVar14) >>

                                 (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                         (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (uVar25 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (uVar10 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f);

        puVar11 = puVar11 + iVar21;

      }

      break;

    case 0xf:

      iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

      if ((int)param_5 < param_3) {

        iVar27 = param_3 - param_5;

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar23) * 4);

        if (param_11 == 0) {

          puVar11 = puVar11 + iVar21;

        }

        else {

          iVar27 = iVar27 + 1;

        }

      }

      else {

        iVar27 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar27 = param_5 - param_3;

        }

        puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

      }

      while (iVar27 != 0) {

        uVar19 = *puVar11;

        iVar27 = iVar27 + -1;

        bVar2 = *(byte *)(lVar5 + 0x1f);

        bVar12 = *(byte *)(lVar5 + 0x18);

        bVar3 = *(byte *)(lVar5 + 0x1c);

        local_b7 = *(byte *)(lVar5 + 0x1f);

        uVar14 = ((byte)(&PTR_DAT_1403e28a0)[bVar12]

                        [(uVar19 & *(uint *)(lVar5 + 8)) >> (bVar3 & 0x3f)] * uVar28) / 0xff +

                 uVar29;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar10 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                        [(uVar19 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] *

                 uVar28) / 0xff + uVar26;

        local_b5 = *(byte *)(lVar5 + 0x1c);

        local_b4 = *(byte *)(lVar5 + 0x18);

        if (uVar10 < 0x100) {

          bVar12 = *(byte *)(lVar5 + 0x18);

        }

        else {

          uVar10 = 0xff;

          local_b7 = bVar2;

          local_b5 = bVar3;

          local_b4 = bVar12;

        }

        uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                        [(uVar19 & *(uint *)(lVar5 + 0x10)) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)] *

                 uVar28) / 0xff + uVar17;

        local_b3 = *(byte *)(lVar5 + 0x1e);

        local_b2 = *(byte *)(lVar5 + 0x1d);

        bVar4 = bVar2;

        local_78 = *(byte *)(lVar5 + 0x1b);

        local_70 = *(byte *)(lVar5 + 0x1a);

        if (0xff < uVar25) {

          uVar25 = 0xff;

          local_b3 = *(byte *)(lVar5 + 0x1e);

          local_b2 = *(byte *)(lVar5 + 0x1d);

          bVar4 = local_b7;

          bVar3 = local_b5;

          bVar12 = local_b4;

          local_78 = *(byte *)(lVar5 + 0x1b);

          local_70 = *(byte *)(lVar5 + 0x1a);

        }

        uVar19 = (uint)param_10 +

                 ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                        [(uVar19 & *(uint *)(lVar5 + 0x14)) >> (bVar2 & 0x3f)] * uVar28) / 0xff;

        if (0xff < uVar19) {

          uVar19 = 0xff;

        }

        *puVar11 = (uVar14 >> (8 - bVar12 & 0x1f)) << (bVar3 & 0x1f) |

                   (uVar19 >> (8 - local_78 & 0x1f)) << (bVar4 & 0x1f) |

                   (uVar25 >> (8 - local_70 & 0x1f)) << (local_b3 & 0x1f) |

                   (uVar10 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (local_b2 & 0x1f);

        puVar11 = puVar11 + iVar21;

      }

    }

  }

  else {

    uVar19 = param_3 - param_5;

    uVar14 = -(param_2 - param_4);

    if ((int)uVar14 < 0) {

      uVar14 = param_2 - param_4;

    }

    uVar10 = -uVar19;

    if ((int)-uVar19 < 0) {

      uVar10 = uVar19;

    }

    if (uVar14 == uVar10) {

      switch(param_6) {

      case 0:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((int)(iVar21 * param_5) + lVar16) * 4);

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar27;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = iVar27 + iVar21;

        }

        uVar14 = uVar19 + 1;

        if (param_11 == 0) {

          uVar14 = uVar19;

        }

        puVar11 = (uint *)(ulonglong)uVar14;

        if (uVar14 != 0) {

          do {

            uVar14 = *local_res8;

            uVar19 = (int)puVar11 - 1;

            *local_res8 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                  [(*(uint *)(lVar5 + 0x14) & uVar14) >>

                                   (*(byte *)(lVar5 + 0x1f) & 0x3f)] * uVar28) / 0xff +

                           (uint)param_10 >> (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                          (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                  [(*(uint *)(lVar5 + 0xc) & uVar14) >>

                                   (*(byte *)(lVar5 + 0x1d) & 0x3f)] * uVar28) / 0xff + uVar26 >>

                          (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (*(byte *)(lVar5 + 0x1d) & 0x1f)

                          | (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                    [(*(uint *)(lVar5 + 0x10) & uVar14) >>

                                     (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar28) / 0xff + uVar17 >>

                            (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                            (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                          (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                  [(uVar14 & *(uint *)(lVar5 + 8)) >>

                                   (*(byte *)(lVar5 + 0x1c) & 0x3f)] * uVar28) / 0xff + uVar29 >>

                          (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) << (*(byte *)(lVar5 + 0x1c) & 0x1f);

            local_res8 = local_res8 + iVar27;

            puVar11 = (uint *)(ulonglong)uVar19;

          } while (uVar19 != 0);

          puVar11 = (uint *)0x0;

        }

        break;

      case 1:

      case 0x1f:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((int)(iVar21 * param_5) + lVar16) * 4);

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar27;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = iVar27 + iVar21;

        }

        uVar28 = uVar19 + 1;

        if (param_11 == 0) {

          uVar28 = uVar19;

        }

        puVar11 = (uint *)(ulonglong)uVar28;

        if (uVar28 != 0) {

          do {

            uVar28 = *local_res8;

            uVar19 = (int)puVar11 - 1;

            uVar14 = uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                    [(uVar28 & *(uint *)(lVar5 + 8)) >>

                                     (*(byte *)(lVar5 + 0x1c) & 0x3f)];

            if (0xff < uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                      [(uVar28 & *(uint *)(lVar5 + 8)) >>

                                       (*(byte *)(lVar5 + 0x1c) & 0x3f)]) {

              uVar14 = 0xff;

            }

            uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(uVar28 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                     uVar26;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                             [(uVar28 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                       + uVar26) {

              uVar10 = 0xff;

            }

            uVar25 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                     + uVar17;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                             [(*(uint *)(lVar5 + 0x10) & uVar28) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)

                             ] + uVar17) {

              uVar25 = 0xff;

            }

            *local_res8 = (uVar14 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                          (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                       [(*(uint *)(lVar5 + 0x14) & uVar28) >>

                                        (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                                (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                          (uVar25 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                          (uVar10 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1d) & 0x1f);

            local_res8 = local_res8 + iVar27;

            puVar11 = (uint *)(ulonglong)uVar19;

          } while (uVar19 != 0);

          puVar11 = (uint *)0x0;

        }

        break;

      case 2:

      case 4:

      case 5:

      case 6:

      case 8:

      case 9:

      case 10:

      case 0xb:

      case 0xc:

      case 0xd:

      case 0xe:

      case 0x10:

      case 0x11:

      case 0x12:

      case 0x13:

      case 0x14:

      case 0x15:

      case 0x16:

      case 0x17:

      case 0x18:

      case 0x19:

      case 0x1a:

      case 0x1b:

      case 0x1c:

      case 0x1d:

      case 0x1e:

      default:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          puVar11 = (uint *)0xffffffff;

          puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar16) * 4)

          ;

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            puVar11 = (uint *)(longlong)iVar27;

            puVar15 = puVar15 + (longlong)puVar11;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          puVar11 = (uint *)0xffffffff;

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          puVar15 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = iVar27 + iVar21;

        }

        uVar28 = uVar19 + 1;

        if (param_11 == 0) {

          uVar28 = uVar19;

        }

        if (uVar28 != 0) {

          do {

            uVar14 = (uVar29 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar5 + 0x1c) & 0x1f);

            puVar11 = (uint *)(ulonglong)uVar14;

            *puVar15 = (uVar26 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                       (uint)(param_10 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                       (uVar17 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1e) & 0x1f) | uVar14;

            puVar15 = puVar15 + iVar27;

            uVar28 = uVar28 - 1;

          } while (uVar28 != 0);

        }

        break;

      case 3:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((int)(iVar21 * param_5) + lVar16) * 4);

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar27;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = iVar27 + iVar21;

        }

        uVar28 = uVar19 + 1;

        if (param_11 == 0) {

          uVar28 = uVar19;

        }

        puVar11 = (uint *)(ulonglong)uVar28;

        if (uVar28 != 0) {

          do {

            uVar28 = *local_res8;

            uVar14 = (int)puVar11 - 1;

            puVar11 = (uint *)(ulonglong)uVar14;

            *local_res8 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                  [(uVar28 & *(uint *)(lVar5 + 8)) >>

                                   (*(byte *)(lVar5 + 0x1c) & 0x3f)] * uVar29) / 0xff >>

                          (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) << (*(byte *)(lVar5 + 0x1c) & 0x1f)

                          | (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                    [(*(uint *)(lVar5 + 0x10) & uVar28) >>

                                     (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar17) / 0xff >>

                            (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                            (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                          (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                  [(uVar28 & *(uint *)(lVar5 + 0xc)) >>

                                   (*(byte *)(lVar5 + 0x1d) & 0x3f)] * uVar26) / 0xff >>

                          (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (*(byte *)(lVar5 + 0x1d) & 0x1f)

                          | (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                         [(*(uint *)(lVar5 + 0x14) & uVar28) >>

                                          (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                                  (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                            (*(byte *)(lVar5 + 0x1f) & 0x1f);

            local_res8 = local_res8 + iVar27;

          } while (uVar14 != 0);

          puVar11 = (uint *)0x0;

        }

        break;

      case 7:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                               ((int)(iVar21 * param_5) + lVar16) * 4);

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            local_res8 = local_res8 + iVar27;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          local_res8 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = iVar27 + iVar21;

        }

        uVar14 = uVar19 + 1;

        if (param_11 == 0) {

          uVar14 = uVar19;

        }

        puVar11 = (uint *)(ulonglong)uVar14;

        if (uVar14 != 0) {

          do {

            uVar14 = *local_res8;

            uVar10 = (int)puVar11 - 1;

            uVar19 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                            [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                     uVar28) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                            [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                     uVar29) / 0xff;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                            [(uVar14 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                     * uVar28) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                            [(uVar14 & *(uint *)(lVar5 + 0xc)) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                     * uVar26) / 0xff;

            if (0xff < uVar25) {

              uVar25 = 0xff;

            }

            uVar20 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                            [(uVar14 & *(uint *)(lVar5 + 0x10)) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                     * uVar28) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                            [(uVar14 & *(uint *)(lVar5 + 0x10)) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                     * uVar17) / 0xff;

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            puVar11 = (uint *)(ulonglong)uVar10;

            *local_res8 = (uVar19 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                          (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                       [(uVar14 & *(uint *)(lVar5 + 0x14)) >>

                                        (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                                (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                          (uVar20 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                          (uVar25 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                          (*(byte *)(lVar5 + 0x1d) & 0x1f);

            local_res8 = local_res8 + iVar27;

          } while (uVar10 != 0);

          puVar11 = (uint *)0x0;

        }

        break;

      case 0xf:

        iVar21 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(lVar5 + 5);

        if ((int)param_5 < param_3) {

          local_88 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)(iVar21 * param_5) + lVar16) * 4

                             );

          iVar27 = 1;

          if (param_2 < param_4) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

          if (param_11 == 0) {

            local_88 = local_88 + iVar27;

          }

        }

        else {

          uVar19 = param_5 - param_3;

          local_88 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar21 * param_3 + lVar23) * 4);

          iVar27 = 1;

          if (param_4 < param_2) {

            iVar27 = -1;

          }

          iVar27 = iVar27 + iVar21;

        }

        uVar14 = uVar19 + 1;

        if (param_11 == 0) {

          uVar14 = uVar19;

        }

        puVar11 = (uint *)(ulonglong)uVar14;

        if (uVar14 != 0) {

          do {

            uVar19 = *local_88;

            uVar10 = (int)puVar11 - 1;

            bVar2 = *(byte *)(lVar5 + 0x1c);

            uVar14 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                            [(uVar19 & *(uint *)(lVar5 + 8)) >> (bVar2 & 0x3f)] * uVar28) / 0xff +

                     uVar29;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                            [(*(uint *)(lVar5 + 0xc) & uVar19) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                     * uVar28) / 0xff + uVar26;

            local_b4 = *(byte *)(lVar5 + 0x1c);

            if (0xff < uVar25) {

              uVar25 = 0xff;

              local_b4 = bVar2;

            }

            uVar20 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                            [(*(uint *)(lVar5 + 0x10) & uVar19) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                     * uVar28) / 0xff + uVar17;

            local_b8 = *(byte *)(lVar5 + 0x1d);

            local_b7 = *(byte *)(lVar5 + 0x1e);

            local_b6 = *(byte *)(lVar5 + 0x1f);

            local_78 = *(byte *)(lVar5 + 0x1b);

            if (0xff < uVar20) {

              uVar20 = 0xff;

              local_b8 = *(byte *)(lVar5 + 0x1d);

              local_b7 = *(byte *)(lVar5 + 0x1e);

              local_b6 = *(byte *)(lVar5 + 0x1f);

              bVar2 = local_b4;

              local_78 = *(byte *)(lVar5 + 0x1b);

            }

            uVar19 = (uint)param_10 +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                            [(*(uint *)(lVar5 + 0x14) & uVar19) >> (*(byte *)(lVar5 + 0x1f) & 0x3f)]

                     * uVar28) / 0xff;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            puVar11 = (uint *)(ulonglong)uVar10;

            *local_88 = (uVar14 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) << (bVar2 & 0x1f) |

                        (uVar19 >> (8 - local_78 & 0x1f)) << (local_b6 & 0x1f) |

                        (uVar20 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) << (local_b7 & 0x1f) |

                        (uVar25 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (local_b8 & 0x1f);

            local_88 = local_88 + iVar27;

          } while (uVar10 != 0);

          puVar11 = (uint *)0x0;

        }

      }

    }

    else {

      local_res18 = param_3;

      switch(param_6) {

      case 0:

        uVar14 = -(param_4 - param_2);

        if ((int)uVar14 < 0) {

          uVar14 = param_4 - param_2;

        }

        uVar19 = -(param_5 - param_3);

        if ((int)uVar19 < 0) {

          uVar19 = param_5 - param_3;

        }

        bVar7 = (int)uVar14 < (int)uVar19;

        if (bVar7) {

          local_a0 = uVar14 * 2;

          local_b0 = local_a0 - uVar19;

          iVar21 = uVar14 - uVar19;

        }

        else {

          local_a0 = uVar19 * 2;

          local_b0 = local_a0 - uVar14;

          iVar21 = uVar19 - uVar14;

          uVar19 = uVar14;

        }

        uVar14 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar14 = (uint)!bVar7;

        }

        uVar10 = -(uint)bVar7;

        if (param_3 <= (int)param_5) {

          uVar10 = (uint)bVar7;

        }

        puVar11 = (uint *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar11 = (uint *)0x1;

        }

        uVar20 = (uint)puVar11;

        uVar25 = uVar19 + 1;

        if (param_11 == 0) {

          uVar25 = uVar19;

        }

        if (0 < (int)uVar25) {

          lVar23 = lVar23 * 4;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          local_60 = (ulonglong)uVar25;

          do {

            puVar11 = (uint *)((int)(local_res18 * *(int *)(param_1 + 0x10)) + lVar23 +

                              *(longlong *)(param_1 + 0x18));

            uVar19 = *puVar11;

            *puVar11 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                               [(uVar19 & *(uint *)(lVar5 + 0x10)) >>

                                (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar28) / 0xff + uVar17 >>

                       (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) << (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                               [(uVar19 & *(uint *)(lVar5 + 0x14)) >>

                                (*(byte *)(lVar5 + 0x1f) & 0x3f)] * uVar28) / 0xff + (uint)param_10

                       >> (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) << (*(byte *)(lVar5 + 0x1f) & 0x1f)

                       | (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                 [(uVar19 & *(uint *)(lVar5 + 0xc)) >>

                                  (*(byte *)(lVar5 + 0x1d) & 0x3f)] * uVar28) / 0xff + uVar26 >>

                         (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                               [(uVar19 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)]

                        * uVar28) / 0xff + uVar29 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1c) & 0x1f);

            lVar6 = lVar16;

            uVar19 = iVar21 * 2;

            uVar25 = uVar20;

            if ((int)local_b0 < 0) {

              lVar6 = (longlong)(int)uVar14 * 4;

              uVar19 = local_a0;

              uVar25 = uVar10;

            }

            local_res18 = local_res18 + uVar25;

            local_b0 = local_b0 + uVar19;

            puVar11 = (uint *)(ulonglong)local_b0;

            lVar23 = lVar23 + lVar6;

            local_60 = local_60 - 1;

          } while (local_60 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar28 = -(param_4 - param_2);

        if ((int)uVar28 < 0) {

          uVar28 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar7 = (int)uVar28 < (int)uVar14;

        if (bVar7) {

          local_a0 = uVar28 * 2;

          local_b0 = local_a0 - uVar14;

          iVar21 = uVar28 - uVar14;

        }

        else {

          local_a0 = uVar14 * 2;

          local_b0 = local_a0 - uVar28;

          iVar21 = uVar14 - uVar28;

          uVar14 = uVar28;

        }

        uVar28 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar28 = (uint)!bVar7;

        }

        uVar19 = -(uint)bVar7;

        if (param_3 <= (int)param_5) {

          uVar19 = (uint)bVar7;

        }

        puVar11 = (uint *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar11 = (uint *)0x1;

        }

        uVar25 = (uint)puVar11;

        uVar10 = uVar14 + 1;

        if (param_11 == 0) {

          uVar10 = uVar14;

        }

        if (0 < (int)uVar10) {

          lVar23 = lVar23 * 4;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          local_98 = (ulonglong)uVar10;

          do {

            puVar11 = (uint *)((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                               *(longlong *)(param_1 + 0x18) + lVar23);

            uVar14 = *puVar11;

            uVar10 = uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                    [(*(uint *)(lVar5 + 8) & uVar14) >>

                                     (*(byte *)(lVar5 + 0x1c) & 0x3f)];

            if (0xff < uVar29 + (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                      [(*(uint *)(lVar5 + 8) & uVar14) >>

                                       (*(byte *)(lVar5 + 0x1c) & 0x3f)]) {

              uVar10 = 0xff;

            }

            uVar20 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                           [(*(uint *)(lVar5 + 0xc) & uVar14) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)] +

                     uVar26;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                             [(*(uint *)(lVar5 + 0xc) & uVar14) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                       + uVar26) {

              uVar20 = 0xff;

            }

            uVar22 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                     + uVar17;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                             [(*(uint *)(lVar5 + 0x10) & uVar14) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)

                             ] + uVar17) {

              uVar22 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                       (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                    [(*(uint *)(lVar5 + 0x14) & uVar14) >>

                                     (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                             (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                       (uVar22 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                       (uVar20 >> (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1d) & 0x1f);

            lVar6 = lVar16;

            uVar10 = iVar21 * 2;

            uVar14 = uVar25;

            if ((int)local_b0 < 0) {

              lVar6 = (longlong)(int)uVar28 * 4;

              uVar10 = local_a0;

              uVar14 = uVar19;

            }

            local_res18 = local_res18 + uVar14;

            local_b0 = local_b0 + uVar10;

            puVar11 = (uint *)(ulonglong)local_b0;

            lVar23 = lVar23 + lVar6;

            local_98 = local_98 - 1;

          } while (local_98 != 0);

        }

        break;

      default:

        uVar28 = -(param_4 - param_2);

        if ((int)uVar28 < 0) {

          uVar28 = param_4 - param_2;

        }

        uVar14 = param_5 - param_3;

        param_5 = -uVar14;

        if ((int)param_5 < 0) {

          param_5 = uVar14;

        }

        bVar7 = (int)uVar28 < (int)param_5;

        if (bVar7) {

          param_6 = uVar28 * 2;

          iVar18 = param_6 - param_5;

          iVar27 = uVar28 - param_5;

        }

        else {

          param_6 = param_5 * 2;

          iVar18 = param_6 - uVar28;

          iVar27 = param_5 - uVar28;

          param_5 = uVar28;

        }

        local_res18 = (uint)!bVar7;

        uVar28 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar28 = local_res18;

        }

        uVar14 = -(uint)bVar7;

        if (param_3 <= iVar21) {

          uVar14 = (uint)bVar7;

        }

        uVar19 = 0xffffffff;

        if (param_3 <= iVar21) {

          uVar19 = 1;

        }

        puVar11 = (uint *)(ulonglong)param_5;

        uVar10 = param_5 + 1;

        if (param_11 == 0) {

          uVar10 = param_5;

        }

        if (0 < (int)uVar10) {

          lVar23 = lVar23 * 4;

          uVar24 = (ulonglong)uVar10;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          do {

            uVar10 = param_3 * *(int *)(param_1 + 0x10);

            puVar11 = (uint *)(ulonglong)uVar10;

            *(uint *)((longlong)(int)uVar10 + *(longlong *)(param_1 + 0x18) + lVar23) =

                 (uVar26 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                 (uint)(param_10 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                 (uVar17 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                 (uVar29 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar5 + 0x1c) & 0x1f);

            lVar6 = lVar16;

            iVar21 = iVar27 * 2;

            uVar10 = uVar19;

            if (iVar18 < 0) {

              lVar6 = (longlong)(int)uVar28 * 4;

              iVar21 = param_6;

              uVar10 = uVar14;

            }

            param_3 = param_3 + uVar10;

            iVar18 = iVar18 + iVar21;

            lVar23 = lVar23 + lVar6;

            uVar24 = uVar24 - 1;

          } while (uVar24 != 0);

        }

        break;

      case 3:

        uVar28 = -(param_4 - param_2);

        if ((int)uVar28 < 0) {

          uVar28 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar7 = (int)uVar28 < (int)uVar14;

        if (bVar7) {

          local_a0 = uVar28 * 2;

          local_b0 = local_a0 - uVar14;

          iVar21 = uVar28 - uVar14;

        }

        else {

          local_a0 = uVar14 * 2;

          local_b0 = local_a0 - uVar28;

          iVar21 = uVar14 - uVar28;

          uVar14 = uVar28;

        }

        uVar28 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar28 = (uint)!bVar7;

        }

        uVar19 = -(uint)bVar7;

        if (param_3 <= (int)param_5) {

          uVar19 = (uint)bVar7;

        }

        puVar11 = (uint *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar11 = (uint *)0x1;

        }

        uVar25 = (uint)puVar11;

        uVar10 = uVar14 + 1;

        if (param_11 == 0) {

          uVar10 = uVar14;

        }

        if (0 < (int)uVar10) {

          lVar23 = lVar23 * 4;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          local_98 = (ulonglong)uVar10;

          do {

            puVar11 = (uint *)((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                               *(longlong *)(param_1 + 0x18) + lVar23);

            uVar14 = *puVar11;

            *puVar11 = (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                               [(*(uint *)(lVar5 + 0x10) & uVar14) >>

                                (*(byte *)(lVar5 + 0x1e) & 0x3f)] * uVar17) / 0xff >>

                       (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) << (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                               [(*(uint *)(lVar5 + 0xc) & uVar14) >>

                                (*(byte *)(lVar5 + 0x1d) & 0x3f)] * uVar26) / 0xff >>

                       (8 - *(byte *)(lVar5 + 0x19) & 0x1f)) << (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                               [(uVar14 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)]

                        * uVar29) / 0xff >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                       (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                    [(*(uint *)(lVar5 + 0x14) & uVar14) >>

                                     (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                             (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1f) & 0x1f);

            lVar6 = lVar16;

            uVar10 = iVar21 * 2;

            uVar14 = uVar25;

            if ((int)local_b0 < 0) {

              lVar6 = (longlong)(int)uVar28 * 4;

              uVar10 = local_a0;

              uVar14 = uVar19;

            }

            local_res18 = local_res18 + uVar14;

            local_b0 = local_b0 + uVar10;

            puVar11 = (uint *)(ulonglong)local_b0;

            lVar23 = lVar23 + lVar6;

            local_98 = local_98 - 1;

          } while (local_98 != 0);

        }

        break;

      case 7:

        uVar14 = -(param_4 - param_2);

        if ((int)uVar14 < 0) {

          uVar14 = param_4 - param_2;

        }

        uVar19 = -(param_5 - param_3);

        if ((int)uVar19 < 0) {

          uVar19 = param_5 - param_3;

        }

        bVar7 = (int)uVar14 < (int)uVar19;

        if (bVar7) {

          local_a0 = uVar14 * 2;

          local_b0 = local_a0 - uVar19;

          iVar21 = uVar14 - uVar19;

        }

        else {

          local_a0 = uVar19 * 2;

          local_b0 = local_a0 - uVar14;

          iVar21 = uVar19 - uVar14;

          uVar19 = uVar14;

        }

        uVar14 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar14 = (uint)!bVar7;

        }

        uVar10 = -(uint)bVar7;

        if (param_3 <= (int)param_5) {

          uVar10 = (uint)bVar7;

        }

        puVar11 = (uint *)0xffffffff;

        if (param_3 <= (int)param_5) {

          puVar11 = (uint *)0x1;

        }

        uVar20 = (uint)puVar11;

        uVar25 = uVar19 + 1;

        if (param_11 == 0) {

          uVar25 = uVar19;

        }

        if (0 < (int)uVar25) {

          lVar23 = lVar23 * 4;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          local_98 = (ulonglong)uVar25;

          do {

            puVar11 = (uint *)((longlong)(int)(local_res18 * *(int *)(param_1 + 0x10)) +

                               *(longlong *)(param_1 + 0x18) + lVar23);

            uVar19 = *puVar11;

            uVar25 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                            [(uVar19 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                     uVar28) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                            [(uVar19 & *(uint *)(lVar5 + 8)) >> (*(byte *)(lVar5 + 0x1c) & 0x3f)] *

                     uVar29) / 0xff;

            if (0xff < uVar25) {

              uVar25 = 0xff;

            }

            uVar22 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                            [(*(uint *)(lVar5 + 0xc) & uVar19) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                     * uVar28) / 0xff +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                            [(*(uint *)(lVar5 + 0xc) & uVar19) >> (*(byte *)(lVar5 + 0x1d) & 0x3f)]

                     * uVar26) / 0xff;

            if (0xff < uVar22) {

              uVar22 = 0xff;

            }

            uVar9 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar19) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar28) / 0xff +

                    ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                           [(*(uint *)(lVar5 + 0x10) & uVar19) >> (*(byte *)(lVar5 + 0x1e) & 0x3f)]

                    * uVar17) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            *puVar11 = (uVar25 >> (8 - *(byte *)(lVar5 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                       (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                    [(*(uint *)(lVar5 + 0x14) & uVar19) >>

                                     (*(byte *)(lVar5 + 0x1f) & 0x3f)] >>

                             (8 - *(byte *)(lVar5 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                       (uVar9 >> (8 - *(byte *)(lVar5 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                       (uVar22 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar5 + 0x1d) & 0x1f);

            lVar6 = lVar16;

            uVar19 = iVar21 * 2;

            uVar25 = uVar20;

            if ((int)local_b0 < 0) {

              lVar6 = (longlong)(int)uVar14 * 4;

              uVar19 = local_a0;

              uVar25 = uVar10;

            }

            local_res18 = local_res18 + uVar25;

            local_b0 = local_b0 + uVar19;

            puVar11 = (uint *)(ulonglong)local_b0;

            lVar23 = lVar23 + lVar6;

            local_98 = local_98 - 1;

          } while (local_98 != 0);

        }

        break;

      case 0xf:

        uVar14 = -(param_4 - param_2);

        if ((int)uVar14 < 0) {

          uVar14 = param_4 - param_2;

        }

        local_res18 = -(param_5 - param_3);

        if ((int)local_res18 < 0) {

          local_res18 = param_5 - param_3;

        }

        bVar7 = (int)uVar14 < (int)local_res18;

        if (bVar7) {

          local_90 = uVar14 * 2;

          local_b0 = local_90 - local_res18;

          iVar21 = uVar14 - local_res18;

        }

        else {

          local_90 = local_res18 * 2;

          local_b0 = local_90 - uVar14;

          iVar21 = local_res18 - uVar14;

          local_res18 = uVar14;

        }

        uVar14 = -(uint)!bVar7;

        if (param_2 <= param_4) {

          uVar14 = (uint)!bVar7;

        }

        uVar19 = -(uint)bVar7;

        if (param_3 <= (int)param_5) {

          uVar19 = (uint)bVar7;

        }

        uVar10 = 0xffffffff;

        if (param_3 <= (int)param_5) {

          uVar10 = 1;

        }

        uVar25 = local_res18 + 1;

        if (param_11 == 0) {

          uVar25 = local_res18;

        }

        puVar11 = (uint *)(ulonglong)uVar25;

        if (0 < (int)uVar25) {

          lVar23 = lVar23 * 4;

          lVar16 = -4;

          if (param_2 <= param_4) {

            lVar16 = 4;

          }

          local_98 = (ulonglong)uVar25;

          do {

            puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                              param_3 * *(int *)(param_1 + 0x10) + lVar23);

            bVar2 = *(byte *)(lVar5 + 0x1d);

            uVar20 = *puVar11;

            bVar3 = *(byte *)(lVar5 + 0x1e);

            bVar12 = *(byte *)(lVar5 + 0x1f);

            bVar13 = *(byte *)(lVar5 + 0x18);

            local_b6 = *(byte *)(lVar5 + 0x1f);

            bVar4 = *(byte *)(lVar5 + 0x1c);

            local_b2 = *(byte *)(lVar5 + 0x1d);

            uVar25 = ((byte)(&PTR_DAT_1403e28a0)[bVar13]

                            [(*(uint *)(lVar5 + 8) & uVar20) >> (bVar4 & 0x3f)] * uVar28) / 0xff +

                     uVar29;

            if (0xff < uVar25) {

              uVar25 = 0xff;

            }

            local_b7 = *(byte *)(lVar5 + 0x1c);

            local_b8 = *(byte *)(lVar5 + 0x18);

            local_a0 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                              [(*(uint *)(lVar5 + 0xc) & uVar20) >> (bVar2 & 0x3f)] * uVar28) / 0xff

                       + uVar26;

            local_b4 = *(byte *)(lVar5 + 0x1e);

            if (local_a0 < 0x100) {

              bVar13 = *(byte *)(lVar5 + 0x18);

            }

            else {

              local_a0 = 0xff;

              local_b8 = bVar13;

              local_b7 = bVar4;

              local_b6 = bVar12;

              local_b4 = bVar3;

              local_b2 = bVar2;

            }

            uVar22 = uVar17 + ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                     [(*(uint *)(lVar5 + 0x10) & uVar20) >> (bVar3 & 0x3f)] * uVar28

                              ) / 0xff;

            bVar8 = bVar12;

            local_60._0_1_ = *(byte *)(lVar5 + 0x1b);

            local_48 = *(byte *)(lVar5 + 0x1a);

            local_50 = *(byte *)(lVar5 + 0x19);

            if (0xff < uVar22) {

              uVar22 = 0xff;

              bVar2 = local_b2;

              bVar3 = local_b4;

              bVar8 = local_b6;

              bVar4 = local_b7;

              bVar13 = local_b8;

              local_60._0_1_ = *(byte *)(lVar5 + 0x1b);

              local_48 = *(byte *)(lVar5 + 0x1a);

              local_50 = *(byte *)(lVar5 + 0x19);

            }

            uVar20 = (uint)param_10 +

                     ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                            [(*(uint *)(lVar5 + 0x14) & uVar20) >> (bVar12 & 0x3f)] * uVar28) / 0xff

            ;

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            *puVar11 = (uVar25 >> (8 - bVar13 & 0x1f)) << (bVar4 & 0x1f) |

                       (uVar20 >> (8 - (byte)local_60 & 0x1f)) << (bVar8 & 0x1f) |

                       (uVar22 >> (8 - local_48 & 0x1f)) << (bVar3 & 0x1f) |

                       (local_a0 >> (8 - local_50 & 0x1f)) << (bVar2 & 0x1f);

            lVar6 = lVar16;

            iVar27 = iVar21 * 2;

            uVar25 = uVar10;

            if ((int)local_b0 < 0) {

              lVar6 = (longlong)(int)uVar14 * 4;

              iVar27 = local_90;

              uVar25 = uVar19;

            }

            param_3 = param_3 + uVar25;

            local_b0 = local_b0 + iVar27;

            puVar11 = (uint *)(ulonglong)local_b0;

            lVar23 = lVar23 + lVar6;

            local_98 = local_98 - 1;

          } while (local_98 != 0);

        }

      }

    }

  }

  return puVar11;

}




