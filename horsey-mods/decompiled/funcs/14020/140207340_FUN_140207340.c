// Address: 0x140207340
// Ghidra name: FUN_140207340
// ============ 0x140207340 FUN_140207340 (size=166) ============


void FUN_140207340(longlong param_1)



{

  int iVar1;

  

  if (*(longlong *)(param_1 + 0x68) != 0) {

    iVar1 = *(int *)(param_1 + 0x8c);

    while ((iVar1 != 0 && (*(undefined4 **)(param_1 + 0x90) != (undefined4 *)0x0))) {

      FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

      iVar1 = *(int *)(param_1 + 0x8c);

    }

    (**(code **)(*(longlong *)(param_1 + 0x68) + 0x90))(param_1);

    *(undefined8 *)(param_1 + 0x68) = 0;

    FUN_140179b40(*(undefined8 *)(param_1 + 0x78));

    if (*(longlong *)(param_1 + 0x80) != 0) {

      FUN_140192f70();

      *(undefined8 *)(param_1 + 0x80) = 0;

    }

    if (*(longlong *)(param_1 + 0x70) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0x70) = 0;

    }

    FUN_140179b60(*(undefined8 *)(param_1 + 0x78));

    return;

  }

  return;

}




