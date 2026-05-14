// Address: 0x14014a590
// Ghidra name: FUN_14014a590
// ============ 0x14014a590 FUN_14014a590 (size=120) ============


void FUN_14014a590(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)FUN_14014a430(param_1,8,param_2);

  if (puVar2 != (undefined4 *)0x0) {

    cVar1 = (**(code **)(param_1 + 0x48))(param_1,puVar2,param_2,param_3,param_4);

    if (cVar1 == '\0') {

      *puVar2 = 0;

    }

  }

  return;

}




