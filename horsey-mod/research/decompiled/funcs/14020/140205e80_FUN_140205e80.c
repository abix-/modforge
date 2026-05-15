// Address: 0x140205e80
// Ghidra name: FUN_140205e80
// ============ 0x140205e80 FUN_140205e80 (size=275) ============


undefined8

FUN_140205e80(longlong param_1,int *param_2,longlong param_3,int param_4,longlong param_5,

             int param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  

  iVar1 = param_2[2];

  iVar5 = 0;

  iVar2 = *(int *)(param_1 + 0xc);

  iVar6 = 0;

  lVar4 = (longlong)(iVar2 * param_2[1]) + (longlong)*param_2 + *(longlong *)(param_1 + 0x18);

  iVar3 = param_2[3];

  if (0 < iVar3) {

    do {

      FUN_1402f8e20(lVar4,param_3,(longlong)iVar1);

      iVar2 = *(int *)(param_1 + 0xc);

      param_3 = param_3 + param_4;

      iVar3 = param_2[3];

      lVar4 = lVar4 + iVar2;

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar3);

  }

  iVar1 = param_2[2];

  lVar4 = (longlong)(((iVar2 + 1) / 2) * param_2[1] + *param_2) +

          (longlong)(iVar2 * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18);

  iVar2 = (iVar3 + 1) / 2;

  if (0 < iVar2) {

    do {

      FUN_1402f8e20(lVar4,param_5,(longlong)((iVar1 + 1) / 2) * 2);

      param_5 = param_5 + param_6;

      iVar5 = iVar5 + 1;

      lVar4 = lVar4 + ((*(int *)(param_1 + 0xc) + 1) / 2) * 2;

      iVar2 = (param_2[3] + 1) / 2;

    } while (iVar5 < iVar2);

  }

  return CONCAT71((uint7)(uint3)((uint)iVar2 >> 8),1);

}




