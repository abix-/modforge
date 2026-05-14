// Address: 0x14020dcf0
// Ghidra name: FUN_14020dcf0
// ============ 0x14020dcf0 FUN_14020dcf0 (size=147) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14020dcf0(longlong param_1,ushort param_2,ushort param_3)



{

  longlong lVar1;

  longlong *plVar2;

  undefined1 auVar3 [12];

  int iVar4;

  undefined8 uVar5;

  undefined4 uVar6;

  double local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  plVar2 = *(longlong **)(lVar1 + 0x18);

  if (plVar2 == (longlong *)0x0) {

    uVar5 = FUN_14012e850("That operation is not supported");

    return uVar5;

  }

  local_28 = (double)param_2 / _DAT_1403502f8;

  uVar6 = (undefined4)((ulonglong)((double)param_3 / _DAT_1403502f8) >> 0x20);

  auVar3._4_4_ = SUB84((double)param_3 / _DAT_1403502f8,0);

  auVar3._0_4_ = uVar6;

  auVar3._8_4_ = uVar6;

  uStack_20 = auVar3._4_8_;

  *(double *)(lVar1 + 0x20) = local_28;

  *(undefined8 *)(lVar1 + 0x28) = uStack_20;

  local_18 = *(undefined4 *)(lVar1 + 0x30);

  uStack_14 = *(undefined4 *)(lVar1 + 0x34);

  uStack_10 = *(undefined4 *)(lVar1 + 0x38);

  uStack_c = *(undefined4 *)(lVar1 + 0x3c);

  iVar4 = (**(code **)(*plVar2 + 0x38))(plVar2,&local_28);

  if (-1 < iVar4) {

    return 1;

  }

  uVar5 = FUN_1401a9ef0("Windows.Gaming.Input.IGamepad.put_Vibration failed",iVar4);

  return uVar5;

}




