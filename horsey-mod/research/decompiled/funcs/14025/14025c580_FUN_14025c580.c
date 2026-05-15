// Address: 0x14025c580
// Ghidra name: FUN_14025c580
// ============ 0x14025c580 FUN_14025c580 (size=3389) ============


undefined8

FUN_14025c580(longlong param_1,int param_2,int param_3,undefined4 param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  undefined8 uVar4;

  ulonglong uVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint *puVar10;

  ushort *puVar11;

  ulonglong uVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x38);

  iVar7 = 0xff - (uint)param_8;

  if (*(char *)(lVar1 + 5) == '\x02') {

    switch(param_4) {

    case 1:

      puVar11 = (ushort *)

                ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                *(longlong *)(param_1 + 0x18));

      uVar6 = (ulonglong)*puVar11;

      uVar5 = 0;

      *puVar11 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                      [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff +

                         (uint)param_7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                      [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff +

                         (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff +

                         (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

      break;

    case 2:

    case 0x20:

      puVar11 = (ushort *)

                ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                *(longlong *)(param_1 + 0x18));

      uVar5 = (ulonglong)*puVar11;

      uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                          [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

              (uint)param_5;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                 (uint)param_5) {

        uVar3 = 0xff;

      }

      uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar5) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] +

              (uint)param_6;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                             [(*(uint *)(lVar1 + 0xc) & uVar5) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]

                 + (uint)param_6) {

        uVar8 = 0xff;

      }

      uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar5) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] +

              (uint)param_7;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                             [(*(uint *)(lVar1 + 0x10) & uVar5) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]

                 + (uint)param_7) {

        uVar9 = 0xff;

      }

      uVar2 = 8 - *(byte *)(lVar1 + 0x19);

      uVar5 = (ulonglong)uVar2;

      *puVar11 = (short)(uVar3 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (short)(uVar9 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (short)(uVar8 >> ((byte)uVar2 & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 *(ushort *)(lVar1 + 0x14);

      break;

    default:

      uVar5 = *(ulonglong *)(param_1 + 0x18);

      *(ushort *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) + uVar5)

           = (ushort)(param_5 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar1 + 0x1c) & 0x1f) |

             (ushort)(param_6 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar1 + 0x1d) & 0x1f) |

             (ushort)(param_7 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

      break;

    case 4:

      puVar11 = (ushort *)

                ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                *(longlong *)(param_1 + 0x18));

      uVar6 = (ulonglong)*puVar11;

      uVar5 = (ulonglong)

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                           [(*(uint *)(lVar1 + 0x10) & uVar6) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] *

              (uint)param_7) * 0x80808081 & 0xffffffff;

      *puVar11 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                      [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_6) / 0xff >>

                        (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * (uint)param_5) / 0xff >>

                        (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                      [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                       (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_7) / 0xff >>

                        (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 *(ushort *)(lVar1 + 0x14);

      break;

    case 8:

      lVar1 = *(longlong *)(param_1 + 0x38);

      puVar11 = (ushort *)

                ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                *(longlong *)(param_1 + 0x18));

      uVar5 = (ulonglong)*puVar11;

      uVar3 = ((uint)param_5 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                          [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar3) {

        uVar3 = 0xff;

      }

      uVar8 = ((uint)param_6 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar5) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      uVar9 = ((uint)param_7 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar5) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar5 = *(ulonglong *)(param_1 + 0x38);

      *puVar11 = (short)(uVar3 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (short)(uVar9 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (short)(uVar8 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(uVar5 + 0x14);

      break;

    case 0x10:

      puVar11 = (ushort *)

                ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                *(longlong *)(param_1 + 0x18));

      uVar5 = (ulonglong)*puVar11;

      uVar3 = (uint)param_5 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar3) {

        uVar3 = 0xff;

      }

      uVar8 = (uint)param_6 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                           [(*(uint *)(lVar1 + 0xc) & uVar5) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      uVar9 = (uint)param_7 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                           [(*(uint *)(lVar1 + 0x10) & uVar5) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar2 = 8 - *(byte *)(lVar1 + 0x19);

      uVar5 = (ulonglong)uVar2;

      *puVar11 = (short)(uVar3 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (short)(uVar9 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (short)(uVar8 >> ((byte)uVar2 & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 *(ushort *)(lVar1 + 0x14);

    }

  }

  else {

    if (*(char *)(lVar1 + 5) != '\x04') {

      uVar4 = FUN_14012e850("That operation is not supported");

      return uVar4;

    }

    switch(param_4) {

    case 1:

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      uVar5 = 0;

      *puVar10 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                               [(*(uint *)(lVar1 + 0x10) & uVar3) >>

                                (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff + (uint)param_7 >>

                 (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                               [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)

                               ] * iVar7) / 0xff + (uint)param_6 >>

                 (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                  * iVar7) / 0xff + (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(uint *)(lVar1 + 0x14);

      break;

    case 2:

    case 0x20:

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                          [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

              (uint)param_5;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                 (uint)param_5) {

        uVar8 = 0xff;

      }

      uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] +

              (uint)param_6;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                             [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]

                 + (uint)param_6) {

        uVar9 = 0xff;

      }

      uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] +

              (uint)param_7;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                             [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]

                 + (uint)param_7) {

        uVar2 = 0xff;

      }

      uVar3 = 8 - *(byte *)(lVar1 + 0x19);

      uVar5 = (ulonglong)uVar3;

      *puVar10 = (uVar8 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f)

                 | (uVar2 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (uVar9 >> ((byte)uVar3 & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 *(uint *)(lVar1 + 0x14);

      break;

    default:

      uVar5 = *(ulonglong *)(param_1 + 0x18);

      *(uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) + uVar5) =

           (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1c) & 0x1f) |

           (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1d) & 0x1f) |

           (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

      break;

    case 4:

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      uVar5 = (ulonglong)

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                           [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] *

              (uint)param_6) * 0x80808081 & 0xffffffff;

      *puVar10 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                  * (uint)param_5) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                               [(*(uint *)(lVar1 + 0x10) & uVar3) >>

                                (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_7) / 0xff >>

                 (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                               [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)

                               ] * (uint)param_6) / 0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

      break;

    case 8:

      lVar1 = *(longlong *)(param_1 + 0x38);

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      uVar8 = ((uint)param_5 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                          [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      uVar9 = ((uint)param_6 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar3 = ((uint)param_7 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

      if (0xff < uVar3) {

        uVar3 = 0xff;

      }

      uVar5 = *(ulonglong *)(param_1 + 0x38);

      *puVar10 = (uVar8 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f)

                 | (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (uVar9 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f)

                 | *(uint *)(uVar5 + 0x14);

      break;

    case 0x10:

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      uVar8 = (uint)param_5 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      uVar9 = (uint)param_6 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                           [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar3 = (uint)param_7 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                           [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] *

              iVar7) / 0xff;

      if (0xff < uVar3) {

        uVar3 = 0xff;

      }

      uVar2 = 8 - *(byte *)(lVar1 + 0x19);

      uVar5 = (ulonglong)uVar2;

      *puVar10 = (uVar8 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f)

                 | (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (uVar9 >> ((byte)uVar2 & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 *(uint *)(lVar1 + 0x14);

    }

  }

  return CONCAT71((int7)(uVar5 >> 8),1);

}




