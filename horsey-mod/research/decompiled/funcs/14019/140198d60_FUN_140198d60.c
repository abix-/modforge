// Address: 0x140198d60
// Ghidra name: FUN_140198d60
// ============ 0x140198d60 FUN_140198d60 (size=58) ============


undefined1 FUN_140198d60(undefined8 *param_1)



{

  tagMENUITEMINFOW local_58;

  

  if (param_1 != (undefined8 *)0x0) {

    local_58.cbSize = 0x50;

    local_58.fMask = 1;

    GetMenuItemInfoW(*(HMENU *)*param_1,*(UINT *)(param_1 + 1),0,&local_58);

  }

  return 0;

}




