// Address: 0x140263d60
// Ghidra name: FUN_140263d60
// ============ 0x140263d60 FUN_140263d60 (size=41) ============


void FUN_140263d60(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar1 + 0x51) != '\0') {

    FUN_140284590(param_1,lVar1 + 0x4c,5);

    *(undefined1 *)(lVar1 + 0x51) = 0;

  }

  return;

}




