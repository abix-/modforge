// Address: 0x1400f03f0
// Ghidra name: FUN_1400f03f0
// ============ 0x1400f03f0 FUN_1400f03f0 (size=538) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400f03f0(longlong param_1,byte *param_2,uint param_3)



{

  int *piVar1;

  byte bVar2;

  int iVar3;

  uint uVar4;

  byte *pbVar5;

  ulonglong uVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  longlong lVar11;

  int iVar12;

  int iVar13;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined4 local_68;

  uint local_58 [16];

  

  iVar8 = 0;

  local_68 = 0;

  iVar7 = 0;

  local_a8 = 0;

  uStack_a0 = 0;

  local_98 = 0;

  uStack_90 = 0;

  local_88 = 0;

  uStack_80 = 0;

  local_78 = 0;

  uStack_70 = 0;

  FUN_1402f94c0(0,0xff,0x400);

  if (0 < (int)param_3) {

    uVar6 = (ulonglong)param_3;

    pbVar5 = param_2;

    do {

      bVar2 = *pbVar5;

      pbVar5 = pbVar5 + 1;

      piVar1 = (int *)((longlong)&local_a8 + (ulonglong)bVar2 * 4);

      *piVar1 = *piVar1 + 1;

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  local_a8 = local_a8 & 0xffffffff00000000;

  uVar9 = 0;

  iVar12 = 1;

  iVar13 = 0xf;

  while( true ) {

    lVar11 = (longlong)iVar12;

    iVar3 = *(int *)((longlong)&local_a8 + lVar11 * 4);

    local_58[lVar11] = uVar9;

    *(short *)(param_1 + 0x400 + lVar11 * 2) = (short)uVar9;

    iVar10 = uVar9 + iVar3;

    *(short *)(param_1 + 0x464 + lVar11 * 2) = (short)iVar7;

    if ((iVar3 != 0) && (1 << ((byte)iVar12 & 0x1f) <= iVar10 + -1)) break;

    uVar9 = iVar10 * 2;

    iVar7 = iVar7 + iVar3;

    *(int *)(param_1 + 0x420 + lVar11 * 4) = iVar10 << ((byte)iVar13 & 0x1f);

    iVar12 = iVar12 + 1;

    iVar13 = iVar13 + -1;

    if (iVar13 < 1) {

      *(undefined4 *)(param_1 + 0x460) = 0x10000;

      if (0 < (int)param_3) {

        do {

          bVar2 = *param_2;

          uVar6 = (ulonglong)bVar2;

          if (bVar2 != 0) {

            uVar9 = local_58[uVar6];

            iVar7 = ((uint)*(ushort *)(param_1 + 0x464 + uVar6 * 2) -

                    (uint)*(ushort *)(param_1 + 0x400 + uVar6 * 2)) + uVar9;

            *(byte *)((longlong)iVar7 + 0x484 + param_1) = bVar2;

            *(short *)(param_1 + 0x5a4 + (longlong)iVar7 * 2) = (short)iVar8;

            if ((bVar2 < 10) &&

               (uVar4 = (int)uVar9 >> 1 & 0x5555U | (uVar9 & 0x5555) * 2,

               uVar4 = uVar4 >> 2 & 0x3333 | (uVar4 & 0x3333) << 2,

               uVar4 = uVar4 >> 4 & 0xf0f | (uVar4 & 0xf0f) << 4,

               iVar12 = (int)((uVar4 & 0xff) << 8 | uVar4 >> 8) >> (0x10 - bVar2 & 0x1f),

               iVar12 < 0x200)) {

              do {

                lVar11 = (longlong)iVar12;

                iVar12 = iVar12 + (1 << (bVar2 & 0x1f));

                *(short *)(param_1 + lVar11 * 2) = (short)iVar7;

              } while (iVar12 < 0x200);

            }

            local_58[uVar6] = uVar9 + 1;

          }

          iVar8 = iVar8 + 1;

          param_2 = param_2 + 1;

        } while (iVar8 < (int)param_3);

      }

      return 1;

    }

  }

  _DAT_1403f4c40 = "bad codelengths";

  return 0;

}




