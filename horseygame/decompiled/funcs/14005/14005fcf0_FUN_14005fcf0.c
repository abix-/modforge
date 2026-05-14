// Address: 0x14005fcf0
// Ghidra name: FUN_14005fcf0
// ============ 0x14005fcf0 FUN_14005fcf0 (size=2577) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14005fcf0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  undefined8 uVar6;

  longlong lVar7;

  int *piVar8;

  int *piVar9;

  int iVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  undefined1 auVar13 [8];

  ulonglong uVar14;

  int *piVar15;

  char cVar16;

  uint uVar17;

  ulonglong uVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  undefined8 local_res8;

  undefined1 local_88 [8];

  int *piStack_80;

  int *local_78;

  undefined8 local_70;

  longlong lStack_68;

  longlong local_60;

  undefined8 local_58;

  

  FUN_1400cf540(param_1,3,DAT_14039ca44,param_4,DAT_140307a48,DAT_140307a44);

  FUN_1400cf540(param_1,4,DAT_140304bf4);

  FUN_1400d0a00(param_1,0);

  FUN_1400ca240(param_1,6,0);

  *(undefined4 *)(param_1 + 0x290) = *(undefined4 *)(DAT_1403fb0d8 + 0x308);

  piVar9 = (int *)0x0;

  *(undefined4 *)(param_1 + 600) = 0;

  *(undefined2 *)(param_1 + 0x2b8) = 0;

  *(undefined4 *)(param_1 + 0x270) = 0;

  *(undefined4 *)(param_1 + 0x268) = 0;

  if ((*(int *)(DAT_1403fb0d8 + 0x308) < 1) && (*(int *)(param_1 + 0x254) == 0)) {

    *(undefined4 *)(param_1 + 0x254) = 5;

    *(undefined4 *)(param_1 + 600) = 0xf;

  }

  local_58 = 0xf;

  if (*(int *)(param_1 + 0x254) == 4) {

    lStack_68 = 0;

    local_60 = 4;

    local_70 = 0x676e7544;

    FUN_14003f340(&local_70,1);

    FUN_1400ce540(param_1,0,0);

    FUN_1400ca240(param_1,7,0);

    FUN_1400cf540(param_1,4,DAT_1403033a4);

    *(undefined1 *)(param_1 + 0x234) = 0;

    *(undefined4 *)(param_1 + 0x238) = 0;

    goto LAB_1400605c0;

  }

  if (*(int *)(param_1 + 0x254) == 5) {

    lStack_68 = 0;

    local_60 = 4;

    local_70 = 0x676e7544;

    FUN_14003f340(&local_70,1);

    FUN_1400ce540(param_1,0,0);

    FUN_1400ca240(param_1,7,0);

    FUN_1400cf540(param_1,4,DAT_1403033a4);

    piVar15 = (int *)(param_1 + 0x264);

    if ((*(int *)(param_1 + 0x260) < 5) || (*piVar15 < DAT_1403eded8 + -1)) {

      if (*piVar15 < DAT_1403eded8 + -10) {

        *(undefined4 *)(param_1 + 0x25c) = 3;

      }

    }

    else {

      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;

    }

    *piVar15 = DAT_1403eded8;

    piVar15 = piVar9;

    if (0 < *(int *)(param_1 + 0x25c)) {

      do {

        uVar6 = FUN_1400cc9d0(param_1,8,0);

        lVar7 = FUN_140106ac0(DAT_1403fb0d8);

        if (lVar7 != 0) {

          FUN_14005d190(uVar6,lVar7 + 0x2b8);

        }

        uVar17 = (int)piVar15 + 1;

        piVar15 = (int *)(ulonglong)uVar17;

      } while ((int)uVar17 < *(int *)(param_1 + 0x25c));

    }

    fVar2 = DAT_14039ca34;

    lVar7 = *(longlong *)(param_1 + 0xb8);

    piVar15 = piVar9;

    if (*(longlong *)(param_1 + 0xc0) - lVar7 >> 3 != 0) {

      do {

        if (*(int *)(*(longlong *)(lVar7 + (longlong)piVar15) + 0xc) == 8) {

          FUN_1400c57a0(&local_res8,*(longlong *)(param_1 + 0x78) + 0x30,fVar2);

          *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + (longlong)piVar15) + 0x28) =

               (undefined4)local_res8;

          *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + (longlong)piVar15) + 0x2c) =

               local_res8._4_4_;

        }

        uVar17 = (int)piVar9 + 1;

        piVar9 = (int *)(ulonglong)uVar17;

        lVar7 = *(longlong *)(param_1 + 0xb8);

        piVar15 = piVar15 + 2;

      } while ((ulonglong)(longlong)(int)uVar17 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar7 >> 3));

    }

    *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;

    *(undefined1 *)(param_1 + 0x234) = 0;

    *(undefined4 *)(param_1 + 0x238) = 0;

    goto LAB_1400605c0;

  }

  lStack_68 = 0;

  local_60 = 7;

  local_70 = (ulonglong)

             CONCAT16(s_Paddock_140307370[6],

                      CONCAT24(s_Paddock_140307370._4_2_,s_Paddock_140307370._0_4_));

  FUN_14003f340(&local_70,1);

  FUN_1400cd5a0(param_1,*(int *)(param_1 + 0x254) != 1);

  FUN_1400ce540(param_1,0,0);

  FUN_1400ca240(param_1,7,1);

  *(undefined1 *)(param_1 + 0x295) = 0;

  if (*(int *)(param_1 + 0x254) != 1) {

    *(undefined4 *)(param_1 + 0x254) = 2;

  }

  FUN_140060710(param_1,0);

  local_78 = (int *)0x0;

  lVar7 = *(longlong *)(param_1 + 0xb8);

  piStack_80 = (int *)0x0;

  local_88 = (undefined1  [8])0x0;

  auVar13 = local_88;

  piVar15 = piStack_80;

  local_88 = (undefined1  [8])0;

  if (*(longlong *)(param_1 + 0xc0) - lVar7 >> 3 != 0) {

    local_res8 = 0;

    piVar8 = piVar9;

    _local_88 = ZEXT816(0);

    do {

      lVar7 = *(longlong *)(lVar7 + local_res8);

      iVar10 = (int)piVar8;

      if ((*(int *)(lVar7 + 8) == 3) &&

         ((*(int *)(lVar7 + 0xc) == 9 || (*(int *)(lVar7 + 0xc) == 10)))) {

        pfVar1 = *(float **)(param_1 + 0x78);

        if ((*(float *)(lVar7 + 0x28) < *pfVar1) ||

           (((*pfVar1 + pfVar1[2] <= *(float *)(lVar7 + 0x28) ||

             (*(float *)(lVar7 + 0x2c) < pfVar1[1])) ||

            (pfVar1[1] + pfVar1[3] <= *(float *)(lVar7 + 0x2c))))) {

          if (piVar15 == piVar9) {

            lVar7 = (longlong)piVar15 - (longlong)auVar13 >> 2;

            if (lVar7 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

              FUN_14002f0d0();

            }

            uVar14 = lVar7 + 1;

            uVar12 = (longlong)piVar9 - (longlong)auVar13 >> 2;

            if (0x3fffffffffffffff - (uVar12 >> 1) < uVar12) {

              uVar11 = 0x3fffffffffffffff;

            }

            else {

              uVar12 = uVar12 + (uVar12 >> 1);

              uVar11 = uVar14;

              if (uVar14 <= uVar12) {

                uVar11 = uVar12;

              }

              if (0x3fffffffffffffff < uVar11) {

                    /* WARNING: Subroutine does not return */

                FUN_140024090();

              }

            }

            piVar8 = (int *)FUN_1400285e0(uVar11 * 4);

            piVar8[lVar7] = iVar10;

            piVar9 = piVar8;

            auVar13 = local_88;

            if (piVar15 != piStack_80) {

              FUN_1402f8e20(piVar8,local_88,(longlong)piVar15 - (longlong)local_88);

              piVar9 = piVar8 + lVar7 + 1;

              auVar13 = (undefined1  [8])piVar15;

            }

            FUN_1402f8e20(piVar9,auVar13);

            if (local_88 != (undefined1  [8])0x0) {

              if ((0xfff < ((longlong)local_78 - (longlong)local_88 & 0xfffffffffffffffcU)) &&

                 (0x1f < (ulonglong)

                         ((longlong)local_88 + (-8 - *(longlong *)((longlong)local_88 + -8))))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

            piVar15 = piVar8 + uVar14;

            local_78 = piVar8 + uVar11;

            local_88 = (undefined1  [8])piVar8;

          }

          else {

            *piVar15 = iVar10;

            piVar15 = piStack_80 + 1;

          }

          piStack_80 = piVar15;

          piVar9 = local_78;

          auVar13 = local_88;

        }

      }

      piVar8 = (int *)(ulonglong)(iVar10 + 1U);

      local_res8 = local_res8 + 8;

      lVar7 = *(longlong *)(param_1 + 0xb8);

    } while ((ulonglong)(longlong)(int)(iVar10 + 1U) <

             (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar7 >> 3));

  }

  uVar14 = 0;

  *(undefined4 *)(param_1 + 0x2c8) = 0;

  fVar4 = DAT_140307a6c;

  fVar3 = DAT_140307a68;

  fVar2 = DAT_14030335c;

  iVar10 = (int)((longlong)piVar15 - (longlong)auVar13 >> 2);

  if (0 < iVar10) {

    iVar5 = 6;

    if (iVar10 + -1 < 6) {

      iVar5 = iVar10 + -1;

    }

    fVar21 = (float)iVar5 * DAT_140307a3c * DAT_14039ca34 + _DAT_140307a50;

    fVar19 = fVar21;

    fVar20 = DAT_140303fb8;

    for (; auVar13 != (undefined1  [8])piVar15; auVar13 = (undefined1  [8])((longlong)auVar13 + 4))

    {

      iVar5 = *(int *)auVar13;

      lVar7 = (longlong)iVar5;

      *(float *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar7 * 8) + 0x28) = fVar19;

      *(float *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar7 * 8) + 0x2c) = fVar20;

      if (6 < iVar5) {

        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar7 * 8);

        *(float *)(lVar7 + 0x2c) = *(float *)(lVar7 + 0x2c) + fVar2;

      }

      fVar19 = fVar19 + fVar3;

      if (fVar19 < fVar2) {

        fVar20 = fVar20 + fVar4;

        fVar19 = fVar21;

      }

    }

    iVar10 = iVar10 * 10 + 3;

    iVar5 = 0x41;

    if (iVar10 < 0x41) {

      iVar5 = iVar10;

    }

    *(float *)(param_1 + 0x2c8) = (float)iVar5;

  }

  cVar16 = *(char *)(param_1 + 0x294);

  if (((cVar16 == '\0') && (*(int *)(param_1 + 0x254) != 1)) &&

     ((0 < *(int *)(DAT_1403fb0d8 + 0x318) &&

      (lVar7 = *(longlong *)(param_1 + 0x130), uVar12 = uVar14,

      *(longlong *)(param_1 + 0x138) - lVar7 >> 3 != 0)))) {

    do {

      lVar7 = FUN_1400c7520(*(undefined4 *)(*(longlong *)(lVar7 + uVar12) + 0x1f8));

      if (0 < *(int *)(lVar7 + 0x54)) {

        *(undefined1 *)(param_1 + 0x294) = 1;

      }

      uVar17 = (int)uVar14 + 1;

      uVar14 = (ulonglong)uVar17;

      lVar7 = *(longlong *)(param_1 + 0x130);

      uVar12 = uVar12 + 8;

    } while ((ulonglong)(longlong)(int)uVar17 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar7 >> 3));

    cVar16 = *(char *)(param_1 + 0x294);

  }

  piVar9 = (int *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    piVar9 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 5) {

    iVar10 = *piVar9 + -0x6d616843;

    if (iVar10 == 0) {

      iVar10 = *(byte *)(piVar9 + 1) - 0x70;

    }

    if (iVar10 != 0) goto LAB_14006049d;

    *(undefined1 *)(param_1 + 0x294) = 1;

LAB_1400604a6:

    if (*(int *)(param_1 + 0x1b0) == 0) {

      FUN_140105b00(DAT_1403fb0d8,&local_70,6,3,1);

      if ((ulonglong)((longlong)(lStack_68 - local_70) >> 3) < 3) {

        piVar9 = (int *)&DAT_1403d9530;

        if (0xf < DAT_1403d9548) {

          piVar9 = DAT_1403d9530;

        }

        if (DAT_1403d9540 == 5) {

          iVar10 = *piVar9 + -0x6d616843;

          if (iVar10 == 0) {

            iVar10 = *(byte *)(piVar9 + 1) - 0x70;

          }

          if (iVar10 == 0) goto LAB_140060517;

        }

      }

      else {

LAB_140060517:

        *(undefined1 *)(param_1 + 0x295) = 1;

      }

      if (local_70 != 0) {

        if ((0xfff < (local_60 - local_70 & 0xfffffffffffffff8)) &&

           (0x1f < (local_70 - *(longlong *)(local_70 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

  }

  else {

LAB_14006049d:

    if (cVar16 != '\0') goto LAB_1400604a6;

  }

  local_res8 = CONCAT44(local_res8._4_4_,0xffffffff);

  FUN_140064380(param_1 + 0x278,*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3

               );

  if (local_88 != (undefined1  [8])0x0) {

    if ((0xfff < ((longlong)local_78 - (longlong)local_88 & 0xfffffffffffffffcU)) &&

       (0x1f < ((longlong)local_88 - *(longlong *)((longlong)local_88 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

LAB_1400605c0:

  uVar14 = 0;

  *(undefined8 *)(param_1 + 0x2c0) = 0;

  if (*(char *)(param_1 + 0x2b8) == '\0') {

    lVar7 = *(longlong *)(param_1 + 0x298);

    if ((lVar7 != *(longlong *)(param_1 + 0x2a0)) &&

       (uVar12 = uVar14, uVar11 = uVar14, uVar18 = uVar14,

       *(longlong *)(param_1 + 0x2a0) - lVar7 >> 4 != 0)) {

      do {

        if (uVar12 != 0) break;

        uVar12 = uVar14;

        if (*(char *)(lVar7 + 10 + uVar11) == '\0') {

          uVar12 = *(ulonglong *)(lVar7 + uVar11);

          *(ulonglong *)(param_1 + 0x2c0) = uVar12;

        }

        uVar17 = (int)uVar18 + 1;

        uVar11 = uVar11 + 0x10;

        uVar18 = (ulonglong)uVar17;

      } while ((ulonglong)(longlong)(int)uVar17 <

               (ulonglong)(*(longlong *)(param_1 + 0x2a0) - lVar7 >> 4));

    }

  }

  if (*(longlong *)(param_1 + 0x298) != *(longlong *)(param_1 + 0x2a0)) {

    *(longlong *)(param_1 + 0x2a0) = *(longlong *)(param_1 + 0x298);

  }

  *(undefined1 *)(param_1 + 0x2b0) = 0;

  *(undefined1 *)(param_1 + 0x26e) = 1;

  if (*(longlong *)(*(longlong *)(DAT_1403fb0d8 + 0x438) + -8 + (longlong)*(int *)(param_1 + 8) * 8)

      == 0) {

    FUN_1400ca240(param_1,7,0);

  }

  return 1;

}




