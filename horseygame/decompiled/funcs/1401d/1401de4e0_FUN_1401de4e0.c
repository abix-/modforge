// Address: 0x1401de4e0
// Ghidra name: FUN_1401de4e0
// ============ 0x1401de4e0 FUN_1401de4e0 (size=189) ============


undefined8 FUN_1401de4e0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(char *)(lVar1 + 0x61) == '\0') {

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x150))();

    *(undefined1 *)(lVar1 + 0x61) = 1;

  }

  iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x18))();

  if (iVar2 == -0x7789f798) {

    return 0;

  }

  if (iVar2 == -0x7789f797) {

    FUN_1401de770(param_1);

  }

  iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x88))(*(longlong **)(lVar1 + 0x10),0,0,0,0);

  if (iVar2 < 0) {

    uVar3 = FUN_1401df290("Present()",iVar2);

    return uVar3;

  }

  return 1;

}




