// Address: 0x14004ef90
// Ghidra name: FUN_14004ef90
// ============ 0x14004ef90 FUN_14004ef90 (size=123) ============


void FUN_14004ef90(void)



{

  longlong lVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  longlong lVar4;

  longlong lVar5;

  

  puVar2 = (undefined8 *)_malloc_base(0x10008);

  lVar5 = 0x400;

  puVar3 = puVar2 + 1;

  do {

    lVar4 = DAT_1403ea2a8;

    puVar3[6] = *(undefined8 *)(DAT_1403ea2a8 + 0xa8);

    puVar3[7] = 0;

    lVar1 = *(longlong *)(lVar4 + 0xa8);

    if (lVar1 != 0) {

      *(undefined8 **)(lVar1 + 0x38) = puVar3;

      lVar4 = DAT_1403ea2a8;

    }

    *(undefined8 **)(lVar4 + 0xa8) = puVar3;

    lVar1 = DAT_1403ea2a8;

    puVar3 = puVar3 + 8;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  *puVar2 = *(undefined8 *)(DAT_1403ea2a8 + 0x98);

  *(undefined8 **)(lVar1 + 0x98) = puVar2;

  return;

}




