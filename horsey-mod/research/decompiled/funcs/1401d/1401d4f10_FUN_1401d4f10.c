// Address: 0x1401d4f10
// Ghidra name: FUN_1401d4f10
// ============ 0x1401d4f10 FUN_1401d4f10 (size=966) ============


ulonglong FUN_1401d4f10(int param_1,int param_2,undefined8 param_3,longlong param_4,

                       undefined8 param_5,int param_6,longlong param_7,undefined4 param_8)



{

  undefined1 *puVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  ulonglong uVar11;

  uint uVar12;

  undefined1 *puVar13;

  byte *pbVar14;

  byte *pbVar15;

  uint uVar16;

  undefined1 *puVar17;

  ulonglong uVar18;

  byte *pbVar19;

  longlong lVar20;

  undefined1 *puVar21;

  byte *pbVar22;

  undefined4 local_res20;

  undefined4 uStackX_24;

  int local_88;

  uint local_84;

  int local_80;

  byte *local_78;

  ulonglong local_70;

  ulonglong local_68;

  byte *local_60;

  undefined1 *local_58 [4];

  

  if (param_4 == param_7) {

    uVar11 = FUN_14012e850("Can\'t change YUV plane types in-place");

    return uVar11;

  }

  uVar11 = FUN_1401d4490();

  pbVar14 = local_60;

  pbVar15 = local_78;

  if ((char)uVar11 != '\0') {

    puVar21 = (undefined1 *)CONCAT44(uStackX_24,local_res20);

    pbVar22 = local_78 + (local_68 & 0xffffffff);

    pbVar19 = local_60 + (local_68 & 0xffffffff);

    puVar13 = puVar21 + (local_70 & 0xffffffff);

    iVar4 = (param_1 + 1) / 2;

    local_80 = (int)local_70 + iVar4 * -4;

    uVar11 = FUN_1401d4490(param_1,param_2,param_6,param_7,param_8,local_58,&local_78,&local_60,

                           &local_84,&local_88);

    if ((char)uVar11 != '\0') {

      uVar5 = local_84 * 2 - param_1;

      puVar17 = local_58[0] + local_84;

      if ((param_6 == 0x3231564e) || (param_6 == 0x3132564e)) {

        lVar20 = 2;

        iVar4 = iVar4 * -2;

      }

      else {

        lVar20 = 1;

        iVar4 = -iVar4;

      }

      uVar16 = local_88 + iVar4;

      uVar6 = 0;

      local_88 = 0;

      uVar7 = param_2 - 1;

      iVar4 = param_1 + -1;

      if (0 < (int)uVar7) {

        uVar8 = (int)local_70 + local_80;

        uVar12 = local_80 + (int)local_68;

        uVar6 = (param_2 - 2U >> 1) + 1;

        local_70 = (ulonglong)uVar6;

        uVar6 = uVar6 * 2;

        do {

          iVar9 = 0;

          if (0 < iVar4) {

            uVar10 = (param_1 - 2U >> 1) + 1;

            local_68 = (ulonglong)uVar10;

            iVar9 = uVar10 * 2;

            do {

              *local_58[0] = *puVar21;

              puVar1 = puVar21 + 2;

              puVar21 = puVar21 + 4;

              local_58[0][1] = *puVar1;

              local_58[0] = local_58[0] + 2;

              *puVar17 = *puVar13;

              puVar1 = puVar13 + 2;

              puVar13 = puVar13 + 4;

              puVar17[1] = *puVar1;

              puVar17 = puVar17 + 2;

              bVar2 = *pbVar15;

              pbVar15 = pbVar15 + 4;

              bVar3 = *pbVar22;

              pbVar22 = pbVar22 + 4;

              *local_78 = (byte)((uint)bVar3 + (uint)bVar2 >> 1);

              local_78 = local_78 + lVar20;

              bVar2 = *pbVar14;

              pbVar14 = pbVar14 + 4;

              bVar3 = *pbVar19;

              pbVar19 = pbVar19 + 4;

              *local_60 = (byte)((uint)bVar2 + (uint)bVar3 >> 1);

              local_60 = local_60 + lVar20;

              local_68 = local_68 - 1;

            } while (local_68 != 0);

          }

          if (iVar9 == iVar4) {

            *local_58[0] = *puVar21;

            puVar1 = puVar21 + 2;

            puVar21 = puVar21 + 4;

            *local_58[0] = *puVar1;

            local_58[0] = local_58[0] + 1;

            *puVar17 = *puVar13;

            puVar1 = puVar13 + 2;

            puVar13 = puVar13 + 4;

            *puVar17 = *puVar1;

            puVar17 = puVar17 + 1;

            bVar2 = *pbVar15;

            pbVar15 = pbVar15 + 4;

            bVar3 = *pbVar22;

            pbVar22 = pbVar22 + 4;

            *local_78 = (byte)((uint)bVar3 + (uint)bVar2 >> 1);

            local_78 = local_78 + lVar20;

            bVar2 = *pbVar14;

            pbVar14 = pbVar14 + 4;

            bVar3 = *pbVar19;

            pbVar19 = pbVar19 + 4;

            *local_60 = (byte)((uint)bVar2 + (uint)bVar3 >> 1);

            local_60 = local_60 + lVar20;

          }

          puVar21 = puVar21 + uVar8;

          pbVar15 = pbVar15 + uVar12;

          puVar13 = puVar13 + uVar8;

          pbVar22 = pbVar22 + uVar12;

          local_58[0] = local_58[0] + uVar5;

          pbVar14 = pbVar14 + uVar12;

          puVar17 = puVar17 + uVar5;

          pbVar19 = pbVar19 + uVar12;

          local_78 = local_78 + uVar16;

          local_60 = local_60 + uVar16;

          local_70 = local_70 - 1;

        } while (local_70 != 0);

      }

      uVar11 = (ulonglong)uVar7;

      if (uVar6 == uVar7) {

        if (0 < iVar4) {

          uVar5 = (param_1 - 2U >> 1) + 1;

          uVar18 = (ulonglong)uVar5;

          local_88 = uVar5 * 2;

          do {

            *local_58[0] = *puVar21;

            puVar13 = puVar21 + 2;

            puVar21 = puVar21 + 4;

            local_58[0][1] = *puVar13;

            local_58[0] = local_58[0] + 2;

            bVar2 = *pbVar15;

            pbVar15 = pbVar15 + 4;

            *local_78 = bVar2;

            local_78 = local_78 + lVar20;

            bVar2 = *pbVar14;

            uVar11 = 0;

            pbVar14 = pbVar14 + 4;

            *local_60 = bVar2;

            local_60 = local_60 + lVar20;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

        if (local_88 == param_1 + -1) {

          *local_58[0] = *puVar21;

          *local_78 = *pbVar15;

          uVar11 = 0;

          *local_60 = *pbVar14;

        }

      }

      return CONCAT71((int7)(uVar11 >> 8),1);

    }

  }

  return uVar11 & 0xffffffffffffff00;

}




