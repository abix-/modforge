// Address: 0x14014ac90
// Ghidra name: FUN_14014ac90
// ============ 0x14014ac90 FUN_14014ac90 (size=273) ============


void FUN_14014ac90(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,

                  undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,

                  undefined4 param_9,undefined8 param_10,undefined4 param_11,undefined4 param_12,

                  undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)



{

  char cVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)FUN_14014a430(param_1,10,param_2);

  if (puVar2 != (undefined4 *)0x0) {

    puVar2[0xf] = param_15;

    puVar2[0x10] = param_16;

    cVar1 = (**(code **)(param_1 + 0x58))

                      (param_1,puVar2,param_2,param_3,param_4,param_5,param_6,param_7,param_8,

                       param_9,param_10,param_11,param_12,param_13,param_14);

    if (cVar1 == '\0') {

      *puVar2 = 0;

    }

  }

  return;

}




