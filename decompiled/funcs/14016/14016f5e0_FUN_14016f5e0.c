// Address: 0x14016f5e0
// Ghidra name: FUN_14016f5e0
// ============ 0x14016f5e0 FUN_14016f5e0 (size=85) ============


void FUN_14016f5e0(void)



{

  longlong lVar1;

  

  FUN_14013b4c0(0x106);

  if (DAT_1403fc410 != 0) {

    for (lVar1 = *(longlong *)(DAT_1403fc410 + 0x348); lVar1 != 0;

        lVar1 = *(longlong *)(lVar1 + 0x1a0)) {

      FUN_140183d70(lVar1);

      FUN_1401cda90(lVar1,0x20b,0,0);

    }

  }

  return;

}




