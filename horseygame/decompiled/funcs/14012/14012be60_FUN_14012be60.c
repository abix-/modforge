// Address: 0x14012be60
// Ghidra name: FUN_14012be60
// ============ 0x14012be60 FUN_14012be60 (size=168) ============


undefined8 FUN_14012be60(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

    return 0xffffffffffffffff;

  }

  if (*(code **)(param_1 + 8) == (code *)0x0) {

    lVar1 = FUN_14012cb40(param_1,0,1);

    if (lVar1 < 0) {

      return 0xffffffffffffffff;

    }

    uVar2 = FUN_14012cb40(param_1,0,2);

    FUN_14012cb40(param_1,lVar1,0);

    return uVar2;

  }

                    /* WARNING: Could not recover jumptable at 0x00014012bf05. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = (**(code **)(param_1 + 8))(*(undefined8 *)(param_1 + 0x38));

  return uVar2;

}




