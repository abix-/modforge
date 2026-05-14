// Address: 0x14005e820
// Ghidra name: FUN_14005e820
// ============ 0x14005e820 FUN_14005e820 (size=168) ============


undefined8 FUN_14005e820(longlong param_1)



{

  undefined8 uVar1;

  undefined4 local_res8;

  undefined4 local_resc;

  

  FUN_1400d0a00(param_1,0);

  if ((*(longlong *)(param_1 + 0x148) == 0) ||

     ((ulonglong)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3) < 2)) {

    *(undefined8 *)(param_1 + 0x260) = 0;

  }

  else {

    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x130) + 8);

    *(undefined8 *)(param_1 + 0x260) = uVar1;

    local_res8 = 0x41500000;

    local_resc = 0x40a00000;

    FUN_1400b6610(uVar1,&local_res8);

  }

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1,0,0);

  *(undefined8 *)(param_1 + 0x250) = 0;

  *(undefined1 *)(param_1 + 600) = 0;

  *(undefined2 *)(param_1 + 0x268) = 0;

  *(undefined4 *)(param_1 + 0x26c) = 0;

  return 1;

}




