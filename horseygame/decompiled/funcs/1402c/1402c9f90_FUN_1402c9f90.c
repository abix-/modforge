// Address: 0x1402c9f90
// Ghidra name: FUN_1402c9f90
// ============ 0x1402c9f90 FUN_1402c9f90 (size=186) ============


void FUN_1402c9f90(longlong param_1,longlong *param_2,int *param_3,longlong param_4)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  lVar3 = 0;

  if (-1 < *param_3) {

    param_2 = (longlong *)((longlong)param_3[2] + *param_2);

  }

  iVar1 = FUN_1402c9ba4();

  if (iVar1 == 1) {

    uVar2 = __AdjustPointer(*(undefined8 *)(param_1 + 0x28),param_4 + 8);

    iVar1 = *(int *)(param_4 + 0x18);

    if (iVar1 != 0) {

      lVar3 = FUN_1402c8e64();

      lVar3 = lVar3 + iVar1;

    }

    FUN_1402cc994(param_2,lVar3,uVar2);

  }

  else if (iVar1 == 2) {

    uVar2 = __AdjustPointer(*(undefined8 *)(param_1 + 0x28),param_4 + 8);

    iVar1 = *(int *)(param_4 + 0x18);

    if (iVar1 != 0) {

      lVar3 = FUN_1402c8e64();

      lVar3 = lVar3 + iVar1;

    }

    FUN_1402cc9a0(param_2,lVar3,uVar2,1);

  }

  return;

}




