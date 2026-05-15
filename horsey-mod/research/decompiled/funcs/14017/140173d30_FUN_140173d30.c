// Address: 0x140173d30
// Ghidra name: FUN_140173d30
// ============ 0x140173d30 FUN_140173d30 (size=373) ============


void FUN_140173d30(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (DAT_1403fc410 == 0) {

    return;

  }

  *(undefined1 *)(DAT_1403fc410 + 0x39d) = 1;

  FUN_140186560();

  FUN_140162430();

  FUN_1401835c0();

  FUN_14017e880(0x4000);

  FUN_14016bbd0();

  lVar2 = *(longlong *)(DAT_1403fc410 + 0x348);

  lVar1 = DAT_1403fc410;

  while (DAT_1403fc410 = lVar1, lVar2 != 0) {

    FUN_14016b720(lVar2);

    lVar1 = DAT_1403fc410;

    lVar2 = *(longlong *)(DAT_1403fc410 + 0x348);

  }

  if ((*(int *)(lVar1 + 0x410) != 0) && (*(code **)(lVar1 + 0x1b0) != (code *)0x0)) {

    (**(code **)(lVar1 + 0x1b0))();

    lVar1 = DAT_1403fc410;

    *(undefined4 *)(DAT_1403fc410 + 0x410) = 0;

  }

  if ((*(int *)(lVar1 + 0x570) != 0) && (*(code **)(lVar1 + 0x200) != (code *)0x0)) {

    (**(code **)(lVar1 + 0x200))();

    lVar1 = DAT_1403fc410;

    *(undefined4 *)(DAT_1403fc410 + 0x570) = 0;

  }

  (**(code **)(lVar1 + 0x10))();

  lVar2 = (longlong)*(int *)(DAT_1403fc410 + 0x328);

  while (lVar2 != 0) {

    lVar2 = lVar2 + -1;

    FUN_14016b4e0(**(undefined4 **)(*(longlong *)(DAT_1403fc410 + 0x330) + lVar2 * 8),0);

  }

  FUN_1401841e0(*(undefined8 *)(DAT_1403fc410 + 0x330));

  *(undefined8 *)(DAT_1403fc410 + 0x330) = 0;

  FUN_140168fa0(0);

  lVar2 = DAT_1403fc410;

  if (*(longlong *)(DAT_1403fc410 + 0x388) != 0) {

    FUN_1401841e0(*(longlong *)(DAT_1403fc410 + 0x388));

    lVar2 = DAT_1403fc410;

    *(undefined8 *)(DAT_1403fc410 + 0x388) = 0;

  }

  (**(code **)(lVar2 + 0x6a0))();

  DAT_1403fc410 = 0;

  FUN_1401a8390();

  return;

}




