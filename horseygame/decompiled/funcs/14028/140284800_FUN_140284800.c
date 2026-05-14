// Address: 0x140284800
// Ghidra name: FUN_140284800
// ============ 0x140284800 FUN_140284800 (size=261) ============


void FUN_140284800(longlong param_1)



{

  longlong *plVar1;

  undefined1 local_res8 [8];

  

  FUN_140139010(param_1 + 4,0);

  if (*(longlong *)(param_1 + 8) != 0) {

    FUN_14017cea0(*(undefined8 *)(param_1 + 0x10));

    FUN_140163d80(*(undefined8 *)(param_1 + 8),local_res8);

    *(undefined8 *)(param_1 + 8) = 0;

  }

  FUN_140179b40(DAT_1403fddb8);

  plVar1 = *(longlong **)(param_1 + 0x20);

  while (plVar1 != (longlong *)0x0) {

    if (plVar1 == *(longlong **)(param_1 + 0x18)) {

      *(undefined8 *)(param_1 + 0x18) = 0;

    }

    *(longlong *)(param_1 + 0x20) = plVar1[0x14];

    if ((code *)plVar1[0x12] != (code *)0x0) {

      (*(code *)plVar1[0x12])(plVar1[0x13]);

    }

    FUN_140138fb0(*plVar1 + 0x88,0xffffffff);

    FUN_1401841e0(plVar1);

    plVar1 = *(longlong **)(param_1 + 0x20);

  }

  FUN_140179b60(DAT_1403fddb8);

  if (*(longlong *)(param_1 + 0x10) != 0) {

    FUN_14017ce80();

    *(longlong *)(param_1 + 0x10) = 0;

  }

  if (DAT_1403fddb8 != 0) {

    FUN_140179b30();

    DAT_1403fddb8 = 0;

  }

  FUN_140139010(param_1,0);

  return;

}




