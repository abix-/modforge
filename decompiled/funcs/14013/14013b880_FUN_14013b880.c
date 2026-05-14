// Address: 0x14013b880
// Ghidra name: FUN_14013b880
// ============ 0x14013b880 FUN_14013b880 (size=331) ============


void FUN_14013b880(void)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  undefined8 *puVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  

  lVar3 = FUN_140142960("SDL_EVENT_QUEUE_STATISTICS");

  FUN_140179b40(DAT_1403fbea0);

  DAT_1403fbea8 = 0;

  lVar1 = DAT_1403fbeb8;

  if ((lVar3 != 0) && (iVar2 = thunk_FUN_1402d89dc(lVar3), lVar1 = DAT_1403fbeb8, iVar2 != 0)) {

    FUN_14012e310("SDL EVENT QUEUE: Maximum events in-flight: %d",DAT_1403fbeb0);

    lVar1 = DAT_1403fbeb8;

  }

  while (lVar3 = DAT_1403fbec8, lVar1 != 0) {

    lVar3 = *(longlong *)(lVar1 + 0x90);

    FUN_14013ba20(lVar1);

    FUN_1401841e0(lVar1);

    lVar1 = lVar3;

  }

  while (lVar3 != 0) {

    lVar3 = *(longlong *)(lVar3 + 0x90);

    FUN_1401841e0();

  }

  FUN_140139010(&DAT_1403fbeac,0);

  DAT_1403fbeb0 = 0;

  DAT_1403fbec8 = 0;

  DAT_1403fbeb8 = 0;

  DAT_1403fbec0 = 0;

  FUN_140139010(&DAT_1403fb690,0);

  puVar4 = &DAT_1403fb6a0;

  uVar7 = 0;

  do {

    FUN_1401841e0(*puVar4);

    uVar6 = (int)uVar7 + 1;

    uVar7 = (ulonglong)uVar6;

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  } while (uVar6 < 0x100);

  FUN_1401ce300(&DAT_1403fb660);

  FUN_1401cda20();

  uVar7 = DAT_1403fbea0;

  uVar5 = 0;

  if (DAT_1403fbea0 != 0) {

    DAT_1403fbea0 = 0;

    uVar5 = uVar7;

  }

  FUN_140179b60(uVar5);

  if (uVar5 != 0) {

    FUN_140179b30(uVar5);

  }

  return;

}




