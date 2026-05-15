// Address: 0x1401960f0
// Ghidra name: FUN_1401960f0
// ============ 0x1401960f0 FUN_1401960f0 (size=179) ============


undefined8 FUN_1401960f0(undefined8 param_1,undefined8 param_2,int param_3)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_res20 [2];

  int local_18 [4];

  

  local_res20[0] = 0;

  iVar1 = (*DAT_1403fccd0)(param_1,param_2,local_18,0,local_res20,0);

  if ((iVar1 == 0x1a) && (local_18[0] == param_3)) {

    uVar2 = FUN_1401841a0(local_res20[0],1);

    iVar1 = (*DAT_1403fccd0)(param_1,param_2,local_18,uVar2,local_res20,0);

    if (iVar1 == 0) {

      return uVar2;

    }

    FUN_1401841e0(uVar2);

  }

  return 0;

}




