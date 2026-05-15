// Address: 0x14021af40
// Ghidra name: FUN_14021af40
// ============ 0x14021af40 FUN_14021af40 (size=212) ============


void FUN_14021af40(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  longlong *plVar3;

  longlong *plVar4;

  

  FUN_140179b40(DAT_1403fdb78);

  plVar2 = (longlong *)0x0;

  plVar3 = DAT_1403fdb70;

  while( true ) {

    if (plVar3 == (longlong *)0x0) {

      FUN_140179b60(DAT_1403fdb78);

      return;

    }

    if (*plVar3 == param_1) break;

    plVar2 = plVar3;

    plVar3 = (longlong *)plVar3[1];

  }

  lVar1 = *(longlong *)(param_1 + 0x28);

  (**(code **)(*(longlong *)(lVar1 + 0x10) + 0x10))(lVar1);

  FUN_1401575b0(*(undefined8 *)(lVar1 + 8));

  plVar4 = (longlong *)plVar3[1];

  if (plVar3 != DAT_1403fdb70) {

    plVar2[1] = plVar3[1];

    plVar4 = DAT_1403fdb70;

  }

  DAT_1403fdb70 = plVar4;

  FUN_1401841e0(*(undefined8 *)(lVar1 + 0x18));

  FUN_1401841e0(lVar1);

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

  FUN_1401841e0(plVar3);

  FUN_140179b60(DAT_1403fdb78);

  return;

}




