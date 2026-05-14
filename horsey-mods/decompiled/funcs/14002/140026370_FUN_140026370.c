// Address: 0x140026370
// Ghidra name: FUN_140026370
// ============ 0x140026370 FUN_140026370 (size=216) ============


void FUN_140026370(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  longlong *plVar3;

  longlong lVar4;

  

  puVar2 = (undefined8 *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar2 = (undefined8 *)*puVar2;

  }

  lVar4 = -1;

  do {

    lVar4 = lVar4 + 1;

  } while (*(char *)((longlong)puVar2 + lVar4) != '\0');

  FUN_140027f50(param_2 + 0x38);

  plVar3 = (longlong *)(param_1 + 0x70);

  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 8);

  *(undefined1 *)(param_2 + 0x68) = *(undefined1 *)(param_1 + 0x68);

  *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x6c);

  if ((longlong *)(param_2 + 0x70) != plVar3) {

    if (0xf < *(ulonglong *)(param_1 + 0x88)) {

      plVar3 = (longlong *)*plVar3;

    }

    FUN_140027f50(param_2 + 0x70,plVar3,*(undefined8 *)(param_1 + 0x80));

  }

  *(undefined4 *)(param_2 + 0x90) = *(undefined4 *)(param_1 + 0x90);

  *(undefined8 *)(param_2 + 0x94) = *(undefined8 *)(param_1 + 0x94);

  *(undefined1 *)(param_2 + 0x9c) = *(undefined1 *)(param_1 + 0x9c);

  for (plVar3 = *(longlong **)(param_1 + 0x28); plVar3 != (longlong *)0x0;

      plVar3 = (longlong *)plVar3[0xc]) {

    uVar1 = (**(code **)(*plVar3 + 0x78))(plVar3);

    FUN_140025120(param_2,uVar1);

  }

  return;

}




