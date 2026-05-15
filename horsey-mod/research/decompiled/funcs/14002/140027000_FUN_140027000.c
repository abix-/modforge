// Address: 0x140027000
// Ghidra name: FUN_140027000
// ============ 0x140027000 FUN_140027000 (size=200) ============


void FUN_140027000(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  longlong *plVar2;

  longlong lVar3;

  

  puVar1 = (undefined8 *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar1 = (undefined8 *)*puVar1;

  }

  lVar3 = -1;

  do {

    lVar3 = lVar3 + 1;

  } while (*(char *)((longlong)puVar1 + lVar3) != '\0');

  FUN_140027f50(param_2 + 0x38);

  plVar2 = (longlong *)(param_1 + 0x68);

  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 8);

  if ((longlong *)(param_2 + 0x68) != plVar2) {

    if (0xf < *(ulonglong *)(param_1 + 0x80)) {

      plVar2 = (longlong *)*plVar2;

    }

    FUN_140027f50(param_2 + 0x68,plVar2,*(undefined8 *)(param_1 + 0x78));

  }

  plVar2 = (longlong *)(param_1 + 0x88);

  if ((longlong *)(param_2 + 0x88) != plVar2) {

    if (0xf < *(ulonglong *)(param_1 + 0xa0)) {

      plVar2 = (longlong *)*plVar2;

    }

    FUN_140027f50(param_2 + 0x88,plVar2,*(undefined8 *)(param_1 + 0x98));

  }

  plVar2 = (longlong *)(param_1 + 0xa8);

  if ((longlong *)(param_2 + 0xa8) != plVar2) {

    if (0xf < *(ulonglong *)(param_1 + 0xc0)) {

      plVar2 = (longlong *)*plVar2;

    }

    FUN_140027f50(param_2 + 0xa8,plVar2,*(undefined8 *)(param_1 + 0xb8));

  }

  return;

}




