// Address: 0x14016d3d0
// Ghidra name: FUN_14016d3d0
// ============ 0x14016d3d0 FUN_14016d3d0 (size=58) ============


undefined8 FUN_14016d3d0(undefined4 *param_1)



{

  undefined8 uVar1;

  

  if (param_1 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","point");

    return 0;

  }

  uVar1 = FUN_140169d40(*param_1,param_1[1],1);

  return uVar1;

}




