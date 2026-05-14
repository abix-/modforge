// Address: 0x1400d8920
// Ghidra name: FUN_1400d8920
// ============ 0x1400d8920 FUN_1400d8920 (size=44) ============


void FUN_1400d8920(longlong *param_1)



{

  longlong *plVar1;

  

  plVar1 = (longlong *)param_1[7];

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x20))(plVar1,plVar1 != param_1);

    param_1[7] = 0;

  }

  return;

}




