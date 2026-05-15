// Address: 0x14005b280
// Ghidra name: FUN_14005b280
// ============ 0x14005b280 FUN_14005b280 (size=1906) ============


void FUN_14005b280(longlong param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  int iVar9;

  int iVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  longlong local_f8;

  ulonglong uStack_f0;

  undefined8 local_e8;

  ulonglong local_e0;

  undefined4 local_d8;

  

  iVar7 = 2 - (uint)(*(int *)(param_1 + 0x2d4) != 0);

  fVar17 = (float)(*(int *)(param_1 + 0x2d4) == 0);

  fVar16 = fVar17 + (float)iVar7;

  iVar9 = (int)(DAT_140304038 / fVar16);

  fVar15 = 0.0;

  FUN_140071000(param_1,iVar7,DAT_14039ca5c,DAT_1403033b4,DAT_1403d4b80);

  FUN_140071000();

  FUN_140071810();

  fVar2 = DAT_140305fc0;

  fVar1 = DAT_140303394;

  fVar13 = DAT_1403033b8;

  if (*(int *)(param_1 + 0x2d4) == 1) {

    do {

      FUN_140071000();

      fVar13 = fVar13 + fVar2;

    } while (fVar1 <= fVar13);

  }

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403ea824) && (FUN_1402c7138(&DAT_1403ea824), DAT_1403ea824 == -1)) {

    local_e8 = 10;

    local_e0 = 0xf;

    local_f8._0_1_ = s_ChartTable_140305f30[0];

    local_f8._1_1_ = s_ChartTable_140305f30[1];

    local_f8._2_1_ = s_ChartTable_140305f30[2];

    local_f8._3_1_ = s_ChartTable_140305f30[3];

    local_f8._4_1_ = s_ChartTable_140305f30[4];

    local_f8._5_1_ = s_ChartTable_140305f30[5];

    local_f8._6_1_ = s_ChartTable_140305f30[6];

    local_f8._7_1_ = s_ChartTable_140305f30[7];

    uStack_f0 = (ulonglong)(ushort)s_ChartTable_140305f30._8_2_;

    DAT_1403ea820 = FUN_14006fe60(&local_f8);

    _Init_thread_footer(&DAT_1403ea824);

  }

  FUN_140071d20(DAT_1403ea820);

  FUN_140071d20(DAT_1403ea820 + 1);

  lVar5 = DAT_1403fb0d8;

  if (*(longlong *)(DAT_1403fb0d8 + 0x280) != *(longlong *)(DAT_1403fb0d8 + 0x288)) {

    iVar7 = 0;

    if (0 < iVar9) {

      lVar8 = (longlong)

              ((int)((*(longlong *)(DAT_1403fb0d8 + 0x288) - *(longlong *)(DAT_1403fb0d8 + 0x280)) /

                    0x24) + -1);

      do {

        if (lVar8 < 0) break;

        FUN_140071000();

        FUN_140071000();

        FUN_140071000();

        iVar7 = iVar7 + 1;

        lVar8 = lVar8 + -1;

      } while (iVar7 < iVar9);

    }

    fVar4 = DAT_14039ca60;

    fVar3 = DAT_14039ca34;

    fVar13 = DAT_140305f90;

    fVar2 = DAT_140305f84;

    lVar8 = *(longlong *)(lVar5 + 0x288) - *(longlong *)(lVar5 + 0x280);

    lVar8 = lVar8 / 0x12 + (lVar8 >> 0x3f);

    iVar7 = (int)(lVar8 >> 1) - (int)(lVar8 >> 0x3f);

    iVar10 = 0;

    fVar11 = DAT_140304004;

    if (-1 < iVar9) {

      do {

        iVar7 = iVar7 + -1;

        if (iVar7 < -1) break;

        iVar6 = 0;

        if (0 < iVar7) {

          iVar6 = iVar7;

        }

        fVar14 = fVar2 - ((float)*(int *)(*(longlong *)(lVar5 + 0x280) + 0x10 +

                                         (longlong)iVar6 * 0x24) * fVar11) / fVar4;

        if (0 < iVar10) {

          fVar12 = (fVar13 - (float)(iVar10 + -1) * fVar16) + fVar17;

          fVar11 = fVar12 - fVar16;

          if (iVar10 == 1) {

            fVar12 = fVar12 - fVar17;

          }

          if (fVar11 <= fVar1) {

            fVar11 = fVar1;

          }

          FUN_140072040((longlong)iVar6 * 9,fVar14 + fVar3,fVar11,fVar14 - fVar3,fVar12,

                        fVar15 - fVar3,fVar12,fVar15 + fVar3,DAT_1403d4b60);

          fVar11 = DAT_140304004;

        }

        iVar10 = iVar10 + 1;

        fVar15 = fVar14;

      } while (iVar10 <= iVar9);

    }

    local_d8 = *(undefined4 *)(*(longlong *)(lVar5 + 0x288) + -4);

    FUN_140086570(DAT_1403ede28);

    FUN_14008d760(&local_f8,&DAT_14039bf04);

    FUN_140086570(DAT_1403ede28);

    if (0xf < local_e0) {

      if ((0xfff < local_e0 + 1) && (0x1f < (local_f8 - *(longlong *)(local_f8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    FUN_140086570(DAT_1403ede28);

    FUN_14008d760(&local_f8,&DAT_140305f5c);

    FUN_140086570(DAT_1403ede28);

    if (0xf < local_e0) {

      if ((0xfff < local_e0 + 1) && (0x1f < (local_f8 - *(longlong *)(local_f8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}




