// Address: 0x1400a8a70
// Ghidra name: FUN_1400a8a70
// ============ 0x1400a8a70 FUN_1400a8a70 (size=38) ============


undefined8 FUN_1400a8a70(longlong param_1,undefined1 *param_2)



{

  int iVar1;

  undefined8 uVar2;

  

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = 0;

  }

  iVar1 = *(int *)(param_1 + 0x24);

  if (iVar1 < 1) {

    return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

  }

  *(int *)(param_1 + 0x24) = iVar1 + -1;

  uVar2 = FUN_1400a8ba0(param_1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));

  return uVar2;

}




