// Address: 0x1402ece80
// Ghidra name: FUN_1402ece80
// ============ 0x1402ece80 FUN_1402ece80 (size=177) ============


undefined4 FUN_1402ece80(undefined4 param_1,undefined4 param_2,int param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  if (param_3 == 2) {

    uVar1 = 4;

    uVar2 = 0x12;

  }

  else {

    if (param_3 != 3) {

      return param_2;

    }

    uVar2 = 0x11;

    uVar1 = 3;

  }

  FUN_1402e8f40(&DAT_14038ef30,0x14,param_2,uVar1,uVar2,0x22,param_1,0,1);

  return param_2;

}




