// Address: 0x140223390
// Ghidra name: FUN_140223390
// ============ 0x140223390 FUN_140223390 (size=133) ============


undefined8 FUN_140223390(longlong param_1,longlong param_2,undefined8 param_3)



{

  int iVar1;

  undefined8 uVar2;

  

  if (*(longlong *)(param_1 + 0x688) == 0) {

    uVar2 = FUN_14012e850("OpenGL not initialized");

    return uVar2;

  }

  if ((param_2 == 0) && (param_2 = FUN_14016c700(), param_2 == 0)) {

    return 1;

  }

  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x28))

                    (*(undefined8 *)(*(longlong *)(param_2 + 0x188) + 0x18),param_3);

  if (iVar1 != 0) {

    return 1;

  }

  uVar2 = FUN_1401a9ed0("wglMakeCurrent()");

  return uVar2;

}




