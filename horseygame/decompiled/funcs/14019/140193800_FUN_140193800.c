// Address: 0x140193800
// Ghidra name: FUN_140193800
// ============ 0x140193800 FUN_140193800 (size=123) ============


undefined8

FUN_140193800(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 == (undefined8 *)0x0) {

LAB_140193855:

    FUN_14012e850("Invalid device");

    uVar2 = 0xffffffff;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_140193855;

    }

    uVar2 = (**(code **)(param_1[1] + 8))(*param_1,param_2,param_3,param_4);

  }

  return uVar2;

}




