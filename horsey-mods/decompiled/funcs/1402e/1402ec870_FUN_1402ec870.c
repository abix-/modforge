// Address: 0x1402ec870
// Ghidra name: FUN_1402ec870
// ============ 0x1402ec870 FUN_1402ec870 (size=66) ============


bool FUN_1402ec870(void)



{

  longlong lVar1;

  bool bVar2;

  

  if (DAT_140424018 == -1) {

    lVar1 = 0;

  }

  else {

    bVar2 = DAT_140424018 == 0;

    if (!bVar2) goto LAB_1402ec8aa;

    lVar1 = FUN_1402ec028(3,"FlsGetValue2",&DAT_14038ea10,"FlsGetValue2");

  }

  bVar2 = lVar1 == 0;

LAB_1402ec8aa:

  return !bVar2;

}




