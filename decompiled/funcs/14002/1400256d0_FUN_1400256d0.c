// Address: 0x1400256d0
// Ghidra name: FUN_1400256d0
// ============ 0x1400256d0 FUN_1400256d0 (size=86) ============


undefined8 * FUN_1400256d0(longlong param_1,longlong param_2)



{

  char cVar1;

  char cVar2;

  longlong lVar3;

  char *pcVar4;

  longlong lVar5;

  

  lVar3 = *(longlong *)(param_1 + 0xd0);

  do {

    if (lVar3 == param_1 + 0x68) {

      return (undefined8 *)0x0;

    }

    pcVar4 = (char *)(lVar3 + 0x20);

    if (0xf < *(ulonglong *)(lVar3 + 0x38)) {

      pcVar4 = *(char **)pcVar4;

    }

    lVar5 = param_2 - (longlong)pcVar4;

    do {

      cVar1 = *pcVar4;

      cVar2 = pcVar4[lVar5];

      if (cVar1 != cVar2) break;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    if (cVar1 == cVar2) {

      if (*(ulonglong *)(lVar3 + 0x58) < 0x10) {

        return (undefined8 *)(lVar3 + 0x40);

      }

      return *(undefined8 **)(lVar3 + 0x40);

    }

    lVar3 = *(longlong *)(lVar3 + 0x68);

  } while( true );

}




