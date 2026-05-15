// Address: 0x14002f9b0
// Ghidra name: FUN_14002f9b0
// ============ 0x14002f9b0 FUN_14002f9b0 (size=95) ============


undefined1 FUN_14002f9b0(longlong param_1,int param_2,undefined4 param_3)



{

  char cVar1;

  

  cVar1 = FUN_1400b76a0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8));

  if (cVar1 == '\0') {

    cVar1 = FUN_1400d5250(param_1,param_2,param_3);

    if (cVar1 == '\0') {

      return 0;

    }

  }

  return 1;

}




