// Address: 0x1400e03a0
// Ghidra name: FUN_1400e03a0
// ============ 0x1400e03a0 FUN_1400e03a0 (size=115) ============


undefined8 FUN_1400e03a0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  undefined **local_48;

  longlong local_40;

  undefined ***local_10;

  

  if ((*(longlong *)(param_1 + 0x138) - (longlong)*(undefined8 **)(param_1 + 0x130) &

      0xfffffffffffffff8U) == 8) {

    cVar1 = FUN_1400b7660(**(undefined8 **)(param_1 + 0x130),0,0);

    if (cVar1 != '\0') {

      return **(undefined8 **)(param_1 + 0x130);

    }

  }

  local_48 = &PTR_LAB_14030fbd0;

  local_10 = &local_48;

  local_40 = param_1;

  uVar2 = FUN_1400cfda0(param_1,&local_48);

  return uVar2;

}




