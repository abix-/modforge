// Address: 0x1402f8b2f
// Ghidra name: VerQueryValueA
// ============ 0x1402f8b2f VerQueryValueA (size=6) ============


BOOL __stdcall VerQueryValueA(LPCVOID pBlock,LPCSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen)



{

  BOOL BVar1;

  

                    /* WARNING: Could not recover jumptable at 0x0001402f8b2f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  BVar1 = VerQueryValueA(pBlock,lpSubBlock,lplpBuffer,puLen);

  return BVar1;

}




