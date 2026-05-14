// Address: 0x1402ecde0
// Ghidra name: FUN_1402ecde0
// ============ 0x1402ecde0 FUN_1402ecde0 (size=155) ============


undefined4 FUN_1402ecde0(undefined8 param_1,undefined8 param_2,int param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  if (param_3 == 2) {

    uVar1 = 4;

    uVar2 = 0x12;

  }

  else {

    if (param_3 != 3) {

      return (int)param_2;

    }

    uVar2 = 0x11;

    uVar1 = 3;

  }

  FUN_1402e8e00(&DAT_14030ccd4,0x14,param_2,uVar1,uVar2,0x22,param_1,0,1);

  return (int)param_2;

}




