// Address: 0x1402f8b29
// Ghidra name: GetFileVersionInfoA
// ============ 0x1402f8b29 GetFileVersionInfoA (size=6) ============


BOOL __stdcall GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData)



{

  BOOL BVar1;

  

                    /* WARNING: Could not recover jumptable at 0x0001402f8b29. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  BVar1 = GetFileVersionInfoA(lptstrFilename,dwHandle,dwLen,lpData);

  return BVar1;

}




