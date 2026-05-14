// Address: 0x1400bd290
// Ghidra name: FUN_1400bd290
// ============ 0x1400bd290 FUN_1400bd290 (size=1408) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400bd290(longlong param_1,int param_2)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  float fVar4;

  undefined4 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  int iVar8;

  longlong lVar9;

  int iVar10;

  int iVar11;

  longlong lVar12;

  longlong lVar13;

  int iVar14;

  undefined4 uVar15;

  float fVar16;

  float fVar17;

  float local_res8;

  float local_resc;

  int local_res10;

  float local_res18;

  float local_res1c;

  float local_res20;

  float local_res24;

  undefined *in_stack_fffffffffffffee8;

  undefined4 uVar18;

  float local_f8;

  float local_f4;

  

  uVar5 = DAT_14039ca48;

  fVar4 = DAT_14039c9f0;

  uVar3 = DAT_14030d9f8;

  local_res10 = 0;

  lVar12 = (longlong)param_2 * 0xb8 + *(longlong *)(param_1 + 0x40);

  lVar9 = *(longlong *)(lVar12 + 0x18);

  uVar7 = (*(longlong *)(lVar12 + 0x20) - lVar9) / 0x168;

  if (uVar7 != 0) {

    lVar13 = 0;

    uVar15 = DAT_140304b20;

    do {

      iVar11 = local_res10;

      uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);

      if (*(char *)(lVar13 + 0x160 + lVar9) != '\0') {

        iVar14 = *(int *)(lVar13 + 0x150 + lVar9);

        if ((iVar14 != 0xd) && (iVar14 != 0xe)) {

          fVar1 = *(float *)(lVar13 + 0x148 + lVar9);

          if (fVar1 <= 0.0) {

            iVar10 = *(int *)(lVar13 + 0x98 + lVar9);

            if (0 < iVar10) {

              uVar15 = DAT_140304b20;

              if ((iVar14 == 0xc) && (iVar10 == 4)) {

                iVar10 = 0;

                iVar14 = *(int *)(param_1 + 0xc4);

                fVar1 = *(float *)(lVar13 + 0x18 + lVar9);

                fVar2 = *(float *)(lVar13 + 0x1c + lVar9);

                fVar17 = (*(float *)(lVar13 + 0x28 + lVar9) - fVar1) / (float)iVar14;

                fVar16 = (*(float *)(lVar13 + 0x2c + lVar9) - fVar2) /

                         (float)*(int *)(param_1 + 200);

                if (0 < *(int *)(param_1 + 200)) {

                  do {

                    iVar8 = 0;

                    if (0 < iVar14) {

                      do {

                        in_stack_fffffffffffffee8 =

                             (undefined *)

                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffee8 >> 0x20),fVar16);

                        FUN_140073140(param_1 + 0x28,(float)iVar8 * fVar17 + fVar1,

                                      (float)iVar10 * fVar16 + fVar2,fVar17,

                                      in_stack_fffffffffffffee8,

                                      *(undefined4 *)

                                       (param_1 + 0x58 +

                                       (longlong)

                                       *(int *)(*(longlong *)(param_1 + 0xa8) +

                                               (longlong)(iVar14 * iVar10 + iVar8) * 4) * 4));

                        iVar14 = *(int *)(param_1 + 0xc4);

                        iVar8 = iVar8 + 1;

                      } while (iVar8 < iVar14);

                    }

                    iVar10 = iVar10 + 1;

                    uVar15 = DAT_140304b20;

                  } while (iVar10 < *(int *)(param_1 + 200));

                }

              }

              else {

                iVar14 = *(int *)(lVar13 + 0x14c + lVar9);

                fVar1 = *(float *)(lVar13 + 0x18 + lVar9);

                fVar2 = *(float *)(lVar13 + 0x1c + lVar9);

                if (iVar14 == -1) {

                  iVar14 = 1;

                  if (1 < iVar10 + -1) {

                    do {

                      in_stack_fffffffffffffee8 =

                           (undefined *)((ulonglong)in_stack_fffffffffffffee8 & 0xffffffff00000000);

                      FUN_1400731f0(param_1 + 0x28);

                      iVar14 = iVar14 + 1;

                      uVar15 = DAT_140304b20;

                      iVar11 = local_res10;

                    } while (iVar14 < *(int *)(lVar13 + 0x98 + lVar9) + -1);

                  }

                }

                else {

                  fVar16 = *(float *)(lVar13 + 0x20 + lVar9) - fVar1;

                  fVar17 = *(float *)(lVar13 + 0x24 + lVar9) - fVar2;

                  fVar17 = fVar17 * fVar17 + fVar16 * fVar16;

                  if (fVar17 < 0.0) {

                    fVar17 = (float)FUN_1402cdfa0();

                  }

                  else {

                    fVar17 = SQRT(fVar17);

                  }

                  if (fVar17 < fVar4) {

                    fVar17 = 0.0;

                  }

                  uVar15 = FUN_1402cd4c0();

                  in_stack_fffffffffffffee8 = (undefined *)CONCAT44(uVar18,uVar15);

                  FUN_140073360(param_1 + 0x28,iVar14,fVar1,fVar2,in_stack_fffffffffffffee8,fVar17,

                                fVar17);

                  uVar15 = DAT_140304b20;

                }

              }

            }

          }

          else {

            fVar2 = *(float *)(lVar13 + 0x140 + lVar9);

            fVar17 = *(float *)(lVar13 + 0x144 + lVar9);

            if (iVar14 == 7) {

              local_res8 = fVar2 + fVar1;

              fVar16 = (float)((uint)fVar1 ^ DAT_14039cac0);

              local_resc = fVar17 + 0.0;

              local_res18 = fVar16 + fVar2;

              local_res1c = local_resc;

              FUN_140073420(param_1 + 0x28,&local_res18,&local_res8,uVar15,&DAT_1403da3d0);

              local_res20 = fVar2 + 0.0;

              in_stack_fffffffffffffee8 = &DAT_1403da3d0;

              local_f4 = fVar16 + fVar17;

              local_res24 = fVar17 + fVar1;

              local_f8 = local_res20;

              FUN_140073420(param_1 + 0x28,&local_f8,&local_res20,uVar15,&DAT_1403da3d0);

            }

            else {

              in_stack_fffffffffffffee8 =

                   (undefined *)

                   CONCAT44(uVar18,*(undefined4 *)(param_1 + 0x58 + (longlong)iVar14 * 4));

              FUN_1400732c0(param_1 + 0x28,uVar7,fVar17,fVar1,in_stack_fffffffffffffee8);

            }

          }

          if ((iVar11 == 0) && (*(uint *)(lVar12 + 0x10) < 4)) {

            if (*(float *)(lVar13 + 0x148 + lVar9) <= 0.0) {

              lVar6 = lVar9 + 0xb0;

              if (*(char *)(param_1 + 0x1a) == '\0') {

                lVar6 = lVar9 + 0x10;

              }

            }

            else {

              lVar6 = lVar9 + 0x140;

            }

            if ((*(int *)(lVar12 + 8) == 3) || (uVar18 = uVar5, *(int *)(lVar12 + 8) == 1)) {

              uVar18 = uVar3;

            }

            in_stack_fffffffffffffee8 =

                 (undefined *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffee8 >> 0x20),uVar18);

            FUN_14005e010(param_1 + 0x28,*(uint *)(lVar12 + 0x10),*(undefined4 *)(lVar6 + lVar13),

                          ((undefined4 *)(lVar6 + lVar13))[1],in_stack_fffffffffffffee8);

          }

        }

      }

      lVar9 = *(longlong *)(lVar12 + 0x18);

      local_res10 = iVar11 + 1;

      lVar13 = lVar13 + 0x168;

      uVar7 = (*(longlong *)(lVar12 + 0x20) - lVar9) / 0x168;

    } while ((ulonglong)(longlong)local_res10 < uVar7);

  }

  return;

}




