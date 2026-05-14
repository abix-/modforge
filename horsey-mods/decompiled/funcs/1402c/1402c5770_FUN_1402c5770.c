// Address: 0x1402c5770
// Ghidra name: FUN_1402c5770
// ============ 0x1402c5770 FUN_1402c5770 (size=106) ============


undefined8 FUN_1402c5770(longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)



{

  undefined4 uVar1;

  

  switch(param_2) {

  case 0:

    uVar1 = FUN_1402c5880(param_4,param_3);

    FUN_1402c5510(param_1,uVar1);

    return 1;

  case 1:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 0x18) = uVar1;

    return 1;

  case 2:

    uVar1 = FUN_1402c5880(param_4,param_3);

    *(undefined4 *)(param_1 + 0x1c) = uVar1;

  }

  return 1;

}




