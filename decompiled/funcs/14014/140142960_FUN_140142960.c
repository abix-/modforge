// Address: 0x140142960
// Ghidra name: FUN_140142960
// ============ 0x140142960 FUN_140142960 (size=126) ============


longlong FUN_140142960(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  undefined8 *puVar3;

  

  if (param_1 == 0) {

    return 0;

  }

  lVar2 = FUN_140142630();

  iVar1 = FUN_1401426c0(0);

  if (iVar1 != 0) {

    FUN_140175050(iVar1);

    puVar3 = (undefined8 *)FUN_140174d30(iVar1,param_1,0);

    if ((puVar3 != (undefined8 *)0x0) && ((lVar2 == 0 || (*(int *)(puVar3 + 1) == 2)))) {

      lVar2 = FUN_1401aa890(*puVar3);

    }

    FUN_1401755c0(iVar1);

  }

  return lVar2;

}




