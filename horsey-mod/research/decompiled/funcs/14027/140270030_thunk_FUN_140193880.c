// Address: 0x140270030
// Ghidra name: thunk_FUN_140193880
// ============ 0x140270030 thunk_FUN_140193880 (size=5) ============


undefined8 thunk_FUN_140193880(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_1401938d7;

    }

                    /* WARNING: Could not recover jumptable at 0x0001401938d4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(param_1[1] + 0x20))(*param_1,param_2,param_3,*(code **)(param_1[1] + 0x20))

    ;

    return uVar2;

  }

LAB_1401938d7:

  FUN_14012e850("Invalid device");

  return 0xffffffff;

}




