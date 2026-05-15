// Address: 0x1400e25b0
// Ghidra name: FUN_1400e25b0
// ============ 0x1400e25b0 FUN_1400e25b0 (size=3312) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400e25b0(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  longlong *plVar3;

  ulonglong uVar4;

  int iVar5;

  int iVar6;

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  float fVar9;

  undefined4 local_res8;

  undefined8 in_stack_ffffffffffffff58;

  uint uVar11;

  ulonglong uVar10;

  undefined4 uVar12;

  undefined8 *in_stack_ffffffffffffff68;

  undefined4 uVar13;

  undefined8 local_88;

  ulonglong uStack_80;

  undefined8 local_78;

  ulonglong local_70;

  

  uVar11 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);

  FUN_140070f90(*(undefined4 *)(&DAT_1403da9f0 + (longlong)*(int *)(param_1 + 600) * 0x50));

  FUN_1400d6500(param_1,*(undefined4 *)(&DAT_1403da9f4 + (longlong)*(int *)(param_1 + 600) * 0x50));

  uVar4 = (ulonglong)_tls_index;

  if (((*(int *)(param_1 + 600) == 0) && (DAT_1403f4bb2 != '\0')) && (DAT_1403f4bb1 != '\0')) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar4 * 8) + 4) <

         DAT_1403f4c14) && (FUN_1402c7138(&DAT_1403f4c14), DAT_1403f4c14 == -1)) {

      local_78 = 9;

      local_70 = 0xf;

      local_88._0_1_ = s_HintTrack_14030fb58[0];

      local_88._1_1_ = s_HintTrack_14030fb58[1];

      local_88._2_1_ = s_HintTrack_14030fb58[2];

      local_88._3_1_ = s_HintTrack_14030fb58[3];

      local_88._4_1_ = s_HintTrack_14030fb58[4];

      local_88._5_1_ = s_HintTrack_14030fb58[5];

      local_88._6_1_ = s_HintTrack_14030fb58[6];

      local_88._7_1_ = s_HintTrack_14030fb58[7];

      uStack_80 = (ulonglong)(byte)s_HintTrack_14030fb58[8];

      DAT_1403f4c10 = FUN_14006fe60(&local_88);

      _Init_thread_footer(&DAT_1403f4c14);

    }

    if (DAT_1403da921 != '\0') {

      FUN_140071d20(DAT_1403f4c10);

    }

    if (DAT_1403da920 != '\0') {

      FUN_140071d20(DAT_1403f4c10 + 1);

    }

  }

  fVar9 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar9 * *(float *)(param_1 + 0x110),fVar9 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ba0(param_1,3);

  lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar4 * 8);

  if ((*(int *)(lVar1 + 4) < DAT_1403f4c1c) && (FUN_1402c7138(&DAT_1403f4c1c), DAT_1403f4c1c == -1))

  {

    local_78 = 9;

    local_70 = 0xf;

    local_88._0_1_ = s_FarmHouse_14030fb68[0];

    local_88._1_1_ = s_FarmHouse_14030fb68[1];

    local_88._2_1_ = s_FarmHouse_14030fb68[2];

    local_88._3_1_ = s_FarmHouse_14030fb68[3];

    local_88._4_1_ = s_FarmHouse_14030fb68[4];

    local_88._5_1_ = s_FarmHouse_14030fb68[5];

    local_88._6_1_ = s_FarmHouse_14030fb68[6];

    local_88._7_1_ = s_FarmHouse_14030fb68[7];

    uStack_80 = (ulonglong)(byte)s_FarmHouse_14030fb68[8];

    _DAT_1403f4c18 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403f4c1c);

  }

  fVar2 = DAT_140303354;

  fVar9 = *(float *)(*(longlong *)(param_1 + 0x78) + 0x38);

  auVar7._4_4_ = fVar9;

  auVar7._0_4_ = fVar9;

  auVar7._8_4_ = fVar9;

  auVar7._12_4_ = fVar9;

  auVar8._4_12_ = auVar7._4_12_;

  auVar8._0_4_ = (fVar9 + *(float *)(*(longlong *)(param_1 + 0x78) + 0x30)) - DAT_1403065b4;

  uVar10 = (ulonglong)uVar11 << 0x20;

  FUN_140071ed0(*(int *)(param_1 + 600) + _DAT_1403f4c18,auVar8._0_8_);

  if ((*(int *)(param_1 + 600) == 0) || (*(int *)(param_1 + 600) == 5)) {

    if ((*(int *)(lVar1 + 4) < DAT_1403f4c24) &&

       (FUN_1402c7138(&DAT_1403f4c24), DAT_1403f4c24 == -1)) {

      uStack_80 = 0;

      local_78 = 4;

      local_70 = 0xf;

      local_88 = 0x6e726142;

      DAT_1403f4c20 = FUN_14006fe60(&local_88);

      _Init_thread_footer(&DAT_1403f4c24);

    }

    uVar10 = uVar10 & 0xffffffff00000000;

    FUN_140071ed0(DAT_1403f4c20);

    if (*(char *)(param_1 + 0x461) != '\0') {

      uVar10 = uVar10 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403f4c20 + 1);

    }

    if (*(int *)(param_1 + 0x1c0) == 5) {

      uVar10 = uVar10 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403f4c20 + 2);

    }

    if (((*(int *)(param_1 + 0x250) == 2) && (*(int *)(param_1 + 0x254) < 0x96)) ||

       (*(longlong *)(param_1 + 0x440) != 0)) {

      uVar10 = uVar10 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403f4c20 + 3);

    }

    if (((*(int *)(param_1 + 0x250) == 2) && (*(int *)(param_1 + 0x254) < 0x96)) ||

       (*(longlong *)(param_1 + 0x448) != 0)) {

      uVar10 = uVar10 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403f4c20 + 4);

    }

    uVar12 = (undefined4)(uVar10 >> 0x20);

    if (*(int *)(param_1 + 600) == 5) {

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar4 * 8) + 4) <

           DAT_1403f4c2c) && (FUN_1402c7138(&DAT_1403f4c2c), DAT_1403f4c2c == -1)) {

        uStack_80 = 0;

        local_78 = 5;

        local_70 = 0xf;

        local_88 = (ulonglong)CONCAT14(DAT_14030fb78,DAT_14030fb74);

        DAT_1403f4c28 = FUN_14006fe60(&local_88);

        _Init_thread_footer(&DAT_1403f4c2c);

      }

      FUN_140071ed0(DAT_1403f4c28);

      in_stack_ffffffffffffff68 = (undefined8 *)FUN_14008d760(&local_88,&DAT_140307a38);

      if (0xf < (ulonglong)in_stack_ffffffffffffff68[3]) {

        in_stack_ffffffffffffff68 = (undefined8 *)*in_stack_ffffffffffffff68;

      }

      uVar10 = CONCAT44(uVar12,fVar2);

      FUN_140086570(DAT_1403ede28);

      if (0xf < local_70) {

        if ((0xfff < local_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

  }

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar4 * 8) + 4) < DAT_1403f4c34)

     && (FUN_1402c7138(&DAT_1403f4c34), DAT_1403f4c34 == -1)) {

    local_78 = 9;

    local_70 = 0xf;

    local_88._0_1_ = s_TestTrack_14030fb80[0];

    local_88._1_1_ = s_TestTrack_14030fb80[1];

    local_88._2_1_ = s_TestTrack_14030fb80[2];

    local_88._3_1_ = s_TestTrack_14030fb80[3];

    local_88._4_1_ = s_TestTrack_14030fb80[4];

    local_88._5_1_ = s_TestTrack_14030fb80[5];

    local_88._6_1_ = s_TestTrack_14030fb80[6];

    local_88._7_1_ = s_TestTrack_14030fb80[7];

    uStack_80 = (ulonglong)(byte)s_TestTrack_14030fb80[8];

    DAT_1403f4c30 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403f4c34);

  }

  uVar12 = DAT_1403da9ac;

  if (*(int *)(param_1 + 0x1c0) == 2) {

    uVar12 = DAT_1403da9a8;

  }

  FUN_140072640(uVar12);

  uVar10 = uVar10 & 0xffffffff00000000;

  FUN_140071ed0(DAT_1403f4c30);

  FUN_1400727d0();

  FUN_1400d5ff0(param_1,1);

  uVar12 = (undefined4)(uVar10 >> 0x20);

  if ((*(longlong *)(param_1 + 0x458) != 0) &&

     (*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) {

    FUN_140072f50(DAT_14039ca58);

    FUN_140071000();

    FUN_140071000();

    FUN_1400be110(*(undefined8 *)(param_1 + 0x458),CONCAT44(DAT_140309bf0,DAT_140309bf0));

    FUN_140086570(DAT_1403ede20);

    FUN_140086570(DAT_1403ede28);

    FUN_140086570(DAT_1403ede28);

    FUN_1400cf970(param_1,*(undefined8 *)(param_1 + 0x458));

    in_stack_ffffffffffffff68 = (undefined8 *)FUN_14008d760(&local_88,&DAT_14030fbbc);

    FUN_1400cf9d0(param_1,*(undefined8 *)(param_1 + 0x458));

    if (0xf < (ulonglong)in_stack_ffffffffffffff68[3]) {

      in_stack_ffffffffffffff68 = (undefined8 *)*in_stack_ffffffffffffff68;

    }

    uVar10 = CONCAT44(uVar12,fVar2);

    FUN_140086570(DAT_1403ede50);

    if (0xf < local_70) {

      if ((0xfff < local_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    FUN_1400730f0();

  }

  iVar5 = 0;

  if (((*(int *)(param_1 + 0x250) == 2) && (*(int *)(param_1 + 0x254) - 0x1eU < 0x78)) &&

     (*(char *)(param_1 + 0x462) != '\0')) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar4 * 8) + 4) <

         DAT_1403f4c3c) && (FUN_1402c7138(&DAT_1403f4c3c), DAT_1403f4c3c == -1)) {

      uStack_80 = 0;

      local_78 = 7;

      local_70 = 0xf;

      local_88 = (ulonglong)

                 CONCAT16(s_Meiosis_14030fbc8[6],

                          CONCAT24(s_Meiosis_14030fbc8._4_2_,s_Meiosis_14030fbc8._0_4_));

      _DAT_1403f4c38 = FUN_14006fe60(&local_88);

      _Init_thread_footer(&DAT_1403f4c3c);

    }

    uVar10 = uVar10 & 0xffffffff00000000;

    FUN_140071ed0(((*(int *)(param_1 + 0x254) + -0x1e) * 10) / 0x78 + _DAT_1403f4c38);

  }

  if (DAT_1403f4bb2 == '\0') {

    for (plVar3 = *(longlong **)(param_1 + 0x130); plVar3 != *(longlong **)(param_1 + 0x138);

        plVar3 = plVar3 + 1) {

      if (*(char *)(*plVar3 + 0x205) != '\0') {

        if (*(int *)(param_1 + 0xd4) == -1) {

          plVar3 = *(longlong **)(param_1 + 0xb8);

          goto joined_r0x0001400e2dc8;

        }

        if (*(int *)(param_1 + 0x254) % 0x1e < 0xf) {

          FUN_1400b4b10(*plVar3,&local_res8);

          uVar10 = uVar10 & 0xffffffff00000000;

          FUN_140071ed0(*(undefined4 *)

                         (*(longlong *)

                           (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd4) * 8)

                         + 0x3c));

        }

        break;

      }

    }

  }

