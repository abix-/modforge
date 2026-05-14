// Address: 0x1400f6fa0
// Ghidra name: FUN_1400f6fa0
// ============ 0x1400f6fa0 FUN_1400f6fa0 (size=48) ============


undefined1 FUN_1400f6fa0(longlong param_1,int param_2)



{

  char cVar1;

  

  if (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) !=

      *(longlong *)(param_1 + 600)) {

    cVar1 = FUN_1400d5290();

    if (cVar1 == '\0') {

      return 0;

    }

  }

  return 1;

}




