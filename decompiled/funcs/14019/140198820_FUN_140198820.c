// Address: 0x140198820
// Ghidra name: FUN_140198820
// ============ 0x140198820 FUN_140198820 (size=135) ============


void FUN_140198820(undefined8 *param_1)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 1)) {

    lVar1 = 0;

    do {

      if ((*(longlong *)(lVar1 + param_1[2]) != 0) &&

         (*(longlong *)(*(longlong *)(lVar1 + param_1[2]) + 0x1028) != 0)) {

        FUN_140198820();

      }

      FUN_1401841e0(*(undefined8 *)(param_1[2] + lVar1));

      iVar2 = iVar2 + 1;

      lVar1 = lVar1 + 8;

    } while (iVar2 < *(int *)(param_1 + 1));

  }

  FUN_1401841e0(param_1[2]);

  DestroyMenu((HMENU)*param_1);

  FUN_1401841e0(param_1);

  return;

}




