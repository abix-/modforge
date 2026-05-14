// Address: 0x14014b2d0
// Ghidra name: FUN_14014b2d0
// ============ 0x14014b2d0 FUN_14014b2d0 (size=815) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



bool FUN_14014b2d0(longlong param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  bool bVar4;

  bool bVar5;

  byte bVar6;

  bool bVar7;

  ulonglong uVar8;

  float *pfVar9;

  int iVar10;

  undefined1 *puVar11;

  float *pfVar12;

  float *pfVar13;

  float *pfVar14;

  int iVar15;

  bool bVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  bool local_res18;

  int local_res20;

  undefined1 auStack_c8 [48];

  float local_98;

  int local_94;

  float *local_90;

  float *local_88;

  float *local_80;

  ulonglong local_78;

  

  puVar11 = auStack_c8;

  local_98 = (float)(param_3 + -1);

  bVar4 = false;

  local_78 = (longlong)(int)local_98 * 0x10;

  bVar5 = false;

  fVar1 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x90);

  bVar16 = true;

  fVar2 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x94);

  local_res20 = 0;

  local_res18 = true;

  if (local_78 < 0x80) {

    uVar8 = local_78 + 0xf;

    if (uVar8 <= local_78) {

      uVar8 = 0xffffffffffffff0;

    }

    puVar11 = auStack_c8 + -(uVar8 & 0xfffffffffffffff0);

    pfVar9 = (float *)((longlong)&local_98 + -(uVar8 & 0xfffffffffffffff0));

  }

  else {

    pfVar9 = (float *)FUN_1401841f0();

  }

  fVar17 = (float)(param_3 + -1);

  iVar15 = 0;

  bVar7 = false;

  if (pfVar9 != (float *)0x0) {

    local_90 = pfVar9;

    if (0 < (int)fVar17) {

      param_3 = param_3 + -2;

      pfVar13 = param_2 + 1;

      pfVar14 = pfVar13;

      local_94 = param_3;

      local_88 = pfVar9;

      local_80 = pfVar13;

      iVar10 = iVar15;

      do {

        fVar18 = pfVar14[-1];

        fVar19 = pfVar14[1];

        fVar20 = *pfVar14;

        fVar3 = pfVar14[2];

        if (iVar15 == param_3) {

          if (((!bVar4) || (fVar19 != *param_2)) || (fVar3 != *pfVar13)) {

            bVar5 = true;

          }

LAB_14014b411:

          if (fVar18 != fVar19) {

LAB_14014b48f:

            if (fVar20 != fVar3) {

              *(undefined8 *)(puVar11 + -8) = 0x14014b523;

              fVar17 = (float)thunk_FUN_1402e1d00();

              *(undefined8 *)(puVar11 + -8) = 0x14014b532;

              fVar18 = (float)thunk_FUN_1402e1d00();

              *(undefined8 *)(puVar11 + -8) = 0x14014b540;

              fVar19 = (float)thunk_FUN_1402e1d00();

              *(undefined8 *)(puVar11 + -8) = 0x14014b54f;

              fVar20 = (float)thunk_FUN_1402e1d00();

              puVar11[0x28] = bVar5;

              *(int *)(puVar11 + 0x20) = (int)fVar17;

              *(undefined8 *)(puVar11 + -8) = 0x14014b56e;

              bVar6 = FUN_14014b030(param_1,(int)fVar20,(int)fVar19,(int)fVar18);

              bVar16 = (local_res18 & bVar6) != 0;

              pfVar12 = local_88;

              pfVar13 = local_80;

              param_3 = local_94;

              local_res18 = bVar16;

              fVar17 = local_98;

            }

            else {

              local_res20 = iVar10 + 1;

              pfVar12 = pfVar9 + 4;

              fVar20 = fVar18;

              if (fVar18 <= fVar19) {

                fVar20 = fVar19;

              }

              if (fVar19 <= fVar18) {

                fVar18 = fVar19;

              }

              local_88 = pfVar12;

              *pfVar9 = fVar18 * fVar1;

              fVar19 = *pfVar14;

              pfVar9[3] = fVar2;

              pfVar9[1] = fVar2 * fVar19;

              pfVar9[2] = ((fVar20 - fVar18) + (float)bVar5) * fVar1;

              if ((bVar5 == false) && (pfVar14[1] <= pfVar14[-1] && pfVar14[-1] != pfVar14[1])) {

                *pfVar9 = fVar18 * fVar1 + fVar1;

              }

            }

          }

          else {

            fVar19 = fVar20;

            if (fVar3 <= fVar20) {

              fVar19 = fVar3;

            }

            local_res20 = iVar10 + 1;

            if (fVar20 <= fVar3) {

              fVar20 = fVar3;

            }

            pfVar12 = pfVar9 + 4;

            *pfVar9 = fVar18 * fVar1;

            pfVar9[2] = fVar1;

            local_88 = pfVar12;

            pfVar9[1] = fVar19 * fVar2;

            pfVar9[3] = ((fVar20 - fVar19) + (float)bVar5) * fVar2;

            if ((!bVar5) && (pfVar14[2] <= *pfVar14 && *pfVar14 != pfVar14[2])) {

              pfVar9[1] = fVar19 * fVar2 + fVar2;

            }

          }

          bVar4 = true;

          pfVar9 = pfVar12;

          iVar10 = local_res20;

        }

        else {

          if (fVar18 != fVar19) goto LAB_14014b48f;

          if (fVar20 != fVar3) goto LAB_14014b411;

        }

        pfVar12 = local_90;

        iVar15 = iVar15 + 1;

        pfVar14 = pfVar14 + 2;

      } while (iVar15 < (int)fVar17);

      if (iVar10 != 0) {

        *(undefined8 *)(puVar11 + -8) = 0x14014b5c5;

        bVar6 = FUN_14014a7b0(param_1,pfVar12,iVar10);

        bVar16 = (bVar16 & bVar6) != 0;

      }

    }

    pfVar9 = local_90;

    bVar7 = bVar16;

    if (0x7f < local_78) {

      *(undefined8 *)(puVar11 + -8) = 0x14014b5e2;

      FUN_1401841e0(pfVar9);

    }

  }

  return bVar7;

}




