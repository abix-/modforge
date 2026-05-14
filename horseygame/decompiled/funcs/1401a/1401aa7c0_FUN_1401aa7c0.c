// Address: 0x1401aa7c0
// Ghidra name: FUN_1401aa7c0
// ============ 0x1401aa7c0 FUN_1401aa7c0 (size=51) ============


bool FUN_1401aa7c0(undefined8 param_1,int param_2)



{

  char cVar1;

  int local_res18 [4];

  

  cVar1 = FUN_1401aaff0(DAT_1403fcdb0,param_1,local_res18);

  if (cVar1 == '\0') {

    return false;

  }

  return local_res18[0] == param_2;

}




