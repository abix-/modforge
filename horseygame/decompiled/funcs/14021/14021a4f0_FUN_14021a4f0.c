// Address: 0x14021a4f0
// Ghidra name: FUN_14021a4f0
// ============ 0x14021a4f0 FUN_14021a4f0 (size=152) ============


void FUN_14021a4f0(longlong param_1,int param_2)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x690);

  if (lVar1 == 0) {

    FUN_14012e850("EGL not initialized");

    return;

  }

  if (param_2 < 0) {

    FUN_14012e850("Late swap tearing currently unsupported");

    return;

  }

  iVar2 = (**(code **)(lVar1 + 0xa0))(*(undefined8 *)(lVar1 + 0x10));

  if (iVar2 == 1) {

    *(int *)(*(longlong *)(param_1 + 0x690) + 0x20) = param_2;

    return;

  }

  uVar3 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

  FUN_14021a490("Unable to set the EGL swap interval","eglSwapInterval",uVar3);

  return;

}




