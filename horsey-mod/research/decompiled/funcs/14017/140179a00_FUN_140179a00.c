// Address: 0x140179a00
// Ghidra name: FUN_140179a00
// ============ 0x140179a00 FUN_140179a00 (size=21) ============


bool FUN_140179a00(LPCRITICAL_SECTION param_1)



{

  BOOL BVar1;

  

  BVar1 = TryEnterCriticalSection(param_1);

  return BVar1 == 1;

}




