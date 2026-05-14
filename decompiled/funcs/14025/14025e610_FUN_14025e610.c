// Address: 0x14025e610
// Ghidra name: FUN_14025e610
// ============ 0x14025e610 FUN_14025e610 (size=947) ============


undefined8

FUN_14025e610(longlong param_1,int param_2,int param_3,undefined4 param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint *puVar8;

  

  iVar4 = 0xff - (uint)param_8;

  uVar3 = 0xff;

  switch(param_4) {

  case 1:

    puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                     *(longlong *)(param_1 + 0x18));

    uVar3 = *puVar8;

    *puVar8 = (((uVar3 >> 8 & 0xff) * iVar4) / 0xff + (uint)param_6) * 0x100 |

              (((uVar3 >> 0x10 & 0xff) * iVar4) / 0xff + (uint)param_5) * 0x10000 |

              ((uVar3 & 0xff) * iVar4) / 0xff + (uint)param_7;

    return 1;

  case 2:

  case 0x20:

    puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                     *(longlong *)(param_1 + 0x18));

    uVar2 = (*puVar8 >> 0x10 & 0xff) + (uint)param_5;

    if (0xff < uVar2) {

      uVar2 = 0xff;

    }

    break;

  default:

    lVar1 = *(longlong *)(param_1 + 0x18);

    *(uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) + lVar1) =

         (uint)CONCAT21(CONCAT11(param_5,param_6),param_7);

    return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

  case 4:

    puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                     *(longlong *)(param_1 + 0x18));

    uVar3 = *puVar8;

    uVar2 = (uVar3 & 0xff) * (uint)param_7;

    *puVar8 = (((uVar3 >> 0x10 & 0xff) * (uint)param_5) / 0xff << 8 |

              ((uVar3 >> 8 & 0xff) * (uint)param_6) / 0xff) << 8 | uVar2 / 0xff;

    return CONCAT71((uint7)((ulonglong)uVar2 * 0x80808081 >> 8) & 0xffffff,1);

  case 8:

    puVar8 = (uint *)((longlong)(param_2 * 4) + (longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                     *(longlong *)(param_1 + 0x18));

    uVar2 = ((uint)param_5 * (uint)*(byte *)((longlong)puVar8 + 2)) / 0xff +

            ((uint)*(byte *)((longlong)puVar8 + 2) * iVar4) / 0xff;

    if (0xff < uVar2) {

      uVar2 = 0xff;

    }

    uVar5 = ((uint)param_6 * (uint)*(byte *)((longlong)puVar8 + 1)) / 0xff +

            ((uint)*(byte *)((longlong)puVar8 + 1) * iVar4) / 0xff;

    if (0xff < uVar5) {

      uVar5 = 0xff;

    }

    uVar7 = ((uint)param_7 * (uint)(byte)*puVar8) / 0xff + ((uint)(byte)*puVar8 * iVar4) / 0xff;

    if (0xff < uVar7) {

      uVar7 = uVar3;

    }

    *puVar8 = (uVar2 << 8 | uVar5) << 8 | uVar7;

    return CONCAT71((uint7)(uint3)(uVar7 >> 8),1);

  case 0x10:

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

    uVar2 = (uint)param_5 + ((*puVar8 >> 0x10 & 0xff) * iVar4) / 0xff;

    if (0xff < uVar2) {

      uVar2 = 0xff;

    }

    uVar5 = (uint)param_6 + ((uint)*(byte *)((longlong)puVar8 + 1) * iVar4) / 0xff;

    if (0xff < uVar5) {

      uVar5 = 0xff;

    }

    uVar6 = (*puVar8 & 0xff) * iVar4;

    uVar7 = (uint)param_7 + uVar6 / 0xff;

    if (0xff < uVar7) {

      uVar7 = uVar3;

    }

    *puVar8 = (uVar2 << 8 | uVar5) << 8 | uVar7;

    return CONCAT71((uint7)((ulonglong)uVar6 * 0x80808081 >> 8) & 0xffffff,1);

  }

  uVar5 = (uint)*(byte *)((longlong)puVar8 + 1) + (uint)param_6;

  if (0xff < uVar5) {

    uVar5 = 0xff;

  }

  uVar7 = (*puVar8 & 0xff) + (uint)param_7;

  if (0xff < uVar7) {

    uVar7 = uVar3;

  }

  *puVar8 = (uVar2 << 8 | uVar5) << 8 | uVar7;

  return 1;

}




