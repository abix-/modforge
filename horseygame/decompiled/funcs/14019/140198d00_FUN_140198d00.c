// Address: 0x140198d00
// Ghidra name: FUN_140198d00
// ============ 0x140198d00 FUN_140198d00 (size=81) ============


ulonglong FUN_140198d00(undefined8 *param_1)



{

  ulonglong in_RAX;

  tagMENUITEMINFOW local_58;

  

  if ((param_1 != (undefined8 *)0x0) && ((*(byte *)(param_1 + 0x202) & 2) != 0)) {

    local_58.cbSize = 0x50;

    local_58.fMask = 1;

    GetMenuItemInfoW(*(HMENU *)*param_1,*(UINT *)(param_1 + 1),0,&local_58);

    return (ulonglong)(local_58.fState >> 3) & 0xffffffffffffff01;

  }

  return in_RAX & 0xffffffffffffff00;

}




