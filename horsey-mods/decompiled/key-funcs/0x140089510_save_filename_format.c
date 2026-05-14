// Hint: save_filename_format
// Address: 0x140089510
// Ghidra name: FUN_140089510
// ============ 0x140089510 FUN_140089510 (size=8654) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140089510(longlong param_1)



{

  uint *puVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  undefined4 uVar6;

  char cVar7;

  int iVar8;

  undefined4 uVar9;

  int *piVar10;

  undefined8 uVar11;

  longlong lVar12;

  int iVar13;

  longlong lVar14;

  char *pcVar15;

  uint uVar16;

  int *piVar18;

  ulonglong uVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  undefined1 local_res8 [8];

  ulonglong in_stack_fffffffffffffd78;

  uint7 uVar23;

  undefined4 uVar24;

  char *local_278;

  undefined8 uStack_270;

  undefined8 local_268;

  ulonglong uStack_260;

  undefined1 local_248 [544];

  ulonglong uVar17;

  

  if (*(int *)(param_1 + 0x250) == 0xc) {

    (**(code **)(*DAT_1403fb0d8 + 0x40))();

    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)((longlong)DAT_1403fb0d8 + 0x124);

    piVar10 = (int *)FUN_1400a8e00(DAT_1403fb0d8[0x60]);

    if ((*piVar10 == 4) && (DAT_1403ed558 == '\0')) {

      return;

    }

    DAT_1403ed558 = 0;

    *(undefined8 *)(param_1 + 0x250) = 0xd;

    return;

  }

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  uVar9 = 3;

  FUN_1400ca150(param_1,3,7);

  FUN_1400ca150(param_1,2);

  if (((*(longlong *)(param_1 + 0x270) != 0) && (*(int *)(param_1 + 0x250) == 2)) &&

     (DAT_1403ed4c1 != '\0')) {

    if (DAT_1403ed633 != '\0') {

      *(undefined4 *)(param_1 + 0xe0) = 0xd;

    }

    if ((DAT_1403ed4c1 != '\0') && (DAT_1403ed646 != '\0')) {

      *(undefined4 *)(param_1 + 0xe0) = 0xe;

    }

  }

  *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + 1;

  uVar17 = 0;

  if (*(int *)(param_1 + 0x250) == 0) {

    iVar8 = *(int *)(param_1 + 0x494);

    if (0 < iVar8) {

      iVar8 = iVar8 + -1;

      *(int *)(param_1 + 0x494) = iVar8;

    }

    iVar13 = *(int *)(param_1 + 0xe0);

    if (iVar13 == 0xb) {

      if (iVar8 == 0) {

        *(undefined4 *)(param_1 + 0x498) = 1;

      }

      if ((*(int *)(param_1 + 0x498) == 7) || (DAT_1403d959b != '\0')) {

        *(undefined8 *)(param_1 + 0x250) = 1;

        uVar11 = FUN_1400279c0(&local_278,param_1 + 0x38);

        FUN_14003f340(uVar11,1);

        iVar13 = *(int *)(param_1 + 0xe0);

      }

      else {

        *(int *)(param_1 + 0x498) = *(int *)(param_1 + 0x498) + 1;

      }

      *(undefined4 *)(param_1 + 0x494) = 0x1e;

    }

    if (*(int *)(param_1 + 0xd8) != 0) {

      *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;

    }

    if (iVar13 != 0) {

      *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;

    }

  }

  if ((*(int *)(param_1 + 0x250) != 6) && (*(int *)(param_1 + 0x250) != 5)) {

    FUN_1400886a0(param_1);

  }

  uVar6 = DAT_14039ca44;

  uVar20 = _UNK_1403040b8;

  uVar11 = _DAT_1403040b0;

  uVar2 = DAT_140303758;

  iVar8 = *(int *)(param_1 + 0xe0);

  uVar23 = (uint7)(in_stack_fffffffffffffd78 >> 8);

  if (iVar8 == 0) {

    iVar13 = *(int *)(param_1 + 0x250);

    if (iVar13 < 3) {

      if (*(int *)(param_1 + 0x488) != -1) {

        FUN_140040ea0();

        *(undefined4 *)(param_1 + 0x488) = 0xffffffff;

      }

      FUN_1400cdae0(param_1);

      uVar11 = _DAT_1403040b0;

      uVar20 = _UNK_1403040b8;

    }

    else {

LAB_14008a0c2:

      if (iVar8 == 0xc) {

        if (((*(int *)(param_1 + 0x250) == 2) && (*(longlong *)(param_1 + 0x270) != 0)) &&

           ((*(int *)(*(longlong *)(param_1 + 0x270) + 0xc) == 0xc &&

            (0.0 < *(float *)((longlong)DAT_1403fb0d8 + 0x39c))))) {

          *(undefined8 *)(param_1 + 0x250) = 0xb;

        }

      }

      else if (iVar8 == 0xd) {

        if (((iVar13 == 2) && (lVar14 = *(longlong *)(param_1 + 0x270), lVar14 != 0)) &&

           (*(int *)(lVar14 + 0xc) == 0xc)) {

          FUN_1400a5400(*(undefined8 *)(lVar14 + 0x78));

          *(undefined8 *)(param_1 + 0x250) = 9;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

      }

      else if (iVar8 == 0xe) {

        if (((iVar13 == 2) && (lVar14 = *(longlong *)(param_1 + 0x270), lVar14 != 0)) &&

           (*(int *)(lVar14 + 0xc) == 0xc)) {

          FUN_1400a58b0(*(undefined8 *)(lVar14 + 0x78));

          *(undefined8 *)(param_1 + 0x250) = 10;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

      }

      else if (iVar8 == 10) {

        local_268 = _DAT_1403040b0;

        uStack_260 = _UNK_1403040b8;

        local_278 = (char *)s_ComputerBeep_14030b400._0_8_;

        uStack_270 = (ulonglong)(uint)s_ComputerBeep_14030b400._8_4_;

        in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

        FUN_140040ca0(&local_278,100,0x32,DAT_14039ca44,in_stack_fffffffffffffd78);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        uVar11 = _DAT_1403040b0;

        uVar20 = _UNK_1403040b8;

        if (*(int *)(param_1 + 0x280) == 0) {

          *(undefined4 *)(param_1 + 0x280) = 3;

LAB_14008a224:

          *(undefined4 *)(param_1 + 0x284) = 0x3c;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

      }

    }

  }

  else if (iVar8 == 8) {

    uVar16 = *(int *)(param_1 + 0x25c) + 1U & 0x80000001;

    if ((int)uVar16 < 0) {

      uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;

    }

    *(uint *)(param_1 + 0x25c) = uVar16;

    pcVar15 = "SwitchToGeneDrive";

    if (uVar16 == 1) {

      pcVar15 = "SwitchToExtract";

    }

    local_278 = (char *)0x0;

    uStack_270 = 0;

    local_268 = 0;

    uStack_260 = 0;

    strlen(pcVar15);

    FUN_140027e30(&local_278,pcVar15);

    in_stack_fffffffffffffd78 = in_stack_fffffffffffffd78 & 0xffffffffffffff00;

    FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78);

    uVar11 = _DAT_1403040b0;

    uVar20 = _UNK_1403040b8;

    if (0xf < uStack_260) {

      if ((0xfff < uStack_260 + 1) &&

         ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

LAB_140089807:

      FUN_1402c7088();

      uVar11 = _DAT_1403040b0;

      uVar20 = _UNK_1403040b8;

    }

  }

  else if (iVar8 == 7) {

    if (*(int *)(param_1 + 0x250) == 2) {

      *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;

      *(undefined1 *)(param_1 + 0x264) = 1;

      if (*(int *)(param_1 + 0x25c) == 1) {

        cVar7 = FUN_140088990(param_1,param_1 + 0x4a0);

        local_278 = (char *)0x0;

        uStack_270 = 0;

        if (cVar7 == '\0') {

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x40);

          uVar11 = _UNK_14030b2a8;

          local_268 = _DAT_140306040;

          uStack_260 = _UNK_140306048;

          *(undefined8 *)local_278 = _DAT_14030b2a0;

          *(undefined8 *)(local_278 + 8) = uVar11;

          uVar11 = _UNK_14030b2b8;

          *(undefined8 *)(local_278 + 0x10) = _DAT_14030b2b0;

          *(undefined8 *)(local_278 + 0x18) = uVar11;

          uVar11 = _UNK_14030b2c8;

          *(undefined8 *)(local_278 + 0x20) = _DAT_14030b2c0;

          *(undefined8 *)(local_278 + 0x28) = uVar11;

          *(undefined8 *)(local_278 + 0x30) = DAT_14030b2d0;

          *(undefined4 *)(local_278 + 0x38) = DAT_14030b2d8;

          *(undefined2 *)(local_278 + 0x3c) = DAT_14030b2dc;

          local_278[0x3e] = DAT_14030b2de;

          local_278[0x3f] = '\0';

          uVar11 = CONCAT44((int)(in_stack_fffffffffffffd78 >> 0x20),uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar11);

          uVar24 = (undefined4)((ulonglong)uVar11 >> 0x20);

          if (0xf < uStack_260) {

            FUN_140028310(&local_278,local_278);

          }

          local_278 = (char *)0x0;

          uStack_270 = 0;

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x20);

          uVar11 = s_A_horse_would_be_my_suggestion_14030b2e0._8_8_;

          local_268 = _DAT_140303770;

          uStack_260 = _UNK_140303778;

          *(undefined8 *)local_278 = s_A_horse_would_be_my_suggestion_14030b2e0._0_8_;

          *(undefined8 *)(local_278 + 8) = uVar11;

          *(undefined8 *)(local_278 + 0x10) = s_A_horse_would_be_my_suggestion_14030b2e0._16_8_;

          *(undefined4 *)(local_278 + 0x18) = s_A_horse_would_be_my_suggestion_14030b2e0._24_4_;

          *(undefined2 *)(local_278 + 0x1c) = s_A_horse_would_be_my_suggestion_14030b2e0._28_2_;

          local_278[0x1e] = '\0';

          in_stack_fffffffffffffd78 = CONCAT44(uVar24,uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                        in_stack_fffffffffffffd78);

          if (0xf < uStack_260) {

            if ((0xfff < uStack_260 + 1) &&

               ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        else {

          local_268 = _DAT_140303400;

          uStack_260 = _UNK_140303408;

          local_278 = (char *)s_StartDNAExtract_14030b300._0_8_;

          uStack_270._0_6_ =

               CONCAT24(s_StartDNAExtract_14030b300._12_2_,s_StartDNAExtract_14030b300._8_4_);

          uStack_270 = (ulonglong)CONCAT16(s_StartDNAExtract_14030b300[0xe],(uint6)uStack_270);

          in_stack_fffffffffffffd78 = in_stack_fffffffffffffd78 & 0xffffffffffffff00;

          FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78);

          if (0xf < uStack_260) {

            if ((0xfff < uStack_260 + 1) &&

               ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          uVar9 = 4;

        }

        *(undefined4 *)(param_1 + 0x250) = uVar9;

        *(undefined4 *)(param_1 + 0x254) = 0;

        uVar11 = _DAT_1403040b0;

        uVar20 = _UNK_1403040b8;

      }

      else {

        local_278 = (char *)0x0;

        uStack_270 = 0;

        if (*(longlong *)(param_1 + 0x270) == 0) {

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x30);

          uVar11 = _UNK_14030b318;

          local_268 = _DAT_140304150;

          uStack_260 = _UNK_140304158;

          *(undefined8 *)local_278 = _DAT_14030b310;

          *(undefined8 *)(local_278 + 8) = uVar11;

          uVar11 = s_for_that_14030b327._1_8_;

          *(undefined8 *)(local_278 + 0x10) = _DAT_14030b320;

          *(undefined8 *)(local_278 + 0x18) = uVar11;

          local_278[0x20] = '\0';

          uVar11 = CONCAT44((int)(in_stack_fffffffffffffd78 >> 0x20),uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar11);

          uVar9 = (undefined4)((ulonglong)uVar11 >> 0x20);

          if (0xf < uStack_260) {

            if ((0xfff < uStack_260 + 1) &&

               ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          local_278 = (char *)0x0;

          uStack_270 = 0;

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x40);

          uVar11 = _UNK_14030b340;

          local_268 = _DAT_14030b670;

          uStack_260 = _UNK_14030b678;

          *(undefined8 *)local_278 = _DAT_14030b338;

          *(undefined8 *)(local_278 + 8) = uVar11;

          uVar11 = _UNK_14030b350;

          *(undefined8 *)(local_278 + 0x10) = _DAT_14030b348;

          *(undefined8 *)(local_278 + 0x18) = uVar11;

          uVar11 = s_using_this_very_same_machine_14030b355._11_8_;

          *(undefined8 *)(local_278 + 0x20) = s_using_this_very_same_machine_14030b355._3_8_;

          *(undefined8 *)(local_278 + 0x28) = uVar11;

          *(undefined8 *)(local_278 + 0x30) = s_using_this_very_same_machine_14030b355._19_8_;

          *(undefined2 *)(local_278 + 0x38) = s_using_this_very_same_machine_14030b355._27_2_;

          local_278[0x3a] = '\0';

          in_stack_fffffffffffffd78 = CONCAT44(uVar9,uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                        in_stack_fffffffffffffd78);

LAB_140089be1:

          if (0xf < uStack_260) {

            FUN_140028310(&local_278,local_278);

          }

          *(undefined8 *)(param_1 + 0x250) = 3;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

        else if (*(int *)(*(longlong *)(param_1 + 0x270) + 0xc) == 0xc) {

          if (*(longlong *)(param_1 + 0x4a0) == *(longlong *)(param_1 + 0x4a8)) {

            local_268 = 0;

            uStack_260 = 0;

            local_278 = (char *)FUN_1400285e0(0x20);

            uVar11 = s_Gene_Drive_must_have_a_target_14030b390._8_8_;

            local_268 = _DAT_140304d00;

            uStack_260 = _UNK_140304d08;

            *(undefined8 *)local_278 = s_Gene_Drive_must_have_a_target_14030b390._0_8_;

            *(undefined8 *)(local_278 + 8) = uVar11;

            *(undefined8 *)(local_278 + 0x10) = s_Gene_Drive_must_have_a_target_14030b390._16_8_;

            *(undefined4 *)(local_278 + 0x18) = s_Gene_Drive_must_have_a_target_14030b390._24_4_;

            local_278[0x1c] = s_Gene_Drive_must_have_a_target_14030b390[0x1c];

            local_278[0x1d] = '\0';

            uVar11 = CONCAT44((int)(in_stack_fffffffffffffd78 >> 0x20),uVar2);

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar11);

            uVar9 = (undefined4)((ulonglong)uVar11 >> 0x20);

            if (0xf < uStack_260) {

              FUN_140028310(&local_278,local_278);

            }

            local_278 = (char *)0x0;

            uStack_270 = 0;

            local_268 = 0;

            uStack_260 = 0;

            local_278 = (char *)FUN_1400285e0(0x30);

            uVar11 = s_Put_a_horse_in_the_chamber_first_14030b3b0._8_8_;

            local_268 = _DAT_140304150;

            uStack_260 = _UNK_140304158;

            *(undefined8 *)local_278 = s_Put_a_horse_in_the_chamber_first_14030b3b0._0_8_;

            *(undefined8 *)(local_278 + 8) = uVar11;

            uVar11 = s_Put_a_horse_in_the_chamber_first_14030b3b0._24_8_;

            *(undefined8 *)(local_278 + 0x10) = s_Put_a_horse_in_the_chamber_first_14030b3b0._16_8_;

            *(undefined8 *)(local_278 + 0x18) = uVar11;

            local_278[0x20] = '\0';

            in_stack_fffffffffffffd78 = CONCAT44(uVar9,uVar2);

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                          in_stack_fffffffffffffd78);

            goto LAB_140089be1;

          }

          local_268 = _DAT_1403040d0;

          uStack_260 = _UNK_1403040d8;

          local_278 = (char *)s_StartGeneDrive_14030b3d8._0_8_;

          uStack_270._0_6_ =

               CONCAT24(s_StartGeneDrive_14030b3d8._12_2_,s_StartGeneDrive_14030b3d8._8_4_);

          uStack_270 = (ulonglong)(uint6)uStack_270;

          lVar14 = (ulonglong)uVar23 << 8;

          FUN_140040ca0(&local_278,100,0,uVar6,lVar14);

          uVar9 = (undefined4)((ulonglong)lVar14 >> 0x20);

          FUN_140027900(&local_278);

          local_278 = (char *)0x0;

          uStack_270 = 0;

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x20);

          uVar11 = s_Engaging_GENE_DRIVE__14030b3e8._8_8_;

          local_268 = _DAT_140303420;

          uStack_260 = _UNK_140303428;

          *(undefined8 *)local_278 = s_Engaging_GENE_DRIVE__14030b3e8._0_8_;

          *(undefined8 *)(local_278 + 8) = uVar11;

          *(undefined4 *)(local_278 + 0x10) = s_Engaging_GENE_DRIVE__14030b3e8._16_4_;

          local_278[0x14] = '\0';

          in_stack_fffffffffffffd78 = CONCAT44(uVar9,uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                        in_stack_fffffffffffffd78);

          FUN_140027900(&local_278);

          if (*(longlong *)(param_1 + 0x148) != 0) {

            FUN_1400b8720();

          }

          *(undefined8 *)(param_1 + 0x250) = 7;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

        else {

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x20);

          uVar11 = s_That_is_not_acceptable__14030b378._8_8_;

          local_268 = _DAT_140304cd0;

          uStack_260 = _UNK_140304cd8;

          *(undefined8 *)local_278 = s_That_is_not_acceptable__14030b378._0_8_;

          *(undefined8 *)(local_278 + 8) = uVar11;

          *(undefined4 *)(local_278 + 0x10) = s_That_is_not_acceptable__14030b378._16_4_;

          *(undefined2 *)(local_278 + 0x14) = s_That_is_not_acceptable__14030b378._20_2_;

          local_278[0x16] = s_That_is_not_acceptable__14030b378[0x16];

          local_278[0x17] = '\0';

          in_stack_fffffffffffffd78 = CONCAT44((int)(in_stack_fffffffffffffd78 >> 0x20),uVar2);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                        in_stack_fffffffffffffd78);

          FUN_140027900(&local_278);

          *(undefined8 *)(param_1 + 0x250) = 3;

          uVar11 = _DAT_1403040b0;

          uVar20 = _UNK_1403040b8;

        }

      }

    }

    else if (*(char *)(param_1 + 0x264) == '\0') {

      *(undefined1 *)(param_1 + 0x264) = 1;

      *(undefined8 *)(param_1 + 0x250) = 3;

      uVar11 = _DAT_1403040b0;

      uVar20 = _UNK_1403040b8;

    }

  }

  else {

    if (iVar8 != 9) {

      iVar13 = *(int *)(param_1 + 0x250);

      goto LAB_14008a0c2;

    }

    if (*(int *)(param_1 + 0x250) == 2) {

      if ((*(longlong *)(param_1 + 0x270) == 0) ||

         (*(int *)(*(longlong *)(param_1 + 0x270) + 0xc) != 0xc)) {

        local_268 = _DAT_1403040b0;

        uStack_260 = _UNK_1403040b8;

        local_278 = (char *)s_ComputerBeep_14030b400._0_8_;

        uStack_270 = (ulonglong)(uint)s_ComputerBeep_14030b400._8_4_;

        in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

        FUN_140040ca0(&local_278,100,0x32,DAT_14039ca44,in_stack_fffffffffffffd78);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        uVar11 = _DAT_1403040b0;

        uVar20 = _UNK_1403040b8;

        if (*(int *)(param_1 + 0x280) == 0) {

          *(undefined4 *)(param_1 + 0x280) = 4;

          goto LAB_14008a224;

        }

      }

      else if (*(int *)(param_1 + 0x280) == 0) {

        local_268 = _DAT_1403040b0;

        uStack_260 = _UNK_1403040b8;

        local_278 = (char *)s_ComputerMenu_14030b410._0_8_;

        uStack_270 = (ulonglong)(uint)s_ComputerMenu_14030b410._8_4_;

        in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

        FUN_140040ca0(&local_278,100,0x32,DAT_14039ca44,in_stack_fffffffffffffd78);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        *(undefined4 *)(param_1 + 0x280) = 5;

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x53d) = 1;

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5a5) = 1;

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x60d) = 1;

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x405) = 0;

        uVar11 = _DAT_1403040b0;

        uVar20 = _UNK_1403040b8;

      }

    }

    else {

      local_268 = _DAT_1403040b0;

      uStack_260 = _UNK_1403040b8;

      local_278 = (char *)s_ComputerBeep_14030b400._0_8_;

      uStack_270 = (ulonglong)(uint)s_ComputerBeep_14030b400._8_4_;

      in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

      FUN_140040ca0(&local_278,100,0x32,DAT_14039ca44,in_stack_fffffffffffffd78);

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        goto LAB_140089807;

      }

    }

  }

  if (((*(int *)(param_1 + 0x280) == 5) && (*(int *)(param_1 + 0xe0) != 9)) &&

     ((DAT_1403ed968 != 0 || (*(int *)(param_1 + 0xe0) != -1)))) {

    *(undefined4 *)(param_1 + 0x280) = 0;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x53d) = 0;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5a5) = 0;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x60d) = 0;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x405) = 1;

  }

  iVar8 = *(int *)(param_1 + 0x250);

  if (iVar8 == 0) {

    if (*(int *)(param_1 + 0x254) == 0x3c) {

      if (*(char *)(param_1 + 0x492) != '\0') {

        local_278 = (char *)0x0;

        uStack_270 = 0;

        local_268 = 0;

        uStack_260 = 0;

        local_278 = (char *)FUN_1400285e0(0x20);

        uVar11 = _UNK_14030b428;

        local_268 = _DAT_140304140;

        uStack_260 = _UNK_140304148;

        *(undefined8 *)local_278 = _DAT_14030b420;

        *(undefined8 *)(local_278 + 8) = uVar11;

        *(undefined8 *)(local_278 + 0x10) = DAT_14030b430;

        *(undefined4 *)(local_278 + 0x18) = DAT_14030b438;

        *(undefined2 *)(local_278 + 0x1c) = DAT_14030b43c;

        local_278[0x1e] = DAT_14030b43e;

        local_278[0x1f] = '\0';

        in_stack_fffffffffffffd78 = CONCAT44((int)(in_stack_fffffffffffffd78 >> 0x20),uVar2);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                      in_stack_fffffffffffffd78);

        FUN_140027900(&local_278);

      }

      uVar9 = (undefined4)(in_stack_fffffffffffffd78 >> 0x20);

      *(undefined1 *)(param_1 + 0x492) = 0;

      local_278 = (char *)0x0;

      uStack_270 = 0;

      local_268 = 0;

      uStack_260 = 0;

      local_278 = (char *)FUN_1400285e0(0x20);

      uVar11 = s_The_power_is_out_again__14030b440._8_8_;

      local_268 = _DAT_140304cd0;

      uStack_260 = _UNK_140304cd8;

      *(undefined8 *)local_278 = s_The_power_is_out_again__14030b440._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      *(undefined4 *)(local_278 + 0x10) = s_The_power_is_out_again__14030b440._16_4_;

      *(undefined2 *)(local_278 + 0x14) = s_The_power_is_out_again__14030b440._20_2_;

      local_278[0x16] = s_The_power_is_out_again__14030b440[0x16];

      local_278[0x17] = '\0';

      uVar11 = CONCAT44(uVar9,uVar2);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar11);

      uVar9 = (undefined4)((ulonglong)uVar11 >> 0x20);

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_278 = (char *)0x0;

      uStack_270 = 0;

      local_268 = 0;

      uStack_260 = 0;

      local_278 = (char *)FUN_1400285e0(0x20);

      uVar11 = s_Find_a_way_to_restore_power_14030b458._8_8_;

      local_268 = _DAT_140304130;

      uStack_260 = _UNK_140304138;

      *(undefined8 *)local_278 = s_Find_a_way_to_restore_power_14030b458._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      *(undefined8 *)(local_278 + 0x10) = s_Find_a_way_to_restore_power_14030b458._16_8_;

      *(undefined2 *)(local_278 + 0x18) = s_Find_a_way_to_restore_power_14030b458._24_2_;

      local_278[0x1a] = s_Find_a_way_to_restore_power_14030b458[0x1a];

      local_278[0x1b] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2));

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    goto LAB_14008b577;

  }

  if (iVar8 == 1) {

    if (*(int *)(param_1 + 0x254) != 0x3c) goto LAB_14008b577;

    cVar7 = FUN_14010dd70(DAT_1403fb0d8);

    uVar9 = (undefined4)(in_stack_fffffffffffffd78 >> 0x20);

    local_278 = (char *)0x0;

    uStack_270 = 0;

    local_268 = 0;

    uStack_260 = 0;

    if (cVar7 == '\0') {

      local_278 = (char *)FUN_1400285e0(0x20);

      uVar11 = s_Must_be_a_loose_wire_14030b478._8_8_;

      local_268 = _DAT_140303420;

      uStack_260 = _UNK_140303428;

      *(undefined8 *)local_278 = s_Must_be_a_loose_wire_14030b478._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      *(undefined4 *)(local_278 + 0x10) = s_Must_be_a_loose_wire_14030b478._16_4_;

      local_278[0x14] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2));

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

