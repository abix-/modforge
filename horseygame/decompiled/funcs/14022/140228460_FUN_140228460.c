// Address: 0x140228460
// Ghidra name: FUN_140228460
// ============ 0x140228460 FUN_140228460 (size=78) ============


void FUN_140228460(int param_1,int param_2)



{

  SetCursorPos(param_1,param_2);

  SetCursorPos(param_1 + 1,param_2);

  SetCursorPos(param_1,param_2);

  DAT_1403fdc60 = GetTickCount();

  if (DAT_1403fdc60 == 0) {

    DAT_1403fdc60 = 1;

  }

  return;

}




