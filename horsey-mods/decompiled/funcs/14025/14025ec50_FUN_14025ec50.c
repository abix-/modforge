// Address: 0x14025ec50
// Ghidra name: FUN_14025ec50
// ============ 0x14025ec50 FUN_14025ec50 (size=56) ============


code * FUN_14025ec50(longlong param_1)



{

  char cVar1;

  code *pcVar2;

  

  cVar1 = *(char *)(param_1 + 5);

  if (cVar1 == '\x01') {

    pcVar2 = FUN_14025ec90;

    if (*(byte *)(param_1 + 4) < 8) {

      pcVar2 = (code *)0x0;

    }

    return pcVar2;

  }

  if (cVar1 != '\x02') {

    if (cVar1 != '\x04') {

      return (code *)0x0;

    }

    return FUN_14025f570;

  }

  return FUN_14025eff0;

}