LAB_1400e2e96:

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  uVar12 = (undefined4)(uVar10 >> 0x20);

  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

  if (((*(int *)(param_1 + 0x250) == 4) ||

      ((*(int *)(param_1 + 0x250) == 3 && (0x2d < *(int *)(param_1 + 0x254))))) &&

     (*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3 != 0)) {

    do {

      FUN_1400d52c0(param_1,iVar5);

      uVar12 = (undefined4)(uVar10 >> 0x20);

      uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

      iVar5 = iVar5 + 1;

    } while ((ulonglong)(longlong)iVar5 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3));

  }

  if (*(int *)(param_1 + 0x250) == 3) {

    local_res8 = DAT_1403da924;

    fVar9 = (float)FUN_1400c6380(*(undefined4 *)(param_1 + 0x254),0,0x23,0x37,CONCAT44(uVar12,0x5a),

                                 0,CONCAT44(uVar13,DAT_14030a2d0));

    local_res8 = CONCAT13((char)(int)fVar9,(undefined3)local_res8);

    FUN_14003f2c0((int)((0xff - ((int)fVar9 & 0xffU)) * DAT_1403d9508) / 0xff);

    FUN_140071000();

  }

  return;

joined_r0x0001400e2dc8:

  if (plVar3 == *(longlong **)(param_1 + 0xc0)) goto LAB_1400e2e96;

  lVar1 = *plVar3;

  if ((*(int *)(lVar1 + 8) == 3) && (*(int *)(lVar1 + 0xc) == 0)) {

    iVar6 = *(int *)(param_1 + 0x254) % 0x1e;

    if (iVar6 == 0) {

      *(float *)(lVar1 + 0x2c) = *(float *)(lVar1 + 0x2c) + fVar2;

    }

    else if (iVar6 == 0xf) {

      *(float *)(lVar1 + 0x2c) = *(float *)(lVar1 + 0x2c) - fVar2;

    }

    goto LAB_1400e2e96;

  }

  plVar3 = plVar3 + 1;

  goto joined_r0x0001400e2dc8;

}




