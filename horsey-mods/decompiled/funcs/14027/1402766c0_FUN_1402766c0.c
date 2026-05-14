// Address: 0x1402766c0
// Ghidra name: FUN_1402766c0
// ============ 0x1402766c0 FUN_1402766c0 (size=58) ============


void FUN_1402766c0(longlong param_1,undefined8 *param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(undefined4 **)(param_1 + 0x90) != (undefined4 *)0x0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  *(undefined1 *)(lVar1 + 8) = 0;

  *param_2 = 0;

  return;

}




