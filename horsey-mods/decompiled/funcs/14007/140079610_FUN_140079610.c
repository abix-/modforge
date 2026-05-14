// Address: 0x140079610
// Ghidra name: FUN_140079610
// ============ 0x140079610 FUN_140079610 (size=2446) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 *

FUN_140079610(byte *param_1,uint param_2,int param_3,int param_4,int param_5,int *param_6)



{

  byte bVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  undefined1 *puVar5;

  longlong lVar6;

  undefined4 *puVar7;

  byte *pbVar8;

  undefined8 *puVar9;

  uint uVar10;

  byte bVar11;

  longlong lVar12;

  longlong lVar13;

  ulonglong uVar14;

  undefined *puVar15;

  longlong lVar16;

  longlong lVar17;

  uint uVar18;

  longlong lVar19;

  longlong lVar20;

  byte bVar21;

  longlong lVar22;

  undefined1 in_XMM1 [16];

  undefined1 auVar23 [16];

  undefined1 in_XMM2 [16];

  undefined1 auVar24 [16];

  int iVar25;

  int iVar26;

  int iVar27;

  int iVar28;

  undefined1 auVar29 [16];

  int local_res10;

  int local_res20 [2];

  int local_b8;

  int local_b0;

  int local_ac;

  int local_a8;

  undefined1 *local_90;

  undefined8 local_60;

  undefined8 uStack_58;

  undefined4 local_50;

  

  lVar12 = (longlong)param_5;

  uVar18 = param_3 * param_5;

  local_50 = 6;

  local_60 = _DAT_14030a5e0;

  uStack_58 = _UNK_14030a5e8;

  if (param_2 == 0) {

    param_2 = uVar18;

  }

  iVar3 = (uVar18 + 1) * param_4;

  local_res20[0] = param_4;

  puVar5 = (undefined1 *)_malloc_base((longlong)iVar3);

  if (puVar5 != (undefined1 *)0x0) {

    lVar22 = (longlong)(int)uVar18;

    lVar6 = _malloc_base(lVar22);

    if (lVar6 == 0) {

      thunk_FUN_1402e9a80(puVar5);

    }

    else {

      local_a8 = 0;

      if (0 < param_4) {

        lVar20 = lVar6 - (longlong)param_1;

        lVar13 = (longlong)(int)param_2;

        local_90 = puVar5;

        do {

          iVar25 = 0;

          local_ac = 0x7fffffff;

          puVar15 = &DAT_1403d9ab8;

          if (local_a8 != 0) {

            puVar15 = &DAT_1403d9aa0;

          }

          local_res10 = 0;

          local_b8 = 0;

          do {

            local_b0 = 0;

            if (local_b8 != 0) {

              local_b0 = iVar25;

            }

            if (local_b0 < 5) {

              puVar7 = (undefined4 *)(puVar15 + (longlong)local_b0 * 4);

LAB_1400797a0:

              uVar2 = *puVar7;

              if (0 < lVar12) {

                lVar17 = -lVar13;

                pbVar8 = param_1;

                lVar16 = lVar12;

                do {

                  switch(uVar2) {

                  case 0:

                    goto switchD_1400797db_caseD_0;

                  case 1:

                    goto switchD_1400797db_caseD_1;

                  case 2:

                    goto switchD_1400797db_caseD_2;

                  case 3:

                    goto switchD_1400797db_caseD_3;

                  case 4:

                    goto switchD_1400797db_caseD_4;

                  case 5:

                    goto switchD_1400797db_caseD_5;

                  case 6:

                    goto switchD_1400797db_caseD_6;

                  }

                  pbVar8 = pbVar8 + 1;

                  lVar16 = lVar16 + -1;

                } while (lVar16 != 0);

              }

              goto LAB_1400797f3;

            }

LAB_140079c04:

            local_b8 = local_b8 + 1;

          } while (local_b8 < 2);

          *local_90 = (char)iVar25;

          FUN_1402f8e20(local_90 + 1,lVar6,lVar22);

          local_a8 = local_a8 + 1;

          local_90 = local_90 + (int)(uVar18 + 1);

          param_1 = param_1 + lVar13;

          lVar20 = lVar20 - lVar13;

          param_4 = local_res20[0];

        } while (local_a8 < local_res20[0]);

      }

      lVar22 = 0;

      thunk_FUN_1402e9a80(lVar6);

      lVar6 = FUN_140078570(puVar5,iVar3,local_res20,8);

      thunk_FUN_1402e9a80(puVar5);

      iVar3 = local_res20[0];

      if (lVar6 != 0) {

        lVar13 = (longlong)local_res20[0];

        iVar25 = local_res20[0] + 0x39;

        puVar9 = (undefined8 *)_malloc_base((longlong)iVar25);

        if (puVar9 != (undefined8 *)0x0) {

          bVar11 = *(byte *)((longlong)&local_60 + lVar12 * 4);

          *param_6 = iVar25;

          *puVar9 = 0xa1a0a0d474e5089;

          *(char *)(puVar9 + 2) = (char)((uint)param_3 >> 0x18);

          *(char *)((longlong)puVar9 + 0x11) = (char)((uint)param_3 >> 0x10);

          *(char *)((longlong)puVar9 + 0x12) = (char)((uint)param_3 >> 8);

          *(char *)((longlong)puVar9 + 0x13) = (char)param_3;

          *(char *)((longlong)puVar9 + 0x14) = (char)((uint)param_4 >> 0x18);

          *(char *)((longlong)puVar9 + 0x15) = (char)((uint)param_4 >> 0x10);

          *(char *)((longlong)puVar9 + 0x16) = (char)((uint)param_4 >> 8);

          *(char *)((longlong)puVar9 + 0x17) = (char)param_4;

          *(undefined4 *)(puVar9 + 1) = 0xd000000;

          *(undefined4 *)((longlong)puVar9 + 0xc) = 0x52444849;

          *(undefined1 *)(puVar9 + 3) = 8;

          *(byte *)((longlong)puVar9 + 0x19) = bVar11;

          *(undefined2 *)((longlong)puVar9 + 0x1a) = 0;

          *(undefined1 *)((longlong)puVar9 + 0x1c) = 0;

          uVar18 = (*(uint *)(&DAT_1403d96a0 +

                             (ulonglong)(byte)~*(byte *)((longlong)puVar9 + 0xc) * 4) ^ 0xffffff) >>

                   8 ^ *(uint *)(&DAT_1403d96a0 +

                                ((ulonglong)

                                 ((*(uint *)(&DAT_1403d96a0 +

                                            (ulonglong)(byte)~*(byte *)((longlong)puVar9 + 0xc) * 4)

                                  ^ 0xffffff) & 0xff) ^ (ulonglong)*(byte *)((longlong)puVar9 + 0xd)

                                ) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0xe) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0xf) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)(puVar9 + 2) ^ (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x11) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x12) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x13) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x14) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          lVar12 = (longlong)puVar9 + 0x29;

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x15) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x16) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)((longlong)puVar9 + 0x17) ^

                            (ulonglong)(uVar18 & 0xff)) * 4);

          *(char *)((longlong)puVar9 + 0x24) = (char)iVar3;

          *(undefined4 *)((longlong)puVar9 + 0x25) = 0x54414449;

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)*(byte *)(puVar9 + 3) ^ (ulonglong)(uVar18 & 0xff)) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 + ((ulonglong)(uVar18 & 0xff) ^ (ulonglong)bVar11) * 4);

          uVar18 = uVar18 >> 8 ^ *(uint *)(&DAT_1403d96a0 + (ulonglong)(uVar18 & 0xff) * 4);

          uVar18 = uVar18 >> 8 ^ *(uint *)(&DAT_1403d96a0 + (ulonglong)(uVar18 & 0xff) * 4);

          uVar18 = ~(uVar18 >> 8 ^ *(uint *)(&DAT_1403d96a0 + (ulonglong)(uVar18 & 0xff) * 4));

          *(char *)(puVar9 + 4) = (char)uVar18;

          *(char *)((longlong)puVar9 + 0x1d) = (char)(uVar18 >> 0x18);

          *(char *)((longlong)puVar9 + 0x1e) = (char)(uVar18 >> 0x10);

          *(char *)((longlong)puVar9 + 0x1f) = (char)(uVar18 >> 8);

          *(char *)((longlong)puVar9 + 0x21) = (char)((uint)iVar3 >> 0x18);

          *(char *)((longlong)puVar9 + 0x22) = (char)((uint)iVar3 >> 0x10);

          *(char *)((longlong)puVar9 + 0x23) = (char)((uint)iVar3 >> 8);

          FUN_1402f8e20(lVar12,lVar6,lVar13);

          puVar5 = (undefined1 *)(lVar12 + lVar13);

          thunk_FUN_1402e9a80(lVar6);

          uVar14 = 0xffffffff;

          uVar18 = 0xffffffff;

          if (0 < iVar3 + 4) {

            do {

              lVar6 = lVar22 + -4;

              lVar22 = lVar22 + 1;

              uVar18 = (uint)(uVar14 >> 8) ^

                       *(uint *)(&DAT_1403d96a0 +

                                ((ulonglong)*(byte *)(lVar6 + lVar12) ^ uVar14 & 0xff) * 4);

              uVar14 = (ulonglong)uVar18;

            } while (lVar22 < iVar3 + 4);

          }

          *(undefined4 *)(puVar5 + 4) = 0;

          uVar18 = ~uVar18;

          puVar5[3] = (char)uVar18;

          *puVar5 = (char)(uVar18 >> 0x18);

          puVar5[1] = (char)(uVar18 >> 0x10);

          puVar5[2] = (char)(uVar18 >> 8);

          uVar18 = DAT_1403d9978 ^ 0xffffff;

          *(undefined4 *)(puVar5 + 8) = 0x444e4549;

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)(uVar18 & 0xff) ^ (ulonglong)(byte)puVar5[9]) * 4);

          uVar18 = uVar18 >> 8 ^

                   *(uint *)(&DAT_1403d96a0 +

                            ((ulonglong)(uVar18 & 0xff) ^ (ulonglong)(byte)puVar5[10]) * 4);

          uVar18 = ~(uVar18 >> 8 ^

                    *(uint *)(&DAT_1403d96a0 +

                             ((ulonglong)(uVar18 & 0xff) ^ (ulonglong)(byte)puVar5[0xb]) * 4));

          puVar5[0xf] = (char)uVar18;

          puVar5[0xc] = (char)(uVar18 >> 0x18);

          puVar5[0xd] = (char)(uVar18 >> 0x10);

          puVar5[0xe] = (char)(uVar18 >> 8);

          return puVar9;

        }

      }

    }

  }

  return (undefined8 *)0x0;

