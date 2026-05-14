// Address: 0x1402e1580
// Ghidra name: FUN_1402e1580
// ============ 0x1402e1580 FUN_1402e1580 (size=288) ============


undefined8 FUN_1402e1580(void)



{

  longlong lVar1;

  longlong lVar2;

  undefined4 *puVar3;

  int iVar4;

  longlong lVar5;

  undefined *puVar6;

  

  lVar1 = 0;

  lVar5 = 3;

  if (DAT_1403fed28 == 0) {

    iVar4 = 0x200;

  }

  else {

    iVar4 = 3;

    if (2 < DAT_1403fed28) goto LAB_1402e15bd;

  }

  DAT_1403fed28 = iVar4;

LAB_1402e15bd:

  DAT_1403fed30 = _calloc_base((longlong)DAT_1403fed28,8);

  FUN_1402e9a80(0);

  if (DAT_1403fed30 == 0) {

    DAT_1403fed28 = 3;

    DAT_1403fed30 = _calloc_base(3,8);

    FUN_1402e9a80(0);

    if (DAT_1403fed30 == 0) {

      return 0xffffffff;

    }

  }

  puVar3 = &DAT_1403e8b78;

  puVar6 = &DAT_1403e8b60;

  lVar2 = lVar1;

  do {

    InitializeCriticalSectionEx((LPCRITICAL_SECTION)(puVar6 + 0x30),4000,0);

    *(undefined **)(lVar1 + DAT_1403fed30) = puVar6;

    if (*(longlong *)((&DAT_1403ff160)[lVar2 >> 6] + 0x28 + (ulonglong)((uint)lVar2 & 0x3f) * 0x48)

        + 2U < 3) {

      *puVar3 = 0xfffffffe;

    }

    lVar2 = lVar2 + 1;

    puVar6 = puVar6 + 0x58;

    lVar1 = lVar1 + 8;

    puVar3 = puVar3 + 0x16;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  return 0;

}




