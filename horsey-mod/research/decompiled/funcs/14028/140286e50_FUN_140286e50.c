// Address: 0x140286e50
// Ghidra name: FUN_140286e50
// ============ 0x140286e50 FUN_140286e50 (size=160) ============


undefined8 FUN_140286e50(short param_1,short param_2,undefined8 param_3)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  

  cVar1 = FUN_1402853c0();

  if ((cVar1 == '\0') && (cVar1 = FUN_14020a870(), cVar1 == '\0')) {

    return 0;

  }

  lVar3 = thunk_FUN_1402c9340(param_3,&DAT_140350290);

  if ((lVar3 == 0) && (iVar2 = FUN_140157b80(param_1,param_2,0,0), 1 < iVar2 - 2U)) {

    if (param_1 != 0x28de) {

      return 0;

    }

    return CONCAT71(0x11,param_2 == 0x11ff);

  }

  return 1;

}




