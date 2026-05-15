// Address: 0x140286870
// Ghidra name: FUN_140286870
// ============ 0x140286870 FUN_140286870 (size=764) ============


undefined8 FUN_140286870(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined4 local_28;

  undefined4 local_24;

  undefined8 local_20;

  undefined4 local_18;

  

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x44) = 1;

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x18) = 0x2c;

  local_20 = 0;

  local_18 = 0;

  local_28 = 0x14;

  local_24 = 0x10;

  iVar2 = (**(code **)(*DAT_1403fde50 + 0x18))

                    (DAT_1403fde50,param_2 + 0x28,*(longlong *)(param_1 + 0x148) + 0x10,0);

  if (iVar2 < 0) {

    uVar4 = FUN_140286ef0("IDirectInput::CreateDevice",iVar2);

    return uVar4;

  }

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  iVar2 = (**(code **)(*plVar1 + 0x68))(plVar1,DAT_1403fcd60,9);

  if (iVar2 < 0) {

    uVar4 = FUN_140286ef0("IDirectInputDevice8::SetCooperativeLevel",iVar2);

    return uVar4;

  }

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  iVar2 = (**(code **)(*plVar1 + 0x58))(plVar1,&DAT_140380558);

  if (iVar2 < 0) {

    uVar4 = FUN_140286ef0("IDirectInputDevice8::SetDataFormat",iVar2);

    return uVar4;

  }

  if (DAT_1403fde49 == '\0') {

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    iVar2 = (**(code **)(*plVar1 + 0x18))(plVar1,*(longlong *)(param_1 + 0x148) + 0x18);

    if (iVar2 < 0) {

      uVar4 = FUN_140286ef0("IDirectInputDevice8::GetCapabilities",iVar2);

      return uVar4;

    }

  }

  if ((*(uint *)(*(longlong *)(param_1 + 0x148) + 0x1c) & 0x100) != 0) {

    iVar2 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    if (iVar2 < 0) {

      uVar4 = FUN_140286ef0("IDirectInputDevice8::Acquire",iVar2);

      return uVar4;

    }

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    (**(code **)(*plVar1 + 0xb0))(plVar1,1);

    iVar2 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x40))();

    if (iVar2 < 0) {

      uVar4 = FUN_140286ef0("IDirectInputDevice8::Unacquire",iVar2);

      return uVar4;

    }

    local_18 = 1;

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    (**(code **)(*plVar1 + 0x30))(plVar1,9,&local_28);

    uVar3 = FUN_140158c10(param_1);

    FUN_140175280(uVar3,"SDL.joystick.cap.rumble",1);

  }

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  (**(code **)(*plVar1 + 0x20))(plVar1,FUN_140285a70,param_1,0x1f);

  FUN_140286f30(param_1);

  local_20 = 0;

  local_18 = 0x80;

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  iVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,1,&local_28);

  if (iVar2 == 2) {

    *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x44) = 0;

  }

  else if (iVar2 < 0) {

    uVar4 = FUN_140286ef0("IDirectInputDevice8::SetProperty",iVar2);

    return uVar4;

  }

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x45) = 1;

  iVar2 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 200))();

  if ((iVar2 == -0x7ff8ffe2) || (iVar2 == -0x7ff8fff4)) {

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 200))();

  }

  FUN_1401492f0(0x32);

  return 1;

}




