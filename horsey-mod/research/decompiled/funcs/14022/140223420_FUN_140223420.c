// Address: 0x140223420
// Ghidra name: FUN_140223420
// ============ 0x140223420 FUN_140223420 (size=104) ============


undefined8 FUN_140223420(longlong param_1,int param_2)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if ((param_2 < 0) && (*(char *)(*(longlong *)(param_1 + 0x688) + 1) == '\0')) {

    uVar3 = FUN_14012e850("Negative swap interval unsupported in this GL");

    return uVar3;

  }

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x688) + 0x48);

  if (pcVar1 == (code *)0x0) {

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  iVar2 = (*pcVar1)(param_2);

  if (iVar2 == 0) {

    uVar3 = FUN_1401a9ed0("wglSwapIntervalEXT()");

    return uVar3;

  }

  return 1;

}




