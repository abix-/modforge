// Address: 0x14022d440
// Ghidra name: FUN_14022d440
// ============ 0x14022d440 FUN_14022d440 (size=117) ============


undefined1 FUN_14022d440(longlong param_1,char param_2)



{

  longlong lVar1;

  char cVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  *(char *)(lVar1 + 0x129) = param_2;

  if (*(longlong *)(lVar1 + 0x138) == 0) {

    cVar2 = FUN_14022d5a0();

    if (cVar2 == '\0') {

      *(bool *)(lVar1 + 0x129) = param_2 == '\0';

      return 0;

    }

  }

  else {

    cVar2 = FUN_1402224b0();

    if (cVar2 == '\0') {

      *(bool *)(lVar1 + 0x129) = param_2 == '\0';

      return 0;

    }

  }

  return 1;

}




