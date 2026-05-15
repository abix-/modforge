// Address: 0x14008d200
// Ghidra name: FUN_14008d200
// ============ 0x14008d200 FUN_14008d200 (size=138) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008d200(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  undefined8 *puVar1;

  

  FUN_1400c5530(param_2,param_3,param_4,param_5);

  if (param_1 != &DAT_1403d9ea0) {

    puVar1 = param_1;

    if (0xf < (ulonglong)param_1[3]) {

      puVar1 = (undefined8 *)*param_1;

    }

    FUN_140027f50(&DAT_1403d9ea0,puVar1,param_1[2]);

  }

  if (param_1 != &DAT_1403d9ec0) {

    puVar1 = param_1;

    if (0xf < (ulonglong)param_1[3]) {

      puVar1 = (undefined8 *)*param_1;

    }

    FUN_140027f50(&DAT_1403d9ec0,puVar1,param_1[2]);

  }

  _DAT_1403ed4c4 = *(undefined4 *)(param_1 + 2);

  DAT_1403ed4c0 = 1;

  FUN_140027900(param_1);

  return;

}




