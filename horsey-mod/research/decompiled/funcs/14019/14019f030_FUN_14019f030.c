// Address: 0x14019f030
// Ghidra name: FUN_14019f030
// ============ 0x14019f030 FUN_14019f030 (size=31) ============


void FUN_14019f030(longlong param_1,longlong param_2,int param_3,undefined4 param_4,

                  undefined4 param_5)



{

  *(longlong *)(param_1 + 0x28) = param_2;

  *(longlong *)(param_1 + 0x20) = param_2;

  *(longlong *)(param_1 + 0x30) = param_3 + param_2;

  *(undefined4 *)(param_1 + 0x38) = param_4;

  FUN_1401a30f0(param_1,param_5);

  return;

}




