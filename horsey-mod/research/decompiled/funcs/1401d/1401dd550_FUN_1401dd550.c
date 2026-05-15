// Address: 0x1401dd550
// Ghidra name: FUN_1401dd550
// ============ 0x1401dd550 FUN_1401dd550 (size=296) ============


void FUN_1401dd550(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar2 = *(longlong *)(param_2 + 0x138);

  if (*(longlong *)(lVar1 + 0x160) == param_2) {

    *(undefined8 *)(lVar1 + 0x160) = 0;

    *(undefined4 *)(lVar1 + 0x184) = 0;

    *(undefined8 *)(lVar1 + 0x188) = 0;

    *(undefined1 *)(lVar1 + 400) = 0;

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x358))(*(longlong **)(lVar1 + 0x10),0);

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x208))(*(longlong **)(lVar1 + 0x10),0,0);

    if (*(longlong *)(param_2 + 0xe0) != 0) {

      (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x208))(*(longlong **)(lVar1 + 0x10),1,0);

    }

    if (lVar2 == 0) {

      return;

    }

    if (*(char *)(lVar2 + 0x48) != '\0') {

      (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x208))(*(longlong **)(lVar1 + 0x10),1,0);

      (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x208))(*(longlong **)(lVar1 + 0x10),2,0);

    }

  }

  else if (lVar2 == 0) {

    return;

  }

  FUN_1401dd680(lVar2);

  FUN_1401dd680(lVar2 + 0x50);

  FUN_1401dd680(lVar2 + 0x78);

  FUN_1401841e0(*(undefined8 *)(lVar2 + 0xa0));

  FUN_1401841e0(lVar2);

  *(undefined8 *)(param_2 + 0x138) = 0;

  return;

}




