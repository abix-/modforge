// Address: 0x1401d2f80
// Ghidra name: FUN_1401d2f80
// ============ 0x1401d2f80 FUN_1401d2f80 (size=265) ============


int FUN_1401d2f80(longlong param_1,uint *param_2,uint param_3,longlong param_4,longlong param_5)



{

  uint uVar1;

  ulonglong uVar2;

  uint uVar3;

  

  uVar2 = (ulonglong)param_3;

  if (0 < (int)param_3) {

    param_1 = param_1 - (longlong)param_2;

    do {

      uVar1 = *param_2;

      param_2 = param_2 + 1;

      uVar3 = (uint)(ushort)((short)(((*(uint *)(param_4 + 0xc) & uVar1) >>

                                     (*(byte *)(param_4 + 0x1d) & 0x1f)) >>

                                    (8U - *(char *)(param_5 + 0x19) & 0x1f)) <<

                             (*(byte *)(param_5 + 0x1d) & 0x1f) |

                             (short)(((*(uint *)(param_4 + 0x10) & uVar1) >>

                                     (*(byte *)(param_4 + 0x1e) & 0x1f)) >>

                                    (8U - *(char *)(param_5 + 0x1a) & 0x1f)) <<

                             (*(byte *)(param_5 + 0x1e) & 0x1f) |

                             (short)(((uVar1 & *(uint *)(param_4 + 8)) >>

                                     (*(byte *)(param_4 + 0x1c) & 0x1f)) >>

                                    (8U - *(char *)(param_5 + 0x18) & 0x1f)) <<

                             (*(byte *)(param_5 + 0x1c) & 0x1f) | *(ushort *)(param_5 + 0x14));

      *(uint *)(param_1 + -4 + (longlong)param_2) =

           ((*(uint *)(param_4 + 0x14) & uVar1) >> (*(byte *)(param_4 + 0x1f) & 0x1f) & 0x1f8) << 2

           | (uVar3 & 0x7e0) << 0x10 | uVar3 & 0xf81f;

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  return param_3 * 4;

}




