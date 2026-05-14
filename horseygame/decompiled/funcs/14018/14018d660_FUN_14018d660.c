// Address: 0x14018d660
// Ghidra name: FUN_14018d660
// ============ 0x14018d660 FUN_14018d660 (size=30) ============


undefined8 FUN_14018d660(HINSTANCE param_1,undefined8 param_2,LPCWSTR param_3,longlong param_4)



{

  HICON pHVar1;

  

  pHVar1 = LoadIconW(param_1,param_3);

  *(HICON *)(param_4 + 0x20) = pHVar1;

  return 0;

}




