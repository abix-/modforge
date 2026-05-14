// Address: 0x1402cfae8
// Ghidra name: FUN_1402cfae8
// ============ 0x1402cfae8 FUN_1402cfae8 (size=10) ============


void FUN_1402cfae8(uint param_1)



{

  code *pcVar1;

  

  common_end_thread(param_1);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




