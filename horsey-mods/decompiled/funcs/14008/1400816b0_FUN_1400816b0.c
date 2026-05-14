// Address: 0x1400816b0
// Ghidra name: FUN_1400816b0
// ============ 0x1400816b0 FUN_1400816b0 (size=1610) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400816b0(longlong param_1,longlong param_2)



{

  ulonglong uVar1;

  int iVar2;

  undefined4 uVar3;

  size_t sVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  int iVar7;

  undefined8 uVar8;

  float fVar9;

  int iVar10;

  undefined4 uVar11;

  longlong lVar12;

  longlong lVar13;

  int iVar14;

  int iVar15;

  undefined8 *puVar16;

  longlong lVar17;

  undefined8 *puVar18;

  void *_Buf2;

  undefined8 *puVar19;

  ulonglong uVar20;

  int local_res8;

  undefined8 in_stack_ffffffffffffff28;

  undefined8 uVar21;

  undefined4 uVar22;

  float local_b8;

  float local_b4;

  undefined8 *local_b0;

  longlong local_a8;

  undefined8 *local_a0;

  longlong local_98;

  ulonglong uStack_90;

  undefined8 local_88;

  ulonglong uStack_80;

  

  if ((*(longlong *)(param_1 + 0x80) == 0) || (*(longlong *)(param_2 + 0x80) == 0)) {

    *(undefined8 *)(param_1 + 0x50) = 0;

    uVar3 = *(undefined4 *)(param_1 + 0xac);

  }

  else {

    iVar2 = *(int *)(*(longlong *)(param_1 + 0x80) + 0x254);

    if (iVar2 == 0) {

      return;

    }

    iVar7 = *(int *)(param_1 + 0x74) / 3;

    iVar14 = *(int *)(param_2 + 0x74);

    iVar14 = (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU) >> 0x1f) +

             iVar14 / 3 + (iVar14 >> 0x1f);

    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) - iVar7;

    *(int *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) - iVar14;

    lVar13 = *(longlong *)(param_1 + 0x80);

    sVar4 = *(size_t *)(lVar13 + 0x298);

    if (sVar4 != 0) {

      lVar12 = *(longlong *)(param_2 + 0x80);

      if (*(size_t *)(lVar12 + 0x298) != 0) {

        puVar19 = (undefined8 *)(lVar12 + 0x288);

        puVar16 = (undefined8 *)(lVar13 + 0x288);

        uVar5 = *(ulonglong *)(lVar12 + 0x2a0);

        puVar18 = puVar19;

        if (0xf < uVar5) {

          puVar18 = (undefined8 *)*puVar19;

        }

        uVar6 = *(ulonglong *)(lVar13 + 0x2a0);

        if (0xf < uVar6) {

          puVar16 = (undefined8 *)*puVar16;

        }

        if (((sVar4 != *(size_t *)(lVar12 + 0x298)) ||

            (iVar10 = memcmp(puVar16,puVar18,sVar4), iVar10 != 0)) && (DAT_1403d9527 != '\0')) {

          if (0xf < uVar5) {

            puVar19 = (undefined8 *)*puVar19;

          }

          puVar18 = (undefined8 *)(*(longlong *)(param_1 + 0x80) + 0x288);

          if (0xf < uVar6) {

            puVar18 = (undefined8 *)*puVar18;

          }

          FUN_1400c4320("interherd mating!  %s + %s",puVar18,puVar19);

        }

      }

    }

    uVar3 = DAT_14039ca44;

    fVar9 = DAT_14039ca34;

    uVar5 = _UNK_1403033f8;

    uVar8 = _DAT_1403033f0;

    local_res8 = 0;

    if (0 < iVar2) {

      do {

        uVar22 = (undefined4)((ulonglong)in_stack_ffffffffffffff28 >> 0x20);

        local_a8 = FUN_1402c704c(0x498);

        puVar18 = (undefined8 *)0x0;

        if (local_a8 != 0) {

          puVar18 = (undefined8 *)FUN_1400aac60(local_a8);

        }

        FUN_1400b2e30(puVar18,*(undefined8 *)(param_1 + 0x80),*(undefined8 *)(param_2 + 0x80));

        lVar13 = *(longlong *)(param_2 + 0x80);

        lVar12 = *(longlong *)(param_1 + 0x80);

        puVar16 = (undefined8 *)(lVar12 + 0x288);

        _Buf2 = (void *)(lVar13 + 0x288);

        if (0xf < *(ulonglong *)(lVar13 + 0x2a0)) {

          _Buf2 = *(void **)(lVar13 + 0x288);

        }

        uVar6 = *(ulonglong *)(lVar12 + 0x2a0);

        if (0xf < uVar6) {

          puVar16 = (undefined8 *)*puVar16;

        }

        sVar4 = *(size_t *)(lVar12 + 0x298);

        if (((sVar4 == *(size_t *)(lVar13 + 0x298)) &&

            ((sVar4 == 0 || (iVar10 = memcmp(puVar16,_Buf2,sVar4), iVar10 == 0)))) &&

           (puVar16 = puVar18 + 0x51, puVar16 != (undefined8 *)(lVar12 + 0x288))) {

          lVar13 = lVar12 + 0x288;

          if (0xf < uVar6) {

            lVar13 = *(longlong *)(lVar12 + 0x288);

          }

          uVar6 = puVar18[0x54];

          if (uVar6 < sVar4) {

            if (0x7fffffffffffffff < sVar4) {

                    /* WARNING: Subroutine does not return */

              FUN_140024130();

            }

            uVar20 = sVar4 | 0xf;

            if (uVar20 < 0x8000000000000000) {

              if (0x7fffffffffffffff - (uVar6 >> 1) < uVar6) {

                uVar20 = 0x7fffffffffffffff;

              }

              else {

                uVar1 = uVar6 + (uVar6 >> 1);

                if (uVar20 < uVar1) {

                  uVar20 = uVar1;

                }

              }

            }

            else {

              uVar20 = 0x7fffffffffffffff;

            }

            lVar12 = FUN_1400285e0(uVar20 + 1);

            puVar18[0x53] = sVar4;

            puVar18[0x54] = uVar20;

            FUN_1402f8e20(lVar12,lVar13);

            *(undefined1 *)(sVar4 + lVar12) = 0;

            if (0xf < uVar6) {

              lVar13 = puVar18[0x51];

              lVar17 = lVar13;

              if ((0xfff < uVar6 + 1) &&

                 (lVar17 = *(longlong *)(lVar13 + -8), 0x1f < (lVar13 - lVar17) - 8U)) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088(lVar17);

            }

            puVar18[0x51] = lVar12;

          }

          else {

            if (0xf < uVar6) {

              puVar16 = (undefined8 *)*puVar16;

            }

            puVar18[0x53] = sVar4;

            FUN_1402f8e20(puVar16,lVar13,sVar4);

            *(undefined1 *)(sVar4 + (longlong)puVar16) = 0;

          }

        }

        FUN_1400c6580(4);

        puVar19 = (undefined8 *)FUN_1402c704c(200);

        puVar16 = (undefined8 *)0x0;

        local_a0 = puVar19;

        if (puVar19 != (undefined8 *)0x0) {

          FUN_1400a8610(puVar19,0);

          *puVar19 = &PTR_FUN_14030ac90;

          *(undefined4 *)(puVar19 + 6) = 0x41c00000;

          *(undefined4 *)((longlong)puVar19 + 0x34) = 0x41800000;

          puVar19[0x10] = 0;

          puVar19[0xe] = 0;

          *(undefined4 *)(puVar19 + 3) = 0;

          puVar19[0xf] = 0;

          *(undefined4 *)((longlong)puVar19 + 0xb4) = 0;

          puVar19[10] = 0;

          *(undefined1 *)(puVar19 + 0x17) = 0;

          *(undefined1 *)((longlong)puVar19 + 0xc4) = 1;

          *(undefined8 *)((longlong)puVar19 + 0xbc) = 0;

          puVar16 = puVar19;

        }

        FUN_140080730(puVar16,puVar18,0,0);

        FUN_1400c6d00(&local_b8,uVar3);

        *(float *)(puVar16 + 5) =

             local_b8 * *(float *)(param_1 + 0x30) * fVar9 + *(float *)(param_1 + 0x28);

        *(float *)((longlong)puVar16 + 0x2c) =

             local_b4 * *(float *)(param_1 + 0x34) * fVar9 + *(float *)(param_1 + 0x2c);

        *(int *)((longlong)puVar16 + 0x74) = (iVar7 + iVar14) / iVar2;

        *(undefined4 *)(puVar16[0x10] + 0x1fc) = 0;

        FUN_140080cc0(puVar16,0);

        if ((*(int *)(*(longlong *)(param_1 + 0x80) + 0x1f8) == -1) ||

           (lVar13 = FUN_1400c7520(), *(longlong *)(lVar13 + 0x10) == 0)) {

          iVar10 = -1;

        }

        else {

          iVar10 = *(int *)(*(longlong *)(param_1 + 0x80) + 0x1f8);

        }

        if ((*(int *)(*(longlong *)(param_2 + 0x80) + 0x1f8) == -1) ||

           (lVar13 = FUN_1400c7520(), *(longlong *)(lVar13 + 0x10) == 0)) {

          iVar15 = -1;

        }

        else {

          iVar15 = *(int *)(*(longlong *)(param_2 + 0x80) + 0x1f8);

        }

        if ((iVar10 != -1) || (iVar15 != -1)) {

          lVar13 = puVar16[0x10];

          uVar21 = CONCAT44(uVar22,iVar15);

          uVar11 = FUN_1400c7600(0,0,0xffffffff,iVar10,uVar21);

          uVar22 = (undefined4)((ulonglong)uVar21 >> 0x20);

          *(undefined4 *)(lVar13 + 0x1f8) = uVar11;

        }

        lVar13 = DAT_1403fb0d8;

        local_b0 = puVar16;

        if (*(undefined8 **)(DAT_1403fb0d8 + 0xc0) == *(undefined8 **)(DAT_1403fb0d8 + 200)) {

          FUN_140030680();

        }

        else {

          **(undefined8 **)(DAT_1403fb0d8 + 0xc0) = puVar16;

          *(longlong *)(lVar13 + 0xc0) = *(longlong *)(lVar13 + 0xc0) + 8;

        }

        local_88 = uVar8;

        uStack_80 = uVar5;

        local_98._0_1_ = s_WildMating_14030ad08[0];

        local_98._1_1_ = s_WildMating_14030ad08[1];

        local_98._2_1_ = s_WildMating_14030ad08[2];

        local_98._3_1_ = s_WildMating_14030ad08[3];

        local_98._4_1_ = s_WildMating_14030ad08[4];

        local_98._5_1_ = s_WildMating_14030ad08[5];

        local_98._6_1_ = s_WildMating_14030ad08[6];

        local_98._7_1_ = s_WildMating_14030ad08[7];

        uStack_90 = (ulonglong)(ushort)s_WildMating_14030ad08._8_2_;

        in_stack_ffffffffffffff28 = CONCAT44(uVar22,8);

        FUN_14010de70(DAT_1403fb0d8,&local_98,0,*(undefined8 *)(param_1 + 0x28),

                      in_stack_ffffffffffffff28,100,uVar3);

        if (0xf < uStack_80) {

          if ((0xfff < uStack_80 + 1) && (0x1f < (local_98 - *(longlong *)(local_98 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        if (*(char *)(param_1 + 0xc4) != '\0') {

          _DAT_1403eaecc = _DAT_1403eaecc + 1;

        }

        local_res8 = local_res8 + 1;

      } while (local_res8 < iVar2);

    }

    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;

    *(int *)(param_2 + 0xbc) = *(int *)(param_2 + 0xbc) + 1;

    FUN_140082550(param_1);

    *(undefined8 *)(param_1 + 0x50) = 0;

    uVar3 = *(undefined4 *)(param_1 + 0xac);

  }

  FUN_140080cc0(param_1,10,uVar3);

  return;

}




