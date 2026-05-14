// Address: 0x1402c50c0
// Ghidra name: FUN_1402c50c0
// ============ 0x1402c50c0 FUN_1402c50c0 (size=150) ============


undefined1 FUN_1402c50c0(undefined8 *param_1)



{

  undefined *puVar1;

  undefined *puVar2;

  char cVar3;

  longlong *plVar4;

  longlong lVar5;

  

  cVar3 = FUN_1402c4ea0();

  if (cVar3 != '\0') {

    plVar4 = (longlong *)FUN_1401841a0(1,0x98);

    if (plVar4 != (longlong *)0x0) {

      lVar5 = FUN_140179a30();

      *plVar4 = lVar5;

      if (lVar5 != 0) {

        lVar5 = FUN_140160230();

        plVar4[1] = lVar5;

        puVar1 = PTR_FUN_140383a30;

        if (lVar5 != 0) {

          *param_1 = PTR_FUN_140383a28;

          param_1[1] = puVar1;

          puVar1 = PTR_FUN_140383a40;

          param_1[2] = PTR_FUN_140383a38;

          param_1[3] = puVar1;

          puVar2 = PTR_FUN_140383a50;

          puVar1 = PTR_FUN_140383a48;

          param_1[6] = plVar4;

          param_1[4] = puVar1;

          param_1[5] = puVar2;

          return 1;

        }

        FUN_140179b30(*plVar4);

      }

      FUN_1401841e0(plVar4);

    }

  }

  return 0;

}




