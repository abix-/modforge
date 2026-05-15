// Address: 0x1400b6260
// Ghidra name: FUN_1400b6260
// ============ 0x1400b6260 FUN_1400b6260 (size=244) ============


void FUN_1400b6260(longlong param_1)



{

  int *piVar1;

  float fVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  

  fVar2 = DAT_14039ca34;

  lVar5 = *(longlong *)(param_1 + 0x40);

  lVar4 = *(longlong *)(param_1 + 0x48) - lVar5;

  iVar6 = 0;

  lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

  if (lVar4 >> 7 != lVar4 >> 0x3f) {

    lVar4 = 0;

    do {

      piVar1 = *(int **)(lVar4 + 0x30 + lVar5);

      if ((piVar1 != (int *)0x0) && (*(char *)(lVar4 + 0x14 + lVar5) != '\0')) {

        fVar7 = (float)piVar1[0x10] * fVar2;

        fVar8 = (float)piVar1[0x11] * fVar2;

        if (*piVar1 != 0) {

          if ((0.0 < fVar7 * fVar7 + fVar8 * fVar8) && ((*(ushort *)(piVar1 + 1) & 2) == 0)) {

            piVar1[0x2b] = 0;

            *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

          }

          piVar1[0x10] = (int)fVar7;

          piVar1[0x11] = (int)fVar8;

        }

      }

      lVar5 = *(longlong *)(param_1 + 0x40);

      iVar6 = iVar6 + 1;

      lVar3 = *(longlong *)(param_1 + 0x48) - lVar5;

      lVar4 = lVar4 + 0xb8;

      lVar3 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar3),8) + lVar3;

    } while ((ulonglong)(longlong)iVar6 < (ulonglong)((lVar3 >> 7) - (lVar3 >> 0x3f)));

  }

  return;

}




