// Address: 0x140190640
// Ghidra name: thunk_FUN_1402e1f30
// ============ 0x140190640 thunk_FUN_1402e1f30 (size=5) ============


ulonglong thunk_FUN_1402e1f30(uint param_1)



{

  ulonglong uVar1;

  uint auStackX_8 [8];

  

  auStackX_8[0] = param_1;

  if (1 < DAT_1403e8ad0) {

    uVar1 = FUN_1402ecf90();

    return uVar1;

  }

  FUN_1402f1940(auStackX_8,0);

  return (ulonglong)auStackX_8[0];

}




