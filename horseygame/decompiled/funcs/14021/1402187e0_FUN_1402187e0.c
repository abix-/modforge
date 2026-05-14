// Address: 0x1402187e0
// Ghidra name: FUN_1402187e0
// ============ 0x1402187e0 FUN_1402187e0 (size=121) ============


undefined8 FUN_1402187e0(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  if (*(longlong *)(param_1 + 0x690) == 0) {

    uVar3 = FUN_14012e850("EGL not initialized");

    return uVar3;

  }

  cVar1 = FUN_140219f80(param_1,1);

  if (cVar1 == '\0') {

    cVar1 = FUN_140219f80(param_1,0);

    if (cVar1 == '\0') {

      uVar2 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

      uVar3 = FUN_14021a490("Couldn\'t find matching EGL config","eglChooseConfig",uVar2);

      return uVar3;

    }

    FUN_14012e310("SDL_EGL_ChooseConfig: found a slow EGL config");

  }

  return 1;

}




