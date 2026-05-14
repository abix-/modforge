// Address: 0x14000a690
// Ghidra name: FUN_14000a690
// ============ 0x14000a690 FUN_14000a690 (size=1612) ============


void FUN_14000a690(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  longlong lVar11;

  uint uVar12;

  longlong lVar13;

  longlong lVar14;

  uint *puVar15;

  float *pfVar16;

  int iVar17;

  bool bVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float local_d0;

  float local_cc;

  float local_c8;

  undefined1 local_c0 [184];

  

  uVar12 = DAT_14039cac0;

  lVar11 = *(longlong *)(param_2 + 8);

  fVar1 = *(float *)(param_1 + 0xe4);

  fVar2 = *(float *)(param_1 + 0xf0);

  fVar3 = *(float *)(param_1 + 0xe8);

  lVar13 = (longlong)*(int *)(param_1 + 0xbc);

  lVar14 = (longlong)*(int *)(param_1 + 0xc0);

  fVar4 = *(float *)(param_1 + 0xec);

  fVar5 = *(float *)(lVar11 + lVar13 * 0xc);

  fVar6 = *(float *)(lVar11 + 4 + lVar13 * 0xc);

  fVar24 = *(float *)(lVar11 + 8 + lVar13 * 0xc);

  fVar7 = *(float *)(lVar11 + lVar14 * 0xc);

  fVar8 = *(float *)(lVar11 + 4 + lVar14 * 0xc);

  bVar18 = fVar2 + fVar4 != 0.0;

  fVar27 = *(float *)(lVar11 + 8 + lVar14 * 0xc);

  if (((*(char *)(param_1 + 0xa0) != '\0') && (*(int *)(param_1 + 0x11c) != 3)) && (bVar18)) {

    fVar22 = *(float *)(param_1 + 0x9c);

    fVar20 = *(float *)(param_1 + 0xa4) * *param_2;

    fVar19 = ((fVar27 - fVar24) - *(float *)(param_1 + 0xa8)) *

             (float)(*(uint *)(param_1 + 0x118) ^ DAT_14039cac0) + fVar22;

    if (fVar20 <= fVar19) {

      fVar19 = fVar20;

    }

    fVar23 = (float)((uint)fVar20 ^ DAT_14039cac0);

    if ((float)((uint)fVar20 ^ DAT_14039cac0) <= fVar19) {

      fVar23 = fVar19;

    }

    *(float *)(param_1 + 0x9c) = fVar23;

    fVar23 = fVar23 - fVar22;

    fVar27 = fVar27 + fVar23 * fVar2;

    fVar24 = fVar24 - fVar23 * fVar4;

  }

  if (((*(char *)(param_1 + 0xac) == '\0') || (iVar17 = *(int *)(param_1 + 0x11c), iVar17 == 0)) ||

     (!bVar18)) {

    fVar19 = (float)((uint)(((fVar7 - fVar27 * *(float *)(param_1 + 0xd0)) - fVar5) -

                           (float)((uint)fVar24 ^ uVar12) * *(float *)(param_1 + 200)) ^ uVar12);

    fVar20 = (float)((uint)(((*(float *)(param_1 + 0xcc) * fVar27 + fVar8) - fVar6) -

                           *(float *)(param_1 + 0xc4) * fVar24) ^ uVar12);

    fVar22 = *(float *)(param_1 + 0x104) * *(float *)(param_1 + 0xf4) -

             *(float *)(param_1 + 0xf8) * *(float *)(param_1 + 0x100);

    if (fVar22 != 0.0) {

      fVar22 = DAT_14039ca44 / fVar22;

    }

    fVar23 = (fVar19 * *(float *)(param_1 + 0x104) - fVar20 * *(float *)(param_1 + 0x100)) * fVar22;

    fVar22 = (fVar20 * *(float *)(param_1 + 0xf4) - fVar19 * *(float *)(param_1 + 0xf8)) * fVar22;

    *(float *)(param_1 + 0x90) = fVar23 + *(float *)(param_1 + 0x90);

    *(float *)(param_1 + 0x94) = fVar22 + *(float *)(param_1 + 0x94);

    fVar20 = fVar22 * *(float *)(param_1 + 0xc4) - fVar23 * *(float *)(param_1 + 200);

    fVar19 = fVar22 * *(float *)(param_1 + 0xcc) - fVar23 * *(float *)(param_1 + 0xd0);

    goto LAB_14000abfd;

  }

  pfVar16 = (float *)(param_1 + 0xf4);

  fVar20 = ((fVar7 - fVar27 * *(float *)(param_1 + 0xd0)) - fVar5) -

           (float)((uint)fVar24 ^ uVar12) * *(float *)(param_1 + 200);

  fVar26 = ((fVar27 * *(float *)(param_1 + 0xcc) + fVar8) - fVar6) -

           fVar24 * *(float *)(param_1 + 0xc4);

  local_c8 = fVar27 - fVar24;

  local_d0 = fVar20;

  local_cc = fVar26;

  puVar15 = (uint *)FUN_140007a90(pfVar16,local_c0,&local_d0);

  fVar23 = (float)(*puVar15 ^ uVar12);

  fVar22 = (float)(puVar15[1] ^ uVar12);

  fVar19 = (float)(puVar15[2] ^ uVar12);

  if (iVar17 == 3) {

    *(float *)(param_1 + 0x90) = fVar23 + *(float *)(param_1 + 0x90);

    *(float *)(param_1 + 0x98) = fVar19 + *(float *)(param_1 + 0x98);

LAB_14000aa26:

    *(float *)(param_1 + 0x94) = fVar22 + *(float *)(param_1 + 0x94);

  }

  else {

    if (iVar17 == 1) {

      fVar25 = *(float *)(param_1 + 0x98);

      fVar21 = fVar25 + fVar19;

      bVar18 = 0.0 < fVar21;

LAB_14000a946:

      if (bVar18 || fVar21 == 0.0) {

        *(float *)(param_1 + 0x98) = fVar21;

      }

      else {

        fVar23 = pfVar16[4];

        fVar21 = *pfVar16;

        fVar20 = fVar25 * *(float *)(param_1 + 0x10c) - fVar20;

        fVar9 = pfVar16[1];

        fVar26 = fVar25 * *(float *)(param_1 + 0x110) - fVar26;

        fVar10 = pfVar16[3];

        fVar22 = fVar23 * fVar21 - fVar9 * fVar10;

        if (fVar22 != 0.0) {

          fVar22 = DAT_14039ca44 / fVar22;

        }

        *(undefined4 *)(param_1 + 0x98) = 0;

        fVar19 = (float)((uint)fVar25 ^ uVar12);

        fVar23 = (fVar23 * fVar20 - fVar10 * fVar26) * fVar22;

        fVar22 = (fVar21 * fVar26 - fVar9 * fVar20) * fVar22;

      }

      *(float *)(param_1 + 0x90) = fVar23 + *(float *)(param_1 + 0x90);

      goto LAB_14000aa26;

    }

    if (iVar17 == 2) {

      fVar25 = *(float *)(param_1 + 0x98);

      fVar21 = fVar25 + fVar19;

      bVar18 = fVar21 < 0.0;

      goto LAB_14000a946;

    }

  }

  fVar20 = (fVar22 * *(float *)(param_1 + 0xc4) - fVar23 * *(float *)(param_1 + 200)) + fVar19;

  fVar19 = (fVar22 * *(float *)(param_1 + 0xcc) - fVar23 * *(float *)(param_1 + 0xd0)) + fVar19;

LAB_14000abfd:

  iVar17 = *(int *)(param_1 + 0xbc);

  lVar11 = *(longlong *)(param_2 + 8);

  *(float *)(lVar11 + (longlong)iVar17 * 0xc) = fVar5 - fVar23 * fVar1;

  *(float *)(lVar11 + 4 + (longlong)iVar17 * 0xc) = fVar6 - fVar22 * fVar1;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xbc) * 0xc) =

       fVar24 - fVar20 * fVar4;

  iVar17 = *(int *)(param_1 + 0xc0);

  lVar11 = *(longlong *)(param_2 + 8);

  *(float *)(lVar11 + (longlong)iVar17 * 0xc) = fVar23 * fVar3 + fVar7;

  *(float *)(lVar11 + 4 + (longlong)iVar17 * 0xc) = fVar22 * fVar3 + fVar8;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) =

       fVar19 * fVar2 + fVar27;

  return;

}




