// Address: 0x140167620
// Ghidra name: FUN_140167620
// ============ 0x140167620 FUN_140167620 (size=206) ============


longlong * FUN_140167620(undefined8 param_1,undefined8 param_2)



{

  char cVar1;

  longlong *plVar2;

  longlong lVar3;

  

  FUN_140211380();

  FUN_140214580();

  plVar2 = (longlong *)FUN_1401841a0(1,0xe8);

  if (plVar2 != (longlong *)0x0) {

    *(undefined4 *)(plVar2 + 0xb) = 0x3f800000;

    *(undefined4 *)((longlong)plVar2 + 0x5c) = 0x3f800000;

    lVar3 = FUN_140217b90(0x2000);

    plVar2[0xc] = lVar3;

    if (lVar3 != 0) {

      lVar3 = FUN_140179a30();

      *plVar2 = lVar3;

      if (lVar3 != 0) {

        FUN_14015ce00(plVar2);

        cVar1 = FUN_140168290(plVar2,param_1,param_2);

        if (cVar1 == '\0') {

          FUN_1401676f0(plVar2);

          return (longlong *)0x0;

        }

        return plVar2;

      }

      FUN_1401841e0(plVar2[0xc]);

    }

    FUN_1401841e0(plVar2);

  }

  return (longlong *)0x0;

}




