// Address: 0x140084b70
// Ghidra name: FUN_140084b70
// ============ 0x140084b70 FUN_140084b70 (size=51) ============


void FUN_140084b70(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  

  for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {

    FUN_140084670(lVar1,param_2);

  }

  return;

}




