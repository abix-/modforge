// Address: 0x140200b00
// Ghidra name: FUN_140200b00
// ============ 0x140200b00 FUN_140200b00 (size=487) ============


undefined8 FUN_140200b00(undefined8 param_1,longlong param_2,float *param_3,int param_4)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  undefined8 uVar6;

  float *pfVar7;

  int iVar8;

  ulonglong uVar9;

  

  piVar4 = (int *)FUN_14014b940(param_1,(longlong)param_4 << 4,0);

  uVar6 = 0;

  if (piVar4 != (int *)0x0) {

    iVar8 = 0;

    *(longlong *)(param_2 + 0x10) = (longlong)param_4;

    if (3 < param_4) {

      uVar2 = (param_4 - 4U >> 2) + 1;

      uVar9 = (ulonglong)uVar2;

      iVar8 = uVar2 * 4;

      do {

        fVar1 = *param_3;

        *piVar4 = (int)fVar1;

        iVar3 = (int)param_3[2];

        piVar4[2] = iVar3;

        if (iVar3 < 0) {

          piVar4[2] = -iVar3;

          *piVar4 = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[1];

        piVar4[1] = (int)fVar1;

        iVar3 = (int)param_3[3];

        piVar4[3] = iVar3;

        if (iVar3 < 0) {

          piVar4[3] = -iVar3;

          piVar4[1] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[4];

        piVar4[4] = (int)fVar1;

        iVar3 = (int)param_3[6];

        piVar4[6] = iVar3;

        if (iVar3 < 0) {

          piVar4[6] = -iVar3;

          piVar4[4] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[5];

        piVar4[5] = (int)fVar1;

        iVar3 = (int)param_3[7];

        piVar4[7] = iVar3;

        if (iVar3 < 0) {

          piVar4[7] = -iVar3;

          piVar4[5] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[8];

        piVar4[8] = (int)fVar1;

        iVar3 = (int)param_3[10];

        piVar4[10] = iVar3;

        if (iVar3 < 0) {

          piVar4[10] = -iVar3;

          piVar4[8] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[9];

        piVar4[9] = (int)fVar1;

        iVar3 = (int)param_3[0xb];

        piVar4[0xb] = iVar3;

        if (iVar3 < 0) {

          piVar4[0xb] = -iVar3;

          piVar4[9] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[0xc];

        piVar4[0xc] = (int)fVar1;

        iVar3 = (int)param_3[0xe];

        piVar4[0xe] = iVar3;

        if (iVar3 < 0) {

          piVar4[0xe] = -iVar3;

          piVar4[0xc] = (int)fVar1 + iVar3;

        }

        fVar1 = param_3[0xd];

        piVar4[0xd] = (int)fVar1;

        iVar3 = (int)param_3[0xf];

        piVar4[0xf] = iVar3;

        if (iVar3 < 0) {

          piVar4[0xf] = -iVar3;

          piVar4[0xd] = (int)fVar1 + iVar3;

        }

        param_3 = param_3 + 0x10;

        piVar4 = piVar4 + 0x10;

        uVar9 = uVar9 - 1;

      } while (uVar9 != 0);

    }

    if (iVar8 < param_4) {

      piVar5 = piVar4 + 3;

      pfVar7 = param_3 + 1;

      uVar9 = (ulonglong)(uint)(param_4 - iVar8);

      do {

        fVar1 = pfVar7[-1];

        *(int *)((longlong)piVar4 + (-4 - (longlong)param_3) + (longlong)pfVar7) = (int)fVar1;

        iVar8 = (int)pfVar7[1];

        piVar5[-1] = iVar8;

        if (iVar8 < 0) {

          piVar5[-1] = -iVar8;

          *(int *)((longlong)piVar4 + (-4 - (longlong)param_3) + (longlong)pfVar7) =

               (int)fVar1 + iVar8;

        }

        fVar1 = *pfVar7;

        piVar5[-2] = (int)fVar1;

        iVar8 = (int)pfVar7[2];

        *piVar5 = iVar8;

        if (iVar8 < 0) {

          *piVar5 = -iVar8;

          piVar5[-2] = (int)fVar1 + iVar8;

        }

        pfVar7 = pfVar7 + 4;

        piVar5 = piVar5 + 4;

        uVar9 = uVar9 - 1;

      } while (uVar9 != 0);

    }

    uVar6 = 1;

  }

  return uVar6;

}