LAB_14008a796:

        FUN_1402c7088();

      }

    }

    else if (*(char *)(param_1 + 0x491) == '\0') {

      local_278 = (char *)FUN_1400285e0(0x20);

      uVar11 = s_The_lights_are_on_now_14030b490._8_8_;

      local_268 = _DAT_140304110;

      uStack_260 = _UNK_140304118;

      *(undefined8 *)local_278 = s_The_lights_are_on_now_14030b490._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      *(undefined4 *)(local_278 + 0x10) = s_The_lights_are_on_now_14030b490._16_4_;

      local_278[0x14] = s_The_lights_are_on_now_14030b490[0x14];

      local_278[0x15] = '\0';

      uVar11 = CONCAT44(uVar9,uVar2);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar11);

      uVar9 = (undefined4)((ulonglong)uVar11 >> 0x20);

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_278 = (char *)0x0;

      uStack_270 = 0;

      local_268 = 0;

      uStack_260 = 0;

      local_278 = (char *)FUN_1400285e0(0x30);

      uVar11 = s_Electricity_is_needed_for_geneti_14030b4a8._8_8_;

      local_268 = _DAT_140303780;

      uStack_260 = _UNK_140303788;

      *(undefined8 *)local_278 = s_Electricity_is_needed_for_geneti_14030b4a8._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      uVar11 = s_Electricity_is_needed_for_geneti_14030b4a8._24_8_;

      *(undefined8 *)(local_278 + 0x10) = s_Electricity_is_needed_for_geneti_14030b4a8._16_8_;

      *(undefined8 *)(local_278 + 0x18) = uVar11;

      *(undefined8 *)(local_278 + 0x20) = s_Electricity_is_needed_for_geneti_14030b4a8._32_8_;

      *(undefined2 *)(local_278 + 0x28) = s_Electricity_is_needed_for_geneti_14030b4a8._40_2_;

      local_278[0x2a] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2));

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined4 *)(param_1 + 0x48c) = 1;

      *(undefined1 *)(param_1 + 0x491) = 1;

    }

    else {

      local_278 = (char *)FUN_1400285e0(0x20);

      uVar11 = s_I_m_a_geneticist_14030b148._8_8_;

      local_268 = _DAT_1403040e0;

      uStack_260 = _UNK_1403040e8;

      *(undefined8 *)local_278 = s_I_m_a_geneticist_14030b148._0_8_;

      *(undefined8 *)(local_278 + 8) = uVar11;

      local_278[0x10] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2));

      if (0xf < uStack_260) {

        if ((0xfff < uStack_260 + 1) &&

           ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        goto LAB_14008a796;

      }

    }

    lVar14 = *(longlong *)(param_1 + 0x130);

    uVar20 = uVar17;

    if (*(longlong *)(param_1 + 0x138) - lVar14 >> 3 != 0) {

      do {

        if ((*(longlong *)(lVar14 + uVar20) != *(longlong *)(param_1 + 0x148)) &&

           (cVar7 = FUN_1400b7720(), cVar7 != '\0')) {

          FUN_1400d1e10(param_1,uVar17,0xf);

          *(undefined8 *)(param_1 + 0x250) = 2;

          goto LAB_14008b577;

        }

        uVar16 = (int)uVar17 + 1;

        uVar17 = (ulonglong)uVar16;

        lVar14 = *(longlong *)(param_1 + 0x130);

        uVar20 = uVar20 + 8;

      } while ((ulonglong)(longlong)(int)uVar16 <

               (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar14 >> 3));

      *(undefined8 *)(param_1 + 0x250) = 2;

      goto LAB_14008b577;

    }

