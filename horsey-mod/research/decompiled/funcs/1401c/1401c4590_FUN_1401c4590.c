// Address: 0x1401c4590
// Ghidra name: FUN_1401c4590
// ============ 0x1401c4590 FUN_1401c4590 (size=117) ============


void FUN_1401c4590(longlong param_1,longlong param_2,undefined4 param_3)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  FUN_1401c5e90();

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x1d8))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(*(longlong *)(param_1 + 0x110) + 0xb8),

             1,*(undefined8 *)(lVar1 + 0x10),param_3,0,0);

  FUN_1401cb5f0(param_1,lVar1);

  return;

}




