// Address: 0x1401612e0
// Ghidra name: FUN_1401612e0
// ============ 0x1401612e0 FUN_1401612e0 (size=72) ============


void FUN_1401612e0(undefined4 *param_1,undefined4 *param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1401611a0();

  if (param_1 != (undefined4 *)0x0) {

    *param_1 = *(undefined4 *)(lVar1 + 0x90);

  }

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = *(undefined4 *)(lVar1 + 0x94);

  }

  FUN_1401611b0(lVar1,0,1);

  return;

}




