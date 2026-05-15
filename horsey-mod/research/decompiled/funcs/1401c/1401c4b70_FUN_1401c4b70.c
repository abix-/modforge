// Address: 0x1401c4b70
// Ghidra name: FUN_1401c4b70
// ============ 0x1401c4b70 FUN_1401c4b70 (size=127) ============


void FUN_1401c4b70(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  FUN_1401c61c0();

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x1d8))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(*(longlong *)(param_1 + 0x110) + 0xa8),

             param_4,*(undefined8 *)(lVar1 + 0x10),param_3,0,0);

  FUN_1401cb5f0(param_1,lVar1);

  return;

}




