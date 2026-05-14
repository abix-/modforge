// Address: 0x1402c5010
// Ghidra name: FUN_1402c5010
// ============ 0x1402c5010 FUN_1402c5010 (size=175) ============


undefined1 FUN_1402c5010(undefined8 param_1,undefined8 param_2,undefined8 *param_3)



{

  undefined *puVar1;

  char cVar2;

  longlong *plVar3;

  longlong lVar4;

  

  cVar2 = FUN_1402c4ea0();

  if ((cVar2 != '\0') && (plVar3 = (longlong *)FUN_1401841a0(1,0x10), plVar3 != (longlong *)0x0)) {

    lVar4 = FUN_140179a30();

    *plVar3 = lVar4;

    if (lVar4 != 0) {

      lVar4 = FUN_14012c130(param_1,param_2);

      plVar3[1] = lVar4;

      puVar1 = PTR_LAB_140383a60;

      if (lVar4 != 0) {

        *param_3 = PTR_LAB_140383a58;

        param_3[1] = puVar1;

        puVar1 = PTR_LAB_140383a70;

        param_3[2] = PTR_LAB_140383a68;

        param_3[3] = puVar1;

        param_3[4] = PTR_FUN_140383a78;

        param_3[5] = plVar3;

        return 1;

      }

      FUN_140179b30(*plVar3);

    }

    FUN_1401841e0(plVar3);

  }

  return 0;

}




