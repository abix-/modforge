// Address: 0x140025bc0
// Ghidra name: FUN_140025bc0
// ============ 0x140025bc0 FUN_140025bc0 (size=280) ============


void FUN_140025bc0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  longlong *plVar4;

  longlong lVar5;

  longlong lVar6;

  

  puVar3 = (undefined8 *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar3 = (undefined8 *)*puVar3;

  }

  lVar5 = -1;

  do {

    lVar5 = lVar5 + 1;

  } while (*(char *)((longlong)puVar3 + lVar5) != '\0');

  FUN_140027f50(param_2 + 0x38);

  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 8);

  lVar5 = *(longlong *)(param_1 + 0xd0);

  if (lVar5 != param_1 + 0x68) {

    do {

      if (lVar5 == 0) break;

      puVar3 = (undefined8 *)(lVar5 + 0x40);

      if (0xf < *(ulonglong *)(lVar5 + 0x58)) {

        puVar3 = (undefined8 *)*puVar3;

      }

      plVar4 = (longlong *)(lVar5 + 0x20);

      if (0xf < *(ulonglong *)(lVar5 + 0x38)) {

        plVar4 = (longlong *)*plVar4;

      }

      lVar1 = FUN_140027540(param_2 + 0x68,plVar4);

      if (lVar1 != 0) {

        lVar6 = -1;

        do {

          lVar6 = lVar6 + 1;

        } while (*(char *)((longlong)puVar3 + lVar6) != '\0');

        FUN_140027f50(lVar1 + 0x40,puVar3);

      }

      lVar5 = *(longlong *)(lVar5 + 0x68);

    } while ((*(longlong *)(lVar5 + 0x50) != 0) || (*(longlong *)(lVar5 + 0x30) != 0));

  }

  for (plVar4 = *(longlong **)(param_1 + 0x28); plVar4 != (longlong *)0x0;

      plVar4 = (longlong *)plVar4[0xc]) {

    uVar2 = (**(code **)(*plVar4 + 0x78))(plVar4);

    FUN_140025120(param_2,uVar2);

  }

  return;

}




