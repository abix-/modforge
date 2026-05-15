// Address: 0x14001e1a0
// Ghidra name: FUN_14001e1a0
// ============ 0x14001e1a0 FUN_14001e1a0 (size=167) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_14001e1a0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined1 auStack_1a8 [32];

  undefined8 local_188;

  undefined8 local_180;

  undefined **local_178;

  undefined4 local_170;

  undefined4 local_16c;

  undefined2 local_148;

  undefined1 local_138 [256];

  ulonglong local_38;

  

  local_38 = DAT_1403e8b00 ^ (ulonglong)auStack_1a8;

  local_178 = b2EdgeShape::vftable;

  local_170 = 1;

  local_16c = 0x3c23d70a;

  local_148 = 0;

  FUN_14000d080(*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),&local_178,

                *(undefined4 *)(param_1 + 0x70));

  local_188 = *(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18);

  local_180 = param_4;

  FUN_140021550(local_138,param_2,&local_178,param_3);

  return;

}




