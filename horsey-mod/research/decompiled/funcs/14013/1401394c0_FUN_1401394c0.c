// Address: 0x1401394c0
// Ghidra name: FUN_1401394c0
// ============ 0x1401394c0 FUN_1401394c0 (size=131) ============


void FUN_1401394c0(code *param_1,undefined8 param_2)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  

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

  return;

}




