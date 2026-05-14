// Address: 0x1400d0a00
// Ghidra name: FUN_1400d0a00
// ============ 0x1400d0a00 FUN_1400d0a00 (size=586) ============


undefined8 FUN_1400d0a00(longlong param_1,char param_2)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  float fVar6;

  char cVar7;

  int iVar8;

  float *pfVar9;

  longlong lVar10;

  int iVar11;

  longlong lVar12;

  int iVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  undefined1 local_res8 [8];

  

  fVar6 = DAT_14039ca34;

  if ((*(longlong *)(param_1 + 0x148) == 0) && (param_2 != '\0')) {

    lVar10 = *(longlong *)(param_1 + 0x130);

    iVar11 = 0;

    iVar13 = -1;

    fVar16 = 0.0;

    if (*(longlong *)(param_1 + 0x138) - lVar10 >> 3 != 0) {

      lVar12 = 0;

      do {

        lVar10 = *(longlong *)(lVar12 + lVar10);

        if ((*(char *)(lVar10 + 0x204) == '\0') && (cVar7 = FUN_1400b7650(lVar10), cVar7 != '\0')) {

          cVar7 = FUN_1400b7720(lVar10);

          lVar3 = *(longlong *)(param_1 + 0x78);

          fVar14 = *(float *)(lVar3 + 0x18);

          fVar15 = *(float *)(lVar3 + 0x1c);

          fVar1 = *(float *)(lVar3 + 0x10);

          fVar2 = *(float *)(lVar3 + 0x14);

          pfVar9 = (float *)FUN_1400b4a10(lVar10,local_res8);

          fVar14 = *pfVar9 - (fVar14 * fVar6 + fVar1);

          fVar15 = pfVar9[1] - (fVar15 * fVar6 + fVar2);

          iVar8 = 0x14;

          if (cVar7 != '\0') {

            iVar8 = 100;

          }

          fVar14 = fVar15 * fVar15 + fVar14 * fVar14;

          if (fVar14 < 0.0) {

            fVar14 = (float)FUN_1402cdfa0(fVar14);

          }

          else {

            fVar14 = SQRT(fVar14);

          }

          if (fVar16 < (float)iVar8 - fVar14) {

            fVar16 = (float)iVar8 - fVar14;

            iVar13 = iVar11;

          }

        }

        lVar10 = *(longlong *)(param_1 + 0x130);

        iVar11 = iVar11 + 1;

        lVar12 = lVar12 + 8;

      } while ((ulonglong)(longlong)iVar11 <

               (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar10 >> 3));

      if (iVar13 != -1) {

        FUN_1400d03f0(param_1,iVar13);

        FUN_1400d1e10(param_1,iVar13,4);

      }

    }

  }

  if (*(longlong *)(param_1 + 0x148) == 0) {

    return 0;

  }

  FUN_1400b8f90(*(longlong *)(param_1 + 0x148),0);

  uVar5 = DAT_14030d9b8;

  uVar4 = DAT_140309bf4;

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x205) = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x206) = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x160) = 1;

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x1a) = 0;

  FUN_1400b6820(*(undefined8 *)(param_1 + 0x148),uVar5,uVar4);

  return *(undefined8 *)(param_1 + 0x148);

}




