// Address: 0x140268370
// Ghidra name: FUN_140268370
// ============ 0x140268370 FUN_140268370 (size=138) ============


ulonglong FUN_140268370(undefined8 param_1,char *param_2,undefined8 param_3,short param_4,

                       ushort param_5)



{

  int iVar1;

  ulonglong uVar2;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  

  uVar2 = (ulonglong)param_5;

  if (param_4 == 0x57e) {

    if (param_5 == 0x2007) {

      iVar1 = strncmp(param_2,"NES Controller",0xe);

      uVar2 = CONCAT44(extraout_var,iVar1);

      if (iVar1 != 0) {

        iVar1 = strncmp(param_2,"HVC Controller",0xe);

        uVar2 = CONCAT44(extraout_var_00,iVar1);

        if (iVar1 != 0) goto LAB_1402683c5;

      }

    }

    else if ((param_5 != 0x2019) && (param_5 != 0x201e)) {

      return (ulonglong)CONCAT11((char)(param_5 >> 8),param_5 == 0x2017);

    }

    return CONCAT71((int7)(uVar2 >> 8),1);

  }

LAB_1402683c5:

  return uVar2 & 0xffffffffffffff00;

}




