// Address: 0x1402c56b0
// Ghidra name: FUN_1402c56b0
// ============ 0x1402c56b0 FUN_1402c56b0 (size=130) ============


undefined8 FUN_1402c56b0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)



{

  undefined4 uVar1;

  

  switch(param_2) {

  case 0:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 4) = uVar1;

    return 1;

  case 7:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 8) = uVar1;

    return 1;

  case 8:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 0x10) = uVar1;

    *(undefined4 *)(param_1 + 0x38) = 0;

    return 1;

  case 9:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 0xc) = uVar1;

  }

  return 1;

}




