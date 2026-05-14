// Address: 0x1400a8070
// Ghidra name: FUN_1400a8070
// ============ 0x1400a8070 FUN_1400a8070 (size=1339) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a8070(longlong param_1)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  char local_78 [8];

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 local_60;

  

  lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if (*(int *)(lVar1 + 4) < DAT_1403f3084) {

    FUN_1402c7138(&DAT_1403f3084);

    if (DAT_1403f3084 == -1) {

      local_68 = 8;

      local_60 = 0xf;

      builtin_strncpy(local_78,"GlueHaus",8);

      uStack_70 = 0;

      DAT_1403f3080 = FUN_14006fe60(local_78);

      _Init_thread_footer(&DAT_1403f3084);

    }

  }

  if (*(int *)(lVar1 + 4) < DAT_1403f308c) {

    FUN_1402c7138(&DAT_1403f308c);

    if (DAT_1403f308c == -1) {

      local_68 = 8;

      local_60 = 0xf;

      builtin_strncpy(local_78,"Conveyor",8);

      uStack_70 = 0;

      _DAT_1403f3088 = FUN_14006fe60(local_78);

      _Init_thread_footer(&DAT_1403f308c);

    }

  }

  if (*(int *)(lVar1 + 4) < DAT_1403f3094) {

    FUN_1402c7138(&DAT_1403f3094);

    if (DAT_1403f3094 == -1) {

      local_68 = 0xb;

      local_60 = 0xf;

      local_78[0] = s_WeightScale_14030d000[0];

      local_78[1] = s_WeightScale_14030d000[1];

      local_78[2] = s_WeightScale_14030d000[2];

      local_78[3] = s_WeightScale_14030d000[3];

      local_78[4] = s_WeightScale_14030d000[4];

      local_78[5] = s_WeightScale_14030d000[5];

      local_78[6] = s_WeightScale_14030d000[6];

      local_78[7] = s_WeightScale_14030d000[7];

      uStack_70 = (ulonglong)CONCAT12(s_WeightScale_14030d000[10],s_WeightScale_14030d000._8_2_);

      DAT_1403f3090 = FUN_14006fe60(local_78);

      _Init_thread_footer(&DAT_1403f3094);

    }

  }

  if (*(int *)(lVar1 + 4) < DAT_1403f309c) {

    FUN_1402c7138(&DAT_1403f309c);

    if (DAT_1403f309c == -1) {

      local_68 = 9;

      local_60 = 0xf;

      local_78[0] = s_NowPaying_14030d010[0];

      local_78[1] = s_NowPaying_14030d010[1];

      local_78[2] = s_NowPaying_14030d010[2];

      local_78[3] = s_NowPaying_14030d010[3];

      local_78[4] = s_NowPaying_14030d010[4];

      local_78[5] = s_NowPaying_14030d010[5];

      local_78[6] = s_NowPaying_14030d010[6];

      local_78[7] = s_NowPaying_14030d010[7];

      uStack_70 = (ulonglong)(byte)s_NowPaying_14030d010[8];

      DAT_1403f3098 = FUN_14006fe60(local_78);

      _Init_thread_footer(&DAT_1403f309c);

    }

  }

  FUN_140070f90(DAT_1403da23c);

  FUN_140071d20(DAT_1403f3098,DAT_140304c2c,DAT_14039ca58);

  uVar6 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar6 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar6 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar6,uVar6));

  FUN_1400d5d90(param_1,1);

  uVar2 = DAT_14030d038;

  uVar5 = DAT_140304c00;

  uVar4 = DAT_140303754;

  FUN_140071000(DAT_140304c00,DAT_14030d038,DAT_140303390,DAT_140303754,DAT_1403da250);

  FUN_140071000(DAT_140303fd4,uVar2,DAT_140307a40,uVar4,DAT_1403da244);

  uVar2 = DAT_140303354;

  FUN_140071ed0(DAT_1403f3080,uVar5,DAT_14030562c,DAT_140303354,0);

  uVar3 = DAT_140303394;

  FUN_140071ed0(DAT_1403f3090,DAT_140303388,DAT_140303394,uVar2,0);

  FUN_140071ed0(DAT_1403f3090 + 1,

                (*(float *)(param_1 + 0x270) * _DAT_14030d020) / DAT_14030d02c + DAT_140303388,uVar3

                ,uVar2,0);

  if (*(char *)(param_1 + 0x278) != '\0') {

    DAT_1403f30a0 = DAT_1403f30a0 + 1;

  }

  uVar6 = DAT_1403f30a0 / 3 + (DAT_1403f30a0 >> 0x1f) +

          (int)(((longlong)DAT_1403f30a0 / 3 + ((longlong)DAT_1403f30a0 >> 0x3f) & 0xffffffffU) >>

               0x1f) & 0x80000003;

  if ((int)uVar6 < 0) {

    uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;

  }

  FUN_140071ed0(uVar6 + _DAT_1403f3088,uVar5,DAT_14030562c,uVar2,0);

  FUN_1400d5ff0(param_1,0xffffffff);

  uVar5 = DAT_14039ca34;

  uVar3 = DAT_140303fd0;

  FUN_140071000(DAT_140303fd0,DAT_14039ca34,DAT_140303750,DAT_140303398,DAT_1403da23c);

  FUN_140071ed0(DAT_1403f3080 + 1,uVar3,DAT_14030562c,uVar2,0);

  uVar3 = DAT_14030d028;

  uVar2 = DAT_14030335c;

  FUN_140071150(DAT_14030d028,DAT_14030374c,DAT_14030335c,DAT_1403da258,0x10);

  FUN_140071000(uVar3,DAT_140303384,uVar4,uVar5,DAT_1403da258);

  uVar3 = DAT_140304c08;

  FUN_140071150(DAT_140304c08,DAT_140307a40,uVar2,DAT_1403da258,0x10);

  FUN_140071000(uVar3,DAT_140303388,uVar4,uVar5,DAT_1403da258);

  FUN_1400d5ff0(param_1,0);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




