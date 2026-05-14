// Address: 0x1402258b0
// Ghidra name: FUN_1402258b0
// ============ 0x1402258b0 FUN_1402258b0 (size=196) ============


void FUN_1402258b0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  SHORT SVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  *(undefined4 *)(lVar1 + 0x204) = 1;

  *(undefined4 *)(lVar1 + 0x170) = 0x40;

  uVar2 = FUN_1401841a0(0x40,2);

  *(undefined8 *)(lVar1 + 0x168) = uVar2;

  FUN_140225bd0(0);

  FUN_140182d30(0x65,&DAT_1403383a8);

  FUN_140182d30(0xe3,"Left Windows");

  FUN_140182d30(0xe7,"Right Windows");

  SVar3 = GetKeyState(0x14);

  FUN_140184030(0x2000,(byte)SVar3 & 1);

  SVar3 = GetKeyState(0x90);

  FUN_140184030(0x1000,(byte)SVar3 & 1);

  SVar3 = GetKeyState(0x91);

  FUN_140184030(0x8000,(byte)SVar3 & 1);

  return;

}




