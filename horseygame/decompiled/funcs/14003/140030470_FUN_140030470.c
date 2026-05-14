// Address: 0x140030470
// Ghidra name: FUN_140030470
// ============ 0x140030470 FUN_140030470 (size=413) ============


void FUN_140030470(longlong param_1)



{

  uint uVar1;

  undefined4 uVar2;

  char local_48 [8];

  char local_40 [2];

  char local_3e;

  undefined1 local_3d;

  undefined4 local_3c;

  undefined8 local_38;

  undefined8 local_30;

  

  FUN_140070f90(DAT_1403d4120);

  FUN_1400d6500(param_1,DAT_1403d4134);

  uVar1 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar1,uVar1));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ba0(param_1,3);

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403ea09c) {

    FUN_1402c7138(&DAT_1403ea09c);

    if (DAT_1403ea09c == -1) {

      local_3c = 0;

      local_38 = 0xb;

      local_30 = 0xf;

      local_48[0] = s_AcresStable_140303740[0];

      local_48[1] = s_AcresStable_140303740[1];

      local_48[2] = s_AcresStable_140303740[2];

      local_48[3] = s_AcresStable_140303740[3];

      local_48[4] = s_AcresStable_140303740[4];

      local_48[5] = s_AcresStable_140303740[5];

      local_48[6] = s_AcresStable_140303740[6];

      local_48[7] = s_AcresStable_140303740[7];

      local_40[0] = s_AcresStable_140303740[8];

      local_40[1] = s_AcresStable_140303740[9];

      local_3e = s_AcresStable_140303740[10];

      local_3d = 0;

      DAT_1403ea098 = FUN_14006fe60(local_48);

      _Init_thread_footer(&DAT_1403ea09c);

    }

  }

  uVar2 = DAT_140303354;

  FUN_140071ed0(DAT_1403ea098,0,0,DAT_140303354,0);

  FUN_140071ed0(DAT_1403ea098,DAT_140303754,0,DAT_14030375c,uVar2);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




