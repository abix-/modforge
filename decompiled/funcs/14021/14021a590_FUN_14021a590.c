// Address: 0x14021a590
// Ghidra name: FUN_14021a590
// ============ 0x14021a590 FUN_14021a590 (size=81) ============


undefined8 FUN_14021a590(longlong param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0x98))

                    (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10));

  if (iVar1 == 0) {

    uVar2 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

    uVar3 = FUN_14021a490("unable to show color buffer in an OS-native window","eglSwapBuffers",

                          uVar2);

    return uVar3;

  }

  return 1;

}




