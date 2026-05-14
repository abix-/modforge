// Address: 0x1401a4400
// Ghidra name: FUN_1401a4400
// ============ 0x1401a4400 FUN_1401a4400 (size=119) ============


void FUN_1401a4400(longlong param_1)



{

  undefined1 *puVar1;

  int iVar2;

  

  puVar1 = (undefined1 *)(param_1 + 0x38);

  iVar2 = (**(code **)(param_1 + 0x10))

                    (*(undefined8 *)(param_1 + 0x28),puVar1,*(undefined4 *)(param_1 + 0x34));

  *(int *)(param_1 + 0xb8) =

       *(int *)(param_1 + 0xb8) + (*(int *)(param_1 + 0xc0) - *(int *)(param_1 + 0xd0));

  *(undefined1 **)(param_1 + 0xc0) = puVar1;

  if (iVar2 == 0) {

    *(undefined4 *)(param_1 + 0x30) = 0;

    *(longlong *)(param_1 + 200) = param_1 + 0x39;

    *puVar1 = 0;

    return;

  }

  *(longlong *)(param_1 + 200) = (longlong)iVar2 + 0x38 + param_1;

  return;

}




