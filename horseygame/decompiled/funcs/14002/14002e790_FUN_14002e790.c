// Address: 0x14002e790
// Ghidra name: FUN_14002e790
// ============ 0x14002e790 FUN_14002e790 (size=1836) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14002e790(longlong param_1)



{

  int iVar1;

  float fVar2;

  undefined4 uVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  float fVar7;

  undefined8 uVar8;

  uint uVar9;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  undefined4 local_d8 [4];

  undefined *local_c8;

  undefined8 uStack_c0;

  undefined *local_b8;

  undefined8 local_b0;

  

  FUN_140070f90(DAT_1403d4084);

  FUN_1400d6500(param_1,DAT_1403d4094);

  fVar16 = (float)(*(uint *)(param_1 + 0x10c) ^ DAT_14039cac0) * *(float *)(param_1 + 0x114);

  lVar10 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar10 + 4) < DAT_1403ea024) && (FUN_1402c7138(&DAT_1403ea024), DAT_1403ea024 == -1)

     ) {

    local_b8 = (undefined *)0xa;

    local_b0 = 0xf;

    local_c8 = (undefined *)s_FinishPost_1403032f8._0_8_;

    uStack_c0 = (undefined *)(ulonglong)(ushort)s_FinishPost_1403032f8._8_2_;

    DAT_1403ea020 = FUN_14006fe60(&local_c8);

    _Init_thread_footer(&DAT_1403ea024);

  }

  uVar11 = 0;

  if ((*(int *)(lVar10 + 4) < DAT_1403ea02c) && (FUN_1402c7138(&DAT_1403ea02c), DAT_1403ea02c == -1)

     ) {

    local_b8 = (undefined *)0xd;

    local_b0 = 0xf;

    local_c8 = (undefined *)s_GrandStandOld_140303308._0_8_;

    uStack_c0._0_5_ = CONCAT14(s_GrandStandOld_140303308[0xc],s_GrandStandOld_140303308._8_4_);

    uStack_c0 = (undefined *)(ulonglong)(uint5)uStack_c0;

    DAT_1403ea028 = FUN_14006fe60(&local_c8);

    _Init_thread_footer(&DAT_1403ea02c);

  }

  if ((*(int *)(lVar10 + 4) < DAT_1403ea034) && (FUN_1402c7138(&DAT_1403ea034), DAT_1403ea034 == -1)

     ) {

    local_b8 = (undefined *)0x8;

    local_b0 = 0xf;

    local_c8 = (undefined *)0x38676e6f6c727546;

    uStack_c0 = (undefined *)0x0;

    _DAT_1403ea030 = FUN_14006fe60(&local_c8);

    _Init_thread_footer(&DAT_1403ea034);

  }

  uVar6 = DAT_1403033c4;

  uVar5 = DAT_1403033ac;

  fVar2 = DAT_1403033a0;

  uVar3 = DAT_140303390;

  FUN_140071000(*(float *)(param_1 + 0x114) * DAT_1403033a0 + fVar16,DAT_1403033ac,DAT_140303390,

                DAT_1403033c4,DAT_1403d4014);

  fVar4 = DAT_1403033c0;

  FUN_140071d20(DAT_1403ea028,(*(float *)(param_1 + 0x114) * fVar2 + fVar16) - DAT_1403033c0,uVar5);

  FUN_140071d20(*(int *)(param_1 + 0x25c) + _DAT_1403ea030,

                *(float *)(param_1 + 0x114) * fVar2 + fVar16 + DAT_1403033b0,uVar5);

  fVar7 = DAT_14039ca44;

  if (1 < *(int *)(param_1 + 0x250)) {

    FUN_140071000(*(float *)(param_1 + 0x264) * *(float *)(param_1 + 0x114) + fVar16,uVar5,uVar3,

                  uVar6,DAT_1403d4014);

    FUN_140071d20(DAT_1403ea020,*(float *)(param_1 + 0x264) * *(float *)(param_1 + 0x114) + fVar16,

                  uVar5);

    if (DAT_1403033a8 < *(float *)(param_1 + 0x260)) {

      FUN_140071d20(DAT_1403ea028,

                    (*(float *)(param_1 + 0x264) * *(float *)(param_1 + 0x114) + fVar16) - fVar4,

                    uVar5);

    }

    fVar15 = DAT_1403033c8;

    fVar4 = DAT_14030339c;

    fVar14 = (*(float *)(param_1 + 0x264) - DAT_14030339c) * *(float *)(param_1 + 0x114) + fVar16;

    if (*(float *)(param_1 + 0x114) * fVar2 + fVar16 + DAT_1403033c8 < fVar14) {

      do {

        FUN_140071000(fVar14,uVar5,fVar7,uVar6,DAT_1403d4014);

        fVar14 = fVar14 - *(float *)(param_1 + 0x114) * fVar4;

      } while (*(float *)(param_1 + 0x114) * fVar2 + fVar16 + fVar15 < fVar14);

    }

  }

  if (*(char *)(param_1 + 0x259) == '\0') {

    if ((*(int *)(lVar10 + 4) < DAT_1403ea03c) &&

       (FUN_1402c7138(&DAT_1403ea03c), DAT_1403ea03c == -1)) {

      local_b8 = (undefined *)0xd;

      local_b0 = 0xf;

      local_c8 = (undefined *)s_DragHorseHere_140303318._0_8_;

      uStack_c0._0_5_ = CONCAT14(s_DragHorseHere_140303318[0xc],s_DragHorseHere_140303318._8_4_);

      uStack_c0 = (undefined *)(ulonglong)(uint5)uStack_c0;

      _DAT_1403ea038 = FUN_14006fe60(&local_c8);

      _Init_thread_footer(&DAT_1403ea03c);

    }

    uVar9 = *(int *)(param_1 + 0x254) / 0x1e & 0x80000001;

    if ((int)uVar9 < 0) {

      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

    }

    FUN_140071d20(uVar9 + _DAT_1403ea038,DAT_1403033b8,DAT_1403033b4);

  }

  uVar3 = DAT_1403033bc;

  fVar4 = DAT_140303398;

  fVar2 = DAT_14030335c;

  lVar10 = *(longlong *)(param_1 + 0x130);

  uVar12 = uVar11;

  uVar13 = uVar11;

  if (*(longlong *)(param_1 + 0x138) - lVar10 >> 3 != 0) {

    do {

      lVar10 = *(longlong *)(uVar13 + lVar10);

      fVar15 = (float)(*(int *)(lVar10 + 0x1dc) - *(int *)(param_1 + 0x120)) * fVar2 - fVar7;

      if ((*(int *)(lVar10 + 0x228) != -1) && (0 < *(int *)(lVar10 + 0x224))) {

        iVar1 = *(int *)(lVar10 + 0x228);

        fVar14 = *(float *)(param_1 + 0x114);

        uVar8 = FUN_1400cf970(param_1);

        FUN_140086570(DAT_1403ede48,uVar3,fVar15 * fVar14,1,fVar7,

                      *(undefined4 *)(&DAT_1403e9fe0 + (longlong)iVar1 * 4),uVar8);

      }

      if (*(int *)(param_1 + 0x250) - 2U < 2) {

        iVar1 = *(int *)(uVar12 + *(longlong *)(param_1 + 0x268));

        if ((-1 < iVar1) && (iVar1 < 3)) {

          local_d8[0] = DAT_1403d4058;

          local_d8[1] = DAT_1403d403c;

          local_d8[2] = DAT_1403d4000;

          local_c8 = &DAT_140303328;

          uStack_c0 = &DAT_14030332c;

          local_b8 = &DAT_140303330;

          FUN_140086570(DAT_1403ede20,

                        *(float *)(param_1 + 0x114) * *(float *)(param_1 + 0x264) + fVar16 + fVar4,

                        *(float *)(param_1 + 0x114) * fVar15,0,fVar7,local_d8[iVar1],

                        (&local_c8)[iVar1]);

        }

      }

      uVar9 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar9;

      lVar10 = *(longlong *)(param_1 + 0x130);

      uVar12 = uVar12 + 0x20;

      uVar13 = uVar13 + 8;

    } while ((ulonglong)(longlong)(int)uVar9 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar10 >> 3));

  }

  if (*(int *)(param_1 + 0x250) != 0) {

    *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;

  }

  uVar9 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar9 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar9 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar9,uVar9));

  if (*(char *)(param_1 + 0x234) != '\0') {

    FUN_1400d5d90(param_1,1);

  }

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,0,1);

  return;

}




