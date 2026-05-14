// Address: 0x140283720
// Ghidra name: FUN_140283720
// ============ 0x140283720 FUN_140283720 (size=49) ============


undefined4 FUN_140283720(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = FUN_140284590(param_1,param_3,param_4);

  if (iVar1 != param_4) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




