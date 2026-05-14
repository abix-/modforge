// Address: 0x14006abf0
// Ghidra name: FUN_14006abf0
// ============ 0x14006abf0 FUN_14006abf0 (size=50) ============


undefined8 FUN_14006abf0(longlong param_1,int param_2)



{

  char cVar1;

  

  if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) + 0x204) ==

      '\0') {

    cVar1 = FUN_1400b7650();

    if (cVar1 != '\0') {

      return 0;

    }

  }

  return 1;

}




