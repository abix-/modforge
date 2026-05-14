// Address: 0x140226950
// Ghidra name: FUN_140226950
// ============ 0x140226950 FUN_140226950 (size=121) ============


void FUN_140226950(undefined8 param_1,undefined8 param_2,float *param_3)



{

  char cVar1;

  float fVar2;

  undefined1 local_a8 [100];

  int local_44;

  float local_1c;

  

  param_3[0] = 0.0;

  param_3[1] = 0.0;

  cVar1 = FUN_1402269d0(param_2,local_a8);

  if ((cVar1 != '\0') && (local_44 == 0xc)) {

    fVar2 = (float)FUN_140226e70(param_1,param_2);

    local_1c = local_1c / DAT_1403033b4;

    *param_3 = fVar2;

    param_3[1] = local_1c / fVar2;

  }

  return;

}




