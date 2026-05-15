// Address: 0x14010fc10
// Ghidra name: FUN_14010fc10
// ============ 0x14010fc10 FUN_14010fc10 (size=2259) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14010fc10(longlong param_1,char param_2)



{

  byte *pbVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined4 uVar5;

  int iVar6;

  uint uVar7;

  undefined8 *puVar8;

  undefined4 *puVar9;

  int iVar10;

  int iVar11;

  ulonglong uVar12;

  longlong lVar13;

  bool bVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  int local_res18;

  undefined8 in_stack_fffffffffffffee8;

  undefined4 uVar19;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  ulonglong local_e0;

  longlong local_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  

  lVar13 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  local_d0 = lVar13;

  if ((*(int *)(lVar13 + 4) < DAT_1403fb464) && (FUN_1402c7138(&DAT_1403fb464), DAT_1403fb464 == -1)

     ) {

    uStack_f0 = 0;

    local_e8 = 6;

    local_e0 = 0xf;

    local_f8._0_6_ = CONCAT24(DAT_1403139f4,DAT_1403139f0);

    local_f8 = (ulonglong)(uint6)local_f8;

    DAT_1403fb460 = FUN_14006fe60(&local_f8);

    _Init_thread_footer(&DAT_1403fb464);

  }

  if ((*(int *)(lVar13 + 4) < DAT_1403fb470) && (FUN_1402c7138(&DAT_1403fb470), DAT_1403fb470 == -1)

     ) {

    local_e8 = 10;

    local_e0 = 0xf;

    local_f8._0_1_ = s_InvTrumpet_14030e7e0[0];

    local_f8._1_1_ = s_InvTrumpet_14030e7e0[1];

    local_f8._2_1_ = s_InvTrumpet_14030e7e0[2];

    local_f8._3_1_ = s_InvTrumpet_14030e7e0[3];

    local_f8._4_1_ = s_InvTrumpet_14030e7e0[4];

    local_f8._5_1_ = s_InvTrumpet_14030e7e0[5];

    local_f8._6_1_ = s_InvTrumpet_14030e7e0[6];

    local_f8._7_1_ = s_InvTrumpet_14030e7e0[7];

    uStack_f0 = (ulonglong)(ushort)s_InvTrumpet_14030e7e0._8_2_;

    _DAT_1403fb468 = FUN_14006fe60(&local_f8);

    local_e8 = 0xb;

    local_e0 = 0xf;

    local_f8._0_1_ = s_InvSTrumpet_1403139f8[0];

    local_f8._1_1_ = s_InvSTrumpet_1403139f8[1];

    local_f8._2_1_ = s_InvSTrumpet_1403139f8[2];

    local_f8._3_1_ = s_InvSTrumpet_1403139f8[3];

    local_f8._4_1_ = s_InvSTrumpet_1403139f8[4];

    local_f8._5_1_ = s_InvSTrumpet_1403139f8[5];

    local_f8._6_1_ = s_InvSTrumpet_1403139f8[6];

    local_f8._7_1_ = s_InvSTrumpet_1403139f8[7];

    uStack_f0 = (ulonglong)CONCAT12(s_InvSTrumpet_1403139f8[10],s_InvSTrumpet_1403139f8._8_2_);

    DAT_1403fb46c = FUN_14006fe60(&local_f8);

    _Init_thread_footer(&DAT_1403fb470);

  }

  uVar5 = DAT_14039ca44;

  fVar16 = DAT_140304c08;

  local_c8 = _DAT_140313a80;

  uStack_c0 = _UNK_140313a88;

  local_b8 = _DAT_140313ab0;

  uStack_b0 = _UNK_140313ab8;

  local_a8 = _DAT_140313a90;

  uStack_a0 = _UNK_140313a98;

  local_98 = _DAT_140313aa0;

  uStack_90 = _UNK_140313aa8;

  local_88 = _DAT_140313ac0;

  uStack_80 = _UNK_140313ac8;

  local_78 = _DAT_140313a70;

  uStack_70 = _UNK_140313a78;

  iVar6 = DAT_1403ed998 + 0x17;

  lVar13 = 0x548;

  local_res18 = 0;

  do {

    lVar4 = *(longlong *)(param_1 + 0x60);

    if (*(char *)(lVar13 + 0x5d + lVar4) == '\0') break;

    fVar15 = (float)DAT_1403ed994;

    *(float *)(lVar13 + 0x34 + lVar4) = fVar15;

    *(undefined4 *)(lVar13 + 0x3c + lVar4) = 0x41a00000;

    *(float *)(lVar13 + 0x38 + lVar4) = (float)local_res18 + (float)iVar6;

    iVar3 = *(int *)(lVar13 + 0x54 + lVar4);

    iVar11 = (int)fVar15;

    if (iVar3 == 5) {

      *(float *)(lVar13 + 0x38 + lVar4) = (float)(DAT_1403d9e6c + -0x19);

      iVar10 = 2;

LAB_14010fe9d:

      if ((*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0') || (iVar3 != 5)) {

        if ((param_2 == '\0') || (*(int *)(param_1 + 0x34c) != iVar3)) {

          if ((*(char *)(param_1 + 0x415) == '\0') || (iVar3 != 1)) goto LAB_14010ff4e;

          uVar7 = (int)(*(int *)(param_1 + 600) + (*(int *)(param_1 + 600) >> 0x1f & 0xfU)) >> 4 &

                  0x80000001;

          if ((int)uVar7 < 0) {

            uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;

          }

        }

        else {

          uVar7 = (int)(*(int *)(param_1 + 600) + (*(int *)(param_1 + 600) >> 0x1f & 0xfU)) >> 4 &

                  0x80000001;

          if ((int)uVar7 < 0) {

            uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;

          }

          iVar10 = 1;

        }

        iVar11 = iVar11 + uVar7;

      }

      else {

        iVar11 = iVar11 + 1;

      }

    }

    else {

      iVar10 = 0;

      if ((iVar3 != 0) || (*(int *)(param_1 + 0x36c) < 1)) goto LAB_14010fe9d;

      *(int *)(param_1 + 0x36c) = *(int *)(param_1 + 0x36c) + -1;

      iVar10 = 3;

    }

LAB_14010ff4e:

    FUN_140071d20(DAT_1403fb460 + iVar10);

    cVar2 = *(char *)(param_1 + 800 + (longlong)iVar3 * 8);

    uVar12 = (ulonglong)(cVar2 != '\0');

    bVar14 = cVar2 != '\0';

    if (iVar3 == 5) {

      if (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) != '\0') {

        bVar14 = true;

        uVar12 = 1;

      }

LAB_14010ffa6:

      FUN_140071d20(*(int *)(&DAT_1403fb468 + uVar12 * 4) + iVar3);

      uVar19 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);

      if (((iVar3 != 0) && (iVar3 != 5)) && (!bVar14)) {

        puVar8 = (undefined8 *)FUN_14008d760(&local_f8,&DAT_14039bf04);

        if (0xf < (ulonglong)puVar8[3]) {

          puVar8 = (undefined8 *)*puVar8;

        }

        in_stack_fffffffffffffee8 = CONCAT44(uVar19,uVar5);

        FUN_140086570(DAT_1403ede28,iVar11 + 0x11,*(float *)(lVar13 + 0x38 + lVar4) + fVar16,1,

                      in_stack_fffffffffffffee8,DAT_1403dc2f8,puVar8);

        if (0xf < local_e0) {

          if ((0xfff < local_e0 + 1) && (0x1f < (local_f8 - *(longlong *)(local_f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

    }

    else {

      if (((iVar3 != 2) || (*(char *)(param_1 + 0x330) == '\0')) || (*(int *)(param_1 + 900) < 1))

      goto LAB_14010ffa6;

      FUN_140072750(0x40);

      FUN_140071d20(*(int *)(&DAT_1403fb468 + uVar12 * 4) + 2);

      FUN_1400727d0();

    }

    local_res18 = local_res18 + 0x16;

    lVar13 = lVar13 + 0x68;

  } while (lVar13 < 0x7b8);

  lVar13 = **(longlong **)(param_1 + 0x438);

  if (lVar13 == 0) {

    return;

  }

  lVar4 = *(longlong *)(param_1 + 0x300);

  if (*(char *)(lVar4 + 0xac) != '\0') {

    return;

  }

  if (2 < *(int *)(param_1 + 0x268)) {

    return;

  }

  fVar15 = *(float *)(lVar13 + 0xc) - *(float *)(lVar4 + 0x28);

  fVar17 = *(float *)(lVar13 + 0x10) - *(float *)(lVar4 + 0x2c);

  fVar16 = (float)((uint)fVar15 & _DAT_14039cab0);

  if ((fVar16 <= DAT_140309c10) && ((float)((uint)fVar17 & _DAT_14039cab0) <= DAT_140309c10)) {

    return;

  }

  pbVar1 = (byte *)(param_1 + 0x390);

  fVar18 = DAT_14039ca34;

  if ((*pbVar1 & 1) == 0) {

    fVar18 = DAT_140303360;

  }

  if ((0.0 <= fVar17) || ((float)((uint)fVar17 ^ DAT_14039cac0) * fVar18 <= fVar16)) {

    if ((fVar17 <= 0.0) || (fVar18 * fVar17 <= fVar16)) {

      if ((0.0 <= fVar15) ||

         ((float)((uint)fVar15 ^ DAT_14039cac0) * fVar18 <= (float)((uint)fVar17 & _DAT_14039cab0)))

      {

        puVar9 = (undefined4 *)(param_1 + 0x390);

        if ((fVar15 <= 0.0) || (fVar18 * fVar15 <= (float)((uint)fVar17 & _DAT_14039cab0))) {

          if (0.0 <= fVar17) {

LAB_140110287:

            if (0.0 <= fVar15) {

              *puVar9 = 3;

            }

            else {

              *puVar9 = 5;

            }

          }

          else if (0.0 <= fVar15) {

            if (fVar15 <= 0.0) goto LAB_140110287;

            *puVar9 = 1;

          }

          else {

            *puVar9 = 7;

          }

        }

        else {

          *(undefined4 *)(param_1 + 0x390) = 2;

        }

      }

      else {

        *(undefined4 *)(param_1 + 0x390) = 6;

      }

    }

    else {

      pbVar1[0] = 4;

      pbVar1[1] = 0;

      pbVar1[2] = 0;

      pbVar1[3] = 0;

    }

  }

  else {

    pbVar1[0] = 0;

    pbVar1[1] = 0;

    pbVar1[2] = 0;

    pbVar1[3] = 0;

  }

  FUN_140072ed0();

  if ((*(int *)(local_d0 + 4) < DAT_1403fb478) &&

     (FUN_1402c7138(&DAT_1403fb478), DAT_1403fb478 == -1)) {

    uStack_f0 = 0;

    local_e8 = 7;

    local_e0 = 0xf;

    local_f8._0_6_ = CONCAT24(s_Compass_140313a08._4_2_,s_Compass_140313a08._0_4_);

    local_f8 = (ulonglong)CONCAT16(s_Compass_140313a08[6],(uint6)local_f8);

    DAT_1403fb474 = FUN_14006fe60(&local_f8);

    _Init_thread_footer(&DAT_1403fb478);

  }

  FUN_140071d20(DAT_1403fb474);

  iVar6 = *(int *)(param_1 + 0x390);

  if (iVar6 == 0) {

    FUN_140071d20(DAT_1403fb474 + 3);

  }

  else {

    if (iVar6 == 4) {

      iVar6 = DAT_1403fb474 + 3;

    }

    else {

      if (iVar6 == 6) {

        FUN_140071d20(DAT_1403fb474 + 2);

        goto LAB_14011049c;

      }

      if (iVar6 == 2) {

        iVar6 = DAT_1403fb474 + 2;

      }

      else {

        if (iVar6 == 7) {

          FUN_140071d20(DAT_1403fb474 + 1);

          goto LAB_14011049c;

        }

        if (iVar6 == 1) {

          iVar6 = DAT_1403fb474 + 1;

        }

        else {

          if ((iVar6 != 5) && (iVar6 != 3)) goto LAB_14011049c;

          iVar6 = DAT_1403fb474 + 1;

        }

      }

    }

    FUN_140071ed0(iVar6);

  }

LAB_14011049c:

  FUN_1400730f0();

  return;

}




