// Address: 0x1402f8aff
// Ghidra name: ImmSetCompositionStringW
// ============ 0x1402f8aff ImmSetCompositionStringW (size=6) ============


BOOL __stdcall

ImmSetCompositionStringW

          (HIMC param_1,DWORD dwIndex,LPVOID lpComp,DWORD dwCompLen,LPVOID lpRead,DWORD dwReadLen)



{

  BOOL BVar1;

  

                    /* WARNING: Could not recover jumptable at 0x0001402f8aff. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  BVar1 = ImmSetCompositionStringW(param_1,dwIndex,lpComp,dwCompLen,lpRead,dwReadLen);

  return BVar1;

}




