// Address: 0x140219df0
// Ghidra name: FUN_140219df0
// ============ 0x140219df0 FUN_140219df0 (size=139) ============


undefined1 FUN_140219df0(longlong param_1,undefined8 param_2)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  

  if (*(longlong *)(param_1 + 0x690) != 0) {

    uVar1 = FUN_14012e850("EGL context already created");

    return uVar1;

  }

  lVar3 = FUN_1401841a0(1,0x118);

  *(longlong *)(param_1 + 0x690) = lVar3;

  if (lVar3 != 0) {

    cVar2 = FUN_140219730(param_1,param_2);

    if (cVar2 != '\0') {

      return 1;

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x690));

    *(undefined8 *)(param_1 + 0x690) = 0;

  }

  return 0;

}




