// Address: 0x140176cb0
// Ghidra name: FUN_140176cb0
// ============ 0x140176cb0 FUN_140176cb0 (size=39) ============


undefined1 FUN_140176cb0(longlong param_1,int param_2)



{

  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x18))) {

    return 1;

  }

  FUN_14012e850("Haptic: Invalid effect identifier.");

  return 0;

}




