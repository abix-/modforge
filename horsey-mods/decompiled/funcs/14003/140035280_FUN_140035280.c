// Address: 0x140035280
// Ghidra name: FUN_140035280
// ============ 0x140035280 FUN_140035280 (size=4815) ============


void FUN_140035280(longlong param_1)



{

  int *piVar1;

  float fVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  undefined4 uVar6;

  undefined8 *puVar7;

  uint *puVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  uint uVar12;

  longlong lVar13;

  ulonglong uVar15;

  float fVar16;

  ulonglong uVar17;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  ulonglong local_a0;

  ulonglong uVar14;

  

  FUN_140070f90(DAT_1403d41c4);

  uVar15 = (ulonglong)_tls_index;

  lVar13 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar15 * 8);

  if ((*(int *)(lVar13 + 4) < DAT_1403ea0fc) && (FUN_1402c7138(&DAT_1403ea0fc), DAT_1403ea0fc == -1)

     ) {

    uStack_b0 = 0;

    local_a8 = 6;

    local_a0 = 0xf;

    local_b8 = (ulonglong)CONCAT24(s_Garage_140303f40._4_2_,s_Garage_140303f40._0_4_);

    DAT_1403ea0f8 = FUN_14006fe60(&local_b8);

    _Init_thread_footer(&DAT_1403ea0fc);

  }

  if ((*(int *)(lVar13 + 4) < DAT_1403ea104) && (FUN_1402c7138(&DAT_1403ea104), DAT_1403ea104 == -1)

     ) {

    DAT_1403ea100 = DAT_1403ea0f8 + 6;

    _Init_thread_footer(&DAT_1403ea104);

  }

  FUN_140071d20(DAT_1403ea0f8);

  uVar12 = DAT_14039ca44;

  if (0 < DAT_1403eda04) {

    FUN_140071ed0(DAT_1403ea0f8 + 1);

  }

  uVar6 = DAT_140304028;

  if (0 < DAT_1403eda00) {

    FUN_140071000();

  }

  FUN_140071000();

  FUN_140071000();

  FUN_140071000();

  uVar17 = (ulonglong)DAT_1403d4148;

  FUN_140071000();

  iVar9 = 0;

  if (*(int *)(param_1 + 0x250) == 4) {

    uVar17 = (ulonglong)DAT_1403d41a8;

    FUN_140071000();

    if (0 < DAT_1403eda00 + 0xe) {

      do {

        iVar4 = FUN_1400c6df0(*(int *)(param_1 + 0x254) - iVar9,0x20);

        if (iVar4 == 0) {

          puVar8 = &DAT_1403ea0a0;

LAB_14003550b:

          uVar17 = (ulonglong)*puVar8;

          FUN_140071000();

        }

        else {

          if (iVar4 == 8) {

            puVar8 = &DAT_1403ea0a4;

            goto LAB_14003550b;

          }

          if (iVar4 == 0x10) {

            puVar8 = &DAT_1403ea0a8;

            goto LAB_14003550b;

          }

          if (iVar4 == 0x18) {

            puVar8 = &DAT_1403ea0ac;

            goto LAB_14003550b;

          }

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < DAT_1403eda00 + 0xe);

      uVar15 = (ulonglong)_tls_index;

    }

  }

  if (*(char *)(param_1 + 0x6b0) != '\0') {

    if ((*(int *)(lVar13 + 4) < DAT_1403ea10c) &&

       (FUN_1402c7138(&DAT_1403ea10c), DAT_1403ea10c == -1)) {

      local_a8 = 10;

      local_a0 = 0xf;

      local_b8._0_1_ = s_ItemMemory_140303f48[0];

      local_b8._1_1_ = s_ItemMemory_140303f48[1];

      local_b8._2_1_ = s_ItemMemory_140303f48[2];

      local_b8._3_1_ = s_ItemMemory_140303f48[3];

      local_b8._4_1_ = s_ItemMemory_140303f48[4];

      local_b8._5_1_ = s_ItemMemory_140303f48[5];

      local_b8._6_1_ = s_ItemMemory_140303f48[6];

      local_b8._7_1_ = s_ItemMemory_140303f48[7];

      uStack_b0 = (ulonglong)(ushort)s_ItemMemory_140303f48._8_2_;

      DAT_1403ea108 = FUN_14006fe60(&local_b8);

      _Init_thread_footer(&DAT_1403ea10c);

    }

    FUN_140071d20(DAT_1403ea108);

  }

  FUN_140071d20((0 < *(int *)(param_1 + 0x27c)) + 3 + DAT_1403ea0f8);

  FUN_140072e40(CONCAT44(DAT_140303fcc,uVar6));

  uVar5 = DAT_14039ca80;

  iVar9 = *(int *)(param_1 + 0x27c);

  if (iVar9 == 1) {

    FUN_140086570(DAT_1403ede38);

    FUN_140071000();

    iVar9 = *(int *)(param_1 + 0x280);

    iVar4 = 0x43;

    do {

      iVar10 = 0xa2;

      do {

        FUN_140071000();

        iVar10 = iVar10 + 1;

      } while (iVar10 < 0xaa);

      iVar10 = 0xb7;

      do {

        uVar5 = iVar9 / 2 + iVar4 + iVar10 & 0x80000003;

        if ((int)uVar5 < 0) {

          uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;

        }

        uVar17 = (ulonglong)(uint)(&DAT_1403ea0a0)[(int)uVar5];

        FUN_140071000();

        iVar10 = iVar10 + 1;

      } while (iVar10 < 0xbe);

      iVar4 = iVar4 + 1;

    } while (iVar4 < 0x45);

    uVar15 = (ulonglong)_tls_index;

  }

  else if (iVar9 == 5) {

    if (*(int *)(param_1 + 0x280) < 0xb5) {

      FUN_140086570(DAT_1403ede38);

      FUN_140071000();

      uVar17 = 0;

      FUN_140071ed0(DAT_1403ea100);

    }

    if (0xb4 < *(int *)(param_1 + 0x280)) {

      uVar17 = (ulonglong)DAT_1403d4160;

      FUN_140071000();

    }

  }

  else if (0 < iVar9) {

    FUN_140071d20(DAT_1403ea100 + -1);

    iVar9 = 0xc;

    do {

      FUN_14008d760(&local_b8,&DAT_14039bf04);

      uVar17 = (ulonglong)uVar12;

      FUN_140086570(DAT_1403ede38);

      if (0xf < local_a0) {

        if ((0xfff < local_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      fVar16 = DAT_140303ff4;

      iVar9 = iVar9 + 0xc;

    } while (iVar9 < 0x3c);

    fVar2 = *(float *)(*(longlong *)(param_1 + 0x2a0) + 8);

    if (*(int *)(*(longlong *)(param_1 + 0x2a0) + 4) < 0x12d) {

      FUN_140071d20(DAT_1403ea100);

    }

    else {

      uVar17 = (ulonglong)uVar5;

      FUN_140071ed0(DAT_1403ea100,fVar2 + fVar2 + DAT_140303ff4);

    }

    fVar2 = *(float *)(*(longlong *)(param_1 + 0x2a0) + 0x18);

    if (*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x14) < 0x12d) {

      FUN_140071d20(DAT_1403ea100);

    }

    else {

      uVar17 = (ulonglong)uVar5;

      FUN_140071ed0(DAT_1403ea100,fVar2 + fVar2 + fVar16);

    }

    fVar2 = *(float *)(*(longlong *)(param_1 + 0x2a0) + 0x28);

    if (*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x24) < 0x12d) {

      FUN_140071d20(DAT_1403ea100);

    }

    else {

      uVar17 = (ulonglong)uVar5;

      FUN_140071ed0(DAT_1403ea100,fVar2 + fVar2 + fVar16);

    }

    fVar2 = *(float *)(*(longlong *)(param_1 + 0x2a0) + 0x38);

    if (*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x34) < 0x12d) {

      FUN_140071d20(DAT_1403ea100);

    }

    else {

      uVar17 = (ulonglong)uVar5;

      FUN_140071ed0(DAT_1403ea100,fVar2 + fVar2 + fVar16);

    }

  }

  uVar14 = 0;

  if (1 < *(int *)(param_1 + 0x27c)) {

    puVar7 = (undefined8 *)

             FUN_14008d760(&local_b8,"R:%d/%d",*(int *)(param_1 + 0x278) + 1,

                           (int)((*(int *)(param_1 + 0x6ac) >> 0x1f & 3U) +

                                *(int *)(param_1 + 0x6ac)) >> 2,uVar17);

    if (0xf < (ulonglong)puVar7[3]) {

      puVar7 = (undefined8 *)*puVar7;

    }

    uVar17 = (ulonglong)uVar12;

    uVar6 = DAT_1403d4184;

    FUN_140086570(DAT_1403ede38);

    if (0xf < local_a0) {

      if ((0xfff < local_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    FUN_14008d760(&local_b8,"G:%d/%d",*(int *)(param_1 + 0x288) + 1,*(undefined4 *)(param_1 + 0x6a8)

                  ,uVar17,uVar6,puVar7);

    FUN_140086570(DAT_1403ede38);

    if (0xf < local_a0) {

      if ((0xfff < local_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    FUN_14008d760(&local_b8,"V:%d%%");

    FUN_140086570(DAT_1403ede38);

    if (0xf < local_a0) {

      if ((0xfff < local_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (*(int *)(param_1 + 0x298) < 1) {

      FUN_140086570(DAT_1403ede38);

    }

    else {

      FUN_14008d760(&local_b8,"T:%.1f");

      FUN_140086570(DAT_1403ede38);

      if (0xf < local_a0) {

        if ((0xfff < local_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

  }

  FUN_1400730f0();

  if (*(int *)(param_1 + 0x250) == 3) {

    FUN_1400c5f50((*(int *)(param_1 + 0x254) + -0x5a) / 2,0,0x58);

  }

  lVar13 = 8;

  do {

    FUN_140071000();

    FUN_140071000();

    lVar13 = lVar13 + -1;

  } while (lVar13 != 0);

  FUN_140071000();

  FUN_140071000();

  if (*(int *)(param_1 + 0x250) != 0) {

    if ((*(int *)(param_1 + 0x250) == 1) && (0x3c < *(int *)(param_1 + 0x254))) {

      *(int *)(param_1 + 0x698) = *(int *)(param_1 + 0x698) + 1;

    }

    iVar9 = ((int)((*(int *)(param_1 + 0x690) >> 0x1f & 0x1fU) + *(int *)(param_1 + 0x690)) >> 5) -

            ((0 < *(int *)(param_1 + 0x694)) + 2);

    if (0 < iVar9) {

      FUN_140071000();

    }

    if (0 < *(int *)(param_1 + 0x694)) {

      iVar4 = *(int *)(param_1 + 0x694) + -1;

      *(int *)(param_1 + 0x694) = iVar4;

      iVar4 = iVar4 / 3;

      FUN_140071d20(DAT_1403ea0f8 + 7 +

                    iVar4 + (iVar4 / 3 + (iVar4 >> 0x1f) +

                            (int)(((longlong)iVar4 / 3 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >>

                                 0x1f)) * -3);

    }

    FUN_140072ed0();

    iVar4 = FUN_1400c6580(0x201);

    lVar13 = *(longlong *)(param_1 + 0x678);

    if ((*(longlong *)(param_1 + 0x680) - lVar13) / 0xc != 0) {

      lVar11 = 0;

      uVar15 = uVar14;

      do {

        if (((0 < *(int *)(param_1 + 0x694)) &&

            (iVar10 = *(int *)(param_1 + 0x694) + (int)uVar14, iVar10 == (iVar10 / 10) * 10)) ||

           ((longlong)iVar4 == uVar15)) {

          bVar3 = FUN_1400c66c0();

          *(int *)(lVar11 + lVar13) = *(int *)(lVar11 + lVar13) + (uint)bVar3 * 2 + -1;

          bVar3 = FUN_1400c66c0();

          piVar1 = (int *)(lVar11 + 4 + lVar13);

          *piVar1 = *piVar1 + (uint)bVar3 * 2 + -1;

          uVar6 = FUN_1400c5f50(*(undefined4 *)(lVar11 + lVar13),0,0x23);

          *(undefined4 *)(lVar11 + lVar13) = uVar6;

          uVar6 = FUN_1400c5f50(*(undefined4 *)(lVar11 + 4 + lVar13),0x1e - iVar9,0x1e);

          *(undefined4 *)(lVar11 + 4 + lVar13) = uVar6;

        }

        FUN_140071000();

        uVar12 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar12;

        uVar15 = uVar15 + 1;

        lVar11 = lVar11 + 0xc;

        lVar13 = *(longlong *)(param_1 + 0x678);

      } while ((ulonglong)(longlong)(int)uVar12 <

               (ulonglong)((*(longlong *)(param_1 + 0x680) - lVar13) / 0xc));

    }

    FUN_1400730f0();

    if (((*(int *)(param_1 + 0xd4) == -1) ||

        (*(int *)(*(longlong *)

                   (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd4) * 8) + 0xc)

         != 0xc)) || (*(int *)(param_1 + 0x250) != 3)) {

      uVar15 = (ulonglong)_tls_index;

    }

    else if (*(int *)(param_1 + 0x27c) == 0) {

      uVar15 = (ulonglong)_tls_index;

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar15 * 8) + 4) <

           DAT_1403ea114) && (FUN_1402c7138(&DAT_1403ea114), DAT_1403ea114 == -1)) {

        local_a8 = 8;

        local_a0 = 0xf;

        local_b8 = 0x657265486e776f44;

        uStack_b0 = 0;

        DAT_1403ea110 = FUN_14006fe60(&local_b8);

        _Init_thread_footer(&DAT_1403ea114);

      }

      FUN_140071d20(DAT_1403ea110);

    }

    else {

      uVar15 = (ulonglong)_tls_index;

    }

  }

  FUN_140071d20(DAT_1403ea0f8 + 2);

  if ((((*(char *)(param_1 + 0x6b0) == '\0') && (*(int *)(param_1 + 0xd4) != -1)) &&

      (*(int *)(*(longlong *)

                 (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd4) * 8) + 0xc) ==

       0x30)) && ((*(int *)(param_1 + 0x250) == 3 && (*(int *)(param_1 + 0x27c) == 0)))) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar15 * 8) + 4) <

         DAT_1403ea11c) && (FUN_1402c7138(&DAT_1403ea11c), DAT_1403ea11c == -1)) {

      local_a8 = 0xd;

      local_a0 = 0xf;

      local_b8._0_1_ = s_PointerAttach_140303fa0[0];

      local_b8._1_1_ = s_PointerAttach_140303fa0[1];

      local_b8._2_1_ = s_PointerAttach_140303fa0[2];

      local_b8._3_1_ = s_PointerAttach_140303fa0[3];

      local_b8._4_1_ = s_PointerAttach_140303fa0[4];

      local_b8._5_1_ = s_PointerAttach_140303fa0[5];

      local_b8._6_1_ = s_PointerAttach_140303fa0[6];

      local_b8._7_1_ = s_PointerAttach_140303fa0[7];

      uStack_b0 = (ulonglong)

                  CONCAT14(s_PointerAttach_140303fa0[0xc],s_PointerAttach_140303fa0._8_4_);

      DAT_1403ea118 = FUN_14006fe60(&local_b8);

      _Init_thread_footer(&DAT_1403ea11c);

    }

    if (*(int *)(param_1 + 0x254) % 0x14 < 10) {

      FUN_140071d20(DAT_1403ea118);

      FUN_140071ed0(DAT_1403ea118);

      FUN_140071ed0(DAT_1403ea118);

      FUN_140071ed0(DAT_1403ea118);

    }

  }

  fVar16 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar16 * *(float *)(param_1 + 0x110),fVar16 * *(float *)(param_1 + 0x10c)))

  ;

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




