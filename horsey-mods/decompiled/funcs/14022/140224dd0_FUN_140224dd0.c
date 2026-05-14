// Address: 0x140224dd0
// Ghidra name: FUN_140224dd0
// ============ 0x140224dd0 FUN_140224dd0 (size=114) ============


void FUN_140224dd0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x168));

  uVar2 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",*(undefined8 *)(param_1 + 0x168),lVar1 * 2 + 2);

  FUN_140183cd0(uVar2);

  FUN_1401841e0();

  **(undefined2 **)(param_1 + 0x168) = 0;

  *(undefined2 *)(param_1 + 0x174) = 0;

  *(undefined4 *)(param_1 + 0x194) = 0;

  return;

}




