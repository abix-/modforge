// Address: 0x140193900
// Ghidra name: FUN_140193900
// ============ 0x140193900 FUN_140193900 (size=97) ============


undefined8 FUN_140193900(undefined8 *param_1,undefined4 param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_140193945;

    }

                    /* WARNING: Could not recover jumptable at 0x000140193942. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(param_1[1] + 0x18))(*param_1,param_2,*(code **)(param_1[1] + 0x18));

    return uVar2;

  }

LAB_140193945:

  FUN_14012e850("Invalid device");

  return 0xffffffff;

}




