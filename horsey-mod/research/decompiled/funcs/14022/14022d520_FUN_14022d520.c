// Address: 0x14022d520
// Ghidra name: FUN_14022d520
// ============ 0x14022d520 FUN_14022d520 (size=117) ============


undefined1 FUN_14022d520(longlong param_1,char param_2)



{

  longlong lVar1;

  char cVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  *(char *)(lVar1 + 0x128) = param_2;

  if (*(longlong *)(lVar1 + 0x138) == 0) {

    cVar2 = FUN_14022d5a0();

    if (cVar2 == '\0') {

      *(bool *)(lVar1 + 0x128) = param_2 == '\0';

      return 0;

    }

  }

  else {

    cVar2 = FUN_1402224b0();

    if (cVar2 == '\0') {

      *(bool *)(lVar1 + 0x128) = param_2 == '\0';

      return 0;

    }

  }

  return 1;

}




