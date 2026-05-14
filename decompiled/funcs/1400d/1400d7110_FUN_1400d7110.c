// Address: 0x1400d7110
// Ghidra name: FUN_1400d7110
// ============ 0x1400d7110 FUN_1400d7110 (size=126) ============


void FUN_1400d7110(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined8 param_4)



{

  undefined4 uVar1;

  char cVar2;

  undefined8 local_res20;

  

  local_res20 = param_4;

  cVar2 = FUN_1400d8c70(&local_res20,*param_2,*param_1);

  if (cVar2 != '\0') {

    uVar1 = *param_2;

    *param_2 = *param_1;

    *param_1 = uVar1;

  }

  cVar2 = FUN_1400d8c70(&local_res20,*param_3,*param_2);

  if (cVar2 != '\0') {

    uVar1 = *param_3;

    *param_3 = *param_2;

    *param_2 = uVar1;

    cVar2 = FUN_1400d8c70(&local_res20,uVar1,*param_1);

    if (cVar2 != '\0') {

      uVar1 = *param_2;

      *param_2 = *param_1;

      *param_1 = uVar1;

    }

  }

  return;

}




