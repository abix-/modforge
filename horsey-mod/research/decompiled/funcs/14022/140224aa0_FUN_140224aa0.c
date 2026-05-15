// Address: 0x140224aa0
// Ghidra name: FUN_140224aa0
// ============ 0x140224aa0 FUN_140224aa0 (size=74) ============


void FUN_140224aa0(longlong param_1)



{

  ushort uVar1;

  

  uVar1 = *(ushort *)(param_1 + 0x248);

  FUN_140225110();

  FUN_140225040(param_1);

  if ((uVar1 & 0x3ff) != (*(ushort *)(param_1 + 0x248) & 0x3ff)) {

    FUN_140223dd0(param_1);

  }

  return;

}




