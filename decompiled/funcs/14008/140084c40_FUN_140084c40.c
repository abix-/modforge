// Address: 0x140084c40
// Ghidra name: FUN_140084c40
// ============ 0x140084c40 FUN_140084c40 (size=1198) ============


/* WARNING: Removing unreachable block (ram,0x000140084e2e) */



void FUN_140084c40(undefined4 *param_1,char *param_2,undefined4 param_3)



{

  ulonglong uVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  size_t sVar8;

  char *pcVar9;

  longlong lVar10;

  int iVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  char *pcVar14;

  char *pcVar15;

  int iVar16;

  undefined1 uVar17;

  longlong lVar18;

  int local_res8 [2];

  int local_res20;

  longlong local_b8;

  int *piStack_b0;

  int *local_a8;

  int local_a0;

  int local_9c;

  longlong local_98;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 local_60;

  

  iVar16 = 0;

  local_res8[0] = 0;

  local_78 = 0;

  uStack_70 = 0;

  local_68 = 0;

  local_60 = 0;

  sVar8 = strlen(param_2);

  FUN_140027e30(&local_78,param_2,sVar8);

  pcVar9 = (char *)FUN_1400c43d0(&local_78,local_res8);

  FUN_1402f94c0(param_1 + 4,0);

  *param_1 = param_3;

  iVar5 = FUN_140072ca0(param_3);

  iVar6 = FUN_140072cc0(*param_1);

  local_b8 = 0;

  piStack_b0 = (int *)0x0;

  local_a8 = (int *)0x0;

  local_res20 = 0;

  local_a0 = 0;

  local_9c = 0;

  if (pcVar9 < pcVar9 + (longlong)local_res8[0] + -1) {

    local_98 = 0;

    pcVar14 = pcVar9;

    do {

      if (local_res20 == 0) {

        cVar2 = *pcVar14;

        while (cVar2 != '=') {

          pcVar14 = pcVar14 + 1;

          cVar2 = *pcVar14;

        }

        pcVar14 = pcVar14 + 1;

      }

      cVar2 = *pcVar14;

      pcVar15 = pcVar14;

      while (('\x1f' < cVar2 && (cVar2 != ','))) {

        pcVar15 = pcVar15 + 1;

        cVar2 = *pcVar15;

      }

      cVar2 = *pcVar15;

      *pcVar15 = '\0';

      iVar7 = FUN_1402d8a8c(pcVar14,0);

      iVar3 = local_a0;

      iVar4 = local_9c;

      if (iVar16 == 2) {

        param_1[1] = iVar7;

      }

      else if (iVar16 == 3) {

        param_1[2] = iVar7;

      }

      else if (iVar16 == 6) {

        if (piStack_b0 == local_a8) {

          lVar18 = (longlong)piStack_b0 - local_b8 >> 2;

          if (lVar18 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar1 = lVar18 + 1;

          uVar12 = (longlong)local_a8 - local_b8 >> 2;

          if (0x3fffffffffffffff - (uVar12 >> 1) < uVar12) {

            uVar13 = 0x3fffffffffffffff;

          }

          else {

            uVar12 = (uVar12 >> 1) + uVar12;

            uVar13 = uVar1;

            if (uVar1 <= uVar12) {

              uVar13 = uVar12;

            }

            if (0x3fffffffffffffff < uVar13) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          lVar10 = FUN_1400285e0(uVar13 * 4);

          *(int *)(lVar10 + lVar18 * 4) = iVar7;

          FUN_1402f8e20(lVar10,local_b8);

          if (local_b8 != 0) {

            if ((0xfff < ((longlong)local_a8 - local_b8 & 0xfffffffffffffffcU)) &&

               (0x1f < (local_b8 - *(longlong *)(local_b8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          piStack_b0 = (int *)(uVar1 * 4 + lVar10);

          local_a8 = (int *)(uVar13 * 4 + lVar10);

          local_b8 = lVar10;

        }

        else {

          *piStack_b0 = iVar7;

          piStack_b0 = piStack_b0 + 1;

        }

      }

      else {

        uVar17 = (undefined1)iVar7;

        if (iVar16 == 0xe) {

          iVar11 = local_res20 +

                   (local_res20 / 3 + (local_res20 >> 0x1f) +

                   (int)(((longlong)local_res20 / 3 + ((longlong)local_res20 >> 0x3f) & 0xffffffffU)

                        >> 0x1f)) * -3;

          iVar3 = iVar7;

          if ((iVar11 != 0) && (iVar3 = local_a0, iVar4 = iVar7, iVar11 != 1)) {

            *(undefined1 *)

             ((longlong)param_1 + (longlong)local_9c + 0x28 + (longlong)local_a0 * 0x118) = uVar17;

            iVar4 = local_9c;

          }

        }

        else if (6 < iVar16) {

          lVar18 = (longlong)*(int *)(local_b8 + local_98 * 4);

          if (iVar16 == 7) {

            param_1[lVar18 * 0x46 + 8] = iVar7;

          }

          else if (iVar16 == 8) {

            *(undefined1 *)(lVar18 * 0x118 + 0x26 + (longlong)param_1) = uVar17;

          }

          else if (iVar16 == 9) {

            *(undefined1 *)(lVar18 * 0x118 + 0x27 + (longlong)param_1) = uVar17;

          }

          else if (iVar16 == 10) {

            *(undefined1 *)(param_1 + lVar18 * 0x46 + 9) = uVar17;

          }

          else if (iVar16 == 0xb) {

            *(undefined1 *)(lVar18 * 0x118 + 0x25 + (longlong)param_1) = uVar17;

          }

          else if (iVar16 == 0xc) {

            param_1[lVar18 * 0x46 + 4] = (float)iVar7 / (float)iVar5;

            param_1[lVar18 * 0x46 + 5] =

                 (float)(*(char *)(param_1 + lVar18 * 0x46 + 9) + iVar7) / (float)iVar5;

          }

          else if (iVar16 == 0xd) {

            param_1[lVar18 * 0x46 + 6] = (float)iVar7 / (float)iVar6;

            param_1[lVar18 * 0x46 + 7] =

                 (float)(*(char *)(lVar18 * 0x118 + 0x25 + (longlong)param_1) + iVar7) /

                 (float)iVar6;

          }

        }

      }

      local_9c = iVar4;

      local_a0 = iVar3;

      if ((cVar2 < ' ') || (pcVar9 + (longlong)local_res8[0] + -1 <= pcVar15)) {

        iVar16 = iVar16 + 1;

        local_res20 = 0;

        local_98 = 0;

      }

      else {

        local_res20 = local_res20 + 1;

        local_98 = local_98 + 1;

      }

      pcVar14 = pcVar15 + 1;

    } while (pcVar14 < pcVar9 + (longlong)local_res8[0] + -1);

  }

  FUN_1400c4de0(pcVar9);

  param_1[3] = param_1[1] - param_1[2];

  if (local_b8 != 0) {

    if ((0xfff < ((longlong)local_a8 - local_b8 & 0xfffffffffffffffcU)) &&

       (0x1f < (local_b8 - *(longlong *)(local_b8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




