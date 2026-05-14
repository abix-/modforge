// Address: 0x140215e60
// Ghidra name: FUN_140215e60
// ============ 0x140215e60 FUN_140215e60 (size=188) ============


undefined8 FUN_140215e60(longlong param_1,undefined4 param_2,undefined8 param_3)



{

  undefined8 *puVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined8 local_28;

  undefined8 local_20;

  undefined8 uStack_18;

  

  plVar2 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x10);

  puVar1 = (undefined8 *)(*(longlong *)(param_1 + 200) + 0x18);

  local_2c = 0;

  local_20 = 0;

  uStack_18 = 0;

  local_38 = 0x28;

  local_34 = 0x80000000;

  local_30 = param_2;

  local_28 = param_3;

  iVar3 = (**(code **)(*plVar2 + 0x18))(plVar2,&local_38,puVar1,0);

  if (iVar3 != 0) {

    uVar4 = FUN_140216c30("DirectSound CreateCaptureBuffer",iVar3);

    return uVar4;

  }

  iVar3 = (**(code **)(*(longlong *)*puVar1 + 0x48))((longlong *)*puVar1,1);

  if (iVar3 != 0) {

    (**(code **)(*(longlong *)*puVar1 + 0x10))();

    uVar4 = FUN_140216c30("DirectSound Start",iVar3);

    return uVar4;

  }

  return 1;

}




