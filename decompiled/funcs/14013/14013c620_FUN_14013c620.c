// Address: 0x14013c620
// Ghidra name: FUN_14013c620
// ============ 0x14013c620 FUN_14013c620 (size=21) ============


uint FUN_14013c620(longlong param_1,longlong param_2)



{

  if (*(uint *)(param_1 + 0x10) != *(uint *)(param_2 + 0x10)) {

    return *(uint *)(param_2 + 0x10) & 0xffffff00;

  }

  return CONCAT31((int3)((uint)*(int *)(param_2 + 0x14) >> 8),

                  *(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14));

}




