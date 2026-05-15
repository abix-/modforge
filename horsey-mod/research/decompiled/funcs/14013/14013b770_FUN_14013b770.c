// Address: 0x14013b770
// Ghidra name: FUN_14013b770
// ============ 0x14013b770 FUN_14013b770 (size=160) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14013b770(code *param_1,undefined8 param_2)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  

  FUN_140179b40(DAT_1403fb660);

  _DAT_1403fb668 = param_1;

  _DAT_1403fb670 = param_2;

  if (param_1 != (code *)0x0) {

    FUN_140179b40(DAT_1403fbea0);

    lVar1 = DAT_1403fbeb8;

    while (lVar2 = lVar1, lVar2 != 0) {

      lVar1 = *(longlong *)(lVar2 + 0x90);

      cVar3 = (*param_1)(param_2,lVar2);

      if (cVar3 == '\0') {

        FUN_140139320(lVar2);

      }

    }

    FUN_140179b60(DAT_1403fbea0);

  }

  FUN_140179b60(DAT_1403fb660);

  return;

}




