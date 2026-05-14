// Address: 0x1402f447c
// Ghidra name: FUN_1402f447c
// ============ 0x1402f447c FUN_1402f447c (size=712) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8 FUN_1402f447c(int param_1,longlong param_2)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  uint uVar4;

  BOOL BVar5;

  uint *puVar6;

  byte *pbVar7;

  undefined *puVar8;

  longlong lVar9;

  BYTE *pBVar10;

  ulonglong uVar11;

  byte *pbVar12;

  undefined2 *puVar13;

  undefined *puVar14;

  undefined *puVar15;

  undefined4 uVar16;

  uint uVar17;

  uint uVar18;

  byte *pbVar19;

  undefined1 auStack_68 [32];

  _cpinfo local_48;

  ulonglong local_30;

  

  local_30 = DAT_1403e8b00 ^ (ulonglong)auStack_68;

  local_48.MaxCharSize = 0;

  local_48.DefaultChar[0] = '\0';

  local_48.DefaultChar[1] = '\0';

  local_48.LeadByte[0] = '\0';

  local_48.LeadByte[1] = '\0';

  local_48.LeadByte[2] = '\0';

  local_48.LeadByte[3] = '\0';

  local_48.LeadByte[4] = '\0';

  local_48.LeadByte[5] = '\0';

  local_48.LeadByte[6] = '\0';

  local_48.LeadByte[7] = '\0';

  local_48.LeadByte[8] = '\0';

  local_48.LeadByte[9] = '\0';

  local_48.LeadByte[10] = '\0';

  local_48.LeadByte[0xb] = '\0';

  local_48._18_2_ = 0;

  uVar4 = getSystemCP(param_1);

  puVar14 = (undefined *)0x0;

  if (uVar4 == 0) {

LAB_1402f4714:

    FUN_1402f3e48(param_2);

    return 0;

  }

  puVar6 = &DAT_1403e95f0;

  uVar16 = 1;

  puVar8 = puVar14;

  do {

    if (*puVar6 == uVar4) {

      FUN_1402f94c0(param_2 + 0x18,0,0x101);

      pbVar19 = &DAT_1403e95e0;

      lVar9 = 4;

      pbVar7 = &DAT_1403e9600 + (longlong)puVar8 * 0x30;

      do {

        bVar2 = *pbVar7;

        pbVar12 = pbVar7;

        while ((bVar2 != 0 && (pbVar12[1] != 0))) {

          bVar2 = *pbVar12;

          uVar18 = (uint)bVar2;

          if (bVar2 <= pbVar12[1]) {

            uVar17 = (uint)bVar2;

            do {

              uVar17 = uVar17 + 1;

              if (0x100 < uVar17) break;

              uVar18 = uVar18 + 1;

              pbVar1 = (byte *)((ulonglong)uVar17 + 0x18 + param_2);

              *pbVar1 = *pbVar1 | *pbVar19;

            } while (uVar18 <= pbVar12[1]);

          }

          pbVar12 = pbVar12 + 2;

          bVar2 = *pbVar12;

        }

        pbVar7 = pbVar7 + 8;

        pbVar19 = pbVar19 + 1;

        lVar9 = lVar9 + -1;

      } while (lVar9 != 0);

      *(uint *)(param_2 + 4) = uVar4;

      *(undefined4 *)(param_2 + 8) = 1;

      puVar15 = PTR_u_ja_JP_1403959b8;

      if (((uVar4 != 0x3a4) && (puVar15 = PTR_u_zh_CN_1403959c0, uVar4 != 0x3a8)) &&

         ((puVar15 = PTR_u_ko_KR_1403959c8, uVar4 != 0x3b5 && (puVar15 = puVar14, uVar4 == 0x3b6))))

      {

        puVar15 = PTR_u_zh_TW_1403959d0;

      }

      *(undefined **)(param_2 + 0x220) = puVar15;

      puVar13 = (undefined2 *)(param_2 + 0xc);

      lVar9 = 6;

      do {

        *puVar13 = *(undefined2 *)

                    (((longlong)puVar8 * 0x30 - param_2) + 0x1403e95e8 + (longlong)puVar13);

        puVar13 = puVar13 + 1;

        lVar9 = lVar9 + -1;

      } while (lVar9 != 0);

      goto LAB_1402f470a;

    }

    uVar18 = (int)puVar8 + 1;

    puVar8 = (undefined *)(ulonglong)uVar18;

    puVar6 = puVar6 + 0xc;

  } while (uVar18 < 5);

  if ((uVar4 == 65000) || (BVar5 = IsValidCodePage(uVar4 & 0xffff), BVar5 == 0)) {

    return 0xffffffff;

  }

  if (uVar4 == 0xfde9) {

    *(undefined8 *)(param_2 + 4) = 0xfde9;

    *(undefined8 *)(param_2 + 0x220) = 0;

    *(undefined4 *)(param_2 + 0x18) = 0;

    *(undefined2 *)(param_2 + 0x1c) = 0;

  }

  else {

    BVar5 = GetCPInfo(uVar4,&local_48);

    if (BVar5 == 0) {

      if (DAT_1403ff768 == 0) {

        return 0xffffffff;

      }

      goto LAB_1402f4714;

    }

    FUN_1402f94c0(param_2 + 0x18,0,0x101);

    *(uint *)(param_2 + 4) = uVar4;

    *(undefined8 *)(param_2 + 0x220) = 0;

    if (local_48.MaxCharSize == 2) {

      pBVar10 = local_48.LeadByte;

      bVar2 = local_48.LeadByte[0];

      while ((bVar2 != 0 && (pBVar10[1] != 0))) {

        bVar2 = *pBVar10;

        if ((uint)bVar2 <= (uint)pBVar10[1]) {

          uVar4 = (uint)bVar2;

          uVar11 = (ulonglong)(((uint)pBVar10[1] - (uint)bVar2) + 1);

          do {

            uVar4 = uVar4 + 1;

            pbVar7 = (byte *)((ulonglong)uVar4 + 0x18 + param_2);

            *pbVar7 = *pbVar7 | 4;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        pBVar10 = pBVar10 + 2;

        bVar2 = *pBVar10;

      }

      pbVar7 = (byte *)(param_2 + 0x1a);

      lVar9 = 0xfe;

      do {

        *pbVar7 = *pbVar7 | 8;

        pbVar7 = pbVar7 + 1;

        lVar9 = lVar9 + -1;

      } while (lVar9 != 0);

      iVar3 = *(int *)(param_2 + 4);

      puVar8 = PTR_u_ja_JP_1403959b8;

      if ((((iVar3 != 0x3a4) && (puVar8 = PTR_u_zh_CN_1403959c0, iVar3 != 0x3a8)) &&

          (puVar8 = PTR_u_ko_KR_1403959c8, iVar3 != 0x3b5)) &&

         (puVar8 = PTR_u_zh_TW_1403959d0, iVar3 != 0x3b6)) {

        puVar8 = puVar14;

      }

      *(undefined **)(param_2 + 0x220) = puVar8;

    }

    else {

      uVar16 = 0;

    }

    *(undefined4 *)(param_2 + 8) = uVar16;

  }

  puVar13 = (undefined2 *)(param_2 + 0xc);

  for (lVar9 = 6; lVar9 != 0; lVar9 = lVar9 + -1) {

    *puVar13 = 0;

    puVar13 = puVar13 + 1;

  }

LAB_1402f470a:

  FUN_1402f3ee0(param_2);

  return 0;

}




