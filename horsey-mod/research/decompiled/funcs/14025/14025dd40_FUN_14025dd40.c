// Address: 0x14025dd40
// Ghidra name: FUN_14025dd40
// ============ 0x14025dd40 FUN_14025dd40 (size=2185) ============


undefined8

FUN_14025dd40(longlong param_1,int param_2,int param_3,undefined4 param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  undefined8 uVar4;

  uint *puVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint *puVar10;

  

  lVar1 = *(longlong *)(param_1 + 0x38);

  iVar6 = 0xff - (uint)param_8;

  if (*(char *)(lVar1 + 5) == '\x04') {

    switch(param_4) {

    case 1:

      lVar2 = *(longlong *)(param_1 + 0x38);

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      uVar3 = *puVar10;

      puVar5 = (uint *)0x0;

      *puVar10 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar2 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                  * iVar6) / 0xff + (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1a)]

                               [(*(uint *)(lVar2 + 0x10) & uVar3) >>

                                (*(byte *)(lVar2 + 0x1e) & 0x3f)] * iVar6) / 0xff + (uint)param_7 >>

                 (8 - *(byte *)(lVar2 + 0x1a) & 0x1f)) << (*(byte *)(lVar2 + 0x1e) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                               [(*(uint *)(lVar2 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)

                               ] * iVar6) / 0xff + (uint)param_6 >>

                 (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1b)]

                               [(*(uint *)(lVar2 + 0x14) & uVar3) >>

                                (*(byte *)(lVar2 + 0x1f) & 0x3f)] * iVar6) / 0xff + (uint)param_8 >>

                 (8 - *(byte *)(lVar2 + 0x1b) & 0x1f)) << (*(byte *)(lVar2 + 0x1f) & 0x1f);

      break;

    case 2:

    case 0x20:

      puVar5 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

      uVar3 = *puVar5;

      lVar2 = *(longlong *)(param_1 + 0x38);

      uVar7 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                          [(*(uint *)(lVar2 + 8) & uVar3) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] +

              (uint)param_5;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x18)]

                             [(*(uint *)(lVar2 + 8) & uVar3) >> (*(byte *)(lVar2 + 0x1c) & 0x3f)] +

                 (uint)param_5) {

        uVar7 = 0xff;

      }

      uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] +

              (uint)param_6;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                             [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]

                 + (uint)param_6) {

        uVar9 = 0xff;

      }

      uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] +

              (uint)param_7;

      if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                             [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]

                 + (uint)param_7) {

        uVar8 = 0xff;

      }

      *puVar5 = (uVar7 >> (8 - *(byte *)(lVar2 + 0x18) & 0x1f)) << (*(byte *)(lVar2 + 0x1c) & 0x1f)

                | (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                               [(*(uint *)(*(longlong *)(param_1 + 0x38) + 0x14) & uVar3) >>

                                (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                        (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) << (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f)

                | (uVar9 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                  (*(byte *)(lVar1 + 0x1d) & 0x1f);

      break;

    default:

      puVar5 = *(uint **)(param_1 + 0x18);

      *(uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

               (longlong)puVar5) =

           (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1c) & 0x1f) |

           (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1d) & 0x1f) |

           (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1e) & 0x1f) |

           (uint)(param_8 >> (8U - *(char *)(lVar1 + 0x1b) & 0x1f)) <<

           (*(byte *)(lVar1 + 0x1f) & 0x1f);

      break;

    case 4:

      puVar10 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                        *(longlong *)(param_1 + 0x18));

      lVar2 = *(longlong *)(param_1 + 0x38);

      uVar3 = *puVar10;

      puVar5 = (uint *)(&PTR_DAT_1403e28a0)[*(byte *)(lVar2 + 0x1b)];

      *puVar10 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                               [(*(uint *)(lVar2 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)

                               ] * (uint)param_6) / 0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar2 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                  * (uint)param_5) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                 (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                               [(*(uint *)(lVar2 + 0x10) & uVar3) >>

                                (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_7) / 0xff >>

                 (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                 (uint)(*(byte *)((ulonglong)

                                  ((*(uint *)(lVar2 + 0x14) & uVar3) >>

                                  (*(byte *)(lVar2 + 0x1f) & 0x3f)) + (longlong)puVar5) >>

                       (8 - *(byte *)(lVar2 + 0x1b) & 0x1f)) << (*(byte *)(lVar2 + 0x1f) & 0x1f);

      break;

    case 8:

      puVar5 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

      uVar3 = *puVar5;

      uVar7 = ((uint)param_5 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                          [(*(uint *)(lVar1 + 8) & uVar3) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar6) / 0xff;

      if (0xff < uVar7) {

        uVar7 = 0xff;

      }

      uVar9 = ((uint)param_6 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                          [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar6) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar8 = ((uint)param_7 *

              (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                          [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)]) /

              0xff + ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar3) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar6) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      *puVar5 = (uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f)

                | (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                               [(*(uint *)(lVar1 + 0x14) & uVar3) >>

                                (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                        (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) << (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f)

                | (uVar9 >> (8U - *(char *)(*(longlong *)(param_1 + 0x38) + 0x19) & 0x1f)) <<

                  (*(byte *)(*(longlong *)(param_1 + 0x38) + 0x1d) & 0x1f);

      break;

    case 0x10:

      puVar5 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

      uVar3 = *puVar5;

      uVar7 = (uint)param_5 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(*(longlong *)(param_1 + 0x38) + 8) & uVar3) >>

                            (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar6) / 0xff;

      if (0xff < uVar7) {

        uVar7 = 0xff;

      }

      uVar9 = (uint)param_6 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                           [(*(uint *)(lVar1 + 0xc) & uVar3) >> (*(byte *)(lVar1 + 0x1d) & 0x3f)] *

              iVar6) / 0xff;

      if (0xff < uVar9) {

        uVar9 = 0xff;

      }

      uVar8 = (uint)param_7 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                           [(*(uint *)(lVar1 + 0x10) & uVar3) >> (*(byte *)(lVar1 + 0x1e) & 0x3f)] *

              iVar6) / 0xff;

      if (0xff < uVar8) {

        uVar8 = 0xff;

      }

      uVar3 = (uint)param_8 +

              ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                           [(*(uint *)(lVar1 + 0x14) & uVar3) >> (*(byte *)(lVar1 + 0x1f) & 0x3f)] *

              iVar6) / 0xff;

      if (0xff < uVar3) {

        uVar3 = 0xff;

      }

      *puVar5 = (uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f)

                | (uVar3 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                  (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f)

                | (uVar9 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                  (*(byte *)(*(longlong *)(param_1 + 0x38) + 0x1d) & 0x1f);

    }

    return CONCAT71((int7)((ulonglong)puVar5 >> 8),1);

  }

  uVar4 = FUN_14012e850("That operation is not supported");

  return uVar4;

}




