// Address: 0x1400b35f0
// Ghidra name: FUN_1400b35f0
// ============ 0x1400b35f0 FUN_1400b35f0 (size=89) ============


undefined1 FUN_1400b35f0(longlong param_1,longlong param_2)



{

  char cVar1;

  char *pcVar2;

  longlong lVar3;

  undefined1 uVar4;

  longlong lVar5;

  

  uVar4 = 0;

  pcVar2 = (char *)(param_1 + 0x2b8);

  lVar5 = 2;

  do {

    lVar3 = 0xf0;

    do {

      cVar1 = pcVar2[(param_2 - param_1) + -0x2b8];

      if ((cVar1 != -1) && (*pcVar2 != cVar1)) {

        *pcVar2 = cVar1;

        uVar4 = 1;

      }

      pcVar2 = pcVar2 + 1;

      lVar3 = lVar3 + -1;

    } while (lVar3 != 0);

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  return uVar4;

}




