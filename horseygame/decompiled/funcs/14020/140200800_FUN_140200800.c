// Address: 0x140200800
// Ghidra name: FUN_140200800
// ============ 0x140200800 FUN_140200800 (size=90) ============


undefined8 FUN_140200800(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  longlong *plVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  lVar2 = *plVar1;

  if (lVar2 != 0) {

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(lVar2 + 8);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(*plVar1 + 0xc);

    }

    return 1;

  }

  if (*(longlong *)(param_1 + 0x118) != 0) {

    FUN_14016ebe0();

    return 1;

  }

  uVar3 = FUN_14012e850("Software renderer doesn\'t have an output surface");

  return uVar3;

}




