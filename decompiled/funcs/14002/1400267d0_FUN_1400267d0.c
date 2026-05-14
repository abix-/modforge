// Address: 0x1400267d0
// Ghidra name: FUN_1400267d0
// ============ 0x1400267d0 FUN_1400267d0 (size=107) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1400267d0(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined1 auStack_78 [32];

  char local_58 [64];

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_78;

  FUN_1400276e0(local_58,0x40,&DAT_14039bf04,param_2);

  lVar2 = -1;

  do {

    lVar1 = lVar2 + 1;

    lVar2 = lVar2 + 1;

  } while (local_58[lVar1] != '\0');

  FUN_140027f50(param_1 + 0x40,local_58);

  return;

}




