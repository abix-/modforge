// Address: 0x14016e290
// Ghidra name: FUN_14016e290
// ============ 0x14016e290 FUN_14016e290 (size=58) ============


undefined8 FUN_14016e290(undefined8 param_1,undefined8 param_2)



{

  undefined8 uVar1;

  

  if (*(code **)(DAT_1403fc410 + 0x108) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x00014016e2c7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(DAT_1403fc410 + 0x108))(DAT_1403fc410,param_1,param_2);

  return uVar1;

}




