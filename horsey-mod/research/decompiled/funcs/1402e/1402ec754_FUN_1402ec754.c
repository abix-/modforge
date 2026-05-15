// Address: 0x1402ec754
// Ghidra name: FUN_1402ec754
// ============ 0x1402ec754 FUN_1402ec754 (size=48) ============


bool FUN_1402ec754(void)



{

  BOOL BVar1;

  DWORD local_res8 [8];

  

  local_res8[0] = 0;

  BVar1 = VirtualProtect(&DAT_140424000,0x100,2,local_res8);

  return BVar1 != 0;

}




