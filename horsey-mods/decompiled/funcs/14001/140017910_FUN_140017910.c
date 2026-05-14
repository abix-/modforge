// Address: 0x140017910
// Ghidra name: FUN_140017910
// ============ 0x140017910 FUN_140017910 (size=1887) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140017910(undefined8 *param_1,longlong param_2,float *param_3,float *param_4,char param_5)



{

  float fVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  longlong lVar5;

  bool bVar6;

  char cVar7;

  char cVar8;

  undefined4 *puVar9;

  longlong lVar10;

  undefined4 *puVar11;

  ulonglong uVar12;

  uint uVar13;

  ulonglong uVar14;

  int iVar15;

  ulonglong uVar16;

  ulonglong uVar17;

  longlong lVar18;

  int iVar19;

  uint uVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  undefined1 auStack_1d8 [32];

  longlong local_1b8;

  float local_1a8;

  float fStack_1a4;

  float fStack_1a0;

  float fStack_19c;

  undefined8 local_198;

  undefined8 local_190;

  undefined4 local_188;

  undefined8 local_180;

  undefined8 local_178;

  undefined8 local_170;

  float local_168;

  float fStack_164;

  float fStack_160;

  float fStack_15c;

  undefined8 local_158;

  undefined8 local_150;

  undefined8 local_148;

  undefined1 local_138 [40];

  undefined8 local_110;

  undefined8 local_108;

  longlong local_100;

  longlong local_f8;

  int local_f0;

  ulonglong local_e8;

  

  fVar21 = DAT_14039ca44;

  local_e8 = DAT_1403e8b00 ^ (ulonglong)auStack_1d8;

  fVar1 = *param_3;

  iVar19 = 0;

  if (0 < *(int *)(param_1 + 7)) {

    lVar10 = 0;

    lVar18 = 0;

    do {

      piVar4 = *(int **)(lVar18 + param_1[2]);

      iVar15 = piVar4[0xc];

      iVar2 = piVar4[0xe];

      fVar27 = (float)piVar4[0x10];

      fVar28 = (float)piVar4[0x11];

      fVar29 = (float)piVar4[0x12];

      piVar4[9] = piVar4[0xb];

      piVar4[10] = iVar15;

      piVar4[0xd] = iVar2;

      if (*piVar4 == 2) {

        fVar22 = fVar21 - fVar1 * (float)piVar4[0x28];

        if (fVar21 <= fVar22) {

          fVar22 = fVar21;

        }

        fVar25 = 0.0;

        if (0.0 <= fVar22) {

          fVar25 = fVar22;

        }

        fVar27 = (((float)piVar4[0x25] * (float)piVar4[0x13] + (float)piVar4[0x2a] * *param_4) *

                  fVar1 + fVar27) * fVar25;

        fVar28 = (((float)piVar4[0x2a] * param_4[1] + (float)piVar4[0x25] * (float)piVar4[0x14]) *

                  fVar1 + fVar28) * fVar25;

        fVar22 = fVar21 - fVar1 * (float)piVar4[0x29];

        if (fVar21 <= fVar22) {

          fVar22 = fVar21;

        }

        fVar25 = 0.0;

        if (0.0 <= fVar22) {

          fVar25 = fVar22;

        }

        fVar29 = fVar25 * (fVar1 * (float)piVar4[0x27] * (float)piVar4[0x15] + fVar29);

      }

      lVar5 = param_1[5];

      *(int *)(lVar10 + lVar5) = piVar4[0xb];

      *(int *)(lVar10 + 4 + lVar5) = iVar15;

      *(int *)(lVar10 + 8 + param_1[5]) = iVar2;

      lVar5 = param_1[6];

      *(float *)(lVar10 + lVar5) = fVar27;

      *(float *)(lVar10 + 4 + lVar5) = fVar28;

      *(float *)(lVar10 + 8 + param_1[6]) = fVar29;

      iVar19 = iVar19 + 1;

      lVar18 = lVar18 + 8;

      lVar10 = lVar10 + 0xc;

    } while (iVar19 < *(int *)(param_1 + 7));

  }

  local_1a8 = *param_3;

  fStack_1a4 = param_3[1];

  fStack_1a0 = param_3[2];

  fStack_19c = param_3[3];

  local_198 = *(undefined8 *)(param_3 + 4);

  local_180 = param_1[5];

  local_178 = param_1[6];

  local_190 = param_1[3];

  local_188 = *(undefined4 *)(param_1 + 8);

  local_170 = *param_1;

  local_1b8 = param_2;

  local_168 = local_1a8;

  fStack_164 = fStack_1a4;

  fStack_160 = fStack_1a0;

  fStack_15c = fStack_19c;

  local_158 = local_198;

  local_150 = local_180;

  local_148 = local_178;

  FUN_14001e5e0(local_138,&local_1a8);

  FUN_14001eae0(local_138);

  if (*(char *)(param_3 + 5) != '\0') {

    FUN_14001f210(local_138);

  }

  iVar19 = 0;

  if (0 < *(int *)((longlong)param_1 + 0x3c)) {

    lVar10 = 0;

    do {

      (**(code **)(**(longlong **)(lVar10 + param_1[4]) + 0x30))

                (*(longlong **)(lVar10 + param_1[4]),&local_168);

      iVar19 = iVar19 + 1;

      lVar10 = lVar10 + 8;

    } while (iVar19 < *(int *)((longlong)param_1 + 0x3c));

  }

  iVar19 = 0;

  *(undefined4 *)(param_2 + 0xc) = 0;

  if (0 < (int)param_3[3]) {

    do {

      uVar12 = 0;

      uVar16 = uVar12;

      if (0 < *(int *)((longlong)param_1 + 0x3c)) {

        do {

          (**(code **)(**(longlong **)(uVar16 + param_1[4]) + 0x38))

                    (*(longlong **)(uVar16 + param_1[4]),&local_168);

          uVar13 = (int)uVar12 + 1;

          uVar12 = (ulonglong)uVar13;

          uVar16 = uVar16 + 8;

        } while ((int)uVar13 < *(int *)((longlong)param_1 + 0x3c));

      }

      FUN_14001f7b0(local_138);

      iVar19 = iVar19 + 1;

    } while (iVar19 < (int)param_3[3]);

  }

  uVar14 = 0;

  uVar16 = uVar14;

  uVar12 = uVar14;

  if (0 < local_f0) {

    do {

      if (0 < *(int *)(uVar16 + 0x90 + local_100)) {

        puVar9 = (undefined4 *)

                 (*(longlong *)(local_f8 + (longlong)*(int *)(uVar16 + 0x94 + local_100) * 8) + 0x84

                 );

        puVar11 = (undefined4 *)(local_100 + 0x14 + uVar16);

        uVar17 = uVar14;

        do {

          puVar9[-1] = puVar11[-1];

          *puVar9 = *puVar11;

          uVar13 = (int)uVar17 + 1;

          uVar17 = (ulonglong)uVar13;

          puVar11 = puVar11 + 9;

          puVar9 = puVar9 + 5;

        } while ((int)uVar13 < *(int *)(uVar16 + 0x90 + local_100));

      }

      uVar13 = (int)uVar12 + 1;

      uVar16 = uVar16 + 0x98;

      uVar12 = (ulonglong)uVar13;

    } while ((int)uVar13 < local_f0);

  }

  *(undefined4 *)(param_2 + 0x10) = 0;

  uVar13 = _DAT_14039cab0;

  fVar28 = DAT_14039ca58;

  fVar27 = DAT_14039ca4c;

  fVar21 = DAT_14039ca48;

  uVar16 = uVar14;

  if (0 < *(int *)(param_1 + 7)) {

    do {

      lVar10 = param_1[5];

      fVar29 = *(float *)(uVar14 + 4 + lVar10);

      fVar22 = *(float *)(uVar14 + 8 + lVar10);

      lVar18 = param_1[6];

      fVar25 = *(float *)(uVar14 + lVar18);

      fVar26 = *(float *)(uVar14 + 4 + lVar18);

      fVar24 = *(float *)(uVar14 + 8 + lVar18);

      fVar23 = fVar25 * fVar1 * fVar25 * fVar1 + fVar26 * fVar1 * fVar26 * fVar1;

      if (DAT_14039ca5c < fVar23) {

        if (fVar23 < 0.0) {

          fVar23 = (float)FUN_1402cdfa0(fVar23);

        }

        else {

          fVar23 = SQRT(fVar23);

        }

        fVar25 = fVar25 * (fVar28 / fVar23);

        fVar26 = fVar26 * (fVar28 / fVar23);

      }

      fVar23 = fVar24 * fVar1;

      if (fVar27 < fVar23 * fVar23) {

        fVar24 = fVar24 * (fVar21 / (float)((uint)fVar23 & uVar13));

      }

      *(float *)(uVar14 + lVar10) = fVar25 * fVar1 + *(float *)(uVar14 + lVar10);

      *(float *)(uVar14 + 4 + lVar10) = fVar26 * fVar1 + fVar29;

      *(float *)(uVar14 + 8 + param_1[5]) = fVar24 * fVar1 + fVar22;

      lVar10 = param_1[6];

      *(float *)(uVar14 + lVar10) = fVar25;

      *(float *)(uVar14 + 4 + lVar10) = fVar26;

      *(float *)(uVar14 + 8 + param_1[6]) = fVar24;

      uVar20 = (int)uVar16 + 1;

      uVar14 = uVar14 + 0xc;

      uVar16 = (ulonglong)uVar20;

    } while ((int)uVar20 < *(int *)(param_1 + 7));

  }

  iVar19 = 0;

  bVar6 = false;

  if (0 < (int)param_3[4]) {

    do {

      iVar15 = 0;

      cVar7 = FUN_140020700(local_138);

      bVar6 = true;

      if (0 < *(int *)((longlong)param_1 + 0x3c)) {

        lVar10 = 0;

        do {

          cVar8 = (**(code **)(**(longlong **)(lVar10 + param_1[4]) + 0x40))

                            (*(longlong **)(lVar10 + param_1[4]),&local_168);

          if ((bVar6) && (cVar8 != '\0')) {

            bVar6 = true;

          }

          else {

            bVar6 = false;

          }

          iVar15 = iVar15 + 1;

          lVar10 = lVar10 + 8;

        } while (iVar15 < *(int *)((longlong)param_1 + 0x3c));

      }

      if ((cVar7 != '\0') && (bVar6)) {

        bVar6 = true;

        goto LAB_140017e21;

      }

      iVar19 = iVar19 + 1;

    } while (iVar19 < (int)param_3[4]);

    bVar6 = false;

  }

LAB_140017e21:

  uVar16 = 0;

  if (0 < *(int *)(param_1 + 7)) {

    lVar10 = 0;

    uVar12 = uVar16;

    do {

      lVar18 = *(longlong *)(lVar10 + param_1[2]);

      *(undefined8 *)(lVar18 + 0x2c) = *(undefined8 *)(uVar16 + param_1[5]);

      uVar3 = *(undefined4 *)(uVar16 + 8 + param_1[5]);

      *(undefined4 *)(lVar18 + 0x38) = uVar3;

      *(undefined8 *)(lVar18 + 0x40) = *(undefined8 *)(uVar16 + param_1[6]);

      *(undefined4 *)(lVar18 + 0x48) = *(undefined4 *)(uVar16 + 8 + param_1[6]);

      fVar21 = (float)FUN_1402cdc50(uVar3);

      *(float *)(lVar18 + 0x14) = fVar21;

      fVar27 = (float)FUN_1402cfda0(uVar3);

      *(float *)(lVar18 + 0x18) = fVar27;

      *(float *)(lVar18 + 0xc) =

           *(float *)(lVar18 + 0x2c) -

           (*(float *)(lVar18 + 0x1c) * fVar27 - *(float *)(lVar18 + 0x20) * fVar21);

      *(float *)(lVar18 + 0x10) =

           *(float *)(lVar18 + 0x30) -

           (*(float *)(lVar18 + 0x20) * fVar27 + *(float *)(lVar18 + 0x1c) * fVar21);

      uVar13 = (int)uVar12 + 1;

      uVar12 = (ulonglong)uVar13;

      lVar10 = lVar10 + 8;

      uVar16 = uVar16 + 0xc;

    } while ((int)uVar13 < *(int *)(param_1 + 7));

  }

  uVar16 = 0;

  *(undefined4 *)(local_1b8 + 0x14) = 0;

  FUN_1400184f0(param_1,local_100);

  fVar27 = DAT_14039ca00;

  fVar21 = DAT_14039c9f8;

  if (param_5 != '\0') {

    iVar19 = *(int *)(param_1 + 7);

    uVar12 = uVar16;

    uVar14 = uVar16;

    fVar28 = DAT_14039ca64;

    if (0 < iVar19) {

      do {

        piVar4 = *(int **)(uVar14 + param_1[2]);

        if (*piVar4 != 0) {

          if ((((*(byte *)(piVar4 + 1) & 4) == 0) ||

              (fVar27 < (float)piVar4[0x12] * (float)piVar4[0x12])) ||

             (fVar21 < (float)piVar4[0x11] * (float)piVar4[0x11] +

                       (float)piVar4[0x10] * (float)piVar4[0x10])) {

            piVar4[0x2b] = 0;

            fVar28 = 0.0;

          }

          else {

            fVar29 = fVar1 + (float)piVar4[0x2b];

            piVar4[0x2b] = (int)fVar29;

            if (fVar29 <= fVar28) {

              fVar28 = fVar29;

            }

          }

        }

        uVar13 = (int)uVar12 + 1;

        iVar19 = *(int *)(param_1 + 7);

        uVar12 = (ulonglong)uVar13;

        uVar14 = uVar14 + 8;

      } while ((int)uVar13 < iVar19);

      if (fVar28 < DAT_14039ca34) goto LAB_140017ff6;

    }

    if ((bVar6) && (uVar12 = uVar16, 0 < iVar19)) {

      do {

        lVar10 = *(longlong *)(uVar12 + param_1[2]);

        *(ushort *)(lVar10 + 4) = *(ushort *)(lVar10 + 4) & 0xfffd;

        *(undefined4 *)(lVar10 + 0xac) = 0;

        *(undefined8 *)(lVar10 + 0x40) = 0;

        *(undefined8 *)(lVar10 + 0x48) = 0;

        *(undefined8 *)(lVar10 + 0x50) = 0;

        uVar13 = (int)uVar16 + 1;

        uVar16 = (ulonglong)uVar13;

        uVar12 = uVar12 + 8;

      } while ((int)uVar13 < *(int *)(param_1 + 7));

    }

  }

LAB_140017ff6:

  FUN_140012970(local_110,local_100);

  FUN_140012970(local_110,local_108);

  return;

}




