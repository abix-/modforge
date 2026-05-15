// Address: 0x1401e8fd0
// Ghidra name: FUN_1401e8fd0
// ============ 0x1401e8fd0 FUN_1401e8fd0 (size=248) ============


void FUN_1401e8fd0(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  undefined8 local_18;

  undefined8 local_10;

  

  local_18 = *(undefined8 *)(param_1 + 0x80);

  local_10 = *(undefined8 *)(param_1 + 0x90);

  plVar1 = *(longlong **)(param_1 + 0xa0 + (longlong)*(int *)(param_1 + 200) * 8);

  (**(code **)(*plVar1 + 0x40))(plVar1);

  (**(code **)(**(longlong **)(param_1 + 0x48) + 0x50))(*(longlong **)(param_1 + 0x48),plVar1,0);

  iVar2 = 0;

  *(undefined1 *)(param_1 + 0x422e0) = 1;

  *(undefined8 *)(param_1 + 0x108) = 0;

  *(undefined4 *)(param_1 + 0x4234c) = 0;

  *(undefined1 *)(param_1 + 0x42350) = 0;

  *(undefined1 *)(param_1 + 0x42308) = 1;

  *(undefined8 *)(param_1 + 0x422b8) = 0;

  if (0 < *(int *)(param_1 + 0x2258)) {

    plVar1 = (longlong *)(param_1 + 0x2158);

    do {

      if ((longlong *)*plVar1 != (longlong *)0x0) {

        (**(code **)(*(longlong *)*plVar1 + 0x10))();

        *plVar1 = 0;

      }

      iVar2 = iVar2 + 1;

      plVar1 = plVar1 + 1;

    } while (iVar2 < *(int *)(param_1 + 0x2258));

  }

  *(undefined4 *)(param_1 + 0x2258) = 0;

  (**(code **)(**(longlong **)(param_1 + 0x48) + 0xe0))(*(longlong **)(param_1 + 0x48),2,&local_18);

  return;

}




