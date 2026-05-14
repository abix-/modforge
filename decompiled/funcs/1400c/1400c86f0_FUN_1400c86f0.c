// Address: 0x1400c86f0
// Ghidra name: FUN_1400c86f0
// ============ 0x1400c86f0 FUN_1400c86f0 (size=1167) ============


void FUN_1400c86f0(float *param_1,uint *param_2,int param_3,int param_4)



{

  undefined4 *puVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  float fVar9;

  int iVar10;

  int iVar11;

  undefined8 uVar12;

  longlong lVar13;

  longlong lVar14;

  longlong lVar15;

  ulonglong uVar16;

  longlong lVar17;

  uint uVar18;

  longlong lVar19;

  int iVar20;

  longlong lVar21;

  longlong lVar22;

  longlong lVar23;

  uint *puVar24;

  longlong lVar25;

  undefined4 uVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  uint *local_res10;

  undefined8 local_128;

  float local_120;

  float local_11c;

  undefined4 local_118;

  longlong local_110;

  int local_108;

  int local_104;

  undefined4 local_100;

  longlong local_f8;

  longlong local_f0;

  

  local_108 = FUN_1400c5c30(param_1[9],1);

  iVar11 = param_3 / local_108;

  local_104 = iVar11 + 3;

  uVar18 = param_4 / local_108 + 3;

  uVar16 = (ulonglong)(int)(uVar18 * local_104 * 2);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = uVar16;

  uVar12 = SUB168(ZEXT816(4) * auVar7,0);

  if (SUB168(ZEXT816(4) * auVar7,8) != 0) {

    uVar12 = 0xffffffffffffffff;

  }

  lVar13 = thunk_FUN_1402c704c(uVar12);

  auVar8._8_8_ = 0;

  auVar8._0_8_ = uVar16;

  uVar12 = SUB168(ZEXT816(4) * auVar8,0);

  if (SUB168(ZEXT816(4) * auVar8,8) != 0) {

    uVar12 = 0xffffffffffffffff;

  }

  local_f8 = lVar13;

  lVar14 = thunk_FUN_1402c704c(uVar12);

  local_110 = lVar14;

  local_100 = FUN_1400c68d0();

  local_118 = FUN_1400c68d0();

  lVar17 = local_f8;

  if (0 < (int)uVar18) {

    local_f0 = (longlong)iVar11 + 3;

    lVar15 = (longlong)iVar11 * 8 + 0x18;

    lVar25 = 0;

    uVar16 = (ulonglong)uVar18;

    lVar19 = local_f0;

    local_128 = lVar15;

    do {

      lVar13 = local_110;

      lVar22 = lVar19;

      if (0 < lVar19) {

        lVar23 = lVar17 - lVar14;

        lVar21 = lVar25;

        do {

          FUN_1400c6940();

          puVar1 = (undefined4 *)(lVar21 + lVar13);

          uVar26 = FUN_1402cdc50();

          *(undefined4 *)((longlong)puVar1 + lVar23) = uVar26;

          uVar26 = FUN_1402cfda0();

          *(undefined4 *)(lVar21 + 4 + lVar17) = uVar26;

          FUN_1400c6940();

          uVar26 = FUN_1402cdc50();

          *puVar1 = uVar26;

          uVar26 = FUN_1402cfda0();

          puVar1[1] = uVar26;

          lVar21 = lVar21 + 8;

          lVar19 = lVar19 + -1;

          lVar15 = local_128;

          lVar14 = local_110;

          lVar22 = local_f0;

        } while (lVar19 != 0);

      }

      lVar25 = lVar25 + lVar15;

      uVar16 = uVar16 - 1;

      lVar13 = local_f8;

      lVar19 = lVar22;

    } while (uVar16 != 0);

  }

  fVar9 = DAT_14039ca44;

  iVar11 = 0;

  if (0 < param_4) {

    local_res10 = param_2;

    do {

      iVar10 = local_104;

      iVar20 = 0;

      if (0 < param_3) {

        puVar24 = local_res10;

        do {

          fVar3 = *param_1;

          fVar27 = param_1[5];

          fVar28 = fVar9;

          if ((int)fVar27 <= iVar20 % ((int)param_1[6] + (int)fVar27)) {

            fVar28 = 0.0;

          }

          fVar4 = param_1[3];

          uVar16 = (longlong)iVar11 % (longlong)((int)param_1[6] + (int)fVar27);

          fVar29 = fVar9;

          if ((int)fVar27 <= (int)uVar16) {

            fVar29 = 0.0;

          }

          fVar5 = param_1[4];

          local_128 = CONCAT44(local_128._4_4_,0x3f000000);

          fVar6 = param_1[7];

          fVar27 = (float)FUN_1400c8b90(fVar27,uVar16 & 0xffffffff,lVar13,iVar10);

          local_128 = CONCAT44(fVar27 * fVar6 + (fVar28 * fVar4 - fVar29 * fVar5),(float)local_128);

          fVar27 = (float)FUN_1400c8b90();

          local_11c = 0.0;

          lVar17 = 4;

          if (*(char *)(param_1 + 2) != '\0') {

            lVar17 = 8;

          }

          local_120 = fVar27 * param_1[8] + ((float)iVar20 * fVar3) / (float)param_3;

          uVar26 = FUN_1400c5c10();

          *(undefined4 *)((longlong)&local_128 + lVar17) = uVar26;

          uVar16 = (ulonglong)((float)local_128 < local_128._4_4_);

          uVar18 = (uint)((float)local_128 < local_128._4_4_);

          pfVar2 = (float *)((longlong)&local_128 + uVar16 * 4);

          if (*pfVar2 <= local_120 && local_120 != *pfVar2) {

            uVar18 = 2;

            uVar16 = 2;

          }

          pfVar2 = (float *)((longlong)&local_128 + uVar16 * 4);

          if (*pfVar2 <= local_11c && local_11c != *pfVar2) {

            uVar18 = 3;

          }

          iVar20 = iVar20 + 1;

          *puVar24 = uVar18;

          puVar24 = puVar24 + 1;

        } while (iVar20 < param_3);

      }

      local_res10 = local_res10 + param_3;

      iVar11 = iVar11 + 1;

    } while (iVar11 < param_4);

  }

  FUN_1402c7088(lVar13);

  FUN_1402c7088(local_110);

  return;

}




