// Address: 0x1400b87e0
// Ghidra name: FUN_1400b87e0
// ============ 0x1400b87e0 FUN_1400b87e0 (size=1137) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400b87e0(longlong param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  float fVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  longlong lVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  uint uVar15;

  ulonglong uVar16;

  float fVar17;

  float fVar18;

  longlong in_stack_ffffffffffffff68;

  uint7 uVar19;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  ulonglong uStack_70;

  

  fVar7 = DAT_14039ca44;

  uVar6 = _UNK_140304088;

  uVar5 = _DAT_140304080;

  uVar14 = _UNK_1403033d8;

  uVar4 = _DAT_1403033d0;

  fVar3 = DAT_14030338c;

  fVar2 = DAT_140303380;

  if (*(int *)(param_1 + 0x1c) < 4) {

    uVar13 = 0;

    lVar10 = *(longlong *)(param_1 + 0x48);

    lVar12 = *(longlong *)(param_1 + 0x40);

    lVar9 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar10 - lVar12),8) + (lVar10 - lVar12);

    uVar11 = uVar13;

    uVar16 = uVar13;

    if (lVar9 >> 7 != lVar9 >> 0x3f) {

      do {

        iVar1 = *(int *)(uVar11 + 8 + lVar12);

        if (iVar1 == 7) {

          *(undefined4 *)(uVar11 + 0xa4 + lVar12) = 1;

          *(undefined4 *)(uVar11 + 0xa8 + *(longlong *)(param_1 + 0x40)) = 0x3c;

          *(undefined4 *)(uVar11 + 0xac + *(longlong *)(param_1 + 0x40)) = 0x3f000000;

          iVar1 = *(int *)(param_1 + 0x1ac);

          if (((iVar1 != -1) && (0 < *(int *)(param_1 + 0x1b0))) &&

             (*(int *)(param_1 + 0x1c4) + 0x3c <= *(int *)(param_1 + 8))) {

            iVar8 = FUN_140040fe0();

            fVar17 = (float)iVar8;

            uVar19 = (uint7)((ulonglong)in_stack_ffffffffffffff68 >> 8);

            if (*(longlong *)(param_1 + 0x178) == 0) {

              fVar18 = fVar7;

              if (*(int *)(param_1 + 0x1fc) == 0) {

                fVar18 = fVar2;

              }

              in_stack_ffffffffffffff68 = (ulonglong)uVar19 << 8;

              FUN_1400409d0(iVar1,*(undefined4 *)(param_1 + 0x1b0),(int)fVar17,

                            fVar18 * *(float *)(param_1 + 0x1b4),in_stack_ffffffffffffff68);

            }

            else {

              in_stack_ffffffffffffff68 = (ulonglong)uVar19 << 8;

              FUN_140040ca0(param_1 + 0x168,*(undefined4 *)(param_1 + 0x1b0),(int)fVar17,fVar7,

                            in_stack_ffffffffffffff68);

            }

            uVar19 = (uint7)((ulonglong)in_stack_ffffffffffffff68 >> 8);

            if (*(int *)(param_1 + 0x1c) == 2) {

              uStack_80 = 0;

              local_78 = uVar5;

              uStack_70 = uVar6;

              local_88 = (ulonglong)CONCAT14(s_Drunk_14030d834[4],s_Drunk_14030d834._0_4_);

              in_stack_ffffffffffffff68 = (ulonglong)uVar19 << 8;

              FUN_140040ca0(&local_88,*(undefined4 *)(param_1 + 0x1b0),(int)fVar17,fVar7,

                            in_stack_ffffffffffffff68);

              if (0xf < uStack_70) {

                if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)

                   ) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

LAB_1400b8a86:

                FUN_1402c7088();

              }

            }

            else if (*(int *)(param_1 + 0x1c) == 1) {

              uStack_80 = 0;

              local_78 = uVar4;

              uStack_70 = uVar14;

              local_88 = (ulonglong)CONCAT24(s_Sauced_14030d83c._4_2_,s_Sauced_14030d83c._0_4_);

              in_stack_ffffffffffffff68 = (ulonglong)uVar19 << 8;

              FUN_140040ca0(&local_88,*(undefined4 *)(param_1 + 0x1b0),(int)fVar17,fVar7,

                            in_stack_ffffffffffffff68);

              if (0xf < uStack_70) {

                if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)

                   ) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                goto LAB_1400b8a86;

              }

            }

            *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 8);

          }

        }

        else if (iVar1 == 8) {

          if (*(int *)(param_1 + 0x238) == 0) {

            *(undefined4 *)(uVar11 + 0xa4 + lVar12) = 1;

            *(undefined4 *)(uVar11 + 0xa8 + *(longlong *)(param_1 + 0x40)) = 0x3c;

            *(float *)(uVar11 + 0xac + *(longlong *)(param_1 + 0x40)) =

                 *(float *)(param_1 + 0x248) * fVar3;

          }

        }

        else if ((iVar1 == 3) && ((*(uint *)(param_1 + 600) & 0x1000000) != 0)) {

          *(undefined4 *)(uVar11 + 0xa4 + lVar12) = 1;

          *(undefined4 *)(uVar11 + 0xa8 + *(longlong *)(param_1 + 0x40)) = 0x5a;

          *(undefined4 *)(uVar11 + 0xac + *(longlong *)(param_1 + 0x40)) = 0x40c00000;

        }

        uVar15 = (int)uVar16 + 1;

        lVar10 = *(longlong *)(param_1 + 0x48);

        lVar12 = *(longlong *)(param_1 + 0x40);

        lVar9 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar10 - lVar12),8) +

                (lVar10 - lVar12);

        uVar11 = uVar11 + 0xb8;

        uVar16 = (ulonglong)uVar15;

      } while ((ulonglong)(longlong)(int)uVar15 < (ulonglong)((lVar9 >> 7) - (lVar9 >> 0x3f)));

    }

    if ((((*(byte *)(param_1 + 600) & 1) != 0) && (*(int *)(param_1 + 0x1c) < 3)) &&

       (lVar10 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar10 - lVar12),8) +

                 (lVar10 - lVar12), uVar14 = uVar13, lVar10 >> 7 != lVar10 >> 0x3f)) {

      do {

        if (*(int *)(uVar13 + 8 + lVar12) == 10) {

          *(undefined4 *)(uVar13 + 0xa4 + lVar12) = 1;

          *(undefined4 *)(uVar13 + 0xa8 + *(longlong *)(param_1 + 0x40)) = 0x2d;

          *(undefined4 *)(uVar13 + 0xac + *(longlong *)(param_1 + 0x40)) = 0x3f800000;

        }

        uVar15 = (int)uVar14 + 1;

        uVar13 = uVar13 + 0xb8;

        lVar12 = *(longlong *)(param_1 + 0x40);

        lVar10 = *(longlong *)(param_1 + 0x48) - lVar12;

        lVar10 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar10),8) + lVar10;

        uVar14 = (ulonglong)uVar15;

      } while ((ulonglong)(longlong)(int)uVar15 < (ulonglong)((lVar10 >> 7) - (lVar10 >> 0x3f)));

    }

  }

  return;

}




