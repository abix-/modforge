// Address: 0x14006dc30
// Ghidra name: FUN_14006dc30
// ============ 0x14006dc30 FUN_14006dc30 (size=70) ============


void FUN_14006dc30(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  FUN_140075b80(param_1 + 0x70);

  iVar1 = FUN_140075da0();

  if (iVar1 != 0) {

    uVar2 = FUN_1402c704c(0x1e0);

    *(undefined8 *)(param_1 + 0x78) = uVar2;

    FUN_14006d580(uVar2);

  }

  FUN_14006db30(param_1);

  FUN_14005cb90(param_1);

  return;

}




