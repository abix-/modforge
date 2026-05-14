// Address: 0x140198900
// Ghidra name: FUN_140198900
// ============ 0x140198900 FUN_140198900 (size=163) ============


undefined8 FUN_140198900(longlong param_1)



{

  char cVar1;

  undefined8 *puVar2;

  HMENU pHVar3;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,0xb);

      if (cVar1 == '\0') goto LAB_140198988;

    }

    puVar2 = (undefined8 *)FUN_1401841a0(1,0x28);

    *(undefined8 **)(param_1 + 0x3e0) = puVar2;

    if (puVar2 == (undefined8 *)0x0) {

      return 0;

    }

    pHVar3 = CreatePopupMenu();

    *puVar2 = pHVar3;

    *(longlong *)(*(longlong *)(param_1 + 0x3e0) + 0x18) = param_1;

    *(undefined8 *)(*(longlong *)(param_1 + 0x3e0) + 0x20) = 0;

    return *(undefined8 *)(param_1 + 0x3e0);

  }

LAB_140198988:

  FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b05c);

  return 0;

}




