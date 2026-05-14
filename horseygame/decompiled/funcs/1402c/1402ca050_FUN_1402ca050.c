// Address: 0x1402ca050
// Ghidra name: FUN_1402ca050
// ============ 0x1402ca050 FUN_1402ca050 (size=187) ============


void FUN_1402ca050(longlong param_1,longlong *param_2,longlong param_3,longlong param_4)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  lVar3 = 0;

  if (-1 < *(int *)(param_3 + 4)) {

    param_2 = (longlong *)((ulonglong)*(uint *)(param_3 + 0xc) + *param_2);

  }

  iVar1 = FUN_1402c9d98();

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




