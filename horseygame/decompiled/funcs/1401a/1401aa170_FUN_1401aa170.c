// Address: 0x1401aa170
// Ghidra name: FUN_1401aa170
// ============ 0x1401aa170 FUN_1401aa170 (size=81) ============


void FUN_1401aa170(UINT param_1,uint param_2,LPCWSTR param_3,int param_4,LPSTR param_5,int param_6,

                  LPCSTR param_7,LPBOOL param_8)



{

  int iVar1;

  uint dwFlags;

  

  iVar1 = FUN_1401a99d0();

  dwFlags = param_2 & 0xffffff7f;

  if (iVar1 == 0) {

    dwFlags = param_2;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401aa1ba. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  WideCharToMultiByte(param_1,dwFlags,param_3,param_4,param_5,param_6,param_7,param_8);

  return;

}




