// Address: 0x14015e240
// Ghidra name: FUN_14015e240
// ============ 0x14015e240 FUN_14015e240 (size=99) ============


undefined8 FUN_14015e240(undefined8 param_1,undefined4 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  

  uVar2 = 0;

  uVar3 = 0;

  lVar1 = FUN_14015cd00();

  if (lVar1 != 0) {

    uVar3 = *(undefined4 *)(lVar1 + 100);

    uVar2 = FUN_14015dd70(*(undefined8 *)(lVar1 + 0x70),uVar3);

  }

  FUN_14015d3e0(lVar1);

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = uVar3;

  }

  return uVar2;

}




