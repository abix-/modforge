// Address: 0x1401d2d50
// Ghidra name: FUN_1401d2d50
// ============ 0x1401d2d50 FUN_1401d2d50 (size=278) ============


int FUN_1401d2d50(ushort *param_1,uint *param_2,uint param_3,longlong param_4,longlong param_5)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = (ulonglong)param_3;

  if (0 < (int)param_3) {

    do {

      uVar1 = *param_2;

      param_2 = param_2 + 1;

      *param_1 = (ushort)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_4 + 0x18)]

                                [(uVar1 & *(uint *)(param_4 + 8)) >>

                                 (*(byte *)(param_4 + 0x1c) & 0x3f)] >>

                         (8U - *(char *)(param_5 + 0x18) & 0x1f)) <<

                 (*(byte *)(param_5 + 0x1c) & 0x1f) |

                 (ushort)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_4 + 0x1a)]

                                [(uVar1 & *(uint *)(param_4 + 0x10)) >>

                                 (*(byte *)(param_4 + 0x1e) & 0x3f)] >>

                         (8U - *(char *)(param_5 + 0x1a) & 0x1f)) <<

                 (*(byte *)(param_5 + 0x1e) & 0x1f) |

                 (ushort)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_4 + 0x19)]

                                [(*(uint *)(param_4 + 0xc) & uVar1) >>

                                 (*(byte *)(param_4 + 0x1d) & 0x3f)] >>

                         (8U - *(char *)(param_5 + 0x19) & 0x1f)) <<

                 (*(byte *)(param_5 + 0x1d) & 0x1f) | *(ushort *)(param_5 + 0x14);

      uVar2 = uVar2 - 1;

      param_1 = param_1 + 1;

    } while (uVar2 != 0);

  }

  return param_3 * 2;

}




