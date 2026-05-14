// Address: 0x1401979c0
// Ghidra name: FUN_1401979c0
// ============ 0x1401979c0 FUN_1401979c0 (size=207) ============


undefined8 FUN_1401979c0(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  char *_Str1;

  longlong lVar2;

  undefined1 *puVar3;

  char *pcVar4;

  

  _Str1 = (char *)FUN_140179690("LC_ALL");

  if (_Str1 == (char *)0x0) {

    _Str1 = (char *)FUN_140179690("LC_CTYPE");

    if (_Str1 != (char *)0x0) goto LAB_140197a25;

    _Str1 = (char *)FUN_140179690("LC_MESSAGES");

    if (_Str1 != (char *)0x0) goto LAB_140197a25;

    _Str1 = (char *)FUN_140179690(&DAT_14033ae94);

    if (_Str1 != (char *)0x0) goto LAB_140197a25;

  }

  else {

LAB_140197a25:

    if (*_Str1 != '\0') {

      iVar1 = strcmp(_Str1,"C");

      if (iVar1 != 0) goto LAB_140197a44;

    }

  }

  _Str1 = "ASCII";

LAB_140197a44:

  lVar2 = thunk_FUN_1402c9190(_Str1,0x2e);

  pcVar4 = (char *)(lVar2 + 1);

  if (lVar2 == 0) {

    pcVar4 = _Str1;

  }

  FUN_14012f1a0(param_1,pcVar4,param_2);

  puVar3 = (undefined1 *)thunk_FUN_1402c9190(param_1,0x40);

  if (puVar3 != (undefined1 *)0x0) {

    *puVar3 = 0;

  }

  return param_1;

}




