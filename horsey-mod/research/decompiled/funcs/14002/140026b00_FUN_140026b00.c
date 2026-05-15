// Address: 0x140026b00
// Ghidra name: FUN_140026b00
// ============ 0x140026b00 FUN_140026b00 (size=136) ============


longlong FUN_140026b00(longlong param_1)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined8 *puVar3;

  longlong lVar4;

  

  uVar1 = FUN_1402c704c(0x70);

  lVar2 = FUN_1400249e0(uVar1);

  if (lVar2 == 0) {

    return 0;

  }

  puVar3 = (undefined8 *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar3 = (undefined8 *)*puVar3;

  }

  lVar4 = -1;

  do {

    lVar4 = lVar4 + 1;

  } while (*(char *)((longlong)puVar3 + lVar4) != '\0');

  FUN_140027f50(lVar2 + 0x38);

  *(undefined8 *)(lVar2 + 0x10) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(param_1 + 8);

  *(undefined1 *)(lVar2 + 0x68) = *(undefined1 *)(param_1 + 0x68);

  return lVar2;

}




