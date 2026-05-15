// Address: 0x140200a10
// Ghidra name: FUN_140200a10
// ============ 0x140200a10 FUN_140200a10 (size=235) ============


undefined8 FUN_140200a10(undefined8 param_1,longlong param_2,float *param_3,int param_4)



{

  float *pfVar1;

  uint uVar2;

  int *piVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  float *pfVar6;

  int iVar7;

  

  piVar3 = (int *)FUN_14014b940(param_1,(longlong)param_4 * 8,0,param_2 + 8);

  uVar4 = 0;

  if (piVar3 != (int *)0x0) {

    iVar7 = 0;

    *(longlong *)(param_2 + 0x10) = (longlong)param_4;

    if (3 < param_4) {

      uVar2 = (param_4 - 4U >> 2) + 1;

      uVar5 = (ulonglong)uVar2;

      iVar7 = uVar2 * 4;

      do {

        *piVar3 = (int)*param_3;

        piVar3[1] = (int)param_3[1];

        piVar3[2] = (int)param_3[2];

        piVar3[3] = (int)param_3[3];

        piVar3[4] = (int)param_3[4];

        piVar3[5] = (int)param_3[5];

        piVar3[6] = (int)param_3[6];

        pfVar6 = param_3 + 7;

        param_3 = param_3 + 8;

        piVar3[7] = (int)*pfVar6;

        piVar3 = piVar3 + 8;

        uVar5 = uVar5 - 1;

      } while (uVar5 != 0);

    }

    if (iVar7 < param_4) {

      uVar5 = (ulonglong)(uint)(param_4 - iVar7);

      pfVar6 = param_3;

      do {

        pfVar1 = pfVar6 + 2;

        *(int *)((longlong)piVar3 + (-8 - (longlong)param_3) + (longlong)pfVar1) = (int)*pfVar6;

        *(int *)((longlong)piVar3 + (-4 - (longlong)param_3) + (longlong)pfVar1) = (int)pfVar6[1];

        uVar5 = uVar5 - 1;

        pfVar6 = pfVar1;

      } while (uVar5 != 0);

    }

    uVar4 = 1;

  }

  return uVar4;

}




