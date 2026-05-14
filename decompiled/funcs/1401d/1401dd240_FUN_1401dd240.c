// Address: 0x1401dd240
// Ghidra name: FUN_1401dd240
// ============ 0x1401dd240 FUN_1401dd240 (size=174) ============


undefined8

FUN_1401dd240(longlong *param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,

             undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  int iVar1;

  undefined8 uVar2;

  

  *(undefined4 *)(param_2 + 8) = param_7;

  *(undefined4 *)(param_2 + 0xc) = param_3;

  *param_2 = 0;

  *(undefined4 *)(param_2 + 4) = param_6;

  *(undefined4 *)(param_2 + 0x10) = param_4;

  *(undefined4 *)(param_2 + 0x14) = param_5;

  FUN_1401e0110(param_4);

  iVar1 = (**(code **)(*param_1 + 0xb8))(param_1,param_6);

  if (iVar1 < 0) {

    uVar2 = FUN_1401df290("CreateTexture(D3DPOOL_DEFAULT)",iVar1);

    return uVar2;

  }

  return 1;

}




