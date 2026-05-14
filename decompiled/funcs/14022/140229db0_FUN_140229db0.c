// Address: 0x140229db0
// Ghidra name: FUN_140229db0
// ============ 0x140229db0 FUN_140229db0 (size=239) ============


undefined8 FUN_140229db0(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  HRESULT HVar3;

  int iVar4;

  LPVOID *ppv;

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  ppv = (LPVOID *)(*(longlong *)(lVar1 + 0xc0) + 0x390);

  if (*ppv == (LPVOID)0x0) {

    HVar3 = CoCreateInstance((IID *)&DAT_140398da8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_140398d98,ppv);

    if (HVar3 < 0) {

      FUN_1401a9ef0("Unable to create taskbar list",HVar3);

      return 0;

    }

    plVar2 = *(longlong **)(*(longlong *)(lVar1 + 0xc0) + 0x390);

    iVar4 = (**(code **)(*plVar2 + 0x18))(plVar2);

    if (iVar4 < 0) {

      (**(code **)(*plVar2 + 0x10))(plVar2);

      *(undefined8 *)(*(longlong *)(lVar1 + 0xc0) + 0x390) = 0;

      FUN_1401a9ef0("Unable to initialize taskbar list",iVar4);

      return 0;

    }

  }

  return *(undefined8 *)(*(longlong *)(lVar1 + 0xc0) + 0x390);

}




