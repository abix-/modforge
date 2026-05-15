// Address: 0x14017f3c0
// Ghidra name: FUN_14017f3c0
// ============ 0x14017f3c0 FUN_14017f3c0 (size=45) ============


void FUN_14017f3c0(void)



{

  undefined1 *puVar1;

  

  while (DAT_1403fc670 != (undefined1 *)0x0) {

    puVar1 = *(undefined1 **)(DAT_1403fc670 + 0x28);

    *DAT_1403fc670 = 0;

    *(undefined4 *)(DAT_1403fc670 + 4) = 0;

    *(undefined8 *)(DAT_1403fc670 + 0x28) = 0;

    DAT_1403fc670 = puVar1;

  }

  DAT_1403fc670 = (undefined1 *)0x0;

  return;

}




