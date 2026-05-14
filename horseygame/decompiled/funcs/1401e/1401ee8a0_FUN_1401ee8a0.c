// Address: 0x1401ee8a0
// Ghidra name: FUN_1401ee8a0
// ============ 0x1401ee8a0 FUN_1401ee8a0 (size=187) ============


undefined8 FUN_1401ee8a0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined8 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401ebd30();

  if (*(char *)(lVar1 + 0x2e) == '\0') {

    uVar4 = FUN_14012e850("Render targets not supported by OpenGL");

    return uVar4;

  }

  *(undefined1 *)(lVar1 + 0x200) = 1;

  if (param_2 == 0) {

    (**(code **)(lVar1 + 0x1e8))(0x8d40,0);

  }

  else {

    puVar2 = *(undefined4 **)(param_2 + 0x138);

    (**(code **)(lVar1 + 0x1e8))(0x8d40,*(undefined4 *)(*(longlong *)(puVar2 + 0x1e) + 8));

    (**(code **)(lVar1 + 0x1e0))(0x8d40,0x8ce0,*(undefined4 *)(lVar1 + 0x28),*puVar2,0);

    iVar3 = (**(code **)(lVar1 + 0x1f0))(0x8d40);

    if (iVar3 != 0x8cd5) {

      uVar4 = FUN_14012e850("glFramebufferTexture2DEXT() failed");

      return uVar4;

    }

  }

  return 1;

}




