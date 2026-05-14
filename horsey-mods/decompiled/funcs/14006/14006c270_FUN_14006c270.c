// Address: 0x14006c270
// Ghidra name: FUN_14006c270
// ============ 0x14006c270 FUN_14006c270 (size=2141) ============


void FUN_14006c270(void)



{

  float fVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  uint *puVar8;

  char *pcVar9;

  longlong lVar10;

  longlong lVar11;

  int iVar12;

  uint uVar13;

  uint *puVar14;

  ulonglong uVar15;

  bool bVar16;

  undefined8 local_d8;

  uint *puStack_d0;

  uint *local_c8;

  undefined8 local_c0;

  longlong local_b8 [3];

  ulonglong local_a0;

  

  lVar10 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar10 + 4) < DAT_1403eac3c) && (FUN_1402c7138(&DAT_1403eac3c), DAT_1403eac3c == -1)

     ) {

    puStack_d0 = (uint *)0x0;

    local_c8 = (uint *)0x7;

    local_c0 = 0xf;

    local_d8 = (uint *)(ulonglong)

                       CONCAT16(s_NewsTop_14030a1f0[6],

                                CONCAT24(s_NewsTop_14030a1f0._4_2_,s_NewsTop_14030a1f0._0_4_));

    DAT_1403eac38 = FUN_14006fe60(&local_d8);

    _Init_thread_footer(&DAT_1403eac3c);

  }

  if ((*(int *)(lVar10 + 4) < DAT_1403eac44) && (FUN_1402c7138(&DAT_1403eac44), DAT_1403eac44 == -1)

     ) {

    local_c8 = (uint *)0xa;

    local_c0 = 0xf;

    local_d8._0_1_ = s_MiniTrophy_14030a1f8[0];

    local_d8._1_1_ = s_MiniTrophy_14030a1f8[1];

    local_d8._2_1_ = s_MiniTrophy_14030a1f8[2];

    local_d8._3_1_ = s_MiniTrophy_14030a1f8[3];

    local_d8._4_1_ = s_MiniTrophy_14030a1f8[4];

    local_d8._5_1_ = s_MiniTrophy_14030a1f8[5];

    local_d8._6_1_ = s_MiniTrophy_14030a1f8[6];

    local_d8._7_1_ = s_MiniTrophy_14030a1f8[7];

    puStack_d0 = (uint *)(ulonglong)(ushort)s_MiniTrophy_14030a1f8._8_2_;

    DAT_1403eac40 = FUN_14006fe60(&local_d8);

    _Init_thread_footer(&DAT_1403eac44);

  }

  FUN_140070f90(DAT_1403d9398);

  FUN_140071000(DAT_1403eda00,DAT_140303750);

  FUN_140071d20(DAT_1403eac38,DAT_140303390);

  uVar7 = DAT_14039ca44;

  uVar2 = DAT_14030a238;

  FUN_140071ed0(DAT_1403eac38,DAT_14030a238);

  FUN_140071d20(DAT_1403eac38 + 1,DAT_140303390);

  FUN_140071ed0(DAT_1403eac38 + 1,uVar2);

  FUN_140071000();

  FUN_140071000();

  FUN_140071000();

  FUN_140071d20(DAT_1403eac38 + 2,DAT_140303fd8);

  FUN_140071d20(DAT_1403eac38 + 3,DAT_14030a230);

  fVar1 = DAT_140304000;

  iVar12 = 0x25;

  bVar16 = *(longlong *)(DAT_1403fb0d8 + 0x3f8) != *(longlong *)(DAT_1403fb0d8 + 0x400);

  if (bVar16) {

    FUN_140072ed0();

    FUN_1400874e0(DAT_1403ede58,DAT_1403fb0d8 + 0x3e0);

    FUN_1400730f0();

    iVar12 = (int)(*(float *)(DAT_1403fb0d8 + 0x3ec) + fVar1);

  }

  fVar1 = DAT_14030a220;

  uVar2 = DAT_14030a210;

  lVar10 = *(longlong *)(DAT_1403fb0d8 + 0x3d0) - *(longlong *)(DAT_1403fb0d8 + 0x3c8);

  lVar10 = lVar10 / 6 + (lVar10 >> 0x3f);

  uVar13 = ((int)(lVar10 >> 3) - (int)(lVar10 >> 0x3f)) - 1;

  if (-1 < (int)uVar13) {

    lVar10 = (longlong)(int)uVar13 * 0x30;

    do {

      if (fVar1 < (float)iVar12 + *(float *)(*(longlong *)(DAT_1403fb0d8 + 0x3c8) + 0xc + lVar10))

      break;

      if (bVar16) {

        FUN_140071d20(DAT_1403eac38 + 4,uVar2);

        iVar12 = iVar12 + 9;

      }

      FUN_140072ed0();

      FUN_1400874e0(DAT_1403ede58,(ulonglong)uVar13 * 0x30 + *(longlong *)(DAT_1403fb0d8 + 0x3c8));

      FUN_1400730f0();

      iVar12 = (int)((float)iVar12 + *(float *)(*(longlong *)(DAT_1403fb0d8 + 0x3c8) + 0xc + lVar10)

                    );

      bVar16 = true;

      lVar10 = lVar10 + -0x30;

      uVar13 = uVar13 - 1;

    } while (-1 < (int)uVar13);

  }

  puVar8 = (uint *)FUN_1402c704c(0x34);

  puStack_d0 = puVar8 + 0xd;

  puVar8[0] = 0;

  puVar8[1] = 0;

  puVar8[2] = 0;

  puVar8[3] = 0;

  puVar8[4] = 0;

  puVar8[5] = 0;

  puVar8[6] = 0;

  puVar8[7] = 0;

  puVar8[8] = 0;

  puVar8[9] = 0;

  puVar8[10] = 0;

  puVar8[0xb] = 0;

  puVar8[0xc] = 0;

  uVar13 = 0;

  puVar14 = puVar8;

  do {

    *puVar14 = uVar13;

    uVar13 = uVar13 + 1;

    puVar14 = puVar14 + 1;

  } while (uVar13 < 0xd);

  uVar15 = (longlong)puStack_d0 - (longlong)puVar8 >> 2;

  local_d8 = puVar8;

  local_c8 = puStack_d0;

  FUN_14006d0c0();

  uVar6 = DAT_14030a234;

  uVar5 = DAT_14030a22c;

  uVar4 = DAT_140305fa4;

  uVar3 = DAT_140304c40;

  uVar2 = DAT_140304c34;

  iVar12 = 0;

  puVar14 = puVar8;

  if (uVar15 != 0) {

    do {

      lVar11 = (longlong)(int)*puVar14;

      lVar10 = *(longlong *)(*(longlong *)(DAT_1403fb0d8 + 0x438) + lVar11 * 8);

      if (lVar10 != 0) {

        if (*puVar14 == 0) {

          pcVar9 = "Player";

        }

        else {

          pcVar9 = (char *)(lVar10 + 0x18);

          if (0xf < *(ulonglong *)(lVar10 + 0x30)) {

            pcVar9 = *(char **)pcVar9;

          }

        }

        FUN_140086570(DAT_1403ede58,uVar3,&DAT_1403eabf0,0,uVar7,

                      *(undefined4 *)(&DAT_1403eabf0 + lVar11 * 4),pcVar9);

        if (0 < *(int *)(DAT_1403fb0d8 + 0x298 + lVar11 * 4)) {

          FUN_140071d20(DAT_1403eac40,uVar6);

          FUN_14008d760(local_b8,&DAT_14039bf04);

          FUN_140086570(DAT_1403ede28,uVar4);

          if (0xf < local_a0) {

            if ((0xfff < local_a0 + 1) &&

               (0x1f < (local_b8[0] - *(longlong *)(local_b8[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        if (0 < *(int *)(DAT_1403fb0d8 + 0x2cc + lVar11 * 4)) {

          FUN_140071d20(DAT_1403eac40 + 1,uVar2);

          FUN_14008d760(local_b8,&DAT_14039bf04);

          FUN_140086570(DAT_1403ede28,uVar5);

          if (0xf < local_a0) {

            if ((0xfff < local_a0 + 1) &&

               (0x1f < (local_b8[0] - *(longlong *)(local_b8[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

      }

      iVar12 = iVar12 + 1;

      puVar14 = puVar14 + 1;

    } while ((ulonglong)(longlong)iVar12 < uVar15);

  }

  FUN_140071000();

  if (puVar8 != (uint *)0x0) {

    puVar14 = puVar8;

    if ((0xfff < uVar15 * 4) &&

       (puVar14 = *(uint **)(puVar8 + -2),

       0x1f < (ulonglong)((longlong)puVar8 + (-8 - (longlong)puVar14)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(puVar14);

  }

  return;

}




