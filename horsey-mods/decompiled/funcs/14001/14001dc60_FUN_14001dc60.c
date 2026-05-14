// Address: 0x14001dc60
// Ghidra name: FUN_14001dc60
// ============ 0x14001dc60 FUN_14001dc60 (size=140) ============


void FUN_14001dc60(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined **local_48;

  undefined4 local_40;

  undefined4 local_3c;

  undefined2 local_18;

  

  local_40 = 1;

  local_48 = b2EdgeShape::vftable;

  local_3c = 0x3c23d70a;

  local_18 = 0;

  FUN_14000d080(*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),&local_48,

                *(undefined4 *)(param_1 + 0x70));

  FUN_1400210d0(param_2,&local_48,param_3,*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18),

                param_4);

  return;

}




