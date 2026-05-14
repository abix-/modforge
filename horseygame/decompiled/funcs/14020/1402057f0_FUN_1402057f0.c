// Address: 0x1402057f0
// Ghidra name: FUN_1402057f0
// ============ 0x1402057f0 FUN_1402057f0 (size=84) ============


void FUN_1402057f0(longlong param_1)



{

  undefined8 uVar1;

  

  if (*(longlong *)(param_1 + 0x90) != 0) {

    FUN_1401367c0();

  }

  uVar1 = FUN_140132d50(*(undefined8 *)(param_1 + 0xa0),param_1 + 0xa8,1,0);

  *(undefined8 *)(param_1 + 0x90) = uVar1;

  *(undefined4 *)(param_1 + 200) = 0;

  *(undefined1 *)(param_1 + 0x111) = 0;

  return;

}




