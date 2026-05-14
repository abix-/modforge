// Address: 0x1402c53b0
// Ghidra name: FUN_1402c53b0
// ============ 0x1402c53b0 FUN_1402c53b0 (size=146) ============


undefined8 FUN_1402c53b0(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  longlong lVar2;

  int iVar3;

  undefined1 *puVar4;

  

  if (*(int *)(param_1 + 0x34) == *(int *)(param_1 + 0x30)) {

    iVar3 = *(int *)(param_1 + 0x30) + 4;

    lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x40),(longlong)iVar3 << 4);

    if (lVar2 == 0) {

      return 0;

    }

    *(longlong *)(param_1 + 0x40) = lVar2;

    *(int *)(param_1 + 0x30) = iVar3;

  }

  puVar4 = (undefined1 *)((longlong)*(int *)(param_1 + 0x34) * 0x10 + *(longlong *)(param_1 + 0x40))

  ;

  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;

  *puVar4 = *(undefined1 *)(param_1 + 0x10);

  *(undefined4 *)(puVar4 + 4) = param_2;

  uVar1 = *(undefined4 *)(param_1 + 0x38);

  *(undefined4 *)(puVar4 + 8) = uVar1;

  *(undefined4 *)(puVar4 + 0xc) = param_3;

  return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);

}




