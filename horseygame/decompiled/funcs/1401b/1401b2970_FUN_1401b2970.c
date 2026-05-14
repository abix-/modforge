// Address: 0x1401b2970
// Ghidra name: FUN_1401b2970
// ============ 0x1401b2970 FUN_1401b2970 (size=126) ============


undefined8 FUN_1401b2970(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  uint uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  FUN_140179b40(*(undefined8 *)(lVar1 + 0x8e0));

  if (*(int *)(lVar1 + 0x830) == 0) {

    uVar2 = FUN_1401b85d0(lVar1,0x8000);

  }

  else {

    uVar3 = *(int *)(lVar1 + 0x830) - 1;

    uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x828) + (ulonglong)uVar3 * 8);

    *(uint *)(lVar1 + 0x830) = uVar3;

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0x8e0));

  FUN_1401bdcb0(param_1,uVar2);

  return uVar2;

}




