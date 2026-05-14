// Address: 0x140028590
// Ghidra name: FUN_140028590
// ============ 0x140028590 FUN_140028590 (size=76) ============


void FUN_140028590(longlong *param_1)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = (longlong)*(int *)(*param_1 + 4);

  if ((*(int *)(lVar2 + 0x10 + (longlong)param_1) == 0) &&

     ((*(byte *)(lVar2 + 0x18 + (longlong)param_1) & 2) != 0)) {

    iVar1 = (**(code **)(**(longlong **)(lVar2 + 0x48 + (longlong)param_1) + 0x68))();

    if (iVar1 == -1) {

      FUN_140028370((longlong)*(int *)(*param_1 + 4) + (longlong)param_1,4,0);

    }

  }

  return;

}




