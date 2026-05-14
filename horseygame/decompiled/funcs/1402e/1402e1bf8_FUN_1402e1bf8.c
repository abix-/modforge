// Address: 0x1402e1bf8
// Ghidra name: FUN_1402e1bf8
// ============ 0x1402e1bf8 FUN_1402e1bf8 (size=85) ============


void FUN_1402e1bf8(void)



{

  code *pcVar1;

  longlong lVar2;

  BOOL BVar3;

  undefined1 *puVar4;

  undefined1 auStack_28 [8];

  undefined1 auStack_20 [32];

  

  puVar4 = auStack_28;

  lVar2 = __acrt_get_sigabrt_handler();

  if (lVar2 != 0) {

    FUN_1402e6268(0x16);

  }

  if ((DAT_1403e8c68 & 2) != 0) {

    BVar3 = IsProcessorFeaturePresent(0x17);

    puVar4 = auStack_28;

    if (BVar3 != 0) {

      pcVar1 = (code *)swi(0x29);

      (*pcVar1)(7);

      puVar4 = auStack_20;

    }

    *(undefined8 *)(puVar4 + -8) = 0x1402e1c43;

    FUN_1402cd188(3,0x40000015);

  }

                    /* WARNING: Subroutine does not return */

  *(undefined **)(puVar4 + -8) = &UNK_1402e1c4d;

  FUN_1402da20c(3);

}




