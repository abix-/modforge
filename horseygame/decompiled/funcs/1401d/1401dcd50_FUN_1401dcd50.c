// Address: 0x1401dcd50
// Ghidra name: FUN_1401dcd50
// ============ 0x1401dcd50 FUN_1401dcd50 (size=102) ============


undefined8 FUN_1401dcd50(longlong *param_1,longlong param_2,undefined4 param_3)



{

  int iVar1;

  undefined8 uVar2;

  

  FUN_1401e0860();

  iVar1 = (**(code **)(*param_1 + 0x208))(param_1,param_3,*(undefined8 *)(param_2 + 0x18));

  if (iVar1 < 0) {

    uVar2 = FUN_1401df290("SetTexture()",iVar1);

    return uVar2;

  }

  return 1;

}




