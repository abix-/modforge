// Address: 0x140215240
// Ghidra name: FUN_140215240
// ============ 0x140215240 FUN_140215240 (size=362) ============


undefined8 FUN_140215240(code *param_1,undefined8 param_2,undefined1 *param_3)



{

  longlong *plVar1;

  undefined1 uVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 uVar6;

  undefined8 *puVar7;

  

  if (param_3 != (undefined1 *)0x0) {

    lVar4 = FUN_140163930(DAT_1403fdac8);

    lVar5 = FUN_14017ffb0();

    if (lVar5 == lVar4) {

      uVar2 = (*param_1)(param_2);

      *param_3 = uVar2;

      return 1;

    }

  }

  iVar3 = FUN_140138fe0(&DAT_1403fdae8);

  if (iVar3 != 0) {

    uVar6 = FUN_14012e850("Can\'t add task, we\'re shutting down");

    return uVar6;

  }

  puVar7 = (undefined8 *)FUN_1401841a0(1,0x30);

  if (puVar7 == (undefined8 *)0x0) {

    return 0;

  }

  *puVar7 = param_1;

  puVar7[1] = param_2;

  if (param_3 != (undefined1 *)0x0) {

    lVar4 = FUN_14017cda0(0);

    puVar7[3] = lVar4;

    if (lVar4 == 0) {

      FUN_1401841e0(puVar7);

      return 0;

    }

  }

  uVar6 = DAT_1403fdad8;

  puVar7[5] = 0;

  FUN_140179b40(uVar6);

  lVar4 = FUN_140138ff0(&DAT_1403fdad0);

  if (lVar4 != 0) {

    do {

      lVar5 = lVar4;

      plVar1 = (longlong *)(lVar5 + 0x28);

      lVar4 = *plVar1;

    } while (lVar4 != 0);

    if (lVar5 != 0) {

      *plVar1 = (longlong)puVar7;

      goto LAB_140215338;

    }

  }

  FUN_140139020(&DAT_1403fdad0,puVar7);

LAB_140215338:

  FUN_140160360(DAT_1403fdae0);

  FUN_140179b60(DAT_1403fdad8);

  if (param_3 != (undefined1 *)0x0) {

    FUN_140163d70(puVar7[3]);

    FUN_14017ce80(puVar7[3]);

    *param_3 = *(undefined1 *)(puVar7 + 2);

    if (puVar7[4] != 0) {

      FUN_14012e850(&DAT_14039bf30);

      FUN_1401841e0(puVar7[4]);

    }

    FUN_1401841e0(puVar7);

  }

  return 1;

}




