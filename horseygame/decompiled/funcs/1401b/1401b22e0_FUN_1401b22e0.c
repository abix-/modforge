// Address: 0x1401b22e0
// Ghidra name: FUN_1401b22e0
// ============ 0x1401b22e0 FUN_1401b22e0 (size=61) ============


undefined8 * FUN_1401b22e0(longlong param_1)



{

  undefined8 *puVar1;

  uint uVar2;

  

  if (*(int *)(param_1 + 0x840) == 0) {

    puVar1 = (undefined8 *)FUN_1401841f0();

    *(undefined4 *)(puVar1 + 1) = 0;

    *puVar1 = 0;

    return puVar1;

  }

  uVar2 = *(int *)(param_1 + 0x840) - 1;

  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x838) + (ulonglong)uVar2 * 8);

  *(uint *)(param_1 + 0x840) = uVar2;

  return puVar1;

}




