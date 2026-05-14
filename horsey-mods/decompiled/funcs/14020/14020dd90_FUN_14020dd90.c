// Address: 0x14020dd90
// Ghidra name: FUN_14020dd90
// ============ 0x14020dd90 FUN_14020dd90 (size=151) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14020dd90(longlong param_1,ushort param_2,ushort param_3)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  plVar2 = *(longlong **)(lVar1 + 0x18);

  if (plVar2 == (longlong *)0x0) {

    uVar4 = FUN_14012e850("That operation is not supported");

    return uVar4;

  }

  *(double *)(lVar1 + 0x30) = (double)param_2 / _DAT_1403502f8;

  *(double *)(lVar1 + 0x38) = (double)param_3 / _DAT_1403502f8;

  local_28 = *(undefined8 *)(lVar1 + 0x20);

  uStack_20 = *(undefined8 *)(lVar1 + 0x28);

  local_18 = *(undefined4 *)(lVar1 + 0x30);

  uStack_14 = *(undefined4 *)(lVar1 + 0x34);

  uStack_10 = *(undefined4 *)(lVar1 + 0x38);

  uStack_c = *(undefined4 *)(lVar1 + 0x3c);

  iVar3 = (**(code **)(*plVar2 + 0x38))(plVar2,&local_28);

  if (-1 < iVar3) {

    return 1;

  }

  uVar4 = FUN_1401a9ef0("Windows.Gaming.Input.IGamepad.put_Vibration failed",iVar3);

  return uVar4;

}




