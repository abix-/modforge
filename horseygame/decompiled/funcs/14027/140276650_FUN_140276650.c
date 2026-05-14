// Address: 0x140276650
// Ghidra name: FUN_140276650
// ============ 0x140276650 FUN_140276650 (size=99) ============


undefined1 FUN_140276650(longlong param_1,undefined8 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  char cVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  cVar3 = FUN_140208110(param_1,0);

  if (cVar3 == '\0') {

    return 0;

  }

  FUN_140276ad0(lVar1);

  uVar2 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  *param_2 = uVar2;

  *(undefined1 *)(lVar1 + 8) = 1;

  return 1;

}




