// Address: 0x1402ffa14
// Ghidra name: FUN_1402ffa14
// ============ 0x1402ffa14 FUN_1402ffa14 (size=89) ============


undefined4 FUN_1402ffa14(undefined8 param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  

  *(undefined8 *)(param_2 + 0x30) = param_1;

  *(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30);

  if (**(int **)(param_2 + 0x28) != -0x1f928c9d) {

    *(undefined4 *)(param_2 + 0x20) = 0;

    return *(undefined4 *)(param_2 + 0x20);

  }

  puVar2 = (undefined8 *)FUN_1402c9134();

  *puVar2 = *(undefined8 *)(param_2 + 0x28);

  uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);

  puVar2 = (undefined8 *)FUN_1402c9148();

  *puVar2 = uVar1;

                    /* WARNING: Subroutine does not return */

  FUN_1402cf8b8();

}




