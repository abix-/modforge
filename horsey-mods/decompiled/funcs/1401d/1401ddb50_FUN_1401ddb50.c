// Address: 0x1401ddb50
// Ghidra name: FUN_1401ddb50
// ============ 0x1401ddb50 FUN_1401ddb50 (size=361) ============


undefined8 FUN_1401ddb50(undefined8 param_1,longlong param_2,uint *param_3,int param_4)



{

  uint *puVar1;

  float fVar2;

  uint uVar3;

  uint *puVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  int iVar7;

  uint uVar8;

  longlong lVar9;

  

  fVar2 = *(float *)(param_2 + 0x18);

  lVar9 = (longlong)param_4 * 0x18;

  uVar8 = (((uint)(longlong)(fVar2 * *(float *)(param_2 + 0x1c) * DAT_14030a2d0) & 0xff |

           (int)(longlong)(*(float *)(param_2 + 0x28) * DAT_14030a2d0) << 8) << 8 |

          (uint)(longlong)(fVar2 * *(float *)(param_2 + 0x20) * DAT_14030a2d0) & 0xff) << 8 |

          (uint)(longlong)(fVar2 * *(float *)(param_2 + 0x24) * DAT_14030a2d0) & 0xff;

  puVar4 = (uint *)FUN_14014b940(param_1,lVar9,0,param_2 + 8);

  uVar5 = 0;

  if (puVar4 != (uint *)0x0) {

    FUN_1402f94c0(puVar4,0,lVar9);

    iVar7 = 0;

    *(longlong *)(param_2 + 0x10) = (longlong)param_4;

    if (3 < param_4) {

      uVar3 = (param_4 - 4U >> 2) + 1;

      uVar6 = (ulonglong)uVar3;

      iVar7 = uVar3 * 4;

      do {

        *puVar4 = *param_3;

        puVar4[1] = param_3[1];

        puVar4[3] = uVar8;

        puVar4[6] = param_3[2];

        puVar4[7] = param_3[3];

        puVar4[9] = uVar8;

        puVar4[0xc] = param_3[4];

        puVar4[0xd] = param_3[5];

        puVar4[0xf] = uVar8;

        puVar4[0x12] = param_3[6];

        puVar1 = param_3 + 7;

        param_3 = param_3 + 8;

        puVar4[0x13] = *puVar1;

        puVar4[0x15] = uVar8;

        puVar4 = puVar4 + 0x18;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (iVar7 < param_4) {

      uVar6 = (ulonglong)(uint)(param_4 - iVar7);

      puVar4 = puVar4 + 3;

      do {

        puVar4[-3] = *param_3;

        puVar4[-2] = param_3[1];

        *puVar4 = uVar8;

        uVar6 = uVar6 - 1;

        param_3 = param_3 + 2;

        puVar4 = puVar4 + 6;

      } while (uVar6 != 0);

    }

    uVar5 = 1;

  }

  return uVar5;

}




