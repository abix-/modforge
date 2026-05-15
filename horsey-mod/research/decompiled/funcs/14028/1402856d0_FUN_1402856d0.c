// Address: 0x1402856d0
// Ghidra name: FUN_1402856d0
// ============ 0x1402856d0 FUN_1402856d0 (size=161) ============


void FUN_1402856d0(longlong param_1)



{

  int iVar1;

  undefined2 local_res10 [12];

  int local_18 [4];

  

  if (DAT_1403fdde8 != (code *)0x0) {

    iVar1 = (*DAT_1403fdde8)(*(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc6a),local_18);

    if (iVar1 != 0x48f) {

      local_res10[0] = 0;

      if (DAT_1403fde08 != (code *)0x0) {

        (*DAT_1403fde08)(*(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc6a),0,local_res10);

      }

      if ((local_18[0] != 0) && (local_18[0] != *(int *)(*(longlong *)(param_1 + 0x148) + 0xc6c))) {

        FUN_140285800(param_1,local_18,local_res10);

        *(int *)(*(longlong *)(param_1 + 0x148) + 0xc6c) = local_18[0];

      }

    }

  }

  return;

}




