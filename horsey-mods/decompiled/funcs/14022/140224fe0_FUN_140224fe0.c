// Address: 0x140224fe0
// Ghidra name: FUN_140224fe0
// ============ 0x140224fe0 FUN_140224fe0 (size=88) ============


void FUN_140224fe0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 in_XMM0_Da;

  

  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x188) + 8);

  if (lVar1 != *(longlong *)(param_1 + 0x150)) {

    *(longlong *)(param_1 + 0x150) = lVar1;

    in_XMM0_Da = 0;

    *(undefined8 *)(param_1 + 0x20c) = 0;

    *(undefined8 *)(param_1 + 0x214) = 0;

    *(undefined8 *)(param_1 + 0x21c) = 0;

    *(undefined4 *)(param_1 + 0x224) = 0;

    *(undefined8 *)(param_1 + 0x228) = 0;

    *(undefined8 *)(param_1 + 0x230) = 0;

    *(undefined8 *)(param_1 + 0x238) = 0;

    *(undefined8 *)(param_1 + 0x240) = 0;

  }

  FUN_140224e50(in_XMM0_Da,lVar1,param_2 + 0x13c,*(undefined4 *)(param_2 + 0x14c));

  return;

}




