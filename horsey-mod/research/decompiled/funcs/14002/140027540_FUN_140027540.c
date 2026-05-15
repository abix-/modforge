// Address: 0x140027540
// Ghidra name: FUN_140027540
// ============ 0x140027540 FUN_140027540 (size=292) ============


undefined8 * FUN_140027540(undefined8 *param_1,longlong param_2)



{

  char cVar1;

  char cVar2;

  char *pcVar3;

  undefined8 *puVar4;

  longlong lVar5;

  

  puVar4 = (undefined8 *)param_1[0xd];

  do {

    if (puVar4 == param_1) {

LAB_140027598:

      puVar4 = (undefined8 *)FUN_1402c704c();

      lVar5 = -1;

      puVar4[1] = 0xffffffffffffffff;

      puVar4[2] = 0;

      *puVar4 = TiXmlAttribute::vftable;

      puVar4[4] = 0;

      puVar4[5] = 0;

      puVar4[6] = 0;

      puVar4[7] = 0xf;

      *(undefined1 *)(puVar4 + 4) = 0;

      puVar4[8] = 0;

      puVar4[9] = 0;

      puVar4[10] = 0;

      puVar4[0xb] = 0xf;

      *(undefined1 *)(puVar4 + 8) = 0;

      puVar4[3] = 0;

      puVar4[0xd] = 0;

      puVar4[0xc] = 0;

      FUN_1400272d0(param_1,puVar4);

      do {

        lVar5 = lVar5 + 1;

      } while (*(char *)(param_2 + lVar5) != '\0');

      FUN_140027f50(puVar4 + 4,param_2,lVar5);

      return puVar4;

    }

    pcVar3 = (char *)(puVar4 + 4);

    if (0xf < (ulonglong)puVar4[7]) {

      pcVar3 = *(char **)pcVar3;

    }

    lVar5 = param_2 - (longlong)pcVar3;

    do {

      cVar1 = *pcVar3;

      cVar2 = pcVar3[lVar5];

      if (cVar1 != cVar2) break;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    if (cVar1 == cVar2) {

      if (puVar4 != (undefined8 *)0x0) {

        return puVar4;

      }

      goto LAB_140027598;

    }

    puVar4 = (undefined8 *)puVar4[0xd];

  } while( true );

}




