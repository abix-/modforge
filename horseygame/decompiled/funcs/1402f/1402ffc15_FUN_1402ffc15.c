// Address: 0x1402ffc15
// Ghidra name: FUN_1402ffc15
// ============ 0x1402ffc15 FUN_1402ffc15 (size=144) ============


undefined4 FUN_1402ffc15(undefined8 param_1,longlong param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  *(undefined8 *)(param_2 + 0x30) = param_1;

  if (*(char *)(param_2 + 0x58) != '\0') {

    *(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30);

    if (((**(int **)(param_2 + 0x28) == -0x1f928c9d) &&

        (*(int *)(*(longlong *)(param_2 + 0x28) + 0x18) == 4)) &&

       ((*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930520 ||

        ((*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930521 ||

         (*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930522)))))) {

      lVar2 = FUN_1402c97f8();

      *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(param_2 + 0x28);

      uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);

      lVar2 = FUN_1402c97f8();

      *(undefined8 *)(lVar2 + 0x28) = uVar1;

                    /* WARNING: Subroutine does not return */

      FUN_1402cf8b8();

    }

  }

  *(undefined4 *)(param_2 + 0x20) = 0;

  return *(undefined4 *)(param_2 + 0x20);

}




