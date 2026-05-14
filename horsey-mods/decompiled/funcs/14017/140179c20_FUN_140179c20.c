// Address: 0x140179c20
// Ghidra name: FUN_140179c20
// ============ 0x140179c20 FUN_140179c20 (size=881) ============


longlong FUN_140179c20(int *param_1,uint param_2,uint param_3,uint param_4,byte param_5,

                      uint *param_6)



{

  ulonglong uVar1;

  byte bVar2;

  uint uVar3;

  longlong lVar4;

  longlong lVar5;

  byte bVar6;

  uint uVar7;

  byte bVar8;

  uint uVar9;

  byte bVar10;

  uint uVar11;

  byte *pbVar12;

  int iVar13;

  int iVar14;

  longlong lVar15;

  uint uVar16;

  

  if (param_1 == (int *)0x0) {

    FUN_14012e850("src does not have a palette set");

    return 0;

  }

  uVar16 = *param_6;

  if ((uVar16 == 0) || ((uVar16 & 0xf0000000) == 0x10000000)) {

    uVar3 = uVar16 & 0xff;

LAB_140179ca5:

    if (uVar3 == 3) {

      uVar16 = 4;

      goto LAB_140179cf8;

    }

    if ((uVar16 == 0) || ((uVar16 & 0xf0000000) == 0x10000000)) {

      uVar16 = uVar16 & 0xff;

      goto LAB_140179cf8;

    }

    if (((uVar16 == 0x32595559) || (uVar16 == 0x59565955)) ||

       ((uVar16 == 0x55595659 || (uVar16 == 0x30313050)))) {

      uVar16 = 2;

      goto LAB_140179cf8;

    }

  }

  else if ((((uVar16 == 0x32595559) || (uVar16 == 0x59565955)) || (uVar16 == 0x55595659)) ||

          (uVar16 == 0x30313050)) {

    uVar3 = 2;

    goto LAB_140179ca5;

  }

  uVar16 = 1;

LAB_140179cf8:

  lVar4 = FUN_1401841a0(0x100,uVar16);

  if ((lVar4 != 0) && (iVar14 = 0, 0 < *param_1)) {

    iVar13 = 0;

    lVar15 = 0;

    do {

      pbVar12 = (byte *)(*(longlong *)(param_1 + 2) + lVar15);

      uVar11 = ((uint)*pbVar12 * (param_2 & 0xff)) / 0xff;

      uVar9 = ((uint)pbVar12[1] * (param_3 & 0xff)) / 0xff;

      uVar7 = ((uint)pbVar12[2] * (param_4 & 0xff)) / 0xff;

      uVar3 = *param_6;

      uVar1 = (ulonglong)((uint)pbVar12[3] * (uint)param_5) / 0xff;

      bVar2 = (byte)uVar1;

      bVar6 = (byte)uVar7;

      bVar10 = (byte)uVar11;

      bVar8 = (byte)uVar9;

      if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

        uVar3 = uVar3 & 0xff;

LAB_140179ddf:

        if (uVar3 == 1) goto LAB_140179efe;

        if (uVar3 == 2) {

          *(ushort *)(iVar13 + lVar4) =

               (ushort)(bVar2 >> (8U - *(char *)((longlong)param_6 + 0x1b) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1f) & 0x1f) |

               (ushort)(bVar6 >> (8U - *(char *)((longlong)param_6 + 0x1a) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1e) & 0x1f) |

               (ushort)(bVar10 >> (8U - (char)param_6[6] & 0x1f)) << ((byte)param_6[7] & 0x1f) |

               (ushort)(bVar8 >> (8U - *(char *)((longlong)param_6 + 0x19) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1d) & 0x1f);

        }

        else if (uVar3 == 3) {

          lVar5 = (longlong)iVar13;

          *(byte *)((ulonglong)(byte)((byte)param_6[7] >> 3) + lVar5 + lVar4) = bVar10;

          *(byte *)((ulonglong)(*(byte *)((longlong)param_6 + 0x1d) >> 3) + lVar5 + lVar4) = bVar8;

          *(byte *)((ulonglong)(*(byte *)((longlong)param_6 + 0x1e) >> 3) + lVar5 + lVar4) = bVar6;

        }

        else if (uVar3 == 4) {

          *(uint *)(iVar13 + lVar4) =

               (((uint)uVar1 & 0xff) >> (8U - *(char *)((longlong)param_6 + 0x1b) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1f) & 0x1f) |

               ((uVar7 & 0xff) >> (8U - *(char *)((longlong)param_6 + 0x1a) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1e) & 0x1f) |

               ((uVar11 & 0xff) >> (8U - (char)param_6[6] & 0x1f)) << ((byte)param_6[7] & 0x1f) |

               ((uVar9 & 0xff) >> (8U - *(char *)((longlong)param_6 + 0x19) & 0x1f)) <<

               (*(byte *)((longlong)param_6 + 0x1d) & 0x1f);

        }

      }

      else {

        if ((((uVar3 == 0x32595559) || (uVar3 == 0x59565955)) || (uVar3 == 0x55595659)) ||

           (uVar3 == 0x30313050)) {

          uVar3 = 2;

          goto LAB_140179ddf;

        }

LAB_140179efe:

        *(byte *)(iVar13 + lVar4) =

             (bVar2 >> (8U - *(char *)((longlong)param_6 + 0x1b) & 0x1f)) <<

             (*(byte *)((longlong)param_6 + 0x1f) & 0x1f) |

             (bVar6 >> (8U - *(char *)((longlong)param_6 + 0x1a) & 0x1f)) <<

             (*(byte *)((longlong)param_6 + 0x1e) & 0x1f) |

             (bVar10 >> (8U - (char)param_6[6] & 0x1f)) << ((byte)param_6[7] & 0x1f) |

             (bVar8 >> (8U - *(char *)((longlong)param_6 + 0x19) & 0x1f)) <<

             (*(byte *)((longlong)param_6 + 0x1d) & 0x1f);

      }

      iVar14 = iVar14 + 1;

      iVar13 = iVar13 + uVar16;

      lVar15 = lVar15 + 4;

    } while (iVar14 < *param_1);

  }

  return lVar4;

}




