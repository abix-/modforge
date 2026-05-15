// Address: 0x140069880
// Ghidra name: FUN_140069880
// ============ 0x140069880 FUN_140069880 (size=1419) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140069880(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  float fVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  uint uVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float local_res10;

  float local_res14;

  undefined4 uVar14;

  undefined4 uVar15;

  undefined8 local_98;

  ulonglong uStack_90;

  undefined8 local_88;

  undefined8 local_80;

  

  lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if (*(int *)(lVar1 + 4) < DAT_1403eabc4) {

    FUN_1402c7138(&DAT_1403eabc4);

    if (DAT_1403eabc4 == -1) {

      local_88 = 10;

      local_80 = 0xf;

      local_98._0_1_ = s_powerplant_140309ba8[0];

      local_98._1_1_ = s_powerplant_140309ba8[1];

      local_98._2_1_ = s_powerplant_140309ba8[2];

      local_98._3_1_ = s_powerplant_140309ba8[3];

      local_98._4_1_ = s_powerplant_140309ba8[4];

      local_98._5_1_ = s_powerplant_140309ba8[5];

      local_98._6_1_ = s_powerplant_140309ba8[6];

      local_98._7_1_ = s_powerplant_140309ba8[7];

      uStack_90 = (ulonglong)(ushort)s_powerplant_140309ba8._8_2_;

      DAT_1403eabc0 = FUN_14006fe60(&local_98);

      _Init_thread_footer(&DAT_1403eabc4);

    }

  }

  uVar9 = DAT_1403d9138;

  if (*(char *)(param_1 + 0x270) != '\0') {

    uVar9 = DAT_1403d9154;

  }

  FUN_140070f90(uVar9);

  FUN_140072750(0x80);

  FUN_140071ed0(DAT_1403eabc0,0,DAT_140309c24,(float)DAT_14030b680 / DAT_140309c10,0);

  FUN_1400727d0();

  if (*(int *)(lVar1 + 4) < DAT_1403eabcc) {

    FUN_1402c7138(&DAT_1403eabcc);

    if (DAT_1403eabcc == -1) {

      uStack_90 = 0;

      local_88 = 5;

      local_80 = 0xf;

      local_98 = (ulonglong)CONCAT14(DAT_140309bb8,DAT_140309bb4);

      DAT_1403eabc8 = FUN_14006fe60(&local_98);

      _Init_thread_footer(&DAT_1403eabcc);

    }

  }

  uVar3 = DAT_140309c04;

  uVar9 = DAT_140303754;

  FUN_140071d20(DAT_1403eabc8,DAT_140309c04,DAT_140303754);

  FUN_140071d20(DAT_1403eabc8 + 1,uVar3,uVar9);

  iVar7 = DAT_1403eabc8;

  FUN_1400c6180(*(uint *)(param_1 + 0x268) & _DAT_14039cab0,DAT_140303394,DAT_140309c00);

  uVar4 = DAT_14039ca44;

  uVar15 = 0;

  uVar14 = DAT_14039ca44;

  FUN_140071f00(iVar7 + 2,DAT_140309c08,DAT_140305f74);

  FUN_140071d20((4 - (uint)(*(char *)(param_1 + 0x270) != '\0')) + DAT_1403eabc8,uVar3,uVar9);

  uVar6 = DAT_14039cac0;

  uVar10 = *(uint *)(param_1 + 0x114);

  fVar12 = (float)(uVar10 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110);

  FUN_140072fe0(CONCAT44(fVar12,(float)(uVar10 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar10,uVar10),fVar12,uVar14,uVar15);

  uVar9 = FUN_1402cd4c0(*(undefined4 *)(*(longlong *)(param_1 + 600) + 0x14),

                        *(undefined4 *)(*(longlong *)(param_1 + 600) + 0x18));

  FUN_140072fe0(CONCAT44(DAT_1403d9178._4_4_,(float)DAT_1403d9178),uVar9,CONCAT44(uVar4,uVar4));

  FUN_140071150(0,0,DAT_140307a44,DAT_1403d9164,0x1f);

  fVar2 = DAT_140309bf0;

  FUN_140071150(0,0,DAT_140309bf0,DAT_1403d90dc,0x1f);

  FUN_140071150(0,0,DAT_140309bec,DAT_1403d90d8,0x1f);

  fVar5 = DAT_14039ca54;

  fVar12 = DAT_140303ff4;

  uVar9 = DAT_140303fb4;

  iVar8 = 0;

  iVar7 = iVar8;

  do {

    fVar13 = ((float)iVar7 * fVar5) / fVar12;

    local_res10 = (float)FUN_1402cfda0(fVar13);

    local_res10 = local_res10 * fVar2;

    uVar10 = FUN_1402cdc50(fVar13);

    local_res14 = (float)(uVar10 ^ uVar6) * fVar2;

    FUN_140071990(&DAT_1403ffbe8,&local_res10,uVar9,&DAT_1403d90d8);

    iVar7 = iVar7 + 1;

  } while (iVar7 < 0x1f);

  FUN_1400730f0();

  FUN_1400d5ff0(param_1,0xffffffff);

  fVar5 = DAT_14039ca50;

  fVar12 = DAT_14039ca34;

  uVar9 = DAT_14030335c;

  do {

    fVar13 = (float)FUN_1402cd4c0(*(undefined4 *)(*(longlong *)(param_1 + 600) + 0x14),

                                  *(undefined4 *)(*(longlong *)(param_1 + 600) + 0x18));

    fVar13 = (float)iVar8 * fVar5 * fVar12 - fVar13;

    fVar11 = (float)FUN_1402cfda0(fVar13);

    local_res10 = fVar11 * fVar2 + (float)DAT_1403d9178;

    fVar13 = (float)FUN_1402cdc50(fVar13);

    local_res14 = DAT_1403d9178._4_4_ - fVar13 * fVar2;

    FUN_140071990(&DAT_1403d9178,&local_res10,uVar9,&DAT_1403d9164);

    iVar8 = iVar8 + 1;

  } while (iVar8 < 4);

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,0);

  FUN_1400730f0();

  if (*(int *)(lVar1 + 4) < DAT_1403eabd4) {

    FUN_1402c7138(&DAT_1403eabd4);

    if (DAT_1403eabd4 == -1) {

      local_88 = 9;

      local_80 = 0xf;

      local_98._0_1_ = s_Lightbulb_140309bc0[0];

      local_98._1_1_ = s_Lightbulb_140309bc0[1];

      local_98._2_1_ = s_Lightbulb_140309bc0[2];

      local_98._3_1_ = s_Lightbulb_140309bc0[3];

      local_98._4_1_ = s_Lightbulb_140309bc0[4];

      local_98._5_1_ = s_Lightbulb_140309bc0[5];

      local_98._6_1_ = s_Lightbulb_140309bc0[6];

      local_98._7_1_ = s_Lightbulb_140309bc0[7];

      uStack_90 = (ulonglong)(byte)s_Lightbulb_140309bc0[8];

      _DAT_1403eabd0 = FUN_14006fe60(&local_98);

      _Init_thread_footer(&DAT_1403eabd4);

    }

  }

  FUN_140071d20((uint)(*(char *)(param_1 + 0x270) != '\0') + _DAT_1403eabd0,DAT_140309c0c,

                DAT_140304008);

  FUN_1400cacd0(param_1,1);

  return;

}




