// Address: 0x140042eb0
// Ghidra name: FUN_140042eb0
// ============ 0x140042eb0 FUN_140042eb0 (size=139) ============


int FUN_140042eb0(longlong param_1,undefined4 param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  undefined8 local_18 [2];

  

  local_18[0] = 0;

  iVar1 = FUN_140042b70(param_1,0,local_18);

  if (param_4 < iVar1) {

    iVar1 = param_4;

  }

  if (iVar1 != 0) {

    FUN_140049e00(param_2,param_3,0,*(undefined4 *)(param_1 + 4),local_18[0],0,iVar1);

  }

  return iVar1;

}




