// Address: 0x1401f3bd0
// Ghidra name: FUN_1401f3bd0
// ============ 0x1401f3bd0 FUN_1401f3bd0 (size=151) ============


undefined8 FUN_1401f3bd0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined8 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  *(undefined1 *)(lVar1 + 0x270) = 1;

  if (param_2 == 0) {

    (**(code **)(lVar1 + 0x180))(0x8d40,*(undefined4 *)(lVar1 + 0x1e0));

  }

  else {

    puVar2 = *(undefined4 **)(param_2 + 0x138);

    (**(code **)(lVar1 + 0x180))(0x8d40,*(undefined4 *)(*(longlong *)(puVar2 + 0x16) + 8));

    (**(code **)(lVar1 + 0x188))(0x8d40,0x8ce0,puVar2[2],*puVar2,0);

    iVar3 = (**(code **)(lVar1 + 400))(0x8d40);

    if (iVar3 != 0x8cd5) {

      uVar4 = FUN_14012e850("glFramebufferTexture2D() failed");

      return uVar4;

    }

  }

  return 1;

}




