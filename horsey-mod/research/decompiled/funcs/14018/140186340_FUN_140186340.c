// Address: 0x140186340
// Ghidra name: FUN_140186340
// ============ 0x140186340 FUN_140186340 (size=170) ============


undefined8 * FUN_140186340(int *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  

  if (param_1 != (int *)0x0) {

    *param_1 = 0;

  }

  FUN_140186540();

  lVar3 = (longlong)DAT_1403fcb5c;

  puVar1 = (undefined8 *)FUN_1401841f0(lVar3 * 8 + 8);

  if (puVar1 != (undefined8 *)0x0) {

    if (0 < lVar3) {

      lVar4 = 0;

      lVar5 = DAT_1403fcb60 - (longlong)puVar1;

      puVar2 = puVar1;

      do {

        lVar4 = lVar4 + 1;

        *puVar2 = **(undefined8 **)((longlong)puVar2 + lVar5);

        puVar2 = puVar2 + 1;

      } while (lVar4 < lVar3);

    }

    puVar1[lVar3] = 0;

    if (param_1 != (int *)0x0) {

      *param_1 = DAT_1403fcb5c;

    }

  }

  FUN_140186c50();

  return puVar1;

}




