// Address: 0x1402854d0
// Ghidra name: FUN_1402854d0
// ============ 0x1402854d0 FUN_1402854d0 (size=226) ============


undefined8 FUN_1402854d0(longlong param_1,longlong param_2)



{

  undefined1 uVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined4 local_res8 [2];

  undefined1 local_28 [32];

  

  uVar1 = *(undefined1 *)(param_2 + 0x22);

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc68) = 1;

  iVar2 = (*DAT_1403fddf8)(uVar1,1,local_28);

  if (iVar2 != 0) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x148));

    *(undefined8 *)(param_1 + 0x148) = 0;

    uVar4 = FUN_14012e850("Failed to obtain XInput device capabilities. Device disconnected?");

    return uVar4;

  }

  local_res8[0] = 0;

  iVar2 = (*DAT_1403fddf0)(uVar1,local_res8);

  *(bool *)(*(longlong *)(param_1 + 0x148) + 0xc69) = iVar2 == 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc6a) = uVar1;

  *(undefined4 *)(param_1 + 0x44) = 6;

  *(undefined4 *)(param_1 + 0x70) = 0xb;

  *(undefined4 *)(param_1 + 0x60) = 1;

  uVar3 = FUN_140158c10(param_1);

  FUN_140175280(uVar3,"SDL.joystick.cap.rumble",1);

  return 1;

}




