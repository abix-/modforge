// Address: 0x14014a740
// Ghidra name: FUN_14014a740
// ============ 0x14014a740 FUN_14014a740 (size=100) ============


void FUN_14014a740(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)FUN_14014a430(param_1,5,0);

  if (puVar2 != (undefined4 *)0x0) {

    cVar1 = (**(code **)(param_1 + 0x30))(param_1,puVar2,param_2,param_3);

    if (cVar1 == '\0') {

      *puVar2 = 0;

    }

  }

  return;

}




