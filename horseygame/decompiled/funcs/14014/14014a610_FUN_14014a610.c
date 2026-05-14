// Address: 0x14014a610
// Ghidra name: FUN_14014a610
// ============ 0x14014a610 FUN_14014a610 (size=189) ============


void FUN_14014a610(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8,

                  undefined4 param_9)



{

  char cVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)FUN_14014a430(param_1,9,param_2);

  if (puVar2 != (undefined4 *)0x0) {

    cVar1 = (**(code **)(param_1 + 0x50))

                      (param_1,puVar2,param_2,param_3,param_4,param_5,param_6,param_7,param_8,

                       param_9);

    if (cVar1 == '\0') {

      *puVar2 = 0;

    }

  }

  return;

}




