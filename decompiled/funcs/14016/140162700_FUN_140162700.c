// Address: 0x140162700
// Ghidra name: FUN_140162700
// ============ 0x140162700 FUN_140162700 (size=121) ============


void FUN_140162700(void)



{

  longlong lVar1;

  longlong lVar2;

  longlong *plVar3;

  bool bVar4;

  

  lVar1 = FUN_1401611a0();

  bVar4 = *(longlong *)(lVar1 + 0x88) == 0;

  lVar2 = 0x120;

  if (bVar4) {

    lVar2 = 0x118;

  }

  plVar3 = *(longlong **)(lVar2 + lVar1);

  if ((bVar4) ||

     ((*(char *)(lVar1 + 0x128) != '\0' &&

      ((*(char *)(lVar1 + 0xc1) == '\0' || (*(char *)(lVar1 + 0xc3) == '\0')))))) {

    if ((plVar3 != (longlong *)0x0) && (lVar2 = *plVar3, lVar2 != 0)) {

      plVar3 = *(longlong **)(*(longlong *)(lVar2 + 0x10) + (longlong)*(int *)(lVar2 + 0xc) * 8);

    }

  }

  else {

    plVar3 = (longlong *)0x0;

  }

  if (*(code **)(lVar1 + 0x18) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140162771. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x18))(plVar3);

    return;

  }

  return;

}




