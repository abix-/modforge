// Address: 0x140042880
// Ghidra name: FUN_140042880
// ============ 0x140042880 FUN_140042880 (size=95) ============


undefined8 FUN_140042880(longlong param_1,int param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 local_res18 [16];

  

  uVar2 = FUN_140042130();

  if ((int)uVar2 == 0) {

    return uVar2;

  }

  iVar1 = *(int *)(param_1 + 0x580);

  if (param_2 != iVar1) {

    FUN_140042b70(param_1,local_res18,0);

    *(int *)(param_1 + 0x764) = *(int *)(param_1 + 0x764) + (param_2 - iVar1);

  }

  return 1;

}




