// Address: 0x1400f95d0
// Ghidra name: FUN_1400f95d0
// ============ 0x1400f95d0 FUN_1400f95d0 (size=1182) ============


void FUN_1400f95d0(longlong param_1)



{

  int iVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  float fVar4;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 local_b0;

  undefined8 extraout_XMM0_Qb;

  

  FUN_140070f90(DAT_1403dc064);

  FUN_140071000();

  FUN_1400c6940();

  FUN_1400c6940();

  FUN_140071000();

  if (*(char *)(param_1 + 0x26c) != '\0') {

    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

        < DAT_1403f4dec) {

      FUN_1402c7138(&DAT_1403f4dec);

      if (DAT_1403f4dec == -1) {

        uStack_c0 = 0;

        local_b8 = 6;

        local_b0 = 0xf;

        local_c8 = (ulonglong)CONCAT24(s_Plinth_140305f24._4_2_,s_Plinth_140305f24._0_4_);

        DAT_1403f4de8 = FUN_14006fe60(&local_c8);

        _Init_thread_footer(&DAT_1403f4dec);

      }

    }

    FUN_140071d20(DAT_1403f4de8);

  }

  fVar4 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar4 * *(float *)(param_1 + 0x110),fVar4 * *(float *)(param_1 + 0x10c)));

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403f4df4) {

    FUN_1402c7138(&DAT_1403f4df4);

    if (DAT_1403f4df4 == -1) {

      uStack_c0 = 0;

      local_b8 = 5;

      local_b0 = 0xf;

      local_c8 = (ulonglong)CONCAT14(s_Shelf_140312f0c[4],s_Shelf_140312f0c._0_4_);

      DAT_1403f4df0 = FUN_14006fe60(&local_c8);

      _Init_thread_footer(&DAT_1403f4df4);

    }

  }

  FUN_140071ed0(DAT_1403f4df0);

  FUN_140071ed0(DAT_1403f4df0 + 1);

  FUN_140071ed0(DAT_1403f4df0 + 2);

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  if (*(int *)(param_1 + 0x260) == 0) {

    fVar4 = (float)(*(int *)(param_1 + 0x250) + -0x1e);

    if (fVar4 < (float)DAT_14030b680) {

      FUN_140072ed0();

      iVar1 = 0;

      do {

        iVar1 = iVar1 + 1;

        FUN_1402cdc50();

        FUN_1402cfda0();

        FUN_1402cdc50();

        auVar2._0_8_ = FUN_1402cfda0();

        auVar2._8_8_ = extraout_XMM0_Qb;

        auVar3._4_12_ = auVar2._4_12_;

        auVar3._0_4_ = (float)auVar2._0_8_ * fVar4;

        FUN_140072040(auVar3._0_8_);

      } while (iVar1 < 0x40);

      FUN_1400730f0();

    }

  }

  return;

}




