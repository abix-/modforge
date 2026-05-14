// Address: 0x14021eb50
// Ghidra name: FUN_14021eb50
// ============ 0x14021eb50 FUN_14021eb50 (size=224) ============


bool FUN_14021eb50(undefined8 *param_1,longlong *param_2)



{

  char *pcVar1;

  undefined8 *puVar2;

  size_t sVar3;

  longlong lVar4;

  longlong lVar5;

  bool bVar6;

  

  lVar5 = 0;

  pcVar1 = (char *)*param_1;

  lVar4 = lVar5;

  puVar2 = param_1;

  while (pcVar1 != (char *)0x0) {

    sVar3 = strlen(pcVar1);

    puVar2 = puVar2 + 1;

    lVar4 = lVar4 + sVar3 + 1;

    pcVar1 = (char *)*puVar2;

  }

  lVar4 = FUN_1401841f0(lVar4 + 1);

  bVar6 = false;

  if (lVar4 != 0) {

    pcVar1 = (char *)*param_1;

    while (pcVar1 != (char *)0x0) {

      sVar3 = strlen(pcVar1);

      FUN_1402f8e20(lVar4 + lVar5,*param_1,sVar3);

      *(undefined1 *)(sVar3 + lVar4 + lVar5) = 0;

      param_1 = param_1 + 1;

      lVar5 = lVar5 + 1 + sVar3;

      pcVar1 = (char *)*param_1;

    }

    *(undefined1 *)(lVar4 + lVar5) = 0;

    lVar5 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,lVar4,lVar5);

    *param_2 = lVar5;

    FUN_1401841e0(lVar4);

    bVar6 = *param_2 != 0;

  }

  return bVar6;

}




