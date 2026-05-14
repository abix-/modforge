// Address: 0x1401e9d30
// Ghidra name: FUN_1401e9d30
// ============ 0x1401e9d30 FUN_1401e9d30 (size=167) ============


undefined8 FUN_1401e9d30(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (param_2 == 0) {

    lVar2 = *(longlong *)(lVar1 + 0x422b0);

    if (lVar2 != 0) {

      FUN_1401ea070(lVar1,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x18),0x80);

      *(undefined4 *)(*(longlong *)(lVar1 + 0x422b0) + 0x18) = 0x80;

    }

    *(undefined8 *)(lVar1 + 0x422b0) = 0;

    return 1;

  }

  lVar2 = *(longlong *)(param_2 + 0x138);

  if (*(longlong *)(lVar2 + 0x28) == 0) {

    uVar3 = FUN_14012e850("specified texture is not a render target");

    return uVar3;

  }

  *(longlong *)(lVar1 + 0x422b0) = lVar2;

  FUN_1401ea070(lVar1,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x18),4);

  *(undefined4 *)(*(longlong *)(lVar1 + 0x422b0) + 0x18) = 4;

  return 1;

}




