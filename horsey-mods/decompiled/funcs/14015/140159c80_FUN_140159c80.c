// Address: 0x140159c80
// Ghidra name: FUN_140159c80
// ============ 0x140159c80 FUN_140159c80 (size=166) ============


void FUN_140159c80(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  longlong lVar1;

  

  *(undefined4 *)(param_1 + 8) = 0;

  *(undefined4 *)(param_1 + 0x20) = 0;

  if ((0 < *(int *)(param_1 + 0x30)) &&

     (lVar1 = FUN_1401841f0((longlong)*(int *)(param_1 + 0x30) << 2), lVar1 != 0)) {

    FUN_1402f8e20(lVar1,*(undefined8 *)(param_1 + 0x38),(longlong)*(int *)(param_1 + 0x30) << 2);

    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x30);

    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x30);

    *(longlong *)(param_1 + 0x10) = lVar1;

  }

  FUN_140159b50(param_2,param_1 + 8,param_1 + 0xc,param_1 + 0x10);

  FUN_140159b50(param_3,param_1 + 0x20,param_1 + 0x24,param_1 + 0x28);

  return;

}




