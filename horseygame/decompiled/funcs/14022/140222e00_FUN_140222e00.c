// Address: 0x140222e00
// Ghidra name: FUN_140222e00
// ============ 0x140222e00 FUN_140222e00 (size=65) ============


void FUN_140222e00(longlong param_1,LPCSTR param_2)



{

  longlong lVar1;

  

  lVar1 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x10))(param_2);

  if (lVar1 == 0) {

    GetProcAddress(*(HMODULE *)(param_1 + 0x518),param_2);

  }

  return;

}




