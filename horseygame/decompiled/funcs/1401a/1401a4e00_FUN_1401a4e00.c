// Address: 0x1401a4e00
// Ghidra name: FUN_1401a4e00
// ============ 0x1401a4e00 FUN_1401a4e00 (size=584) ============


undefined8 FUN_1401a4e00(longlong param_1,byte *param_2,uint param_3)



{

  int *piVar1;

  byte bVar2;

  int iVar3;

  undefined8 uVar4;

  uint uVar5;

  uint uVar6;

  byte *pbVar7;

  ulonglong uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  longlong lVar12;

  int iVar13;

  int iVar14;

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

  

  iVar10 = 0;

  local_68 = 0;

  iVar9 = 0;

  local_a8 = 0;

  uStack_a0 = 0;

  local_98 = 0;

  uStack_90 = 0;

  local_88 = 0;

  uStack_80 = 0;

  local_78 = 0;

  uStack_70 = 0;

  FUN_1402f94c0(0,0,0x400);

  if (0 < (int)param_3) {

    uVar8 = (ulonglong)param_3;

    pbVar7 = param_2;

    do {

      bVar2 = *pbVar7;

      pbVar7 = pbVar7 + 1;

      piVar1 = (int *)((longlong)&local_a8 + (ulonglong)bVar2 * 4);

      *piVar1 = *piVar1 + 1;

      uVar8 = uVar8 - 1;

    } while (uVar8 != 0);

  }

  local_a8 = local_a8 & 0xffffffff00000000;

  uVar5 = 1;

  do {

    if (1 << ((byte)uVar5 & 0x1f) < *(int *)((longlong)&local_a8 + (ulonglong)uVar5 * 4)) {

      uVar4 = FUN_14019f050("Corrupt PNG");

      return uVar4;

    }

    uVar5 = uVar5 + 1;

  } while ((int)uVar5 < 0x10);

  uVar5 = 0;

  iVar13 = 1;

  iVar14 = 0xf;

  while( true ) {

    lVar12 = (longlong)iVar13;

    iVar3 = *(int *)((longlong)&local_a8 + lVar12 * 4);

    local_58[lVar12] = uVar5;

    *(short *)(param_1 + 0x400 + lVar12 * 2) = (short)uVar5;

    iVar11 = uVar5 + iVar3;

    *(short *)(param_1 + 0x464 + lVar12 * 2) = (short)iVar9;

    if ((iVar3 != 0) && (1 << ((byte)iVar13 & 0x1f) <= iVar11 + -1)) break;

    uVar5 = iVar11 * 2;

    iVar9 = iVar9 + iVar3;

    *(int *)(param_1 + 0x420 + lVar12 * 4) = iVar11 << ((byte)iVar14 & 0x1f);

    iVar13 = iVar13 + 1;

    iVar14 = iVar14 + -1;

    if (iVar14 < 1) {

      *(undefined4 *)(param_1 + 0x460) = 0x10000;

      if (0 < (int)param_3) {

        do {

          bVar2 = *param_2;

          uVar8 = (ulonglong)bVar2;

          if (bVar2 != 0) {

            uVar5 = local_58[uVar8];

            lVar12 = (longlong)

                     (int)(uVar5 + ((uint)*(ushort *)(param_1 + 0x464 + uVar8 * 2) -

                                   (uint)*(ushort *)(param_1 + 0x400 + uVar8 * 2)));

            *(byte *)(lVar12 + 0x484 + param_1) = bVar2;

            *(ushort *)(param_1 + 0x5a4 + lVar12 * 2) = (ushort)iVar10;

            if ((bVar2 < 10) &&

               (uVar6 = (int)uVar5 >> 1 & 0x5555U | (uVar5 & 0x5555) * 2,

               uVar6 = uVar6 >> 2 & 0x3333 | (uVar6 & 0x3333) << 2,

               uVar6 = uVar6 >> 4 & 0xf0f | (uVar6 & 0xf0f) << 4,

               iVar9 = (int)((uVar6 & 0xff) << 8 | uVar6 >> 8) >> (0x10 - bVar2 & 0x1f),

               iVar9 < 0x200)) {

              do {

                lVar12 = (longlong)iVar9;

                iVar9 = iVar9 + (1 << (bVar2 & 0x1f));

                *(ushort *)(param_1 + lVar12 * 2) = (ushort)bVar2 << 9 | (ushort)iVar10;

              } while (iVar9 < 0x200);

            }

            local_58[uVar8] = uVar5 + 1;

          }

          iVar10 = iVar10 + 1;

          param_2 = param_2 + 1;

        } while (iVar10 < (int)param_3);

      }

      return 1;

    }

  }

  uVar4 = FUN_14019f050("Corrupt PNG");

  return uVar4;

}




