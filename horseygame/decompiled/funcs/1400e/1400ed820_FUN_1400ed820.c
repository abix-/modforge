// Address: 0x1400ed820
// Ghidra name: FUN_1400ed820
// ============ 0x1400ed820 FUN_1400ed820 (size=107) ============


void FUN_1400ed820(longlong param_1)



{

  int iVar1;

  undefined1 *puVar2;

  

  iVar1 = (**(code **)(param_1 + 0x10))

                    (*(undefined8 *)(param_1 + 0x28),param_1 + 0x38,*(undefined4 *)(param_1 + 0x34))

  ;

  if (iVar1 == 0) {

    *(undefined4 *)(param_1 + 0x30) = 0;

    puVar2 = (undefined1 *)(*(longlong *)(param_1 + 0xc0) + -1);

    *(undefined1 **)(param_1 + 0xb8) = puVar2;

    *puVar2 = 0;

    return;

  }

  *(longlong *)(param_1 + 0xb8) = param_1 + 0x38;

  *(longlong *)(param_1 + 0xc0) = (longlong)iVar1 + 0x38 + param_1;

  return;

}




