// Address: 0x1401d3430
// Ghidra name: FUN_1401d3430
// ============ 0x1401d3430 FUN_1401d3430 (size=724) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401d3430(int param_1,int param_2,double param_3,undefined8 param_4,int *param_5,

                  double *param_6,double *param_7)



{

  uint uVar1;

  int iVar2;

  undefined8 uVar3;

  double dVar4;

  double dVar5;

  double dVar6;

  double dVar7;

  double dVar8;

  uint uVar9;

  uint uVar10;

  

  uVar3 = thunk_FUN_1402d0f80();

  dVar4 = (double)thunk_FUN_1402e3490();

  FUN_1401d3850();

  FUN_1401d3850();

  FUN_1401d3850();

  FUN_1401d3850();

  dVar5 = (double)thunk_FUN_1402d0290();

  dVar6 = (double)thunk_FUN_1402da530();

  dVar7 = (double)thunk_FUN_1402d0290();

  dVar8 = (double)thunk_FUN_1402da530();

  param_3 = param_3 / _DAT_14034a968;

  param_5[2] = (int)dVar6 - (int)dVar5;

  *param_5 = (int)dVar5;

  param_5[1] = (int)dVar7;

  uVar9 = (uint)uVar3 ^ (uint)DAT_140305470;

  uVar10 = (uint)((ulonglong)uVar3 >> 0x20) ^ DAT_140305470._4_4_;

  param_5[3] = (int)dVar8 - (int)dVar7;

  uVar1 = (uint)param_3;

  *param_7 = (double)CONCAT44(uVar10,uVar9);

  *param_6 = dVar4;

  if ((double)(int)uVar1 == param_3) {

    uVar1 = uVar1 & 0x80000003;

    if ((int)uVar1 < 0) {

      uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

    }

    uVar9 = uVar1 + 4;

    if (-1 < (int)uVar1) {

      uVar9 = uVar1;

    }

    if ((uVar9 & 1) == 0) {

      param_5[2] = param_1;

      param_5[3] = param_2;

      iVar2 = -1;

      if (uVar9 == 0) {

        iVar2 = 1;

      }

      *param_6 = (double)iVar2;

      *param_7 = 0.0;

    }

    else {

      param_5[2] = param_2;

      param_5[3] = param_1;

      *param_6 = 0.0;

      iVar2 = 1;

      if (uVar9 == 1) {

        iVar2 = -1;

      }

      *param_7 = (double)iVar2;

    }

  }

  return;

}




