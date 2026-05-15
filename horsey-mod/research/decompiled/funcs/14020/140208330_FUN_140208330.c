// Address: 0x140208330
// Ghidra name: FUN_140208330
// ============ 0x140208330 FUN_140208330 (size=55) ============


ulonglong FUN_140208330(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0xa0);

  if (((lVar1 != 0) && (*(int *)(param_1 + 0x8c) == 1)) && (*(int *)(lVar1 + 0x8c) == 1)) {

    return (ulonglong)

           CONCAT31((int3)((uint)**(int **)(lVar1 + 0x90) >> 8),

                    **(int **)(param_1 + 0x90) != **(int **)(lVar1 + 0x90));

  }

  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

}




