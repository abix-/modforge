// Address: 0x1401747e0
// Ghidra name: FUN_1401747e0
// ============ 0x1401747e0 FUN_1401747e0 (size=81) ============


void FUN_1401747e0(int param_1)



{

  char cVar1;

  undefined8 local_res10 [3];

  

  if (param_1 != 0) {

    local_res10[0] = 0;

    cVar1 = FUN_1401aaff0(DAT_1403fc450,param_1,local_res10);

    if (cVar1 != '\0') {

      FUN_140174920(local_res10[0]);

      FUN_1401ab340(DAT_1403fc450,param_1);

    }

  }

  return;

}




