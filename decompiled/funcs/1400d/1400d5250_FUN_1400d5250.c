// Address: 0x1400d5250
// Ghidra name: FUN_1400d5250
// ============ 0x1400d5250 FUN_1400d5250 (size=53) ============


undefined8 FUN_1400d5250(longlong param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if (lVar1 == *(longlong *)(param_1 + 0x148)) {

    cVar2 = FUN_1400b7650(lVar1);

    if (cVar2 != '\0') {

      return 0;

    }

  }

  return 1;

}




