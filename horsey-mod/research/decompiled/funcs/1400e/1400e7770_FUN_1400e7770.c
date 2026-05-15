// Address: 0x1400e7770
// Ghidra name: FUN_1400e7770
// ============ 0x1400e7770 FUN_1400e7770 (size=3065) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1400e7770(undefined8 *param_1,byte *param_2,uint param_3,uint param_4,int param_5,uint param_6)



{

  byte *pbVar1;

  byte *pbVar2;

  byte *pbVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined1 auVar6 [16];

  byte bVar7;

  uint uVar8;

  int *piVar9;

  int iVar10;

  byte bVar11;

  byte bVar12;

  byte bVar13;

  byte bVar14;

  byte bVar15;

  byte bVar16;

  byte bVar17;

  byte bVar18;

  byte bVar19;

  byte bVar20;

  byte bVar21;

  byte bVar22;

  byte bVar23;

  byte bVar24;

  byte bVar25;

  byte bVar26;

  byte bVar27;

  byte bVar28;

  byte bVar29;

  byte bVar30;

  byte bVar31;

  byte bVar32;

  byte bVar33;

  byte bVar34;

  byte bVar35;

  byte bVar36;

  byte bVar37;

  byte bVar38;

  byte bVar39;

  byte bVar40;

  byte bVar41;

  byte bVar42;

  byte bVar43;

  byte bVar44;

  byte bVar45;

  byte bVar46;

  byte bVar47;

  byte bVar48;

  byte bVar49;

  byte bVar50;

  byte bVar51;

  byte bVar52;

  byte bVar53;

  byte bVar54;

  byte bVar55;

  byte bVar56;

  byte bVar57;

  byte bVar58;

  byte bVar59;

  byte bVar60;

  byte bVar61;

  byte bVar62;

  byte bVar63;

  byte bVar64;

  byte bVar65;

  byte bVar66;

  byte bVar67;

  byte bVar68;

  byte bVar69;

  byte bVar70;

  byte bVar71;

  byte bVar72;

  int iVar73;

  int iVar74;

  longlong lVar75;

  uint uVar76;

  int iVar77;

  int iVar78;

  byte bVar79;

  byte *pbVar80;

  ulonglong uVar81;

  byte *pbVar82;

  ulonglong uVar83;

  uint uVar84;

  longlong lVar85;

  uint uVar86;

  ulonglong uVar87;

  longlong lVar88;

  byte *pbVar89;

  longlong lVar90;

  longlong lVar91;

  ulonglong uVar92;

  uint local_78;

  

  piVar9 = (int *)*param_1;

  lVar90 = (longlong)(int)param_4;

  uVar8 = piVar9[2];

  uVar87 = (ulonglong)(int)uVar8;

  uVar84 = param_4 * param_5;

  if (DAT_1403ffc00 != 0) {

    param_6 = 1;

  }

  lVar75 = _malloc_base(uVar84 * param_6);

  param_1[3] = lVar75;

  if (lVar75 == 0) {

    _DAT_1403f4c40 = "outofmem";

    return 0;

  }

  if (DAT_1403ffc00 == 0) {

    if ((*piVar9 == param_5) && (piVar9[1] == param_6)) {

      if (param_3 != (uVar8 * param_5 + 1) * param_6) {

LAB_1400e78e3:

        _DAT_1403f4c40 = "not enough pixels";

        return 0;

      }

    }

    else if (param_3 < (uVar8 * param_5 + 1) * param_6) goto LAB_1400e78e3;

  }

  local_78 = 0;

  uVar92 = uVar87;

  if (param_6 == 0) {

    return 1;

  }

LAB_1400e7860:

  bVar7 = *param_2;

  param_2 = param_2 + 1;

  lVar75 = (ulonglong)(local_78 * uVar84) + param_1[3];

  lVar88 = lVar75 - (ulonglong)uVar84;

  if (4 < bVar7) {

    _DAT_1403f4c40 = "invalid filter";

    return 0;

  }

  if (local_78 == 0) {

    bVar7 = (&DAT_1403dae08)[bVar7];

  }

  if (0 < (longlong)uVar87) {

    lVar85 = lVar88 - (longlong)param_2;

    lVar91 = lVar75 - (longlong)param_2;

    pbVar80 = param_2;

    uVar83 = uVar87;

    do {

      switch(bVar7) {

      case 0:

        goto switchD_1400e78cd_caseD_0;

      case 1:

        goto switchD_1400e78cd_caseD_1;

      case 2:

        goto switchD_1400e78cd_caseD_2;

      case 3:

        goto switchD_1400e78cd_caseD_3;

      case 4:

        goto switchD_1400e78cd_caseD_4;

      case 5:

        goto switchD_1400e78cd_caseD_5;

      case 6:

        goto switchD_1400e78cd_caseD_6;

      }

      pbVar80 = pbVar80 + 1;

      uVar83 = uVar83 - 1;

    } while (uVar83 != 0);

  }

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_6:

  do {

    pbVar80[lVar91] = *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_5:

  do {

    pbVar80[lVar91] = *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_4:

  do {

    bVar79 = 0;

    if (pbVar80[lVar85] != 0) {

      bVar79 = pbVar80[lVar85];

    }

    pbVar80[lVar91] = bVar79 + *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_3:

  do {

    pbVar80[lVar91] = (pbVar80[lVar85] >> 1) + *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_2:

  do {

    pbVar80[lVar91] = pbVar80[lVar85] + *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

LAB_1400e79f6:

  uVar86 = (uint)uVar92;

  if (uVar86 == param_4) {

    pbVar89 = (byte *)(lVar88 + lVar90);

    param_2 = param_2 + uVar87;

    pbVar80 = (byte *)(lVar75 + lVar90);

    switch(bVar7) {

    case 0:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          lVar75 = 0;

          if ((((int)uVar86 < 1) || (uVar86 < 0x10)) ||

             ((pbVar80 <= param_2 + (int)(uVar86 - 1) && (param_2 <= pbVar80 + (int)(uVar86 - 1)))))

          {

            if (0 < (longlong)uVar87) {

              pbVar89 = pbVar80;

              uVar81 = uVar87;

              do {

                *pbVar89 = pbVar89[(longlong)param_2 - (longlong)pbVar80];

                pbVar89 = pbVar89 + 1;

                uVar81 = uVar81 - 1;

              } while (uVar81 != 0);

            }

          }

          else {

            FUN_1402f8e20(pbVar80,param_2,uVar87);

            do {

              lVar75 = lVar75 + 1;

            } while (lVar75 < (longlong)uVar87);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 1:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - uVar87))] + *pbVar89;

              pbVar89 = pbVar89 + 1;

              uVar81 = uVar81 - 1;

            } while (uVar81 != 0);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 2:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          lVar88 = 0;

          lVar75 = lVar88;

          if ((0 < (int)uVar86) && (7 < uVar86)) {

            iVar73 = uVar86 - 1;

            if (((param_2 + iVar73 < pbVar80) || (pbVar80 + iVar73 < param_2)) &&

               ((pbVar89 + iVar73 < pbVar80 || (lVar75 = 0, pbVar80 + iVar73 < pbVar89)))) {

              lVar75 = lVar88;

              if (0x3f < uVar86) {

                uVar76 = uVar86 & 0x8000003f;

                if ((int)uVar76 < 0) {

                  uVar76 = (uVar76 - 1 | 0xffffffc0) + 1;

                }

                lVar85 = (longlong)pbVar89 - (longlong)param_2;

                pbVar82 = param_2 + 0x10;

                do {

                  pbVar2 = pbVar82 + lVar85 + -0x10;

                  bVar7 = pbVar2[1];

                  bVar79 = pbVar2[2];

                  bVar11 = pbVar2[3];

                  bVar12 = pbVar2[4];

                  bVar13 = pbVar2[5];

                  bVar14 = pbVar2[6];

                  bVar15 = pbVar2[7];

                  bVar16 = pbVar2[8];

                  bVar17 = pbVar2[9];

                  bVar18 = pbVar2[10];

                  bVar19 = pbVar2[0xb];

                  bVar20 = pbVar2[0xc];

                  bVar21 = pbVar2[0xd];

                  bVar22 = pbVar2[0xe];

                  bVar23 = pbVar2[0xf];

                  lVar75 = lVar75 + 0x40;

                  bVar24 = pbVar82[-0xf];

                  bVar25 = pbVar82[-0xe];

                  bVar26 = pbVar82[-0xd];

                  bVar27 = pbVar82[-0xc];

                  bVar28 = pbVar82[-0xb];

                  bVar29 = pbVar82[-10];

                  bVar30 = pbVar82[-9];

                  bVar31 = pbVar82[-8];

                  bVar32 = pbVar82[-7];

                  bVar33 = pbVar82[-6];

                  bVar34 = pbVar82[-5];

                  bVar35 = pbVar82[-4];

                  bVar36 = pbVar82[-3];

                  bVar37 = pbVar82[-2];

                  bVar38 = pbVar82[-1];

                  pbVar1 = pbVar82 + lVar85;

                  bVar39 = *pbVar1;

                  bVar40 = pbVar1[1];

                  bVar41 = pbVar1[2];

                  bVar42 = pbVar1[3];

                  bVar43 = pbVar1[4];

                  bVar44 = pbVar1[5];

                  bVar45 = pbVar1[6];

                  bVar46 = pbVar1[7];

                  bVar47 = pbVar1[8];

                  bVar48 = pbVar1[9];

                  bVar49 = pbVar1[10];

                  bVar50 = pbVar1[0xb];

                  bVar51 = pbVar1[0xc];

                  bVar52 = pbVar1[0xd];

                  bVar53 = pbVar1[0xe];

                  bVar54 = pbVar1[0xf];

                  pbVar1 = pbVar82 + 0x40;

                  bVar55 = *pbVar82;

                  bVar56 = pbVar82[1];

                  bVar57 = pbVar82[2];

                  bVar58 = pbVar82[3];

                  bVar59 = pbVar82[4];

                  bVar60 = pbVar82[5];

                  bVar61 = pbVar82[6];

                  bVar62 = pbVar82[7];

                  bVar63 = pbVar82[8];

                  bVar64 = pbVar82[9];

                  bVar65 = pbVar82[10];

                  bVar66 = pbVar82[0xb];

                  bVar67 = pbVar82[0xc];

                  bVar68 = pbVar82[0xd];

                  bVar69 = pbVar82[0xe];

                  bVar70 = pbVar82[0xf];

                  pbVar3 = pbVar1 + (longlong)(pbVar80 + (-0x50 - (longlong)param_2));

                  *pbVar3 = pbVar82[-0x10] + *pbVar2;

                  pbVar3[1] = bVar24 + bVar7;

                  pbVar3[2] = bVar25 + bVar79;

                  pbVar3[3] = bVar26 + bVar11;

                  pbVar3[4] = bVar27 + bVar12;

                  pbVar3[5] = bVar28 + bVar13;

                  pbVar3[6] = bVar29 + bVar14;

                  pbVar3[7] = bVar30 + bVar15;

                  pbVar3[8] = bVar31 + bVar16;

                  pbVar3[9] = bVar32 + bVar17;

                  pbVar3[10] = bVar33 + bVar18;

                  pbVar3[0xb] = bVar34 + bVar19;

                  pbVar3[0xc] = bVar35 + bVar20;

                  pbVar3[0xd] = bVar36 + bVar21;

                  pbVar3[0xe] = bVar37 + bVar22;

                  pbVar3[0xf] = bVar38 + bVar23;

                  pbVar2 = pbVar1 + lVar85 + -0x30;

                  bVar7 = *pbVar2;

                  bVar79 = pbVar2[1];

                  bVar11 = pbVar2[2];

                  bVar12 = pbVar2[3];

                  bVar13 = pbVar2[4];

                  bVar14 = pbVar2[5];

                  bVar15 = pbVar2[6];

                  bVar16 = pbVar2[7];

                  bVar17 = pbVar2[8];

                  bVar18 = pbVar2[9];

                  bVar19 = pbVar2[10];

                  bVar20 = pbVar2[0xb];

                  bVar21 = pbVar2[0xc];

                  bVar22 = pbVar2[0xd];

                  bVar23 = pbVar2[0xe];

                  bVar24 = pbVar2[0xf];

                  bVar25 = pbVar82[0x10];

                  bVar26 = pbVar82[0x11];

                  bVar27 = pbVar82[0x12];

                  bVar28 = pbVar82[0x13];

                  bVar29 = pbVar82[0x14];

                  bVar30 = pbVar82[0x15];

                  bVar31 = pbVar82[0x16];

                  bVar32 = pbVar82[0x17];

                  bVar33 = pbVar82[0x18];

                  bVar34 = pbVar82[0x19];

                  bVar35 = pbVar82[0x1a];

                  bVar36 = pbVar82[0x1b];

                  bVar37 = pbVar82[0x1c];

                  bVar38 = pbVar82[0x1d];

                  bVar71 = pbVar82[0x1e];

                  bVar72 = pbVar82[0x1f];

                  pbVar2 = pbVar1 + (longlong)(pbVar80 + (-0x40 - (longlong)param_2));

                  *pbVar2 = bVar39 + bVar55;

                  pbVar2[1] = bVar40 + bVar56;

                  pbVar2[2] = bVar41 + bVar57;

                  pbVar2[3] = bVar42 + bVar58;

                  pbVar2[4] = bVar43 + bVar59;

                  pbVar2[5] = bVar44 + bVar60;

                  pbVar2[6] = bVar45 + bVar61;

                  pbVar2[7] = bVar46 + bVar62;

                  pbVar2[8] = bVar47 + bVar63;

                  pbVar2[9] = bVar48 + bVar64;

                  pbVar2[10] = bVar49 + bVar65;

                  pbVar2[0xb] = bVar50 + bVar66;

                  pbVar2[0xc] = bVar51 + bVar67;

                  pbVar2[0xd] = bVar52 + bVar68;

                  pbVar2[0xe] = bVar53 + bVar69;

                  pbVar2[0xf] = bVar54 + bVar70;

                  auVar6 = *(undefined1 (*) [16])(pbVar1 + lVar85 + -0x20);

                  bVar39 = pbVar82[0x20];

                  bVar40 = pbVar82[0x21];

                  bVar41 = pbVar82[0x22];

                  bVar42 = pbVar82[0x23];

                  bVar43 = pbVar82[0x24];

                  bVar44 = pbVar82[0x25];

                  bVar45 = pbVar82[0x26];

                  bVar46 = pbVar82[0x27];

                  bVar47 = pbVar82[0x28];

                  bVar48 = pbVar82[0x29];

                  bVar49 = pbVar82[0x2a];

                  bVar50 = pbVar82[0x2b];

                  bVar51 = pbVar82[0x2c];

                  bVar52 = pbVar82[0x2d];

                  bVar53 = pbVar82[0x2e];

                  bVar54 = pbVar82[0x2f];

                  pbVar82 = pbVar1 + (longlong)(pbVar80 + (-0x30 - (longlong)param_2));

                  *pbVar82 = bVar25 + bVar7;

                  pbVar82[1] = bVar26 + bVar79;

                  pbVar82[2] = bVar27 + bVar11;

                  pbVar82[3] = bVar28 + bVar12;

                  pbVar82[4] = bVar29 + bVar13;

                  pbVar82[5] = bVar30 + bVar14;

                  pbVar82[6] = bVar31 + bVar15;

                  pbVar82[7] = bVar32 + bVar16;

                  pbVar82[8] = bVar33 + bVar17;

                  pbVar82[9] = bVar34 + bVar18;

                  pbVar82[10] = bVar35 + bVar19;

                  pbVar82[0xb] = bVar36 + bVar20;

                  pbVar82[0xc] = bVar37 + bVar21;

                  pbVar82[0xd] = bVar38 + bVar22;

                  pbVar82[0xe] = bVar71 + bVar23;

                  pbVar82[0xf] = bVar72 + bVar24;

                  pbVar82 = pbVar1 + (longlong)(pbVar80 + (-0x20 - (longlong)param_2));

                  *pbVar82 = bVar39 + auVar6[0];

                  pbVar82[1] = bVar40 + auVar6[1];

                  pbVar82[2] = bVar41 + auVar6[2];

                  pbVar82[3] = bVar42 + auVar6[3];

                  pbVar82[4] = bVar43 + auVar6[4];

                  pbVar82[5] = bVar44 + auVar6[5];

                  pbVar82[6] = bVar45 + auVar6[6];

                  pbVar82[7] = bVar46 + auVar6[7];

                  pbVar82[8] = bVar47 + auVar6[8];

                  pbVar82[9] = bVar48 + auVar6[9];

                  pbVar82[10] = bVar49 + auVar6[10];

                  pbVar82[0xb] = bVar50 + auVar6[0xb];

                  pbVar82[0xc] = bVar51 + auVar6[0xc];

                  pbVar82[0xd] = bVar52 + auVar6[0xd];

                  pbVar82[0xe] = bVar53 + auVar6[0xe];

                  pbVar82[0xf] = bVar54 + auVar6[0xf];

                  pbVar82 = pbVar1;

                } while (lVar75 < (int)(uVar86 - uVar76));

                if (((byte)uVar92 & 0x3f) < 8) goto LAB_1400e8101;

              }

              uVar76 = uVar86 & 0x80000007;

              if ((int)uVar76 < 0) {

                uVar76 = (uVar76 - 1 | 0xfffffff8) + 1;

              }

              pbVar82 = param_2 + lVar75;

              do {

                uVar4 = *(undefined8 *)(pbVar82 + ((longlong)pbVar89 - (longlong)param_2));

                lVar75 = lVar75 + 8;

                uVar5 = *(undefined8 *)pbVar82;

                pbVar82 = pbVar82 + 8;

                *(ulonglong *)(pbVar82 + (longlong)(pbVar80 + (-8 - (longlong)param_2))) =

                     CONCAT17((char)((ulonglong)uVar4 >> 0x38) + (char)((ulonglong)uVar5 >> 0x38),

                              CONCAT16((char)((ulonglong)uVar4 >> 0x30) +

                                       (char)((ulonglong)uVar5 >> 0x30),

                                       CONCAT15((char)((ulonglong)uVar4 >> 0x28) +

                                                (char)((ulonglong)uVar5 >> 0x28),

                                                CONCAT14((char)((ulonglong)uVar4 >> 0x20) +

                                                         (char)((ulonglong)uVar5 >> 0x20),

                                                         CONCAT13((char)((ulonglong)uVar4 >> 0x18) +

                                                                  (char)((ulonglong)uVar5 >> 0x18),

                                                                  CONCAT12((char)((ulonglong)uVar4

                                                                                 >> 0x10) +

                                                                           (char)((ulonglong)uVar5

                                                                                 >> 0x10),

                                                                           CONCAT11((char)((

                                                  ulonglong)uVar4 >> 8) +

                                                  (char)((ulonglong)uVar5 >> 8),

                                                  (char)uVar4 + (char)uVar5)))))));

              } while (lVar75 < (int)(uVar86 - uVar76));

            }

          }

LAB_1400e8101:

          if (lVar75 < (longlong)uVar87) {

            pbVar82 = param_2 + lVar75;

            lVar75 = uVar87 - lVar75;

            do {

              pbVar82[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar82[(longlong)pbVar89 - (longlong)param_2] + *pbVar82;

              pbVar82 = pbVar82 + 1;

              lVar75 = lVar75 + -1;

            } while (lVar75 != 0);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          pbVar89 = pbVar89 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 3:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar82 = pbVar89;

            uVar81 = uVar87;

            do {

              pbVar82[(longlong)pbVar80 - (longlong)pbVar89] =

                   (char)((uint)pbVar82[(longlong)(pbVar80 + (-(longlong)pbVar89 - uVar87))] +

                          (uint)*pbVar82 >> 1) + pbVar82[(longlong)param_2 - (longlong)pbVar89];

              uVar81 = uVar81 - 1;

              pbVar82 = pbVar82 + 1;

            } while (uVar81 != 0);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          pbVar89 = pbVar89 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 4:

      uVar83 = (ulonglong)(param_5 - 1U);

      if (param_5 - 1U != 0) {

        do {

          if (0 < (longlong)uVar87) {

            pbVar82 = pbVar80 + -uVar87;

            uVar92 = uVar87;

            do {

              bVar7 = pbVar82[(longlong)pbVar89 - (longlong)pbVar80];

              iVar77 = (uint)pbVar82[(longlong)(pbVar89 + (uVar87 - (longlong)pbVar80))] -

                       (uint)bVar7;

              iVar73 = -iVar77;

              if (-iVar77 < 0) {

                iVar73 = iVar77;

              }

              iVar74 = (uint)*pbVar82 - (uint)bVar7;

              iVar10 = -iVar74;

              if (-iVar74 < 0) {

                iVar10 = iVar74;

              }

              iVar78 = -(iVar74 + iVar77);

              if (iVar78 < 0) {

                iVar78 = iVar74 + iVar77;

              }

              if (((iVar10 < iVar73) || (bVar79 = *pbVar82, iVar78 < iVar73)) &&

                 (bVar79 = bVar7, iVar10 <= iVar78)) {

                bVar79 = pbVar82[(longlong)(pbVar89 + (uVar87 - (longlong)pbVar80))];

              }

              pbVar82[uVar87] = bVar79 + (param_2 + (uVar87 - (longlong)pbVar80))[(longlong)pbVar82]

              ;

              pbVar82 = pbVar82 + 1;

              uVar92 = uVar92 - 1;

            } while (uVar92 != 0);

          }

          pbVar89 = pbVar89 + uVar87;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

        uVar92 = (ulonglong)uVar8;

      }

      break;

    case 5:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   (pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - uVar87))] >> 1) + *pbVar89;

              uVar81 = uVar81 - 1;

              pbVar89 = pbVar89 + 1;

            } while (uVar81 != 0);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 6:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - uVar87))] + *pbVar89;

              pbVar89 = pbVar89 + 1;

              uVar81 = uVar81 - 1;

            } while (uVar81 != 0);

          }

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

    }

  }

  else {

    *(undefined1 *)(uVar87 + lVar75) = 0xff;

    pbVar80 = (byte *)(lVar75 + lVar90);

    pbVar89 = (byte *)(lVar88 + lVar90);

    param_2 = param_2 + uVar87;

    switch(bVar7) {

    case 0:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = pbVar80;

            uVar81 = uVar87;

            do {

              *pbVar89 = pbVar89[(longlong)param_2 - (longlong)pbVar80];

              pbVar89 = pbVar89 + 1;

              uVar81 = uVar81 - 1;

            } while (uVar81 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 1:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - lVar90))] + *pbVar89;

              pbVar89 = pbVar89 + 1;

              uVar81 = uVar81 - 1;

            } while (uVar81 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 2:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          lVar88 = 0;

          lVar75 = lVar88;

          if ((0 < (int)uVar86) && (7 < uVar86)) {

            iVar73 = uVar86 - 1;

            if (((param_2 + iVar73 < pbVar80) || (pbVar80 + iVar73 < param_2)) &&

               ((pbVar89 + iVar73 < pbVar80 || (lVar75 = 0, pbVar80 + iVar73 < pbVar89)))) {

              lVar75 = lVar88;

              if (0x3f < uVar86) {

                uVar76 = uVar86 & 0x8000003f;

                if ((int)uVar76 < 0) {

                  uVar76 = (uVar76 - 1 | 0xffffffc0) + 1;

                }

                lVar85 = (longlong)pbVar89 - (longlong)param_2;

                lVar91 = (longlong)pbVar80 - (longlong)param_2;

                pbVar82 = param_2 + 0x10;

                do {

                  pbVar2 = pbVar82 + lVar85 + -0x10;

                  bVar7 = pbVar2[1];

                  bVar79 = pbVar2[2];

                  bVar11 = pbVar2[3];

                  bVar12 = pbVar2[4];

                  bVar13 = pbVar2[5];

                  bVar14 = pbVar2[6];

                  bVar15 = pbVar2[7];

                  bVar16 = pbVar2[8];

                  bVar17 = pbVar2[9];

                  bVar18 = pbVar2[10];

                  bVar19 = pbVar2[0xb];

                  bVar20 = pbVar2[0xc];

                  bVar21 = pbVar2[0xd];

                  bVar22 = pbVar2[0xe];

                  bVar23 = pbVar2[0xf];

                  lVar75 = lVar75 + 0x40;

                  bVar24 = pbVar82[-0xf];

                  bVar25 = pbVar82[-0xe];

                  bVar26 = pbVar82[-0xd];

                  bVar27 = pbVar82[-0xc];

                  bVar28 = pbVar82[-0xb];

                  bVar29 = pbVar82[-10];

                  bVar30 = pbVar82[-9];

                  bVar31 = pbVar82[-8];

                  bVar32 = pbVar82[-7];

                  bVar33 = pbVar82[-6];

                  bVar34 = pbVar82[-5];

                  bVar35 = pbVar82[-4];

                  bVar36 = pbVar82[-3];

                  bVar37 = pbVar82[-2];

                  bVar38 = pbVar82[-1];

                  pbVar1 = pbVar82 + lVar85;

                  bVar39 = *pbVar1;

                  bVar40 = pbVar1[1];

                  bVar41 = pbVar1[2];

                  bVar42 = pbVar1[3];

                  bVar43 = pbVar1[4];

                  bVar44 = pbVar1[5];

                  bVar45 = pbVar1[6];

                  bVar46 = pbVar1[7];

                  bVar47 = pbVar1[8];

                  bVar48 = pbVar1[9];

                  bVar49 = pbVar1[10];

                  bVar50 = pbVar1[0xb];

                  bVar51 = pbVar1[0xc];

                  bVar52 = pbVar1[0xd];

                  bVar53 = pbVar1[0xe];

                  bVar54 = pbVar1[0xf];

                  bVar55 = *pbVar82;

                  bVar56 = pbVar82[1];

                  bVar57 = pbVar82[2];

                  bVar58 = pbVar82[3];

                  bVar59 = pbVar82[4];

                  bVar60 = pbVar82[5];

                  bVar61 = pbVar82[6];

                  bVar62 = pbVar82[7];

                  bVar63 = pbVar82[8];

                  bVar64 = pbVar82[9];

                  bVar65 = pbVar82[10];

                  bVar66 = pbVar82[0xb];

                  bVar67 = pbVar82[0xc];

                  bVar68 = pbVar82[0xd];

                  bVar69 = pbVar82[0xe];

                  bVar70 = pbVar82[0xf];

                  pbVar1 = pbVar82 + lVar91 + -0x10;

                  *pbVar1 = pbVar82[-0x10] + *pbVar2;

                  pbVar1[1] = bVar24 + bVar7;

                  pbVar1[2] = bVar25 + bVar79;

                  pbVar1[3] = bVar26 + bVar11;

                  pbVar1[4] = bVar27 + bVar12;

                  pbVar1[5] = bVar28 + bVar13;

                  pbVar1[6] = bVar29 + bVar14;

                  pbVar1[7] = bVar30 + bVar15;

                  pbVar1[8] = bVar31 + bVar16;

                  pbVar1[9] = bVar32 + bVar17;

                  pbVar1[10] = bVar33 + bVar18;

                  pbVar1[0xb] = bVar34 + bVar19;

                  pbVar1[0xc] = bVar35 + bVar20;

                  pbVar1[0xd] = bVar36 + bVar21;

                  pbVar1[0xe] = bVar37 + bVar22;

                  pbVar1[0xf] = bVar38 + bVar23;

                  pbVar1 = pbVar82 + lVar85 + 0x10;

                  bVar7 = *pbVar1;

                  bVar79 = pbVar1[1];

                  bVar11 = pbVar1[2];

                  bVar12 = pbVar1[3];

                  bVar13 = pbVar1[4];

                  bVar14 = pbVar1[5];

                  bVar15 = pbVar1[6];

                  bVar16 = pbVar1[7];

                  bVar17 = pbVar1[8];

                  bVar18 = pbVar1[9];

                  bVar19 = pbVar1[10];

                  bVar20 = pbVar1[0xb];

                  bVar21 = pbVar1[0xc];

                  bVar22 = pbVar1[0xd];

                  bVar23 = pbVar1[0xe];

                  bVar24 = pbVar1[0xf];

                  bVar25 = pbVar82[0x10];

                  bVar26 = pbVar82[0x11];

                  bVar27 = pbVar82[0x12];

                  bVar28 = pbVar82[0x13];

                  bVar29 = pbVar82[0x14];

                  bVar30 = pbVar82[0x15];

                  bVar31 = pbVar82[0x16];

                  bVar32 = pbVar82[0x17];

                  bVar33 = pbVar82[0x18];

                  bVar34 = pbVar82[0x19];

                  bVar35 = pbVar82[0x1a];

                  bVar36 = pbVar82[0x1b];

                  bVar37 = pbVar82[0x1c];

                  bVar38 = pbVar82[0x1d];

                  bVar71 = pbVar82[0x1e];

                  bVar72 = pbVar82[0x1f];

                  pbVar1 = pbVar82 + lVar91;

                  *pbVar1 = bVar39 + bVar55;

                  pbVar1[1] = bVar40 + bVar56;

                  pbVar1[2] = bVar41 + bVar57;

                  pbVar1[3] = bVar42 + bVar58;

                  pbVar1[4] = bVar43 + bVar59;

                  pbVar1[5] = bVar44 + bVar60;

                  pbVar1[6] = bVar45 + bVar61;

                  pbVar1[7] = bVar46 + bVar62;

                  pbVar1[8] = bVar47 + bVar63;

                  pbVar1[9] = bVar48 + bVar64;

                  pbVar1[10] = bVar49 + bVar65;

                  pbVar1[0xb] = bVar50 + bVar66;

                  pbVar1[0xc] = bVar51 + bVar67;

                  pbVar1[0xd] = bVar52 + bVar68;

                  pbVar1[0xe] = bVar53 + bVar69;

                  pbVar1[0xf] = bVar54 + bVar70;

                  auVar6 = *(undefined1 (*) [16])(pbVar82 + lVar85 + 0x20);

                  bVar39 = pbVar82[0x20];

                  bVar40 = pbVar82[0x21];

                  bVar41 = pbVar82[0x22];

                  bVar42 = pbVar82[0x23];

                  bVar43 = pbVar82[0x24];

                  bVar44 = pbVar82[0x25];

                  bVar45 = pbVar82[0x26];

                  bVar46 = pbVar82[0x27];

                  bVar47 = pbVar82[0x28];

                  bVar48 = pbVar82[0x29];

                  bVar49 = pbVar82[0x2a];

                  bVar50 = pbVar82[0x2b];

                  bVar51 = pbVar82[0x2c];

                  bVar52 = pbVar82[0x2d];

                  bVar53 = pbVar82[0x2e];

                  bVar54 = pbVar82[0x2f];

                  pbVar1 = pbVar82 + lVar91 + 0x10;

                  *pbVar1 = bVar25 + bVar7;

                  pbVar1[1] = bVar26 + bVar79;

                  pbVar1[2] = bVar27 + bVar11;

                  pbVar1[3] = bVar28 + bVar12;

                  pbVar1[4] = bVar29 + bVar13;

                  pbVar1[5] = bVar30 + bVar14;

                  pbVar1[6] = bVar31 + bVar15;

                  pbVar1[7] = bVar32 + bVar16;

                  pbVar1[8] = bVar33 + bVar17;

                  pbVar1[9] = bVar34 + bVar18;

                  pbVar1[10] = bVar35 + bVar19;

                  pbVar1[0xb] = bVar36 + bVar20;

                  pbVar1[0xc] = bVar37 + bVar21;

                  pbVar1[0xd] = bVar38 + bVar22;

                  pbVar1[0xe] = bVar71 + bVar23;

                  pbVar1[0xf] = bVar72 + bVar24;

                  pbVar1 = pbVar82 + lVar91 + 0x20;

                  *pbVar1 = bVar39 + auVar6[0];

                  pbVar1[1] = bVar40 + auVar6[1];

                  pbVar1[2] = bVar41 + auVar6[2];

                  pbVar1[3] = bVar42 + auVar6[3];

                  pbVar1[4] = bVar43 + auVar6[4];

                  pbVar1[5] = bVar44 + auVar6[5];

                  pbVar1[6] = bVar45 + auVar6[6];

                  pbVar1[7] = bVar46 + auVar6[7];

                  pbVar1[8] = bVar47 + auVar6[8];

                  pbVar1[9] = bVar48 + auVar6[9];

                  pbVar1[10] = bVar49 + auVar6[10];

                  pbVar1[0xb] = bVar50 + auVar6[0xb];

                  pbVar1[0xc] = bVar51 + auVar6[0xc];

                  pbVar1[0xd] = bVar52 + auVar6[0xd];

                  pbVar1[0xe] = bVar53 + auVar6[0xe];

                  pbVar1[0xf] = bVar54 + auVar6[0xf];

                  pbVar82 = pbVar82 + 0x40;

                } while (lVar75 < (int)(uVar86 - uVar76));

                if (((byte)uVar92 & 0x3f) < 8) goto LAB_1400e7c31;

              }

              uVar76 = uVar86 & 0x80000007;

              if ((int)uVar76 < 0) {

                uVar76 = (uVar76 - 1 | 0xfffffff8) + 1;

              }

              pbVar82 = param_2 + lVar75;

              do {

                uVar4 = *(undefined8 *)(pbVar82 + ((longlong)pbVar89 - (longlong)param_2));

                lVar75 = lVar75 + 8;

                uVar5 = *(undefined8 *)pbVar82;

                *(ulonglong *)(pbVar82 + ((longlong)pbVar80 - (longlong)param_2)) =

                     CONCAT17((char)((ulonglong)uVar4 >> 0x38) + (char)((ulonglong)uVar5 >> 0x38),

                              CONCAT16((char)((ulonglong)uVar4 >> 0x30) +

                                       (char)((ulonglong)uVar5 >> 0x30),

                                       CONCAT15((char)((ulonglong)uVar4 >> 0x28) +

                                                (char)((ulonglong)uVar5 >> 0x28),

                                                CONCAT14((char)((ulonglong)uVar4 >> 0x20) +

                                                         (char)((ulonglong)uVar5 >> 0x20),

                                                         CONCAT13((char)((ulonglong)uVar4 >> 0x18) +

                                                                  (char)((ulonglong)uVar5 >> 0x18),

                                                                  CONCAT12((char)((ulonglong)uVar4

                                                                                 >> 0x10) +

                                                                           (char)((ulonglong)uVar5

                                                                                 >> 0x10),

                                                                           CONCAT11((char)((

                                                  ulonglong)uVar4 >> 8) +

                                                  (char)((ulonglong)uVar5 >> 8),

                                                  (char)uVar4 + (char)uVar5)))))));

                pbVar82 = pbVar82 + 8;

              } while (lVar75 < (int)(uVar86 - uVar76));

            }

          }

LAB_1400e7c31:

          if (lVar75 < (longlong)uVar87) {

            pbVar82 = param_2 + lVar75;

            lVar75 = uVar87 - lVar75;

            do {

              pbVar82[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar82[(longlong)pbVar89 - (longlong)param_2] + *pbVar82;

              pbVar82 = pbVar82 + 1;

              lVar75 = lVar75 + -1;

            } while (lVar75 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          pbVar89 = pbVar89 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 3:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar82 = pbVar89;

            uVar81 = uVar87;

            do {

              pbVar82[(longlong)pbVar80 - (longlong)pbVar89] =

                   (char)((uint)pbVar82[(longlong)(pbVar80 + (-(longlong)pbVar89 - lVar90))] +

                          (uint)*pbVar82 >> 1) + pbVar82[(longlong)param_2 - (longlong)pbVar89];

              uVar81 = uVar81 - 1;

              pbVar82 = pbVar82 + 1;

            } while (uVar81 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          pbVar89 = pbVar89 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 4:

      uVar83 = (ulonglong)(param_5 - 1U);

      if (param_5 - 1U != 0) {

        do {

          if (0 < (longlong)uVar87) {

            pbVar82 = pbVar80 + -lVar90;

            uVar92 = uVar87;

            do {

              bVar7 = pbVar82[(longlong)pbVar89 - (longlong)pbVar80];

              iVar77 = (uint)pbVar82[(longlong)(pbVar89 + (lVar90 - (longlong)pbVar80))] -

                       (uint)bVar7;

              iVar73 = -iVar77;

              if (-iVar77 < 0) {

                iVar73 = iVar77;

              }

              iVar74 = (uint)*pbVar82 - (uint)bVar7;

              iVar10 = -iVar74;

              if (-iVar74 < 0) {

                iVar10 = iVar74;

              }

              iVar78 = -(iVar74 + iVar77);

              if (iVar78 < 0) {

                iVar78 = iVar74 + iVar77;

              }

              if (((iVar10 < iVar73) || (bVar79 = *pbVar82, iVar78 < iVar73)) &&

                 (bVar79 = bVar7, iVar10 <= iVar78)) {

                bVar79 = pbVar82[(longlong)(pbVar89 + (lVar90 - (longlong)pbVar80))];

              }

              pbVar82[lVar90] = bVar79 + (param_2 + (lVar90 - (longlong)pbVar80))[(longlong)pbVar82]

              ;

              pbVar82 = pbVar82 + 1;

              uVar92 = uVar92 - 1;

            } while (uVar92 != 0);

          }

          pbVar89 = pbVar89 + lVar90;

          pbVar80[uVar87] = 0xff;

          pbVar80 = pbVar80 + lVar90;

          param_2 = param_2 + uVar87;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

        uVar92 = (ulonglong)uVar8;

      }

      break;

    case 5:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   (pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - lVar90))] >> 1) + *pbVar89;

              uVar81 = uVar81 - 1;

              pbVar89 = pbVar89 + 1;

            } while (uVar81 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

      break;

    case 6:

      if (param_5 - 1U != 0) {

        uVar83 = (ulonglong)(param_5 - 1U);

        do {

          if (0 < (longlong)uVar87) {

            pbVar89 = param_2;

            uVar81 = uVar87;

            do {

              pbVar89[(longlong)pbVar80 - (longlong)param_2] =

                   pbVar89[(longlong)(pbVar80 + (-(longlong)param_2 - lVar90))] + *pbVar89;

              pbVar89 = pbVar89 + 1;

              uVar81 = uVar81 - 1;

            } while (uVar81 != 0);

          }

          pbVar80[uVar87] = 0xff;

          param_2 = param_2 + uVar87;

          pbVar80 = pbVar80 + lVar90;

          uVar83 = uVar83 - 1;

        } while (uVar83 != 0);

      }

    }

  }

  local_78 = local_78 + 1;

  if (param_6 <= local_78) {

    return 1;

  }

  goto LAB_1400e7860;

switchD_1400e78cd_caseD_1:

  do {

    pbVar80[lVar91] = *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

switchD_1400e78cd_caseD_0:

  do {

    pbVar80[lVar91] = *pbVar80;

    uVar83 = uVar83 - 1;

    pbVar80 = pbVar80 + 1;

  } while (uVar83 != 0);

  goto LAB_1400e79f6;

}




