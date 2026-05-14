// Address: 0x14014ddb0
// Ghidra name: FUN_14014ddb0
// ============ 0x14014ddb0 FUN_14014ddb0 (size=123) ============


void FUN_14014ddb0(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  

  if (*(longlong *)(param_1 + 0x248) == 0) {

    plVar2 = (longlong *)(param_1 + 0x250);

  }

  else {

    *(undefined8 *)(*(longlong *)(param_1 + 0x248) + 0x50) = *(undefined8 *)(param_1 + 0x250);

    plVar2 = (longlong *)(param_1 + 0x240);

  }

  lVar1 = *plVar2;

  *(undefined8 *)(param_1 + 0x250) = 0;

  *(undefined8 *)(param_1 + 0x248) = 0;

  *(undefined8 *)(param_1 + 0x240) = 0;

  *(undefined8 *)(param_1 + 0x2a0) = 0;

  while (lVar1 != 0) {

    lVar1 = *(longlong *)(lVar1 + 0x50);

    FUN_1401841e0();

  }

  return;

}




