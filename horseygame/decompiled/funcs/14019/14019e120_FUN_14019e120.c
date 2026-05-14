// Address: 0x14019e120
// Ghidra name: FUN_14019e120
// ============ 0x14019e120 FUN_14019e120 (size=2508) ============


ulonglong FUN_14019e120(longlong *param_1,byte *param_2,uint param_3,int param_4,uint param_5,

                       uint param_6,int param_7,int param_8)



{

  byte *pbVar1;

  byte *pbVar2;

  byte *pbVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined1 auVar6 [16];

  int iVar7;

  char cVar8;

  byte bVar9;

  byte bVar10;

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

  char cVar71;

  byte bVar72;

  longlong lVar73;

  ulonglong uVar74;

  byte *pbVar75;

  longlong lVar76;

  int iVar77;

  longlong lVar78;

  longlong lVar79;

  byte *pbVar80;

  byte *pbVar81;

  longlong lVar82;

  byte bVar83;

  int iVar84;

  uint uVar85;

  uint uVar86;

  uint uVar87;

  longlong lVar88;

  byte *pbVar89;

  uint uVar90;

  byte *pbVar91;

  uint uVar92;

  uint local_74;

  uint local_5c;

  

  iVar77 = (param_7 == 0x10) + 1;

  iVar84 = iVar77 * param_4;

  iVar7 = *(int *)(*param_1 + 8);

  local_5c = iVar77 * iVar7;

  lVar73 = FUN_1401a1b30(param_5,param_6,iVar84,0);

  param_1[3] = lVar73;

  if (lVar73 == 0) {

    uVar74 = FUN_14019f050("Out of memory");

    return uVar74;

  }

  iVar77 = FUN_1401a19f0(iVar7,param_5,param_7,7);

  if (iVar77 == 0) {

    uVar74 = FUN_14019f050("Corrupt PNG");

    return uVar74;

  }

  uVar92 = iVar7 * param_5;

  uVar90 = uVar92 * param_7 + 7 >> 3;

  iVar77 = FUN_1401a19b0(uVar90,param_6,uVar90);

  if ((iVar77 == 0) || (param_3 < (uVar90 + 1) * param_6)) {

    uVar74 = FUN_14019f050("Corrupt PNG");

  }

  else {

    lVar73 = FUN_1401a1ae0(uVar90,2,0);

    if (lVar73 == 0) {

      uVar74 = FUN_14019f050("Out of memory");

    }

    else {

      iVar77 = 1;

      uVar85 = param_5;

      if (param_7 < 8) {

        local_5c = 1;

        uVar85 = uVar90;

      }

      local_74 = 0;

      if (param_6 == 0) {

LAB_14019eac3:

        FUN_1401841e0(lVar73);

        uVar74 = (ulonglong)(iVar77 != 0);

      }

      else {

        lVar88 = (longlong)(int)local_5c;

        uVar85 = uVar85 * local_5c;

        do {

          lVar82 = (longlong)(int)uVar85;

          lVar78 = 0;

          pbVar80 = (byte *)((ulonglong)((local_74 & 1) * uVar90) + lVar73);

          pbVar91 = (byte *)((ulonglong)(uVar90 * (~local_74 & 1)) + lVar73);

          pbVar81 = (byte *)((ulonglong)(local_74 * iVar84 * param_5) + param_1[3]);

          bVar83 = *param_2;

          pbVar89 = param_2 + 1;

          if (4 < bVar83) {

            iVar77 = FUN_14019f050("Corrupt PNG");

            goto LAB_14019eac3;

          }

          if (local_74 == 0) {

            bVar83 = (&DAT_1403e3d08)[bVar83];

          }

          switch(bVar83) {

          case 0:

            FUN_1402f8e20(pbVar80,pbVar89);

            break;

          case 1:

            FUN_1402f8e20(pbVar80,pbVar89);

            if (lVar88 < lVar82) {

              pbVar91 = pbVar89 + lVar88;

              lVar82 = lVar82 - lVar88;

              do {

                pbVar91[(longlong)pbVar80 - (longlong)pbVar89] =

                     pbVar91[(longlong)(pbVar80 + (-(longlong)pbVar89 - lVar88))] + *pbVar91;

                pbVar91 = pbVar91 + 1;

                lVar82 = lVar82 + -1;

              } while (lVar82 != 0);

            }

            break;

          case 2:

            lVar79 = lVar78;

            if ((0 < (int)uVar85) && (7 < uVar85)) {

              iVar77 = uVar85 - 1;

              lVar79 = 0;

              if (((pbVar89 + iVar77 < pbVar80) || (pbVar80 + iVar77 < pbVar89)) &&

                 ((pbVar91 + iVar77 < pbVar80 || (pbVar80 + iVar77 < pbVar91)))) {

                lVar79 = lVar78;

                if (0x3f < uVar85) {

                  uVar87 = uVar85 & 0x8000003f;

                  if ((int)uVar87 < 0) {

                    uVar87 = (uVar87 - 1 | 0xffffffc0) + 1;

                  }

                  pbVar75 = param_2 + 0x11;

                  do {

                    pbVar2 = pbVar75 + (longlong)(pbVar91 + (-0x10 - (longlong)pbVar89));

                    bVar83 = pbVar2[1];

                    bVar72 = pbVar2[2];

                    bVar9 = pbVar2[3];

                    bVar10 = pbVar2[4];

                    bVar11 = pbVar2[5];

                    bVar12 = pbVar2[6];

                    bVar13 = pbVar2[7];

                    bVar14 = pbVar2[8];

                    bVar15 = pbVar2[9];

                    bVar16 = pbVar2[10];

                    bVar17 = pbVar2[0xb];

                    bVar18 = pbVar2[0xc];

                    bVar19 = pbVar2[0xd];

                    bVar20 = pbVar2[0xe];

                    bVar21 = pbVar2[0xf];

                    lVar79 = lVar79 + 0x40;

                    bVar22 = pbVar75[-0xf];

                    bVar23 = pbVar75[-0xe];

                    bVar24 = pbVar75[-0xd];

                    bVar25 = pbVar75[-0xc];

                    bVar26 = pbVar75[-0xb];

                    bVar27 = pbVar75[-10];

                    bVar28 = pbVar75[-9];

                    bVar29 = pbVar75[-8];

                    bVar30 = pbVar75[-7];

                    bVar31 = pbVar75[-6];

                    bVar32 = pbVar75[-5];

                    bVar33 = pbVar75[-4];

                    bVar34 = pbVar75[-3];

                    bVar35 = pbVar75[-2];

                    bVar36 = pbVar75[-1];

                    bVar37 = *pbVar75;

                    bVar38 = pbVar75[1];

                    bVar39 = pbVar75[2];

                    bVar40 = pbVar75[3];

                    bVar41 = pbVar75[4];

                    bVar42 = pbVar75[5];

                    bVar43 = pbVar75[6];

                    bVar44 = pbVar75[7];

                    bVar45 = pbVar75[8];

                    bVar46 = pbVar75[9];

                    bVar47 = pbVar75[10];

                    bVar48 = pbVar75[0xb];

                    bVar49 = pbVar75[0xc];

                    bVar50 = pbVar75[0xd];

                    bVar51 = pbVar75[0xe];

                    bVar52 = pbVar75[0xf];

                    pbVar1 = pbVar75 + 0x40;

                    pbVar3 = pbVar1 + (longlong)(pbVar91 + (-0x40 - (longlong)pbVar89));

                    bVar53 = *pbVar3;

                    bVar54 = pbVar3[1];

                    bVar55 = pbVar3[2];

                    bVar56 = pbVar3[3];

                    bVar57 = pbVar3[4];

                    bVar58 = pbVar3[5];

                    bVar59 = pbVar3[6];

                    bVar60 = pbVar3[7];

                    bVar61 = pbVar3[8];

                    bVar62 = pbVar3[9];

                    bVar63 = pbVar3[10];

                    bVar64 = pbVar3[0xb];

                    bVar65 = pbVar3[0xc];

                    bVar66 = pbVar3[0xd];

                    bVar67 = pbVar3[0xe];

                    bVar68 = pbVar3[0xf];

                    pbVar3 = pbVar1 + (longlong)(pbVar80 + (-0x50 - (longlong)pbVar89));

                    *pbVar3 = pbVar75[-0x10] + *pbVar2;

                    pbVar3[1] = bVar22 + bVar83;

                    pbVar3[2] = bVar23 + bVar72;

                    pbVar3[3] = bVar24 + bVar9;

                    pbVar3[4] = bVar25 + bVar10;

                    pbVar3[5] = bVar26 + bVar11;

                    pbVar3[6] = bVar27 + bVar12;

                    pbVar3[7] = bVar28 + bVar13;

                    pbVar3[8] = bVar29 + bVar14;

                    pbVar3[9] = bVar30 + bVar15;

                    pbVar3[10] = bVar31 + bVar16;

                    pbVar3[0xb] = bVar32 + bVar17;

                    pbVar3[0xc] = bVar33 + bVar18;

                    pbVar3[0xd] = bVar34 + bVar19;

                    pbVar3[0xe] = bVar35 + bVar20;

                    pbVar3[0xf] = bVar36 + bVar21;

                    pbVar2 = pbVar1 + (longlong)(pbVar91 + (-0x30 - (longlong)pbVar89));

                    bVar83 = *pbVar2;

                    bVar72 = pbVar2[1];

                    bVar9 = pbVar2[2];

                    bVar10 = pbVar2[3];

                    bVar11 = pbVar2[4];

                    bVar12 = pbVar2[5];

                    bVar13 = pbVar2[6];

                    bVar14 = pbVar2[7];

                    bVar15 = pbVar2[8];

                    bVar16 = pbVar2[9];

                    bVar17 = pbVar2[10];

                    bVar18 = pbVar2[0xb];

                    bVar19 = pbVar2[0xc];

                    bVar20 = pbVar2[0xd];

                    bVar21 = pbVar2[0xe];

                    bVar22 = pbVar2[0xf];

                    bVar23 = pbVar75[0x10];

                    bVar24 = pbVar75[0x11];

                    bVar25 = pbVar75[0x12];

                    bVar26 = pbVar75[0x13];

                    bVar27 = pbVar75[0x14];

                    bVar28 = pbVar75[0x15];

                    bVar29 = pbVar75[0x16];

                    bVar30 = pbVar75[0x17];

                    bVar31 = pbVar75[0x18];

                    bVar32 = pbVar75[0x19];

                    bVar33 = pbVar75[0x1a];

                    bVar34 = pbVar75[0x1b];

                    bVar35 = pbVar75[0x1c];

                    bVar36 = pbVar75[0x1d];

                    bVar69 = pbVar75[0x1e];

                    bVar70 = pbVar75[0x1f];

                    pbVar2 = pbVar1 + (longlong)(pbVar80 + (-0x40 - (longlong)pbVar89));

                    *pbVar2 = bVar37 + bVar53;

                    pbVar2[1] = bVar38 + bVar54;

                    pbVar2[2] = bVar39 + bVar55;

                    pbVar2[3] = bVar40 + bVar56;

                    pbVar2[4] = bVar41 + bVar57;

                    pbVar2[5] = bVar42 + bVar58;

                    pbVar2[6] = bVar43 + bVar59;

                    pbVar2[7] = bVar44 + bVar60;

                    pbVar2[8] = bVar45 + bVar61;

                    pbVar2[9] = bVar46 + bVar62;

                    pbVar2[10] = bVar47 + bVar63;

                    pbVar2[0xb] = bVar48 + bVar64;

                    pbVar2[0xc] = bVar49 + bVar65;

                    pbVar2[0xd] = bVar50 + bVar66;

                    pbVar2[0xe] = bVar51 + bVar67;

                    pbVar2[0xf] = bVar52 + bVar68;

                    auVar6 = *(undefined1 (*) [16])

                              (pbVar1 + (longlong)(pbVar91 + (-0x20 - (longlong)pbVar89)));

                    bVar37 = pbVar75[0x20];

                    bVar38 = pbVar75[0x21];

                    bVar39 = pbVar75[0x22];

                    bVar40 = pbVar75[0x23];

                    bVar41 = pbVar75[0x24];

                    bVar42 = pbVar75[0x25];

                    bVar43 = pbVar75[0x26];

                    bVar44 = pbVar75[0x27];

                    bVar45 = pbVar75[0x28];

                    bVar46 = pbVar75[0x29];

                    bVar47 = pbVar75[0x2a];

                    bVar48 = pbVar75[0x2b];

                    bVar49 = pbVar75[0x2c];

                    bVar50 = pbVar75[0x2d];

                    bVar51 = pbVar75[0x2e];

                    bVar52 = pbVar75[0x2f];

                    pbVar75 = pbVar1 + (longlong)(pbVar80 + (-0x30 - (longlong)pbVar89));

                    *pbVar75 = bVar23 + bVar83;

                    pbVar75[1] = bVar24 + bVar72;

                    pbVar75[2] = bVar25 + bVar9;

                    pbVar75[3] = bVar26 + bVar10;

                    pbVar75[4] = bVar27 + bVar11;

                    pbVar75[5] = bVar28 + bVar12;

                    pbVar75[6] = bVar29 + bVar13;

                    pbVar75[7] = bVar30 + bVar14;

                    pbVar75[8] = bVar31 + bVar15;

                    pbVar75[9] = bVar32 + bVar16;

                    pbVar75[10] = bVar33 + bVar17;

                    pbVar75[0xb] = bVar34 + bVar18;

                    pbVar75[0xc] = bVar35 + bVar19;

                    pbVar75[0xd] = bVar36 + bVar20;

                    pbVar75[0xe] = bVar69 + bVar21;

                    pbVar75[0xf] = bVar70 + bVar22;

                    pbVar75 = pbVar1 + (longlong)(pbVar80 + (-0x20 - (longlong)pbVar89));

                    *pbVar75 = bVar37 + auVar6[0];

                    pbVar75[1] = bVar38 + auVar6[1];

                    pbVar75[2] = bVar39 + auVar6[2];

                    pbVar75[3] = bVar40 + auVar6[3];

                    pbVar75[4] = bVar41 + auVar6[4];

                    pbVar75[5] = bVar42 + auVar6[5];

                    pbVar75[6] = bVar43 + auVar6[6];

                    pbVar75[7] = bVar44 + auVar6[7];

                    pbVar75[8] = bVar45 + auVar6[8];

                    pbVar75[9] = bVar46 + auVar6[9];

                    pbVar75[10] = bVar47 + auVar6[10];

                    pbVar75[0xb] = bVar48 + auVar6[0xb];

                    pbVar75[0xc] = bVar49 + auVar6[0xc];

                    pbVar75[0xd] = bVar50 + auVar6[0xd];

                    pbVar75[0xe] = bVar51 + auVar6[0xe];

                    pbVar75[0xf] = bVar52 + auVar6[0xf];

                    pbVar75 = pbVar1;

                  } while (lVar79 < (int)(uVar85 - uVar87));

                  if (((byte)uVar85 & 0x3f) < 8) goto LAB_14019e4e6;

                }

                uVar87 = uVar85 & 0x80000007;

                if ((int)uVar87 < 0) {

                  uVar87 = (uVar87 - 1 | 0xfffffff8) + 1;

                }

                pbVar75 = pbVar89 + lVar79;

                do {

                  uVar4 = *(undefined8 *)(pbVar75 + ((longlong)pbVar91 - (longlong)pbVar89));

                  lVar79 = lVar79 + 8;

                  uVar5 = *(undefined8 *)pbVar75;

                  pbVar75 = pbVar75 + 8;

                  *(ulonglong *)(pbVar75 + (longlong)(pbVar80 + (-8 - (longlong)pbVar89))) =

                       CONCAT17((char)((ulonglong)uVar4 >> 0x38) + (char)((ulonglong)uVar5 >> 0x38),

                                CONCAT16((char)((ulonglong)uVar4 >> 0x30) +

                                         (char)((ulonglong)uVar5 >> 0x30),

                                         CONCAT15((char)((ulonglong)uVar4 >> 0x28) +

                                                  (char)((ulonglong)uVar5 >> 0x28),

                                                  CONCAT14((char)((ulonglong)uVar4 >> 0x20) +

                                                           (char)((ulonglong)uVar5 >> 0x20),

                                                           CONCAT13((char)((ulonglong)uVar4 >> 0x18)

                                                                    + (char)((ulonglong)uVar5 >>

                                                                            0x18),

                                                                    CONCAT12((char)((ulonglong)uVar4

                                                                                   >> 0x10) +

                                                                             (char)((ulonglong)uVar5

                                                                                   >> 0x10),

                                                                             CONCAT11((char)((

                                                  ulonglong)uVar4 >> 8) +

                                                  (char)((ulonglong)uVar5 >> 8),

                                                  (char)uVar4 + (char)uVar5)))))));

                } while (lVar79 < (int)(uVar85 - uVar87));

              }

            }

LAB_14019e4e6:

            if (lVar79 < lVar82) {

              pbVar75 = pbVar89 + lVar79;

              lVar82 = lVar82 - lVar79;

              do {

                pbVar75[(longlong)pbVar80 - (longlong)pbVar89] =

                     pbVar75[(longlong)pbVar91 - (longlong)pbVar89] + *pbVar75;

                pbVar75 = pbVar75 + 1;

                lVar82 = lVar82 + -1;

              } while (lVar82 != 0);

            }

            break;

          case 3:

            if (0 < lVar88) {

              pbVar75 = pbVar89;

              lVar78 = lVar88;

              do {

                (pbVar75 + 1)[(longlong)(pbVar80 + (-1 - (longlong)pbVar89))] =

                     (pbVar75[(longlong)pbVar91 - (longlong)pbVar89] >> 1) + *pbVar75;

                lVar78 = lVar78 + -1;

                pbVar75 = pbVar75 + 1;

              } while (lVar78 != 0);

            }

            if (lVar88 < lVar82) {

              pbVar75 = pbVar91 + lVar88;

              lVar82 = lVar82 - lVar88;

              do {

                pbVar1 = pbVar75 + (longlong)(pbVar80 + (-(longlong)pbVar91 - lVar88));

                bVar83 = *pbVar75;

                pbVar75 = pbVar75 + 1;

                pbVar75[(longlong)(pbVar80 + (-1 - (longlong)pbVar91))] =

                     (char)((uint)*pbVar1 + (uint)bVar83 >> 1) +

                     pbVar75[(longlong)(pbVar89 + (-1 - (longlong)pbVar91))];

                lVar82 = lVar82 + -1;

              } while (lVar82 != 0);

            }

            break;

          case 4:

            lVar79 = lVar78;

            if ((0 < (int)local_5c) && (7 < local_5c)) {

              iVar77 = local_5c - 1;

              lVar79 = 0;

              if (((pbVar89 + iVar77 < pbVar80) || (pbVar80 + iVar77 < pbVar89)) &&

                 ((pbVar91 + iVar77 < pbVar80 || (pbVar80 + iVar77 < pbVar91)))) {

                lVar79 = lVar78;

                if (0x3f < local_5c) {

                  uVar87 = local_5c & 0x8000003f;

                  if ((int)uVar87 < 0) {

                    uVar87 = (uVar87 - 1 | 0xffffffc0) + 1;

                  }

                  lVar76 = (longlong)pbVar91 - (longlong)pbVar89;

                  pbVar75 = param_2 + 0x11;

                  do {

                    pbVar2 = pbVar75 + lVar76 + -0x10;

                    bVar83 = pbVar2[1];

                    bVar72 = pbVar2[2];

                    bVar9 = pbVar2[3];

                    bVar10 = pbVar2[4];

                    bVar11 = pbVar2[5];

                    bVar12 = pbVar2[6];

                    bVar13 = pbVar2[7];

                    bVar14 = pbVar2[8];

                    bVar15 = pbVar2[9];

                    bVar16 = pbVar2[10];

                    bVar17 = pbVar2[0xb];

                    bVar18 = pbVar2[0xc];

                    bVar19 = pbVar2[0xd];

                    bVar20 = pbVar2[0xe];

                    bVar21 = pbVar2[0xf];

                    lVar79 = lVar79 + 0x40;

                    bVar22 = pbVar75[-0xf];

                    bVar23 = pbVar75[-0xe];

                    bVar24 = pbVar75[-0xd];

                    bVar25 = pbVar75[-0xc];

                    bVar26 = pbVar75[-0xb];

                    bVar27 = pbVar75[-10];

                    bVar28 = pbVar75[-9];

                    bVar29 = pbVar75[-8];

                    bVar30 = pbVar75[-7];

                    bVar31 = pbVar75[-6];

                    bVar32 = pbVar75[-5];

                    bVar33 = pbVar75[-4];

                    bVar34 = pbVar75[-3];

                    bVar35 = pbVar75[-2];

                    bVar36 = pbVar75[-1];

                    pbVar1 = pbVar75 + lVar76;

                    bVar37 = *pbVar1;

                    bVar38 = pbVar1[1];

                    bVar39 = pbVar1[2];

                    bVar40 = pbVar1[3];

                    bVar41 = pbVar1[4];

                    bVar42 = pbVar1[5];

                    bVar43 = pbVar1[6];

                    bVar44 = pbVar1[7];

                    bVar45 = pbVar1[8];

                    bVar46 = pbVar1[9];

                    bVar47 = pbVar1[10];

                    bVar48 = pbVar1[0xb];

                    bVar49 = pbVar1[0xc];

                    bVar50 = pbVar1[0xd];

                    bVar51 = pbVar1[0xe];

                    bVar52 = pbVar1[0xf];

                    pbVar1 = pbVar75 + 0x40;

                    bVar53 = *pbVar75;

                    bVar54 = pbVar75[1];

                    bVar55 = pbVar75[2];

                    bVar56 = pbVar75[3];

                    bVar57 = pbVar75[4];

                    bVar58 = pbVar75[5];

                    bVar59 = pbVar75[6];

                    bVar60 = pbVar75[7];

                    bVar61 = pbVar75[8];

                    bVar62 = pbVar75[9];

                    bVar63 = pbVar75[10];

                    bVar64 = pbVar75[0xb];

                    bVar65 = pbVar75[0xc];

                    bVar66 = pbVar75[0xd];

                    bVar67 = pbVar75[0xe];

                    bVar68 = pbVar75[0xf];

                    pbVar3 = pbVar1 + (longlong)(pbVar80 + (-0x50 - (longlong)pbVar89));

                    *pbVar3 = pbVar75[-0x10] + *pbVar2;

                    pbVar3[1] = bVar22 + bVar83;

                    pbVar3[2] = bVar23 + bVar72;

                    pbVar3[3] = bVar24 + bVar9;

                    pbVar3[4] = bVar25 + bVar10;

                    pbVar3[5] = bVar26 + bVar11;

                    pbVar3[6] = bVar27 + bVar12;

                    pbVar3[7] = bVar28 + bVar13;

                    pbVar3[8] = bVar29 + bVar14;

                    pbVar3[9] = bVar30 + bVar15;

                    pbVar3[10] = bVar31 + bVar16;

                    pbVar3[0xb] = bVar32 + bVar17;

                    pbVar3[0xc] = bVar33 + bVar18;

                    pbVar3[0xd] = bVar34 + bVar19;

                    pbVar3[0xe] = bVar35 + bVar20;

                    pbVar3[0xf] = bVar36 + bVar21;

                    pbVar2 = pbVar1 + lVar76 + -0x30;

                    bVar83 = *pbVar2;

                    bVar72 = pbVar2[1];

                    bVar9 = pbVar2[2];

                    bVar10 = pbVar2[3];

                    bVar11 = pbVar2[4];

                    bVar12 = pbVar2[5];

                    bVar13 = pbVar2[6];

                    bVar14 = pbVar2[7];

                    bVar15 = pbVar2[8];

                    bVar16 = pbVar2[9];

                    bVar17 = pbVar2[10];

                    bVar18 = pbVar2[0xb];

                    bVar19 = pbVar2[0xc];

                    bVar20 = pbVar2[0xd];

                    bVar21 = pbVar2[0xe];

                    bVar22 = pbVar2[0xf];

                    bVar23 = pbVar75[0x10];

                    bVar24 = pbVar75[0x11];

                    bVar25 = pbVar75[0x12];

                    bVar26 = pbVar75[0x13];

                    bVar27 = pbVar75[0x14];

                    bVar28 = pbVar75[0x15];

                    bVar29 = pbVar75[0x16];

                    bVar30 = pbVar75[0x17];

                    bVar31 = pbVar75[0x18];

                    bVar32 = pbVar75[0x19];

                    bVar33 = pbVar75[0x1a];

                    bVar34 = pbVar75[0x1b];

                    bVar35 = pbVar75[0x1c];

                    bVar36 = pbVar75[0x1d];

                    bVar69 = pbVar75[0x1e];

                    bVar70 = pbVar75[0x1f];

                    pbVar2 = pbVar1 + (longlong)(pbVar80 + (-0x40 - (longlong)pbVar89));

                    *pbVar2 = bVar37 + bVar53;

                    pbVar2[1] = bVar38 + bVar54;

                    pbVar2[2] = bVar39 + bVar55;

                    pbVar2[3] = bVar40 + bVar56;

                    pbVar2[4] = bVar41 + bVar57;

                    pbVar2[5] = bVar42 + bVar58;

                    pbVar2[6] = bVar43 + bVar59;

                    pbVar2[7] = bVar44 + bVar60;

                    pbVar2[8] = bVar45 + bVar61;

                    pbVar2[9] = bVar46 + bVar62;

                    pbVar2[10] = bVar47 + bVar63;

                    pbVar2[0xb] = bVar48 + bVar64;

                    pbVar2[0xc] = bVar49 + bVar65;

                    pbVar2[0xd] = bVar50 + bVar66;

                    pbVar2[0xe] = bVar51 + bVar67;

                    pbVar2[0xf] = bVar52 + bVar68;

                    auVar6 = *(undefined1 (*) [16])(pbVar1 + lVar76 + -0x20);

                    bVar37 = pbVar75[0x20];

                    bVar38 = pbVar75[0x21];

                    bVar39 = pbVar75[0x22];

                    bVar40 = pbVar75[0x23];

                    bVar41 = pbVar75[0x24];

                    bVar42 = pbVar75[0x25];

                    bVar43 = pbVar75[0x26];

                    bVar44 = pbVar75[0x27];

                    bVar45 = pbVar75[0x28];

                    bVar46 = pbVar75[0x29];

                    bVar47 = pbVar75[0x2a];

                    bVar48 = pbVar75[0x2b];

                    bVar49 = pbVar75[0x2c];

                    bVar50 = pbVar75[0x2d];

                    bVar51 = pbVar75[0x2e];

                    bVar52 = pbVar75[0x2f];

                    pbVar75 = pbVar1 + (longlong)(pbVar80 + (-0x30 - (longlong)pbVar89));

                    *pbVar75 = bVar23 + bVar83;

                    pbVar75[1] = bVar24 + bVar72;

                    pbVar75[2] = bVar25 + bVar9;

                    pbVar75[3] = bVar26 + bVar10;

                    pbVar75[4] = bVar27 + bVar11;

                    pbVar75[5] = bVar28 + bVar12;

                    pbVar75[6] = bVar29 + bVar13;

                    pbVar75[7] = bVar30 + bVar14;

                    pbVar75[8] = bVar31 + bVar15;

                    pbVar75[9] = bVar32 + bVar16;

                    pbVar75[10] = bVar33 + bVar17;

                    pbVar75[0xb] = bVar34 + bVar18;

                    pbVar75[0xc] = bVar35 + bVar19;

                    pbVar75[0xd] = bVar36 + bVar20;

                    pbVar75[0xe] = bVar69 + bVar21;

                    pbVar75[0xf] = bVar70 + bVar22;

                    pbVar75 = pbVar1 + (longlong)(pbVar80 + (-0x20 - (longlong)pbVar89));

                    *pbVar75 = bVar37 + auVar6[0];

                    pbVar75[1] = bVar38 + auVar6[1];

                    pbVar75[2] = bVar39 + auVar6[2];

                    pbVar75[3] = bVar40 + auVar6[3];

                    pbVar75[4] = bVar41 + auVar6[4];

                    pbVar75[5] = bVar42 + auVar6[5];

                    pbVar75[6] = bVar43 + auVar6[6];

                    pbVar75[7] = bVar44 + auVar6[7];

                    pbVar75[8] = bVar45 + auVar6[8];

                    pbVar75[9] = bVar46 + auVar6[9];

                    pbVar75[10] = bVar47 + auVar6[10];

                    pbVar75[0xb] = bVar48 + auVar6[0xb];

                    pbVar75[0xc] = bVar49 + auVar6[0xc];

                    pbVar75[0xd] = bVar50 + auVar6[0xd];

                    pbVar75[0xe] = bVar51 + auVar6[0xe];

                    pbVar75[0xf] = bVar52 + auVar6[0xf];

                    pbVar75 = pbVar1;

                  } while (lVar79 < (int)(local_5c - uVar87));

                  if (((byte)local_5c & 0x3f) < 8) goto LAB_14019e6e1;

                }

                uVar87 = local_5c & 0x80000007;

                if ((int)uVar87 < 0) {

                  uVar87 = (uVar87 - 1 | 0xfffffff8) + 1;

                }

                pbVar75 = pbVar89 + lVar79;

                do {

                  uVar4 = *(undefined8 *)(pbVar75 + ((longlong)pbVar91 - (longlong)pbVar89));

                  lVar79 = lVar79 + 8;

                  uVar5 = *(undefined8 *)pbVar75;

                  pbVar75 = pbVar75 + 8;

                  *(ulonglong *)(pbVar75 + (longlong)(pbVar80 + (-8 - (longlong)pbVar89))) =

                       CONCAT17((char)((ulonglong)uVar4 >> 0x38) + (char)((ulonglong)uVar5 >> 0x38),

                                CONCAT16((char)((ulonglong)uVar4 >> 0x30) +

                                         (char)((ulonglong)uVar5 >> 0x30),

                                         CONCAT15((char)((ulonglong)uVar4 >> 0x28) +

                                                  (char)((ulonglong)uVar5 >> 0x28),

                                                  CONCAT14((char)((ulonglong)uVar4 >> 0x20) +

                                                           (char)((ulonglong)uVar5 >> 0x20),

                                                           CONCAT13((char)((ulonglong)uVar4 >> 0x18)

                                                                    + (char)((ulonglong)uVar5 >>

                                                                            0x18),

                                                                    CONCAT12((char)((ulonglong)uVar4

                                                                                   >> 0x10) +

                                                                             (char)((ulonglong)uVar5

                                                                                   >> 0x10),

                                                                             CONCAT11((char)((

                                                  ulonglong)uVar4 >> 8) +

                                                  (char)((ulonglong)uVar5 >> 8),

                                                  (char)uVar4 + (char)uVar5)))))));

                } while (lVar79 < (int)(local_5c - uVar87));

              }

            }

LAB_14019e6e1:

            if (lVar79 < lVar88) {

              pbVar75 = pbVar89 + lVar79;

              lVar79 = lVar88 - lVar79;

              do {

                pbVar75[(longlong)pbVar80 - (longlong)pbVar89] =

                     pbVar75[(longlong)pbVar91 - (longlong)pbVar89] + *pbVar75;

                pbVar75 = pbVar75 + 1;

                lVar79 = lVar79 + -1;

              } while (lVar79 != 0);

            }

            if (lVar88 < lVar82) {

              lVar82 = lVar82 - lVar88;

              pbVar75 = pbVar80;

              do {

                cVar71 = FUN_1401a1c70(*pbVar75,pbVar75[(longlong)

                                                        (pbVar91 + (lVar88 - (longlong)pbVar80))]);

                pbVar75[lVar88] =

                     cVar71 + (pbVar89 + (lVar88 - (longlong)pbVar80))[(longlong)pbVar75];

                pbVar75 = pbVar75 + 1;

                lVar82 = lVar82 + -1;

              } while (lVar82 != 0);

            }

            break;

          case 5:

            FUN_1402f8e20(pbVar80,pbVar89);

            if (lVar88 < lVar82) {

              lVar82 = lVar82 - lVar88;

              pbVar91 = pbVar89 + lVar88;

              do {

                (pbVar91 + 1)[(longlong)(pbVar80 + (-1 - (longlong)pbVar89))] =

                     (pbVar91[(longlong)(pbVar80 + (-(longlong)pbVar89 - lVar88))] >> 1) + *pbVar91;

                lVar82 = lVar82 + -1;

                pbVar91 = pbVar91 + 1;

              } while (lVar82 != 0);

            }

          }

          uVar87 = 0;

          param_2 = pbVar89 + (int)uVar85;

          if (param_7 < 8) {

            if (param_8 == 0) {

              cVar71 = (&DAT_14033b610)[param_7];

            }

            else {

              cVar71 = '\x01';

            }

            bVar83 = 0;

            if (param_7 == 4) {

              pbVar89 = pbVar81;

              if (uVar92 != 0) {

                do {

                  uVar86 = uVar87 & 1;

                  if (uVar86 == 0) {

                    bVar83 = *pbVar80;

                  }

                  bVar72 = bVar83 >> 4;

                  uVar87 = uVar87 + 1;

                  bVar83 = bVar83 << 4;

                  *pbVar89 = bVar72 * cVar71;

                  pbVar89 = pbVar89 + 1;

                  pbVar91 = pbVar80 + 1;

                  if (uVar86 != 0) {

                    pbVar91 = pbVar80;

                  }

                  pbVar80 = pbVar91;

                } while (uVar87 < uVar92);

              }

            }

            else if (param_7 == 2) {

              pbVar89 = pbVar81;

              if (uVar92 != 0) {

                do {

                  uVar86 = uVar87 & 3;

                  if (uVar86 == 0) {

                    bVar83 = *pbVar80;

                  }

                  bVar72 = bVar83 >> 6;

                  uVar87 = uVar87 + 1;

                  bVar83 = bVar83 << 2;

                  *pbVar89 = bVar72 * cVar71;

                  pbVar89 = pbVar89 + 1;

                  pbVar91 = pbVar80 + 1;

                  if (uVar86 != 0) {

                    pbVar91 = pbVar80;

                  }

                  pbVar80 = pbVar91;

                } while (uVar87 < uVar92);

              }

            }

            else {

              pbVar89 = pbVar81;

              if (uVar92 != 0) {

                do {

                  uVar86 = uVar87 & 7;

                  if (uVar86 == 0) {

                    bVar83 = *pbVar80;

                  }

                  cVar8 = (char)bVar83 >> 7;

                  bVar83 = bVar83 * '\x02';

                  uVar87 = uVar87 + 1;

                  *pbVar89 = -cVar8 * cVar71;

                  pbVar91 = pbVar80 + 1;

                  if (uVar86 != 0) {

                    pbVar91 = pbVar80;

                  }

                  pbVar80 = pbVar91;

                  pbVar89 = pbVar89 + 1;

                } while (uVar87 < uVar92);

              }

            }

            pbVar80 = pbVar81;

            if (iVar7 != param_4) {

LAB_14019e8fc:

              FUN_14019dc90(pbVar81,pbVar80,param_5);

            }

          }

          else if (param_7 == 8) {

            if (iVar7 != param_4) goto LAB_14019e8fc;

            FUN_1402f8e20(pbVar81,pbVar80,uVar92);

          }

          else if (param_7 == 0x10) {

            if (iVar7 == param_4) {

              if (uVar92 != 0) {

                uVar74 = (ulonglong)uVar92;

                pbVar89 = pbVar80 + (longlong)

                                    (pbVar81 + (-lVar73 - (ulonglong)((local_74 & 1) * uVar90)));

                do {

                  bVar83 = *pbVar80;

                  pbVar80 = pbVar80 + 2;

                  *(ushort *)pbVar89 =

                       CONCAT11(bVar83,pbVar89[((ulonglong)((local_74 & 1) * uVar90) -

                                               (longlong)pbVar81) + lVar73 + 1]);

                  uVar74 = uVar74 - 1;

                  pbVar89 = pbVar89 + 2;

                } while (uVar74 != 0);

              }

            }

            else if (iVar7 == 1) {

              if (param_5 != 0) {

                uVar74 = (ulonglong)param_5;

                do {

                  bVar83 = *pbVar80;

                  bVar72 = pbVar80[1];

                  pbVar80 = pbVar80 + 2;

                  pbVar81[2] = 0xff;

                  pbVar81[3] = 0xff;

                  *(ushort *)pbVar81 = CONCAT11(bVar83,bVar72);

                  uVar74 = uVar74 - 1;

                  pbVar81 = pbVar81 + 4;

                } while (uVar74 != 0);

              }

            }

            else if (param_5 != 0) {

              uVar74 = (ulonglong)param_5;

              pbVar81 = pbVar81 + 4;

              do {

                *(ushort *)(pbVar81 + -4) = CONCAT11(*pbVar80,pbVar80[1]);

                *(ushort *)(pbVar81 + -2) = CONCAT11(pbVar80[2],pbVar80[3]);

                bVar83 = pbVar80[4];

                bVar72 = pbVar80[5];

                pbVar81[2] = 0xff;

                pbVar81[3] = 0xff;

                *(ushort *)pbVar81 = CONCAT11(bVar83,bVar72);

                uVar74 = uVar74 - 1;

                pbVar81 = pbVar81 + 8;

                pbVar80 = pbVar80 + 6;

              } while (uVar74 != 0);

            }

          }

          local_74 = local_74 + 1;

        } while (local_74 < param_6);

        FUN_1401841e0(lVar73);

        uVar74 = 1;

      }

    }

  }

  return uVar74;

}




