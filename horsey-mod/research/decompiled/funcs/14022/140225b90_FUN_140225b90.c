// Address: 0x140225b90
// Ghidra name: FUN_140225b90
// ============ 0x140225b90 FUN_140225b90 (size=50) ============


void FUN_140225b90(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  if (*(char *)(lVar1 + 0x1a1) != '\0') {

    FUN_140223fc0(lVar1,*(undefined8 *)(lVar1 + 0x150));

    *(undefined1 *)(lVar1 + 0x1a1) = 0;

  }

  return;

}




