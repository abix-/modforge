// Address: 0x140037680
// Ghidra name: FUN_140037680
// ============ 0x140037680 FUN_140037680 (size=136) ============


void FUN_140037680(void)



{

  undefined *puVar1;

  longlong *plVar2;

  undefined1 *puVar3;

  longlong lVar4;

  undefined **ppuVar5;

  

  if (DAT_1403f3354 != '\0') {

    plVar2 = (longlong *)SteamInternal_ContextInit(&PTR_FUN_1403d4380);

    plVar2 = (longlong *)*plVar2;

    if (plVar2 != (longlong *)0x0) {

      puVar3 = &DAT_1403ea120;

      lVar4 = 0x1a;

      ppuVar5 = &PTR_DAT_1403d41e0;

      do {

        puVar1 = *ppuVar5;

        *puVar3 = 0;

        (**(code **)(*plVar2 + 0x28))(plVar2,puVar1,puVar3);

        puVar3 = puVar3 + 1;

        ppuVar5 = ppuVar5 + 2;

        lVar4 = lVar4 + -1;

      } while (lVar4 != 0);

    }

  }

  return;

}




