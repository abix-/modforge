// Address: 0x14005c720
// Ghidra name: FUN_14005c720
// ============ 0x14005c720 FUN_14005c720 (size=523) ============


void FUN_14005c720(longlong param_1)



{

  uint uVar1;

  longlong lVar2;

  char local_38 [8];

  ulonglong uStack_30;

  undefined8 local_28;

  undefined8 local_20;

  

  FUN_140070f90(DAT_1403d4cf8);

  lVar2 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if (*(int *)(lVar2 + 4) < DAT_1403ea8d4) {

    FUN_1402c7138(&DAT_1403ea8d4);

    if (DAT_1403ea8d4 == -1) {

      local_28 = 10;

      local_20 = 0xf;

      local_38[0] = s_HermitCave_1403065a8[0];

      local_38[1] = s_HermitCave_1403065a8[1];

      local_38[2] = s_HermitCave_1403065a8[2];

      local_38[3] = s_HermitCave_1403065a8[3];

      local_38[4] = s_HermitCave_1403065a8[4];

      local_38[5] = s_HermitCave_1403065a8[5];

      local_38[6] = s_HermitCave_1403065a8[6];

      local_38[7] = s_HermitCave_1403065a8[7];

      uStack_30 = (ulonglong)(ushort)s_HermitCave_1403065a8._8_2_;

      DAT_1403ea8d0 = FUN_14006fe60(local_38);

      _Init_thread_footer(&DAT_1403ea8d4);

    }

  }

  if (*(int *)(lVar2 + 4) < DAT_1403ea8dc) {

    FUN_1402c7138(&DAT_1403ea8dc);

    if (DAT_1403ea8dc == -1) {

      uStack_30 = 0;

      local_28 = 4;

      local_20 = 0xf;

      builtin_strncpy(local_38,"clop",5);

      local_38[5] = '\0';

      local_38[6] = '\0';

      local_38[7] = '\0';

      DAT_1403ea8d8 = FUN_14006fe60(local_38);

      _Init_thread_footer(&DAT_1403ea8dc);

    }

  }

  FUN_140071ed0(DAT_1403ea8d0,DAT_140303398,DAT_140303750,DAT_14030374c,DAT_14039ca44);

  FUN_140071ed0(DAT_1403ea8d8,DAT_1403065d4,DAT_140303fe8,DAT_14030335c,0);

  uVar1 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar1,uVar1));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




