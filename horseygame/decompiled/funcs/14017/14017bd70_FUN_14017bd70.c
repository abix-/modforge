// Address: 0x14017bd70
// Ghidra name: FUN_14017bd70
// ============ 0x14017bd70 FUN_14017bd70 (size=395) ============


uint FUN_14017bd70(uint *param_1,longlong param_2,ulonglong param_3,byte param_4,byte param_5)



{

  uint uVar1;

  byte bVar2;

  uint uVar3;

  

  param_3 = param_3 & 0xff;

  if (param_1 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","format");

    return 0;

  }

  uVar1 = *param_1;

  if (uVar1 != 0) {

    if ((uVar1 & 0xf0000000) != 0x10000000) goto LAB_14017be7f;

    if (((int)uVar1 >> 0x18 & 0xfU) == 1) goto LAB_14017bdd9;

  }

  uVar3 = (int)uVar1 >> 0x18 & 0xf;

  if ((uVar3 == 0xc) || (uVar3 - 2 < 2)) {

LAB_14017bdd9:

    if (param_2 != 0) {

      bVar2 = FUN_14017a230(param_2,param_3,param_4,param_5,0xff);

      return (uint)bVar2;

    }

    FUN_14012e850("Parameter \'%s\' is invalid","palette");

    return 0;

  }

  if ((((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) &&

      (((byte)(uVar1 >> 0x18) & 0xf) == 6)) && ((uVar1 & 0xf0000) == 0x70000)) {

    return (uint)*(ushort *)(&DAT_140335c90 + param_3 * 2) << ((byte)param_1[7] & 0x1f) |

           (uint)*(ushort *)(&DAT_140335c90 + (ulonglong)param_4 * 2) <<

           (*(byte *)((longlong)param_1 + 0x1d) & 0x1f) |

           (uint)*(ushort *)(&DAT_140335c90 + (ulonglong)param_5 * 2) <<

           (*(byte *)((longlong)param_1 + 0x1e) & 0x1f) | param_1[5];

  }

LAB_14017be7f:

  return ((uint)param_3 >> (8U - (char)param_1[6] & 0x1f)) << ((byte)param_1[7] & 0x1f) |

         (uint)(param_4 >> (8U - *(char *)((longlong)param_1 + 0x19) & 0x1f)) <<

         (*(byte *)((longlong)param_1 + 0x1d) & 0x1f) |

         (uint)(param_5 >> (8U - *(char *)((longlong)param_1 + 0x1a) & 0x1f)) <<

         (*(byte *)((longlong)param_1 + 0x1e) & 0x1f) | param_1[5];

}




