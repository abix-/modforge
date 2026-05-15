// Address: 0x14025c160
// Ghidra name: FUN_14025c160
// ============ 0x14025c160 FUN_14025c160 (size=986) ============


undefined8

FUN_14025c160(longlong param_1,int param_2,int param_3,undefined4 param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  ulonglong uVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint *puVar8;

  

  iVar4 = 0xff - (uint)param_8;

  uVar5 = 0xff;

  uVar2 = 0xff;

  switch(param_4) {

  case 1:

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

    uVar5 = *puVar8;

    uVar2 = (uVar5 >> 0x18) * iVar4;

    uVar1 = (ulonglong)uVar2 * 0x80808081 & 0xffffffff;

    *puVar8 = (((uVar5 >> 8 & 0xff) * iVar4) / 0xff + (uint)param_6) * 0x100 |

              (((uVar5 >> 0x10 & 0xff) * iVar4) / 0xff + (uint)param_5) * 0x10000 |

              ((uVar5 & 0xff) * iVar4) / 0xff + (uint)param_7 |

              (uVar2 / 0xff + (uint)param_8) * 0x1000000;

    break;

  case 2:

  case 0x20:

    puVar8 = (uint *)((longlong)(param_2 * 4) + (longlong)(param_3 * *(int *)(param_1 + 0x10)) +

                     *(longlong *)(param_1 + 0x18));

    uVar7 = *puVar8;

    uVar3 = (uVar7 >> 0x10 & 0xff) + (uint)param_5;

    if (0xff < uVar3) {

      uVar3 = uVar5;

    }

    uVar5 = (uint)*(byte *)((longlong)puVar8 + 1) + (uint)param_6;

    uVar1 = 0;

    if (0xff < uVar5) {

      uVar5 = uVar2;

    }

    uVar6 = (uVar7 & 0xff) + (uint)param_7;

    if (0xff < uVar6) {

      uVar6 = uVar2;

    }

    *puVar8 = (((uVar7 >> 0x18) << 8 | uVar3) << 8 | uVar5) << 8 | uVar6;

    break;

  default:

    uVar1 = *(ulonglong *)(param_1 + 0x18);

    *(uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) + uVar1) =

         CONCAT31(CONCAT21(CONCAT11(param_8,param_5),param_6),param_7);

    break;

  case 4:

    puVar8 = (uint *)(*(longlong *)(param_1 + 0x18) +

                     (longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4));

    uVar5 = *puVar8;

    uVar2 = (uVar5 & 0xff) * (uint)param_7;

    uVar1 = (ulonglong)uVar2 * 0x80808081 & 0xffffffff;

    *puVar8 = (((uVar5 >> 0x10 & 0xff) * (uint)param_5) / 0xff << 8 |

              ((uVar5 >> 8 & 0xff) * (uint)param_6) / 0xff) << 8 | uVar2 / 0xff | uVar5 & 0xff000000

    ;

    break;

  case 8:

    puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                     *(longlong *)(param_1 + 0x18));

    uVar7 = *puVar8 & 0xff;

    uVar2 = ((uint)param_5 * (uint)*(byte *)((longlong)puVar8 + 2)) / 0xff +

            ((uint)*(byte *)((longlong)puVar8 + 2) * iVar4) / 0xff;

    if (0xff < uVar2) {

      uVar2 = uVar5;

    }

    uVar3 = ((uint)param_6 * (uint)*(byte *)((longlong)puVar8 + 1)) / 0xff +

            ((uint)*(byte *)((longlong)puVar8 + 1) * iVar4) / 0xff;

    if (0xff < uVar3) {

      uVar3 = uVar5;

    }

    uVar5 = (param_7 * uVar7) / 0xff + (uVar7 * iVar4) / 0xff;

    if (0xff < uVar5) {

      uVar5 = 0xff;

    }

    uVar1 = (ulonglong)uVar5;

    *puVar8 = (((*puVar8 >> 0x18) << 8 | uVar2) << 8 | uVar3) << 8 | uVar5;

    break;

  case 0x10:

    puVar8 = (uint *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

                     *(longlong *)(param_1 + 0x18));

    uVar7 = *puVar8;

    uVar3 = (uint)param_5 + ((uVar7 >> 0x10 & 0xff) * iVar4) / 0xff;

    if (0xff < uVar3) {

      uVar3 = uVar2;

    }

    uVar6 = (uint)param_6 + ((uint)*(byte *)((longlong)puVar8 + 1) * iVar4) / 0xff;

    if (0xff < uVar6) {

      uVar6 = uVar2;

    }

    uVar2 = (uint)param_7 + ((uVar7 & 0xff) * iVar4) / 0xff;

    if (0xff < uVar2) {

      uVar2 = uVar5;

    }

    uVar5 = ((uVar7 >> 0x18) * iVar4) / 0xff + (uint)param_8;

    if (0xff < uVar5) {

      uVar5 = 0xff;

    }

    uVar2 = ((uVar5 << 8 | uVar3) << 8 | uVar6) << 8 | uVar2;

    uVar1 = (ulonglong)uVar2;

    *puVar8 = uVar2;

  }

  return CONCAT71((int7)(uVar1 >> 8),1);

}




