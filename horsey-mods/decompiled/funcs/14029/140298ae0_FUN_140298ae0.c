// Address: 0x140298ae0
// Ghidra name: FUN_140298ae0
// ============ 0x140298ae0 FUN_140298ae0 (size=478) ============


void FUN_140298ae0(longlong param_1,longlong param_2,int *param_3,int *param_4,int *param_5,

                  int *param_6,undefined4 *param_7)



{

  byte bVar1;

  uint uVar2;

  undefined4 uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  

  uVar4 = *(uint *)(param_1 + 0x14);

  uVar3 = 0;

  if (uVar4 == 0) {

    uVar2 = *(uint *)(param_1 + 8);

    uVar5 = 0;

    bVar1 = *(byte *)(param_1 + 0x1c);

  }

  else {

    uVar2 = *(uint *)(param_1 + 8);

    bVar1 = *(byte *)(param_1 + 0x1c);

    uVar5 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_1 + 0x1b)]

                        [(uVar4 & 0x4030201) >> (*(byte *)(param_1 + 0x1f) & 0x3f)];

  }

  if ((*(int *)(param_2 + 0x14) == 0) || (uVar4 == 0)) {

    uVar4 = ((int)(uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_1 + 0x1a)]

                              [(*(uint *)(param_1 + 0x10) & 0x4030201) >>

                               (*(byte *)(param_1 + 0x1e) & 0x3f)] >>

            (8U - *(char *)(param_2 + 0x1a) & 0x1f)) << (*(byte *)(param_2 + 0x1e) & 0x1f);

  }

  else {

    uVar4 = ((int)uVar5 >> (8U - *(char *)(param_2 + 0x1b) & 0x1f)) <<

            (*(byte *)(param_2 + 0x1f) & 0x1f) |

            ((int)(uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_1 + 0x1a)]

                              [(*(uint *)(param_1 + 0x10) & 0x4030201) >>

                               (*(byte *)(param_1 + 0x1e) & 0x3f)] >>

            (8U - *(char *)(param_2 + 0x1a) & 0x1f)) << (*(byte *)(param_2 + 0x1e) & 0x1f);

  }

  uVar5 = uVar4 | ((int)(uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_1 + 0x19)]

                                    [(*(uint *)(param_1 + 0xc) & 0x4030201) >>

                                     (*(byte *)(param_1 + 0x1d) & 0x3f)] >>

                  (8U - *(char *)(param_2 + 0x19) & 0x1f)) << (*(byte *)(param_2 + 0x1d) & 0x1f) |

          ((int)(uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_1 + 0x18)]

                            [(uVar2 & 0x4030201) >> (bVar1 & 0x3f)] >>

          (8U - *(char *)(param_2 + 0x18) & 0x1f)) << (*(byte *)(param_2 + 0x1c) & 0x1f);

  uVar7 = uVar5 & 0xff;

  uVar6 = (int)uVar5 >> 8 & 0xff;

  uVar4 = (int)uVar5 >> 0x10 & 0xff;

  uVar2 = (int)uVar5 >> 0x18 & 0xff;

  if (uVar7 == 0) {

    uVar7 = 1;

    uVar3 = 0;

  }

  else if (uVar6 == 0) {

    uVar3 = 1;

    uVar6 = 1;

  }

  else if ((char)(uVar5 >> 0x10) == '\0') {

    uVar4 = 1;

    uVar3 = 2;

  }

  else if ((char)(uVar5 >> 0x18) == '\0') {

    uVar2 = 1;

    uVar3 = 3;

  }

  *param_3 = uVar7 - 1;

  *param_4 = uVar6 - 1;

  *param_5 = uVar4 - 1;

  *param_6 = uVar2 - 1;

  if (param_7 != (undefined4 *)0x0) {

    *param_7 = uVar3;

  }

  return;

}