LAB_14008b36f:

    *(undefined8 *)(param_1 + 0x250) = 2;

  }

  else {

    if (iVar8 == 2) {

      if (((6 < *(int *)(param_1 + 0xd8)) && (*(int *)(param_1 + 0xd8) != 0xb)) &&

         (*(int *)(param_1 + 0x124) == 0)) {

        *(undefined4 *)(param_1 + 0x124) = 9;

      }

      goto LAB_14008b577;

    }

    if (iVar8 == 3) {

      if (*(int *)(param_1 + 0x254) == 1) {

        local_268 = _DAT_1403033f0;

        uStack_260 = _UNK_1403033f8;

        local_278 = (char *)s_JustSwitch_14030b4d8._0_8_;

        uStack_270 = (ulonglong)(ushort)s_JustSwitch_14030b4d8._8_2_;

        FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78 & 0xffffffffffffff00);

        if (0xf < uStack_260) {

          if ((0xfff < uStack_260 + 1) &&

             ((char *)0x1f < local_278 + (-8 - *(longlong *)(local_278 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      if (*(int *)(param_1 + 0x254) != 0x1e) goto LAB_14008b577;

      goto LAB_14008b0cf;

    }

    uVar23 = (uint7)(in_stack_fffffffffffffd78 >> 8);

    if (iVar8 == 8) {

      if (*(int *)(param_1 + 0x254) == 1) {

        local_268 = _DAT_1403033f0;

        uStack_260 = _UNK_1403033f8;

        local_278 = (char *)s_InsertDisk_14030b4e8._0_8_;

        uStack_270 = (ulonglong)(ushort)s_InsertDisk_14030b4e8._8_2_;

        FUN_140040ca0(&local_278,100,0,uVar6,(ulonglong)uVar23 << 8);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        *(undefined4 *)(param_1 + 0x280) = 2;

        *(undefined4 *)(param_1 + 0x284) = 0x69;

      }

      if (*(int *)(param_1 + 0x284) == 0) {

        *(undefined8 *)(param_1 + 0x250) = 4;

      }

      goto LAB_14008b577;

    }

    if (iVar8 == 4) {

      if ((*(int *)(param_1 + 0x254) == 1) && (*(longlong *)(param_1 + 0x270) != 0)) {

        FUN_1400c6d00(local_res8);

        in_stack_fffffffffffffd78 = in_stack_fffffffffffffd78 & 0xffffffff00000000;

        FUN_1400a8890(*(undefined8 *)(param_1 + 0x270));

        *(undefined8 *)(param_1 + 0x270) = 0;

      }

      uVar9 = (undefined4)(in_stack_fffffffffffffd78 >> 0x20);

      if (*(int *)(param_1 + 0x254) == 0xf) {

        *(undefined4 *)(param_1 + 0x254) = 0;

        if (*(longlong *)(param_1 + 0x278) == 0) {

          *(undefined4 *)(param_1 + 0x250) = 5;

          local_278 = (char *)0x0;

          uStack_270 = 0;

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x20);

          uVar11 = s_Commencing_EXTRACTION__14030b4f8._8_8_;

          local_268 = _DAT_140305fd0;

          uStack_260 = _UNK_140305fd8;

          *(undefined8 *)local_278 = s_Commencing_EXTRACTION__14030b4f8._0_8_;

          *(undefined8 *)(local_278 + 8) = uVar11;

          *(undefined4 *)(local_278 + 0x10) = s_Commencing_EXTRACTION__14030b4f8._16_4_;

          *(undefined2 *)(local_278 + 0x14) = s_Commencing_EXTRACTION__14030b4f8._20_2_;

          local_278[0x16] = '\0';

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2))

          ;

          FUN_140027900(&local_278);

          if (*(longlong *)(param_1 + 0x148) != 0) {

            FUN_1400b8720();

          }

        }

        else {

          *(undefined4 *)(param_1 + 0x250) = 6;

        }

      }

      goto LAB_14008b577;

    }

    if (iVar8 == 5) {

      if ((*(int *)(param_1 + 0x254) == 0x1e) &&

         (lVar14 = *(longlong *)(param_1 + 0x4a0), uVar20 = uVar17,

         *(longlong *)(param_1 + 0x4a8) - lVar14 >> 2 != 0)) {

        do {

          iVar8 = *(int *)(lVar14 + uVar20);

          cVar7 = FUN_1400b7720(*(undefined8 *)

                                 (*(longlong *)(param_1 + 0x130) + (longlong)iVar8 * 8));

          if (cVar7 != '\0') {

            FUN_1400d1e10(param_1,iVar8,0x10);

            break;

          }

          uVar16 = (int)uVar17 + 1;

          uVar17 = (ulonglong)uVar16;

          lVar14 = *(longlong *)(param_1 + 0x4a0);

          uVar20 = uVar20 + 4;

        } while ((ulonglong)(longlong)(int)uVar16 <

                 (ulonglong)(*(longlong *)(param_1 + 0x4a8) - lVar14 >> 2));

      }

      if (*(int *)(param_1 + 0x254) == 0x78) {

        *(undefined8 *)(param_1 + 0x250) = 6;

      }

      goto LAB_14008b577;

    }

    if (iVar8 == 6) {

      if (*(int *)(param_1 + 0x254) == 1) {

        local_268 = _DAT_140304090;

        uStack_260 = _UNK_140304098;

        local_278 = (char *)0x6c6c69466c616956;

        uStack_270 = 0;

        in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

        FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        lVar14 = *(longlong *)(param_1 + 0x278);

        if (lVar14 == 0) {

          cVar7 = FUN_140088990(param_1,param_1 + 0x4a0,param_1 + 0x4b8,local_248);

          if (cVar7 != '\0') {

            uVar11 = FUN_1400cc9d0(param_1,0xc,*(undefined4 *)(param_1 + 0x268),

                                   *(undefined4 *)(param_1 + 0x26c));

            *(undefined8 *)(param_1 + 0x270) = uVar11;

            FUN_14005d190(uVar11,local_248);

            piVar10 = *(int **)(param_1 + 0x4c0);

            for (piVar18 = *(int **)(param_1 + 0x4b8); piVar18 != piVar10; piVar18 = piVar18 + 1) {

              puVar1 = (uint *)(*(longlong *)(param_1 + 0x270) + 0x70);

              *puVar1 = *puVar1 | *(uint *)(*(longlong *)

                                             (*(longlong *)(param_1 + 0xb8) + (longlong)*piVar18 * 8

                                             ) + 0x70);

            }

          }

        }

        else {

          *(longlong *)(param_1 + 0x270) = lVar14;

          *(undefined4 *)(lVar14 + 0xc) = 0xc;

          local_268 = 8;

          uStack_260 = 0xf;

          local_278 = (char *)0x6c6169566d657449;

          uStack_270 = 0;

          lVar14 = *(longlong *)(param_1 + 0x270);

          uVar9 = FUN_14006fe60(&local_278);

          *(undefined4 *)(lVar14 + 0x3c) = uVar9;

          *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x28) = *(undefined4 *)(param_1 + 0x268);

          *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x2c) = *(undefined4 *)(param_1 + 0x26c);

        }

      }

      uVar9 = (undefined4)(in_stack_fffffffffffffd78 >> 0x20);

      if (*(int *)(param_1 + 0x254) != 0x3c) goto LAB_14008b577;

      if (*(longlong *)(param_1 + 0x278) == 0) {

        local_278 = (char *)0x0;

        uStack_270 = 0;

        local_268 = 0;

        uStack_260 = 0;

        local_278 = (char *)FUN_1400285e0(0x20);

        uVar11 = s_Extraction_complete_14030b510._8_8_;

        local_268 = _DAT_140304100;

        uStack_260 = _UNK_140304108;

        *(undefined8 *)local_278 = s_Extraction_complete_14030b510._0_8_;

        *(undefined8 *)(local_278 + 8) = uVar11;

        *(undefined2 *)(local_278 + 0x10) = s_Extraction_complete_14030b510._16_2_;

        local_278[0x12] = s_Extraction_complete_14030b510[0x12];

        local_278[0x13] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2));

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

      }

      else {

        *(undefined8 *)(param_1 + 0x278) = 0;

      }

    }

    else {

      if (iVar8 != 7) {

        if (iVar8 == 9) {

          if (*(int *)(param_1 + 0x254) == 1) {

            local_278 = (char *)s_ComputerCopy_14030b550._0_8_;

            uStack_270 = (ulonglong)(uint)s_ComputerCopy_14030b550._8_4_;

            in_stack_fffffffffffffd78 = (ulonglong)uVar23 << 8;

            local_268 = uVar11;

            uStack_260 = uVar20;

            FUN_140040ca0(&local_278,100,0x32,uVar6,in_stack_fffffffffffffd78);

            if (0xf < uStack_260) {

              FUN_140028310(&local_278,local_278);

            }

          }

          uVar9 = (undefined4)(in_stack_fffffffffffffd78 >> 0x20);

          if (*(int *)(param_1 + 0x254) != 0x1e) goto LAB_14008b577;

          local_278 = (char *)0x0;

          uStack_270 = 0;

          local_268 = 0;

          uStack_260 = 0;

          local_278 = (char *)FUN_1400285e0(0x20);

          uVar11 = s_Genome_copied_to_clipboard__14030b560._8_8_;

          local_268 = _DAT_140304130;

          uStack_260 = _UNK_140304138;

          *(undefined8 *)local_278 = s_Genome_copied_to_clipboard__14030b560._0_8_;

          *(undefined8 *)(local_278 + 8) = uVar11;

          *(undefined8 *)(local_278 + 0x10) = s_Genome_copied_to_clipboard__14030b560._16_8_;

          *(undefined2 *)(local_278 + 0x18) = s_Genome_copied_to_clipboard__14030b560._24_2_;

          local_278[0x1a] = s_Genome_copied_to_clipboard__14030b560[0x1a];

          local_278[0x1b] = '\0';

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,CONCAT44(uVar9,uVar2))

          ;

          if (0xf < uStack_260) {

            FUN_140028310(&local_278,local_278);

            *(undefined8 *)(param_1 + 0x250) = 2;

            goto LAB_14008b577;

          }

        }

        else {

          if (iVar8 != 10) {

            if (*(int *)(param_1 + 0x250) == 0xb) {

              if (*(int *)(param_1 + 0x254) == 1) {

                FUN_14003f6f0();

                local_268 = _DAT_1403033f0;

                uStack_260 = _UNK_1403033f8;

                local_278 = (char *)s_VialZoomIn_14030b5b0._0_8_;

                uStack_270 = (ulonglong)(ushort)s_VialZoomIn_14030b5b0._8_2_;

                FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78 & 0xffffffffffffff00)

                ;

                if (0xf < uStack_260) {

                  FUN_140028310(&local_278,local_278);

                }

                FUN_1400fce70(DAT_1403fb0d8,*(undefined8 *)(*(longlong *)(param_1 + 0x270) + 0x78));

                *(undefined4 *)(param_1 + 0x280) = 1;

                *(undefined4 *)(param_1 + 0x284) = 0x78;

                goto LAB_14008b577;

              }

              if (*(int *)(param_1 + 0x254) != 0x79) goto LAB_14008b577;

              *(undefined8 *)(param_1 + 0x250) = 0xc;

              uVar11 = 9;

              pcVar15 = "VialWorld";

            }

            else {

              if (*(int *)(param_1 + 0x250) != 0xd) goto LAB_14008b577;

              if (*(int *)(param_1 + 0x254) == 1) {

                FUN_14003f6f0();

                local_268 = _DAT_140304cc0;

                uStack_260 = _UNK_140304cc8;

                local_278 = (char *)s_VialZoomOut_14030b5c0._0_8_;

                uStack_270 = (ulonglong)

                             CONCAT12(s_VialZoomOut_14030b5c0[10],s_VialZoomOut_14030b5c0._8_2_);

                FUN_140040ca0(&local_278,100,0,uVar6,in_stack_fffffffffffffd78 & 0xffffffffffffff00)

                ;

                if (0xf < uStack_260) {

                  FUN_140028310(&local_278,local_278);

                }

                FUN_1400fd1e0(DAT_1403fb0d8);

                *(undefined4 *)(param_1 + 0x280) = 1;

                *(undefined4 *)(param_1 + 0x284) = 0x78;

              }

              if (*(int *)(param_1 + 0x254) != 0x79) goto LAB_14008b577;

              if (*(longlong *)(param_1 + 0x270) != 0) {

                FUN_1400fd3e0(DAT_1403fb0d8,*(undefined8 *)(*(longlong *)(param_1 + 0x270) + 0x78));

              }

              *(undefined8 *)(param_1 + 0x250) = 2;

              uVar11 = 6;

              pcVar15 = "Crispr";

            }

            local_278 = (char *)0x0;

            uStack_270 = 0;

            local_268 = 0;

            uStack_260 = 0;

            FUN_140027e30(&local_278,pcVar15,uVar11);

            FUN_14003f340(&local_278,1);

            goto LAB_14008b577;

          }

          if (*(int *)(param_1 + 0x254) == 1) {

            local_268 = _DAT_1403040c0;

            uStack_260 = _UNK_1403040c8;

            local_278 = (char *)s_ComputerPaste_14030b580._0_8_;

            uStack_270 = (ulonglong)

                         CONCAT14(s_ComputerPaste_14030b580[0xc],s_ComputerPaste_14030b580._8_4_);

            lVar14 = (ulonglong)uVar23 << 8;

            FUN_140040ca0(&local_278,100,0x32,uVar6,lVar14);

            uVar9 = (undefined4)((ulonglong)lVar14 >> 0x20);

            if (0xf < uStack_260) {

              FUN_140028310(&local_278,local_278);

            }

            if (*(int *)(param_1 + 0x254) == 1) {

              local_278 = (char *)0x0;

              uStack_270 = 0;

              local_268 = 0;

              uStack_260 = 0;

              local_278 = (char *)FUN_1400285e0(0x20);

              uVar11 = s_Pasting_genome_from_clipboard__14030b590._8_8_;

              local_268 = _DAT_140303770;

              uStack_260 = _UNK_140303778;

              *(undefined8 *)local_278 = s_Pasting_genome_from_clipboard__14030b590._0_8_;

              *(undefined8 *)(local_278 + 8) = uVar11;

              *(undefined8 *)(local_278 + 0x10) = s_Pasting_genome_from_clipboard__14030b590._16_8_;

              *(undefined4 *)(local_278 + 0x18) = s_Pasting_genome_from_clipboard__14030b590._24_4_;

              *(undefined2 *)(local_278 + 0x1c) = s_Pasting_genome_from_clipboard__14030b590._28_2_;

              local_278[0x1e] = '\0';

              FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,

                            CONCAT44(uVar9,uVar2));

              if (0xf < uStack_260) {

                FUN_140028310(&local_278,local_278);

              }

            }

          }

          if ((*(int *)(param_1 + 0x254) == 0x32) && (*(longlong *)(param_1 + 0x270) != 0)) {

            FUN_14005d360();

          }

          if (*(int *)(param_1 + 0x254) != 0x1e) goto LAB_14008b577;

        }

        goto LAB_14008b36f;

      }

      if (*(int *)(param_1 + 0x254) == 1) {

        *(undefined4 *)(param_1 + 0x260) = 0x5a;

      }

      else if (((*(int *)(param_1 + 0x254) == 0x5a) &&

               (FUN_14005cf70(*(undefined8 *)(param_1 + 0x270)), uVar4 = _UNK_140304cb8,

               uVar3 = _DAT_140304cb0, uVar20 = _UNK_140303418, uVar11 = _DAT_140303410,

               *(longlong *)(*(longlong *)(param_1 + 0x270) + 0x78) != 0)) &&

              (lVar14 = *(longlong *)(param_1 + 0x4a0), uVar19 = uVar17, uVar21 = uVar17,

              uVar22 = uVar17, *(longlong *)(param_1 + 0x4a8) - lVar14 >> 2 != 0)) {

        do {

          lVar14 = *(longlong *)

                    (*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(lVar14 + uVar19) * 8);

          FUN_1400b35f0(lVar14,*(undefined8 *)(*(longlong *)(param_1 + 0x270) + 0x78));

          if (0 < (int)uVar21) {

            FUN_1400a32c0(lVar14 + 0x2b8,uVar22);

          }

          FUN_1400b3070(lVar14);

          if (*(int *)(lVar14 + 0x1f8) != -1) {

            lVar12 = FUN_1400c7520();

            *(undefined1 *)(lVar12 + 0x6c) = 1;

            uStack_270 = 0;

            local_268 = uVar3;

            uStack_260 = uVar4;

            local_278 = (char *)(ulonglong)(uint3)DAT_140304380;

            FUN_140037710(&local_278);

            if (0xf < uStack_260) {

              FUN_140028310(&local_278,local_278);

            }

          }

          FUN_1400cead0(param_1,lVar14);

          if ((*(int *)(*(longlong *)(param_1 + 0x270) + 0x70) == 1) &&

             (cVar7 = FUN_1400b7720(lVar14), cVar7 != '\0')) {

            local_278 = (char *)0x0;

            uStack_270 = 0;

            local_268 = 0;

            uStack_260 = 0;

            local_278 = (char *)FUN_1400285e0(0x20);

            uVar5 = s_Algernon_De_Horsey_14030b528._8_8_;

            local_268 = uVar11;

            uStack_260 = uVar20;

            *(undefined8 *)local_278 = s_Algernon_De_Horsey_14030b528._0_8_;

            *(undefined8 *)(local_278 + 8) = uVar5;

            *(undefined2 *)(local_278 + 0x10) = s_Algernon_De_Horsey_14030b528._16_2_;

            local_278[0x12] = '\0';

            FUN_1400cf950(param_1,lVar14,&local_278);

            *(undefined4 *)(lVar14 + 0x284) = 9;

            if (0xf < uStack_260) {

              FUN_140028310(&local_278,local_278);

            }

          }

          else {

            FUN_1400b9220(lVar14);

          }

          uVar16 = (int)uVar21 + 1;

          lVar14 = *(longlong *)(param_1 + 0x4a0);

          uVar19 = uVar19 + 4;

          uVar21 = (ulonglong)uVar16;

          uVar22 = (ulonglong)((int)uVar22 + 5);

        } while ((ulonglong)(longlong)(int)uVar16 <

                 (ulonglong)(*(longlong *)(param_1 + 0x4a8) - lVar14 >> 2));

      }

      if (*(int *)(param_1 + 0x254) != 0x78) goto LAB_14008b577;

      if (*(longlong *)(param_1 + 0x4a0) != *(longlong *)(param_1 + 0x4a8)) {

        local_268 = _DAT_1403033f0;

        uStack_260 = _UNK_1403033f8;

        local_278 = (char *)s_It_worked__14030b540._0_8_;

        uStack_270 = (ulonglong)(ushort)s_It_worked__14030b540._8_2_;

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_278,0,uVar2);

        if (0xf < uStack_260) {

          FUN_140028310(&local_278,local_278);

        }

        lVar14 = *(longlong *)(param_1 + 0x4a0);

        uVar20 = uVar17;

        if (*(longlong *)(param_1 + 0x4a8) - lVar14 >> 2 != 0) {

          do {

            iVar8 = *(int *)(lVar14 + uVar20);

            FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + (longlong)iVar8 * 8));

            cVar7 = FUN_1400b7720(*(undefined8 *)

                                   (*(longlong *)(param_1 + 0x130) + (longlong)iVar8 * 8));

            if (cVar7 != '\0') {

              FUN_1400d1e10(param_1,iVar8,0x11);

              break;

            }

            uVar16 = (int)uVar17 + 1;

            uVar17 = (ulonglong)uVar16;

            lVar14 = *(longlong *)(param_1 + 0x4a0);

            uVar20 = uVar20 + 4;

          } while ((ulonglong)(longlong)(int)uVar16 <

                   (ulonglong)(*(longlong *)(param_1 + 0x4a8) - lVar14 >> 2));

        }

      }

    }

LAB_14008b0cf:

    *(undefined1 *)(param_1 + 0x264) = 0;

    *(undefined8 *)(param_1 + 0x250) = 2;

  }

LAB_14008b577:

  if ((0 < *(int *)(param_1 + 0x284)) &&

     (iVar8 = *(int *)(param_1 + 0x284) + -1, *(int *)(param_1 + 0x284) = iVar8, iVar8 == 0)) {

    *(undefined4 *)(param_1 + 0x280) = 0;

  }

  if (*(longlong *)(param_1 + 0x270) != 0) {

    uVar9 = DAT_140303374;

    if (4 < *(int *)(param_1 + 0x250)) {

      uVar9 = DAT_14039ca80;

    }

    *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x30) = uVar9;

  }

  return;

}




