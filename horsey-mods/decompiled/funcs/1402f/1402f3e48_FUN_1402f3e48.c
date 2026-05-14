// Address: 0x1402f3e48
// Ghidra name: FUN_1402f3e48
// ============ 0x1402f3e48 FUN_1402f3e48 (size=152) ============


void FUN_1402f3e48(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined2 *puVar3;

  longlong lVar4;

  

  FUN_1402f94c0(param_1 + 0x18,0,0x101);

  lVar2 = 0;

  *(undefined8 *)(param_1 + 4) = 0;

  *(undefined8 *)(param_1 + 0x220) = 0;

  puVar3 = (undefined2 *)(param_1 + 0xc);

  for (lVar1 = 6; lVar4 = lVar2, lVar1 != 0; lVar1 = lVar1 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  do {

    lVar1 = lVar4 + 1;

    *(undefined1 *)(param_1 + lVar4 + 0x18) = (&DAT_1403e91b8)[lVar4];

    lVar4 = lVar1;

  } while (lVar1 < 0x101);

  do {

    lVar1 = lVar2 + 1;

    *(undefined1 *)(param_1 + lVar2 + 0x119) = (&DAT_1403e92b9)[lVar2];

    lVar2 = lVar1;

  } while (lVar1 < 0x100);

  return;

}




