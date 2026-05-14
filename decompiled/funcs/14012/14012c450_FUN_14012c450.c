// Address: 0x14012c450
// Ghidra name: FUN_14012c450
// ============ 0x14012c450 FUN_14012c450 (size=88) ============


undefined8

FUN_14012c450(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 local_res18;

  undefined8 local_res20;

  undefined8 local_18 [2];

  

  local_res18 = param_3;

  local_res20 = param_4;

  iVar1 = FUN_14012f790(local_18,param_2,&local_res18);

  if (iVar1 < 0) {

    return 0;

  }

  uVar2 = FUN_14012cbb0(param_1,local_18[0],(longlong)iVar1);

  FUN_1401841e0(local_18[0]);

  return uVar2;

}




