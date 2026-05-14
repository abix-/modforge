// Address: 0x14014b030
// Ghidra name: FUN_14014b030
// ============ 0x14014b030 FUN_14014b030 (size=659) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined1

FUN_14014b030(longlong param_1,int param_2,int param_3,int param_4,int param_5,char param_6)



{

  bool bVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  char cVar5;

  undefined1 uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  ulonglong uVar10;

  longlong lVar11;

  uint uVar12;

  uint uVar13;

  undefined1 *puVar14;

  longlong lVar15;

  int iVar16;

  int iVar17;

  uint uVar18;

  uint uVar19;

  ulonglong uVar20;

  int local_res10 [2];

  int local_res18 [2];

  int local_res20 [2];

  undefined1 auStack_b8 [32];

  undefined4 *local_98;

  uint local_88;

  int local_84;

  uint local_80;

  int local_7c;

  int local_78;

  int local_74;

  ulonglong local_70;

  int *local_68;

  undefined8 local_60;

  undefined8 uStack_58;

  

  puVar14 = auStack_b8;

  local_68 = *(int **)(param_1 + 0x138);

  local_98 = &param_5;

  uStack_58 = *(undefined8 *)(local_68 + 8);

  iVar2 = *local_68;

  if (*local_68 <= local_68[1]) {

    iVar2 = local_68[1];

  }

  lVar15 = 0;

  local_60 = 0;

  local_res10[0] = param_2;

  local_res18[0] = param_3;

  local_res20[0] = param_4;

  cVar5 = FUN_140184d90(&local_60,local_res10,local_res18,local_res20);

  if (cVar5 == '\0') {

    uVar6 = 1;

  }

  else {

    iVar7 = FUN_140190050(local_res20[0] - local_res10[0]);

    iVar8 = FUN_140190050(param_5 - local_res18[0]);

    uVar18 = 1;

    bVar1 = iVar7 < iVar8;

    if (bVar1) {

      local_84 = iVar7 * 2;

      iVar16 = local_84 - iVar8;

      local_74 = iVar7 - iVar8;

    }

    else {

      local_84 = iVar8 * 2;

      iVar16 = local_84 - iVar7;

      local_74 = iVar8 - iVar7;

      iVar8 = iVar7;

    }

    local_88 = (uint)bVar1;

    uVar19 = (uint)!bVar1;

    local_74 = local_74 * 2;

    local_78 = local_res10[0];

    if (local_res20[0] < local_res10[0]) {

      uVar19 = -(uint)!bVar1;

      local_80 = 0xffffffff;

    }

    else {

      local_80 = 1;

    }

    local_7c = local_res18[0];

    if (param_5 < local_res18[0]) {

      local_88 = -local_88;

      uVar18 = 0xffffffff;

    }

    if (param_6 != '\0') {

      iVar8 = iVar8 + 1;

    }

    if (iVar2 * 4 < iVar8) {

      uVar6 = FUN_14012e850("Line too long (tried to draw %d pixels, max %d)",iVar8,iVar2 * 4);

    }

    else {

      uVar20 = (longlong)iVar8 * 8;

      local_70 = uVar20;

      if (uVar20 < 0x80) {

        uVar10 = uVar20 + 0xf;

        if (uVar10 <= uVar20) {

          uVar10 = 0xffffffffffffff0;

        }

        puVar14 = auStack_b8 + -(uVar10 & 0xfffffffffffffff0);

        lVar11 = (longlong)&local_88 + -(uVar10 & 0xfffffffffffffff0);

      }

      else {

        lVar11 = FUN_1401841f0(uVar20);

      }

      uVar4 = local_80;

      iVar2 = local_84;

      uVar3 = local_88;

      if (lVar11 == 0) {

        uVar6 = 0;

      }

      else {

        iVar7 = local_78;

        iVar17 = local_7c;

        if (0 < iVar8) {

          do {

            *(float *)(lVar11 + lVar15 * 8) = (float)iVar7;

            *(float *)(lVar11 + 4 + lVar15 * 8) = (float)iVar17;

            iVar9 = local_74;

            uVar13 = uVar18;

            uVar12 = uVar4;

            if (iVar16 < 0) {

              iVar9 = iVar2;

              uVar13 = uVar3;

              uVar12 = uVar19;

            }

            iVar16 = iVar16 + iVar9;

            lVar15 = lVar15 + 1;

            uVar20 = local_70;

            iVar7 = iVar7 + uVar12;

            iVar17 = iVar17 + uVar13;

          } while (lVar15 < iVar8);

        }

        if (((float)local_68[0x24] == DAT_14039ca44) && ((float)local_68[0x25] == DAT_14039ca44)) {

          *(undefined8 *)(puVar14 + -8) = 0x14014b286;

          uVar6 = FUN_14014a740(param_1,lVar11,iVar8);

        }

        else {

          *(undefined8 *)(puVar14 + -8) = 0x14014b29a;

          uVar6 = FUN_14014b600(param_1,lVar11,iVar8);

        }

        if (0x7f < uVar20) {

          *(undefined8 *)(puVar14 + -8) = 0x14014b2ae;

          FUN_1401841e0(lVar11);

        }

      }

    }

  }

  return uVar6;

}




