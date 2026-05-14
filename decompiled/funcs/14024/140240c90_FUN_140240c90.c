// Address: 0x140240c90
// Ghidra name: FUN_140240c90
// ============ 0x140240c90 FUN_140240c90 (size=109) ============


void FUN_140240c90(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 *puVar3;

  

  puVar3 = (undefined8 *)(param_1 + 0x130);

  lVar1 = param_1 + 0x84;

  lVar2 = 0xe;

  do {

    FUN_140240980(param_1,lVar1);

    FUN_1401841e0(*puVar3);

    lVar1 = lVar1 + 0xc;

    puVar3 = puVar3 + 1;

    lVar2 = lVar2 + -1;

  } while (lVar2 != 0);

  FUN_1401841e0(param_1);

  return;

}




