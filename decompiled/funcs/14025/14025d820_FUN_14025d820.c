// Address: 0x14025d820
// Ghidra name: FUN_14025d820
// ============ 0x14025d820 FUN_14025d820 (size=1254) ============


undefined8

FUN_14025d820(longlong param_1,int param_2,int param_3,undefined4 param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  byte bVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  ushort uVar5;

  ushort uVar6;

  ushort uVar7;

  uint uVar8;

  ushort *puVar9;

  

  iVar4 = 0xff - (uint)param_8;

  uVar3 = 0xff;

  switch(param_4) {

  case 1:

    puVar9 = (ushort *)

             ((longlong)(param_2 * 2) + (longlong)(param_3 * *(int *)(param_1 + 0x10)) +

             *(longlong *)(param_1 + 0x18));

    uVar5 = *puVar9;

    *puVar9 = ((short)(((uint)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f] * iVar4) / 0xff) +

              (ushort)param_6) * 8 & 0xffe0 |

              ((short)((ulonglong)((uint)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb] * iVar4) / 0xff) +

              (ushort)param_5) * 0x100 & 0xf81f |

              (ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar5 & 0x1f] * iVar4) / 0xff + (uint)param_7

                      >> 3);

    return 1;

  case 2:

  case 0x20:

    puVar9 = (ushort *)

             ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

             *(longlong *)(param_1 + 0x18));

    uVar5 = *puVar9;

    uVar7 = (ushort)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb] + (ushort)param_5;

    if (0xff < uVar7) {

      uVar7 = 0xff;

    }

    break;

  default:

    lVar2 = *(longlong *)(param_1 + 0x18);

    *(ushort *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) + lVar2) =

         ((param_5 & 0xfff8) << 5 | param_6 & 0xfffc) << 3 | (ushort)(param_7 >> 3);

    return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

  case 4:

    puVar9 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2));

    uVar5 = *puVar9;

    bVar1 = PTR_DAT_1403e28c8[uVar5 & 0x1f];

    *puVar9 = (((ushort)(((uint)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb] * (uint)param_5) / 0xff) &

               0xfff8) << 5 |

              (ushort)((ulonglong)((uint)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f] * (uint)param_6)

                      / 0xff) & 0xfffc) << 3 |

              (ushort)((ulonglong)((uint)bVar1 * (uint)param_7) / 0xff >> 3);

    return CONCAT71((uint7)((ulonglong)((uint)bVar1 * (uint)param_7) * 0x80808081 >> 8) & 0xffffff,1

                   );

  case 8:

    puVar9 = (ushort *)

             ((longlong)(param_2 * 2) + (longlong)(param_3 * *(int *)(param_1 + 0x10)) +

             *(longlong *)(param_1 + 0x18));

    uVar5 = *puVar9;

    uVar8 = ((uint)param_5 * (uint)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb]) / 0xff +

            ((uint)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb] * iVar4) / 0xff;

    uVar7 = (ushort)uVar8;

    if (0xff < uVar8) {

      uVar7 = 0xff;

    }

    uVar8 = ((uint)param_6 * (uint)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f]) / 0xff +

            ((uint)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f] * iVar4) / 0xff;

    uVar6 = (ushort)uVar8;

    if (0xff < uVar8) {

      uVar6 = 0xff;

    }

    uVar8 = ((uint)param_7 * (uint)(byte)PTR_DAT_1403e28c8[uVar5 & 0x1f]) / 0xff +

            ((uint)(byte)PTR_DAT_1403e28c8[uVar5 & 0x1f] * iVar4) / 0xff;

    if (0xff < uVar8) {

      uVar8 = uVar3;

    }

    *puVar9 = ((uVar7 & 0xfff8) << 5 | uVar6 & 0xfffc) << 3 | (ushort)(uVar8 >> 3);

    return CONCAT71((uint7)(uint3)(uVar8 >> 0xb),1);

  case 0x10:

    puVar9 = (ushort *)

             (*(longlong *)(param_1 + 0x18) +

             (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2));

    uVar5 = *puVar9;

    bVar1 = PTR_DAT_1403e28c8[uVar5 & 0x1f];

    uVar8 = (uint)param_5 + ((uint)(byte)PTR_DAT_1403e28c8[uVar5 >> 0xb] * iVar4) / 0xff;

    uVar7 = (ushort)uVar8;

    if (0xff < uVar8) {

      uVar7 = 0xff;

    }

    uVar8 = (uint)param_6 + ((uint)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f] * iVar4) / 0xff;

    uVar5 = (ushort)uVar8;

    if (0xff < uVar8) {

      uVar5 = 0xff;

    }

    uVar8 = (uint)param_7 + ((uint)bVar1 * iVar4) / 0xff;

    if (0xff < uVar8) {

      uVar8 = uVar3;

    }

    *puVar9 = ((uVar7 & 0xfff8) << 5 | uVar5 & 0xfffc) << 3 | (ushort)(uVar8 >> 3);

    return CONCAT71((uint7)((ulonglong)((uint)bVar1 * iVar4) * 0x80808081 >> 8) & 0xffffff,1);

  }

  uVar6 = (ushort)(byte)PTR_DAT_1403e28d0[uVar5 >> 5 & 0x3f] + (ushort)param_6;

  if (0xff < uVar6) {

    uVar6 = 0xff;

  }

  uVar8 = (uint)(byte)PTR_DAT_1403e28c8[uVar5 & 0x1f] + (uint)param_7;

  if (0xff < (uint)(byte)PTR_DAT_1403e28c8[uVar5 & 0x1f] + (uint)param_7) {

    uVar8 = uVar3;

  }

  *puVar9 = ((uVar7 & 0xfff8) << 5 | uVar6 & 0xfffc) << 3 | (ushort)(uVar8 >> 3);

  return 1;

}




