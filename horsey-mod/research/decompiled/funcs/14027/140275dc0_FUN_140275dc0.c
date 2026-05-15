// Address: 0x140275dc0
// Ghidra name: FUN_140275dc0
// ============ 0x140275dc0 FUN_140275dc0 (size=67) ============


undefined8 FUN_140275dc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  undefined8 uVar2;

  

  if (param_4 != 0x41) {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  iVar1 = FUN_140277070(param_1,param_3,0x41);

  if (iVar1 < 0) {

    uVar2 = FUN_14012e850("Couldn\'t write feature report");

    return uVar2;

  }

  return 1;

}




