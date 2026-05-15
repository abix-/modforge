// Address: 0x14016f720
// Ghidra name: FUN_14016f720
// ============ 0x14016f720 FUN_14016f720 (size=51) ============


undefined1 FUN_14016f720(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (DAT_1403fc410 != 0) {

    lVar1 = *(longlong *)(DAT_1403fc410 + 0x310);

    lVar2 = FUN_14017ffb0();

    if (lVar2 == lVar1) {

      return 1;

    }

  }

  return 0;

}




