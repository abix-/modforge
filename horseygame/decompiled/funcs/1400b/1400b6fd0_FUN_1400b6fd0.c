// Address: 0x1400b6fd0
// Ghidra name: FUN_1400b6fd0
// ============ 0x1400b6fd0 FUN_1400b6fd0 (size=849) ============


undefined8 FUN_1400b6fd0(longlong param_1,float param_2,float param_3,int *param_4)



{

  float fVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  int iVar8;

  int iVar9;

  undefined4 uVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float local_res8;

  float local_resc;

  float local_128;

  float local_124;

  float local_120;

  float local_11c;

  undefined **local_118;

  undefined4 local_110;

  undefined4 local_10c;

  undefined4 local_108;

  undefined4 local_104;

  undefined8 local_100;

  undefined8 uStack_f8;

  undefined8 local_f0;

  undefined8 uStack_e8;

  undefined8 local_e0;

  undefined8 uStack_d8;

  undefined8 local_d0;

  undefined8 uStack_c8;

  undefined8 local_c0;

  undefined8 uStack_b8;

  undefined8 local_b0;

  undefined8 uStack_a8;

  undefined4 local_a0;

  undefined4 uStack_9c;

  undefined4 uStack_98;

  undefined4 uStack_94;

  undefined4 local_90;

  undefined4 uStack_8c;

  undefined4 uStack_88;

  undefined4 uStack_84;

  undefined4 local_80;

  

  iVar8 = 0;

  lVar6 = *(longlong *)(param_1 + 0x40);

  lVar7 = *(longlong *)(param_1 + 0x48) - lVar6;

  lVar7 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar7),8) + lVar7;

  if (lVar7 >> 7 != lVar7 >> 0x3f) {

    lVar7 = 0;

    local_res8 = param_2;

    local_resc = param_3;

    do {

      uVar10 = FUN_1400c5f10(*(undefined4 *)(lVar7 + 0x48 + lVar6));

      fVar15 = *(float *)(lVar7 + 0x40 + lVar6);

      fVar16 = *(float *)(lVar7 + 0x44 + lVar6);

      local_128 = fVar15;

      local_124 = fVar16;

      fVar11 = (float)FUN_1402cdc50();

      local_120 = fVar11;

      fVar12 = (float)FUN_1402cfda0(uVar10);

      iVar9 = 0;

      lVar4 = *(longlong *)(lVar7 + 0x18 + lVar6);

      lVar3 = *(longlong *)(lVar7 + 0x20 + lVar6) - lVar4;

      lVar5 = lVar3 >> 0x3f;

      local_11c = fVar12;

      if (lVar3 / 0x168 + lVar5 != lVar5) {

        lVar5 = 0;

        do {

          lVar4 = lVar5 + lVar4;

          if (((*(char *)(lVar4 + 0x160) != '\0') && (*(int *)(lVar4 + 0x150) != 0xd)) &&

             (*(float *)(lVar4 + 0x154) != 0.0)) {

            fVar1 = *(float *)(lVar4 + 0x148);

            if (fVar1 <= 0.0) {

              lVar3 = lVar4 + 0xa0;

              if (*(char *)(param_1 + 0x1a) == '\0') {

                lVar3 = lVar4;

              }

              local_110 = *(undefined4 *)(lVar3 + 8);

              local_10c = *(undefined4 *)(lVar3 + 0xc);

              local_118 = b2PolygonShape::vftable;

              local_108 = *(undefined4 *)(lVar3 + 0x10);

              local_104 = *(undefined4 *)(lVar3 + 0x14);

              local_100 = *(undefined8 *)(lVar3 + 0x18);

              uStack_f8 = *(undefined8 *)(lVar3 + 0x20);

              local_f0 = *(undefined8 *)(lVar3 + 0x28);

              uStack_e8 = *(undefined8 *)(lVar3 + 0x30);

              local_e0 = *(undefined8 *)(lVar3 + 0x38);

              uStack_d8 = *(undefined8 *)(lVar3 + 0x40);

              local_d0 = *(undefined8 *)(lVar3 + 0x48);

              uStack_c8 = *(undefined8 *)(lVar3 + 0x50);

              local_c0 = *(undefined8 *)(lVar3 + 0x58);

              uStack_b8 = *(undefined8 *)(lVar3 + 0x60);

              local_b0 = *(undefined8 *)(lVar3 + 0x68);

              uStack_a8 = *(undefined8 *)(lVar3 + 0x70);

              local_a0 = *(undefined4 *)(lVar3 + 0x78);

              uStack_9c = *(undefined4 *)(lVar3 + 0x7c);

              uStack_98 = *(undefined4 *)(lVar3 + 0x80);

              uStack_94 = *(undefined4 *)(lVar3 + 0x84);

              local_90 = *(undefined4 *)(lVar3 + 0x88);

              uStack_8c = *(undefined4 *)(lVar3 + 0x8c);

              uStack_88 = *(undefined4 *)(lVar3 + 0x90);

              uStack_84 = *(undefined4 *)(lVar3 + 0x94);

              local_80 = *(undefined4 *)(lVar3 + 0x98);

              cVar2 = FUN_14000e340(&local_118,&local_128,&local_res8);

              fVar12 = local_11c;

              fVar11 = local_120;

              fVar15 = local_128;

              fVar16 = local_124;

              if (cVar2 != '\0') {

                if (param_4 != (int *)0x0) {

                  *param_4 = iVar8;

                }

                return 1;

              }

            }

            else {

              fVar14 = local_res8 -

                       ((*(float *)(lVar4 + 0x140) * fVar12 - *(float *)(lVar4 + 0x144) * fVar11) +

                       fVar15);

              fVar13 = local_resc -

                       (*(float *)(lVar4 + 0x140) * fVar11 + *(float *)(lVar4 + 0x144) * fVar12 +

                       fVar16);

              if (fVar13 * fVar13 + fVar14 * fVar14 < fVar1 * fVar1) {

                if (param_4 != (int *)0x0) {

                  *param_4 = iVar8;

                }

                return 1;

              }

            }

          }

          iVar9 = iVar9 + 1;

          lVar5 = lVar5 + 0x168;

          lVar4 = *(longlong *)(lVar7 + 0x18 + lVar6);

        } while ((ulonglong)(longlong)iVar9 <

                 (ulonglong)((*(longlong *)(lVar7 + 0x20 + lVar6) - lVar4) / 0x168));

      }

      iVar8 = iVar8 + 1;

      lVar7 = lVar7 + 0xb8;

      lVar6 = *(longlong *)(param_1 + 0x40);

      lVar4 = *(longlong *)(param_1 + 0x48) - lVar6;

      lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

    } while ((ulonglong)(longlong)iVar8 < (ulonglong)((lVar4 >> 7) - (lVar4 >> 0x3f)));

  }

  return 0;

}




