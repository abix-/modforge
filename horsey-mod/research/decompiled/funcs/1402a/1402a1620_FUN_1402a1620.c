// Address: 0x1402a1620
// Ghidra name: FUN_1402a1620
// ============ 0x1402a1620 FUN_1402a1620 (size=2340) ============


/* WARNING: Removing unreachable block (ram,0x0001402a1838) */



void FUN_1402a1620(longlong *param_1)



{

  byte bVar1;

  byte bVar2;

  undefined4 *puVar3;

  longlong lVar4;

  double dVar5;

  float fVar6;

  undefined4 uVar7;

  int iVar8;

  int iVar9;

  char *_Str1;

  ulonglong uVar10;

  uint uVar11;

  longlong lVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  undefined4 *puVar15;

  uint uVar16;

  undefined1 *puVar17;

  undefined4 uVar18;

  undefined4 uVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  undefined1 local_res8;

  float local_res20 [2];

  float *pfVar26;

  float *pfVar27;

  float *pfVar28;

  undefined4 uVar29;

  undefined4 uVar30;

  float local_1c8;

  float local_1c4;

  float local_1c0;

  float local_1bc;

  float local_1b8;

  float local_1b4;

  float local_1b0;

  uint local_1ac;

  uint local_1a8;

  int local_1a4;

  ulonglong local_1a0;

  undefined4 *local_198;

  uint local_190;

  uint local_18c;

  uint local_188;

  uint local_184;

  uint local_180;

  uint local_17c;

  int local_178;

  uint local_174;

  int local_170;

  uint local_16c;

  int local_168;

  longlong local_160;

  ulonglong local_158;

  undefined8 uStack_150;

  longlong local_148;

  longlong local_140;

  longlong local_138;

  undefined4 *local_130;

  ulonglong local_128;

  longlong local_120;

  ulonglong local_118;

  ulonglong local_110;

  ulonglong local_108;

  ulonglong local_100;

  ulonglong local_f8;

  

  puVar3 = (undefined4 *)param_1[0xb];

  lVar4 = param_1[0xc];

  local_16c = *(uint *)(param_1 + 0xf);

  local_190 = (uint)*(byte *)(param_1 + 0x10);

  local_18c = (uint)*(byte *)((longlong)param_1 + 0x81);

  local_188 = (uint)*(byte *)((longlong)param_1 + 0x82);

  local_198 = (undefined4 *)param_1[9];

  local_180 = (uint)*(byte *)((longlong)param_1 + 0x83);

  local_120 = param_1[10];

  local_138 = param_1[0xe];

  bVar1 = *(byte *)((longlong)local_198 + 5);

  bVar2 = *(byte *)((longlong)puVar3 + 5);

  local_160 = 0;

  local_1a8 = 0;

  local_res8 = 0;

  iVar9 = *(int *)(param_1[5] + 0x40);

  iVar8 = *(int *)(*param_1 + 0x40);

  uVar11 = iVar8 >> 10 & 0x1f;

  local_1a4 = iVar9;

  local_168 = iVar8;

  local_140 = lVar4;

  local_130 = puVar3;

  uVar18 = FUN_140146c10(*param_1,iVar8);

  uVar19 = FUN_140146c10(param_1[5],iVar9);

  fVar20 = (float)FUN_1401468a0(*param_1,iVar8);

  fVar21 = (float)FUN_1401468a0(param_1[5]);

  if (fVar21 == 0.0) {

    uVar7 = FUN_140146bc0(param_1[5]);

    FUN_1401752f0(uVar7,"SDL.surface.HDR_headroom",fVar20);

    fVar21 = fVar20;

  }

  fVar6 = DAT_14039ca44;

  local_148 = 0;

  local_158 = 0;

  uStack_150 = 0;

  if (fVar20 <= fVar21) {

LAB_1402a1875:

    local_1a0 = local_158 & 0xffffffff;

  }

  else {

    uVar7 = FUN_140146bc0(*param_1);

    _Str1 = (char *)FUN_140174e70(uVar7,"SDL.surface.tonemap",0);

    local_1a0 = 2;

    if (_Str1 != (char *)0x0) {

      iVar8 = strncmp(_Str1,"*=",2);

      if (iVar8 == 0) {

        local_1a0 = 1;

        local_158 = CONCAT44(local_158._4_4_,1);

        dVar5 = (double)thunk_FUN_1402de5ec(_Str1 + 2);

        uStack_150 = CONCAT44(uStack_150._4_4_,(float)dVar5);

        goto LAB_1402a187d;

      }

      iVar8 = FUN_14012ef60(_Str1,"chrome");

      if (iVar8 != 0) {

        iVar8 = FUN_14012ef60(_Str1);

        if (iVar8 != 0) {

          local_1a0 = 0;

          goto LAB_1402a187d;

        }

        goto LAB_1402a1875;

      }

    }

    local_158 = CONCAT44(local_158._4_4_,2);

    uStack_150 = CONCAT44(fVar6 / fVar21,fVar21 / (fVar20 * fVar20));

    local_148 = FUN_14017a400(uVar11);

    if (local_148 != 0) {

      uVar11 = 9;

    }

  }

LAB_1402a187d:

  if (uVar11 != (iVar9 >> 10 & 0x1fU)) {

    local_160 = FUN_14017a400(uVar11);

  }

  lVar12 = local_160;

  puVar15 = local_198;

  local_1ac = FUN_14029fe00(*local_198);

  uVar14 = (ulonglong)local_1ac;

  iVar9 = FUN_14029fe00(*puVar3);

  local_178 = iVar9;

  if (iVar9 == 0) {

    local_res8 = FUN_14017bb00(local_138,0,lVar4);

    uVar14 = (ulonglong)local_1ac;

    puVar15 = local_198;

  }

  fVar21 = DAT_14030a2d0;

  uVar13 = (ulonglong)*(int *)((longlong)param_1 + 0x3c);

  uVar10 = (ulonglong)((longlong)*(int *)((longlong)param_1 + 0x14) << 0x10) / uVar13;

  local_118 = (ulonglong)((longlong)(int)param_1[2] << 0x10) / (ulonglong)(longlong)(int)param_1[7];

  local_128 = uVar10 >> 1;

  if (*(int *)((longlong)param_1 + 0x3c) != 0) {

    local_f8 = local_118 >> 1;

    local_100 = uVar10;

    do {

      puVar17 = (undefined1 *)param_1[6];

      *(int *)((longlong)param_1 + 0x3c) = (int)uVar13 + -1;

      local_170 = (int)param_1[7];

      local_110 = local_128 >> 0x10;

      if (local_170 != 0) {

        local_108 = (ulonglong)bVar1;

        local_184 = local_16c & 2;

        uVar11 = local_16c & 1;

        uVar16 = local_16c & 0x350;

        local_17c = local_16c & 0x50;

        uVar13 = local_f8;

        local_174 = uVar11;

        do {

          local_170 = local_170 + -1;

          pfVar27 = &local_1b8;

          pfVar28 = &local_1bc;

          pfVar26 = &local_1c0;

          FUN_14029ff40((uVar13 >> 0x10) * local_108 + (longlong)(int)param_1[3] * local_110 +

                        param_1[1],uVar14 & 0xffffffff,puVar15,local_120,local_168,uVar18,pfVar26,

                        pfVar28,pfVar27,&local_1b0);

          uVar7 = (undefined4)((ulonglong)pfVar26 >> 0x20);

          uVar29 = (undefined4)((ulonglong)pfVar28 >> 0x20);

          uVar30 = (undefined4)((ulonglong)pfVar27 >> 0x20);

          if ((int)local_1a0 != 0) {

            FUN_14029fd70(&local_158,&local_1c0,&local_1bc,&local_1b8);

          }

          if (lVar12 != 0) {

            FUN_140179fa0(&local_1c0,&local_1bc,&local_1b8,lVar12);

          }

          if (uVar16 == 0) {

            local_1b4 = 0.0;

            local_1c8 = 0.0;

            local_res20[0] = 0.0;

            local_1c4 = 0.0;

          }

          else {

            pfVar28 = &local_1c4;

            pfVar26 = &local_1c8;

            pfVar27 = local_res20;

            FUN_14029ff40(puVar17,iVar9,local_130,local_140,local_1a4,uVar19,pfVar27,pfVar26,pfVar28

                          ,&local_1b4);

            uVar7 = (undefined4)((ulonglong)pfVar27 >> 0x20);

            uVar29 = (undefined4)((ulonglong)pfVar26 >> 0x20);

            uVar30 = (undefined4)((ulonglong)pfVar28 >> 0x20);

          }

          if (uVar11 != 0) {

            local_1c0 = ((float)local_190 * local_1c0) / fVar21;

            local_1bc = ((float)local_18c * local_1bc) / fVar21;

            local_1b8 = ((float)local_188 * local_1b8) / fVar21;

          }

          if (local_184 != 0) {

            local_1b0 = ((float)local_180 * local_1b0) / fVar21;

          }

          if ((local_17c != 0) && (local_1b0 < fVar6)) {

            local_1c0 = local_1c0 * local_1b0;

            local_1bc = local_1bc * local_1b0;

            local_1b8 = local_1b8 * local_1b0;

          }

          fVar20 = local_1c0;

          fVar23 = local_1bc;

          fVar25 = local_1b8;

          fVar24 = local_1b0;

          if (uVar16 != 0) {

            if (uVar16 == 0x10) {

              fVar24 = fVar6 - local_1b0;

              fVar20 = fVar24 * local_res20[0] + local_1c0;

              fVar23 = fVar24 * local_1c8 + local_1bc;

              fVar25 = fVar24 * local_1c4 + local_1b8;

              fVar24 = fVar24 * local_1b4 + local_1b0;

            }

            else {

              fVar24 = local_1b4;

              if (uVar16 == 0x40) {

                fVar20 = local_res20[0] + local_1c0;

                fVar23 = local_1c8 + local_1bc;

                fVar25 = local_1c4 + local_1b8;

              }

              else if (uVar16 == 0x100) {

                fVar20 = local_res20[0] * local_1c0;

                fVar23 = local_1c8 * local_1bc;

                fVar25 = local_1c4 * local_1b8;

              }

              else {

                fVar20 = local_res20[0];

                fVar23 = local_1c8;

                fVar25 = local_1c4;

                if (uVar16 == 0x200) {

                  fVar25 = fVar6 - local_1b0;

                  fVar20 = local_res20[0] * local_1c0 + fVar25 * local_res20[0];

                  fVar23 = local_1c8 * local_1bc + fVar25 * local_1c8;

                  fVar25 = local_1c4 * local_1b8 + fVar25 * local_1c4;

                }

              }

            }

          }

          local_1b4 = fVar24;

          local_1c4 = fVar25;

          local_1c8 = fVar23;

          local_res20[0] = fVar20;

          fVar24 = local_1b4;

          fVar25 = local_1c4;

          fVar23 = local_1c8;

          fVar20 = local_res20[0];

          if (iVar9 == 0) {

            fVar22 = (float)FUN_14017c370(local_res20[0]);

            if (0.0 <= fVar22) {

              fVar22 = (float)FUN_14017c370(fVar20);

              fVar20 = fVar6;

              if (fVar22 <= fVar6) {

                fVar20 = fVar22;

              }

            }

            else {

              fVar20 = 0.0;

            }

            fVar20 = (float)thunk_FUN_1402e1d00(fVar20 * fVar21);

            fVar22 = (float)FUN_14017c370(fVar23);

            if (0.0 <= fVar22) {

              fVar22 = (float)FUN_14017c370(fVar23);

              fVar23 = fVar6;

              if (fVar22 <= fVar6) {

                fVar23 = fVar22;

              }

            }

            else {

              fVar23 = 0.0;

            }

            fVar23 = (float)thunk_FUN_1402e1d00(fVar23 * fVar21);

            fVar22 = (float)FUN_14017c370(fVar25);

            if (0.0 <= fVar22) {

              fVar22 = (float)FUN_14017c370(fVar25);

              fVar25 = fVar6;

              if (fVar22 <= fVar6) {

                fVar25 = fVar22;

              }

            }

            else {

              fVar25 = 0.0;

            }

            fVar25 = (float)thunk_FUN_1402e1d00(fVar25 * fVar21);

            if (0.0 <= fVar24) {

              fVar22 = fVar6;

              if (fVar24 <= fVar6) {

                fVar22 = fVar24;

              }

            }

            else {

              fVar22 = 0.0;

            }

            fVar24 = (float)thunk_FUN_1402e1d00(fVar22 * fVar21);

            uVar11 = (int)fVar24 & 0xffU |

                     ((((int)fVar20 & 0xffU) << 8 | (int)fVar23 & 0xffU) << 8 | (int)fVar25 & 0xffU)

                     << 8;

            if (uVar11 == local_1a8) {

              *puVar17 = local_res8;

              lVar12 = local_160;

              uVar11 = local_174;

              iVar9 = local_178;

            }

            else {

              local_1a8 = uVar11;

              local_res8 = FUN_14017bb00(local_138,uVar11,local_140);

              *puVar17 = local_res8;

              lVar12 = local_160;

              uVar11 = local_174;

              iVar9 = local_178;

            }

          }

          else {

            FUN_1402a1fd0(puVar17,iVar9,local_130,local_1a4,uVar19,local_res20[0],

                          CONCAT44(uVar7,local_1c8),CONCAT44(uVar29,local_1c4),

                          CONCAT44(uVar30,local_1b4));

          }

          uVar13 = uVar13 + local_118;

          puVar17 = puVar17 + bVar2;

          uVar14 = (ulonglong)local_1ac;

          uVar10 = local_100;

          puVar15 = local_198;

        } while (local_170 != 0);

      }

      local_128 = local_128 + uVar10;

      param_1[6] = param_1[6] + (longlong)(int)param_1[8];

      uVar13 = (ulonglong)*(uint *)((longlong)param_1 + 0x3c);

      uVar14 = (ulonglong)local_1ac;

      puVar15 = local_198;

    } while (*(uint *)((longlong)param_1 + 0x3c) != 0);

  }

  *(undefined4 *)((longlong)param_1 + 0x3c) = 0xffffffff;

  return;

}




