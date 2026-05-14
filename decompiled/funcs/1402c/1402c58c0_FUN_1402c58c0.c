// Address: 0x1402c58c0
// Ghidra name: FUN_1402c58c0
// ============ 0x1402c58c0 FUN_1402c58c0 (size=62) ============


ulonglong FUN_1402c58c0(int *param_1,undefined2 param_2,undefined2 param_3)



{

  int iVar1;

  int *in_RAX;

  longlong lVar2;

  

  if (param_1 != (int *)0x0) {

    iVar1 = *param_1;

    in_RAX = (int *)(longlong)iVar1;

    if (0 < iVar1) {

      lVar2 = 0;

      in_RAX = (int *)(*(longlong *)(param_1 + 2) + 4);

      do {

        if (*in_RAX == CONCAT22(param_2,param_3)) {

          return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);

        }

        lVar2 = lVar2 + 1;

        in_RAX = in_RAX + 4;

      } while (lVar2 < iVar1);

    }

  }

  return (ulonglong)in_RAX & 0xffffffffffffff00;

}




