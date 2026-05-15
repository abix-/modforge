// Address: 0x14019f440
// Ghidra name: FUN_14019f440
// ============ 0x14019f440 FUN_14019f440 (size=200) ============


bool FUN_14019f440(longlong param_1,longlong param_2,int param_3)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  int iVar4;

  bool bVar5;

  

  plVar1 = (longlong *)(param_1 + 0xc0);

  lVar3 = (longlong)param_3;

  if ((*(longlong *)(param_1 + 0x10) == 0) ||

     (iVar4 = *(int *)(param_1 + 200) - *(int *)plVar1, param_3 <= iVar4)) {

    if (*(ulonglong *)(param_1 + 200) < (ulonglong)(lVar3 + *plVar1)) {

      bVar5 = false;

    }

    else {

      FUN_1402f8e20(param_2,*plVar1,lVar3);

      *plVar1 = *plVar1 + lVar3;

      bVar5 = true;

    }

  }

  else {

    FUN_1402f8e20(param_2,*plVar1,(longlong)iVar4);

    iVar2 = (**(code **)(param_1 + 0x10))

                      (*(undefined8 *)(param_1 + 0x28),iVar4 + param_2,param_3 - iVar4);

    bVar5 = iVar2 == param_3 - iVar4;

    *plVar1 = *(longlong *)(param_1 + 200);

  }

  return bVar5;

}




