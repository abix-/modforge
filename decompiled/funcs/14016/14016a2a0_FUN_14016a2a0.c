// Address: 0x14016a2a0
// Ghidra name: FUN_14016a2a0
// ============ 0x14016a2a0 FUN_14016a2a0 (size=99) ============


undefined8 FUN_14016a2a0(longlong param_1,undefined8 param_2)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x180),(longlong)*(int *)(param_1 + 0x17c) * 8 + 8

                       );

  if (lVar2 == 0) {

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0x17c);

  *(longlong *)(param_1 + 0x180) = lVar2;

  *(undefined8 *)(lVar2 + (longlong)iVar1 * 8) = param_2;

  *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;

  return CONCAT71((int7)(int3)((uint)iVar1 >> 8),1);

}