switchD_1400797db_caseD_6:

  do {

    pbVar8[lVar20] = *pbVar8;

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_1400797db_caseD_5:

  do {

    pbVar8[lVar20] = *pbVar8;

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_1400797db_caseD_4:

  do {

    bVar11 = 0;

    if (pbVar8[lVar17] != 0) {

      bVar11 = pbVar8[lVar17];

    }

    pbVar8[lVar20] = *pbVar8 - bVar11;

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_1400797db_caseD_3:

  do {

    pbVar8[lVar20] = *pbVar8 - (pbVar8[lVar17] >> 1);

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_1400797db_caseD_2:

  do {

    pbVar8[lVar20] = *pbVar8 - pbVar8[lVar17];

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

LAB_1400797f3:

  if (lVar12 < lVar22) {

    lVar16 = lVar12 + lVar20;

    lVar19 = lVar12 - lVar13;

    lVar17 = lVar22 - lVar12;

    pbVar8 = param_1;

    do {

      switch(uVar2) {

      case 0:

        goto switchD_14007982f_caseD_0;

      case 1:

        goto switchD_14007982f_caseD_1;

      case 2:

        goto switchD_14007982f_caseD_2;

      case 3:

        goto switchD_14007982f_caseD_3;

      case 4:

        goto switchD_14007982f_caseD_4;

      case 5:

        goto switchD_14007982f_caseD_5;

      case 6:

        goto switchD_14007982f_caseD_6;

      }

      pbVar8 = pbVar8 + 1;

      lVar17 = lVar17 + -1;

    } while (lVar17 != 0);

  }

  goto LAB_140079aa6;

switchD_1400797db_caseD_1:

  do {

    pbVar8[lVar20] = *pbVar8;

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_1400797db_caseD_0:

  do {

    pbVar8[lVar20] = *pbVar8;

    lVar16 = lVar16 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar16 != 0);

  goto LAB_1400797f3;

switchD_14007982f_caseD_6:

  do {

    pbVar8[lVar16] = pbVar8[lVar12] - *pbVar8;

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

switchD_14007982f_caseD_5:

  do {

    pbVar8[lVar16] = pbVar8[lVar12] - (*pbVar8 >> 1);

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

switchD_14007982f_caseD_4:

  do {

    bVar11 = (pbVar8 + lVar19)[-lVar12];

    bVar1 = pbVar8[lVar19];

    iVar26 = (uint)bVar1 - (uint)bVar11;

    iVar25 = -iVar26;

    if (-iVar26 < 0) {

      iVar25 = iVar26;

    }

    iVar28 = (uint)*pbVar8 - (uint)bVar11;

    iVar27 = -iVar28;

    if (-iVar28 < 0) {

      iVar27 = iVar28;

    }

    iVar4 = -(iVar28 + iVar26);

    if (iVar4 < 0) {

      iVar4 = iVar28 + iVar26;

    }

    if (((iVar27 < iVar25) || (bVar21 = *pbVar8, iVar4 < iVar25)) &&

       (bVar21 = bVar11, iVar27 <= iVar4)) {

      bVar21 = bVar1;

    }

    pbVar8[lVar16] = pbVar8[lVar12] - bVar21;

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

LAB_140079aa6:

  lVar16 = 0;

  iVar25 = local_res10;

  if (local_b8 != 0) goto LAB_140079c04;

  lVar17 = lVar16;

  iVar25 = 0;

  if (((0 < (int)uVar18) && (lVar17 = 0, iVar25 = 0, 7 < uVar18)) && (1 < DAT_1403e8ad0)) {

    iVar25 = 0;

    iVar26 = 0;

    iVar27 = 0;

    iVar28 = 0;

    uVar10 = uVar18 & 0x80000007;

    if ((int)uVar10 < 0) {

      uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;

    }

    auVar29 = ZEXT816(0);

    do {

      auVar23 = pmovsxbd(in_XMM1,*(undefined4 *)(lVar16 + lVar6));

      auVar24 = pabsd(in_XMM2,auVar23);

      in_XMM1 = pmovsxbd(auVar23,*(undefined4 *)(lVar16 + 4 + lVar6));

      iVar25 = iVar25 + auVar24._0_4_;

      iVar26 = iVar26 + auVar24._4_4_;

      iVar27 = iVar27 + auVar24._8_4_;

      iVar28 = iVar28 + auVar24._12_4_;

      lVar16 = lVar16 + 8;

      auVar23 = pabsd(auVar24,in_XMM1);

      in_XMM2._0_4_ = auVar23._0_4_ + auVar29._0_4_;

      in_XMM2._4_4_ = auVar23._4_4_ + auVar29._4_4_;

      in_XMM2._8_4_ = auVar23._8_4_ + auVar29._8_4_;

      in_XMM2._12_4_ = auVar23._12_4_ + auVar29._12_4_;

      auVar29 = in_XMM2;

    } while (lVar16 < (int)(uVar18 - uVar10));

    iVar25 = iVar25 + in_XMM2._0_4_ + iVar27 + in_XMM2._8_4_ +

             iVar26 + in_XMM2._4_4_ + iVar28 + in_XMM2._12_4_;

    lVar17 = lVar16;

  }

  iVar26 = 0;

  iVar27 = 0;

  if (lVar22 <= lVar17) goto LAB_140079b9e;

  if (lVar22 - lVar17 < 2) {

LAB_140079b8b:

    iVar28 = -(int)*(char *)(lVar17 + lVar6);

    if (iVar28 < 0) {

      iVar28 = (int)*(char *)(lVar17 + lVar6);

    }

    iVar25 = iVar25 + iVar28;

  }

  else {

    do {

      iVar28 = -(int)*(char *)(lVar17 + lVar6);

      if (iVar28 < 0) {

        iVar28 = (int)*(char *)(lVar17 + lVar6);

      }

      iVar4 = (int)*(char *)(lVar17 + 1 + lVar6);

      iVar26 = iVar26 + iVar28;

      iVar28 = -iVar4;

      if (iVar28 < 0) {

        iVar28 = iVar4;

      }

      lVar17 = lVar17 + 2;

      iVar27 = iVar27 + iVar28;

    } while (lVar17 < lVar22 + -1);

    if (lVar17 < lVar22) goto LAB_140079b8b;

  }

  iVar25 = iVar25 + iVar27 + iVar26;

LAB_140079b9e:

  iVar26 = local_b0;

  if (local_ac <= iVar25) {

    iVar25 = local_ac;

    iVar26 = local_res10;

  }

  local_res10 = iVar26;

  local_b0 = local_b0 + 1;

  puVar7 = puVar7 + 1;

  local_ac = iVar25;

  iVar25 = local_res10;

  if (4 < local_b0) goto LAB_140079c04;

  goto LAB_1400797a0;

switchD_14007982f_caseD_3:

  do {

    pbVar8[lVar16] = pbVar8[lVar12] - (char)((uint)pbVar8[lVar19] + (uint)*pbVar8 >> 1);

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

switchD_14007982f_caseD_2:

  do {

    pbVar8[lVar16] = pbVar8[lVar12] - pbVar8[lVar19];

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

switchD_14007982f_caseD_1:

  do {

    pbVar8[lVar16] = pbVar8[lVar12] - *pbVar8;

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

switchD_14007982f_caseD_0:

  do {

    pbVar8[lVar16] = pbVar8[lVar12];

    lVar17 = lVar17 + -1;

    pbVar8 = pbVar8 + 1;

  } while (lVar17 != 0);

  goto LAB_140079aa6;

}




