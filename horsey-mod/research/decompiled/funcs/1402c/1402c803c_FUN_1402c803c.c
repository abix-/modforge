// Address: 0x1402c803c
// Ghidra name: FUN_1402c803c
// ============ 0x1402c803c FUN_1402c803c (size=211) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402c803c(void)



{

  code *pcVar1;

  BOOL BVar2;

  undefined1 *puVar3;

  undefined1 auStack_38 [8];

  undefined1 auStack_30 [48];

  

  puVar3 = auStack_38;

  BVar2 = IsProcessorFeaturePresent(0x17);

  if (BVar2 != 0) {

    pcVar1 = (code *)swi(0x29);

    (*pcVar1)(2);

    puVar3 = auStack_30;

  }

  *(undefined8 *)(puVar3 + -8) = 0x1402c8067;

  FUN_1402c8110(&DAT_1403fe730);

  _DAT_1403fe6a0 = *(undefined8 *)(puVar3 + 0x38);

  _DAT_1403fe7c8 = puVar3 + 0x40;

  _DAT_1403fe7b0 = *(undefined8 *)(puVar3 + 0x40);

  _DAT_1403fe690 = 0xc0000409;

  _DAT_1403fe694 = 1;

  _DAT_1403fe6a8 = 1;

  DAT_1403fe6b0 = 2;

  *(undefined8 *)(puVar3 + 0x20) = DAT_1403e8b00;

  *(undefined8 *)(puVar3 + 0x28) = DAT_1403e8b40;

  *(undefined8 *)(puVar3 + -8) = 0x1402c8109;

  DAT_1403fe828 = _DAT_1403fe6a0;

  __raise_securityfailure(&PTR_DAT_1403872b0);

  return;

}




