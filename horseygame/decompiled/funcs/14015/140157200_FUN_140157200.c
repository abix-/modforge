// Address: 0x140157200
// Ghidra name: FUN_140157200
// ============ 0x140157200 FUN_140157200 (size=375) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140157200(longlong param_1,char param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  char cVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  int *piVar9;

  ulonglong uVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  

  cVar5 = FUN_14017e460(0x8000);

  if (cVar5 != '\0') {

    piVar9 = (int *)FUN_140177270(0);

    if (piVar9 != (int *)0x0) {

      uVar10 = 0;

      iVar8 = *piVar9;

      while (iVar8 != 0) {

        if ((*(int *)(param_1 + 0xf4) == 0) && (iVar6 = FUN_1401771c0(iVar8), iVar6 == 1)) {

          FUN_14017e460(0x8000);

          *(int *)(param_1 + 0xf4) = iVar8;

          FUN_14015a190(param_1,1,0);

        }

        if ((*(int *)(param_1 + 0x100) == 0) && (iVar6 = FUN_1401771c0(iVar8), iVar6 == 2)) {

          FUN_14017e460(0x8000);

          *(int *)(param_1 + 0x100) = iVar8;

          FUN_14015a190(param_1,2,0);

        }

        uVar10 = (ulonglong)((int)uVar10 + 1);

        iVar8 = piVar9[uVar10];

      }

      FUN_1401841e0(piVar9);

    }

    FUN_14017e880(0x8000);

    uVar7 = FUN_14016dba0();

    iVar8 = FUN_14016daa0(uVar7);

    if (iVar8 == 1) {

      *(undefined4 *)(param_1 + 0x110) = 0x3f800000;

      *(undefined4 *)(param_1 + 300) = 0xbf800000;

    }

    else {

      *(undefined4 *)(param_1 + 0x114) = 0xbf800000;

      *(undefined4 *)(param_1 + 0x128) = 0xbf800000;

    }

    *(undefined4 *)(param_1 + 0x124) = 0x3f800000;

    fVar4 = _UNK_14033353c;

    fVar3 = _UNK_140333538;

    fVar2 = _UNK_140333534;

    fVar1 = _DAT_140333530;

    if (param_2 != '\0') {

      fVar11 = *(float *)(param_1 + 0x114) * _UNK_140333534;

      fVar12 = *(float *)(param_1 + 0x118) * _UNK_140333538;

      fVar13 = *(float *)(param_1 + 0x11c) * _UNK_14033353c;

      *(float *)(param_1 + 0x110) = *(float *)(param_1 + 0x110) * _DAT_140333530;

      *(float *)(param_1 + 0x114) = fVar11;

      *(float *)(param_1 + 0x118) = fVar12;

      *(float *)(param_1 + 0x11c) = fVar13;

      *(float *)(param_1 + 0x120) = *(float *)(param_1 + 0x120) * fVar1;

      *(float *)(param_1 + 0x124) = *(float *)(param_1 + 0x124) * fVar2;

      *(float *)(param_1 + 0x128) = *(float *)(param_1 + 0x128) * fVar3;

      *(float *)(param_1 + 300) = *(float *)(param_1 + 300) * fVar4;

      *(float *)(param_1 + 0x130) = *(float *)(param_1 + 0x130) * fVar1;

    }

  }

  return;

}




