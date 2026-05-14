// Address: 0x14003c8c0
// Ghidra name: FUN_14003c8c0
// ============ 0x14003c8c0 FUN_14003c8c0 (size=4039) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14003c8c0(longlong param_1)



{

  ushort *puVar1;

  longlong *plVar2;

  float fVar3;

  float *pfVar4;

  undefined8 *puVar5;

  double dVar6;

  undefined4 uVar7;

  double dVar8;

  double dVar9;

  undefined4 uVar10;

  char cVar11;

  undefined8 uVar12;

  longlong lVar13;

  ulonglong uVar14;

  longlong lVar15;

  longlong lVar16;

  ulonglong uVar17;

  ulonglong *puVar18;

  uint uVar19;

  int iVar20;

  float fVar21;

  undefined4 uVar22;

  float fVar23;

  float fVar24;

  double dVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  undefined8 local_res8;

  float local_res10;

  float fStackX_14;

  undefined8 local_res18;

  undefined1 local_res20 [8];

  undefined8 in_stack_fffffffffffffee8;

  uint uVar31;

  ulonglong uVar29;

  undefined4 uVar32;

  undefined8 uVar30;

  undefined4 uVar33;

  undefined4 uVar34;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  

  uVar31 = (uint)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);

  *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x254);

  uVar19 = DAT_140304c68;

  uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),(ulonglong)DAT_140304c68 << 0x20,1);

  *(undefined8 *)(param_1 + 0x298) = uVar12;

  fVar21 = DAT_14039ca44;

  fVar3 = DAT_14039ca34;

  uVar10 = DAT_140304c8c;

  uVar29 = (ulonglong)uVar31 << 0x20;

  uVar12 = FUN_140083480(uVar12,DAT_140304c8c,CONCAT44(DAT_14039ca34,DAT_140303ff0),0,uVar29,

                         DAT_14039ca44,0);

  *(undefined8 *)(param_1 + 0x2c8) = uVar12;

  uVar33 = DAT_140304c5c;

  uVar7 = DAT_140304c00;

  uVar34 = DAT_14030374c;

  uVar22 = DAT_14030335c;

  iVar20 = *(int *)(param_1 + 0x254);

  uVar32 = (undefined4)(uVar29 >> 0x20);

  if (iVar20 == 0) {

    uVar30 = CONCAT44(uVar32,fVar21);

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),CONCAT44(DAT_140304c98,DAT_140303390),

                           CONCAT44(DAT_14030335c,DAT_140303394),0,uVar30,fVar21,0);

    uVar33 = (undefined4)((ulonglong)uVar30 >> 0x20);

    *(undefined8 *)(param_1 + 0x2d0) = uVar12;

    local_res8._0_4_ = (float)FUN_1400c6940();

    local_res8._0_4_ = (float)local_res8 + DAT_140303390;

    uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),CONCAT44(uVar19,(float)local_res8),0);

    *(undefined8 *)(param_1 + 0x2a0) = uVar12;

    uVar19 = DAT_140304c54;

    uVar7 = DAT_14030374c;

    uVar34 = DAT_140303380;

    fVar26 = DAT_140303358;

    uVar30 = CONCAT44(uVar33,DAT_14030374c);

    FUN_140083480(uVar12,(ulonglong)DAT_140304c54 << 0x20,CONCAT44(DAT_140303358,DAT_140303380),0,

                  uVar30,fVar21,uVar22);

    uVar10 = DAT_14039ca24;

    uVar33 = DAT_140304c64;

    uVar12 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),uVar7);

    FUN_140083800(*(undefined8 *)(param_1 + 0x2a0),CONCAT44(DAT_140304c64,DAT_140304c58),

                  CONCAT44(DAT_140304c64,uVar19),CONCAT44(uVar19,fVar26),uVar12,DAT_14039ca24,uVar22

                 );

    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),uVar7);

    FUN_140083800(*(undefined8 *)(param_1 + 0x2a0),CONCAT44(uVar33,DAT_140304c58),

                  CONCAT44(uVar19,fVar26),(ulonglong)uVar19 << 0x20,uVar12,uVar10,uVar22);

    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),uVar7);

    FUN_140083800(*(undefined8 *)(param_1 + 0x2a0),CONCAT44(uVar33,DAT_140304b58),

                  CONCAT44(uVar33,DAT_140303384),CONCAT44(uVar19,uVar34),uVar12,uVar10,uVar22);

    uVar29 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),uVar7);

    FUN_140083800(*(undefined8 *)(param_1 + 0x2a0),CONCAT44(uVar33,DAT_140304b58),

                  CONCAT44(uVar19,uVar34),CONCAT44(uVar19,DAT_140304b48),uVar29,uVar10,uVar22);

    FUN_140084570(*(undefined8 *)(param_1 + 0x2a0),1,0x10,0xff);

    uVar29 = uVar29 & 0xffffffff00000000;

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x2a0),(ulonglong)DAT_140304c60 << 0x20,

                           CONCAT44(fVar3,uVar34),0,uVar29,0,0);

    *(undefined8 *)(param_1 + 0x2d8) = uVar12;

    FUN_1400083a0(uVar12,1);

    FUN_1400845c0(*(undefined8 *)(param_1 + 0x2d8),1,0x10,2);

    dVar9 = DAT_140304c70;

    dVar8 = DAT_140304b78;

    dVar25 = DAT_140304b50;

    uVar22 = DAT_140304b28;

    fVar21 = DAT_140303354;

    uVar19 = 0;

    fVar26 = (float)local_res8 + fVar26 + DAT_140303354;

    local_res8 = CONCAT44(local_res8._4_4_,fVar26);

    do {

      dVar6 = (double)((float)(int)uVar19 * fVar21);

      fStackX_14 = (float)(dVar9 - (dVar6 + dVar6) * dVar8);

      iVar20 = 0;

      do {

        local_res10 = (float)((double)iVar20 * dVar25 +

                             (double)((float)(uVar19 & 1) * fVar21 + fVar26));

        uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),CONCAT44(fStackX_14,local_res10),0);

        uVar29 = uVar29 & 0xffffffff00000000;

        local_res18 = uVar12;

        FUN_140083770(uVar12,DAT_1403ffbe8,uVar22,fVar3,uVar29,0);

        FUN_140084570(uVar12,1,0x20,0xff);

        if (*(undefined8 **)(param_1 + 0x2b8) == *(undefined8 **)(param_1 + 0x2c0)) {

          FUN_140030680(param_1 + 0x2b0);

        }

        else {

          **(undefined8 **)(param_1 + 0x2b8) = uVar12;

          *(longlong *)(param_1 + 0x2b8) = *(longlong *)(param_1 + 0x2b8) + 8;

        }

        iVar20 = iVar20 + 1;

      } while (iVar20 < 9);

      uVar19 = uVar19 + 1;

      fVar26 = (float)local_res8;

    } while ((int)uVar19 < 0x10);

    FUN_1400b4a10(*(undefined8 *)(param_1 + 0x260),local_res20);

    *(undefined1 *)(*(longlong *)(param_1 + 0x260) + 0x1a) = 0;

    fVar3 = DAT_140303390;

    fVar21 = (float)FUN_1400c6940();

    FUN_1400b6820(*(undefined8 *)(param_1 + 0x260),fVar21 + fVar3,DAT_140304ca4);

    FUN_1400b6990(*(undefined8 *)(param_1 + 0x260),1,0);

  }

  else if (iVar20 == 1) {

    uVar30 = CONCAT44(uVar32,fVar21);

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),CONCAT44(DAT_140304c5c,DAT_140304c00),

                           CONCAT44(DAT_14039ca38,DAT_140303fbc),0,uVar30,fVar21,0);

    *(undefined8 *)(param_1 + 0x2d0) = uVar12;

    uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),fVar21);

    uVar12 = FUN_140083800(*(undefined8 *)(param_1 + 0x298),DAT_140303394,CONCAT44(uVar33,uVar7),

                           uVar7,uVar30,fVar21,0);

    *(undefined8 *)(param_1 + 0x2d8) = uVar12;

    *(undefined1 *)(*(longlong *)(param_1 + 0x260) + 0x1a) = 0;

    uVar22 = DAT_140304c78;

    FUN_1400b6820(*(undefined8 *)(param_1 + 0x260),DAT_140304be4,DAT_140304c78);

    FUN_1400b6990(*(undefined8 *)(param_1 + 0x260),1,0);

    plVar2 = (longlong *)(param_1 + 0x270);

    lVar13 = *plVar2;

    if (lVar13 == 0) {

      lVar13 = *(longlong *)(param_1 + 0x268);

      *plVar2 = lVar13;

    }

    FUN_1400b3dc0(lVar13,*(undefined8 *)(param_1 + 0x98));

    FUN_1400b6820(*plVar2,*(float *)(*(longlong *)

                                      (*(longlong *)(*(longlong *)(param_1 + 0x260) + 0x40) + 0x30)

                                    + 0xc) - fVar21,uVar22);

    FUN_1400b6990(*plVar2,1,1);

    uVar22 = (undefined4)((ulonglong)uVar30 >> 0x20);

    iVar20 = 0;

    lVar13 = *plVar2;

    lVar15 = *(longlong *)(lVar13 + 0x48) - *(longlong *)(lVar13 + 0x40);

    lVar15 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar15),8) + lVar15;

    if (lVar15 >> 7 != lVar15 >> 0x3f) {

      lVar15 = 0;

      do {

        if ((*(int *)(*(longlong *)(lVar13 + 0x40) + 100 + lVar15) == 1) &&

           (lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x40) + 0x38 + lVar15), lVar13 != 0)) {

          FUN_14000b2a0(lVar13,0);

        }

        uVar22 = (undefined4)((ulonglong)uVar30 >> 0x20);

        iVar20 = iVar20 + 1;

        lVar15 = lVar15 + 0xb8;

        lVar13 = *plVar2;

        lVar16 = *(longlong *)(lVar13 + 0x48) - *(longlong *)(lVar13 + 0x40);

        lVar16 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar16),8) + lVar16;

      } while ((ulonglong)(longlong)iVar20 < (ulonglong)((lVar16 >> 7) - (lVar16 >> 0x3f)));

    }

    FUN_14003e600(param_1 + 0x130,plVar2);

    uVar12 = FUN_140083e10(*(undefined8 *)

                            (*(longlong *)(*(longlong *)(param_1 + 0x260) + 0x40) + 0x30),

                           *(undefined8 *)(*(longlong *)(*plVar2 + 0x40) + 0x30),

                           CONCAT44(DAT_140303354,

                                    *(float *)(*(longlong *)(param_1 + 0x260) + 300) - DAT_140303354

                                   ),

                           CONCAT44(DAT_140303358,*(float *)(*plVar2 + 300) + DAT_140304b2c),

                           CONCAT44(uVar22,fVar3));

    uVar22 = FUN_14000bfd0(uVar12);

    *(undefined4 *)(param_1 + 0x224c) = uVar22;

    *(undefined8 *)(param_1 + 0x2244) = 0x40a00000;

  }

  else if (iVar20 == 2) {

    uVar30 = CONCAT44(uVar32,fVar21);

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),CONCAT44(uVar19,DAT_140304be8),

                           CONCAT44(DAT_14030374c,DAT_14030335c),0,uVar30,fVar21,0);

    *(undefined8 *)(param_1 + 0x2d0) = uVar12;

    uVar29 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),fVar21);

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),CONCAT44(uVar19,DAT_140303fcc),

                           CONCAT44(uVar34,uVar22),0,uVar29,fVar21,0);

    *(undefined8 *)(param_1 + 0x2d8) = uVar12;

    fVar3 = DAT_140303358;

    uVar29 = uVar29 & 0xffffffff00000000;

    uVar12 = FUN_140083770(*(undefined8 *)(param_1 + 0x298),CONCAT44(uVar19,DAT_140304bec),

                           DAT_140303358,fVar21,uVar29,0);

    *(undefined8 *)(param_1 + 0x2e0) = uVar12;

    uVar29 = uVar29 & 0xffffffff00000000;

    uVar12 = FUN_140083770(*(undefined8 *)(param_1 + 0x298),CONCAT44(uVar19,DAT_140304c04),fVar3,

                           fVar21,uVar29,0);

    *(undefined8 *)(param_1 + 0x2e8) = uVar12;

    uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),CONCAT44(uVar10,DAT_140303398),0);

    *(undefined8 *)(param_1 + 0x2a0) = uVar12;

    fVar24 = DAT_14039ca50;

    fVar28 = DAT_14039ca2c;

    uVar22 = DAT_14039ca24;

    fVar26 = DAT_140303750;

    local_e8 = _DAT_140304d30;

    uStack_e0 = _UNK_140304d38;

    iVar20 = 1;

    do {

      uVar34 = (undefined4)(uVar29 >> 0x20);

      fVar23 = (float)FUN_1402cdc50((float)iVar20 * fVar24 * fVar3);

      fVar23 = fVar23 * fVar28;

      local_f8 = uStack_e0;

      uStack_f0 = local_e8;

      fVar27 = (float)iVar20 * fVar26 * fVar3;

      local_e8 = CONCAT44(fVar23,fVar27);

      uStack_e0 = CONCAT44(fVar23 + fVar28,fVar27);

      uVar29 = CONCAT44(uVar34,fVar21);

      lVar13 = FUN_1400838e0(*(undefined8 *)(param_1 + 0x2a0),&local_f8,4,uVar22,uVar29,0);

      *(undefined8 *)(lVar13 + 0x40) = 0xc;

      iVar20 = iVar20 + 1;

    } while (iVar20 < 9);

    iVar20 = FUN_1400c6580(10);

    if (0 < iVar20) {

      puVar1 = (ushort *)(*(longlong *)(param_1 + 0x2a0) + 4);

      *puVar1 = *puVar1 | 8;

    }

    uVar12 = FUN_140083d40(*(undefined8 *)(param_1 + 0x298),*(undefined8 *)(param_1 + 0x2a0),

                           CONCAT44(uVar10,DAT_14039ca58),(ulonglong)(uint)fVar21 << 0x20,

                           uVar29 & 0xffffffff00000000,fVar21);

    *(undefined8 *)(param_1 + 0x2a8) = uVar12;

    FUN_140009e10(uVar12,1);

    FUN_140009e60(*(undefined8 *)(param_1 + 0x2a8),0);

    FUN_140009eb0(*(undefined8 *)(param_1 + 0x2a8),DAT_140304c38);

    FUN_140084570(*(undefined8 *)(param_1 + 0x2a0),1,0x10,2);

    fVar26 = *(float *)(*(longlong *)(param_1 + 0x260) + 0x128) - DAT_140303390;

    fVar3 = *(float *)(*(longlong *)(param_1 + 0x260) + 0x130);

    fVar21 = (float)FUN_1400c6940();

    local_res8 = CONCAT44(fVar26 - fVar3,(float)((double)fVar21 + _DAT_140304bb0));

    FUN_1400b6610(*(undefined8 *)(param_1 + 0x260),&local_res8);

    FUN_1400b6990(*(undefined8 *)(param_1 + 0x260),1,0);

    *(undefined4 *)(param_1 + 0x2238) = 0;

  }

  else if (iVar20 == 3) {

    *(undefined1 *)(*(longlong *)(param_1 + 0x260) + 0x1a) = 0;

    FUN_1400b6820(*(undefined8 *)(param_1 + 0x260),DAT_140303750,DAT_140304c78);

    FUN_1400b6990(*(undefined8 *)(param_1 + 0x260),1,0);

    plVar2 = (longlong *)(param_1 + 0x278);

    if (*plVar2 == 0) {

      *plVar2 = *(longlong *)(param_1 + 0x268);

    }

    lVar13 = *(longlong *)(param_1 + 0x260);

    lVar15 = *(longlong *)(*(longlong *)(lVar13 + 0x40) + 0x30);

    dVar25 = (double)*(float *)(lVar15 + 0x10) - DAT_140304b50;

    FUN_1400b6820(dVar25,*(float *)(lVar15 + 0xc) + *(float *)(lVar13 + 0x230) +

                         *(float *)(lVar13 + 0x22c),(float)dVar25);

    FUN_1400b3dc0(*plVar2,*(undefined8 *)(param_1 + 0x98));

    FUN_1400b6990(*plVar2,1,1);

    FUN_14003e600(param_1 + 0x130,plVar2);

    uVar17 = 0;

    lVar15 = *(longlong *)(*plVar2 + 0x40);

    lVar13 = *(longlong *)(*plVar2 + 0x48) - lVar15;

    lVar13 = lVar13 + SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar13),8);

    lVar16 = lVar13 >> 7;

    lVar13 = lVar13 >> 0x3f;

    if (lVar16 != lVar13) {

      puVar18 = (ulonglong *)(lVar15 + 0x30);

      uVar14 = uVar17;

      fVar26 = local_res8._4_4_;

      fVar28 = (float)local_res8;

      do {

        if ((int)puVar18[-5] == 10) {

          pfVar4 = *(float **)(*(longlong *)(*puVar18 + 0x70) + 0x28);

          fVar24 = (pfVar4[2] + *pfVar4) * fVar3;

          if ((uVar14 == 0) || (fVar28 < fVar24)) {

            uVar14 = *puVar18;

            fVar26 = (pfVar4[3] + pfVar4[1]) * fVar3;

            fVar28 = fVar24;

          }

        }

        uVar19 = (int)uVar17 + 1;

        uVar17 = (ulonglong)uVar19;

        puVar18 = puVar18 + 0x17;

      } while ((ulonglong)(longlong)(int)uVar19 < (ulonglong)(lVar16 - lVar13));

      if (uVar14 != 0) {

        uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),

                               CONCAT44(fVar26 + 0.0,fVar28 + fVar21),0);

        *(undefined8 *)(param_1 + 0x2a0) = uVar12;

        uVar19 = 0;

        uVar29 = uVar29 & 0xffffffff00000000;

        FUN_140083770(uVar12,DAT_1403ffbe8,fVar21,DAT_140303350,uVar29,0);

        FUN_140084570(*(undefined8 *)(param_1 + 0x2a0),1,2,1);

        FUN_140083c30(uVar14,*(undefined8 *)(param_1 + 0x2a0),CONCAT44(fVar26,fVar28),0,

                      uVar29 & 0xffffffff00000000,uVar19 & 0xffffff00);

      }

    }

  }

  else if (iVar20 == 5) {

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),CONCAT44(DAT_140304c88,DAT_14030339c),

                           CONCAT44(fVar21,DAT_140303398),0,CONCAT44(uVar32,fVar21),fVar21,0);

    *(undefined8 *)(param_1 + 0x2d0) = uVar12;

    uVar12 = FUN_140083480(*(undefined8 *)(param_1 + 0x298),(ulonglong)uVar19 << 0x20,

                           CONCAT44(fVar21,DAT_140303754),0,fVar21,fVar21,0);

    *(undefined8 *)(param_1 + 0x2d8) = uVar12;

    uVar29 = _UNK_140304088;

    uVar12 = _DAT_140304080;

    puVar18 = (ulonglong *)(param_1 + 0x268);

    uVar17 = 0;

    do {

      puVar5 = (undefined8 *)*puVar18;

      if (puVar5 != (undefined8 *)0x0) {

        (**(code **)*puVar5)(puVar5,1);

      }

      local_res8 = FUN_1402c704c(0x498);

      uVar14 = 0;

      if (local_res8 != 0) {

        uVar14 = FUN_1400aac60(local_res8);

      }

      *puVar18 = uVar14;

      uStack_f0 = 0;

      local_e8 = uVar12;

      uStack_e0 = uVar29;

      local_f8 = (ulonglong)CONCAT14(s_freak_140303b30[4],s_freak_140303b30._0_4_);

      FUN_1400b2ee0(uVar14,&local_f8);

      if (0xf < uStack_e0) {

        if ((0xfff < uStack_e0 + 1) && (0x1f < (local_f8 - *(longlong *)(local_f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      cVar11 = FUN_1400b4af0(*puVar18);

    } while ((cVar11 == '\0') &&

            (uVar19 = (int)uVar17 + 1, uVar17 = (ulonglong)uVar19, (int)uVar19 < 7));

    uVar29 = *puVar18;

    local_res8 = CONCAT44((*(float *)(uVar29 + 0x128) - DAT_140303394) - *(float *)(uVar29 + 0x130),

                          0x41200000);

    FUN_1400b6610(uVar29,&local_res8);

    FUN_1400b3dc0(*puVar18,*(undefined8 *)(param_1 + 0x98));

    FUN_1400b6990(*puVar18,1,1);

    FUN_14003e600(param_1 + 0x130,puVar18);

  }

  FUN_140084570(*(undefined8 *)(param_1 + 0x298),1,1,0xff);

  return;

}




