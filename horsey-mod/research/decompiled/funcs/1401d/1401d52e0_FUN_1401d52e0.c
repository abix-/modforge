// Address: 0x1401d52e0
// Ghidra name: FUN_1401d52e0
// ============ 0x1401d52e0 FUN_1401d52e0 (size=937) ============


ulonglong FUN_1401d52e0(int param_1,int param_2,int param_3,longlong param_4,undefined8 param_5,

                       undefined4 param_6,longlong param_7,undefined4 param_8)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  longlong lVar3;

  int iVar4;

  ulonglong uVar5;

  undefined1 *puVar6;

  uint uVar7;

  undefined1 *puVar8;

  undefined1 *puVar9;

  undefined1 *puVar10;

  undefined1 *puVar11;

  uint uVar12;

  int iVar13;

  undefined1 *puVar14;

  longlong lVar15;

  uint uVar16;

  uint uVar17;

  undefined1 *puVar18;

  undefined1 *puVar19;

  int local_res20;

  undefined4 uStackX_24;

  uint local_88;

  ulonglong local_80;

  undefined4 local_78;

  undefined4 uStack_74;

  int local_70;

  undefined4 uStack_6c;

  int local_68;

  undefined4 uStack_64;

  ulonglong local_60;

  undefined1 *local_58;

  undefined1 *local_50;

  

  lVar3 = param_7;

  if (param_4 == param_7) {

    uVar5 = FUN_14012e850("Can\'t change YUV plane types in-place");

    return uVar5;

  }

  uVar5 = FUN_1401d4490();

  if ((char)uVar5 != '\0') {

    puVar8 = (undefined1 *)CONCAT44(uStackX_24,local_res20);

    puVar9 = puVar8 + local_88;

    local_60 = CONCAT44(local_60._4_4_,local_88 - param_1);

    if ((param_3 == 0x3231564e) || (param_3 == 0x3132564e)) {

      lVar15 = 2;

      local_res20 = (param_1 + 1) / 2;

      iVar4 = local_res20 * 2;

    }

    else {

      lVar15 = 1;

      iVar4 = (param_1 + 1) / 2;

      local_res20 = iVar4;

    }

    uVar16 = (uint)param_7 - iVar4;

    uVar5 = FUN_1401d4490(param_1,param_2,param_6,lVar3,param_8,&local_68,&local_70,&local_78,

                          &param_7,&local_80);

    if ((char)uVar5 != '\0') {

      puVar14 = (undefined1 *)CONCAT44(uStack_6c,local_70);

      puVar10 = (undefined1 *)CONCAT44(uStack_74,local_78);

      puVar11 = (undefined1 *)CONCAT44(uStack_64,local_68);

      puVar18 = puVar14 + (local_80 & 0xffffffff);

      puVar19 = puVar10 + (local_80 & 0xffffffff);

      puVar6 = puVar11 + (uint)param_7;

      iVar13 = (uint)param_7 + local_res20 * -4;

      local_68 = 0;

      local_70 = 0;

      iVar4 = param_1 + -1;

      if (0 < param_2 + -1) {

        uVar12 = (int)local_60 + local_88;

        param_7._0_4_ = (uint)param_7 + iVar13;

        uVar17 = (int)local_80 + iVar13;

        uVar7 = (param_2 - 2U >> 1) + 1;

        local_60 = (ulonglong)uVar7;

        local_70 = uVar7 * 2;

        do {

          iVar13 = 0;

          if (0 < iVar4) {

            uVar7 = (param_1 - 2U >> 1) + 1;

            uVar5 = (ulonglong)uVar7;

            iVar13 = uVar7 * 2;

            do {

              *puVar11 = *puVar8;

              puVar1 = puVar8 + 1;

              puVar8 = puVar8 + 2;

              puVar11[2] = *puVar1;

              puVar11 = puVar11 + 4;

              *puVar14 = *local_58;

              puVar14 = puVar14 + 4;

              *puVar10 = *local_50;

              puVar10 = puVar10 + 4;

              *puVar6 = *puVar9;

              puVar1 = puVar9 + 1;

              puVar9 = puVar9 + 2;

              puVar6[2] = *puVar1;

              puVar6 = puVar6 + 4;

              uVar2 = *local_58;

              local_58 = local_58 + lVar15;

              *puVar18 = uVar2;

              puVar18 = puVar18 + 4;

              uVar2 = *local_50;

              local_50 = local_50 + lVar15;

              *puVar19 = uVar2;

              puVar19 = puVar19 + 4;

              uVar5 = uVar5 - 1;

            } while (uVar5 != 0);

          }

          if (iVar13 == iVar4) {

            *puVar11 = *puVar8;

            uVar2 = *puVar8;

            puVar8 = puVar8 + 1;

            puVar11[2] = uVar2;

            puVar11 = puVar11 + 4;

            *puVar14 = *local_58;

            puVar14 = puVar14 + 4;

            *puVar10 = *local_50;

            puVar10 = puVar10 + 4;

            *puVar6 = *puVar9;

            uVar2 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar6[2] = uVar2;

            puVar6 = puVar6 + 4;

            uVar2 = *local_58;

            local_58 = local_58 + lVar15;

            *puVar18 = uVar2;

            puVar18 = puVar18 + 4;

            uVar2 = *local_50;

            local_50 = local_50 + lVar15;

            *puVar19 = uVar2;

            puVar19 = puVar19 + 4;

          }

          puVar14 = puVar14 + uVar17;

          puVar8 = puVar8 + uVar12;

          puVar18 = puVar18 + uVar17;

          puVar9 = puVar9 + uVar12;

          puVar10 = puVar10 + uVar17;

          local_58 = local_58 + uVar16;

          puVar19 = puVar19 + uVar17;

          local_50 = local_50 + uVar16;

          puVar11 = puVar11 + (uint)param_7;

          puVar6 = puVar6 + (uint)param_7;

          local_60 = local_60 - 1;

        } while (local_60 != 0);

      }

      if (local_70 == param_2 + -1) {

        if (0 < iVar4) {

          uVar16 = (param_1 - 2U >> 1) + 1;

          uVar5 = (ulonglong)uVar16;

          local_68 = uVar16 * 2;

          do {

            *puVar11 = *puVar8;

            puVar9 = puVar8 + 1;

            puVar8 = puVar8 + 2;

            puVar11[2] = *puVar9;

            puVar11 = puVar11 + 4;

            uVar2 = *local_58;

            local_58 = local_58 + lVar15;

            *puVar14 = uVar2;

            puVar14 = puVar14 + 4;

            uVar2 = *local_50;

            puVar6 = (undefined1 *)0x0;

            local_50 = local_50 + lVar15;

            *puVar10 = uVar2;

            puVar10 = puVar10 + 4;

            uVar5 = uVar5 - 1;

          } while (uVar5 != 0);

        }

        if (local_68 == param_1 + -1) {

          *puVar11 = *puVar8;

          puVar11[2] = *puVar8;

          *puVar14 = *local_58;

          puVar6 = (undefined1 *)0x0;

          *puVar10 = *local_50;

        }

      }

      return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);

    }

  }

  return uVar5 & 0xffffffffffffff00;

}




