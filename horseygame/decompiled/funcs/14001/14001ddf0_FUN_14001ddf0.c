// Address: 0x14001ddf0
// Ghidra name: FUN_14001ddf0
// ============ 0x14001ddf0 FUN_14001ddf0 (size=91) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_14001ddf0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined1 auStack_148 [32];

  undefined8 local_128;

  undefined8 local_120;

  undefined1 local_118 [256];

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_148;

  local_128 = *(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18);

  local_120 = param_4;

  FUN_140021550(local_118,param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_3);

  return;

}




