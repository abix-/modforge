// Address: 0x1400be110
// Ghidra name: FUN_1400be110
// ============ 0x1400be110 FUN_1400be110 (size=1557) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400be110(longlong param_1,undefined8 param_2,float param_3,char param_4,float param_5)



{

  bool bVar1;

  uint uVar2;

  undefined8 *puVar3;

  longlong lVar4;

  longlong lVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar9;

  ulonglong uVar10;

  float fVar11;

  undefined4 uVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  ulonglong in_stack_fffffffffffffed8;

  float local_108;

  float fStack_104;

  undefined8 local_100;

  ulonglong uStack_f8;

  undefined8 local_f0;

  ulonglong local_e8;

  

  if (*(char *)(param_1 + 0x207) == '\0') {

    if ((*(int *)(param_1 + 0x234) == -1) &&

       ((*(int *)(param_1 + 0xc) == 7 || (*(int *)(param_1 + 0xc) == 5)))) {

      bVar1 = true;

    }

    else {

      bVar1 = false;

    }

    if (*(int *)(param_1 + 0x1fc) == 0) {

      param_3 = param_3 * _DAT_14030d974;

    }

    fVar18 = DAT_14039ca44;

    if (bVar1) {

      fVar18 = DAT_14039ca80;

    }

    fVar17 = DAT_14039ca44;

    if (*(char *)(param_1 + 0x1a) != '\0') {

      fVar17 = DAT_14039ca80;

    }

    fVar17 = param_3 * *(float *)(param_1 + 0x124) * fVar17;

    fVar18 = param_3 * param_5 * fVar18;

    fVar15 = DAT_14039ca44;

    if (bVar1) {

      fVar15 = DAT_14039ca80;

    }

    fVar11 = DAT_14039ca80;

    if (*(char *)(param_1 + 0x1a) == '\0') {

      fVar11 = DAT_14039ca44;

    }

    local_108 = (float)param_2;

    fStack_104 = (float)((ulonglong)param_2 >> 0x20);

    FUN_140072fe0(CONCAT44(fStack_104 - fVar18,local_108 - fVar17),0,

                  CONCAT44(fVar15 * param_3,fVar11 * param_3));

    if (*(longlong *)(param_1 + 0x28) == *(longlong *)(param_1 + 0x30)) {

      FUN_140072dc0();

      FUN_1400bd290(param_1,0);

      iVar7 = 1;

      lVar9 = *(longlong *)(param_1 + 0x40);

      lVar4 = *(longlong *)(param_1 + 0x48) - lVar9;

      lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

      if (1 < (ulonglong)((lVar4 >> 7) - (lVar4 >> 0x3f))) {

        lVar4 = 0xb8;

        do {

          uVar12 = FUN_1400c5f10(*(undefined4 *)(lVar4 + 0x58 + lVar9));

          FUN_140072f50(*(undefined8 *)(lVar4 + 0x50 + lVar9),uVar12);

          FUN_1400bd290(param_1,iVar7);

          FUN_1400730f0();

          iVar7 = iVar7 + 1;

          lVar4 = lVar4 + 0xb8;

          lVar9 = *(longlong *)(param_1 + 0x40);

          lVar5 = *(longlong *)(param_1 + 0x48) - lVar9;

          lVar5 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar5),8) + lVar5;

        } while ((ulonglong)(longlong)iVar7 < (ulonglong)((lVar5 >> 7) - (lVar5 >> 0x3f)));

      }

      FUN_1400730f0();

    }

    uVar10 = 0;

    uVar8 = (ulonglong)_tls_index;

    if (*(longlong *)(param_1 + 0x28) != *(longlong *)(param_1 + 0x30)) {

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar8 * 8) + 4) <

           DAT_1403f3260) && (FUN_1402c7138(&DAT_1403f3260), DAT_1403f3260 == -1)) {

        uStack_f8 = 0;

        local_f0 = 7;

        local_e8 = 0xf;

        local_100 = (ulonglong)

                    CONCAT16(s_sprites_14030d920[6],

                             CONCAT24(s_sprites_14030d920._4_2_,s_sprites_14030d920._0_4_));

        DAT_1403f325c = FUN_14006fe60(&local_100);

        _Init_thread_footer(&DAT_1403f3260);

      }

      FUN_140072510(param_1 + 0x28,DAT_1403f325c);

    }

    fVar15 = DAT_14039ca34;

    uVar12 = (undefined4)(in_stack_fffffffffffffed8 >> 0x20);

    if (-1 < *(int *)(param_1 + 0x234)) {

      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18);

      fVar11 = *(float *)(lVar9 + 0x2c);

      fVar16 = *(float *)(lVar9 + 0x28) * DAT_14039ca34 - DAT_140303358;

      if (9 < *(int *)(param_1 + 0x234)) {

        fVar16 = fVar16 + DAT_140304c54;

      }

      puVar3 = (undefined8 *)FUN_14008d760(&local_100,&DAT_14039bf04);

      iVar7 = FUN_1400c6df0(*(undefined4 *)(param_1 + 0x234),0x14);

      if (0xf < (ulonglong)puVar3[3]) {

        puVar3 = (undefined8 *)*puVar3;

      }

      in_stack_fffffffffffffed8 = CONCAT44(uVar12,DAT_140303fb4);

      FUN_140086570(DAT_1403ede20,fVar16,fVar11 * DAT_140303364,0,in_stack_fffffffffffffed8,

                    *(undefined4 *)(&DAT_1403f31b0 + (longlong)iVar7 * 4),puVar3);

      if (0xf < local_e8) {

        if ((0xfff < local_e8 + 1) && (0x1f < (local_100 - *(longlong *)(local_100 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    FUN_1400730f0();

    if (param_4 != '\0') {

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar8 * 8) + 4) <

           DAT_1403f3268) && (FUN_1402c7138(&DAT_1403f3268), DAT_1403f3268 == -1)) {

        local_f0 = 9;

        local_e8 = 0xf;

        local_100._0_1_ = s_AnimSleep_14030d900[0];

        local_100._1_1_ = s_AnimSleep_14030d900[1];

        local_100._2_1_ = s_AnimSleep_14030d900[2];

        local_100._3_1_ = s_AnimSleep_14030d900[3];

        local_100._4_1_ = s_AnimSleep_14030d900[4];

        local_100._5_1_ = s_AnimSleep_14030d900[5];

        local_100._6_1_ = s_AnimSleep_14030d900[6];

        local_100._7_1_ = s_AnimSleep_14030d900[7];

        uStack_f8 = (ulonglong)(byte)s_AnimSleep_14030d900[8];

        _DAT_1403f3264 = FUN_14006fe60(&local_100);

        _Init_thread_footer(&DAT_1403f3268);

      }

      uVar2 = DAT_14039cac0;

      fVar11 = DAT_14030374c;

      lVar9 = *(longlong *)(param_1 + 0x40);

      lVar4 = *(longlong *)(param_1 + 0x48) - lVar9;

      lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

      uVar8 = uVar10;

      if (lVar4 >> 7 != lVar4 >> 0x3f) {

        do {

          if (*(int *)(uVar8 + 8 + lVar9) == 7) {

            uVar12 = FUN_1400c5f10(*(undefined4 *)(uVar8 + 0x58 + lVar9));

            fVar16 = (float)FUN_1402cdc50();

            fVar13 = (float)FUN_1402cfda0(uVar12);

            fVar14 = (*(float *)(param_1 + 0x140) * fVar13 - *(float *)(param_1 + 0x144) * fVar16) *

                     param_3 + param_3 * *(float *)(uVar8 + 0x50 + *(longlong *)(param_1 + 0x40));

            if (*(char *)(param_1 + 0x1a) != '\0') {

              fVar14 = (float)((uint)fVar14 ^ uVar2);

            }

            iVar7 = (int)((ulonglong)((longlong)*(int *)(param_1 + 0x10) * -0x77777777) >> 0x20) +

                    *(int *)(param_1 + 0x10);

            uVar6 = (iVar7 >> 4) - (iVar7 >> 0x1f) & 0x80000001;

            if ((int)uVar6 < 0) {

              uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;

            }

            in_stack_fffffffffffffed8 = in_stack_fffffffffffffed8 & 0xffffffff00000000;

            FUN_140071ed0(uVar6 + _DAT_1403f3264,(local_108 - fVar17) + fVar14,

                          ((fStack_104 - fVar18) +

                          (*(float *)(param_1 + 0x140) * fVar16 +

                          *(float *)(param_1 + 0x144) * fVar13) * param_3 +

                          param_3 * *(float *)(uVar8 + 0x54 + *(longlong *)(param_1 + 0x40))) -

                          fVar11,fVar15,in_stack_fffffffffffffed8);

          }

          uVar6 = (int)uVar10 + 1;

          uVar10 = (ulonglong)uVar6;

          lVar9 = *(longlong *)(param_1 + 0x40);

          lVar4 = *(longlong *)(param_1 + 0x48) - lVar9;

          lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

          uVar8 = uVar8 + 0xb8;

        } while ((ulonglong)(longlong)(int)uVar6 < (ulonglong)((lVar4 >> 7) - (lVar4 >> 0x3f)));

      }

    }

    FUN_1400727d0();

  }

  return;

}




